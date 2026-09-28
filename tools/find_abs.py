#!/usr/bin/env python3
"""List what in a linked module still points into a module without a
relocation, i.e. what a shifted build would leave behind.

  find_abs.py <module> <version> [elf]

Run from blastcorps/.  The ELF (build/<module>.<version>.elf by default) must
be linked with --emit-relocs, as the Makefile does.  Reported:

- a lui whose immediate is the high half of an address in a module (not a
  module's load address) and that has no R_MIPS_HI16;
- a word in .data/.rodata, or in a `bin` inside .text (the data islands),
  that holds such an address and has no R_MIPS_32.

Constants that merely look like addresses show up too; the report is for a
look by hand.
"""
import bisect
import re
import struct
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import modmap  # noqa: E402


def main():
    mod_name, ver = sys.argv[1], sys.argv[2]
    elf = sys.argv[3] if len(sys.argv) > 3 else f"build/{mod_name}.{ver}.elf"
    mods = modmap.modules(ver)
    mod = mods[mod_name]

    def movable(v):
        m = modmap.owner(mods, v)
        return m is not None and v != m.vram

    relocs = {}
    out = subprocess.run(["mips-linux-gnu-readelf", "-rW", elf], capture_output=True, text=True).stdout
    for line in out.splitlines():
        p = line.split()
        if len(p) >= 3 and re.fullmatch(r"[0-9a-f]{8}", p[0]) and p[2].startswith("R_MIPS_"):
            relocs.setdefault(int(p[0], 16), set()).add(p[2])
    if not relocs:
        sys.exit(f"{elf} has no relocations; link it with --emit-relocs")

    syms = []
    for line in subprocess.run(["mips-linux-gnu-nm", "-n", elf], capture_output=True, text=True).stdout.splitlines():
        p = line.split()
        if len(p) == 3 and p[1] in "tTdDbBrR":
            syms.append((int(p[0], 16), p[2]))
    addrs = [a for a, _ in syms]

    def where(a):
        i = bisect.bisect_right(addrs, a) - 1
        return f"{syms[i][1]}+0x{a - syms[i][0]:X}" if i >= 0 else f"0x{a:08X}"

    sects = []
    for line in subprocess.run(["mips-linux-gnu-readelf", "-SW", elf], capture_output=True, text=True).stdout.splitlines():
        m = re.match(r"\s*\[\s*\d+\] (\S+)\s+PROGBITS\s+([0-9a-f]+) [0-9a-f]+ ([0-9a-f]+) \S+\s+(\S+)", line)
        if m and "A" in m.group(4):
            sects.append((m.group(1), int(m.group(2), 16), int(m.group(3), 16), "X" in m.group(4)))
    # the bins inside .text, by their original addresses (the build may be
    # shifted, so by symbol: <module>_<offset>_bin)
    nm = dict((n, a) for a, n in syms)
    bins = []
    subs = [x for x in mod.subsegments if isinstance(x, list)]
    for k, x in enumerate(subs):
        if len(x) >= 3 and x[1] == "bin":
            start = nm.get(f"{mod.name}_{x[0]:X}_bin")
            if start is not None and k + 1 < len(subs):
                bins.append((start, start + subs[k + 1][0] - x[0]))
    found = 0
    for name, vma, size, code in sects:
        data = subprocess.run(["mips-linux-gnu-objcopy", "-O", "binary", "--only-section", name, elf, "/dev/stdout"],
                              capture_output=True).stdout
        for off in range(0, len(data) - 3, 4):
            w = struct.unpack(">I", data[off:off + 4])[0]
            a = vma + off
            in_bin = any(b <= a < e for b, e in bins)
            if code and not in_bin:
                if w >> 26 == 0x0F and "R_MIPS_HI16" not in relocs.get(a, ()):
                    hi = (w & 0xFFFF) << 16
                    if any(movable(hi + k) for k in (-0x8000, 0, 0x7FFF)):
                        print(f"{where(a)}: lui 0x{w & 0xFFFF:X}")
                        found += 1
            elif movable(w) and "R_MIPS_32" not in relocs.get(a, ()):
                print(f"{where(a)}: .word 0x{w:08X}")
                found += 1
    print(f"{elf}: {found} found", file=sys.stderr)


main()
