#include "common.h"

#include "src/libultra/io/aisetfreq.c"

/* osAiSetNextBuffer's static hdwrBugFlag, in hd_code's .data (not split yet). */
extern u8 D_80306E40;
#define hdwrBugFlag D_80306E40

/* osAiSetNextBuffer is osAiSetNextBuffer. */

#include "src/libultra/io/aisetnextbuf.c"
