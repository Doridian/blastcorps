"""VR4300 (MIPS III) instruction decoder.

Decodes a raw 32-bit instruction word into an `Insn`.  The translator decodes
the word that splat prints in each line's comment instead of parsing the
mnemonic text: the word is exactly what the ROM holds, so no pseudo-op
(`b`, `beqz`, `neg`, `li`...) or operand spelling can be misread.  Symbolic
operands (%hi/%lo, branch labels, jal targets) still come from the text; see
parse.py.
"""

from dataclasses import dataclass, field

GPR_NAMES = [
    "zero", "at", "v0", "v1", "a0", "a1", "a2", "a3",
    "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7",
    "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7",
    "t8", "t9", "k0", "k1", "gp", "sp", "fp", "ra",
]


@dataclass
class Insn:
    word: int
    op: str                 # canonical mnemonic ("addiu", "c.lt.s", ...)
    rs: int = 0
    rt: int = 0
    rd: int = 0
    sa: int = 0
    imm: int = 0            # sign-extended 16-bit immediate
    uimm: int = 0           # zero-extended 16-bit immediate
    target: int = 0         # j/jal: 26-bit index
    fs: int = 0
    ft: int = 0
    fd: int = 0
    fmt: str = ""           # "s", "d", "w", "l" for COP1 arithmetic
    code: int = 0           # break/syscall code
    cond: int = 0           # c.cond.fmt condition (0..15)

    # classification, filled in by decode()
    kind: str = "alu"       # alu, load, store, branch, jump, trap, cop0, cop1, misc
    likely: bool = False
    link: bool = False


class DecodeError(Exception):
    pass


def _s16(x):
    x &= 0xFFFF
    return x - 0x10000 if x & 0x8000 else x


SPECIAL = {
    0x00: "sll", 0x02: "srl", 0x03: "sra", 0x04: "sllv", 0x06: "srlv",
    0x07: "srav", 0x08: "jr", 0x09: "jalr", 0x0C: "syscall", 0x0D: "break",
    0x0F: "sync", 0x10: "mfhi", 0x11: "mthi", 0x12: "mflo", 0x13: "mtlo",
    0x14: "dsllv", 0x16: "dsrlv", 0x17: "dsrav", 0x18: "mult", 0x19: "multu",
    0x1A: "div", 0x1B: "divu", 0x1C: "dmult", 0x1D: "dmultu", 0x1E: "ddiv",
    0x1F: "ddivu", 0x20: "add", 0x21: "addu", 0x22: "sub", 0x23: "subu",
    0x24: "and", 0x25: "or", 0x26: "xor", 0x27: "nor", 0x2A: "slt",
    0x2B: "sltu", 0x2C: "dadd", 0x2D: "daddu", 0x2E: "dsub", 0x2F: "dsubu",
    0x30: "tge", 0x31: "tgeu", 0x32: "tlt", 0x33: "tltu", 0x34: "teq",
    0x36: "tne", 0x38: "dsll", 0x3A: "dsrl", 0x3B: "dsra", 0x3C: "dsll32",
    0x3E: "dsrl32", 0x3F: "dsra32",
}

REGIMM = {
    0x00: "bltz", 0x01: "bgez", 0x02: "bltzl", 0x03: "bgezl",
    0x08: "tgei", 0x09: "tgeiu", 0x0A: "tlti", 0x0B: "tltiu", 0x0C: "teqi",
    0x0E: "tnei", 0x10: "bltzal", 0x11: "bgezal", 0x12: "bltzall",
    0x13: "bgezall",
}

PRIMARY = {
    0x02: "j", 0x03: "jal", 0x04: "beq", 0x05: "bne", 0x06: "blez",
    0x07: "bgtz", 0x08: "addi", 0x09: "addiu", 0x0A: "slti", 0x0B: "sltiu",
    0x0C: "andi", 0x0D: "ori", 0x0E: "xori", 0x0F: "lui", 0x14: "beql",
    0x15: "bnel", 0x16: "blezl", 0x17: "bgtzl", 0x18: "daddi",
    0x19: "daddiu", 0x1A: "ldl", 0x1B: "ldr", 0x20: "lb", 0x21: "lh",
    0x22: "lwl", 0x23: "lw", 0x24: "lbu", 0x25: "lhu", 0x26: "lwr",
    0x27: "lwu", 0x28: "sb", 0x29: "sh", 0x2A: "swl", 0x2B: "sw",
    0x2C: "sdl", 0x2D: "sdr", 0x2E: "swr", 0x2F: "cache", 0x30: "ll",
    0x31: "lwc1", 0x34: "lld", 0x35: "ldc1", 0x37: "ld", 0x38: "sc",
    0x39: "swc1", 0x3C: "scd", 0x3D: "sdc1", 0x3F: "sd",
}

LOADS = {"lb", "lbu", "lh", "lhu", "lw", "lwu", "ld", "lwl", "lwr", "ldl",
         "ldr", "lwc1", "ldc1", "ll", "lld"}
STORES = {"sb", "sh", "sw", "sd", "swl", "swr", "sdl", "sdr", "swc1",
          "sdc1", "sc", "scd"}
BRANCHES = {"beq", "bne", "blez", "bgtz", "beql", "bnel", "blezl", "bgtzl",
            "bltz", "bgez", "bltzl", "bgezl", "bltzal", "bgezal", "bltzall",
            "bgezall", "bc1f", "bc1t", "bc1fl", "bc1tl"}
TRAPS = {"syscall", "break", "tge", "tgeu", "tlt", "tltu", "teq", "tne",
         "tgei", "tgeiu", "tlti", "tltiu", "teqi", "tnei"}

COP1_FUNCT = {
    0x00: "add", 0x01: "sub", 0x02: "mul", 0x03: "div", 0x04: "sqrt",
    0x05: "abs", 0x06: "mov", 0x07: "neg", 0x08: "round.l", 0x09: "trunc.l",
    0x0A: "ceil.l", 0x0B: "floor.l", 0x0C: "round.w", 0x0D: "trunc.w",
    0x0E: "ceil.w", 0x0F: "floor.w", 0x20: "cvt.s", 0x21: "cvt.d",
    0x24: "cvt.w", 0x25: "cvt.l",
}
FMT = {16: "s", 17: "d", 20: "w", 21: "l"}
FCOND = ["f", "un", "eq", "ueq", "olt", "ult", "ole", "ule",
         "sf", "ngle", "seq", "ngl", "lt", "nge", "le", "ngt"]


def decode(word):
    op = word >> 26
    rs = (word >> 21) & 31
    rt = (word >> 16) & 31
    rd = (word >> 11) & 31
    sa = (word >> 6) & 31
    funct = word & 63
    i = Insn(word=word, op="?", rs=rs, rt=rt, rd=rd, sa=sa,
             imm=_s16(word), uimm=word & 0xFFFF, target=word & 0x3FFFFFF,
             fs=rd, ft=rt, fd=sa)
    if op == 0:
        name = SPECIAL.get(funct)
        if name is None:
            raise DecodeError(f"SPECIAL funct {funct:#x} in {word:08X}")
        i.op = name
        if name in ("syscall", "break"):
            i.code = (word >> 6) & 0xFFFFF
        if name in ("jr", "jalr"):
            i.kind = "jump"
            i.link = name == "jalr"
        elif name in TRAPS:
            i.kind = "trap"
        elif name == "sync":
            i.kind = "misc"
    elif op == 1:
        name = REGIMM.get(rt)
        if name is None:
            raise DecodeError(f"REGIMM rt {rt:#x} in {word:08X}")
        i.op = name
        if name in BRANCHES:
            i.kind = "branch"
            i.likely = name.endswith("l") and name not in ("bltzal", "bgezal")
            i.link = "al" in name
        else:
            i.kind = "trap"
    elif op == 0x10:
        # COP0
        if rs == 0:
            i.op, i.kind = "mfc0", "cop0"
        elif rs == 1:
            i.op, i.kind = "dmfc0", "cop0"
        elif rs == 4:
            i.op, i.kind = "mtc0", "cop0"
        elif rs == 5:
            i.op, i.kind = "dmtc0", "cop0"
        elif rs == 16:
            name = {1: "tlbr", 2: "tlbwi", 6: "tlbwr", 8: "tlbp",
                    0x18: "eret"}.get(funct)
            if name is None:
                raise DecodeError(f"COP0 CO funct {funct:#x} in {word:08X}")
            i.op, i.kind = name, "cop0"
        else:
            raise DecodeError(f"COP0 rs {rs:#x} in {word:08X}")
    elif op == 0x11:
        # COP1
        i.kind = "cop1"
        if rs in (0, 1, 2, 4, 5, 6):
            i.op = {0: "mfc1", 1: "dmfc1", 2: "cfc1", 4: "mtc1", 5: "dmtc1",
                    6: "ctc1"}[rs]
        elif rs == 8:
            nd_tf = rt & 3
            i.op = ["bc1f", "bc1t", "bc1fl", "bc1tl"][nd_tf]
            i.kind = "branch"
            i.likely = bool(nd_tf & 2)
        elif rs in FMT:
            fmt = FMT[rs]
            i.fmt = fmt
            if funct >= 0x30:
                i.cond = funct & 15
                i.op = f"c.{FCOND[i.cond]}.{fmt}"
                i.fd = 0
            else:
                base = COP1_FUNCT.get(funct)
                if base is None:
                    raise DecodeError(f"COP1 funct {funct:#x} in {word:08X}")
                i.op = f"{base}.{fmt}"
        else:
            raise DecodeError(f"COP1 rs {rs:#x} in {word:08X}")
    else:
        name = PRIMARY.get(op)
        if name is None:
            raise DecodeError(f"opcode {op:#x} in {word:08X}")
        i.op = name
        if name in ("j", "jal"):
            i.kind = "jump"
            i.link = name == "jal"
        elif name in BRANCHES:
            i.kind = "branch"
            i.likely = name.endswith("l")
        elif name in LOADS:
            i.kind = "load"
        elif name in STORES:
            i.kind = "store"
        elif name == "cache":
            i.kind = "misc"
    return i


# Text mnemonics splat prints that are aliases of the canonical op, used by
# parse.py to cross-check the decoder against the listing.
ALIASES = {
    "nop": {"sll"}, "b": {"beq"}, "beqz": {"beq"}, "bnez": {"bne"},
    "beqzl": {"beql"}, "bnezl": {"bnel"}, "bal": {"bgezal"},
    "neg": {"sub"}, "negu": {"subu"}, "dneg": {"dsub"}, "dnegu": {"dsubu"},
    "not": {"nor"}, "move": {"or", "addu", "daddu"}, "li": {"addiu", "ori"},
    "mul.s": {"mul.s"},
}


def text_matches(text_op, insn):
    if text_op == insn.op:
        return True
    return insn.op in ALIASES.get(text_op, ())
