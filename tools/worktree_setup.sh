#!/usr/bin/env bash
# Make a git worktree of this repo able to build stage 2 on its own.
#
#   tools/worktree_setup.sh <main checkout>
#
# Run from inside the worktree.  A worktree has the tracked files only: no
# submodule contents, no venv, and none of the extracted, untracked outputs
# (blastcorps/asm, assets, the module .bins, the .ld and *_auto.txt files).
# This symlinks those from the main checkout, which must already be
# extracted for the version you want, so the worktree gets its own build/
# but shares everything that only re-extracting would change.  Don't
# re-extract in a worktree set up like this; the links point into the main
# checkout.
set -euo pipefail
MAIN=$(cd "${1:?usage: $0 <main checkout>}" && pwd)
HERE=$(pwd)
[ "$MAIN" != "$HERE" ] || { echo "run this in the worktree, not the main checkout" >&2; exit 1; }

link() {  # path relative to the repo root
    if [ -e "$MAIN/$1" ] && [ ! -e "$HERE/$1" ]; then
        rm -rf "$HERE/$1"
        ln -s "$MAIN/$1" "$HERE/$1"
    fi
}

link .env
for sub in tools/splat tools/asm-differ tools/asm-processor tools/mips_to_c; do
    [ -n "$(ls -A "$HERE/$sub" 2>/dev/null)" ] || { rmdir "$HERE/$sub" 2>/dev/null || true; link "$sub"; }
done
link assets
link blastcorps/asm
link blastcorps/assets
link blastcorps/.version
for f in "$MAIN"/blastcorps/*.bin "$MAIN"/blastcorps/*.ld "$MAIN"/blastcorps/*_auto.*.txt; do
    link "blastcorps/$(basename "$f")"
done
echo "worktree ready: make VERSION=$(cat "$MAIN/blastcorps/.version") -C blastcorps"
