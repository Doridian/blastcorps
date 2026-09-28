/* libultra io/conteepprobe.c: the functions.  Its data, if any, is defined by the includer. */
/* Older than ultralib's 2.0I: there is no 16K EEPROM, so any EEPROM is reported as 1. */
#include "common.h"
#include "ultra_internal.h"

s32 osEepromProbe(OSMesgQueue *mq) {
    s32 ret = 0;
    OSContStatus sdata;

    __osSiGetAccess();
    ret = __osEepStatus(mq, &sdata);
    if (ret == 0 && (sdata.type & CONT_EEPROM) != 0) {
        ret = 1;
    } else {
        ret = 0;
    }
    __osSiRelAccess();
    return ret;
}
