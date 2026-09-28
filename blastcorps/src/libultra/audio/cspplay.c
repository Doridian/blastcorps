/* libultra audio/cspplay.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "src/libultra/audio/synthInternals.h"

void alCSPPlay(ALCSPlayer *seqp)
{
    ALEvent evt;

    evt.type = AL_SEQP_PLAY_EVT;

    alEvtqPostEvent(&seqp->evtq, &evt, 0);
}
