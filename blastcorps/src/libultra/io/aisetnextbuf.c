/* libultra io/aisetnextbuf.c: the functions.  Its data, if any, is defined by the includer. */
/* Older than ultralib's: the DMA-end bug check is ((bufPtr + size) & 0x3FFF) == 0x2000, and hdwrBugFlag is the includer's. */
#include "common.h"
#include "ultra_internal.h"

s32 osAiSetNextBuffer(void *bufPtr, u32 size) {
    char *bptr = bufPtr;

    if (hdwrBugFlag) {
        bptr = (char *)bufPtr - 0x2000;
    }
    if ((((u32)bufPtr + size) & 0x3FFF) == 0x2000) {
        hdwrBugFlag = TRUE;
    } else {
        hdwrBugFlag = FALSE;
    }
    if (__osAiDeviceBusy()) {
        return -1;
    }
    IO_WRITE(AI_DRAM_ADDR_REG, osVirtualToPhysical(bptr));
    IO_WRITE(AI_LEN_REG, size);
    return 0;
}
