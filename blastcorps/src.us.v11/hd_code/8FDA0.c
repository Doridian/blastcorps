#include "common.h"
#include "ultra_internal.h"

/* libultra pimgr.c; the thread, its stack and the event queue are in hd_code's .bss. */
#define PI_STACKSIZE 0x1000
OSDevMgr __osPiDevMgr = { 0 };
extern OSThread D_803FCD90;
extern u8 D_803FCF40[PI_STACKSIZE];
extern OSMesgQueue D_803FDF40;
extern OSMesg D_803FDF58[1];
#define piThread D_803FCD90
#define piThreadStack D_803FCF40
#define piEventQueue D_803FDF40
#define piEventBuf D_803FDF58

#include "src/libultra/io/pimgr.c"
