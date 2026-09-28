#include "common.h"
#include "ultra_internal.h"

#include "src/libultra/os/thread.c"

/* piacs.c's static piAccessBuf, in hd_code's .bss. */
extern OSMesg D_803FF2D0[1];
#define piAccessBuf D_803FF2D0

#include "src/libultra/io/piacs.c"

#include "src/libultra/os/getthreadpri.c"
