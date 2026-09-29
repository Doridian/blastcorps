#ifndef GAME_GAME_H
#define GAME_GAME_H

#include "game/types.h"

/*
 * The game's global state that most files share.  All of it is hd_code
 * 00000.c's (hd.c's) .bss unless noted.  What each is for is given with its
 * evidence; the names stay address names until they are renamed everywhere.
 */

/*
 * Game modes, one bit each.  hd.c prints both words through func_8026F92C
 * (the number of the set bit) as "enter initlevel game_mode=%d
 * loop_done=%d".
 */
extern u64 D_80364A90; /* game_mode */
extern u64 D_80364A98; /* loop_done */

/*
 * The heap: a bump allocator that hd.c's setup starts at 0x8004B400, above
 * the two framebuffers.  D_80358070 is the next free byte; the level setup
 * loads the level file there (at D_80358074) and prints what the level took
 * ("exit initlevel allocated %d bytes, %x").  func_80257490(&D_80358070, n)
 * rounds it up to a multiple of n.  Segment 1 (D_8035806C) is separate: the
 * static data hd.c loads from ROM to the end of .bss (D_803FF600, "Static
 * end = 0x%x").
 */
extern u8 *D_80358070;

/* Which of the two frames is being built (0 or 1): picks the framebuffer
 * (D_80000400[i]), the per-frame buffer (D_803156F8) and the task slot. */
extern u8 D_8035805C;

/* Nonzero while the game is paused: the scheduler's level timer
 * (Sched.unk280, "TIME IN LEVEL") stops. */
extern u8 D_802E8BD0;

/* The player's (the current vehicle's) position in world units << 5: level
 * data compares x, z (and y) >> 5 with its boxes. */
extern s32 D_803643E0;
extern s32 D_803643E4;
extern s32 D_803643E8;

/*
 * The controller (hd_code 45BB0.c's .bss): the buttons held this frame and
 * the frame before, as OSContPad.button (A_BUTTON, START_BUTTON, ...); a
 * press is `(D_80370C28 & b) && !(D_80370C2A & b)`.
 */
extern u16 D_80370C28;
extern u16 D_80370C2A;

/* Nonzero once hd_front_end is loaded (academy.c's assert "frontEndPresent"). */
extern u8 D_80370C50;

#endif
