/* libultra audio/synsetpriority.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "src/libultra/audio/synthInternals.h"

void alSynSetPriority(ALSynth *s, ALVoice *voice, s16 priority)
{
    voice->priority = priority;
}
