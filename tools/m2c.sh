#!/usr/bin/env bash
# First-draft C for one function:  tools/m2c.sh <module> <function> [m2c args]
#
# Finds the function's .s under blastcorps/asm/nonmatchings and runs m2c on it
# with the project venv (m2c needs pycparser<3).
set -euo pipefail
ROOT=$(cd "$(dirname "$0")/.." && pwd)
MOD=${1:?usage: $0 <module> <function> [m2c args]}
FN=${2:?usage: $0 <module> <function> [m2c args]}
shift 2
ASM=$(find "$ROOT/blastcorps/asm/nonmatchings/$MOD" -name "$FN.s" | head -1)
[ -n "$ASM" ] || { echo "no $FN.s under asm/nonmatchings/$MOD" >&2; exit 1; }
cd "$ROOT"
exec .env/bin/python tools/mips_to_c/m2c.py "$@" "$ASM"
