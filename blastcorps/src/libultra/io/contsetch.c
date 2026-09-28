/* libultra io/contsetch.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "ultra_internal.h"

s32 osContSetCh(u8 ch) {
    s32 ret = 0;

    __osSiGetAccess();
    if (ch > MAXCONTROLLERS) {
        __osMaxControllers = MAXCONTROLLERS;
    } else {
        __osMaxControllers = ch;
    }
    __osContLastCmd = CONT_CMD_END;
    __osSiRelAccess();
    return ret;
}
