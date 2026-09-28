#!/usr/bin/env python3
"""Generate a stage-2 splat config for one code module.

Runs splat once with `find_file_boundaries` to learn where the compiler's
object-file boundaries are, then writes the config out with each boundary as
its own named subsegment.  Regions that are known not to be r4300 code are
passed with --bin and emitted as `bin` so they survive the round trip untouched;
code resumes as its own subsegment where each one ends.

With --c, code subsegments are emitted as `c` (one GLOBAL_ASM file per function
under asm/nonmatchings) wherever both ends are 16-byte aligned, the alignment an
IDO object gets.  Code that starts or ends elsewhere sits between data islands,
is handwritten, and stays `asm`.  So does code that saves $ra with sd and never
with sw: IDO never does that, and Rare's handwritten engine code (about a
third of hd_code) always does.  A run of such functions inside otherwise-IDO
code is split out as its own asm subsegment, as are libultra's handwritten
functions (HANDWRITTEN_LIBULTRA).

With --rodata, .data and .rodata are split per object too (see
split_data below); without it they stay one bin.  --tail gives the regions
after .rodata that belong to no object's .data or .rodata (hd_code's RSP
microcode data).  A data subsegment the existing config gives to a C file
(`.data`/`.rodata`) keeps that type when it is regenerated at the same offset.

Usage:
  gen_code_yaml.py <module> <version> --vram 0x... --data <off> --end <off>
                   [--bin off:len:note] ... [--c] [--symbols <path>]
                   [--rodata <off> [--tail off:len:note] ...] [--split <off>] ...
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
SPLAT = HERE / "splat" / "split.py"


def header(module, version, vram, note, symbols):
    lines = [
        "options:",
        "  base_path: .",
        f"  basename: {module}.{version}",
        "  compiler: IDO",
        "  create_detected_syms: yes",
        "  find_file_boundaries: yes",
        f"  target_path: {module}.{version}.bin",
        *([f"  symbol_addrs_path: {symbols}"] if symbols else []),
        f"  undefined_funcs_auto_path: undefined_funcs_auto.{module}.{version}.txt",
        f"  undefined_syms_auto_path: undefined_syms_auto.{module}.{version}.txt",
        f"  src_path: src.{version}",
        "segments:",
    ]
    if note:
        lines.append(f"  # {note}")
    lines += [
        f"  - name:  {module}",
        "    type:  code",
        f"    vram:  0x{vram:X}",
        "    start: 0x00000000",
        # Subsegment offsets are exact.  The default SUBALIGN(16) would pad
        # the handwritten code that resumes after a data island at an odd offset.
        "    subalign: 4",
        "    subsegments:",
    ]
    return lines


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


def split_data(names, refs, pairs, blob, vram, data, rodata, tail, text_end):
    """Per-object .data and .rodata subsegments: [(offset, kind, name)].

    names: object names in link order.  refs, pairs: {(object index,
    address, late)} for the references from code (see asm_refs); pairs,
    being guesses, only anchor and widen blocks, like .data's pointers.  Offsets are module
    offsets; addresses are vram.

    The layout is the one init has: every object's .data in link order, then
    every object's .rodata, each block 16-aligned.  So:

    - An object is anchored by the addresses only it references, keeping
      the largest set that rises with link order (chain()); the rest are
      objects reaching into each other's data (an extern table, libultra's
      globals).  An object with no such address is anchored by any address
      it shares that falls between its anchored neighbours, and every
      object's block is widened to its own references in the gap before it.
      The block starts at its first address, rounded down to 16.
    - Pointers in .data count as references by the object that owns them.
      That is how strings reached only through a table find their object,
      in .rodata or (for tables of tables) in .data.
    - In .rodata an object's late part (jump tables, float and double
      constants, after its strings) ends it.  Whatever lies between that end
      and the next object, and in .data whatever past an object's own
      references only others use, is a data-only object (libultra's VI
      modes, libm's NaN) and gets a subsegment named by its offset.
    """
    word = lambda a: struct.unpack(">I", blob[a - vram:a - vram + 4])[0]
    in_text = lambda w: vram <= w < vram + text_end
    late = {a: l for _, a, l in refs | pairs if l}

    def layout(lo, hi, refs, extra=()):
        """extra: references that may anchor or widen a block but not
        choose the chain (a table in .data can point anywhere)."""
        users = collections.defaultdict(set)
        for i, a in refs:
            if lo <= a < hi:
                users[a].add(i)
        keep = chain([(i, a) for a, us in users.items() if len(us) == 1 for i in us])
        for i, a in extra:
            if lo <= a < hi:
                users[a].add(i)
        mine = collections.defaultdict(set)
        for a, us in users.items():
            for i in us:
                mine[i].add(a)
        blocks = {i: [min(v), max(v)] for i, v in keep.items()}
        # anchor the rest on shared addresses between their neighbours
        for i in range(len(names)):
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
        for k, i in enumerate(order):
            p_hi = blocks[order[k - 1]][1] if k else lo - 1
            p = order[k - 1] if k else None
            early = [a for a in mine[i] if p_hi < a < blocks[i][0] and p not in users[a]]
            if early:
                blocks[i][0] = min(early)
        res = []
        for k, i in enumerate(order):
            first, last = blocks[i]
            if not res:
                start = lo
            else:
                start = first & ~15
                if start <= res[-1][2]:
                    start = first & ~3
            res.append([start, i, last, users])
        return res

    out = []

    # .data: once from code alone, then again with .data's own pointers
    lo, hi = vram + data, vram + rodata
    code_refs = [(i, a) for i, a, _ in refs]
    pair_refs = [(i, a) for i, a, _ in pairs]
    dblocks = layout(lo, hi, code_refs, pair_refs)
    owner = lambda blocks, a: next((i for s, i, _, _ in reversed(blocks) if s <= a), None)
    ptrs = [(a, word(a)) for a in range(lo, hi, 4)]
    data_ptrs = [(owner(dblocks, a), w) for a, w in ptrs if lo <= w < hi and owner(dblocks, a) is not None]
    dblocks = layout(lo, hi, code_refs, pair_refs + data_ptrs)
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
    ro_ptrs = [(owner(dblocks, a), w) for a, w in ptrs if lo <= w < hi and owner(dblocks, a) is not None]
    rblocks = layout(lo, hi, code_refs, pair_refs + ro_ptrs)
    for k, (start, i, last, users) in enumerate(rblocks):
        if k:
            p_last = rblocks[k - 1][2]
            if p_last in late:
                # the previous object ends after its last constant; a jump
                # table runs as long as its words point into .text
                e = p_last + (8 if late[p_last] == "d" else 4)
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


LUI_RE = re.compile(r"^lui\s+\$(\w+), (0x[0-9A-Fa-f]+)$")
LO_RE = re.compile(r"^(\w+)\s+\$\w+, (?:\$(\w+), (-?0x[0-9A-Fa-f]+|-?\d+)$|(-?0x[0-9A-Fa-f]+|-?\d+)?\(\$(\w+)\)$)")
NO_DEST = re.compile(r"^(s[bhwd]|swc1|sdc1|swl|swr|b\w*|j|jr|jal|jalr|mt\w+|ctc1|nop|syscall|break|cache|sync|eret)$")


def asm_refs(mod, names, symbols, lo, hi):
    """References to [lo, hi) in the asm splat wrote for each object:
    {(object index, address, late)} for %hi/%lo symbols, and a second set
    for lui/addiu and lui/load pairs splat left as numbers (scheduling split
    them), which are only a guess.  late is "j" for a jump table, "f" or
    "d" for a float or double load or store, else None."""
    refs, pairs = set(), set()
    for i, name in enumerate(names):
        path = Path("asm", mod, f"{name}.s")
        if not path.exists():
            continue
        hi_regs = {}
        for line in path.read_text().splitlines():
            if line.startswith("glabel ") or line.startswith(".L"):
                hi_regs = {}
                continue
            if "*/" not in line:
                continue
            body = line.split("*/")[-1].strip()
            insn = body.split()
            op = insn[0] if insn else ""
            kind = "f" if op in ("lwc1", "swc1") else "d" if op in ("ldc1", "sdc1") else None
            syms = re.findall(r"%(?:hi|lo)\((\w+)", body)
            for sym in syms:
                m = re.search(r"_([0-9A-F]{8})$", sym)
                addr = symbols.get(sym, int(m.group(1), 16) if m else None)
                if addr is not None and lo <= addr < hi:
                    refs.add((i, addr, "j" if sym.startswith("jtbl_") else kind))
            m = LUI_RE.search(body)
            if m and not syms:
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
            if dest and not NO_DEST.match(op):
                srcs = [r for r in re.findall(r"\$(\w+)", body)[1:] if r in hi_regs]
                if op == "addu" and len(srcs) == 1:
                    hi_regs[dest.group(1)] = hi_regs[srcs[0]]  # base + index
                else:
                    hi_regs.pop(dest.group(1), None)
    return refs, pairs


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("module")
    ap.add_argument("version")
    ap.add_argument("--vram", required=True, type=lambda s: int(s, 16))
    ap.add_argument("--data", required=True, type=lambda s: int(s, 16),
                    help="offset where .data starts")
    ap.add_argument("--end", required=True, type=lambda s: int(s, 16))
    ap.add_argument("--bin", action="append", default=[], metavar="OFF:LEN:NOTE",
                    help="region inside .text that is not r4300 code")
    ap.add_argument("--note", default="")
    ap.add_argument("--c", action="store_true", help="emit aligned code as c subsegments")
    ap.add_argument("--symbols", help="symbol_addrs file to use")
    ap.add_argument("--rodata", type=lambda s: int(s, 16),
                    help="offset where .rodata starts; splits .data/.rodata per object")
    ap.add_argument("--split", action="append", default=[], type=lambda s: int(s, 16),
                    help="an object boundary in .text that splat misses")
    ap.add_argument("--tail", action="append", default=[], metavar="OFF:LEN:NOTE",
                    help="region after .rodata that belongs to no object")
    args = ap.parse_args()

    mod, ver = args.module, args.version
    bins = []
    for spec in args.bin:
        off, length, note = spec.split(":", 2)
        bins.append((int(off, 16), int(length, 16), note))
    bins.sort()

    # Code runs between the bins: [start, end) pairs.
    code, pos = [], 0
    for off, length, _ in bins:
        if off > pos:
            code.append((pos, off))
        pos = off + length
    if pos < args.data:
        code.append((pos, args.data))
    in_bin = lambda x: any(o <= x < o + n for o, n, _ in bins)

    cfg = Path(f"{mod}.{ver}.yaml")
    # Data the C owns already (.data/.rodata subsegments), by (offset, kind, name).
    owned = set()
    if cfg.exists():
        for m in re.finditer(r"- \[0x([0-9A-F]+), \.(data|rodata), (\S+)\]", cfg.read_text()):
            owned.add((int(m.group(1), 16), m.group(2), m.group(3)))
    blob = Path(f"{mod}.{ver}.bin").read_bytes()[:args.data]
    words = struct.unpack(f">{len(blob) // 4}I", blob)

    # Function starts from the symbol file: name -> offset in this module.
    funcs = {}
    if args.symbols:
        for line in Path(args.symbols).read_text().splitlines():
            m = re.match(r"\s*(\w+)\s*=\s*0x([0-9A-Fa-f]+);", line)
            if m and ("type:func" in line or m.group(1) in HANDWRITTEN_LIBULTRA):
                off = int(m.group(2), 16) - args.vram
                if 0 <= off < args.data:
                    funcs.setdefault(off, m.group(1))
    hand_lib = {o for o, n in funcs.items() if n in HANDWRITTEN_LIBULTRA}

    def ra_saves(start, end):
        """How often [start, end) saves $ra with sd and with sw."""
        sd = sw = 0
        for w in words[start // 4:end // 4]:
            sd += (w & 0xFFFF0000) == 0xFFBF0000  # sd $ra, x($sp)
            sw += (w & 0xFFFF0000) == 0xAFBF0000  # sw $ra, x($sp)
        return sd, sw

    def handwritten(start, end):
        """True if [start, end) is Rare's handwritten asm.  IDO saves $ra with
        sw; that code saves it (and everything else it touches) with sd."""
        sd, sw = ra_saves(start, end)
        if sd > 0 and sw == 0:
            return True
        inside = [o for o in funcs if start <= o < end]
        return bool(inside) and start in hand_lib and all(o in hand_lib for o in inside)

    def emit(starts):
        """Config lines for code split at `starts` plus the bins, in address order."""
        ends = sorted({e for _, e in code} | set(starts) | {o for o, _, _ in bins} | {args.data})
        items = [(x, "code") for x in starts] + [(o, "bin", n) for o, _, n in bins]
        lines = []
        for item in sorted(items):
            x = item[0]
            if item[1] == "bin":
                lines += [f"    # {line}" for line in textwrap.wrap(item[2], 72)]
                lines.append(f"    - [0x{x:X}, bin, {mod}/{x:X}]")
                continue
            nxt = next(e for e in ends if e > x)
            hand = handwritten(x, nxt)
            kind = "c" if args.c and x % 16 == 0 and nxt % 16 == 0 and not hand else "asm"
            name = f"{x:05X}" if x == 0 else f"{x:X}"
            note = " # handwritten" if hand and args.c else ""
            lines.append(f"    - [0x{name}, {kind}, {mod}/{name}]{note}")
        lines.append(f"    - [0x{args.data:X}, linker, data]")
        return lines

    # Pass 1: one asm subsegment per code run, just to collect boundary suggestions.
    boot = header(mod, ver, args.vram, args.note, args.symbols)
    boot += [line.replace(", c,", ", asm,") for line in emit([s for s, _ in code])]
    boot.append(f"    - [0x{args.data:X}, bin, {mod}/{mod}_data]")
    boot.append(f"  - [0x{args.end:X}]")
    cfg.write_text("\n".join(boot) + "\n")

    proc = subprocess.run([sys.executable, str(SPLAT), str(cfg)],
                          capture_output=True, text=True)
    if proc.returncode:
        sys.exit(proc.stderr)
    splits = [int(m, 16) for m in
              re.findall(r"- \[(0x[0-9A-Fa-f]+), asm\]", proc.stdout)]
    splits = {s for s in splits if 0 < s < args.data and not in_bin(s)}

    # Splat's function detection trips over some of the handwritten code and
    # suggests boundaries inside a function.  No branch crosses a real object
    # boundary, so drop any suggestion one does.
    crossed = set()
    for a, b in branch_spans(words):
        if in_bin(4 * a):
            continue
        lo, hi = sorted((a, b))
        crossed |= {s for s in splits if lo < s // 4 <= hi}
    for s in sorted(crossed):
        print(f"dropping boundary 0x{s:X}: a branch crosses it", file=sys.stderr)
    splits -= crossed
    splits |= set(args.split)

    # Split each run of handwritten libultra out of the C around it: at its
    # first function, and at the next function or split after it that isn't
    # handwritten.  Both are object boundaries, so 16-aligned.
    # Every function splat found in pass 1, from the glabels in its asm output
    # (the symbol file only lists named and called ones).
    found = set()
    for x, _ in code:
        asm = Path("asm", mod, f"{x:05X}.s" if x == 0 else f"{x:X}.s")
        if not asm.exists():
            continue
        for m in re.finditer(r"^glabel \w+\n/\* [0-9A-F]+ ([0-9A-F]{8}) ", asm.read_text(), re.M):
            found.add(int(m.group(1), 16) - args.vram)
    known = sorted(set(funcs) | found | splits | {s for s, _ in code} | {e for _, e in code})
    for off in sorted(hand_lib):
        prev = max((k for k in known if k < off), default=None)
        if prev is not None and prev in hand_lib:
            continue  # inside a run; one .s file can hold several functions
        if off % 16 == 0:
            splits.add(off)
        nxt = next((k for k in known if k > off and k not in hand_lib), None)
        if nxt is not None and nxt % 16 == 0 and nxt < args.data:
            splits.add(nxt)

    # Likewise split each run of Rare's handwritten functions (sd $ra, never
    # sw $ra) out of an otherwise-IDO subsegment.  A leaf function (neither)
    # between two of them belongs to the run; one at either end stays with
    # the C, as it may well be IDO's.  Only runs whose both ends are object
    # boundaries (16-aligned) can be split.
    bounds = sorted(splits | {s for s, _ in code} | {e for _, e in code}
                    | {o for o, _, _ in bins} | {o + n for o, n, _ in bins} | {args.data})
    for s, e in zip(bounds, bounds[1:]):
        if in_bin(s) or handwritten(s, e):
            continue
        fns = sorted({s} | {k for k in known if s < k < e})
        kinds = []
        for f, g in zip(fns, fns[1:] + [e]):
            sd, sw = ra_saves(f, g)
            kinds.append("hand" if sd and not sw else "ido" if sw else "leaf")
        k = 0
        while k < len(fns):
            if kinds[k] != "hand":
                k += 1
                continue
            j = k
            for m in range(k + 1, len(fns)):
                if kinds[m] == "ido":
                    break
                if kinds[m] == "hand":
                    j = m
            lo, hi = fns[k], fns[j + 1] if j + 1 < len(fns) else e
            if lo % 16 == 0 and hi % 16 == 0 and (lo, hi) != (s, e):
                splits |= {lo, hi} - {e}
            k = j + 1
    starts = sorted(splits | {s for s, _ in code})

    data_lines = [f"    - [0x{args.data:X}, bin, {mod}/{mod}_data] # .data"]
    if args.rodata is not None:
        # Pass 3: every object as asm, to see what each one references.
        tails = sorted((int(o, 16), int(n, 16), note) for o, n, note in
                       (t.split(":", 2) for t in args.tail))
        tail = tails[0][0] if tails else args.end
        probe = header(mod, ver, args.vram, args.note, args.symbols)
        probe += [line.replace(", c,", ", asm,") for line in emit(starts)]
        probe += data_lines + [f"  - [0x{args.end:X}]"]
        cfg.write_text("\n".join(probe) + "\n")
        proc = subprocess.run([sys.executable, str(SPLAT), str(cfg)],
                              capture_output=True, text=True)
        if proc.returncode:
            sys.exit(proc.stderr)
        symbols = {}
        for path in [args.symbols, f"undefined_syms_auto.{mod}.{ver}.txt"]:
            if path and Path(path).exists():
                for m in re.finditer(r"^\s*(\w+)\s*=\s*0x([0-9A-Fa-f]+);", Path(path).read_text(), re.M):
                    symbols.setdefault(m.group(1), int(m.group(2), 16))
        names = [f"{x:05X}" if x == 0 else f"{x:X}" for x in starts]
        full = Path(f"{mod}.{ver}.bin").read_bytes()
        refs, pairs = asm_refs(mod, names, symbols, args.vram + args.data, args.vram + tail)
        layout = split_data(names, refs, pairs, full, args.vram,
                            args.data, args.rodata, tail, args.data)
        data_lines = ["    # .data, then .rodata, of each object in link order (see split_data"
                      " in tools/gen_code_yaml.py)"]
        for off, kind, name in layout:
            if (off, kind, f"{mod}/{name}") in owned:
                kind = "." + kind
            data_lines.append(f"    - [0x{off:X}, {kind}, {mod}/{name}]")
        for off, _, note in tails:
            data_lines += [f"    # {line}" for line in textwrap.wrap(note, 72)]
            data_lines.append(f"    - [0x{off:X}, bin, {mod}/{off:X}]")

    # The real config.
    out = header(mod, ver, args.vram, args.note, args.symbols)
    out += emit(starts)
    out += data_lines
    out.append(f"  - [0x{args.end:X}] # EOF")
    cfg.write_text("\n".join(out) + "\n")
    print(f"{cfg}: {len(starts)} code subsegments, {len(bins)} bin")


main()
