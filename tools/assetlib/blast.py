"""Rare's texture compression ("blast"), the decoders func_802A57DC picks by
the type in the texture table (hd_code 60F60, docs/blast_corps_docs.txt).

Every type but 0 is a stream of big-endian u16 codes.  A code with the top
bit clear is one literal texel (or two, for types 4 and 6); with it set it
copies `length` (bits 0-4) texels from `offset` bytes back in the output.

  type  texels         literal                          back-reference
  0     (raw bytes)    -                                -
  1     RGBA16         RGBA5551 minus green's low bit   byte offset 0x7FFF >> 5, u16 units
  2     RGBA32         RGBA 4444 in the top bits (+alpha's low bits 0)  offset 0x7FE0 >> 4, u32 units
  3     IA16           I7 A7 (low bits 0)               as type 1
  4     RGBA16 x 2     two 7-bit LUT indices + alpha bit as type 2
  5     RGBA32         11-bit LUT index + 4 alpha bits  as type 2
  6     IA8 x 2        two I3A3 (low bits 0)            as type 1

Types 4 and 5 read a table of RGBA5551-without-alpha u16s (a type-0 entry
of the texture table, 0x80 or 0x100 bytes) from a pointer the loader sets
up; which one belongs to which texture is not known yet (see ASSETS.md).

The compression is lossy and Rare's encoder matched on the source texels
before they were quantized, so its back-references can't be recomputed from
the decoded texture: of 1.15M codes, 45k copies are shorter than the longest
available and 28k literals had a copy available.  (Where it did take the
longest, it took the farthest.)  encode() here is greedy, farthest-first;
its output decodes to the same texels but is not Rare's stream.
"""
import struct

ELEM = {1: 2, 2: 4, 3: 2, 4: 4, 5: 4, 6: 2}   # bytes per back-reference unit
FORMAT = {1: "rgba16", 2: "rgba32", 3: "ia16", 4: "rgba16", 5: "rgba32", 6: "ia8"}
MAX_LEN = 31
MAX_OFF_UNITS = 511


def _offset(code, t):
    return ((code & 0x7FFF) >> 5) if ELEM[t] == 2 else ((code & 0x7FE0) >> 4)


def literal(code, t, lut):
    """The texel bytes of a literal code."""
    if t == 1:
        return struct.pack(">H", ((code & 0xFFC0) << 1) | (code & 0x3F))
    if t == 2:
        return struct.pack(">I", ((code & 0x7800) << 17) | ((code & 0x780) << 13)
                           | ((code & 0x78) << 9) | ((code & 0x7) << 5))
    if t == 3:
        return bytes(((code >> 8) << 1 & 0xFF, (code & 0xFF) << 1 & 0xFF))
    if t == 4:
        hi = code >> 8
        a = (struct.unpack_from(">H", lut, hi & 0xFE)[0] << 1 | (hi & 1)) & 0xFFFF
        b = (struct.unpack_from(">H", lut, code & 0xFE)[0] << 1 | (code & 1)) & 0xFFFF
        return struct.pack(">HH", a, b)
    if t == 5:
        e = struct.unpack_from(">H", lut, (code >> 4) << 1)[0]
        return struct.pack(">I", ((e & 0x7C00) << 17) | ((e & 0x3E0) << 14)
                           | ((e & 0x1F) << 11) | ((code & 0xF) << 4))
    if t == 6:
        hi, lo = code >> 8, code & 0xFF
        return bytes((((hi & 0x38) << 2) | ((hi & 7) << 1), ((lo & 0x38) << 2) | ((lo & 7) << 1)))
    raise ValueError(f"blast type {t}")


def decode(t, stream, lut=None):
    if t == 0:
        return bytes(stream)
    out = bytearray()
    es = ELEM[t]
    for (code,) in struct.iter_unpack(">H", stream[: len(stream) & ~1]):
        if code & 0x8000:
            n = (code & 0x1F) * es
            start = len(out) - _offset(code, t)
            for k in range(n):         # may overlap what it writes
                out.append(out[start + k])
        else:
            out += literal(code, t, lut)
    return bytes(out)


def _nearest(table, want, key):
    """Index of the table entry closest to want (exact if there is one)."""
    if want in key:
        return key[want]
    best = min(range(len(table)), key=lambda i: sum((a - b) ** 2 for a, b in zip(table[i], want)))
    key[want] = best
    return best


def literals(t, raw, lut=None):
    """The literal code for each back-reference unit of raw (quantizing what
    the format can't hold)."""
    es = ELEM[t]
    codes = []
    if t in (4, 5):
        n = len(lut) // 2
        ents = struct.unpack(f">{n}H", lut[: 2 * n])
        rgb = [((e >> 10) & 31, (e >> 5) & 31, e & 31) for e in ents]
        cache = {}
    for i in range(0, len(raw), es):
        u = raw[i:i + es]
        if t == 1:
            v = struct.unpack(">H", u)[0]
            codes.append(((v >> 1) & 0x7FC0) | (v & 0x3F))
        elif t == 2:
            r, g, b, a = u
            codes.append(((r >> 4) << 11) | ((g >> 4) << 7) | ((b >> 4) << 3) | (a >> 5))
        elif t == 3:
            codes.append(((u[0] >> 1) << 8) | (u[1] >> 1))
        elif t == 6:
            def half(x):
                return (((x >> 5) & 7) << 3) | ((x >> 1) & 7)
            codes.append((half(u[0]) << 8) | half(u[1]))
        elif t == 4:
            a, b = struct.unpack(">HH", u)
            ia = _nearest(rgb[:128], ((a >> 11) & 31, (a >> 6) & 31, (a >> 1) & 31), cache)
            ib = _nearest(rgb[:128], ((b >> 11) & 31, (b >> 6) & 31, (b >> 1) & 31), cache)
            codes.append((ia << 9) | ((a & 1) << 8) | (ib << 1) | (b & 1))
        elif t == 5:
            r, g, b, a = u
            idx = _nearest(rgb[:0x800], (r >> 3, g >> 3, b >> 3), cache)
            codes.append((idx << 4) | (a >> 4))
    return codes


def encode(t, raw, lut=None):
    """A stream that decodes to raw (as the format quantizes it)."""
    if t == 0:
        return bytes(raw)
    codes = literals(t, raw, lut)
    units = [literal(c, t, lut) for c in codes]   # what the decoder makes
    es = ELEM[t]
    out = []
    r = 0
    n = len(units)
    while r < n:
        best, bd = 0, 0
        for d in range(min(MAX_OFF_UNITS, r), 0, -1):   # farthest first
            j = 0
            while j < MAX_LEN and r + j < n and units[r - d + j] == units[r + j]:
                j += 1
            if j > best:
                best, bd = j, d
                if j == MAX_LEN:
                    break
        if best >= 2:
            off = bd * es
            out.append(0x8000 | ((off << 5) if es == 2 else (off << 4)) | best)
            r += best
        else:
            out.append(codes[r])
            r += 1
    return struct.pack(f">{len(out)}H", *out)
