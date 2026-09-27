#!/usr/bin/env bash
# Regenerate the stage-2 hd_code and hd_front_end configs for every version.
#
# Run from the repo root with the module binaries decompressed
# (`make VERSION=<v> decompress` for each version).  Splat is run in blastcorps/
# and leaves that version's asm/ behind, so `make -C blastcorps clean` afterwards.
#
# The bins are the data islands inside .text.  hd_code has six in every
# version, in the same order:
#   1. u16 lookup table (sine) used by the handwritten math routines
#   2. a second u16 table, between two blocks of those routines
#   3. data with code pointers, before a block of handwritten routines
#   4. more such data, after it
#   5. data no code reaches
#   6. RSP microcode, right after libultra's ldiv
# 1, 2, 5 and 6 are byte-identical across versions; 3 and 4 hold pointers, so
# their offsets come from where code stops reaching into them.
set -euo pipefail
cd "$(dirname "$0")/../blastcorps"

GEN="python3 ../tools/gen_code_yaml.py"
EXTRA=("$@")    # e.g. --c

T1="u16 lookup table (sine) for the handwritten math routines around it"
T2="second u16 lookup table of the handwritten math routines"
D1="data with code pointers, ahead of a block of handwritten routines"
D2="more data with code pointers, after that block"
D3="data island; no code reaches it"
UC="RSP microcode; its entry sets sp=0x110 and jumps into IMEM"
FE="RSP microcode (0xFB0 bytes, fits IMEM): sets sp=0x110 and loads from DMEM 0xFC4, so it is not r4300 code"
FE_NOTE="hd_front_end_text is inflated to 0x801E7000 by func_8028B3E0 in hd_code"

hd_code() {  # version data end t1 t2 d1 d2 d3 uc
    local v=$1
    $GEN hd_code "$v" --vram 0x802447C0 --data "$2" --end "$3" \
        --bin "$4:804:$T1" --bin "$5:884:$T2" --bin "$6:1EE0:$D1" \
        --bin "$7:1A4:$D2" --bin "$8:F50:$D3" --bin "$9:37E0:$UC" \
        ${SYMS:+--symbols symbol_addrs.hd_code.$v.txt} "${EXTRA[@]}"
}

hd_front_end() {  # version data end ucode
    local v=$1
    $GEN hd_front_end "$v" --vram 0x801E7000 --data "$2" --end "$3" \
        --bin "$4:FB0:$FE" --note "$FE_NOTE" \
        ${SYMS:+--symbols symbol_addrs.hd_front_end.$v.txt} "${EXTRA[@]}"
}

hd_code us.v10 0xA4360 0xCADF0 0x68790 0x69040 0x7D920 0x8002C 0x8E860 0xA0B80
hd_code us.v11 0xA4410 0xCAEA0 0x68810 0x690C0 0x7D9D0 0x800DC 0x8E910 0xA0C30
hd_code jp     0xA47E0 0xCAF60 0x68B80 0x69430 0x7DDA0 0x804AC 0x8ECE0 0xA1000
hd_code eu     0xA6210 0xCD2D0 0x6B180 0x6BA30 0x80340 0x82A4C 0x91280 0xA2A30

hd_front_end us.v10 0x21010 0x29E60 0x20060
hd_front_end us.v11 0x21040 0x29E90 0x20090
hd_front_end jp     0x20F90 0x29B00 0x1FFE0
hd_front_end eu     0x21990 0x2CAB0 0x209E0
