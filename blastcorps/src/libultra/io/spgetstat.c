/* libultra io/spgetstat.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "ultra_internal.h"

u32 __osSpGetStatus(void) {
    return IO_READ(SP_STATUS_REG);
}
