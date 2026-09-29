#!/usr/bin/env python3
"""Turn splat's MIPS data files into x86 GNU as input, big-endian.

The port keeps memory in the N64's byte order (docs/PORT.md), so every
number is written out as big-endian bytes.  A `.word` that names a symbol
can only be filled in by the host linker, in host order: it becomes a
`.long`, and its address goes into the `port_bswap32` section, which the
runtime swaps once at startup (port/src/startup.c).

  asm2x86.py OUT.s IN.s            a .data/.rodata/.bss file (asm/data, asm/bss)
  asm2x86.py OUT.s IN.bin LABEL    a binary blob (a data island), as LABEL

Each file becomes one section, `.n64.<first label>` (".n64b." for .bss),
which gen_ld.py places at that label's N64 address: the game's data keeps
its N64 layout (docs/PORT.md).  .rodata is writable too, since fixups
write to it.
"""

import re
import struct
import sys

fix_count = 0


def be_bytes(values, size):
    out = []
    for v in values:
        v &= (1 << (8 * size)) - 1
        out += list(v.to_bytes(size, "big"))
    return out


def emit_bytes(out, bs):
    for k in range(0, len(bs), 32):
        out.append(".byte " + ", ".join(f"0x{b:02X}" for b in bs[k:k + 32]))


def split_args(s):
    return [a.strip() for a in s.split(",") if a.strip()]


def is_number(a):
    try:
        int(a, 0)
        return True
    except ValueError:
        return False


def open_section(out, section, label):
    if section == ".bss":
        out.append(f".section .n64b.{label},\"aw\",@nobits")
    else:
        out.append(f".section .n64.{label},\"aw\",@progbits")


def convert(src, label=None):
    global fix_count
    out = []
    section = None
    pending_section = None
    base = re.sub(r"[^A-Za-z0-9_]", "_", src)
    for raw in open(src):
        line = raw.split("#", 1)[0].rstrip() if not raw.lstrip().startswith(".ascii") else raw.rstrip()
        s = line.strip()
        if not s or s.startswith("/*"):
            continue
        if s.startswith(".include"):
            continue
        m = re.match(r"\.section\s+(\S+)", s)
        if m:
            sec = m.group(1).rstrip(",")
            section = ".bss" if sec == ".bss" else ".data"
            pending_section = section
            if label:
                open_section(out, section, label)
                out.append(f".globl {label}")
                out.append(f"{label}:")
                label = None
                pending_section = None
            continue
        m = re.match(r"(dlabel|glabel)\s+(\S+)", s)
        if m and pending_section:
            open_section(out, pending_section, m.group(2))
            pending_section = None
        if m:
            if m.group(1) == "glabel":
                out.append(".balign 4")
            out.append(f".globl {m.group(2)}")
            out.append(f"{m.group(2)}:")
            continue
        m = re.match(r"(\.L\w+):$", s)
        if m:
            out.append(s)
            continue
        m = re.match(r"(\.\w+)\s*(.*)$", s)
        if not m:
            sys.exit(f"asm2x86.py: {src}: can't parse {s!r}")
        d, rest = m.group(1), m.group(2)
        if d == ".byte":
            emit_bytes(out, be_bytes([int(a, 0) for a in split_args(rest)], 1))
        elif d in (".short", ".half"):
            emit_bytes(out, be_bytes([int(a, 0) for a in split_args(rest)], 2))
        elif d in (".word", ".word32"):
            args = split_args(rest)
            pend = []
            for a in args:
                if is_number(a):
                    pend.append(int(a, 0))
                    continue
                if pend:
                    emit_bytes(out, be_bytes(pend, 4))
                    pend = []
                lab = f".Lfix_{base}_{fix_count}"
                fix_count += 1
                out.append(f"{lab}: .long {a}")
                out.append(".pushsection port_bswap32, \"aw\"")
                out.append(f".long {lab}")
                out.append(".popsection")
            if pend:
                emit_bytes(out, be_bytes(pend, 4))
        elif d == ".float":
            bs = []
            for a in split_args(rest):
                bs += list(struct.pack(">f", float(a)))
            emit_bytes(out, bs)
        elif d == ".double":
            bs = []
            for a in split_args(rest):
                bs += list(struct.pack(">d", float(a)))
            emit_bytes(out, bs)
        elif d in (".space", ".skip"):
            out.append(f".space {rest}")
        elif d in (".ascii", ".asciz", ".string"):
            out.append(f"{d} {rest}")
        elif d == ".align":
            out.append(f".p2align {rest}")
        elif d == ".balign":
            out.append(f".balign {rest}")
        elif d in (".size", ".type", ".set", ".global", ".globl", ".local"):
            if d in (".global", ".globl"):
                out.append(f".globl {rest}")
        else:
            sys.exit(f"asm2x86.py: {src}: unsupported directive {d}")
    return out


def main():
    dst, src = sys.argv[1], sys.argv[2]
    if src.endswith(".bin"):
        label = sys.argv[3]
        out = [f".section .n64.{label},\"aw\",@progbits", f".globl {label}", f"{label}:",
               f".incbin \"{src}\""]
    else:
        label = sys.argv[3] if len(sys.argv) > 3 else None
        out = convert(src, label)
    with open(dst, "w") as f:
        f.write("/* generated by port/tools/asm2x86.py from " + src + " */\n")
        f.write("\n".join(out) + "\n")


if __name__ == "__main__":
    main()
