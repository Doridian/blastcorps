# The PC port

The PC build (`port/`, milestone 1 of ROADMAP Phase 5) and the translator
it runs Rare's handwritten asm through.  The build is described first; the
translator and its test follow from "The handwritten asm".

## Building and running

```
make VERSION=us.v11 -C blastcorps          # the N64 build: the port reads its ELFs and asm/
make -C tools/recomp                       # translate the handwritten engine
cmake -S port -B build/port -G Ninja -DCMAKE_C_COMPILER=clang \
      -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_ASM_COMPILER=clang
cmake --build build/port
build/port/blastcorps baserom.us.v11.z64   # the user's own ROM
```

It needs clang/LLVM with its development headers (BEPass is an LLVM
plugin), a 32-bit (multilib) libc and SDL2, and Python 3.  Keys: arrows or
WASD for the stick, X = A, C = B, Z = Z, Enter = Start, Q/E = L/R, IJKL = C
buttons, TFGH = D-pad; an SDL game controller works too.  `--help` lists
the options: `--headless`, `--deterministic` (virtual time: as fast as the
host can, identical every run), `--frames N`, `--screenshot PREFIX`,
`--save PATH` (the 4 Kbit EEPROM, default `blastcorps.eep`).
`PORT_AUTOSTART=1` taps Start and A, which is enough to get from the title
through the name entry into Simian Acres; `PORT_DUMP=N,...` writes RDRAM at
the Nth controller read, counted as `tools/recomp/test/snapshot.c` counts
them in mupen64plus, so the two can be compared byte for byte.

## Memory model

The decompiled C, the translated asm, the game's data and whatever the ROM
holds all have to agree on memory.  The port keeps the N64's view of it
exactly, and adapts the host to that, rather than the other way round:

- **32-bit addresses.**  The whole program is a 32-bit x86 program
  (`-m32 -malign-double`), so a pointer is 4 bytes and every struct has its
  N64 layout.  The executable is linked at `0x80400000`.
- **RDRAM at `0x80000000`.**  The first 4 MB of the address space is the
  image's `.rdram` section (`tools/gen_ld.py`), so a KSEG0 address *is* the
  host address.  The translated code's `rdram + (addr & 0x1FFFFFFF)` with
  `rdram = 0x80000000` is the identity; `K0_TO_PHYS`, `PHYS_TO_K0`,
  `osVirtualToPhysical` and segment addresses round-trip; the game's fixed
  buffers (framebuffers at `0x80000400`, the level pool from `0x8004B400`,
  the heap after `.bss` at `0x803FF600`) are where it expects them.  The
  hardware registers (`0xA4000000`) are mapped as plain memory, and the
  fibers' host stacks sit at `0x90000000`, inside the KSEG0 window, so the
  address of a local means the same to the translated code.
- **Every game variable at its N64 address.**  The decompiled C relies on
  the layout of the data, not just its contents: structs read past one
  variable into the next (the scheduler's frame counter is `sc->unk284`,
  which is the separate variable `D_803156C4`), tables are indexed from a
  neighbour, the front end's area is cleared by address.  The game's C is
  built with `-fdata-sections`, the data files are converted one section per
  file (`tools/asm2x86.py`), and `gen_ld.py` places each at its address in
  the N64 link; the build checks all 3,937 symbols afterwards.  Anything in
  RDRAM the port doesn't define is simply there, at its N64 address
  (`tools/gen_syms.py`).
- **Big-endian memory.**  The data files, the ROM's assets and most of the
  C-owned data are untyped bytes: a native little-endian reading would need
  every structure typed first (Phase 3/4).  Instead the game's C is compiled
  by clang with **BEPass** (`port/bepass/`), an LLVM pass that byte-swaps
  every multi-byte load and store, so memory holds exactly the N64's bytes.
  Type punning, unions, `u64` halves, reading a struct from the ROM: all
  behave as on the N64.  The translated asm stays in its tested big-endian
  mode, and DMA is a plain copy.  Initialized data is fixed at startup: the
  pass records the scalars in C initializers and a constructor swaps them
  (`__bepass_fixup`), and symbolic `.word`s in the data files are listed in
  a `port_bswap32` section and swapped by `port_fixups()`.  Swaps on locals
  fold away; what's left costs a `bswap` or `movbe`.  Only code built with
  the pass is on the "N64 side"; host code (`port/host/`) that touches game
  memory does so through `port_be32()` and friends (`port/include/port.h`).
  Functions that use `va_start` are left unswapped (the argument area is
  the host's); the game's are empty debug printfs, and `sprintf` is the
  host's `vsprintf`.
- **Why this and not native pointers.**  It is the quickest way to run the
  code as it is: no data needs typing, the translated engine is used exactly
  as tested, and the game's own assumptions about addresses hold.  The path
  to a clean port stays open and is incremental: as structures get typed
  (Phase 3) and assets get loaders that swap and widen them (Phase 4),
  BEPass and `-m32` go away together; the translated code has a native-endian
  mode (`RECOMP_NATIVE_ENDIAN`) for then, and every place the port depends
  on the layout is a symbol or a documented fixed address.

BEPass also puts a call to `__port_poll()` on every loop back edge.  The
game busy-waits on counters that another thread or an interrupt advances
(`while (D_803156C4 - sp60 < 15) {}` waits for retraces); the port runs its
threads one at a time, and the poll is where it lets a due event in.  As an
opaque call it also stops clang from hoisting the load out of the loop, as
IDO never would.

## The platform layer

- **Threads** (`port/host/threads.c`): each OSThread is a fiber (ucontext) on
  the one OS thread, scheduled as libultra does: the highest-priority
  runnable thread runs until it blocks, yields, or wakes a thread of higher
  priority.  The idle thread parks when it drops to priority 0.  Each thread
  has its own `recomp_context`, whose `$sp` is the N64 stack the game gave
  `osCreateThread` (only the translated code uses it).
- **The loop** (`port/host/main.c`) runs when no thread can: it raises the
  events the hardware would (VI retrace at 60 Hz, timers, SP and DP task
  completion) and sleeps until the next one.
- **libultra** (`port/src/ultra.c`, N64 side): messages, events, timers,
  `osGetTime` from the host clock (at 46.875 MHz), PI DMA from the ROM
  file, the controller from SDL, EEPROM to a file, no Controller Pak, VI
  swap, SP tasks, AI (ignored).  The stubs of `src.us.v11` that include only
  libultra's os/io (and libc's printf and string functions) aren't built;
  gu, libaudio and the rest of libc are.  hd_code's entry point
  (`func_802447C0`) runs on a boot thread (`port/src/boot.c`).
- **The overlay** (`port/src/overlay.c`): the front end is linked in, and
  "loading" it (`func_8028B3E0`, wrapped at link time) restores its `.data`
  from a startup copy and clears its `.bss`, which is what the N64's inflate
  leaves behind.
- **Graphics** (`port/host/gfx.c`): a software Fast3D (gbi 2.0D) renderer
  that draws into the game's framebuffer in RDRAM, as the RDP would, and
  shows the VI's current framebuffer.  RSP: matrices, vertices, lighting,
  texgen, clipping, culling.  RDP: TMEM loads, tiles, all texture formats,
  the combiner (both cycles), a simplified blender, alpha compare, a float
  z-buffer tied to the z image, 8/16/32-bit color images.  OS_EVENT_DP is
  raised only for a display list that ends in a full sync, as the game's
  scheduler expects.  Point sampling, no anti-aliasing, no fog.
- **Audio**: the game's audio thread and libaudio run; the audio task is
  reported done without running, so there is no sound.

## The glue to the translated code

`port/tools/gen_glue.py` generates both directions from the C:

- `entry.c`: for each of the 167 translated functions the C calls, a native
  function with the C's prototype that puts the arguments where the o32 ABI
  does (`a0`-`a3`, `f12`/`f14` when the first argument is a float, the
  stack from `sp+16`, doubles and `u64`s as register pairs), calls
  `recomp_func_X` with the thread's context, and returns `v0` or `f0`.
- `externs.c`: `recomp_extern_X` for the 53 calls out, the reverse; it saves
  and restores the callee-saved registers around the native call, as the
  IDO-compiled callee would.

Prototypes come from the definition for a C function (K&R ones included)
and from the most common declaration for a translated one.
`port/tools/liveness.py` computes each translated function's live-in
registers; the generator checks the prototypes against them (no entry reads
an argument outside `a0`-`a3`/`f12`/`f14`) and lists disagreements in
`glue_report.txt`.

## Source changes for the port

Guarded with `#ifdef TARGET_PC`; the N64 build still matches.

- `hd_code/26570.c`: `func_8026BBD0` is `void`, but its callers use the
  result, which on the N64 is `v0` left over from `func_8026BCE0`; the port
  returns that.  Two string copies whose unsequenced `a[i] = b[i++]` IDO
  evaluates with the old index.
- `hd_code/168B0.c`: the same unsequenced copy.
- `tools/recomp/runtime/recomp.h`: `dmult`/`dmultu` without `__int128` on a
  32-bit host (checked against the `__int128` version).

## Status

- Boots, runs every thread, and plays the Rare logo, the title screen and
  the attract mode (the story sequence and the demo levels) for as long as
  it is left running; with Start/A it goes through the save-erase prompt,
  the name entry, the world map and into Simian Acres, which plays (the
  bulldozer, the carrier, the pause menu).
- Known problems: the game's pacing.  The RSP and RDP finish instantly and
  the CPU is fast, and the intro modes don't wait for the retrace (the
  scheduler swaps at once when `D_80364A90` has certain bits), so the
  attract sequence runs about 15 times faster than on the hardware, and
  gameplay at 60 frames a second instead of about 30.  Rendering: some
  textures glitch (no TMEM swizzle, no bilinear filtering or LOD), the
  blender is approximate.  No audio.  Non-void functions that fall off the
  end (`func_8024B4B8`, `func_80271F48`, `func_8027E164`, `func_801F6160`,
  `func_801F61C8`, `func_801F6ED4`) return whatever the host leaves.

## What's left for the port

- **Timing.**  Charge the RDP's (and the CPU's) time: raise OS_EVENT_DP
  after the time the RDP would take, as `--deterministic` already
  estimates, and find what the game uses to pace its modes.
- **Audio.**  An audio-ucode HLE for the audio task, and SDL output from
  `osAiSetNextBuffer`.
- **An accelerated renderer** (OpenGL, or Fast3D in the style of sm64-port's
  gfx_pc) in place of the software one, at `host_gfx_task()`.
- **Real call states** for the translated code's test.  Recording `ctx` and
  memory at each translated function's entry during play would replace the
  random registers, and reach the 30% of blocks the random states don't.
- **Toward native code**: type the data (Phase 3), load assets through typed
  swapping loaders (Phase 4), then drop BEPass and `-m32` together and
  switch the translated code to `RECOMP_NATIVE_ENDIAN`.
- **Readable C.** Replace translated functions with hand-written C one at a
  time. Each replacement can be checked with the same harness: point the
  test library at the new C instead of the generated file.

# The handwritten asm

About a third of hd_code (us.v11 `0x56040`–`0x8E910`, 31 objects, 688
functions, 55k instructions) and hd_front_end's `0x1B100` run are Rare's
handwritten MIPS. It can't become matching C, so the port runs a mechanical
translation of it first (ROADMAP, Phase 5). This is that translator, and the
test that shows it's right.

## Approach

Our own translator over the symbolic `.s` files, in `tools/recomp/`, rather
than N64Recomp over the linked ELF:

- **Symbols survive.** Splat's `.s` already names every address (`%hi(D_…)`,
  `jal func_…`, `.L` labels), so the C says `SYM(D_803A7410)`, not
  `0x803A7410`. Its address comes from a generated header, so it follows the
  shiftable build and, later, wherever the port puts the variable. N64Recomp
  works from relocations and emits addresses.
- **It sees exactly the code we classified.** The set of objects comes from
  the `asm` subsegments in `hd_code.us.v11.yaml` (minus libultra's). It isn't
  a whole-ELF pass, so the decompiled C is never pulled in again, and the data
  islands inside `.text` are never mistaken for code.
- **Rare's code is simple to translate.** Every `jr` is `jr $ra`, and there is
  no `jalr`, no `j`, no jump table and no function pointer into it (none in
  the data, none in the islands). Control flow is branches and `jal`, which
  become `goto` and direct C calls. The only irregular spots are one
  branch into another function's epilogue (`func_8029CB04` into
  `func_8029CF04`), handled by merging those functions into one C body with an
  entry switch, and 19 branches into delay slots.
- **Small and deterministic.** It is about 1,100 lines of Python with no
  dependencies, and it gives the same output for the same input.

The instructions are decoded from the word in each line's comment
(`tools/recomp/mips.py`), not from the mnemonic text, and cross-checked
against the text. Only the symbolic operands come from the text.

## Interface

```c
typedef struct recomp_context {
    union { uint64_t r[32]; struct { uint64_t zero, at, v0, v1, a0, ... ra; }; };
    uint64_t hi, lo;
    uint32_t f[32];        /* COP1, Status.FR = 0 as the game runs it */
    uint32_t fcr31;
    int64_t budget;        /* test only */
} recomp_context;

void recomp_func_8029A800(uint8_t *rdram, recomp_context *ctx);
```

- **State.** All of it is N64 state. The registers live in `ctx`, 64 bits
  wide. Memory is reached by 32-bit N64 addresses: `rdram + (addr &
  0x1FFFFFFF)` for KSEG0 and KSEG1. The translated code never holds a host
  pointer, and one `ctx` per game thread carries `$gp`/`$sp` between calls.
- **Addresses** are `SYM(name)` (`syms_<module>.h`, generated from the linked
  ELF). A port that places data elsewhere redefines those, as long as each
  datum is still inside the arena that `rdram` points at.
- **Calls into translated code** (IDO C calls 167 of the 688 functions by
  name): set `a0`–`a3` (and `$sp` into the arena, since the functions build
  frames there) in the thread's context, call `recomp_func_X(rdram, ctx)`,
  and read `v0`. Many of these functions also take arguments in
  `v0`/`v1`/`t*`/`s0`, and the wrapper for each one has to set those, so the
  wrappers are hand-written as the C callers get decompiled. No function
  pointer reaches this code, but `recomp_lookup(addr)` (`funcs.c`) resolves
  one if that ever changes.
- **Calls out of translated code** (53 callees: IDO C and libultra) go
  through `recomp_extern_<name>(rdram, ctx)`. The generated default
  (`externs.c`) forwards to `recomp_call_external(rdram, ctx, SYM(name))`.
  The port replaces each one with glue that unpacks `a0`–`a3` (and stack
  arguments at `sp+0x10`), converts address arguments with `rdram + (a &
  0x1FFFFFFF)`, calls the native function, and puts the result in `v0`.
- **Hooks the embedder provides:** `recomp_trap` (break/syscall, which are
  Rare's asserts, plus faults in the test build), `recomp_call_external`, and
  `recomp_mfc0`/`recomp_mtc0` (one Status read and one Compare write).
- **Memory layout.** By default memory is a byte-exact big-endian image (what
  the ROM's data is), and every access byte-swaps on the host. That is what
  the test verifies. `-DRECOMP_NATIVE_ENDIAN` switches to host-order words for
  a port whose native C shares those structs. Words, halves and bytes then
  read the same from both sides, but `lwl`/`lwr`/`swl`/`swr` (32 uses) and
  anything that reads one datum at two widths would need checking. Doubles
  and `ld`/`sd` are two words, high word first, in both modes.

How the PC build meets this interface (RDRAM at `0x80000000`, big-endian
memory, the glue generated from the C) is under "Memory model" and "The
glue to the translated code" above.

## Semantics worth knowing

These are the choices where the VR4300, the MIPS spec and QEMU disagree, or
where the obvious C is wrong:

- **`sra`/`srav`** shift the whole 64-bit register and sign-extend the low
  word. Rare does this after `dmult`/`mflo`, so it matters for fixed point.
  QEMU leaves such inputs unextended; the test build follows QEMU there
  (`RECOMP_QEMU_COMPAT`).
- **FR = 0.** Doubles and 64-bit integers are even/odd pairs, and the code
  builds a double with `mtc1 $at, $f9`. The L-format conversions (`cvt.s.l`,
  `cvt.d.l`, `cvt.l.s`, `cvt.l.d`, 44 uses) are legal on the VR4300 with FR =
  0. QEMU rejects them, so the test harness executes those itself.
- **Float to int** out of range or NaN gives `0x7FFFFFFF`/`0x7FFF…F`. `cvt`
  rounds to nearest-even (the FCSR mode the game leaves), with
  `-ffp-contract=off` so nothing fuses.
- **NaNs** follow MIPS legacy encoding: a quiet NaN operand propagates, and a
  signaling NaN or an invalid operation gives `0x7FBFFFFF`. `abs`/`neg`/`mov`
  only touch bits. The FCSR's flag and cause bits aren't kept; nothing but
  libultra's thread switch reads them.
- **`add`/`addi`/`sub`/`dadd`** trap on overflow in the test build and wrap
  in the port. The game never overflows them, since that would crash on
  hardware.
- **Divide by zero** gives the VR4300's result (`LO = n<0 ? 1 : -1`,
  `HI = n`), or QEMU's in the test build. The code only reaches it on paths
  that then `break 7`.

## Running it

```
make -C tools/recomp                  # translate -> blastcorps/build/recomp/src
make -C tools/recomp port             # compile it as the port would (-Werror)
make -C tools/recomp snapshots        # optional: RDRAM from real play (mupen64plus)
make -C tools/recomp test PYTHON=.env/bin/python TRIALS=100
```

These need a built us.v11 stage 2, because the translator reads
`blastcorps/asm/` and `blastcorps/build/*.elf`. The test needs `numpy` and
`unicorn` in the venv. `tools/recomp/analyze.py` prints the opcode
inventory and any control flow the translator would refuse (there is none
now).

### The differential test (`tools/recomp/test/difftest.py`)

Each translated function runs many trials, and each trial does this:

1. Build 4 MB of RDRAM from the linked `hd_code`, `hd_front_end` and `init`
   images, plus one of these fills:
   - one of 8 seeded random fills, mostly zeros, small integers, floats and
     pointers back into RDRAM;
   - one of 16 snapshots of real play. `test/snapshot.c` is a headless
     mupen64plus front-end that is its own scripted input plugin. It plays
     through the title, the name entry, Simian Acres, the pause menu and the
     world map. A snapshot keeps the linked `.text` on top.
2. Randomize the registers the same way. Registers the function
   dereferences before writing them get pointers, taken from pointer-looking
   words of the snapshot when there is one. Words that the code loads from a
   symbol and then dereferences are also given pointers.
3. Run the original in unicorn (MIPS64 big-endian, R4000 model, FR = 0) until
   it returns, traps, or uses up its budget of 400k instructions.
4. Reset memory and run the translated C, built into a shared library with
   `RECOMP_TEST`, on the same state. Calls out of it run the original callee
   in unicorn on the same buffer. So everything that isn't translated
   executes identically in both runs, which is also why `hd_code`'s C doesn't
   need to be available as C here. A second pass (`--stub-externs`) makes
   every callee return a hash of its arguments in both runs instead, which
   gets further into code whose callees fault on random state.
5. Compare all GPRs, HI/LO, all 32 FPR words, the FCSR condition bit, every
   byte of RDRAM, and how the run ended (return, break, syscall, overflow,
   or address fault). Code pages are write-protected in both runs, so
   random pointers can't rewrite instructions that only the original would
   then execute.

A trial where either side hit the budget is inconclusive. So is one where
the random state overwrote the saved `$ra` (the translated code refuses to
return anywhere but its caller). `--trace FUNC:TRIAL` with the
`librecomp_trace.so` build (`make trace-lib`) replays one trial with a
per-instruction register trace on both sides and prints where they diverge.

### Results (100 trials per function, with snapshots)

- **688/688 functions pass.** Across both passes, 0 of about 137,000 trials
  differ.
- 548 functions returned normally in at least one trial, and 584 when
  callees are stubbed. The other 104 only ever faulted or trapped,
  identically on both sides, which still compares state up to the fault.
  100 of those dereference a register or global that neither the random
  state nor the snapshots make valid: 62 null or small-integer pointers and
  38 other bad addresses. Of the last four, one always overflows, one
  always faults on alignment, one always runs past the budget, and one is
  an assert (`syscall`, hd_front_end's `func_80202100`) that always fires.
- Coverage of the translated code, over both passes: 69.4% of basic blocks
  (6385 of 9203) and 75.7% of instructions executed at least once. All 102
  opcodes the code uses are executed.
- Mutation check: of 11 bugs planted in the runtime or the translator (slti
  signedness, sra as logical, `lb` zero-extending, `cvt.w.s` truncating,
  mult HI/LO swapped, dmult HI dropped, `c.le` as `c.lt`, `lwr` shift,
  `swl` bytes, branch condition read after the delay slot), the test catches
  10, each with 2 to 188 failing functions. The eleventh, `lwl` keeping the
  wrong low bytes, is masked by the code: every `lwl` is paired with an
  `lwr` that overwrites those bytes.

What this can't test:

- Code that reads hardware or needs another thread (libultra's message
  queues) only gets as far as its first fault in these runs.
- The other 30% of the blocks were never reached. Getting there
  needs realistic arguments, not only realistic memory.
- Undefined-behaviour cases where QEMU and the VR4300 differ (`sra` on
  unextended values, divide by zero) are checked against QEMU's behaviour in
  the test build. The port build's VR4300 behaviour for them is not
  exercised.
