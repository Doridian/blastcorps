"""Level files (the gzip members func_8025615C loads) as YAML.

The layout is LevelHeader's (blastcorps/include/game/level.h): 0xC8 bytes
of header, then the display data segment 8 points at, then the sections
the header's offsets point to, in the order of the header fields (0x20 to
0x74, then 0xA0 to 0xC0).  A section runs to the next one's offset; the
last to the end of the file.  The ten display list offsets at 0x78 point
past the end of the file, into the level's _dl file that is loaded after
it, so they are kept relative to the file's end.

The YAML has the header's numbers, `display: <name>.display.bin`, and one
entry per section.  Sections whose records are understood are lists
(`records`), with any bytes after the last record as `tail`; the rest are
`hex`.  A section is only written as records if they turn back into the
same bytes.  On rebuild every offset is recomputed from the section sizes,
so records can be added or removed.
"""
import struct
from pathlib import Path

# (field, header offset) of the sections, in file order
SECTIONS = [
    ("ammoBoxes", 0x20), ("collisionFixes", 0x24), ("commPoint", 0x28), ("animTextures", 0x2C),
    ("terrain", 0x30), ("rdus", 0x34), ("tntCrates", 0x38), ("blocks", 0x3C),
    ("bounds40", 0x40), ("bounds44", 0x44), ("unk48", 0x48), ("levelBounds", 0x4C),
    ("vehicles", 0x50), ("carrier", 0x54), ("unk58", 0x58), ("buildings", 0x5C),
    ("unk60", 0x60), ("unk64", 0x64), ("trainStops", 0x68), ("collisionXZ", 0x6C),
    ("playerCollisionXZ", 0x70), ("unk74", 0x74),
] + [(f"unkA0_{k}", 0xA0 + 4 * k) for k in range(9)]

# fixed-size records: struct format and field names (docs/blast_corps_levels.txt)
RECORDS = {
    "ammoBoxes": (">hhhh", "x y z type"),
    "collisionFixes": (">hhhhhhhhhh", "x1 y1 z1 x2 y2 z2 x3 y3 z3 pad"),
    "commPoint": (">hhhh", "x y z spin"),
    "rdus": (">hhh", "x y z"),
    "tntCrates": (">hhhBBHH", "x y z b6 timer h8 ha"),
    "bounds40": (">HHHHH", "x1 z1 x2 z2 y"),
    "bounds44": (">HHHHH", "x1 z1 x2 z2 y"),
    "unk48": (">I", "value"),
    "levelBounds": (">HHHH", "x1 z1 x2 z2"),
    "vehicles": (">Bhhhh", "type x y z heading"),
    "carrier": (">BhhhhB", "speed x z heading distance b9"),
    "unk58": (">hhhh", "x y z w"),
    "buildings": (">hhhHBBHH", "x y z type counts b9 behavior speed"),
}
# groups of triangles: u32 end offset (from the section's start), then triangles
GROUPS = {
    "terrain": (">hhhhhhhhhBB", "x1 y1 z1 x2 y2 z2 x3 y3 z3 type flags"),
    "collisionXZ": (">hhhhhhhhhHBB", "x1 y1 z1 x2 y2 z2 x3 y3 z3 a b c"),
    "playerCollisionXZ": (">hhhhhhhhhHBB", "x1 y1 z1 x2 y2 z2 x3 y3 z3 a b c"),
}
HEADER = [("unk0", ">HH", 0x0), ("unk4", ">HH", 0x4), ("unk8", ">HH", 0x8), ("unkC", ">HH", 0xC),
          ("unk10", ">HH", 0x10), ("unk14", ">HH", 0x14), ("gravity", ">i", 0x18), ("unk1C", ">I", 0x1C),
          ("unkC4", ">I", 0xC4)]


def _records(fmt, data):
    size = struct.calcsize(fmt)
    n = len(data) // size
    return [list(struct.unpack_from(fmt, data, k * size)) for k in range(n)], data[n * size:]


def _pack_records(fmt, recs):
    return b"".join(struct.pack(fmt, *r) for r in recs)


def _groups(fmt, data):
    size = struct.calcsize(fmt)
    groups = []
    p = 0
    while p < len(data):
        if p + 4 > len(data):
            return None
        end = struct.unpack_from(">I", data, p)[0]
        if end < p + 4 or end > len(data) or (end - p - 4) % size:
            return None
        groups.append([list(struct.unpack_from(fmt, data, q)) for q in range(p + 4, end, size)])
        p = end
    return groups


def _pack_groups(fmt, groups):
    size = struct.calcsize(fmt)
    out = bytearray()
    for g in groups:
        out += struct.pack(">I", len(out) + 4 + size * len(g))
        out += _pack_records(fmt, g)
    return bytes(out)


def split(data):
    """(header values, display bytes, [(section, bytes)])."""
    offs = [struct.unpack_from(">I", data, h)[0] for _, h in SECTIONS]
    if offs[0] < 0xC8 or any(a > b for a, b in zip(offs, offs[1:])) or offs[-1] > len(data):
        raise ValueError("level: section offsets out of order")
    ends = offs[1:] + [len(data)]
    secs = [(name, data[o:e]) for (name, _), o, e in zip(SECTIONS, offs, ends)]
    dls = [struct.unpack_from(">I", data, 0x78 + 4 * k)[0] - len(data) for k in range(10)]
    head = {name: list(struct.unpack_from(fmt, data, off)) for name, fmt, off in HEADER}
    head["displayLists"] = dls
    return head, data[0xC8:offs[0]], secs


def _num(v):
    return str(v)


def _flow(vals):
    return "[" + ", ".join(_num(v) for v in vals) + "]"


def _hex_block(b, indent):
    lines = [b[k:k + 32].hex() for k in range(0, len(b), 32)]
    return "\n".join(indent + line for line in lines)


def to_yaml(name, data, display_file):
    head, display, secs = split(data)
    out = [f"# level file {name}: see tools/assetlib/level.py and docs/ASSETS.md", "header:"]
    for key, _, _ in HEADER:
        v = head[key]
        out.append(f"  {key}: {v[0] if len(v) == 1 else _flow(v)}")
    out.append(f"  displayLists: {_flow(head['displayLists'])}   # from the end of the file, into the _dl file")
    out.append(f"display: {display_file}")
    out.append("sections:")
    for sec, b in secs:
        out.append(f"  {sec}:")
        body = None
        if sec in RECORDS:
            fmt, names = RECORDS[sec]
            recs, tail = _records(fmt, b)
            if _pack_records(fmt, recs) + tail == b:
                body = [f"    fields: {names}", "    records:"]
                body += [f"    - {_flow(r)}" for r in recs] if recs else []
                if not recs:
                    body[-1] = "    records: []"
                if tail:
                    body.append(f"    tail: '{tail.hex()}'")
        elif sec in GROUPS:
            fmt, names = GROUPS[sec]
            groups = _groups(fmt, b)
            if groups is not None and _pack_groups(fmt, groups) == b:
                body = [f"    fields: {names}", "    groups:" if groups else "    groups: []"]
                for g in groups:
                    if not g:
                        body.append("    - []")
                        continue
                    body.append(f"    - - {_flow(g[0])}")
                    body += [f"      - {_flow(r)}" for r in g[1:]]
        if body is None:
            body = ["    hex: |-", _hex_block(b, "      ")] if b else ["    hex: ''"]
        out += body
    return "\n".join(out) + "\n"


def from_yaml(text, display):
    import yaml
    y = yaml.load(text, Loader=getattr(yaml, "CSafeLoader", yaml.SafeLoader))
    secs = []
    for sec, _ in SECTIONS:
        s = y["sections"][sec]
        if "hex" in s:
            b = bytes.fromhex("".join(str(s["hex"]).split()))
        elif "records" in s:
            b = _pack_records(RECORDS[sec][0], s["records"]) + bytes.fromhex(s.get("tail", ""))
        else:
            b = _pack_groups(GROUPS[sec][0], s["groups"])
        secs.append(b)
    head = bytearray(0xC8)
    for name, fmt, off in HEADER:
        v = y["header"][name]
        struct.pack_into(fmt, head, off, *(v if isinstance(v, list) else [v]))
    pos = 0xC8 + len(display)
    for (sec, h), b in zip(SECTIONS, secs):
        struct.pack_into(">I", head, h, pos)
        pos += len(b)
    for k, d in enumerate(y["header"]["displayLists"]):
        struct.pack_into(">I", head, 0x78 + 4 * k, pos + d)
    return bytes(head) + display + b"".join(secs)


def extract(name, data, out_dir):
    out_dir = Path(out_dir)
    disp = f"{name}.display.bin"
    head, display, _ = split(data)
    (out_dir / disp).write_bytes(display)
    text = to_yaml(name, data, disp)
    if from_yaml(text, display) != data:
        raise ValueError(f"level {name}: YAML doesn't rebuild the file")
    (out_dir / f"{name}.yaml").write_text(text)


def build(yaml_path):
    import yaml
    yaml_path = Path(yaml_path)
    text = yaml_path.read_text()
    disp = yaml.load(text, Loader=getattr(yaml, "CSafeLoader", yaml.SafeLoader))["display"]
    return from_yaml(text, (yaml_path.parent / disp).read_bytes())
