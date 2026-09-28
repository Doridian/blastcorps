/* libultra audio/synstartvoiceparam.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "src/libultra/audio/synthInternals.h"

void alSynStartVoiceParams(ALSynth *s, ALVoice *v, ALWaveTable *w,
                           f32 pitch, s16 vol, ALPan pan, u8 fxmix,
                           ALMicroTime t)
{
    ALStartParamAlt  *update;
    ALFilter    *f;

    if (v->pvoice) {
        /*
         * get new update struct from the free list
         */
        update = (ALStartParamAlt *)__allocParam();
        ALFailIf(update == 0, ERR_ALSYN_NO_UPDATE);

        if (fxmix < 0) { // Not possible
            fxmix = -fxmix;
        }

        /*
         * set offset and fxmix data
         */
        update->delta  = s->paramSamples + v->pvoice->offset;
        update->next   = 0;
        update->type   = AL_FILTER_START_VOICE_ALT;

        update->unity  = v->unityPitch;
        update->pan    = pan;
        update->volume = vol;
        update->fxMix  = fxmix;
        update->pitch  = pitch;
        update->samples = _timeToSamples(s, t);
        update->wave    = w;

        f = v->pvoice->channelKnob;
        (*f->setParam)(f, AL_FILTER_ADD_UPDATE, update);
    }

}
