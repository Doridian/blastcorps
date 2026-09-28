/* libultra io/aigetlen.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "ultra_internal.h"

u32 osAiGetLength(void) {
    return IO_READ(AI_LEN_REG);
}
