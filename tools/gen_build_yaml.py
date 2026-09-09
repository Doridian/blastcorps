#!/usr/bin/env python3
"""Generate the top-level splat build config for a Blast Corps ROM.

The top-level config is a plain binary split: every segment is `bin`, so the
linker can glue the pieces back into a byte-identical ROM.  Segment boundaries
are read out of the ROM itself rather than copied from a table, because the
gzip members are self-delimiting and hand-written offsets have been wrong
before (see the us.v10 hd_front_end_data off-by-one).

Usage: gen_build_yaml.py <baserom.z64> <version>  # e.g. baserom.jp.z64 jp
"""
import struct
import sys
import zlib

# Fixed layout, identical in every known revision.
INIT_START = 0x1000
TABLE_START = 0x4CE0  # texture offset/type table, 0x8000 long
BLAST_START = 0xCCE0  # start of the blast-compressed texture blocks
CODE_SECTIONS = (
    "hd_code_text",
    "hd_code_data",
    "hd_front_end_text",
    "hd_front_end_data",
)


def gzip_member(buf, off):
    """Return (length, name, mtime) of the gzip member starting at off."""
    if buf[off : off + 3] != b"\x1f\x8b\x08":
        return None
    flg = buf[off + 3]
    mtime = struct.unpack_from("<I", buf, off + 4)[0]
    p = off + 10
    try:
        if flg & 4:  # FEXTRA
            p += 2 + struct.unpack_from("<H", buf, p)[0]
        name = b""
        if flg & 8:  # FNAME
            end = buf.index(b"\x00", p)
            name, p = buf[p:end], end + 1
        if flg & 16:  # FCOMMENT
            p = buf.index(b"\x00", p) + 1
        if flg & 2:  # FHCRC
            p += 2
        d = zlib.decompressobj(-15)
        d.decompress(buf[p:])
        if not d.eof:
            return None
    except (ValueError, IndexError, zlib.error):
        return None
    # header + deflate stream + CRC32 + ISIZE
    consumed = len(buf) - p - len(d.unused_data)
    return (p - off) + consumed + 8, name.decode(), mtime


def find_members(buf):
    """Every named gzip member in the ROM, in offset order."""
    members, off = [], 0
    while True:
        off = buf.find(b"\x1f\x8b\x08", off)
        if off < 0:
            return members
        found = gzip_member(buf, off)
        if found and found[1]:
            length, name, mtime = found
            members.append((off, length, name, mtime))
            off += length
        else:
            off += 1


def trailer_start(buf, after):
    """Start of the 0xff filler that pads the ROM out to its full size."""
    end = len(buf)
    while end > after and buf[end - 1] == 0xFF:
        end -= 1
    return end


def main():
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    rom_path, version = sys.argv[1], sys.argv[2]
    buf = open(rom_path, "rb").read()
    members = find_members(buf)

    code = {}
    assets = []
    for off, length, name, mtime in members:
        base = name.removesuffix(".raw")
        if base in CODE_SECTIONS:
            code[base] = (off, length, mtime)
        else:
            assets.append((off, length, base, mtime))
    missing = [s for s in CODE_SECTIONS if s not in code]
    if missing:
        sys.exit(f"{rom_path}: could not locate {', '.join(missing)}")

    # `name.mtime` collides for a handful of assets; the first one keeps the
    # plain label and later ones get their ROM offset appended.
    first = {}
    for off, _, base, mtime in assets:
        first.setdefault(f"{base}.raw.{mtime}", off)

    out = [
        "options:",
        "  base_path: .",
        f"  basename: blastcorps.{version}",
        "  compiler: IDO",
        "  create_detected_syms: yes",
        "  find_file_boundaries: yes",
        f"  target_path: baserom.{version}.z64",
        "segments:",
        "  - name:  header",
        "    type:  header",
        "    start: 0x00000000",
        "  - name:  boot",
        "    type:  bin",
        "    start: 0x00000040",
        f"  - [0x{INIT_START:X}, bin, init.{version}]",
        f"  - [0x{TABLE_START:X}, bin]                           "
        "# offsets table (0x8000 long)",
        f"  - [0x{BLAST_START:X}, bin]                           "
        "# blast-compressed textures, tbd",
        "  # TODO: extract each of these",
    ]

    pos = BLAST_START
    for off, length, base, mtime in assets:
        label = f"{base}.raw.{mtime}"
        if first[label] != off:
            label = f"{label}.{off:X}"
        out.append(f"  - [0x{off:X}, bin, {label}]")
        pos = off + length

    out.append("  #")
    comments = {
        "hd_code_text": "main asm code",
        "hd_code_data": "data for main asm",
        "hd_front_end_text": "UI asm code",
        "hd_front_end_data": "data for UI asm",
    }
    for i, section in enumerate(CODE_SECTIONS):
        off, length, mtime = code[section]
        # The run of padding before the first code section is left inside the
        # preceding asset segment, which is opaque anyway.  Padding between the
        # code sections gets its own segment so each one starts on its true
        # offset even after being re-deflated.
        if i and off > pos:
            out.append(f"  - [0x{pos:X}, bin]                            # zero padding")
        name = f"{section}.{version}"
        out.append(f"  - [0x{off:X}, bin, {name}]".ljust(48) + f"# {comments[section]:<18} {mtime}")
        pos = off + length

    trailer = trailer_start(buf, pos)
    if trailer > pos:
        out.append(f"  - [0x{pos:X}, bin]                            # zero padding")
    out.append(f"  - [0x{trailer:X}, bin, trailer]".ljust(48) + "# 0xff to end")
    out.append(f"  - [0x{len(buf):X}]")
    print("\n".join(out))


main()
