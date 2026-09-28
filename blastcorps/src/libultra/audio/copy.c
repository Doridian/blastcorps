/* libultra audio/copy.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "src/libultra/audio/synthInternals.h"

void alCopy(void *src, void *dest, s32 len)
{
    s32  i;
    u8 *s = (u8 *)src;
    u8 *d = (u8 *)dest;

    for (i = 0; i < len; i++){
        *d++ = *s++;
    }
}
