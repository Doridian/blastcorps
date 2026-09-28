#include "common.h"
#include "ultra_internal.h"

/* controller.c's own state, in hd_code's .data (not split yet) and .bss. */
extern s32 D_80307730;
extern OSMesgQueue D_803FF2A8;
extern OSMesg D_803FF2C0;
#define __osContinitialized D_80307730
#define __osEepromTimerQ D_803FF2A8
#define __osEepromTimerMsg D_803FF2C0

/* func_802DB0A0 is osContInit. */
#define osContInit func_802DB0A0

#include "src/libultra/io/controller.c"

#include "src/libultra/io/contsetch.c"
