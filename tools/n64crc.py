#!/usr/bin/env python3
"""Recompute an N64 ROM header's checksum (CRC1/CRC2 at 0x10), in place.

The boot code checks it over the 1 MiB from 0x1000, which holds init.  The
CIC is identified by the boot code's own checksum (0x40-0x1000).  Only
6101/6102, 6103, 6105 and 6106 are handled.

  n64crc.py <rom.z64> [--check]
"""
import argparse
import struct
import sys
import zlib
from pathlib import Path

SEEDS = {6102: 0xF8CA4DDC, 6103: 0xA3886759, 6105: 0xDF26F436, 6106: 0x1FEA617A}
BOOT_CRC = {0x6170A4A1: 6101, 0x90BB6CB5: 6102, 0x0B050EE0: 6103, 0x98BC2C86: 6105, 0xACC8580A: 6106}
M = 0xFFFFFFFF


def rol(v, n):
    n &= 31
    return ((v << n) | (v >> (32 - n))) & M if n else v


def checksum(rom, cic):
    seed = SEEDS[6102 if cic == 6101 else cic]
    t1 = t2 = t3 = t4 = t5 = t6 = seed
    words = struct.unpack(">262144I", rom[0x1000:0x101000])
    boot = struct.unpack(">1024I", rom[0:0x1000]) if cic == 6105 else None
    for i, d in enumerate(words):
        if (t6 + d) & M < t6:
            t4 = (t4 + 1) & M
        t6 = (t6 + d) & M
        t3 ^= d
        r = rol(d, d & 0x1F)
        t5 = (t5 + r) & M
        t2 = t2 ^ r if t2 > d else t2 ^ t6 ^ d
        if cic == 6105:
            t1 = (t1 + (boot[0x710 // 4 + (i & 0xFF)] ^ d)) & M
        else:
            t1 = (t1 + (t5 ^ d)) & M
    if cic == 6103:
        return (t6 ^ t4) + t3 & M, (t5 ^ t2) + t1 & M
    if cic == 6106:
        return (t6 * t4 + t3) & M, (t5 * t2 + t1) & M
    return t6 ^ t4 ^ t3, t5 ^ t2 ^ t1


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("rom")
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()
    rom = bytearray(Path(args.rom).read_bytes())
    cic = BOOT_CRC.get(zlib.crc32(rom[0x40:0x1000]))
    if cic is None:
        sys.exit(f"{args.rom}: unknown boot code")
    crc = checksum(rom, cic)
    old = struct.unpack(">II", rom[0x10:0x18])
    if args.check:
        if old != crc:
            sys.exit(f"{args.rom}: checksum {old[0]:08X} {old[1]:08X}, should be {crc[0]:08X} {crc[1]:08X}")
        return
    if old != crc:
        rom[0x10:0x18] = struct.pack(">II", *crc)
        Path(args.rom).write_bytes(rom)
        print(f"{args.rom}: CIC-{cic} checksum set to {crc[0]:08X} {crc[1]:08X}")


main()
