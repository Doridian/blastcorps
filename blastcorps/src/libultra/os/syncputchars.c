/* libultra os/syncputchars.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "ultra_internal.h"
#include <PR/rdb.h>

void __osSyncPutChars(int type, int length, const char *buf) {
    __OSRdbPacket packet;
    int i;
    u32 mask;

    packet.type = type;
    packet.length = length;
    for (i = 0; i < length; i++) {
        /* libultra was built with unsigned chars; this build uses -signed. */
        packet.buf[i] = ((const u8 *)buf)[i];
    }
    while (!__osAtomicDec(&__osRdbWriteOK)) {
        ;
    }
    mask = __osDisableInt();
    *(vu32 *)RDB_BASE_REG = *(vu32 *)&packet;
    while (!(__osGetCause() & CAUSE_IP6)) {
        ;
    }
    *(vu32 *)RDB_READ_INTR_REG = 0;
    __osRdbWriteOK++;
    __osRestoreInt(mask);
}
