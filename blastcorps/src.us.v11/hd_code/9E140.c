#include "common.h"
#include "ultra_internal.h"
#include <PR/rdb.h>

/* kdebugserver.c's state, in hd_code's .data (not split yet) and .bss. */
extern u32 debugState;
extern s32 numChars;
extern s32 numCharsToReceive;
extern u8 debugBuffer[0x100];
extern OSThread __osThreadSave;

#include "src/libultra/debug/kdebugserver.c"
