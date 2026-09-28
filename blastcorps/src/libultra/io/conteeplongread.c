/* libultra io/conteeplongread.c: the functions.  Its data, if any, is defined by the includer. */
/*
 * Older than ultralib's 2.0I: the start address is range-checked first, and
 * each block is followed by the same 12ms wait as a write.
 */
#include "common.h"
#include "ultra_internal.h"

/* This libultra's os.h scaled by osClockRate without 2.0I's /15625 trick. */
#undef OS_USEC_TO_CYCLES
#define OS_USEC_TO_CYCLES(n) (((u64)(n) * osClockRate) / 1000000LL)

s32 osEepromLongRead(OSMesgQueue *mq, u8 address, u8 *buffer, int length) {
    s32 ret = 0;

    if (address > EEPROM_MAXBLOCKS) {
        return -1;
    }

    while (length > 0) {
        ERRCK(osEepromRead(mq, address, buffer));
        length -= EEPROM_BLOCK_SIZE;
        address++;
        buffer += EEPROM_BLOCK_SIZE;
        osSetTimer(&__osEepromTimer, OS_USEC_TO_CYCLES(12000), 0, &__osEepromTimerQ, &__osEepromTimerMsg);
        osRecvMesg(&__osEepromTimerQ, NULL, OS_MESG_BLOCK);
    }

    return ret;
}
