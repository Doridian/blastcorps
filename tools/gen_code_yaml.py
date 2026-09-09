#!/usr/bin/env python3
"""Generate a stage-2 splat config for one code module.

Runs splat once with `find_file_boundaries` to learn where the compiler's
object-file boundaries are, then writes the config out with each boundary as
its own named subsegment.  Regions that are known not to be r4300 code are
passed with --bin and emitted as `bin` so they survive the round trip untouched.

Usage:
  gen_code_yaml.py <module> <version> --vram 0x... --data <off> [--bin off:name] ...
"""
import argparse
import re
import subprocess
import sys
import textwrap
from pathlib import Path

HERE = Path(__file__).resolve().parent
SPLAT = HERE / "splat" / "split.py"


def header(module, version, vram, note):
    lines = [
        "options:",
        "  base_path: .",
        f"  basename: {module}.{version}",
        "  compiler: IDO",
        "  create_detected_syms: yes",
        "  find_file_boundaries: yes",
        f"  target_path: {module}.{version}.bin",
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
        "    subsegments:",
    ]
    return lines


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
    args = ap.parse_args()

    mod, ver = args.module, args.version
    bins = []
    for spec in args.bin:
        off, length, note = spec.split(":", 2)
        bins.append((int(off, 16), int(length, 16), note))
    bins.sort()

    cfg = Path(f"{mod}.{ver}.yaml")
    text_end = bins[0][0] if bins else args.data

    # Pass 1: one big asm subsegment, just to collect boundary suggestions.
    boot = header(mod, ver, args.vram, args.note)
    boot.append(f"    - [0x00000, asm, {mod}/00000]")
    for off, length, _ in bins:
        boot.append(f"    - [0x{off:X}, bin, {mod}/{off:X}]")
    boot.append(f"    - [0x{args.data:X}, linker, data]")
    boot.append(f"    - [0x{args.data:X}, bin, {mod}/{mod}_data]")
    boot.append(f"  - [0x{args.end:X}]")
    cfg.write_text("\n".join(boot) + "\n")

    proc = subprocess.run([sys.executable, str(SPLAT), str(cfg)],
                          capture_output=True, text=True)
    splits = [int(m, 16) for m in
              re.findall(r"- \[(0x[0-9A-Fa-f]+), asm\]", proc.stdout)]
    splits = sorted({s for s in splits if 0 < s < text_end})

    # Pass 2: the real config.
    out = header(mod, ver, args.vram, args.note)
    out.append(f"    - [0x00000, asm, {mod}/00000]")
    for off in splits:
        out.append(f"    - [0x{off:X}, asm, {mod}/{off:X}]")
    for off, _, note in bins:
        out += [f"    # {line}" for line in textwrap.wrap(note, 72)]
        out.append(f"    - [0x{off:X}, bin, {mod}/{off:X}]")
    out.append(f"    - [0x{args.data:X}, linker, data]")
    out.append(f"    - [0x{args.data:X}, bin, {mod}/{mod}_data] # .data")
    out.append(f"  - [0x{args.end:X}] # EOF")
    cfg.write_text("\n".join(out) + "\n")
    print(f"{cfg}: {len(splits) + 1} asm subsegments, {len(bins)} bin")


main()
