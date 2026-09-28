"""Which objects get translated, and where the build puts things.

Only Rare's handwritten engine is translated.  libultra's own .s files and
init's boot code are exception vectors, TLB/cache maintenance and thread
switching: the port's platform layer replaces them, so a call from translated
code into one of them is an external call like any call into C.
"""

import os
import re

ROOT = os.path.normpath(os.path.join(os.path.dirname(__file__), "..", ".."))
BLAST = os.path.join(ROOT, "blastcorps")

# module -> VRAM of its .text (CLAUDE.md, "Layout notes")
MODULE_VRAM = {
    "init": 0x8021ED00,
    "hd_code": 0x802447C0,
    "hd_front_end": 0x801E7000,
}

# Objects libultra or the boot code own; never translated.
LIBULTRA_ASM = {
    "hd_code": {"906E0", "91820", "91F50", "91F80", "92EA0", "95060",
                "96F70", "96FF0", "971D0", "971F0", "972A0", "97B70",
                "98330", "9DB80", "9E6F0", "A0A30"},
    "hd_front_end": set(),
}


def handwritten_objects(module, version="us.v11"):
    """The `asm` subsegments of a module's config, in link order."""
    path = os.path.join(BLAST, f"{module}.{version}.yaml")
    out = []
    for line in open(path):
        m = re.match(r"\s*- \[(0x[0-9A-Fa-f]+), asm, ([^\]]+)\]", line)
        if m:
            out.append((int(m.group(1), 16), m.group(2).strip()))
    return out


def translated_objects(version="us.v11"):
    """(module, object name, .s path) for every object the translator covers."""
    out = []
    for module in ("hd_code", "hd_front_end"):
        for _, name in handwritten_objects(module, version):
            obj = name.split("/")[-1]
            if obj in LIBULTRA_ASM.get(module, ()):
                continue
            out.append((module, obj, os.path.join(BLAST, "asm", name + ".s")))
    return out
