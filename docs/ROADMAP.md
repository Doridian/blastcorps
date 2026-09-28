# Roadmap

The end goal is a PC port that builds from this source. A matching decomp is
the route there, not the goal in itself: the sha1 checks are what tell us each C
function is right. The port then needs three more things: C that doesn't depend
on addresses, data with real types, and a platform layer to stand in for
libultra and the RCP.

`us.v11` is the reference version. The other three stay matching, but new work
lands in `us.v11` first.

## Where things stand

| module         | functions | instructions | in C (2026-09-27) |
| ---            | ---:      | ---:         | ---:              |
| `init`         | 67        | ~3.7k        | 100%              |
| `hd_code`      | 1421      | ~160k        | 0%                |
| `hd_front_end` | 161       | ~33k         | 0%                |

Run `tools/progress.py` for current numbers.

What's known that affects the port:

- **Graphics use SGI's Fast3D, not F3DEX.** The string is
  `RSP SW Version: 2.0D, 04-01-96`. That's the GBI family SM64 uses, so
  existing Fast3D-to-OpenGL/Vulkan translators (sm64-port's `gfx_pc`,
  libultraship's Fast3D) are a realistic starting point.
- **Audio uses libultra's `libaudio`** (`alAudioFrame`, `AL_MAX_RSP_SAMPLES`)
  with the stock audio microcode. The PC side needs a C implementation of that
  microcode (HLE, as the Perfect Dark port does) plus the decompiled `libaudio`.
- **The scheduler is SGI's sample `sched.c`** (the `sc->curRSPTask` asserts).
- **Compiler:** IDO 5.3, with `-O1` for the code seen so far (every local is
  spilled to the stack). Per-file flags still have to be confirmed.
- **Handwritten asm:** Rare's math routines and the block with the data
  islands (`tools/regen_code_yaml.sh`). They stay `.s` in the matching build
  and get C versions for the port.
- **All `.data`/`.rodata` is still one opaque `bin` per module**, and `.bss`
  isn't modelled at all. This is the biggest structural gap. Until it's split,
  no data pointer is a relocation, and nothing can be moved.

## Phase 0: workflow

Tooling that makes decompiling one function cheap. Do this before large-scale
decompilation.

- [x] `tools/progress.py`: C vs `GLOBAL_ASM` bytes per module and version.
- [x] `tools/fdiff.py`: diff one function between the original and rebuilt
      module (asm-differ without its dependencies).
- [x] Objects depend on their headers and `GLOBAL_ASM` files.
- [x] `diff_settings.py`: `--module`/`--version`, for asm-differ.
- [x] mips_to_c bumped to current m2c. It needs `pycparser<3`.
- [x] `tools/m2c.sh <module> <function>`.
- [x] Per-file flag overrides in `blastcorps/Makefile` (`ll.c` is `-mips3`).
- [x] `tools/sync_stub_names.py`: keep stubs in step with new names.
- [ ] m2c context from `include/`, so its output uses real types.
- [ ] decomp-permuter wiring for the few functions that won't match by hand.
- [ ] `common.h`/`include/`: the base types, the `GLOBAL_ASM` macro, and
      libultra headers from the matching SDK version.

## Phase 1: data, bss, and a shiftable build

A PC port needs every address to be symbolic. The same work lets the N64 build
change size (a "shiftable" build), which is how we test it.

- [x] `init`: `.data`/`.rodata` split per object. Each C file defines its
      own data (the gzip tables, `osClockRate`, the thread queues); the asm
      files' data are splat `data`/`rodata` segments. The layout, one 16-byte
      aligned block per object in link order, is in `init.us.v11.yaml`.
- [ ] `init` `.bss` (`0x802229E0`, `0x23A0` bytes, cleared by the entry
      point). Its variables are still absolute linker symbols. Two problems:
      this splat only supports `.bss` belonging to a C file, and IDO emits
      uninitialized globals as COMMON, which GNU ld places by its own rules.
      Options: `obj(COMMON)` entries per object in the linker script, or
      linker symbols relative to the start of `.bss` rather than absolute.
- [ ] The same for `hd_code` and `hd_front_end`, whose data is still one
      `bin` each. The hd_code entry point should give its `.bss` range as
      `init`'s did.
- [ ] Make the ROM offsets that code uses to find assets and the compressed
      modules into linker symbols instead of constants. For example,
      `func_80220730` hardcodes `0x787FD0`, `0x7E3AD0` and `0x7F9BE0`.
- [ ] Shiftability test: a `NON_MATCHING=1 SHIFT=1` build inserts padding
      after each module, and the resulting ROM still boots (checked in an
      emulator).

## Phase 2: decompile the code

Matching C for every non-handwritten function, in this order:

1. **`init`.** Done. The rest of `init` is handwritten and split out as
   `asm`: the entry point, the boot code at `0x1A30`, and libultra's `.s`
   files.
2. **libultra everywhere.** Most functions match ultralib's source directly.
   The ones that don't (`lib:fuzzy`) are an older revision and get their own
   copies. Share one source file across modules where the code is identical.
3. **`hd_code`**, the game engine. Work in file-sized units (one file per
   splat split), leaves first. Generate context with m2c and grind the
   stragglers with the permuter.
4. **`hd_front_end`**, the menus and front end.

Rules for the C, so it ports cleanly later:

- No hardcoded addresses, not even in casts. Use `extern`s and linker symbols.
- Structs over pointer-plus-offset as soon as the layout is known. m2c's
  `*(s32 *)(p + 0x1C)` output is a first draft, not the finished C.
- Keep matching hacks (`do {} while (0)`, register pinning) behind
  `#ifdef` only when the port would otherwise be affected.

## Phase 3: types, names, headers

Mostly done alongside Phase 2, but it's its own effort.

- Structs for the level, the actors (vehicles, buildings, the carrier), the
  camera, and the save data. `docs/blast_corps_levels.txt` and
  `docs/blast_corps_vehicles.txt` are the starting points.
- Name functions from evidence only (strings, asserts, known source, call
  graph), and write down the evidence in `symbols_known.txt`, as for gzip.
- Mark every field that holds a pointer or a ROM offset in data loaded from
  ROM. The port has to widen or rebase exactly those fields.

## Phase 4: assets

- Extract every ROM asset through the existing `blast`/`rzip` splat
  extensions into editable formats (PNG textures, structured level data), and
  rebuild them byte for byte.
- Describe level/model data as typed records rather than blobs. The PC build
  reads the same assets but byteswaps them and widens their pointers at load
  time.

## Phase 5: the PC port

A second build target (host compiler, CMake or meson) over the same `src/`,
selected with `TARGET_PC`. The N64 build stays matching.

- **Platform layer** in place of libultra: threads and messages (on a single
  thread, as sm64-port does), PI DMA reads from the ROM file or extracted
  assets, VI swap to the window, SDL controllers, EEPROM to a save file,
  `osGetTime` from the host clock. Look at libultraship before writing this
  from scratch.
- **Graphics:** feed the Fast3D display lists to a Fast3D renderer. Look for
  Rare-specific tricks: direct RDP commands, framebuffer reads, CPU-drawn
  textures.
- **Audio:** decompiled `libaudio` plus a C version of the audio microcode.
- **64-bit cleanliness:** replace `K0_TO_PHYS`/TLB/`osVirtualToPhysical` use,
  make `u32` pointer fields in structs from ROM data into real pointers, and
  convert on load.
- **Handwritten asm:** C versions of Rare's math routines, checked against the
  asm on the N64 build (same results for the same inputs).
- Later: widescreen, higher framerate (the game loop is tied to VI retrace),
  and mod support.

## Milestones

1. `init` fully in C, all four versions still matching.
2. Data split and a shiftable ROM that boots.
3. libultra fully in C.
4. 50% of `hd_code` by bytes.
5. 100% matching.
6. The PC build reaches the title screen.
7. The PC build is playable start to finish.

A partial port can start before 100%: once data is symbolic, a PC build could
run the decompiled C and statically recompile what's left (N64Recomp-style).
Whether that's worth it depends on where Phase 2 stands then.
