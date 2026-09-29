#!/usr/bin/env python3
"""Generate the top-level splat build config for a Blast Corps ROM.

The top-level config is a plain binary split: every segment is `bin`, so the
linker can glue the pieces back into a byte-identical ROM.  Every piece has
a name (and so a `<name>_ROM_START` symbol, tools/rom_syms.py): the texture
table and textures, the sound banks and sequences, each gzip member (named
after the file name in its header), the LZSS images and data between them,
the model table, the code modules.  The boundaries are read out of the ROM
itself (tools/assetlib/romlayout.py), not copied from a table, because
hand-written offsets have been wrong before (see the us.v10
hd_front_end_data off-by-one).  tools/assets.py turns the asset segments
into editable files and back.

Usage: gen_build_yaml.py <baserom.z64> <version>  # e.g. baserom.jp.z64 jp
"""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from assetlib import romlayout  # noqa: E402

COMMENTS = {
    "texture_table": "offset/length/type of 4096 textures",
    "textures": "blast-compressed textures",
    "music_ctl": "music bank .ctl (LZSS)",
    "music_tbl": "music bank .tbl",
    "sfx_ctl": "sound effects bank .ctl (LZSS)",
    "sfx_tbl": "sound effects bank .tbl",
    "sequences": "ALSeqFile",
    "model_table": "offsets of the models (from here)",
    "static_data": "viewport and display list (LZSS)",
    "hd_code_text": "main asm code",
    "hd_code_data": "data for main asm",
    "hd_front_end_text": "UI asm code",
    "hd_front_end_data": "data for UI asm",
}


def main():
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    rom_path, version = sys.argv[1], sys.argv[2]
    buf = Path(rom_path).read_bytes()
    segs, rom_end = romlayout.discover(buf, version)

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
    ]
    for k, s in enumerate(segs[2:], 2):
        prev = segs[k - 1]
        base = s.name.split(".")[0]
        # Padding between the code modules gets its own segment so each one
        # starts on its true offset even after being re-deflated; before
        # them, each asset segment runs to the next one's start.
        if s.kind in ("module", "copy") and k > 2 and s.start > prev.end and prev.kind == "module":
            out.append(f"  - [0x{prev.end:X}, bin]".ljust(48) + "# zero padding")
        note = COMMENTS.get(base)
        if s.kind == "module":
            note = f"{note:<18} {s.params.get('mtime', '')}".rstrip()
        elif s.kind in ("gzip", "level"):
            note = s.params["gzname"] + (" (level)" if s.kind == "level" else "")
        elif s.kind == "lzss_image":
            note = "320x240 RGBA16 image (LZSS)"
        elif s.name == "trailer":
            note = "0xff to end"
        line = f"  - [0x{s.start:X}, bin, {s.name}]"
        out.append(line.ljust(48) + f"# {note}" if note else line)
    out.append(f"  - [0x{rom_end:X}]")
    print("\n".join(out))


main()
