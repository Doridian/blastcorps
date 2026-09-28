#include "common.h"
#include "ultra_internal.h"

/* cosf.c's constants, in hd_code's .rodata (not split yet). */
extern const du D_8030DA70[5];
extern const du D_8030DA98;
extern const du D_8030DAA0;
extern const du D_8030DAA8;
extern const fu D_8030DAB0;
#define P D_8030DA70
#define rpi D_8030DA98
#define pihi D_8030DAA0
#define pilo D_8030DAA8
#define zero D_8030DAB0

#include "src/libultra/gu/cosf.c"
