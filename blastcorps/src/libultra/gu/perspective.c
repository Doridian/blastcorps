/* libultra gu/perspective.c: the functions.  Its data, if any, is defined by the includer. */
/* An includer whose .rodata isn't split yet supplies the pi/180 constant as PERSPECTIVE_DTOR. */
#include "common.h"
#include "ultra_internal.h"

#ifndef PERSPECTIVE_DTOR
#define PERSPECTIVE_DTOR (3.1415926 / 180.0)
#endif

void guPerspectiveF(float mf[4][4], u16 *perspNorm, float fovy, float aspect, float near, float far, float scale) {
    float cot;
    int i, j;

    guMtxIdentF(mf);
    fovy *= PERSPECTIVE_DTOR;
    cot = cosf(fovy / 2) / sinf(fovy / 2);
    mf[0][0] = cot / aspect;
    mf[1][1] = cot;
    mf[2][2] = (near + far) / (near - far);
    mf[2][3] = -1;
    mf[3][2] = (2 * near * far) / (near - far);
    mf[3][3] = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            mf[i][j] *= scale;
        }
    }
    if (perspNorm != (u16 *)NULL) {
        if (near + far <= 2.0) {
            *perspNorm = (u16)0xFFFF;
        } else {
            *perspNorm = (u16)((2.0 * 65536.0) / (near + far));
            if (*perspNorm <= 0) {
                *perspNorm = (u16)0x0001;
            }
        }
    }
}

void guPerspective(Mtx *m, u16 *perspNorm, float fovy, float aspect, float near, float far, float scale) {
    Matrix mf;

    guPerspectiveF(mf, perspNorm, fovy, aspect, near, far, scale);
    guMtxF2L(mf, m);
}
