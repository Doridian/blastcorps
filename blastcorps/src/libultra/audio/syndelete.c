/* libultra audio/syndelete.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "src/libultra/audio/synthInternals.h"

void alSynDelete(ALSynth *drvr)
{
    drvr->head = 0;
}
