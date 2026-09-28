#include "common.h"

/* A recorded replay frame: 0x14 bytes. */
typedef struct {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ s32 z;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ s16 unk12;
} UnkStruct_8039CA68;

/* A spline path: 0x84 bytes. */
typedef struct {
    /* 0x00 */ s16 pts[10][6];
    /* 0x78 */ s32 count;
    /* 0x7C */ f32 tension;
    /* 0x80 */ u8 speed;
    /* 0x81 */ u8 mode;
} UnkStruct_802FE980;

typedef struct {
    /* 0x00 */ u32 unk0;
    /* 0x04 */ s32 unk4;
} UnkStruct_80294B64;

typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
} UnkStruct_80293F84;

typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
} UnkStruct_802936AC;

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ u8 unk6;
} UnkStruct_802FEDA0; /* size = 0x8 */

typedef struct {
    /* 0x00 */ u32 from;
    /* 0x04 */ u32 to;
} UnkStruct_802FF11C;

typedef struct {
    /* 0x00 */ s32 x[4];
    /* 0x10 */ s32 z[4];
    /* 0x20 */ s8 list[8];
    /* 0x28 */ u8 unk28;
} UnkStruct_802FF150;

extern s32 func_802AC4C4(s32, s32, s32, s32, s32, s32, s32, s32);
typedef struct {
    /* 0x0000 */ Mtx unk0[8];
    /* 0x0200 */ u8 unk200[0x12C0];
    /* 0x14C0 */ Mtx unk14C0;
} UnkStruct_02000000;

extern UnkStruct_02000000 D_02000000;

void func_80295394(s32 *arg0, s32 *arg1, s32 *arg2, s16 *arg3, s16 *arg4, s16 *arg5);
extern void func_802AA6D0(s32, s32, s32, s16, s32, s32, s32, Mtx *);
s16 func_80295924(s16 arg0, s16 arg1, f32 arg2);
void func_802949B0(s32 arg0);
f32 func_80294840(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
extern void func_8026A2E8(f32, f32 *);
extern u8 func_8027EED8(s32, s32, s16 *);
extern void func_802608C8(void *);
extern void func_8029A7E4(char *, ...);
extern s32 func_80286038(s32);

extern u8 D_802E8BD0;
extern UnkStruct_802FE980 D_802FE980[];
extern char D_8030CD60[];
extern f32 D_8030CD50;
extern s32 D_803156C0;
extern u32 D_803156C4;
extern u64 D_80364A90;
extern s32 D_803643E0;
extern s32 D_803643E4;
extern s32 D_803643E8;
extern u8 D_803643D4;
extern f32 D_8039CA10[4][4];
extern f32 D_8039CA50;
extern f32 D_8039CA54;
extern f32 D_8039CA58;
extern u8 D_8039CA61;
extern u8 D_8039CA62;
extern UnkStruct_8039CA68 *D_8039CA68[2];
extern s32 D_8039CA70[2];
extern s32 D_8039CA78;
extern u8 D_8039CA7C;
extern u8 D_8039CA7D;
extern u8 D_8039CA7E;
extern s32 D_8039CA80;
extern s32 D_8039CA84;
extern u32 D_8039CA88;
extern u8 D_8039CA8C;
extern s16 D_803ED390[3];
extern s32 D_802E8BDC;
extern UnkStruct_802FEDA0 D_802FEDA0[];
extern void *D_8036DCD8;
extern s16 D_8036E4C8;
extern u8 D_8036E4CA;
extern f64 D_8030CD48;
extern s32 D_802FF0D0[];
extern void *D_803BDB00;
extern void *D_803BDB04;
extern void *D_803BDB08;
extern UnkStruct_802FF150 D_802FF150[];
extern u16 D_803C30A8[];
extern UnkStruct_802FF11C D_802FF11C[6];
extern char D_8030CD7C[];
extern char D_8030CDA8[];
extern char D_8030CDB0[];
extern f64 D_8030CDC0;
extern f64 D_8030CDC8;
extern f64 D_8030CDD0;

/* Needs a jump table, which would go in the unsplit .rodata. */
#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/4EBE0/func_802933A0.s")

void func_802936AC(f32 arg0[4][4], s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 *arg5, s16 *arg6, s16 *arg7,
                   UnkStruct_802936AC *arg8, s32 arg9) {
    f32 mf[4][4];
    s32 j;
    u8 found;
    s16 angle;
    s16 px;
    s16 pz;
    s16 dx;
    s16 dz;
    s16 adx;
    s16 adz;
    u8 mask;
    u8 dir;
    s32 opp;
    s16 cur;
    s16 target;
    s16 diff;
    s32 dist;

    j = 0;
    found = 0;
    if (D_8036E4C8 == 0 && D_8036DCD8 != NULL) {
        func_802608C8(D_8036DCD8);
    }
    if (D_802E8BD0 == 0) {
        if (D_8036E4CA != 0) {
            arg8->unk8 = -1;
            switch (arg8->unk0) {
                case 1:
                    arg8->unk0 = 2;
                    break;
                case 2:
                    arg8->unk0 = 1;
                    break;
                case 4:
                    arg8->unk0 = 8;
                    break;
                case 8:
                    arg8->unk0 = 4;
                    break;
            }
        }
        while (j < 0x66 && found == 0) {
            if (D_802FEDA0[j].unk0 == D_802E8BDC && arg3 >= D_802FEDA0[j].unk2 - 5 &&
                arg4 >= D_802FEDA0[j].unk4 - 5 && arg3 < D_802FEDA0[j].unk2 + 5 && arg4 < D_802FEDA0[j].unk4 + 5 &&
                arg8->unk8 != j) {
                found = 1;
            } else {
                j++;
            }
        }
        if (found != 0) {
            arg8->unk8 = j;
            px = D_803643E0 >> 5, pz = D_803643E8 >> 5;
            if (D_8036E4C8 == 0) {
                dx = px - arg3, dz = pz - arg4;
            } else {
                dx = arg3 - px;
                dz = arg4 - pz;
            }
            if (dx < 0) {
                adx = -dx;
            } else {
                adx = dx;
            }
            if (dz < 0) {
                adz = -dz;
            } else {
                adz = dz;
            }
            switch (arg8->unk0) {
                case 1:
                    opp = 2;
                    break;
                case 2:
                    opp = 1;
                    break;
                case 4:
                    opp = 8;
                    break;
                case 8:
                    opp = 4;
                    break;
                default:
                    opp = 0;
                    break;
            }
            if (D_802FEDA0[j].unk6 & opp) {
                mask = D_802FEDA0[j].unk6 & (opp ^ 0xFF);
            } else {
                mask = D_802FEDA0[j].unk6;
            }
            if (dz > 0 && adz >= adx) {
                dir = 1;
            }
            if (dz <= 0 && adz >= adx) {
                dir = 2;
            }
            if (dx > 0 && adx >= adz) {
                dir = 4;
            }
            if (dx <= 0 && adx >= adz) {
                dir = 8;
            }
            if (mask & dir) {
                arg8->unk0 = dir;
            } else {
                if (dir == 1) {
                    if (mask & 4) {
                        arg8->unk0 = 4;
                    } else if (mask & 8) {
                        arg8->unk0 = 8;
                    } else {
                        arg8->unk0 = 2;
                    }
                }
                if (dir == 2) {
                    if (mask & 8) {
                        arg8->unk0 = 8;
                    } else if (mask & 4) {
                        arg8->unk0 = 4;
                    } else {
                        arg8->unk0 = 1;
                    }
                }
                if (dir == 4) {
                    if (mask & 1) {
                        arg8->unk0 = 1;
                    } else if (mask & 2) {
                        arg8->unk0 = 2;
                    } else {
                        arg8->unk0 = 8;
                    }
                }
                if (dir == 8) {
                    if (mask & 2) {
                        arg8->unk0 = 2;
                    } else if (mask & 1) {
                        arg8->unk0 = 1;
                    } else {
                        arg8->unk0 = 4;
                    }
                }
            }
        }
        if (D_8036E4C8 == 0) {
            dist = arg9;
        } else {
            dist = (arg9 * 3) / 2;
        }
        switch (arg8->unk0) {
            case 1:
                *arg5 = arg3 - arg1;
                *arg7 = arg4 - arg2 + dist;
                angle = 270;
                break;
            case 2:
                *arg5 = arg3 - arg1;
                *arg7 = arg4 - arg2 - dist;
                angle = 90;
                break;
            case 4:
                *arg5 = arg3 - arg1 + dist;
                *arg7 = arg4 - arg2;
                angle = 0;
                break;
            case 8:
                *arg5 = arg3 - arg1 - dist;
                *arg7 = arg4 - arg2;
                angle = 180;
                break;
        }
        *arg6 = 0;
        cur = (arg8->unk4 << 16) / 360;
        target = (angle << 16) / 360;
        diff = target - cur;
        if (((diff > 0) ? diff : -diff) < 2000) {
            arg8->unk4 = angle;
        } else {
            if (diff > 0) {
                arg8->unk4 += 10;
            } else {
                arg8->unk4 -= 10;
            }
            if (arg8->unk4 >= 360) {
                arg8->unk4 -= 360;
            }
            if (arg8->unk4 < 0) {
                arg8->unk4 += 360;
            }
        }
    } else {
        *arg5 = arg3 - arg1;
        *arg6 = 0;
        *arg7 = arg4 - arg2;
    }
    guRotateF(arg0, arg8->unk4, 0.0f, 1.0f, 0.0f);
    if (D_8036E4C8 == 0 || (D_803156C4 & 0xF) >= 7) {
        guTranslateF(mf, *arg5, *arg6, *arg7);
    } else {
        guTranslateF(mf, 0.0f, 20000.0f, 0.0f);
    }
    guMtxCatF(arg0, mf, arg0);
}

void func_80293F84(f32 arg0[4][4], s16 arg1, s16 arg2, s16 *arg3, s16 *arg4, s16 *arg5, UnkStruct_80293F84 *arg6,
                   s32 arg7) {
    s32 cur;
    s32 n;
    f32 rx;
    f32 ry;
    f32 rz;
    f32 mf[4][4];
    u8 idx[4];
    f32 p0;
    f32 p1;
    f32 p2;
    f32 p3;

    func_802949B0(arg7);
    if (D_802E8BD0 == 0) {
        arg6->unk4 += D_802FE980[arg7].speed;
        if (arg6->unk4 >= 1000) {
            arg6->unk4 = 0;
            arg6->unk0++;
            if (arg6->unk0 >= D_802FE980[arg7].count - 1) {
                arg6->unk0 = 0;
            }
        }
    }
    cur = arg6->unk0;
    n = D_802FE980[arg7].count - 1;
    if (cur <= 0) {
        idx[0] = n + cur - 1;
    } else {
        idx[0] = cur - 1;
    }
    idx[1] = cur;
    if (cur + 1 >= n) {
        idx[2] = cur - n + 1;
    } else {
        idx[2] = cur + 1;
    }
    if (cur + 2 >= n) {
        idx[3] = cur - n + 2;
    } else {
        idx[3] = cur + 2;
    }
    D_8039CA50 = (f32) arg6->unk4 / D_8030CD48;
    D_8039CA54 = D_8039CA50 * D_8039CA50;
    D_8039CA58 = D_8039CA54 * D_8039CA50;
    p0 = D_802FE980[arg7].pts[idx[0]][3];
    p1 = D_802FE980[arg7].pts[idx[1]][3];
    p2 = D_802FE980[arg7].pts[idx[2]][3];
    p3 = D_802FE980[arg7].pts[idx[3]][3];
    func_8026A2E8(p0, &p1);
    func_8026A2E8(p1, &p2);
    func_8026A2E8(p2, &p3);
    rx = func_80294840(p0, p1, p2, p3);
    p0 = D_802FE980[arg7].pts[idx[0]][4];
    p1 = D_802FE980[arg7].pts[idx[1]][4];
    p2 = D_802FE980[arg7].pts[idx[2]][4];
    p3 = D_802FE980[arg7].pts[idx[3]][4];
    func_8026A2E8(p0, &p1);
    func_8026A2E8(p1, &p2);
    func_8026A2E8(p2, &p3);
    ry = func_80294840(p0, p1, p2, p3);
    p0 = D_802FE980[arg7].pts[idx[0]][5];
    p1 = D_802FE980[arg7].pts[idx[1]][5];
    p2 = D_802FE980[arg7].pts[idx[2]][5];
    p3 = D_802FE980[arg7].pts[idx[3]][5];
    func_8026A2E8(p0, &p1);
    func_8026A2E8(p1, &p2);
    func_8026A2E8(p2, &p3);
    rz = func_80294840(p0, p1, p2, p3);
    *arg3 = func_80294840(D_802FE980[arg7].pts[idx[0]][0], D_802FE980[arg7].pts[idx[1]][0],
                        D_802FE980[arg7].pts[idx[2]][0], D_802FE980[arg7].pts[idx[3]][0]);
    *arg5 = func_80294840(D_802FE980[arg7].pts[idx[0]][2], D_802FE980[arg7].pts[idx[1]][2],
                        D_802FE980[arg7].pts[idx[2]][2], D_802FE980[arg7].pts[idx[3]][2]);
    switch (D_802FE980[arg7].mode) {
        case 0:
            *arg4 = func_80294840(D_802FE980[arg7].pts[idx[0]][1], D_802FE980[arg7].pts[idx[1]][1],
                                  D_802FE980[arg7].pts[idx[2]][1], D_802FE980[arg7].pts[idx[3]][1]);
            break;
        case 1:
            func_8027EED8(*arg3 + arg1, *arg5 + arg2, arg4);
            break;
    }
    guRotateF(mf, rx, 1.0f, 0.0f, 0.0f);
    guRotateF(arg0, ry, 0.0f, 1.0f, 0.0f);
    guMtxCatF(mf, arg0, mf);
    guRotateF(arg0, rz, 0.0f, 0.0f, 1.0f);
    guMtxCatF(mf, arg0, mf);
    guTranslateF(arg0, *arg3, *arg4, *arg5);
    guMtxCatF(mf, arg0, arg0);
}

f32 func_80294840(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;

    a = D_8039CA10[0][0] * arg0 + D_8039CA10[1][0] * arg1 + D_8039CA10[2][0] * arg2 + D_8039CA10[3][0] * arg3;
    b = D_8039CA10[0][1] * arg0 + D_8039CA10[1][1] * arg1 + D_8039CA10[2][1] * arg2 + D_8039CA10[3][1] * arg3;
    c = D_8039CA10[0][2] * arg0 + D_8039CA10[1][2] * arg1 + D_8039CA10[2][2] * arg2 + D_8039CA10[3][2] * arg3;
    d = D_8039CA10[0][3] * arg0 + D_8039CA10[1][3] * arg1 + D_8039CA10[2][3] * arg2 + D_8039CA10[3][3] * arg3;
    return a * D_8039CA58 + D_8039CA54 * b + D_8039CA50 * c + d;
}

void func_802949B0(s32 arg0) {
    f32 t;

    t = D_802FE980[arg0].tension;
    D_8039CA10[0][0] = -t;
    D_8039CA10[0][1] = t * 2.0;
    D_8039CA10[0][2] = -t;
    D_8039CA10[0][3] = 0.0f;
    D_8039CA10[1][0] = 2.0 - t;
    D_8039CA10[1][1] = t - 3.0;
    D_8039CA10[1][2] = 0.0f;
    D_8039CA10[1][3] = 1.0f;
    D_8039CA10[2][0] = t - 2.0;
    D_8039CA10[2][1] = 3.0 - t * 2.0;
    D_8039CA10[2][2] = t;
    D_8039CA10[2][3] = 0.0f;
    D_8039CA10[3][0] = t;
    D_8039CA10[3][1] = -t;
    D_8039CA10[3][2] = 0.0f;
    D_8039CA10[3][3] = 0.0f;
}

void func_80294B64(f32 arg0[4][4], s32 arg1, s16 *arg2, s16 *arg3, s16 *arg4, UnkStruct_80294B64 *arg5, s32 arg6) {
    if (arg5->unk0 == 0) {
        arg5->unk0 = arg6 + D_803156C4;
    }
    if (D_803156C4 > arg5->unk0 && D_802E8BD0 == 0) {
        arg5->unk4++;
        if (arg5->unk4 > arg1) {
            arg5->unk4 = arg1;
        }
    }
    guRotateF(arg0, -arg5->unk4, 0.0f, 1.0f, 0.0f);
    *arg2 = 0;
    *arg3 = 0;
    *arg4 = 0;
}

void func_80294C50(f32 arg0[4][4], s16 *arg1, s16 *arg2, s16 *arg3, s32 *arg4, s32 arg5) {
    f32 s;

    if (D_802E8BD0 == 0) {
        *arg4 += 1;
    }
    s = sinf(*arg4 / 5.0f);
    *arg1 = 0;
    *arg3 = 0;
    *arg2 = arg5 * s;
    guTranslateF(arg0, 0.0f, *arg2, 0.0f);
}

void func_80294D24(f32 arg0[4][4], s16 *arg1, s16 *arg2, s16 *arg3, s32 *arg4, s32 arg5) {
    f32 mf[4][4];
    f32 x;
    f32 y;
    f32 z;

    if (D_802E8BD0 == 0) {
        *arg4 += arg5;
    }
    guRotateF(mf, *arg4, 0.2f, 0.7f, D_8030CD50);
    guMtxXFMF(mf, 90.0f, 0.0f, 0.0f, &x, &y, &z);
    *arg1 = x;
    *arg2 = y;
    *arg3 = z;
    guTranslateF(arg0, x, y, z);
}

void func_80294E30(void) {
    D_8039CA68[0] = (UnkStruct_8039CA68 *) 0x80055400;
    D_8039CA68[1] = (UnkStruct_8039CA68 *) 0x80065400;
    D_8039CA88 = func_80286038(0xFFFF) - 1;
    D_8039CA7D = 0;
}

void func_80294E88(void) {
    D_8039CA70[1] = 0;
    D_8039CA80 = -1;
    D_8039CA62 = 1;
    D_8039CA8C = 0;
}

void func_80294EB8(void) {
    if (D_8039CA7D != 0) {
        D_8039CA61 = 1;
        D_8039CA84 = -1;
        D_8039CA78 = 0;
        D_8039CA7E = D_8039CA7C;
    }
}

void func_80294F00(void) {
    if (D_80364A90 & 0x104) {
        if (D_8039CA80 == -1) {
            D_8039CA80 = D_803156C0;
        }
        if ((u32) D_8039CA70[1] < 0xCCC) {
            D_8039CA68[1][D_8039CA70[1]].x = D_803643E0;
            D_8039CA68[1][D_8039CA70[1]].y = D_803643E4;
            D_8039CA68[1][D_8039CA70[1]].z = D_803643E8;
            D_8039CA68[1][D_8039CA70[1]].unkC = D_803ED390[0];
            D_8039CA68[1][D_8039CA70[1]].unkE = D_803ED390[1];
            D_8039CA68[1][D_8039CA70[1]].unk10 = D_803ED390[2];
            D_8039CA68[1][D_8039CA70[1]].unk12 = D_803156C0 - D_8039CA80;
            D_8039CA70[1]++;
        } else {
            D_8039CA8C = 1;
            func_8029A7E4(D_8030CD60);
        }
    }
}

void func_80295120(Gfx **arg0, UnkStruct_02000000 *arg1) {
    Gfx *gfx;
    s32 x;
    s32 y;
    s32 z;
    s16 rx;
    s16 ry;
    s16 rz;

    gfx = *arg0;
    if (D_8039CA61 != 0) {
        func_80295394(&x, &y, &z, &rx, &ry, &rz);
        func_802AA6D0(x, y, z, rx, ry, rz, D_802FF0D0[D_8039CA7C], &arg1->unk14C0);
        gSPSegment(gfx++, 6, osVirtualToPhysical(D_803BDB04));
        gSPSegment(gfx++, 7, osVirtualToPhysical(D_803BDB00));
        gSPMatrix(gfx++, &D_02000000.unk14C0, G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
        gDPPipeSync(gfx++);
        gDPSetEnvColor(gfx++, 0, 0, 0, 255);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 100);
        gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
        gSPDisplayList(gfx++, osVirtualToPhysical(D_803BDB08));
        gSPMatrix(gfx++, &D_02000000.unk0[7], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
        gDPPipeSync(gfx++);
    }
    *arg0 = gfx;
}

void func_80295394(s32 *arg0, s32 *arg1, s32 *arg2, s16 *arg3, s16 *arg4, s16 *arg5) {
    u8 found;
    s32 t;
    s32 j;
    s32 span;
    s32 elapsed;
    f32 frac;

    t = D_803156C0 - D_8039CA84;
    if (D_80364A90 == 0x2000) {
        *arg0 = D_8039CA68[0][0].x;
        *arg1 = D_8039CA68[0][0].y;
        *arg2 = D_8039CA68[0][0].z;
        *arg3 = D_8039CA68[0][0].unkC;
        *arg4 = D_8039CA68[0][0].unkE;
        *arg5 = D_8039CA68[0][0].unk10;
        D_8039CA84 = D_803156C0;
        return;
    }
    found = 0;
    while (D_8039CA78 < D_8039CA70[0] - 2 && found == 0) {
        if (t >= D_8039CA68[0][D_8039CA78].unk12 && t < D_8039CA68[0][D_8039CA78 + 1].unk12) {
            found = 1;
        } else {
            D_8039CA78++;
        }
    }
    found = 0;
    j = D_8039CA78 + 1;
    while (j < D_8039CA70[0] - 2 && found == 0) {
        if (t <= D_8039CA68[0][j].unk12) {
            found = 1;
        } else {
            j++;
        }
    }
    span = D_8039CA68[0][j].unk12 - D_8039CA68[0][D_8039CA78].unk12;
    if (j >= D_8039CA70[0] - 2) {
        elapsed = D_8039CA68[0][j].unk12 - D_8039CA68[0][D_8039CA78].unk12;
    } else {
        elapsed = t - D_8039CA68[0][D_8039CA78].unk12;
    }
    frac = (f32) elapsed / (f32) span;
    *arg0 = (D_8039CA68[0][j].x - D_8039CA68[0][D_8039CA78].x) * frac + D_8039CA68[0][D_8039CA78].x;
    *arg1 = (D_8039CA68[0][j].y - D_8039CA68[0][D_8039CA78].y) * frac + D_8039CA68[0][D_8039CA78].y;
    *arg2 = (D_8039CA68[0][j].z - D_8039CA68[0][D_8039CA78].z) * frac + D_8039CA68[0][D_8039CA78].z;
    *arg3 = func_80295924(D_8039CA68[0][D_8039CA78].unkC, D_8039CA68[0][j].unkC, frac);
    *arg4 = func_80295924(D_8039CA68[0][D_8039CA78].unkE, D_8039CA68[0][j].unkE, frac);
    *arg5 = func_80295924(D_8039CA68[0][D_8039CA78].unk10, D_8039CA68[0][j].unk10, frac);
}

s16 func_80295924(s16 arg0, s16 arg1, f32 arg2) {
    s16 d;

    d = arg1 - arg0;
    if (d >= -0x800) {
        if (d > 0x800) {
            d -= 0xFFF;
        }
    } else {
        d += 0xFFF;
    }
    arg2 *= d;
    arg2 += arg0;
    if (arg2 < 0.0) {
        arg2 += D_8030CDC0;
    }
    if (arg2 > D_8030CDC8) {
        arg2 -= D_8030CDD0;
    }
    return arg2;
}

void func_80295A20(u32 arg0) {
    u8 *dst;
    u8 *src;
    s32 i;

    if (arg0 <= D_8039CA88) {
        if (D_8039CA8C == 0) {
            D_8039CA7D = 1;
        } else {
            D_8039CA7D = 0;
        }
        dst = (u8 *) D_8039CA68[0];
        src = (u8 *) D_8039CA68[1];
        for (i = 0; i < 0x10000; i++) {
            dst[i] = src[i];
        }
        D_8039CA7C = D_803643D4;
        D_8039CA70[0] = D_8039CA70[1];
        D_8039CA88 = arg0;
    }
}

void func_80295AE0(Gfx *gfx, Gfx *end) {
    s8 cmd;
    s32 sft;
    u8 found;
    s32 i;
    u32 w1;

    while (gfx != end) {
        switch (cmd = gfx->words.w0 >> 24) {
            case (s8) G_SETCOMBINE:
                gDPSetCombineMode(gfx++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
                break;
            case (s8) G_SETOTHERMODE_L:
                sft = (gfx->words.w0 >> 8) & 0xFFFF;
                if (sft == G_MDSFT_RENDERMODE) {
                    w1 = gfx->words.w1;
                    i = 0;
                    found = 0;
                    do {
                        if (D_802FF11C[i].from == w1) {
                            found = 1;
                        } else {
                            i++;
                        }
                    } while (!found && i < 6);
                    if (!found) {
                        func_8029A7E4(D_8030CD7C, D_8030CDA8, D_8030CDB0, 0x152);
                    }
                    gfx->words.w1 = D_802FF11C[i].to;
                }
                gfx++;
                break;
            default:
                gfx++;
                break;
        }
    }
}

void func_80295C70(u8 arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 j;

    for (i = 0; i < 1; i++) {
        if (D_802FF150[i].unk28 == arg0 &&
            (func_802AC4C4(arg1, arg2, D_802FF150[i].x[0], D_802FF150[i].z[0], D_802FF150[i].x[1],
                           D_802FF150[i].z[1], D_802FF150[i].x[2], D_802FF150[i].z[2]) != 0 ||
             func_802AC4C4(arg1, arg2, D_802FF150[i].x[0], D_802FF150[i].z[0], D_802FF150[i].x[2],
                           D_802FF150[i].z[2], D_802FF150[i].x[3], D_802FF150[i].z[3]) != 0)) {
            j = 0;
            while (D_802FF150[i].list[j] != -1) {
                D_803C30A8[j] = D_802FF150[i].list[j];
                j++;
            }
            D_803C30A8[j] = 0xFFFF;
        }
    }
}
