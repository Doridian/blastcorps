#!/usr/bin/env python3
"""Relabel an IDO -mips3 -32 object as mips2 so GNU ld will link it.

libultra's ll.c is built -mips3 -32 for its 64-bit arithmetic, but everything
else is -mips2, and ld refuses to mix the two ("linking 32-bit code with
64-bit code").  The code itself is what it is; only the EF_MIPS_ARCH field of
the ELF header changes.

    tools/elf_mips2.py <object>
"""
import struct
import sys

EF_MIPS_ARCH = 0xF0000000
EF_MIPS_ARCH_2 = 0x10000000
E_FLAGS = 0x24  # offset in a 32-bit ELF header

with open(sys.argv[1], "r+b") as f:
    head = f.read(E_FLAGS + 4)
    assert head[:4] == b"\x7fELF" and head[4] == 1 and head[5] == 2, "not a 32-bit big-endian ELF"
    flags = struct.unpack_from(">I", head, E_FLAGS)[0]
    f.seek(E_FLAGS)
    f.write(struct.pack(">I", (flags & ~EF_MIPS_ARCH) | EF_MIPS_ARCH_2))
