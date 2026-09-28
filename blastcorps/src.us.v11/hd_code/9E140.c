#include "common.h"
#include "ultra_internal.h"
#include <PR/rdb.h>

/* libultra kdebugserver.c; its buffer and saved thread are in hd_code's .bss. */
static u32 debugState = 0;
static s32 numChars = 0;
static s32 numCharsToReceive = 0;
extern u8 debugBuffer[0x100];
extern OSThread __osThreadSave;

#include "src/libultra/debug/kdebugserver.c"
