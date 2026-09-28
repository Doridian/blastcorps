/* libultra io/sptaskyield.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "ultra_internal.h"

void osSpTaskYield(void) {
    __osSpSetStatus(SP_SET_YIELD);
}
