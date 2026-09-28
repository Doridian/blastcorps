/* libultra audio/cspgetvol.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "src/libultra/audio/synthInternals.h"

s16 alCSPGetVol(ALCSPlayer *seqp)
{
    return seqp->vol;
}
