# Decompiling notes

What has mattered for matching so far. The loop and tools are in CLAUDE.md.
All of this is IDO 5.3 at `-O1` unless it says otherwise.

## Locals and registers

- At `-O1` every local lives on the stack, so m2c's `spXX` variables are real
  locals. Declare them in order of descending stack offset: the first one
  declared gets the highest address.
- Unused locals still get a stack slot. If the frame is 4 or 8 bytes smaller
  than the original and every instruction is otherwise the same, add an unused
  `s32` where the gap is.
- Some temporaries go in `$s` registers with no stack slot: a value-producing
  `a ? 1 : 0`, `&&`/`||`, a MIN/ABS ternary, a chained assignment
  `a = b = f();`.
- `register` variables get `$s` registers in declaration order, and each still
  gets a stack slot where it's declared.

## Statement shape

- The comma operator changes scheduling. `a = 1, b = 2;` doesn't compile like
  two statements; a comma group of local assignments stores in reverse.
- Where an increment sits matters: `a[i] = b[i++]` vs `a[i++] = b[i]`, and
  `X++; if (X == Y)` vs `if (++X == Y)`.
- `for (;;) { if (x) return ...; p++; }` and `while (!x) p++;` differ. m2c
  writes loops as `goto`; rewrite them as `while`/`for`.
- m2c sometimes drops early returns, so check the function's size.
- An empty `if (x) {}` can force a reload IDO would otherwise skip.
- `if (x) return;` before the body, instead of wrapping the body in an `if`,
  can keep a pointer from being held in a register across the branch.
- For commutative adds and compares, IDO often evaluates the operands in the
  reverse of the order written. Try swapping them.
- Passing `x = y` directly as a call argument, rather than assigning first,
  changes register allocation.
- Things that matched: clamps as `(x + 31 >= 80) ? 79 : x + 31`, and
  `MAX(0.0, x)` as `(0.0 > x) ? 0.0 : x`.
- In a compare-chain `switch`, the source order of the case bodies sets their
  layout.

- A `sqrt.s` inline in one function while its neighbours `jal sqrtf`:
  `#pragma intrinsic(sqrtf)` before that function and `#pragma function(sqrtf)`
  after it.
- IDO drops a loop's first test when the counter starts at a known constant.
  A search loop that guards the first element and then does
  `++i < n && ...` matched as
  `if (a[0] != x) { do {} while (++i < n && a[i] != x); }`.
- GBI macro temporaries take stack slots in the order they appear. Locals
  declared between macros may need a nested `{ }` block to land in the right
  slots. `sp7C = gfx = (Gfx *)D_80358070;` right after bumping the allocator
  let the next macro reuse the register where other spellings reloaded it.
- A `sizeof` in a loop bound makes the compare unsigned (`sltiu`) even with
  an `s32` counter.
- For a multiply by a large constant stride, a pointer to a multi-dimensional
  array (`u16 (*p)[49][0x1A4]`) gives the direct multiply; `p + i * 0x5064`
  multiplies then shifts.

- `X += a; if (X >= b)` and `if ((X += a) >= b)` differ; so do `X--; if (!X)`
  and `if (--X == 0)`. A single-case `switch` can reproduce a reload after a
  branch. `x -= k` written inside a call argument can match where a separate
  statement doesn't.
- IDO only reuses a loaded value if no store (even to a local) comes between.
  Chained assignments store right to left: `a = b = x` stores `b` first; a
  u16 field stored then read back (`sh`, `lhu`) is `a.x = a.y = 20;`.
- Put the operand that must be evaluated first on the left: `sign * f(...)`,
  not `f(...) * sign`; `p->unk14 + (u8 *)p` rather than the other order.
- `D = !p;` gives `sltiu`; `p == NULL` and ternaries don't.
- A ternary assigned to a global becomes a store in each arm; one nested in
  another, or used as a call argument, goes in an `$s` register.
- `&a[3][i] + 2` and `&a[3][i + 2]` compile differently.
- `if (x > 0.0f) {} else { x = -x; }` is the abs pattern that reloads `x`.
- A constant index into an extern array (`D_X[7].f`) is `lui/addiu` plus an
  offset. If the asm instead loads `%lo(sym)` at a nonzero offset directly,
  those are separate scalar globals.
- `lw $at`/`sw` copies of an initialized local array or struct are a struct
  assignment from an extern: `sp34 = D_80208358;`.

## Types

- An argument that's `lw`'d from its stack slot and truncated at use is `s32`,
  not `s16`. `andi a0,a0,0xff` at entry means a `u8` parameter.
- A function that reads its own arguments back from their stack slots as
  bytes, or whose callers pass narrow values unconverted, is probably a K&R
  (non-prototype) definition. Declare it `s32 func();`.
- m2c shows a 64-bit global as two 32-bit ones (`D_X` and `D_X+4`). If the
  code uses `ld`/`sd` or 64-bit compares, it's one `s64`/`u64`. A
  `(x & 0) || ...` shape in m2c is a u64 mask test.
- `addiu a0,zero,0` for a high word, where plain 0 would be `or a0,zero,zero`,
  is the tell for a u64 argument.
- A `switch` on a u64 compiles to compare trees, not a jump table.
- Storing an `s8`-converted value into a u8 (`v.cn[i] = (s8)f`) produces the
  `sll`/`sra` pair.
- Converting a `u8` to float gives the unsigned-conversion fixup sequence; it
  doesn't mean the variable is `u32`. A float passed in an integer register is
  built with `lui`/`ori`, so it needs no `.rodata`.
- libultra was built with unsigned `char`; this build passes `-signed`. Read
  through `(u8 *)` where the asm uses `lbu`.

## Data, and what has to wait for the data split

hd_code's and hd_front_end's `.data`/`.rodata` are still one `bin` each, so C
in those modules must not create data:

- No string literals, and no float or double constants that IDO puts in
  `.rodata`. Floats whose low 16 bits are zero (`1.0f`, `45.0f`, `32.0f`) are
  fine: they're loaded with `lui`. Otherwise use `extern f32 D_...;` with the
  value in a comment.
- No `switch` that compiles to a jump table. Leave those functions as
  `GLOBAL_ASM`.
- No initialized globals or statics.
- A global defined in the same file is addressed differently from an extern
  one: neighbouring globals, or a u64's two halves, share one `lui`. If that
  global is in `.bss` (hd_code's starts at `0x8030F660`), define it without an
  initializer. The absolute linker symbol still pins its address; see the
  `OSTime` block in `hd_code/26570.c`. If it's `.data` or `.rodata`, the
  function waits for the split.

Addresses reached through a `lui`/`addiu` pair that splat didn't match up
(including segment and ROM addresses like `0x02000000` or `0x00487050`) get a
line in `undefined_syms.<module>.<VERSION>.txt`. Don't use constant-address
casts or struct-offset tricks for them.

## Display lists

- The game uses SGI's Fast3D GBI (2.0D-era; `include/2.0I/PR/gbi.h`, without
  `F3DEX_GBI`). Write display lists with the GBI macros. Each `Gfx *_g`
  temporary m2c shows is one macro call on `gfx++`.
- Where no named mode fits, use `gDPSetCombineLERP` for combiners and write
  raw tile/load sequences as `gDPSetTextureImage`/`gDPSetTile`/
  `gDPLoadBlock`/`gDPTileSync`.
- `x & 0x1FFFFFFF` is `K0_TO_PHYS(x)`; `x + 0x80000000` is
  `OS_K0_TO_PHYSICAL(x)`.
- Where the older gbi.h builds different words:
  - `gSPPerspNormalize` is its own command, `0xB4`. `common.h` fixes this.
  - Texture rectangles send s/t with `G_RDPHALF_2` and dsdx/dtdy with
    `G_RDPHALF_CONT`, and `gSPScisTextureRectangle` clamps without 2.0I's
    `s16` casts and sign tests. `hd_code/17E10.c` redefines both, to move to
    `common.h` once agents are done with the files that copy them.
- hd_front_end's `gDPSetPrimColor` with u8 struct fields ORs the colour
  word in a different order (`b | (r | g) | a`); `hd_front_end/9570.c` has a
  local variant.
- Segment 2 (`D_02000000`) holds a buffer with `Mtx[8]` at 0 and vertices from
  `0x1E00`; see `hd_code/30C70.c`.

## Handwritten code

Code that saves registers with `sd`/`ld`, uses `add`/`addi`, passes
arguments in `$v0`/`$v1`/`$t*`/`$s0` or has no normal prologue isn't IDO
output. `tools/gen_code_yaml.py` makes such code an `asm` subsegment, so it
never reaches a stub:

- any code subsegment that saves `$ra` with `sd` and never with `sw` (Rare's
  engine block, `0x56040`–`0x8F860` in us.v11 hd_code);
- libultra's handwritten functions, by name (`HANDWRITTEN_LIBULTRA` in the
  generator), split out of whatever C they sat next to.

If you find more, extend the generator rather than hand-editing a config.

## Known so far

These are only guesses at meaning until they're in `symbols_known.txt`:

- `D_803643E0`/`E4`/`E8` are s32 world coordinates, used as `>> 5`.
- `func_8029A7E4` and `func_8029A7D0` are the debug printf, compiled out:
  `void (char *, ...)`.
- `D_80364AF0` is 0x100-byte records indexed by `D_80364AE8`.
- `D_802E8F94` is 0x44-byte records indexed by `D_802E8BDC`.
- `D_80358070` is a bump-allocator pointer.
- `D_80364A90`, `D_80364A98` and `D_8036C778` are u64 flag words.
  `func_80275270` takes `(u64, f32)`; `func_80275390` and `func_8026F92C`
  take `(u64)`.
- `func_8028B4C4(u8 *romStart, u8 *dst, s32 *size, s32, s32, s32)` loads from
  ROM; callers pass `end - start` of ROM ranges.
- Audio (1C460, 17E10, 20460) and scheduler (26570) structs follow libaudio
  and SGI's sample code.
