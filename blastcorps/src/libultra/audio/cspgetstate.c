/* libultra audio/cspgetstate.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "src/libultra/audio/synthInternals.h"

s32 alCSPGetState(ALCSPlayer *seqp)
{
    return seqp->state;
}
