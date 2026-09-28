/* libultra io/dpgetstat.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "ultra_internal.h"

u32 osDpGetStatus(void) {
    return IO_READ(DPC_STATUS_REG);
}
