/*
 * libultra kdebugserver.c, in its 2.0D-era form (SM64's libultra has the same
 * code).  Serves memory and register reads to a host debugger over the RDB
 * port.
 */
#include "common.h"
#include "ultra_internal.h"
#include <PR/rdb.h>

static u32 debugState = 0;
static s32 numChars = 0;
static s32 numCharsToReceive = 0;
extern u8 debugBuffer[0x100];
extern OSThread __osThreadSave;

#include "src/libultra/debug/kdebugserver.c"
