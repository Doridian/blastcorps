/* libultra audio/synaddplayer.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "src/libultra/audio/synthInternals.h"

void alSynAddPlayer(ALSynth *drvr, ALPlayer *client)
{
    OSIntMask mask = osSetIntMask(OS_IM_NONE);

    client->samplesLeft = drvr->curSamples;
    client->next = drvr->head;
    drvr->head   = client;

    osSetIntMask(mask);
}
