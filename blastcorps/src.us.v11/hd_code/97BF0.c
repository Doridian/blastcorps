#include "common.h"
#include "ultra_internal.h"

/* libultra piacs.c; its static piAccessBuf is in hd_code's .bss. */
u32 __osPiAccessQueueEnabled = 0;
extern OSMesg D_803FF2D0[1];
#define piAccessBuf D_803FF2D0

#include "src/libultra/io/piacs.c"

#include "src/libultra/os/getthreadpri.c"
