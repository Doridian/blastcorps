#ifndef GAME_CAMERA_H
#define GAME_CAMERA_H

#include "game/types.h"

/*
 * The gameplay camera, separate variables in hd.c's (hd_code 00000.c's)
 * .bss.  hd.c's view setup eases the eye towards its target each frame and
 * passes it and the look-at point to guLookAt/guLookAtReflect; the rest of
 * its state (the look-at point D_80365084..8C and its target D_80365078..80)
 * is only used there.
 */

/* The eye, in world units << 16 (hd.c divides by 65536 for guLookAt; >> 11
 * gives the << 5 units the level data uses).  It follows D_803643EC..F4. */
extern s32 D_803643F8;
extern s32 D_803643FC;
extern s32 D_80364400;

/* The view's yaw from the eye to the look-at point, 0..0xFFF for a full
 * turn (hd.c works it out per quadrant, 3E4C0.c converts it to degrees). */
extern s16 D_80364452;

/* guPerspective's fovy (45.0 after a level's setup, func_80262150). */
extern f32 D_80364438;

#endif
