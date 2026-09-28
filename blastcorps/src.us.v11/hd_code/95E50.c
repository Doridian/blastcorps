#include "common.h"
#include "ultra_internal.h"

/*
 * libultra vimgr.c.  Its thread, stack, queue and messages are in hd_code's
 * .bss; the messages are defined here (without an initializer) so that IDO
 * stores their fields through one lui.  The absolute symbols still give the
 * addresses.
 */
#define VI_STACKSIZE 0x1000
OSDevMgr __osViDevMgr = { 0 };
extern OSThread D_803FDF70;
extern u8 D_803FE120[VI_STACKSIZE];
extern OSMesgQueue D_803FF120;
extern OSMesg D_803FF138[5];
OSIoMesg D_803FF150;
OSIoMesg D_803FF168;
extern u16 D_803FF17C;
#define viThread D_803FDF70
#define viThreadStack D_803FE120
#define viEventQueue D_803FF120
#define viEventBuf D_803FF138
#define viRetraceMsg D_803FF150
#define viCounterMsg D_803FF168
#define retrace D_803FF17C

#include "src/libultra/io/vimgr.c"
