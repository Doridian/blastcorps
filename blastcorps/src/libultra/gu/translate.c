/* libultra gu/translate.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "ultra_internal.h"

void guTranslateF(float mf[4][4], float x, float y, float z) {
    guMtxIdentF(mf);
    mf[3][0] = x;
    mf[3][1] = y;
    mf[3][2] = z;
}

void guTranslate(Mtx *m, float x, float y, float z) {
    Matrix mf;

    guTranslateF(mf, x, y, z);
    guMtxF2L(mf, m);
}
