"""The texture table (ROM 0x4CE0, 4096 entries) and the texture data after it.

An entry is `u32 offset from the table's start, u16 length, u16 blast type`.
The game DMAs from the entry's offset up to the next entry's, then decodes
(hd_code func_802A08E4 and friends in 5BF40).  In the ROM the data is in
entry order, each piece 8-aligned, and the bytes between one piece and the
next are leftovers of Rare's tool (not zeros), kept here as `pad`.

Entries that hold nothing (unused slots) point at the current position with
whatever length and type they had (0x7FFF, 0xFBC, ...); they are kept as
`slot` entries and follow the data around them when it moves.

textures/textures.yaml, one line per entry:

  {i: 0x001, type: 1, png: [[32, 32]], pad: '259d'}   data, as NNN.png
  {i: 0x444, type: 0}                                 raw data, NNN.bin
  {i: 0x2E5, slot: [0x0000, 0]}                       empty slot: length, type

A texture with `png` has one PNG per image in it (mipmaps: NNN.0.png, ...);
bytes left over after them are NNN.rest.bin.  `lut` names the type-0 entry a
type 4/5 texture's colours come from (a guess, see blast.py).  NNN.blast is
the ROM's compressed stream: the build uses it while the PNGs still decode
from it, and compresses the PNGs itself once they don't.
"""
import struct
from pathlib import Path

from . import blast, texel

TABLE_START = 0x4CE0
TABLE_SIZE = 0x8000
COUNT = TABLE_SIZE // 8


def align8(x):
    return (x + 7) & ~7


def parse_table(rom, table=TABLE_START, data_start=None):
    """[(offset, length, type)] with absolute offsets, and each entry's kind:
    'data' (its bytes are there) or 'slot'."""
    ents = [struct.unpack_from(">IHH", rom, table + 8 * i) for i in range(COUNT)]
    ents = [(o + table, n, t) for o, n, t in ents]
    offs = sorted({o for o, _, _ in ents})
    nxt = {offs[k]: offs[k + 1] if k + 1 < len(offs) else None for k in range(len(offs))}
    pos = data_start if data_start is not None else table + TABLE_SIZE
    kinds = []
    seen = set()
    for o, n, t in ents:
        a = align8(pos)
        if o == a and n and o not in seen and nxt[o] is not None and align8(o + n) == nxt[o]:
            kinds.append("data")
            seen.add(o)
            pos = o + n
        elif o == a:
            kinds.append("slot")
        else:
            raise ValueError(f"texture table: entry {len(kinds):03X} at 0x{o:X} isn't at the current position 0x{a:X}")
    return ents, kinds, pos


def guess_lut(i, t, ents, kinds):
    """The type-0 entry before a type 4/5 texture that its LUT probably is:
    the nearest earlier 0x80-byte one for type 4, 0x100-byte for type 5."""
    want = 0x80 if t == 4 else 0x100
    for j in range(i - 1, -1, -1):
        o, n, tt = ents[j]
        if kinds[j] == "data" and tt == 0 and n == want:
            return j
    return None


def image_plan(size, t, hint):
    """[(w, h)] of the images in `size` decoded bytes, from a hint list, else
    one image 32 texels wide (or narrower, if that doesn't divide)."""
    fmt = blast.FORMAT[t]
    bpp = texel.BPP[fmt]
    if hint and sum(w * h * bpp for w, h in hint) <= size:
        return list(hint)
    for w in (32, 16, 8, 4, 2, 1):
        if size % (w * bpp) == 0 and size // (w * bpp) > 0:
            return [(w, size // (w * bpp))]
    return []


def extract(rom, out_dir, hints, blob_start, blob_end):
    """Write textures/ from the ROM.  hints: {index: [(w, h)]}."""
    out_dir = Path(out_dir)
    out_dir.mkdir(parents=True, exist_ok=True)
    ents, kinds, end = parse_table(rom, data_start=blob_start)
    if end > blob_end:
        raise ValueError("texture data runs past its segment")
    data_offs = [ents[i][0] for i in range(COUNT) if kinds[i] == "data"]
    lines = ["# Blast Corps texture table: one entry per line, see tools/assetlib/textures.py"]
    for i, ((o, n, t), kind) in enumerate(zip(ents, kinds)):
        if kind == "slot":
            lines.append(f"- {{i: 0x{i:03X}, slot: [0x{n:04X}, {t}]}}")
            continue
        stream = rom[o:o + n]
        nxt = align8(o + n)
        pad = rom[o + n:nxt]
        fields = [f"i: 0x{i:03X}", f"type: {t}"]
        name = f"{i:03X}"
        if t == 0:
            (out_dir / f"{name}.bin").write_bytes(stream)
        else:
            lut = None
            if t in (4, 5):
                j = guess_lut(i, t, ents, kinds)
                if j is None:
                    raise ValueError(f"texture {i:03X}: no LUT")
                lo, ln, _ = ents[j]
                lut = rom[lo:lo + ln]
                fields.append(f"lut: 0x{j:03X}")
            raw = blast.decode(t, stream, lut)
            (out_dir / f"{name}.blast").write_bytes(stream)
            plan = image_plan(len(raw), t, hints.get(i))
            fmt = blast.FORMAT[t]
            bpp = texel.BPP[fmt]
            p = 0
            for k, (w, h) in enumerate(plan):
                fn = f"{name}.png" if len(plan) == 1 else f"{name}.{k}.png"
                texel.write_png(out_dir / fn, fmt, raw[p:p + w * h * bpp], w, h)
                p += w * h * bpp
            if p < len(raw):
                (out_dir / f"{name}.rest.bin").write_bytes(raw[p:])
            fields.append("png: [" + ", ".join(f"[{w}, {h}]" for w, h in plan) + "]")
        if any(pad):
            fields.append(f"pad: '{pad.hex()}'")
        lines.append("- {" + ", ".join(fields) + "}")
    (out_dir / "textures.yaml").write_text("\n".join(lines) + "\n")


def load_list(src_dir):
    import yaml
    return yaml.load((Path(src_dir) / "textures.yaml").read_text(), Loader=getattr(yaml, "CSafeLoader", yaml.SafeLoader))


def build(src_dir, blob_start, table_start=TABLE_START, stats=None):
    """(table bytes, blob bytes) with the blob placed at blob_start."""
    src_dir = Path(src_dir)
    items = load_list(src_dir)
    if len(items) != COUNT:
        raise ValueError(f"{src_dir}/textures.yaml: {len(items)} entries, want {COUNT}")
    blob = bytearray()
    table = bytearray()
    built = {}   # index -> bytes, for the LUTs
    pos = blob_start
    prev = None
    for n, it in enumerate(items):
        if it["i"] != n:
            raise ValueError(f"textures.yaml: entry {n:03X} is numbered 0x{it['i']:X}")
        a = align8(pos)
        if "slot" in it:
            ln, t = it["slot"]
            table += struct.pack(">IHH", a - table_start, ln, t)
            continue
        t = it["type"]
        name = f"{n:03X}"
        if t == 0:
            data = (src_dir / f"{name}.bin").read_bytes()
        else:
            lut = built[it["lut"]] if "lut" in it else None
            fmt = blast.FORMAT[t]
            raw = bytearray()
            plan = it["png"]
            for k, (w, h) in enumerate(plan):
                fn = f"{name}.png" if len(plan) == 1 else f"{name}.{k}.png"
                px, pw, ph = texel.read_png(src_dir / fn, fmt)
                if (pw, ph) != (w, h):
                    raise ValueError(f"{src_dir / fn}: {pw}x{ph}, textures.yaml says {w}x{h}")
                raw += px
            rest = src_dir / f"{name}.rest.bin"
            if rest.exists():
                raw += rest.read_bytes()
            orig = src_dir / f"{name}.blast"
            data = orig.read_bytes() if orig.exists() else None
            if data is None or blast.decode(t, data, lut) != bytes(raw):
                data = blast.encode(t, bytes(raw), lut)
                if stats is not None:
                    stats.append(name)
        built[n] = data
        gap = a - pos
        if gap:
            pad = bytes(gap)
            if prev is not None and "pad" in items[prev]:
                orig_pad = bytes.fromhex(items[prev]["pad"])
                if len(orig_pad) == gap:   # the ROM's leftovers, if the gap is still that size
                    pad = orig_pad
            blob += pad
        table += struct.pack(">IHH", a - table_start, len(data), t)
        blob += data
        pos = a + len(data)
        prev = n
    return bytes(table), bytes(blob)
