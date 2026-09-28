#include "common.h"
#include "ultra_internal.h"

/* libultra initialize.c, from before 2.0J and before osViClock. */
OSTime osClockRate = OS_CLOCK_RATE;
u32 __osShutdown = 0;

#include "src/libultra/os/initialize.c"
#include "src/libultra/io/pirawdma.c"
#include "src/libultra/io/pigetstat.c"
