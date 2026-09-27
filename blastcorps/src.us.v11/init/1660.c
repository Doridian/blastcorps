#include "common.h"
#include <ultra64.h>

extern s32 method;
extern s32 D_802229E0;
extern u8 *inbuf;
extern s32 window;
extern s32 bytes_in;
extern s32 bytes_out;
extern s32 insize;
extern s32 inptr;
extern s32 outcnt;

void clear_bufs(void);
s32  get_method(void);
s32  inflate(void);


void func_80220360(s32 *arg0, s32 *arg1, s32 arg2) {
    inbuf = *arg0;
    window = *arg1;
    D_802229E0 = arg2;

    clear_bufs();

    if (*(inbuf + inptr) != 0x1F) {
        inptr += 1;
    }
    method = get_method();
    if (method >= 0) {
        inflate();
        *arg0 += inptr;
        *arg1 += outcnt;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/init/1660/get_method.s")

/* gzip 1.2.4, bits.c */
unsigned bi_reverse(unsigned code, int len) {
    register unsigned res = 0;
    do {
        res |= code & 1;
        code >>= 1, res <<= 1;
    } while (--len > 0);
    return res >> 1;
}

/* gzip 1.2.4, util.c */
void clear_bufs(void) {
    outcnt = 0;
    insize = inptr = 0;
    bytes_in = bytes_out = 0;
}
