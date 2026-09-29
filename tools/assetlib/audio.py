"""libaudio's files: the sound banks (.ctl, .tbl) and the sequence bank.

hd_code 1C460.c loads two banks (music, then sound effects).  Each .ctl is
an ALBankFile ("B1"), LZSS-compressed in the ROM (13 index bits) and
inflated to RAM for alBnkfNew; its wavetables' `base` fields are offsets
into the .tbl, which stays uncompressed in the ROM (the synthesizer DMAs
samples from it) and whose ROM address alBnkfNew adds.  The sequence bank
is an ALSeqFile ("S1": revision, count, then {offset, length} per
sequence), uncompressed, whose offsets alSeqFileNew rebases to its ROM
address; the sequences are libaudio's .seq (16 track offsets, then MIDI).
"""
import struct
from pathlib import Path


def ctl_waves(ctl):
    """[(base, length)] of the wavetables an ALBankFile uses."""
    rev, nbanks = struct.unpack_from(">hh", ctl, 0)
    if rev != 0x4231:
        raise ValueError("not an ALBankFile")
    out = set()
    for b in struct.unpack_from(f">{nbanks}i", ctl, 4):
        ninst, _, _, _, perc = struct.unpack_from(">hBBii", ctl, b)
        insts = list(struct.unpack_from(f">{ninst}i", ctl, b + 12))
        if perc:
            insts.append(perc)
        for ins in filter(None, insts):
            (nsnd,) = struct.unpack_from(">h", ctl, ins + 14)
            for s in struct.unpack_from(f">{nsnd}i", ctl, ins + 16):
                (wt,) = struct.unpack_from(">i", ctl, s + 8)
                out.add(struct.unpack_from(">ii", ctl, wt))
    return sorted(out)


def tbl_size(ctl):
    return max(b + n for b, n in ctl_waves(ctl))


def seq_split(data):
    """(revision, [(sequence bytes, pad after it)]) of an ALSeqFile."""
    rev, n = struct.unpack_from(">hh", data, 0)
    if rev != 0x5331:
        raise ValueError("not an ALSeqFile")
    ents = [struct.unpack_from(">ii", data, 4 + 8 * k) for k in range(n)]
    out = []
    for k, (o, ln) in enumerate(ents):
        nxt = ents[k + 1][0] if k + 1 < n else o + ln
        out.append((data[o:o + ln], data[o + ln:nxt]))
    if ents and ents[0][0] != 4 + 8 * n:
        raise ValueError("ALSeqFile: sequences don't follow the header")
    return rev, out


def seq_size(data):
    rev, n = struct.unpack_from(">hh", data, 0)
    return max(o + ln for o, ln in (struct.unpack_from(">ii", data, 4 + 8 * k) for k in range(n)))


def seq_join(seqs, pads=None):
    """An ALSeqFile of the sequences, each 4-aligned (the ROM's layout)."""
    n = len(seqs)
    head = bytearray(struct.pack(">hh", 0x5331, n))
    body = bytearray()
    pos = 4 + 8 * n
    for k, s in enumerate(seqs):
        head += struct.pack(">ii", pos + len(body), len(s))
        body += s
        if k + 1 < n:
            gap = (-(pos + len(body))) % 4
            pad = pads[k] if pads and len(pads[k]) == gap else bytes(gap)
            body += pad
    return bytes(head + body)


def seq_extract(data, out_dir):
    out_dir = Path(out_dir)
    out_dir.mkdir(parents=True, exist_ok=True)
    rev, seqs = seq_split(data)
    lines = ["# the sequence bank (ALSeqFile): one .seq per line, in order; see tools/assetlib/audio.py"]
    for k, (s, pad) in enumerate(seqs):
        (out_dir / f"{k:02d}.seq").write_bytes(s)
        lines.append(f"- {{file: {k:02d}.seq" + (f", pad: '{pad.hex()}'" if any(pad) else "") + "}")
    (out_dir / "sequences.yaml").write_text("\n".join(lines) + "\n")
    if seq_build(out_dir) != data:
        raise ValueError("sequence bank doesn't rebuild")


def seq_build(src_dir):
    import yaml
    src_dir = Path(src_dir)
    items = yaml.safe_load((src_dir / "sequences.yaml").read_text())
    seqs = [(src_dir / it["file"]).read_bytes() for it in items]
    pads = [bytes.fromhex(it.get("pad", "")) for it in items]
    return seq_join(seqs, pads)
