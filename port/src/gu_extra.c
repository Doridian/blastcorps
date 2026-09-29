/*
 * libultra code the port needs from stubs it doesn't build whole:
 * guRotateF/guRotate (hd_code/90C50.c is still GLOBAL_ASM; this is the SDK
 * source, which the N64 build doesn't match only by one scheduled lui) and
 * guMtxCatL (hd_code/96800.c, which also holds osSpTaskYield).
 */
#include "common.h"

f32 fcos(f32);

/* .bss of hd_code/90C50.c */
u8 D_803FDF60[0x10];

void guRotateF(float mf[4][4], float a, float x, float y, float z) {
    static float dtor = 3.1415926 / 180.0;
    float sine, cosine, ab, bc, ca, t;

    guNormalize(&x, &y, &z);
    a *= dtor;
    sine = sinf(a);
    cosine = fcos(a);
    t = (1 - cosine);
    ab = x * y * t;
    bc = y * z * t;
    ca = z * x * t;
    guMtxIdentF(mf);
    t = x * x;
    mf[0][0] = t + cosine * (1 - t);
    mf[2][1] = bc - (x * sine);
    mf[1][2] = bc + (x * sine);
    t = y * y;
    mf[1][1] = t + cosine * (1 - t);
    mf[2][0] = ca + (y * sine);
    mf[0][2] = ca - (y * sine);
    t = z * z;
    mf[2][2] = t + cosine * (1 - t);
    mf[1][0] = ab - (z * sine);
    mf[0][1] = ab + (z * sine);
}

void guRotate(Mtx *m, float a, float x, float y, float z) {
    float mf[4][4];

    guRotateF(mf, a, x, y, z);
    guMtxF2L(mf, m);
}

#include "src/libultra/gu/mtxcatl.c"

/* the Controller Pak's CRC, which the front end also uses for its saves */
#include "src/libultra/io/crc.c"
