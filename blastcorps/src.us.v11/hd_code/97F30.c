#include "common.h"
#include "ultra_internal.h"

/*
 * libultra timerintr.c.  __osCurrentTime is in hd_code's .bss, but defining
 * it here makes IDO store both halves through one lui; the absolute symbol
 * still gives its address.
 */
OSTime __osCurrentTime;
OSTimer *__osTimerList = &__osBaseTimer;

#include "src/libultra/os/timerintr.c"
