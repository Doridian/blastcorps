#include "common.h"

/* func_802D81F0 is alCSPPlay, func_802D8220 alCSPSetVol. */
#define alCSPPlay func_802D81F0
#define alCSPSetVol func_802D8220

/* Built -O3, which emits the files' functions in reverse order. */
#include "src/libultra/audio/cspsetvol.c"
#include "src/libultra/audio/cspplay.c"
