"""What is where in a Blast Corps ROM, read out of the ROM itself.

  0x0000   header, boot code
  0x1000   init (uncompressed code)
  0x4CE0   texture_table: 4096 {offset, length, type} entries (textures.py)
  0xCCE0   textures: the data those entries point to, mostly "blast" compressed
           music_ctl, music_tbl, sfx_ctl, sfx_tbl: two libaudio sound banks,
           the .ctl LZSS-compressed (audio.py, lzss.py)
           sequences: the ALSeqFile
           738 gzip members, named in their headers (levels, their display
           lists, models, images, the code modules), with, between them:
             bg_image_1..3 after attract: 320x240 RGBA16, LZSS
             model_table after reflectlogo_dl: 512 offsets of the models
             static_data before hd_code_text: 0xC0 bytes (a viewport and a
             display list), LZSS
  ...      hd_code_text, hd_code_data, hd_front_end_text, hd_front_end_data
           trailer: 0xFF to the end

Each boundary is found from the data (gzip and LZSS streams end themselves,
the table's last entry, a .ctl's largest wavetable, the ALSeqFile's last
sequence), so the same code handles every version.
"""
import struct
import zlib

from . import audio, lzss, textures

INIT_START = 0x1000
CODE_SECTIONS = ("hd_code_text", "hd_code_data", "hd_front_end_text", "hd_front_end_data")
LEVELS = ["chimp", "lagp", "valley", "fact", "dip", "beetle", "bonus1", "bonus2", "bonus3"] + \
         [f"level{k}" for k in range(9, 60)]
BG_IMAGE_BITS = 13
STATIC_BITS = 10
CTL_BITS = 13


def align(x, a):
    return (x + a - 1) & ~(a - 1)


def gzip_member(buf, off):
    """(length, name, mtime, header length) of the gzip member at off, or None."""
    if buf[off:off + 3] != b"\x1f\x8b\x08":
        return None
    flg = buf[off + 3]
    mtime = struct.unpack_from("<I", buf, off + 4)[0]
    p = off + 10
    try:
        if flg & 4:
            p += 2 + struct.unpack_from("<H", buf, p)[0]
        name = b""
        if flg & 8:
            end = buf.index(b"\x00", p)
            name, p = buf[p:end], end + 1
        if flg & 16:
            p = buf.index(b"\x00", p) + 1
        if flg & 2:
            p += 2
        d = zlib.decompressobj(-15)
        d.decompress(buf[p:])
        if not d.eof:
            return None
    except (ValueError, IndexError, zlib.error):
        return None
    consumed = len(buf) - p - len(d.unused_data)
    return (p - off) + consumed + 8, name.decode(), mtime, p - off


def gzip_members(buf, off):
    out = []
    while True:
        off = buf.find(b"\x1f\x8b\x08", off)
        if off < 0:
            return out
        m = gzip_member(buf, off)
        if m and m[1]:
            out.append((off,) + m)
            off += m[0]
        else:
            off += 1


class Seg:
    """A top-level segment.  `end` is where its data ends (the next segment
    may start later, after padding); `align` is what its start keeps."""

    def __init__(self, name, start, end, kind, align=1, **params):
        self.name, self.start, self.end, self.kind, self.align = name, start, end, kind, align
        self.params = params

    def __repr__(self):
        return f"Seg({self.name}, 0x{self.start:X}-0x{self.end:X}, {self.kind})"


def discover(buf, version):
    segs = [Seg("header", 0, 0x40, "copy"), Seg("boot", 0x40, INIT_START, "copy"),
            Seg(f"init.{version}", INIT_START, textures.TABLE_START, "copy")]
    tstart = textures.TABLE_START
    segs.append(Seg("texture_table", tstart, tstart + textures.TABLE_SIZE, "texture_table", 16))
    blob = tstart + textures.TABLE_SIZE
    _, _, tex_end = textures.parse_table(buf, data_start=blob)
    segs.append(Seg("textures", blob, tex_end, "textures", 16))

    pos = align(tex_end, 16)
    for bank in ("music", "sfx"):
        ctl, n = lzss.decode(buf, pos, CTL_BITS)
        segs.append(Seg(f"{bank}_ctl", pos, pos + n, "lzss", 16, bits=CTL_BITS, file=f"audio/{bank}.ctl"))
        tpos = align(pos + n, 16)
        tend = tpos + audio.tbl_size(ctl)
        segs.append(Seg(f"{bank}_tbl", tpos, tend, "raw", 16, file=f"audio/{bank}.tbl"))
        pos = align(tend, 16)
    send = pos + audio.seq_size(buf[pos:pos + 0x100000])
    segs.append(Seg("sequences", pos, send, "sequences", 16, dir="audio/seq"))

    members = gzip_members(buf, align(send, 16))
    code = {}
    seen = {}
    prev_end = send
    last_asset = None
    for off, length, gzname, mtime, hlen in members:
        base = gzname.removesuffix(".raw")
        if base in CODE_SECTIONS:
            code[base] = (off, length, mtime)
            continue
        # what fills the gap before this member
        gap_start = prev_end
        if off > align(prev_end, 16):
            prev = segs[-1].name
            if prev == "attract":
                p = align(gap_start, 16)
                k = 1
                while p < off:
                    _, n = lzss.decode(buf, p, BG_IMAGE_BITS)
                    segs.append(Seg(f"bg_image_{k}", p, p + n, "lzss_image", 16, bits=BG_IMAGE_BITS,
                                    file=f"images/bg_image_{k}.png", width=320, height=240))
                    p = align(p + n, 16)
                    k += 1
            elif prev == "reflectlogo_dl":
                p = align(gap_start, 16)
                segs.append(Seg("model_table", p, p + 0x800, "model_table", 16))
            else:
                raise ValueError(f"unknown data between 0x{prev_end:X} and 0x{off:X}")
            prev_end = segs[-1].end
        name = base if base not in seen else f"{base}_{off:X}"
        seen[base] = off
        # a member after padding keeps its 16-byte alignment
        al = 16 if off != prev_end and off % 16 == 0 else 1
        kind = "level" if base in LEVELS and name == base else "gzip"
        segs.append(Seg(name, off, off + length, kind, al, gzname=gzname, mtime=mtime))
        prev_end = off + length
        last_asset = segs[-1]
    missing = [s for s in CODE_SECTIONS if s not in code]
    if missing:
        raise ValueError(f"could not locate {', '.join(missing)}")
    first_code = code[CODE_SECTIONS[0]][0]
    p = align(prev_end, 16)
    if p < first_code:
        _, n = lzss.decode(buf, p, STATIC_BITS)
        segs.append(Seg("static_data", p, p + n, "lzss", 16, bits=STATIC_BITS, file="static_data.bin"))
        prev_end = p + n
    if align(prev_end, 16) != first_code:
        raise ValueError(f"unknown data before hd_code_text at 0x{first_code:X}")
    # model table: what each entry points to
    mt = next((s for s in segs if s.kind == "model_table"), None)
    if mt:
        byoff = {s.start: s.name for s in segs}
        ents = struct.unpack_from(">512I", buf, mt.start)
        names = []
        for e in ents:
            a = mt.start + e
            if a in byoff:
                names.append(byoff[a])
            elif a == last_asset.end:
                names.append(None)
            else:
                raise ValueError(f"model table entry 0x{e:X} points at nothing")
        mt.params["entries"] = names
        mt.params["end_of"] = last_asset.name
    for i, sec in enumerate(CODE_SECTIONS):
        off, length, mtime = code[sec]
        segs.append(Seg(f"{sec}.{version}", off, off + length, "module", mtime=mtime))
    end = len(buf)
    trailer = end
    while trailer > segs[-1].end and buf[trailer - 1] == 0xFF:
        trailer -= 1
    segs.append(Seg("trailer", trailer, end, "copy"))
    return segs, end
