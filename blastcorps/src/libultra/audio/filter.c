/* libultra audio/filter.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "src/libultra/audio/synthInternals.h"

void alFilterNew(ALFilter *f, ALCmdHandler h, ALSetParam s, s32 type)
{
    f->source    = 0;
    f->handler   = h;
    f->setParam  = s;
    f->inp       = 0;
    f->outp      = 0;
    f->type      = type;
}
