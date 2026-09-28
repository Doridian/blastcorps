#include "common.h"
#include "ultra_internal.h"

/* siacs.c's state; the queue and its buffer are in hd_code's .bss. */
extern OSMesg D_803FF330[1];
extern OSMesgQueue __osSiAccessQueue;
u32 __osSiAccessQueueEnabled = 0;
#define siAccessBuf D_803FF330

#include "src/libultra/io/siacs.c"

#include "src/libultra/io/si.c"

