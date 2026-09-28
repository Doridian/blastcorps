/* libultra io/sirawread.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "ultra_internal.h"

s32 __osSiRawReadIo(u32 devAddr, u32 *data) {
    if (__osSiDeviceBusy()) {
        return -1;
    }
    *data = IO_READ(devAddr);
    return 0;
}
