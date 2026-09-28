#!/usr/bin/env python3
"""Generate a stage-2 splat config for one code module.

Run from blastcorps/ (tools/regen_code_yaml.sh drives it for every module and
version).  The config is built in passes, each running splat on a probe
config written to <module>.<version>.yaml and reading back what it found:

1. Code runs.  Regions of .text that are not r4300 code (--bin: data
   islands, RSP microcode) become `bin` subsegments; code resumes as its own
   subsegment where each one ends.

2. Object boundaries (find_boundaries).  Splat runs once with
   `find_file_boundaries` over one asm subsegment per code run.  Its
   suggestions are kept unless a branch crosses them (splat's function
   detection trips over some handwritten code), and --split adds ones it
   misses.

3. Handwritten code (split_handwritten).  Runs of libultra's handwritten
   functions (HANDWRITTEN_LIBULTRA) and of Rare's handwritten functions
   (sd $ra, never sw $ra: IDO never does that) are split out of the IDO code
   around them, and every function in OBJECT_STARTS starts an object.

4. Data (split_code_data, only with --rodata).  Splat runs again with every
   object as asm, and the references each object's code makes into
   .data/.rodata (asm_refs) lay out one .data and one .rodata subsegment per
   object (split_data).  --data-split adds block starts no reference shows,
   --tail the regions after .rodata that belong to no object (hd_code's RSP
   microcode data).  Two objects' .rodata in one block reveal a .text
   boundary splat missed (missed_boundaries); the code is split there and
   this pass repeats until no new boundary turns up.  --join keeps a found
   boundary unsplit.  Without --rodata, .data and .rodata stay one bin.

5. The config.  With --c, code subsegments are `c` (one GLOBAL_ASM file per
   function under asm/nonmatchings) wherever both ends are 16-byte aligned,
   the alignment an IDO object gets; handwritten code and code between data
   islands (which starts or ends elsewhere) stays `asm`.  A data subsegment
   the existing config gives to a C file (`.data`/`.rodata`) keeps that type
   when it is regenerated at the same offset.

Usage:
  gen_code_yaml.py <module> <version> --vram 0x... --data <off> --end <off>
                   [--bin off:len:note] ... [--c] [--symbols <path>] [--split <off>] ...
                   [--rodata <off> [--tail off:len:note] ... [--data-split off[:obj]] ...
                    [--join <off>] ...]
"""
import argparse
import bisect
import collections
import re
import struct
import subprocess
import sys
import textwrap
from pathlib import Path

HERE = Path(__file__).resolve().parent
SPLAT = HERE / "splat" / "split.py"

# libultra functions that come from its handwritten .s files.  A code
# subsegment made only of these is emitted as `asm`, and each run of them is
# split out of whatever C it was lumped in with.
HANDWRITTEN_LIBULTRA = {
    "bcopy", "bzero", "sqrtf", "osGetCount", "osSetIntMask", "osMapTLBRdb",
    "osInvalDCache", "osInvalICache", "osWritebackDCache", "osWritebackDCacheAll",
    "__osSetSR", "__osGetSR", "__osSetFpcCsr", "__osGetCause", "__osSetCompare",
    "__osDisableInt", "__osRestoreInt", "__osProbeTLB",
    # exceptasm.s
    "__osExceptionPreamble", "__osException", "send_mesg", "handle_CpU",
    "__osEnqueueAndYield", "__osEnqueueThread", "__osPopThread", "__osDispatchThread",
}
# First functions of objects that splat's boundary suggestions miss (no
# padding between them and the object before).  A version where a name is
# unknown needs --split instead.
OBJECT_STARTS = {
    "huft_build",               # gzip's inflate.c, after hd_code's dialogue code
    "osCreateMesgQueue",        # after sinf.c; -O1 where gu is -O3
    "__osPiCreateAccessQueue",  # piacs.c, after thread.c
    "alCSeqGetLoc",             # cseq.c, after cspstop.c
    "alUnlink",                 # sl.c, after event.c (-O3 would inline alLink)
    "alSynAddPlayer",           # synaddplayer.c, after sl.c
    "_allocatePVoice",          # synallocvoice.c, after synaddplayer.c
    "coss",                     # coss.c, after sins.c
    "__osViInit",               # vi.c (-O1), after coss.c (-O3)
    "alSaveNew",                # drvrnew.c (-O3), after ai.c (-O1)
    "osJamMesg",                # jammesg.c (-O1), after save.c (-O3)
    "alLoadParam",              # load.c, after mainbus.c
    "alSynSetPriority",         # synsetpriority.c, after seq.c
    "alFilterNew",              # filter.c, after synsetpriority.c
    "osPiStartDma",             # pidma.c (-O1), after synthesizer.c (-O3)
    "alSeqGetLoc",              # seq.c (-O3), after xldtob.c (-O1)
}

SYMBOL_RE = re.compile(r"^\s*(\w+)\s*=\s*0x([0-9A-Fa-f]+);", re.M)
LUI_RE = re.compile(r"^lui\s+\$(\w+), (0x[0-9A-Fa-f]+)$")
LO_RE = re.compile(r"^(\w+)\s+\$\w+, (?:\$(\w+), (-?0x[0-9A-Fa-f]+|-?\d+)$|(-?0x[0-9A-Fa-f]+|-?\d+)?\(\$(\w+)\)$)")
LIKELY = re.compile(r"^(beql|bnel|blezl|bgtzl|bltzl|bgezl|bltzall|bgezall|bc1fl|bc1tl)$")
NO_DEST = re.compile(r"^(s[bhwd]|swc1|sdc1|swl|swr|b\w*|j|jr|jal|jalr|mt\w+|ctc1|nop|syscall|break|cache|sync|eret)$")


def seg_name(off):
    return f"{off:05X}" if off == 0 else f"{off:X}"


def be_word(blob, vram):
    """The big-endian word at vram address a of blob (loaded at vram)."""
    return lambda a: struct.unpack(">I", blob[a - vram:a - vram + 4])[0]


def late_size(late):
    return 8 if late == "d" else 4


def branch_spans(words):
    """(from, to) word indices of every PC-relative branch."""
    for i, w in enumerate(words):
        op, rs, rt = w >> 26, (w >> 21) & 31, (w >> 16) & 31
        if op in (4, 5, 6, 7, 0x14, 0x15, 0x16, 0x17) or \
                (op == 1 and rt in (0, 1, 2, 3, 0x10, 0x11, 0x12, 0x13)) or \
                (op == 0x11 and rs == 8):  # bc1*
            off = w & 0xFFFF
            yield i, i + 1 + (off - 0x10000 if off & 0x8000 else off)


def chain(points):
    """The largest subset of (object index, address) points in which
    addresses rise with the object index.  Objects lay out their .data (and
    their .rodata) in link order, so an address outside the chain is one
    object reaching into another's data."""
    points = sorted(points)
    tails, tail_idx, prev = [], [], [None] * len(points)
    for j, (_, addr) in enumerate(points):
        k = bisect.bisect_right(tails, addr)
        if k == len(tails):
            tails.append(addr)
            tail_idx.append(j)
        else:
            tails[k] = addr
            tail_idx[k] = j
        prev[j] = tail_idx[k - 1] if k else None
    keep = collections.defaultdict(list)
    j = tail_idx[-1] if tail_idx else None
    while j is not None:
        keep[points[j][0]].append(points[j][1])
        j = prev[j]
    return keep


def layout_blocks(n_objects, lo, hi, refs, guesses=(), ptrs=()):
    """One section's blocks: [[start, object index, last address, users]]
    in address order, users being {address: {object index}}.

    refs: (object index, address) references from code, which alone choose
    the chain.  guesses (pairs splat left as numbers) and ptrs (.data words
    pointing into the section, credited to the object whose .data holds
    them) may anchor a block and widen it backwards, but not choose the
    chain: a table can point anywhere.  Only code widens a block forwards."""
    users = collections.defaultdict(set)
    for i, a in refs:
        if lo <= a < hi:
            users[a].add(i)
    keep = chain([(i, a) for a, us in users.items() if len(us) == 1 for i in us])
    for i, a in [*guesses, *ptrs]:
        if lo <= a < hi:
            users[a].add(i)
    from_code = {a for _, a in [*refs, *guesses]} - {a for _, a in ptrs}
    mine = collections.defaultdict(set)
    for a, us in users.items():
        for i in us:
            mine[i].add(a)
    blocks = {i: [min(v), max(v)] for i, v in keep.items()}

    # anchor the rest on shared addresses between their neighbours
    for i in range(n_objects):
        if i in blocks or not mine[i]:
            continue
        prev = max((k for k in blocks if k < i), default=None)
        nxt = min((k for k in blocks if k > i), default=None)
        p_hi = blocks[prev][1] if prev is not None else lo - 1
        n_lo = blocks[nxt][0] if nxt is not None else hi
        inside = [a for a in mine[i] if p_hi < a < n_lo]
        if inside:
            blocks[i] = [min(inside), max(inside)]
    order = sorted(blocks)

    # widen each block back to its own references in the gap before it
    for k, i in enumerate(order):
        p = order[k - 1] if k else None
        p_hi = blocks[p][1] if k else lo - 1
        early = [a for a in mine[i] if p_hi < a < blocks[i][0] and p not in users[a]]
        if early:
            blocks[i][0] = min(early)
    # and forward to what only its code references before the next block (a
    # constant reached through a pair splat couldn't match).  Not to .data
    # pointers: those past its block are a data-only object's.
    for k, i in enumerate(order):
        n_lo = blocks[order[k + 1]][0] if k + 1 < len(order) else hi
        later = [a for a in mine[i] if blocks[i][1] < a < n_lo and users[a] == {i}
                 and a in from_code]
        if later:
            blocks[i][1] = max(later)

    res = []
    for i in order:
        first, last = blocks[i]
        if not res:
            start = lo
        else:
            start = first & ~15
            if start <= res[-1][2]:
                start = first & ~3
        res.append([start, i, last, users])
    return res


def split_data(names, refs, pairs, blob, vram, data, rodata, tail, text_end):
    """Per-object .data and .rodata subsegments: [(offset, kind, name)].

    names: object names in link order.  refs, pairs: {(object index,
    address, late)} for the references from code (see asm_refs); pairs,
    being guesses, only anchor and widen blocks, like .data's pointers.
    Offsets are module offsets; addresses are vram.

    The layout is the one init has: every object's .data in link order, then
    every object's .rodata, each block 16-aligned.  So (layout_blocks):

    - An object is anchored by the addresses only it references, keeping
      the largest set that rises with link order (chain()); the rest are
      objects reaching into each other's data (an extern table, libultra's
      globals).  An object with no such address is anchored by any address
      it shares that falls between its anchored neighbours.  Every block is
      widened back to its own references in the gap before it, and forward
      to constants only its code uses before the next.  The block starts at
      its first address, rounded down to 16.
    - Pointers in .data count as references by the object that owns them.
      That is how strings reached only through a table find their object,
      in .rodata or (for tables of tables) in .data.
    - In .rodata an object's late part (jump tables, float and double
      constants, after its strings) ends it.  Whatever lies between that end
      and the next object, and in .data whatever past an object's own
      references only others use, is a data-only object (libultra's VI
      modes, libm's NaN, hd_front_end's menu tables) and gets a subsegment
      named by its offset.
    """
    word = be_word(blob, vram)
    in_text = lambda w: vram <= w < vram + text_end
    late = {a: l for _, a, l in refs | pairs if l}
    code_refs = [(i, a) for i, a, _ in refs]
    pair_refs = [(i, a) for i, a, _ in pairs]
    out = []

    # .data: once from code alone, then again with .data's own pointers
    lo, hi = vram + data, vram + rodata
    ptrs = [(a, word(a)) for a in range(lo, hi, 4)]

    def pointers(blocks, lo, hi):
        """.data's pointers into [lo, hi), by the object whose block holds them."""
        owner = lambda a: next((i for s, i, _, _ in reversed(blocks) if s <= a), None)
        return [(owner(a), w) for a, w in ptrs if lo <= w < hi and owner(a) is not None]

    dblocks = layout_blocks(len(names), lo, hi, code_refs, pair_refs)
    dblocks = layout_blocks(len(names), lo, hi, code_refs, pair_refs, pointers(dblocks, lo, hi))
    for k, (start, i, last, users) in enumerate(dblocks):
        end = dblocks[k + 1][0] if k + 1 < len(dblocks) else hi
        out.append((start - vram, "data", names[i]))
        for a in sorted(users):
            if last < a < end and a % 16 == 0 and i not in users[a]:
                out.append((a - vram, "data", f"{a - vram:X}"))
                break

    # .rodata
    lo, hi = vram + rodata, vram + tail
    ro_only = []
    rblocks = layout_blocks(len(names), lo, hi, code_refs, pair_refs, pointers(dblocks, lo, hi))
    for k, (start, i, last, users) in enumerate(rblocks):
        if k:
            p_last = rblocks[k - 1][2]
            if p_last in late:
                # the previous object ends after its last constant; a jump
                # table runs as long as its words point into .text
                e = p_last + late_size(late[p_last])
                while e < start and in_text(word(e)):
                    e += 4
                e = (e + 15) & ~15
                if e < start and any(blob[e - vram:start - vram]):
                    out.append((e - vram, "rodata", f"{e - vram:X}"))
                    ro_only.append((e, start))
        out.append((start - vram, "rodata", names[i]))

    # A data-only object's .rodata holds the strings its .data points to, so
    # the .data that points into it is that object's too: from the first
    # such word (rounded down to 16) to the last, whoever else uses it.
    for e, start in ro_only:
        at = [a for a, w in ptrs if e <= w < start]
        if not at:
            continue
        d, last = min(at) & ~15, max(at)
        out = [x for x in out if not (x[1] == "data" and d <= x[0] + vram <= last
                                      and x[2] == f"{x[0]:X}")]
        if not any(x[1] == "data" and x[0] + vram == d for x in out):
            out.append((d - vram, "data", f"{d - vram:X}"))
    return sorted(out, key=lambda x: (x[1] == "rodata", x[0]))


def missed_boundaries(layout, names, by_func, blob, vram, text_end, compiled):
    """Module offsets of .text boundaries splat missed, found in .rodata.

    Within one object's .rodata IDO puts its strings (and other early
    data) first and its late rodata (jump tables, float and double
    constants) after, so a string after a late constant in one block starts
    another object.  So does a late constant that sits on a 16-byte boundary
    with zeros before it, beyond the natural alignment after the previous
    constant: that gap is the padding at the end of an object.  The new
    object starts at the first 16-aligned function after the last one that
    uses the earlier data, and no later than the first that uses the new.
    Only compiled objects (names in `compiled`) are looked at, and a float
    or double followed by more than padding is left out: it may be a table
    (xldtob.c's pows is early data), or a constant whose neighbour splat
    could not symbolize."""
    word = be_word(blob, vram)
    ro = [(off, name) for off, kind, name in layout if kind == "rodata"]
    index = {n: i for i, n in enumerate(names)}
    found = set()
    for k, (off, name) in enumerate(ro):
        i = index.get(name)
        if i is None or i not in by_func or name not in compiled:
            continue
        lo = vram + off
        hi = vram + ro[k + 1][0] if k + 1 < len(ro) else None
        items = collections.defaultdict(lambda: [None, set()])  # addr: [late, users]
        for f, uses in by_func[i].items():
            for a, late in uses:
                if a >= lo and (hi is None or a < hi):
                    items[a][0] = items[a][0] or late
                    items[a][1].add(f)
        starts = sorted(f for f in by_func[i] if (f - vram) % 16 == 0)
        addrs = sorted(items)
        for n, a in enumerate(addrs):
            late = items[a][0]
            if late in ("f", "d"):
                size = late_size(late)
                stop = addrs[n + 1] if n + 1 < len(addrs) else (hi or a + size)
                if any(blob[a + size - vram:stop - vram]):
                    items[a][0] = "table"
        prev = None  # (end, alignment, users) of the last late item
        for a in addrs:
            late, users = items[a]
            if late == "table":
                continue  # early or late, it proves nothing
            cut = None
            if prev is not None and not late:
                cut = prev[2]
            elif prev is not None and a % 16 == 0:
                natural = (prev[0] + prev[1] - 1) & ~(prev[1] - 1)
                if a - natural >= 8 and not any(blob[prev[0] - vram:a - vram]):
                    cut = prev[2]
            if cut is not None:
                s = next((s for s in starts if max(cut) < s <= min(users)), None)
                if s is not None:
                    found.add(s - vram)
                    break
            if late:
                end = a + late_size(late)
                while late == "j" and vram <= word(end) < vram + text_end:
                    end += 4
                prev = (end, late_size(late), users)
    return found


def asm_refs(mod, names, symbols, lo, hi, by_func=None):
    """References to [lo, hi) in the asm splat wrote for each object:
    {(object index, address, late)} for %hi/%lo symbols, and a second set
    for lui/addiu and lui/load pairs splat left as numbers (scheduling split
    them), which are only a guess.  late is "j" for a jump table, "f" or
    "d" for a float or double load or store, else None.

    by_func, if given, is filled with {object index: {function vram:
    {(address, late)}}} for the %hi/%lo references, every function of the
    object present (see missed_boundaries)."""
    refs, pairs = set(), set()
    for i, name in enumerate(names):
        path = Path("asm", mod, f"{name}.s")
        if not path.exists():
            continue
        hi_regs = {}
        op = ""
        func, new_func = None, False
        for line in path.read_text().splitlines():
            if line.startswith("glabel ") or line.startswith(".L"):
                hi_regs = {}
                # jump table targets are glabels too: L<vram>_<offset>
                if line.startswith("glabel ") and not re.match(r"glabel L[0-9A-F]{8}_", line):
                    new_func = True
                continue
            if "*/" not in line:
                continue
            if new_func:
                m = re.match(r"/\* [0-9A-F]+ ([0-9A-F]{8}) ", line)
                if m:
                    func, new_func = int(m.group(1), 16), False
                    if by_func is not None:
                        by_func.setdefault(i, {}).setdefault(func, set())
            body = line.split("*/")[-1].strip()
            insn = body.split()
            # A branch-likely's delay slot only runs when the branch is
            # taken, so it doesn't clobber a %hi on the fall-through path.
            likely = bool(LIKELY.match(op))
            op = insn[0] if insn else ""
            kind = "f" if op in ("lwc1", "swc1") else "d" if op in ("ldc1", "sdc1") else None
            syms = re.findall(r"%(?:hi|lo)\((\w+)", body)
            for sym in syms:
                m = re.search(r"_([0-9A-F]{8})$", sym)
                addr = symbols.get(sym, int(m.group(1), 16) if m else None)
                if addr is not None and lo <= addr < hi:
                    late = "j" if sym.startswith("jtbl_") else kind
                    refs.add((i, addr, late))
                    if by_func is not None and func is not None:
                        by_func[i][func].add((addr, late))
            m = LUI_RE.search(body)
            if m and not syms:
                if not likely:
                    hi_regs[m.group(1)] = int(m.group(2), 16) << 16
                continue
            m = LO_RE.search(body)
            if m and not syms:
                base, imm = (m.group(2), m.group(3)) if m.group(2) else (m.group(5), m.group(4) or "0")
                if base in hi_regs and (op == "addiu" or m.group(5)):
                    addr = (hi_regs[base] + int(imm, 0)) & 0xFFFFFFFF
                    if lo <= addr < hi:
                        pairs.add((i, addr, kind))
            dest = re.match(r"\$(\w+)", insn[1]) if len(insn) > 1 else None
            if dest and not NO_DEST.match(op) and not likely:
                srcs = [r for r in re.findall(r"\$(\w+)", body)[1:] if r in hi_regs]
                if op == "addu" and len(srcs) == 1:
                    hi_regs[dest.group(1)] = hi_regs[srcs[0]]  # base + index
                else:
                    hi_regs.pop(dest.group(1), None)
    return refs, pairs


class Module:
    """One module's .text: its bins, code runs and functions, and the
    config written for it (<module>.<version>.yaml)."""

    def __init__(self, args):
        self.args = args
        self.mod, self.ver, self.vram = args.module, args.version, args.vram
        self.data = args.data
        self.bins = sorted((int(off, 16), int(length, 16), note) for off, length, note in
                           (spec.split(":", 2) for spec in args.bin))
        # code runs between the bins: [start, end) pairs
        self.code, pos = [], 0
        for off, length, _ in self.bins:
            if off > pos:
                self.code.append((pos, off))
            pos = off + length
        if pos < self.data:
            self.code.append((pos, self.data))
        self.cfg = Path(f"{self.mod}.{self.ver}.yaml")
        self.full = Path(f"{self.mod}.{self.ver}.bin").read_bytes()
        blob = self.full[:self.data]
        self.words = struct.unpack(f">{len(blob) // 4}I", blob)

        # function starts from the symbol file: offset -> name
        self.funcs = {}
        if args.symbols:
            for line in Path(args.symbols).read_text().splitlines():
                m = SYMBOL_RE.match(line)
                if m and ("type:func" in line or m.group(1) in HANDWRITTEN_LIBULTRA
                          or m.group(1) in OBJECT_STARTS):
                    off = int(m.group(2), 16) - self.vram
                    if 0 <= off < self.data:
                        self.funcs.setdefault(off, m.group(1))
        self.hand_lib = {o for o, n in self.funcs.items() if n in HANDWRITTEN_LIBULTRA}

    def in_bin(self, x):
        return any(o <= x < o + n for o, n, _ in self.bins)

    def edges(self, starts=()):
        """Every offset a subsegment can end at."""
        return sorted({e for _, e in self.code} | set(starts)
                      | {o for o, _, _ in self.bins} | {self.data})

    def ra_saves(self, start, end):
        """How often [start, end) saves $ra with sd and with sw."""
        sd = sw = 0
        for w in self.words[start // 4:end // 4]:
            sd += (w & 0xFFFF0000) == 0xFFBF0000  # sd $ra, x($sp)
            sw += (w & 0xFFFF0000) == 0xAFBF0000  # sw $ra, x($sp)
        return sd, sw

    def handwritten(self, start, end):
        """True if [start, end) is handwritten: Rare's (it saves $ra, and
        everything else it touches, with sd; IDO uses sw) or libultra's."""
        sd, sw = self.ra_saves(start, end)
        if sd > 0 and sw == 0:
            return True
        inside = [o for o in self.funcs if start <= o < end]
        return bool(inside) and start in self.hand_lib and all(o in self.hand_lib for o in inside)

    def text_lines(self, starts, c):
        """Config lines for code split at `starts` plus the bins, in address
        order; code is `c` where allowed if c is set, else all `asm`."""
        ends = self.edges(starts)
        items = [(x, "code") for x in starts] + [(o, "bin", n) for o, _, n in self.bins]
        lines = []
        for item in sorted(items):
            x = item[0]
            if item[1] == "bin":
                lines += [f"    # {line}" for line in textwrap.wrap(item[2], 72)]
                lines.append(f"    - [0x{x:X}, bin, {self.mod}/{x:X}]")
                continue
            nxt = next(e for e in ends if e > x)
            hand = self.handwritten(x, nxt)
            kind = "c" if c and x % 16 == 0 and nxt % 16 == 0 and not hand else "asm"
            name = seg_name(x)
            note = " # handwritten" if hand and c else ""
            lines.append(f"    - [0x{name}, {kind}, {self.mod}/{name}]{note}")
        lines.append(f"    - [0x{self.data:X}, linker, data]")
        return lines

    def header(self):
        a = self.args
        lines = [
            "options:",
            "  base_path: .",
            f"  basename: {self.mod}.{self.ver}",
            "  compiler: IDO",
            "  create_detected_syms: yes",
            "  find_file_boundaries: yes",
            f"  target_path: {self.mod}.{self.ver}.bin",
            *([f"  symbol_addrs_path: {a.symbols}"] if a.symbols else []),
            f"  undefined_funcs_auto_path: undefined_funcs_auto.{self.mod}.{self.ver}.txt",
            f"  undefined_syms_auto_path: undefined_syms_auto.{self.mod}.{self.ver}.txt",
            f"  src_path: src.{self.ver}",
            "segments:",
        ]
        if a.note:
            lines.append(f"  # {a.note}")
        lines += [
            f"  - name:  {self.mod}",
            "    type:  code",
            f"    vram:  0x{self.vram:X}",
            "    start: 0x00000000",
            # Subsegment offsets are exact.  The default SUBALIGN(16) would pad
            # the handwritten code that resumes after a data island at an odd offset.
            "    subalign: 4",
            "    subsegments:",
        ]
        return lines

    def data_bin(self):
        return [f"    - [0x{self.data:X}, bin, {self.mod}/{self.mod}_data] # .data"]

    def write(self, starts, data_lines, c=False, eof=""):
        lines = self.header() + self.text_lines(starts, c) + data_lines
        lines.append(f"  - [0x{self.args.end:X}]{eof}")
        self.cfg.write_text("\n".join(lines) + "\n")

    def splat(self, starts, data_lines):
        """Run splat on a probe config (all code asm); its stdout."""
        self.write(starts, data_lines)
        proc = subprocess.run([sys.executable, str(SPLAT), str(self.cfg)],
                              capture_output=True, text=True)
        if proc.returncode:
            sys.exit(proc.stderr)
        return proc.stdout


def find_boundaries(m):
    """Pass 2: splat's object-boundary suggestions, less the ones a branch
    crosses, plus --split."""
    out = m.splat([s for s, _ in m.code], m.data_bin())
    splits = {int(s, 16) for s in re.findall(r"- \[(0x[0-9A-Fa-f]+), asm\]", out)}
    splits = {s for s in splits if 0 < s < m.data and not m.in_bin(s)}

    # Splat's function detection trips over some of the handwritten code and
    # suggests boundaries inside a function.  No branch crosses a real object
    # boundary, so drop any suggestion one does.
    crossed = set()
    for a, b in branch_spans(m.words):
        if m.in_bin(4 * a):
            continue
        lo, hi = sorted((a, b))
        crossed |= {s for s in splits if lo < s // 4 <= hi}
    for s in sorted(crossed):
        print(f"dropping boundary 0x{s:X}: a branch crosses it", file=sys.stderr)
    return (splits - crossed) | set(m.args.split)


def split_handwritten(m, splits):
    """Pass 3: split out runs of handwritten functions, and at OBJECT_STARTS.
    Uses the functions splat found in pass 2 (the symbol file only lists
    named and called ones)."""
    splits = set(splits)
    found = set()
    for x, _ in m.code:
        asm = Path("asm", m.mod, f"{seg_name(x)}.s")
        if asm.exists():
            for g in re.finditer(r"^glabel \w+\n/\* [0-9A-F]+ ([0-9A-F]{8}) ", asm.read_text(), re.M):
                found.add(int(g.group(1), 16) - m.vram)
    known = sorted(set(m.funcs) | found | splits | {s for s, _ in m.code} | {e for _, e in m.code})

    # Each run of handwritten libultra: at its first function, and at the
    # next function or split after it that isn't handwritten.  Both are
    # object boundaries, so 16-aligned.
    for off in sorted(m.hand_lib):
        prev = max((k for k in known if k < off), default=None)
        if prev is not None and prev in m.hand_lib:
            continue  # inside a run; one .s file can hold several functions
        if off % 16 == 0:
            splits.add(off)
        nxt = next((k for k in known if k > off and k not in m.hand_lib), None)
        if nxt is not None and nxt % 16 == 0 and nxt < m.data:
            splits.add(nxt)

    # Each run of Rare's handwritten functions (sd $ra, never sw $ra) in an
    # otherwise-IDO subsegment.  A leaf function (neither) between two of
    # them belongs to the run; one at either end stays with the C, as it may
    # well be IDO's.  Only runs whose both ends are object boundaries
    # (16-aligned) can be split.
    bounds = sorted(splits | set(m.edges()) | {s for s, _ in m.code} | {o + n for o, n, _ in m.bins})
    for s, e in zip(bounds, bounds[1:]):
        if m.in_bin(s) or m.handwritten(s, e):
            continue
        fns = sorted({s} | {k for k in known if s < k < e})
        kinds = []
        for f, g in zip(fns, fns[1:] + [e]):
            sd, sw = m.ra_saves(f, g)
            kinds.append("hand" if sd and not sw else "ido" if sw else "leaf")
        k = 0
        while k < len(fns):
            if kinds[k] != "hand":
                k += 1
                continue
            j = k
            for n in range(k + 1, len(fns)):
                if kinds[n] == "ido":
                    break
                if kinds[n] == "hand":
                    j = n
            lo, hi = fns[k], fns[j + 1] if j + 1 < len(fns) else e
            if lo % 16 == 0 and hi % 16 == 0 and (lo, hi) != (s, e):
                splits |= {lo, hi} - {e}
            k = j + 1

    splits |= {o for o, n in m.funcs.items() if n in OBJECT_STARTS and o % 16 == 0}
    return splits


def split_code_data(m, starts):
    """Pass 4: the per-object .data/.rodata layout, and the .text starts
    with the boundaries it reveals.  Returns (starts, layout, tails)."""
    args = m.args
    tails = sorted((int(o, 16), int(n, 16), note) for o, n, note in
                   (t.split(":", 2) for t in args.tail))
    tail = tails[0][0] if tails else args.end
    symbols = {}
    while True:
        m.splat(starts, m.data_bin())
        for path in [args.symbols, f"undefined_syms_auto.{m.mod}.{m.ver}.txt"]:
            if path and Path(path).exists():
                for s in SYMBOL_RE.finditer(Path(path).read_text()):
                    symbols.setdefault(s.group(1), int(s.group(2), 16))
        names = [seg_name(x) for x in starts]
        by_func = {}
        refs, pairs = asm_refs(m.mod, names, symbols, m.vram + m.data, m.vram + tail, by_func)
        layout = split_data(names, refs, pairs, m.full, m.vram,
                            m.data, args.rodata, tail, m.data)
        have = {off for off, _, _ in layout}
        for spec in args.data_split:
            off, _, obj = spec.partition(":")
            off = int(off, 16)
            if off not in have:
                layout.append((off, "data" if off < args.rodata else "rodata", obj or f"{off:X}"))
        layout.sort(key=lambda x: x[0])

        # A .text boundary splat missed shows up as two objects' .rodata in
        # one block; split there and lay the data out again.
        ends = m.edges(starts)
        compiled = {n for x, n in zip(starts, names)
                    if not m.handwritten(x, next(e for e in ends if e > x))}
        missed = missed_boundaries(layout, names, by_func, m.full, m.vram, m.data, compiled)
        missed -= set(starts) | set(args.join)
        if not missed:
            return starts, layout, tails
        for s in sorted(missed):
            print(f"splitting at 0x{s:X}: its .rodata starts a new object", file=sys.stderr)
        starts = sorted(set(starts) | missed)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("module")
    ap.add_argument("version")
    hexarg = lambda s: int(s, 16)
    ap.add_argument("--vram", required=True, type=hexarg)
    ap.add_argument("--data", required=True, type=hexarg, help="offset where .data starts")
    ap.add_argument("--end", required=True, type=hexarg)
    ap.add_argument("--bin", action="append", default=[], metavar="OFF:LEN:NOTE",
                    help="region inside .text that is not r4300 code")
    ap.add_argument("--note", default="")
    ap.add_argument("--c", action="store_true", help="emit aligned code as c subsegments")
    ap.add_argument("--symbols", help="symbol_addrs file to use")
    ap.add_argument("--split", action="append", default=[], type=hexarg,
                    help="an object boundary in .text that splat misses")
    ap.add_argument("--rodata", type=hexarg,
                    help="offset where .rodata starts; splits .data/.rodata per object")
    ap.add_argument("--tail", action="append", default=[], metavar="OFF:LEN:NOTE",
                    help="region after .rodata that belongs to no object")
    ap.add_argument("--data-split", action="append", default=[], metavar="OFF[:OBJ]",
                    help="start of a block in .data/.rodata that no reference shows: "
                    "object OBJ's, or a data-only object's")
    ap.add_argument("--join", action="append", default=[], type=hexarg,
                    help="a boundary found in .rodata that the config leaves unsplit")
    args = ap.parse_args()

    m = Module(args)
    # Data the C owns already (.data/.rodata subsegments), by (offset, kind, name).
    owned = set()
    if m.cfg.exists():
        for o in re.finditer(r"- \[0x([0-9A-F]+), \.(data|rodata), (\S+)\]", m.cfg.read_text()):
            owned.add((int(o.group(1), 16), o.group(2), o.group(3)))

    splits = split_handwritten(m, find_boundaries(m))
    starts = sorted(splits | {s for s, _ in m.code})

    data_lines = m.data_bin()
    if args.rodata is not None:
        starts, layout, tails = split_code_data(m, starts)
        data_lines = ["    # .data, then .rodata, of each object in link order (see split_data"
                      " in tools/gen_code_yaml.py)"]
        for off, kind, name in layout:
            if (off, kind, f"{m.mod}/{name}") in owned:
                kind = "." + kind
            data_lines.append(f"    - [0x{off:X}, {kind}, {m.mod}/{name}]")
        for off, _, note in tails:
            data_lines += [f"    # {line}" for line in textwrap.wrap(note, 72)]
            data_lines.append(f"    - [0x{off:X}, bin, {m.mod}/{off:X}]")

    m.write(starts, data_lines, c=args.c, eof=" # EOF")
    print(f"{m.cfg}: {len(starts)} code subsegments, {len(m.bins)} bin")


main()
