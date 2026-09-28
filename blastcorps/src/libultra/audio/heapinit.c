/* libultra audio/heapinit.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "src/libultra/audio/synthInternals.h"

void alHeapInit(ALHeap *hp, u8 *base, s32 len)
{
    s32 extraAlign = (AL_CACHE_ALIGN+1) - ((s32) base & AL_CACHE_ALIGN);

    if (extraAlign != AL_CACHE_ALIGN+1)
        hp->base = base + extraAlign;
    else
        hp->base = base;

    hp->len  = len;
    hp->cur  = hp->base;
    hp->count = 0;
}
