/* libultra audio/synfreevoice.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "src/libultra/audio/synthInternals.h"

void alSynFreeVoice(ALSynth *drvr, ALVoice *voice)
{
    ALFilter *f;
    ALFreeParam *update;

    if (voice->pvoice) {

        if (voice->pvoice->offset) { /* if voice was stolen */
            update = (ALFreeParam *)__allocParam();
            ALFailIf(update == 0, ERR_ALSYN_NO_UPDATE);

            /*
             * set voice data
             */
            update->delta  = drvr->paramSamples + voice->pvoice->offset;
            update->type   = AL_FILTER_FREE_VOICE;
            update->pvoice = voice->pvoice;

            f = voice->pvoice->channelKnob;
            (*f->setParam)(f, AL_FILTER_ADD_UPDATE, update);
        } else {
            _freePVoice(drvr, voice->pvoice);
        }

        voice->pvoice = 0;

    }
}
