/* libultra io/si.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "ultra_internal.h"

int __osSiDeviceBusy(void) {
    register u32 stat = IO_READ(SI_STATUS_REG);

    if (stat & (SI_STATUS_DMA_BUSY | SI_STATUS_RD_BUSY)) {
        return 1;
    } else {
        return 0;
    }
}
