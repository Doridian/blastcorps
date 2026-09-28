"""The stage-2 modules' memory map, read from their splat configs.

Each config (blastcorps/<module>.<version>.yaml) has one code segment and,
for modules whose .bss is laid out, a top-level `bss:` list that splat
ignores: `[vram, bss|.bss, <module>/<object>]` per object in link order,
then `[end]`.  `bss` is an asm object (tools/split.py writes its .bss as
asm/data/<module>/<object>.bss.s), `.bss` a C file that defines its own.
"""
from pathlib import Path

import yaml

MODULES = ("init", "hd_code", "hd_front_end")


class Module:
    def __init__(self, cfg_path):
        self.cfg_path = Path(cfg_path)
        cfg = yaml.safe_load(self.cfg_path.read_text())
        self.cfg = cfg
        seg = next(s for s in cfg["segments"] if isinstance(s, dict) and s.get("type") == "code")
        self.name = seg["name"]
        self.vram = seg["vram"]
        last = cfg["segments"][-1]
        self.size = last[0] if isinstance(last, list) else last["start"]
        self.end = self.vram + self.size  # end of .text/.data/.rodata
        self.subsegments = seg["subsegments"]
        self.bss = []  # [(vram, kind, name)]
        self.bss_start = self.bss_end = self.end
        entries = cfg.get("bss") or []
        for e in entries:
            if len(e) >= 3:
                self.bss.append((e[0], e[1], e[2]))
            else:
                self.bss_end = e[0]
        if self.bss:
            self.bss_start = self.bss[0][0]

    def contains(self, addr):
        """True if addr is in the module's image or its .bss."""
        return self.vram <= addr < max(self.end, self.bss_end)

    def in_bss(self, addr):
        return self.bss_start <= addr < self.bss_end

    def bss_block(self, addr):
        """(start, end, kind, name) of the .bss block holding addr."""
        for k, (start, kind, name) in enumerate(self.bss):
            end = self.bss[k + 1][0] if k + 1 < len(self.bss) else self.bss_end
            if start <= addr < end:
                return start, end, kind, name
        return None


def modules(version, base="."):
    """{name: Module} for every stage-2 module of this version whose config
    is in base."""
    out = {}
    for name in MODULES:
        path = Path(base) / f"{name}.{version}.yaml"
        if path.exists():
            out[name] = Module(path)
    return out


def owner(mods, addr):
    """The module whose image or .bss holds addr, or None."""
    for m in mods.values():
        if m.contains(addr):
            return m
    return None
