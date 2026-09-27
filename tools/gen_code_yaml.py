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
is handwritten, and stays `asm`.

Usage:
  gen_code_yaml.py <module> <version> --vram 0x... --data <off> --end <off>
                   [--bin off:len:note] ... [--c] [--symbols <path>]
"""
import argparse
import re
import struct
import subprocess
import sys
import textwrap
from pathlib import Path

HERE = Path(__file__).resolve().parent
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
            kind = "c" if args.c and x % 16 == 0 and nxt % 16 == 0 else "asm"
            name = f"{x:05X}" if x == 0 else f"{x:X}"
            lines.append(f"    - [0x{name}, {kind}, {mod}/{name}]")
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
    blob = Path(f"{mod}.{ver}.bin").read_bytes()[:args.data]
    words = struct.unpack(f">{len(blob) // 4}I", blob)
    crossed = set()
    for a, b in branch_spans(words):
        if in_bin(4 * a):
            continue
        lo, hi = sorted((a, b))
        crossed |= {s for s in splits if lo < s // 4 <= hi}
    for s in sorted(crossed):
        print(f"dropping boundary 0x{s:X}: a branch crosses it", file=sys.stderr)
    splits -= crossed
    starts = sorted(splits | {s for s, _ in code})

    # Pass 2: the real config.
    out = header(mod, ver, args.vram, args.note, args.symbols)
    out += emit(starts)
    out.append(f"    - [0x{args.data:X}, bin, {mod}/{mod}_data] # .data")
    out.append(f"  - [0x{args.end:X}] # EOF")
    cfg.write_text("\n".join(out) + "\n")
    print(f"{cfg}: {len(starts)} code subsegments, {len(bins)} bin")


main()
