#include "common.h"
#include "ultra_internal.h"

/* xprintf.c's tables, in hd_code's .data and .rodata (not split yet). */
extern char D_803077A0[];         /* spaces */
extern char D_803077C4[];         /* zeroes */
extern char D_8030DE20[];         /* "hlL" */
extern const char D_8030DE24[];   /* fchar */
extern const unsigned int D_8030DE2C[]; /* fbit */
#define spaces D_803077A0
#define zeroes D_803077C4
#define PRINTF_QUALS D_8030DE20
#define fchar D_8030DE24
#define fbit D_8030DE2C

/* _Putfld is xprintf.c's static _Putfld. */

#include "src/libultra/libc/xprintf.c"

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/983F0/_Putfld.s")
