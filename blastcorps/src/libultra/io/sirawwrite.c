/* libultra io/sirawwrite.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "ultra_internal.h"

s32 __osSiRawWriteIo(u32 devAddr, u32 data) {
    if (__osSiDeviceBusy()) {
        return -1;
    }
    IO_WRITE(devAddr, data);
    return 0;
}
