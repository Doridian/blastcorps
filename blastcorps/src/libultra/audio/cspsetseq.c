/* libultra audio/cspsetseq.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "src/libultra/audio/synthInternals.h"

void alCSPSetSeq(ALCSPlayer *seqp, ALCSeq *seq)
{
    ALEvent evt;

    evt.type = AL_SEQP_SEQ_EVT;
    evt.msg.spseq.seq = seq;

    alEvtqPostEvent(&seqp->evtq, &evt, 0);
}
