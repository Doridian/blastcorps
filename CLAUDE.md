# Blast Corps decompilation

A matching decompilation of Blast Corps / Blastdozer, aimed at a PC port. All
four ROMs rebuild byte for byte. us.v11 is the working version: most of its
IDO-compiled code is C (`tools/progress.py`); about a third of hd_code is
Rare's handwritten asm, which stays asm. The other versions are still
disassembly.

## Build

Needs `mips-linux-gnu-` binutils on `PATH` and splat's Python deps in a venv.
`VERSION` is one of `us.v10 us.v11 jp eu`, default `us.v11`.

```
make VERSION=us.v11 extract                  # stage 1: split the ROM
make VERSION=us.v11                          # stage 1: relink, sha1-checked
make VERSION=us.v11 decompress               # inflate the gzipped code modules
make VERSION=us.v11 -C blastcorps extract    # stage 2: disassemble
make VERSION=us.v11 -C blastcorps            # stage 2: reassemble, sha1-checked
make VERSION=us.v11 -C blastcorps compress   # re-deflate into assets/
make VERSION=us.v11                          # relink the ROM from that
```

`compress` also copies the rebuilt `init` into `assets/`, so the ROM is made
entirely from rebuilt modules. The ROM link places everything from
`hd_code_text` on by the compressed modules' sizes (`tools/rom_syms.py`), and
the header checksum is recomputed (`tools/n64crc.py`); for the original
modules both are no-ops.

A shifted build proves nothing depends on absolute addresses: `SHIFT=1` puts
`SHIFT_PAD` (default `0x10`) bytes of zeros at the start of hd_code's and
hd_front_end's `.text` and `.data`, and nothing is sha1-checked:

```
make VERSION=us.v11 -C blastcorps SHIFT=1 all compress
make VERSION=us.v11 SHIFT=1
```

Rebuild without `SHIFT` (both steps) to get the matching assets back.
`SHIFT_LDFLAGS="--defsym SHIFT_PAD_hd_code_data=0x20 ..."` pads single
sections (`hd_code`, `hd_code_data`, `hd_code_bss`, and the same for
`hd_front_end`), which is how to bisect a shift that breaks something.

`asm/` and `assets/` hold one version at a time. Switching `VERSION` without
`make clean` (both directories) is rejected by the `stamp` target — that guard
exists because stale output from another version otherwise links in silently and
surfaces only as a confusing sha1 mismatch.

## What "matching" depends on

The sha1 checks are the arbiter. Everything below is a way to keep them passing.

- **gzip mtimes are part of the compressed stream.** The `*_TIMESTAMP` values in
  `blastcorps/Makefile` come from each ROM's own gzip headers. A wrong one makes
  a rebuilt section differ even when the code inside it is identical.
- **Padding must stay outside the code sections.** `hd_code_*` and
  `hd_front_end_*` get inflated and re-deflated, so a recompressed section is the
  bare gzip stream. Any inter-section padding folded into a segment shifts
  everything after it. Asset segments are opaque and may absorb their padding.
  This was a live bug in `blastcorps.us.v10.yaml` (`0x7f9c76` should have been
  `0x7f9c75`).
- **Every name must still be where it was.** Outside `SHIFT`, each link is
  followed by `tools/link_syms.py --check`, which fails if any name in the
  symbol files moved; that points at a layout problem before the sha1 does.
- **Config offsets are generated, not hand-written.** `tools/gen_build_yaml.py`
  reads the top-level split straight out of the ROM (gzip members are
  self-delimiting); `tools/gen_code_yaml.py` runs splat once for file boundaries
  and emits the stage-2 module configs. Both reproduce the hand-maintained US
  configs, so prefer regenerating over editing offsets by hand.

## Layout notes

Load addresses, identical across all four revisions:

| module         | VRAM         | notes                                          |
| ---            | ---          | ---                                            |
| `init`         | `0x8021ED00` | uncompressed at ROM `0x1000`                   |
| `hd_code`      | `0x802447C0` | staged at `0x80000400`, inflated by `init`     |
| `hd_front_end` | `0x801E7000` | inflated by `func_8028B3E0` in `hd_code`       |

Regions kept as `bin` because they are not r4300 code:

- The last `0xFB0` bytes of every `hd_front_end` `.text` are RSP microcode
  (`sp = 0x110`, loads from DMEM `0xFC4`, exactly IMEM-sized).
- Six data islands inside each `hd_code` `.text`, listed with their offsets in
  `tools/regen_code_yaml.sh`: two u16 tables embedded in Rare's handwritten
  math routines, two pointer-bearing blobs around another block of handwritten
  routines, one unreferenced blob, and the RSP microcode after libultra's
  `ldiv`. Four are byte-identical across versions; the pointer-bearing two were
  bounded by following control flow from every call into them. Capstone decodes
  data as Octeon opcodes (`bbit0`, `synci`, `dlsa`) that `-march=vr4300`
  rejects, so an island left as `asm` fails to assemble.

The islands are not 16-aligned, so the code between them starts and ends at odd
offsets. That is why the code segments use `subalign: 4` and stage 2 assembles
with `--no-pad-sections`; either default pads those objects and shifts
everything after them. The same code also trips splat's file-boundary
suggestions, so `gen_code_yaml.py` drops any boundary that a branch crosses.

The two pointer-bearing islands are written as `.s` files with those words
as `.word <symbol>` (`tools/postsplit.py`, `pointer_bins`), so they move with
the code they point at.

The jp/eu configs used to lump about 0x38000 bytes of real code into these bins
(the generator ignored bin lengths). It still matched, because a bin is exact,
so a too-wide `bin` goes unnoticed: only the sha1 decides, and it cannot tell.

## Functions and symbols

- One `.s` per function under `asm/nonmatchings/`, pulled into the committed
  `src.<VERSION>/**/*.c` stubs by `GLOBAL_ASM`. Splat writes a stub only when
  it is missing, so after anything that moves function boundaries (a new
  `symbol_addrs` entry, a config change) delete the untouched stubs and
  re-extract, or they list the old split. `init/1660.c` in `src.us.v11` is the
  hand-written proof of concept; keep it.
- `symbol_addrs.<module>.<VERSION>.txt` are generated by `tools/gen_symbols.py`
  (below the marker line). Only libultra is named; everything else keeps
  `func_`/`D_` address names on purpose. Don't guess names.
- libultra here predates every version ultralib builds. Its libc (`sprintf`,
  `_Litob`, `_Ldtob`) is `-O1` where ultralib's 2.0I uses `-O3`, hence the
  extra `-O1` build in `tools/build_ultralib.sh`. A few functions
  (`__osDispatchThread`, `__osSyncPutChars`, `osPiStartDma`, `osSpTaskLoad`,
  `alAudioFrame`) differ outright and are placed by similarity (`lib:fuzzy`).
- Hand-identified code goes in `blastcorps/symbols_known.txt` (us.v11 init
  addresses, with evidence). gen_symbols copies each name to every
  masked-identical copy, pairing globals by lui/lo position. Rare's gzip 1.2.4
  inflate lives there: one copy in init (inflates hd_code), one in hd_code
  (inflates hd_front_end). `bi_reverse` and `clear_bufs` match as gzip's own
  source, which pins down the global names.
- Each module links its own copies of libultra, so a name like `__osDisableInt`
  exists in both `init` and `hd_code` at different addresses. Cross-module names
  (`from:`) are only added where they don't collide.
- Splat starts a function only after a `jr $ra` that no branch spans. Every call
  target it would miss is listed as `func_XXXXXXXX ... called`; a new one that
  isn't shows up as a jal into the middle of a function.

## Decompiling

`docs/ROADMAP.md` has the plan and `docs/DECOMPILING.md` the matching notes. The loop for one function:

- `tools/m2c.sh <module> <function>` for a first draft (m2c, run from the
  project venv). Replace the `GLOBAL_ASM` line with the C.
- `make VERSION=us.v11 -C blastcorps <module>`, then
  `tools/fdiff.py <module> <function>` to diff it against the original. It
  refuses to run when the last link failed, since the binary would be stale.
- `tools/progress.py` for totals.
- For a draft that's only registers or scheduling away,
  `tools/permute.sh <module> <function> [draft.c]` sets up decomp-permuter
  (`docs/DECOMPILING.md`, "The permuter").

IDO quirks that have mattered so far (all `-O1`):

- `register` variables get `$s` registers in declaration order, and each
  still gets a stack slot at the point where it's declared. Declaration order
  moves both the register assignment and the offsets of the other locals.
- Statement spelling changes the scheduling: `p = c + 1, xp = x + 2;` and the
  same two statements separated by `;` don't compile the same.
- m2c drops some early returns; check the function's size.
- A global defined in the same file is addressed differently from an
  `extern` one (a `u64`'s two halves share one `lui`). Such functions only
  match with their data defined in C, in the file that owns it (`.data`,
  `.rodata` and `.bss` are per object in us.v11).
- libultra was built with unsigned `char`; this build passes `-signed`.
- Per-file flags go under "Optimisation Overrides" in `blastcorps/Makefile`
  (`ll.c` is `-mips3 -32`, relabelled mips2 by `tools/elf_mips2.py` so ld
  will link it).

When symbols_known.txt names a function, run `tools/gen_symbols.py` for each
version (with the ultralib objects from `tools/build_ultralib.sh`), then
`tools/sync_stub_names.py`, then remove `blastcorps/asm` and re-extract.
Splat only writes a `.s` for names the existing stub lists, so without the
middle step the stubs keep pointing at stale `func_` files.

Handwritten code (the game's own asm, and libultra's `.s` files) is an `asm`
subsegment, not a `c` file full of `GLOBAL_ASM`. That keeps
`tools/progress.py` honest and marks what a port has to replace.
`gen_code_yaml.py` classifies it (see `docs/DECOMPILING.md`). About a third
of hd_code is Rare's handwritten engine; it can't become matching C. For
the port it is translated to C mechanically by `tools/recomp/` and checked
against the original in unicorn (`docs/PORT.md`).

## Data and symbols at link time

Extraction goes through `tools/split.py`, a wrapper around the splat
submodule that fixes its data output (exact string escapes, `dlabel`, pointer
words between subsegments as symbols, working rodata migration). `init`,
`hd_code` us.v11 and `hd_front_end` us.v11 have their `.data`/`.rodata` split per object, in link order:
all `.data`, then all `.rodata`, each block 16-aligned. `gen_code_yaml.py`
works out hd_code's split (see `docs/ROADMAP.md`, Phase 1). A C file owns
its data with a `.data`/`.rodata` subsegment; its remaining `GLOBAL_ASM`
functions then carry their own rodata into the `.s`, and asm-processor places
it. `tools/inline_rodata.py` turns a file's `extern` string/float uses into
literals when switching it to own its `.rodata`. In us.v11 every C file owns
its `.data` and `.rodata`; what is still asm `data`/`rodata` belongs to
handwritten objects or to data-only objects (named by offset: text tables,
display lists, libultra's VI modes). `tools/data_c.py <module> <object>`
writes a C file's `.data` definitions from the asm block, typed by the
file's declarations (see `docs/DECOMPILING.md`); it needs the block still
`data` and extracted, or `--ref` with a saved copy of its `.data.s`. The other
versions still have one data `bin` and no `.bss` layout.

`.bss` (us.v11) is laid out per object too, in the top-level `bss:` list of
each module's config (`tools/modmap.py` reads it; splat ignores it):
`[vram, bss|.bss, <module>/<object>]` in link order, then `[end]`.
`gen_code_yaml.py --bss` works it out for hd_code and hd_front_end as it does
`.data`; init's is hand-written. `postsplit.py` writes an asm object's block
as `asm/data/<module>/<object>.bss.s` and adds a NOLOAD `.<module>_bss`
section to the linker script. A `.bss` block belongs to a C file, which
defines its variables itself: `tools/bss_c.py <module> <object>` writes those
definitions from the block (reference copy in `asm/bss/`), and
`bss_c.py --check` compares an object with it. Every C file owns its `.bss`;
only the handwritten objects use `.bss.s`. IDO emits uninitialized globals
into `.bss` (not COMMON) in the order it first sees them, so the tool puts
the definitions before any use; see `docs/DECOMPILING.md`.

`postsplit.py` also symbolizes the lui pairs splat leaves as numbers (split
by scheduling, 64-bit loads, `add`/`addi` in Rare's asm) wherever they point
into a module or at a ROM segment, and data words (even inside `.byte`
records) that point into any module. What no object here defines by name goes
into `module_syms_auto.<module>.<VERSION>.txt` if it lies in a module, else
`undefined_syms_auto` (only hardware registers, the boot globals at
`0x800003xx`, segment addresses, ROM offsets and the fixed memory map are left
there). At link time `tools/link_syms.py` turns all the symbol files into
`build/<module>.<VERSION>.syms.ld`: names an object defines are dropped, the
rest of this module's become relative to the nearest symbol below them, other
modules' come from their layout links (each module is linked twice, see the
Makefile), ROM segment starts become `rom_syms.py`'s symbols, and the rest
stays absolute. `build/*.syms.txt` lists which is which. A hand-written line
in `undefined_syms.<module>.<VERSION>.txt` marked `/* fixed */` stays
absolute even inside a module (hd_code's allocator limit `0x8020ED00`).

A C file can still name an address splat never saw with a line in
`undefined_syms.<module>.<VERSION>.txt`; inside a module that is resolved
like the rest, so don't use constant-address casts for it.
`tools/find_abs.py <module> <VERSION>` lists what a linked module still
points at without a relocation (the final links keep `--emit-relocs`); what's
left is the fixed memory map: the modules' load addresses, the framebuffers
at `0x80000400` and `0x8021ED00`, `0x80400000`, and the ROM range init leaves
at `0x803FFFF8`.

## Conventions

- Straight to `main`; this project does not use branches.
- `docs/sm64tools-configs/` are queueRAM's original configs, kept for reference.
  Their offsets are not always right (the `jp` `hd_front_end_data` end is wrong),
  so verify against the ROM before trusting one.
