#!/usr/bin/env bash
# Build the libultra reference objects tools/libmatch.py compares against.
#
#   tools/build_ultralib.sh <dir>
#
# Clones decompals/ultralib into <dir> and builds libultra_rom 2.0I, J and K
# with IDO 5.3, plus a 2.0I variant with every directory at -O1.  Blast Corps
# links an older libultra whose libc (sprintf, _Litob, _Ldtob) was built at
# -O1 where ultralib's 2.0I uses -O3; only the variant reproduces those.
#
# Prints the object directories to pass to libmatch.py / gen_symbols.py.
set -euo pipefail

DIR=${1:?usage: $0 <dir>}
REV=e24c836796df4bf520ff8b11a5c9d2cea3a66cbd

if [ ! -d "$DIR/.git" ]; then
    git clone -q https://github.com/decompals/ultralib "$DIR"
fi
cd "$DIR"
git checkout -q "$REV"
make -C tools >/dev/null    # fetches IDO 5.3 (and the GCC tools ultralib also wants)

build() {  # version build-root
    make -j"$(nproc)" VERSION="$1" TARGET=libultra_rom COMPARE=0 BUILD_ROOT="$2" >/dev/null
}

for v in I J K; do
    build "$v" build
done

# The -O1 variant: drop the block that raises libc, gu, audio, ... to -O3.
cp makefiles/ido.mk makefiles/ido.mk.orig
trap 'mv makefiles/ido.mk.orig makefiles/ido.mk' EXIT
python3 - <<'EOF'
import re
p = "makefiles/ido.mk"
s = open(p).read()
s, n = re.subn(r"ifneq \(\$\(filter \$\(VERSION\),D E F G H I\),\)\n\$\(BUILD_DIR\)/src/libc/%\.marker: OPTFLAGS := -O3\n.*?endif\n",
               "", s, flags=re.S)
assert n == 1, "ido.mk layout changed"
open(p, "w").write(s)
EOF
build I build_o1

echo "$PWD/build_o1/I/libultra_rom $PWD/build/I/libultra_rom $PWD/build/J/libultra_rom $PWD/build/K/libultra_rom"
