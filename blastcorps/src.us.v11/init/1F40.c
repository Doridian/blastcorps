#include "common.h"
#include "ultra_internal.h"

/*
 * libultra initialize.c, from before 2.0J and before osViClock.  The C is
 * known (see symbols_known.txt), but it only matches with osClockRate
 * defined in this file: both of its halves are stored through one lui.  That
 * needs init's .data split first.
 */
#pragma GLOBAL_ASM("asm/nonmatchings/init/1F40/osInitialize.s")

s32 osPiRawStartDma(s32 direction, u32 devAddr, void *dramAddr, u32 size) {
    register u32 stat;

    WAIT_ON_IOBUSY(stat);
    IO_WRITE(PI_DRAM_ADDR_REG, osVirtualToPhysical(dramAddr));
    IO_WRITE(PI_CART_ADDR_REG, K1_TO_PHYS((u32)osRomBase | devAddr));
    switch (direction) {
        case OS_READ:
            IO_WRITE(PI_WR_LEN_REG, size - 1);
            break;
        case OS_WRITE:
            IO_WRITE(PI_RD_LEN_REG, size - 1);
            break;
        default:
            return -1;
    }
    return 0;
}

u32 osPiGetStatus(void) {
    return IO_READ(PI_STATUS_REG);
}
