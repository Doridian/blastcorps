"""The ROM's gzip members, as tools/rarezip.py makes them: gzip 1.2.4
(tools/gzip) at -6, with Rare's header (FNAME set, the original file's name
and mtime, OS 3).  Every one of the 738 members in each ROM recompresses to
the same bytes this way."""
import struct
import subprocess
import zlib
from pathlib import Path

GZIP = Path(__file__).resolve().parent.parent / "gzip"


def compress(data, name, mtime, level=6):
    res = subprocess.run([str(GZIP), f"-{level}", "--no-name", "-c"], input=data, capture_output=True, check=True)
    return (b"\x1f\x8b\x08\x08" + struct.pack("<I", mtime) + b"\x00\x03" + name.encode() + b"\x00"
            + res.stdout[10:])


def decompress(member):
    d = zlib.decompressobj(31)
    out = d.decompress(member)
    if not d.eof:
        raise ValueError("truncated gzip member")
    return out
