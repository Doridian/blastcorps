/* libultra audio/synstartvoice.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "src/libultra/audio/synthInternals.h"

void alSynStartVoice(ALSynth *synth, ALVoice *v, ALWaveTable *table)
{
    ALStartParam  *update;
    ALFilter *f;

    if (v->pvoice) {

        update = (ALStartParam *)__allocParam();
        ALFailIf(update == 0, ERR_ALSYN_NO_UPDATE);

        /*
         * send the start message to the motion control filter
         */
        update->delta  = synth->paramSamples + v->pvoice->offset;
        update->type   = AL_FILTER_START_VOICE;
        update->wave   = table;
        update->next   = 0;
        update->unity  = v->unityPitch;

        f = v->pvoice->channelKnob;
        (*f->setParam)(f, AL_FILTER_ADD_UPDATE, update);
    }
}
