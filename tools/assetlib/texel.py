"""N64 texel formats to and from 8-bit PNGs, exactly.

Each format widens to 8 bits the way the RDP does (replicating the high
bits), so narrowing back is a shift and a PNG written here reads back to the
same bytes.  An edited PNG is narrowed the same way (alpha thresholded for
RGBA16).
"""
import struct

import png

BPP = {"rgba16": 2, "rgba32": 4, "ia16": 2, "ia8": 1}   # bytes per texel


def _w5(x):
    return (x << 3) | (x >> 2)


def _w4(x):
    return x * 17


def to_rows(fmt, raw, w, h):
    """(rows, greyscale, alpha) for pypng."""
    rows = []
    bpp = BPP[fmt]
    for y in range(h):
        line = raw[y * w * bpp:(y + 1) * w * bpp]
        row = []
        if fmt == "rgba16":
            for (v,) in struct.iter_unpack(">H", line):
                row += (_w5(v >> 11), _w5((v >> 6) & 31), _w5((v >> 1) & 31), 255 if v & 1 else 0)
        elif fmt == "rgba32":
            row = list(line)
        elif fmt == "ia16":
            row = list(line)
        elif fmt == "ia8":
            for v in line:
                row += (_w4(v >> 4), _w4(v & 15))
        rows.append(row)
    return rows, fmt in ("ia16", "ia8")


def write_png(path, fmt, raw, w, h):
    rows, grey = to_rows(fmt, raw, w, h)
    with open(path, "wb") as f:
        png.Writer(w, h, greyscale=grey, alpha=True, bitdepth=8).write(f, rows)


def read_png(path, fmt):
    """(raw texels, width, height) of a PNG in the given format."""
    r = png.Reader(filename=str(path))
    w, h, rows, info = r.asRGBA8() if fmt in ("rgba16", "rgba32") else _as_la(r)
    out = bytearray()
    for row in rows:
        row = list(row)
        if fmt == "rgba16":
            for i in range(0, len(row), 4):
                red, g, b, a = row[i:i + 4]
                out += struct.pack(">H", (red >> 3) << 11 | (g >> 3) << 6 | (b >> 3) << 1 | (1 if a >= 128 else 0))
        elif fmt == "rgba32":
            out += bytes(row)
        elif fmt == "ia16":
            out += bytes(row)
        elif fmt == "ia8":
            for i in range(0, len(row), 2):
                out.append((row[i] >> 4) << 4 | (row[i + 1] >> 4))
    return bytes(out), w, h


def _as_la(reader):
    """Greyscale + alpha, 8 bits, from any PNG (colour is averaged)."""
    w, h, rows, info = reader.asRGBA8()

    def conv():
        for row in rows:
            row = list(row)
            out = []
            for i in range(0, len(row), 4):
                red, g, b, a = row[i:i + 4]
                out += ((red + g + b) // 3 if not (red == g == b) else red, a)
            yield out
    return w, h, conv(), info
