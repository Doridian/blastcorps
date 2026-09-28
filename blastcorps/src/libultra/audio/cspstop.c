/* libultra audio/cspstop.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "src/libultra/audio/synthInternals.h"

void alCSPStop(ALCSPlayer *seqp)
{
    ALEvent     evt;

    evt.type = AL_SEQP_STOPPING_EVT;                    
    alEvtqPostEvent(&seqp->evtq, &evt, 0);
}
