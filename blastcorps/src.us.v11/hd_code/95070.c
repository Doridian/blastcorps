#include "common.h"
#include "ultra_internal.h"

/* sins.c's table, in hd_code's .data (not split yet). */
extern s16 D_803065D0[];
#define sintable D_803065D0

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/95070/sins.s")
#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/95070/coss.s")

/* vi.c's state and the two modes it picks from, in hd_code's .data (not split yet). */
extern __OSViContext D_80306DD0[2];
extern u32 D_80306E38;
extern OSViMode D_803077F0;
extern OSViMode D_80307840;
#define vi D_80306DD0
#define tvType D_80306E38
#define viModeNtsc D_803077F0
#define viModeMpal D_80307840

/* func_802D98D0 is __osViInit. */
#define __osViInit func_802D98D0

#include "src/libultra/io/vi.c"
