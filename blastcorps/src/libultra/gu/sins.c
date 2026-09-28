/* libultra gu/sins.c: the functions.  Its data, if any, is defined by the includer. */
/* The includer provides sintable (sintable.h's table). */
#include "common.h"
#include "ultra_internal.h"

signed short sins(unsigned short x) {
    /* 0 <= x < 0x10000  ==>  0 <= x < 2PI */
    signed short val;

    x >>= 4; /* Now range 0 <= x < 0x1000 */

    if (x & 0x400) {
        val = sintable[0x3ff - (x & 0x3ff)];
    } else {
        val = sintable[x & 0x3ff];
    }

    if (x & 0x800) {
        return -val;
    } else {
        return val;
    }
}
