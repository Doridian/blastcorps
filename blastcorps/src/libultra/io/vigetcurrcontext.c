/* libultra io/vigetcurrcontext.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "ultra_internal.h"

__OSViContext *__osViGetCurrentContext(void) {
    return __osViCurr;
}
