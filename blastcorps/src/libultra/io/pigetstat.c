/* libultra io/pigetstat.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "ultra_internal.h"

u32 osPiGetStatus(void) {
    return IO_READ(PI_STATUS_REG);
}
