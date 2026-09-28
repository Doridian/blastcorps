#include "common.h"

typedef struct {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s16 unk4;
} UnkStruct_8036C7A0; /* size = 0x6 */

typedef struct {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ u8 unk4;
    /* 0x8 */ s32 unk8;
} UnkStruct_8036C8D0; /* size = 0xC */

typedef struct {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ u8 unk2;
    /* 0x3 */ u8 unk3;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 unk5;
    /* 0x6 */ u8 unk6;
} UnkStruct_803BE6FC; /* size = 0x8 */

typedef struct {
    /* 0x0000 */ Mtx unk0[8];
    /* 0x0200 */ u8 unk200[0x1C00];
    /* 0x1E00 */ Vtx unk1E00[1];
} UnkStruct_8027690C;

void func_80276D1C(Mtx *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 *arg5, f32 *arg6, f32 *arg7, f32 *arg8);
void func_8027690C(UnkStruct_8027690C *arg0, f32 x, f32 y, f32 z, s16 *outX, s16 *outY, Mtx *arg6, Mtx *arg7,
                   Mtx *arg8, f32 arg9);

s32 func_80277D34(void);
s32 func_80277E08(void);
void func_80277C20(void);
void func_802778FC(void);
void func_80277AE0(void);
void func_80277B84(void);

s32 func_80276130(UnkStruct_8027690C *arg0, u8 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, u8 arg7,
                  u8 arg8, u8 arg9, u8 arg10, u8 arg11, u8 arg12, u8 arg13, u8 arg14, u8 arg15, u8 arg16, u8 arg17,
                  u8 arg18, u8 arg19, u8 arg20, u8 arg21, u8 arg22);

s32 func_8026205C(s32);
void func_80260650(s32, s32, s32);
s32 func_8026A828(s32, s32);
void func_802A1040(s32, s32, s32);
s32 func_8026AD30(s32);
void func_8026AF6C(s32);
s32 func_802BCE40(void);
void func_802BD10C(s32);
Gfx *func_80275DA4(Gfx *arg0, u8 arg1);
s32 func_80276080(UnkStruct_8027690C *arg0, u8 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, u8 arg7,
                  u8 arg8, u8 arg9, u8 arg10);
void func_8027656C(UnkStruct_8027690C *arg0);
s32 func_802768A8(void);
void func_80277EDC();
void func_8029A7E4(char *, ...);

extern UnkStruct_8027690C D_02000000;
extern f64 D_8030C548;
extern f64 D_8030C550;
extern f64 D_8030C558;
extern f64 D_8030C560;
extern u16 D_8035807C;
extern u8 D_802E8BD0;
extern u8 D_802FA940[];
extern u8 D_802FAD50[];
extern Vtx D_802FBD50[];
extern s32 D_802FAD40;
extern s32 D_802FAD44;
extern u8 D_802FAD48;
extern f32 D_8030C540;
extern char D_8030C570[];
extern char D_8030C584[];
extern char D_8030C598[];
extern char D_8030C5AC[];
extern char D_8030C5C0[];
extern char D_8030C5D4[];
extern s32 D_80358070;
extern u8 D_803643D6;
extern u8 D_803643DB;
extern s16 D_8036443E;
extern u8 D_80364456;
extern s32 D_80367738;
extern s32 D_80364AA8;
extern UnkStruct_8036C7A0 *D_8036C790;
extern UnkStruct_8036C7A0 *D_8036C794;
extern UnkStruct_8036C7A0 *D_8036C7A0[10];
extern s32 D_8036C798;
extern s32 D_8036C7C8;
extern u8 D_8036EB98;
extern u8 D_803F7808;
extern u8 D_803F7809;
extern u8 D_8036C7CC;
extern Vtx D_8036C7D0[][4];
extern Mtx D_8036C850[];
extern UnkStruct_8036C8D0 D_8036C8D0[50];
extern u8 D_8036CB28;
extern u8 D_8036CB29;
extern s16 D_8036CB2A;
extern s16 D_8036CB2C;
extern u8 D_8036CB2E;
extern u8 D_8036CB2F;
extern u8 D_8036CB30;
extern u8 D_8036CB31;
extern u8 D_8036CB32;
extern u8 D_8036CB33;
extern u8 D_8036CB34;
extern u8 D_8036CB35;
extern u8 D_8036CB36;
extern u8 D_8036CB37;
extern u8 D_8036CB38;
extern u8 D_8036CB39;
extern u8 D_8036CB3A;
extern u8 D_8036CB3B;
extern u8 D_8036CB3C;
extern s16 *D_8036CB40;
extern s32 D_8036CB48[2];
extern u8 D_8036CB50;
extern u8 D_8036CB51;
extern UnkStruct_803BE6FC *D_803BE6FC;
extern UnkStruct_803BE6FC *D_803BE700;
extern s32 D_803EF6E4;

void func_80275430(void) {
    s32 i;

    for (i = 0; i < 10; i++) {
        D_8036C7A0[i] = 0;
    }
    D_8036C794 = 0;
    D_8036C7CC = 0;
}

void func_80275478(UnkStruct_8027690C *arg0, Gfx **arg1, u8 arg2) {
    s16 i;
    s16 j;
    s16 vtxIdx;
    Gfx *gfx;
    s16 sx;
    s16 sy;
    s16 px;
    s16 py;
    s16 minX;
    s16 maxX;
    s16 minY;
    s16 maxY;
    u8 r;
    u8 g;
    s16 t;
    UnkStruct_8036C7A0 *p;
    s32 sp50;

    vtxIdx = 16;
    gfx = *arg1;
    minX = 0x7FFF, maxX = -0x8000, minY = 0x7FFF, maxY = -0x8000;
    sp50 = func_802BCE40();
    D_8036C7CC = 0;
    p = D_8036C790;
    if (D_8036EB98 == 0 && sp50 == 0 && D_80364AA8 == 1 && D_802E8BD0 == 0) {
        if (func_8026AD30(0x4B) == 0) {
            func_8026AF6C(0x803D);
            func_80277EDC(3, 1, 2, 0x82);
        }
        D_8036EB98 = 1;
    }
    if (D_8036C790 != NULL && (func_802768A8() == 0 || arg2 != 0) && D_8036C794 == NULL) {
        for (i = 0; i < 4; i++) {
            func_8027690C(arg0, D_8036C790->unk0, D_8036C790->unk2, D_8036C790->unk4, &sx, &sy, NULL, NULL, NULL, 1.0f);
            D_8036C790++;
            if (sx < minX) {
                minX = sx;
            }
            if (sx > maxX) {
                maxX = sx;
            }
            if (sy < minY) {
                minY = sy;
            }
            if (sy > maxY) {
                maxY = sy;
            }
        }
        D_8036C7CC = 0;
        for (j = 0; j < 4; j++) {
            switch (j) {
                case 0:
                    px = (maxX - minX) / 2 + minX;
                    py = minY;
                    break;
                case 1:
                    px = (maxX - minX) / 2 + minX;
                    py = maxY;
                    break;
                case 2:
                    px = minX;
                    py = (maxY - minY) / 2 + minY;
                    break;
                case 3:
                    px = maxX;
                    py = (maxY - minY) / 2 + minY;
                    break;
            }
            if (px < 310 && px >= 11 && py < 230 && py >= 11) {
                D_8036C794 = p;
                D_8036C798 = sp50;
                D_803F7809 = D_803F7808;
                D_802FAD44 = 0;
            }
        }
    }
    if (D_8036C794 != NULL) {
        func_802BD10C(D_8036C798);
        if (D_8036C7C8 > 1500 || D_803643DB == 0) {
            g = 255;
            r = 0;
        } else if (D_8036C7C8 < 500) {
            r = 255;
            g = 0;
        } else {
            t = (D_8036C7C8 - 500) / 1000.0f * D_8030C540;
            if (t < 256) {
                g = t, r = 255;
            } else {
                g = 255, r = 510 - t;
            }
        }
        p = D_8036C794;
        for (i = 0; i < 4; i++) {
            func_8027690C(arg0, p->unk0, p->unk2, p->unk4, &sx, &sy, NULL, NULL, NULL, 1.0f);
            p++;
            if (sx < minX) {
                minX = sx;
            }
            if (sx > maxX) {
                maxX = sx;
            }
            if (sy < minY) {
                minY = sy;
            }
            if (sy > maxY) {
                maxY = sy;
            }
        }
        for (j = 0; j < 4; j++) {
            switch (j) {
                case 0:
                    px = (maxX - minX) / 2 + minX, py = minY - D_802FAD40;
                    break;
                case 1:
                    px = (maxX - minX) / 2 + minX, py = maxY + D_802FAD40;
                    break;
                case 2:
                    px = minX - D_802FAD40;
                    py = (maxY - minY) / 2 + minY;
                    break;
                case 3:
                    px = maxX + D_802FAD40;
                    py = (maxY - minY) / 2 + minY;
                    break;
            }
            if (px < 310 && px >= 11 && py < 230 && py >= 11) {
                D_8036C7CC++;
            }
            vtxIdx = func_80276080(arg0, j, vtxIdx, px, py, 8, 8, r, g, 0, 255);
        }
        if (D_802FAD48 == 0) {
            if (++D_802FAD40 == 10) {
                D_802FAD48 = 1;
                D_802FAD44++;
            }
        } else {
            if (--D_802FAD40 == 0) {
                D_802FAD48 = 0;
                D_802FAD44++;
            }
        }
        if (D_802FAD44 == 5) {
            D_8036C794 = NULL;
        }
        gfx = func_80275DA4(gfx, 0);
        gSPVertex(gfx++, &D_02000000.unk1E00[16], 16, 0);
        vtxIdx = 0;
        for (j = 0; j < 4; j++) {
            gSP1Triangle(gfx++, vtxIdx, vtxIdx + 1, vtxIdx + 2, 0);
            gSP1Triangle(gfx++, vtxIdx, vtxIdx + 2, vtxIdx + 3, 0);
            vtxIdx += 4;
        }
    }
    func_8027656C(arg0);
    *arg1 = gfx;
}

Gfx *func_80275DA4(Gfx *arg0, u8 arg1) {
    Gfx *gfx = arg0;

    if (!arg1) {
        gSPMatrix(gfx++, &D_02000000.unk0[3], G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
        gSPMatrix(gfx++, &D_02000000.unk0[7], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    }
    gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
    gSPSetGeometryMode(gfx++, G_SHADE | G_SHADING_SMOOTH);
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(gfx++, G_CC_MODULATERGBA, G_CC_MODULATERGBA);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPLoadTextureBlock(gfx++, OS_K0_TO_PHYSICAL(D_802FA940), G_IM_FMT_IA, G_IM_SIZ_8b, 32, 32, 0, G_TX_CLAMP,
                        G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    return gfx;
}

s32 func_80276080(UnkStruct_8027690C *arg0, u8 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, u8 arg7,
                  u8 arg8, u8 arg9, u8 arg10) {
    return func_80276130(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg7, arg8, arg9, arg10, arg7,
                  arg8, arg9, arg10, arg7, arg8, arg9, arg10);
}

s32 func_80276130(UnkStruct_8027690C *arg0, u8 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, u8 arg7,
                  u8 arg8, u8 arg9, u8 arg10, u8 arg11, u8 arg12, u8 arg13, u8 arg14, u8 arg15, u8 arg16, u8 arg17,
                  u8 arg18, u8 arg19, u8 arg20, u8 arg21, u8 arg22) {
    s32 sp4;

    switch (arg1) {
        case 0:
            arg0->unk1E00[arg2].v.tc[0] = 0, arg0->unk1E00[arg2].v.tc[1] = 0;
            arg0->unk1E00[arg2 + 1].v.tc[0] = 0x3E0, arg0->unk1E00[arg2 + 1].v.tc[1] = 0;
            arg0->unk1E00[arg2 + 2].v.tc[0] = 0x3E0, arg0->unk1E00[arg2 + 2].v.tc[1] = 0x3E0;
            arg0->unk1E00[arg2 + 3].v.tc[0] = 0, arg0->unk1E00[arg2 + 3].v.tc[1] = 0x3E0;
            break;
        case 1:
            arg0->unk1E00[arg2].v.tc[0] = 0, arg0->unk1E00[arg2].v.tc[1] = 0x3E0;
            arg0->unk1E00[arg2 + 1].v.tc[0] = 0x3E0, arg0->unk1E00[arg2 + 1].v.tc[1] = 0x3E0;
            arg0->unk1E00[arg2 + 2].v.tc[0] = 0x3E0, arg0->unk1E00[arg2 + 2].v.tc[1] = 0;
            arg0->unk1E00[arg2 + 3].v.tc[0] = 0, arg0->unk1E00[arg2 + 3].v.tc[1] = 0;
            break;
        case 2:
            arg0->unk1E00[arg2].v.tc[0] = 0, arg0->unk1E00[arg2].v.tc[1] = 0;
            arg0->unk1E00[arg2 + 1].v.tc[0] = 0, arg0->unk1E00[arg2 + 1].v.tc[1] = 0x3E0;
            arg0->unk1E00[arg2 + 2].v.tc[0] = 0x3E0, arg0->unk1E00[arg2 + 2].v.tc[1] = 0x3E0;
            arg0->unk1E00[arg2 + 3].v.tc[0] = 0x3E0, arg0->unk1E00[arg2 + 3].v.tc[1] = 0;
            break;
        case 3:
            arg0->unk1E00[arg2].v.tc[0] = 0, arg0->unk1E00[arg2].v.tc[1] = 0x3E0;
            arg0->unk1E00[arg2 + 1].v.tc[0] = 0, arg0->unk1E00[arg2 + 1].v.tc[1] = 0;
            arg0->unk1E00[arg2 + 2].v.tc[0] = 0x3E0, arg0->unk1E00[arg2 + 2].v.tc[1] = 0;
            arg0->unk1E00[arg2 + 3].v.tc[0] = 0x3E0, arg0->unk1E00[arg2 + 3].v.tc[1] = 0x3E0;
            break;
    }
    arg0->unk1E00[arg2].v.ob[0] = arg3 - arg5;
    arg0->unk1E00[arg2].v.ob[1] = arg4 - arg6;
    arg0->unk1E00[arg2].v.ob[2] = -10;
    arg0->unk1E00[arg2].v.flag = 0;
    arg0->unk1E00[arg2].v.cn[0] = arg7;
    arg0->unk1E00[arg2].v.cn[1] = arg8;
    arg0->unk1E00[arg2].v.cn[2] = arg9;
    arg0->unk1E00[arg2].v.cn[3] = arg10;
    arg2++;
    arg0->unk1E00[arg2].v.ob[0] = arg3 + arg5;
    arg0->unk1E00[arg2].v.ob[1] = arg4 - arg6;
    arg0->unk1E00[arg2].v.ob[2] = -10;
    arg0->unk1E00[arg2].v.flag = 0;
    arg0->unk1E00[arg2].v.cn[0] = arg11;
    arg0->unk1E00[arg2].v.cn[1] = arg12;
    arg0->unk1E00[arg2].v.cn[2] = arg13;
    arg0->unk1E00[arg2].v.cn[3] = arg14;
    arg2++;
    arg0->unk1E00[arg2].v.ob[0] = arg3 + arg5;
    arg0->unk1E00[arg2].v.ob[1] = arg4 + arg6;
    arg0->unk1E00[arg2].v.ob[2] = -10;
    arg0->unk1E00[arg2].v.flag = 0;
    arg0->unk1E00[arg2].v.cn[0] = arg15;
    arg0->unk1E00[arg2].v.cn[1] = arg16;
    arg0->unk1E00[arg2].v.cn[2] = arg17;
    arg0->unk1E00[arg2].v.cn[3] = arg18;
    arg2++;
    arg0->unk1E00[arg2].v.ob[0] = arg3 - arg5;
    arg0->unk1E00[arg2].v.ob[1] = arg4 + arg6;
    arg0->unk1E00[arg2].v.ob[2] = -10;
    arg0->unk1E00[arg2].v.flag = 0;
    arg0->unk1E00[arg2].v.cn[0] = arg19;
    arg0->unk1E00[arg2].v.cn[1] = arg20;
    arg0->unk1E00[arg2].v.cn[2] = arg21;
    arg0->unk1E00[arg2].v.cn[3] = arg22;
    arg2++;
    return arg2;
}

void func_8027656C(UnkStruct_8027690C *arg0) {
    s32 i;
    s32 j;
    UnkStruct_8036C7A0 *p;
    s16 sx;
    s16 sy;
    s16 px;
    s16 py;
    s16 minX;
    s16 maxX;
    s16 minY;
    s16 maxY;
    u8 visible;

    for (i = 0; i < 10; i++) {
        if (D_8036C7A0[i] != NULL) {
            minX = 0x7FFF, maxX = -0x8000;
            minY = 0x7FFF, maxY = -0x8000;
            p = D_8036C7A0[i];
            for (j = 0; j < 4; j++) {
                func_8027690C(arg0, p->unk0, p->unk2, p->unk4, &sx, &sy, NULL, NULL, NULL, 1.0f);
                p++;
                if (sx < minX) {
                    minX = sx;
                }
                if (sx > maxX) {
                    maxX = sx;
                }
                if (sy < minY) {
                    minY = sy;
                }
                if (sy > maxY) {
                    maxY = sy;
                }
            }
            j = 0;
            visible = FALSE;
            while (j < 4 && !visible) {
                switch (j) {
                    case 0:
                        px = (maxX - minX) / 2 + minX;
                        py = minY;
                        break;
                    case 1:
                        px = (maxX - minX) / 2 + minX;
                        py = maxY;
                        break;
                    case 2:
                        px = minX;
                        py = (maxY - minY) / 2 + minY;
                        break;
                    case 3:
                        px = maxX;
                        py = (maxY - minY) / 2 + minY;
                        break;
                }
                if (px < 310 && px >= 11 && py < 230 && py >= 11) {
                    visible = TRUE;
                }
                j++;
            }
            if (!visible) {
                D_8036C7A0[i] = NULL;
            }
        }
    }
}

void func_8027684C(void) {
    s32 i;

    i = 0;
    while (i < 10) {
        if (D_8036C7A0[i] == NULL) {
            D_8036C7A0[i] = D_8036C794;
            return;
        }
        i++;
    }
}

s32 func_802768A8(void) {
    s32 i;

    i = 0;
    while (i < 10) {
        if (D_8036C7A0[i] != NULL && D_8036C7A0[i] == D_8036C790) {
            return 1;
        }
        i++;
    }
    return 0;
}

void func_8027690C(UnkStruct_8027690C *arg0, f32 x, f32 y, f32 z, s16 *outX, s16 *outY, Mtx *arg6, Mtx *arg7,
                   Mtx *arg8, f32 arg9) {
    f32 w;

    w = 1.0f;
    if (arg8 != NULL) {
        func_80276D1C(arg8, x, y, z, w, &x, &y, &z, &w);
    }
    if (arg7 != NULL) {
        func_80276D1C(arg7, x, y, z, w, &x, &y, &z, &w);
    }
    if (arg6 != NULL) {
        func_80276D1C(arg6, x, y, z, w, &x, &y, &z, &w);
    }
    func_80276D1C(&arg0->unk0[5], x, y, z, w, &x, &y, &z, &w);
    if (z >= 0.0) {
        *outX = 0x4000;
        *outY = 0x4000;
        return;
    }
    func_80276D1C(&arg0->unk0[2], x, y, z, w, &x, &y, &z, &w);
    x = x * ((u32)D_8035807C / D_8030C548);
    y = y * ((u32)D_8035807C / D_8030C548);
    w = w * ((u32)D_8035807C / D_8030C548);
    x = x / w;
    y = y / w;
    x = ((320.0f * arg9) / 2.0f) * x;
    y = ((240.0f * arg9) / 2.0f) * y;
    x = ((320.0f * arg9) / 2.0f) + x;
    y = ((240.0f * arg9) / 2.0f) + y;
    y = (240.0f * arg9) - y;
    if (((x > 0.0f) ? x : -x) >= 16384.0f) {
        x = ((x >= 0.0f) ? 1 : -1) << 14;
    }
    if (((y > 0.0f) ? y : -y) >= 16384.0f) {
        y = ((y >= 0.0f) ? 1 : -1) << 14;
    }
    *outX = x;
    *outY = y;
}

void func_80276D1C(Mtx *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 *arg5, f32 *arg6, f32 *arg7, f32 *arg8) {
    f32 mf[4][4];

    guMtxL2F(mf, arg0);
    *arg5 = mf[0][0] * arg1 + mf[1][0] * arg2 + mf[2][0] * arg3 + mf[3][0];
    *arg6 = mf[0][1] * arg1 + mf[1][1] * arg2 + mf[2][1] * arg3 + mf[3][1];
    *arg7 = mf[0][2] * arg1 + mf[1][2] * arg2 + mf[2][2] * arg3 + mf[3][2];
    *arg8 = mf[0][3] * arg1 + mf[1][3] * arg2 + mf[2][3] * arg3 + mf[3][3];
}

void func_80276E50(Gfx **arg0, UnkStruct_8027690C *arg1, u8 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s16 sx;
    s16 sy;
    Gfx *gfx;
    f32 mf1[4][4];
    f32 mf2[4][4];

    gfx = *arg0;
    func_8027690C(arg1, arg3 >> 5, arg4 >> 5, arg5 >> 5, &sx, &sy, NULL, NULL, NULL, 1.0f);
    if (sx < 30 || sx >= 291 || sy < 25 || sy >= 216) {
        if (sx < 30) {
            sx = 30;
        }
        if (sy < 25) {
            sy = 25;
        }
        if (sx >= 291) {
            sx = 290;
        }
        if (sy >= 216) {
            sy = 215;
        }
        D_8036C7D0[arg2][0].v.ob[0] = -15;
        D_8036C7D0[arg2][0].v.ob[1] = -15;
        D_8036C7D0[arg2][0].v.ob[2] = -10;
        D_8036C7D0[arg2][0].v.tc[0] = 0;
        D_8036C7D0[arg2][0].v.tc[1] = 0;
        D_8036C7D0[arg2][1].v.ob[0] = 15;
        D_8036C7D0[arg2][1].v.ob[1] = -15;
        D_8036C7D0[arg2][1].v.ob[2] = -10;
        D_8036C7D0[arg2][1].v.tc[0] = 0x3E0;
        D_8036C7D0[arg2][1].v.tc[1] = 0;
        D_8036C7D0[arg2][2].v.ob[0] = 15;
        D_8036C7D0[arg2][2].v.ob[1] = 15;
        D_8036C7D0[arg2][2].v.ob[2] = -10;
        D_8036C7D0[arg2][2].v.tc[0] = 0x3E0;
        D_8036C7D0[arg2][2].v.tc[1] = 0x3E0;
        D_8036C7D0[arg2][3].v.ob[0] = -15;
        D_8036C7D0[arg2][3].v.ob[1] = 15;
        D_8036C7D0[arg2][3].v.ob[2] = -10;
        D_8036C7D0[arg2][3].v.tc[0] = 0;
        D_8036C7D0[arg2][3].v.tc[1] = 0x3E0;
        guTranslateF(mf1, sx, sy, 0.0f);
        guRotateF(mf2, D_8030C560 - D_8036443E / D_8030C550 * D_8030C558, 0.0f, 0.0f, 1.0f);
        guMtxCatF(mf2, mf1, mf1);
        guMtxF2L(mf1, &D_8036C850[arg2]);
        gSPMatrix(gfx++, &D_02000000.unk0[3], G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
        gSPMatrix(gfx++, &D_8036C850[arg2], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
        gSPSetGeometryMode(gfx++, G_SHADE | G_SHADING_SMOOTH);
        gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
        gDPSetCombineMode(gfx++, G_CC_MODULATERGBA_PRIM, G_CC_MODULATERGBA_PRIM);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
        gDPLoadTextureBlock(gfx++, OS_K0_TO_PHYSICAL(D_802FA940), G_IM_FMT_IA, G_IM_SIZ_8b, 32, 32, 0, G_TX_CLAMP,
                            G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPVertex(gfx++, OS_K0_TO_PHYSICAL(D_8036C7D0[arg2]), 4, 0);
        gSP1Triangle(gfx++, 0, 1, 2, 0);
        gSP1Triangle(gfx++, 0, 2, 3, 0);
        gDPPipeSync(gfx++);
    }
    *arg0 = gfx;
}

void func_802775C0(void) {
    D_8036CB34 = 0;
    D_8036CB48[0] = D_80358070;
    D_80358070 += 0xC80;
    D_8036CB48[1] = D_80358070;
    D_80358070 += 0xC80;
    D_8036CB28 = 0;
    D_8036CB29 = 0;
}

void func_80277620(s32 arg0) {
    u8 found;
    UnkStruct_803BE6FC *p;
    s16 z;

    found = FALSE;
    p = D_803BE6FC;
    while (!found && D_8036CB28 != D_8036CB29) {
        if (arg0 - D_8036C8D0[D_8036CB28].unk8 > 1000) {
            if (++D_8036CB28 == 50) {
                D_8036CB28 = 0;
            }
        } else {
            found = TRUE;
        }
    }
    if (D_8036CB2F != 0 && D_8036CB29 + 1 != D_8036CB28 && (D_8036CB29 != 49 || D_8036CB28 != 0)) {
        D_8036C8D0[D_8036CB29].unk0 = func_80277D34();
        D_8036C8D0[D_8036CB29].unk2 = func_80277E08();
        D_8036C8D0[D_8036CB29].unk4 = D_8036CB2E;
        D_8036C8D0[D_8036CB29].unk8 = arg0;
        if (++D_8036CB29 == 50) {
            D_8036CB29 = 0;
        }
    }
    if (D_8036CB2F != 0) {
        func_80277C20();
        func_802778FC();
        func_80277AE0();
        func_80277B84();
    }
    if (arg0 == 50 && D_803643D6 == 0) {
        func_80277EDC(2, 1, 2, func_8026205C(1));
    }
    if (D_803643DB != 0) {
        z = D_803EF6E4 >> 5;
        while (p < D_803BE700) {
            if (p->unk6 == 0 && z > p->unk0) {
                func_80277EDC(p->unk2, p->unk3, p->unk4, p->unk5);
                p->unk6 = 1;
            }
            p++;
        }
    }
    D_8036CB2F = 0;
}

void func_802778FC(void) {
    switch (D_80364456) {
        case 5:
            if (D_8036CB31 >= 16 && D_8036CB30 >= 16) {
                func_80277EDC(3, 1, 1, 0x63);
                D_8036CB28 = 0;
                D_8036CB29 = 0;
                func_8029A7E4(D_8030C570);
            }
            break;
        case 4:
            if (D_8036CB31 >= 41 && D_8036CB30 >= 41) {
                func_80277EDC(4, 1, 1, func_8026205C(4));
                D_8036CB28 = 0;
                D_8036CB29 = 0;
                func_8029A7E4(D_8030C584);
            }
            break;
        case 3:
            if (D_8036CB31 >= 11 && D_8036CB30 >= 11) {
                func_80277EDC(0, 1, 3, 0xB2);
                D_8036CB28 = 0;
                D_8036CB29 = 0;
                func_8029A7E4(D_8030C598);
            }
            break;
        case 9:
            if (D_8036CB31 >= 26 && D_8036CB30 >= 26) {
                func_80277EDC(4, 1, 1, func_8026205C(4));
                D_8036CB28 = 0;
                D_8036CB29 = 0;
                func_8029A7E4(D_8030C5AC);
            }
            break;
    }
}

void func_80277AE0(void) {
    switch (D_80364456) {
        case 3:
        case 4:
        case 5:
        case 9:
            if (D_8036CB31 >= 6 && D_8036CB30 < 2) {
                func_80277EDC(1, 1, 3, 0xB3);
                D_8036CB28 = 0;
                D_8036CB29 = 0;
                func_8029A7E4(D_8030C5C0);
            }
            break;
    }
}

void func_80277B84(void) {
    switch (D_80364456) {
        case 3:
        case 4:
        case 5:
            if (D_8036CB33 >= 31 && D_8036CB30 < 6) {
                func_80277EDC(2, 1, 2, 0x58);
                D_8036CB28 = 0;
                D_8036CB29 = 0;
                func_8029A7E4(D_8030C5D4);
            }
            break;
    }
}

void func_80277C20(void) {
    u8 i;

    i = D_8036CB28;
    D_8036CB30 = 0;
    D_8036CB31 = 0;
    D_8036CB32 = 0;
    D_8036CB33 = 0;
    while (i != D_8036CB29) {
        if (D_8036C8D0[i].unk2 == 0) {
            D_8036CB30++;
        } else {
            D_8036CB32++;
        }
        if (D_8036C8D0[i].unk0 == 0) {
            D_8036CB31++;
        } else {
            D_8036CB33++;
        }
        i++;
        if (i == 50) {
            i = 0;
        }
    }
}

s32 func_80277D34(void) {
    switch (D_8036CB2E) {
        case 5:
            if (D_8036CB2A > 400) {
                return 0;
            }
            return 1;
        case 4:
            if (D_8036CB2A > 400) {
                return 0;
            }
            return 1;
        case 9:
            if (D_8036CB2A > 99) {
                return 0;
            }
            return 1;
        case 3:
            if (D_8036CB2A > 99) {
                return 0;
            }
            return 1;
    }
    return 1;
}

s32 func_80277E08(void) {
    switch (D_8036CB2E) {
        case 5:
            if (D_8036CB2C > 80) {
                return 0;
            }
            return 1;
        case 4:
            if (D_8036CB2C > 80) {
                return 0;
            }
            return 1;
        case 9:
            if (D_8036CB2C > 99) {
                return 0;
            }
            return 1;
        case 3:
            if (D_8036CB2C > 99) {
                return 0;
            }
            return 1;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/30C70/func_80277EDC.s")

void func_80278318(void) {
    D_8036CB34 = 0;
}

void func_80278324(Gfx **arg0, s32 arg1, u8 arg2) {
    Gfx *gfx;

    gfx = *arg0;
    if (D_8036CB34 != 0) {
        func_802A1040(D_8036CB40[D_8036CB39], D_8036CB48[arg2], 0);
        switch (D_8036CB38) {
            case 1:
                if (D_8036CB37 == 0) {
                    D_8036CB3A++;
                    if (D_8036CB3A == D_8036CB3B) {
                        D_8036CB3A = 0;
                        D_8036CB39++;
                        if (D_8036CB39 + 1 == D_8036CB3C) {
                            D_8036CB37 = 1;
                            D_8036CB36++;
                        }
                    }
                } else {
                    D_8036CB3A++;
                    if (D_8036CB3A == D_8036CB3B) {
                        D_8036CB3A = 0;
                        D_8036CB39--;
                        if (D_8036CB39 == 0) {
                            D_8036CB37 = 0;
                            D_8036CB36++;
                        }
                    }
                }
                break;
            case 0:
                D_8036CB3A++;
                if (D_8036CB3A == D_8036CB3B) {
                    D_8036CB3A = 0;
                    D_8036CB39++;
                    if (D_8036CB39 == D_8036CB3C) {
                        D_8036CB39 = 0;
                        D_8036CB36++;
                    }
                }
                break;
        }
        if (D_8036CB36 == D_8036CB35) {
            D_8036CB34 = 0;
        }
        if (D_8036CB36 == 0 && D_8036CB39 < 5) {
            if (D_8036CB39 == 0) {
                func_80260650(D_80367738, 0x69, 0);
            }
            D_8036CB51 = 80;
        } else if (D_8036CB50 != 0) {
            D_8036CB51 -= 15;
            D_8036CB50--;
        } else if (func_8026A828(0, 20) == 0) {
            D_8036CB50 = 5;
            D_8036CB51 = 80;
            func_80260650(D_80367738, 0x69, 0);
        } else {
            D_8036CB51 = 0;
        }
        gSPMatrix(gfx++, &D_02000000.unk0[3], G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
        gSPMatrix(gfx++, &D_02000000.unk0[7], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_2CYCLE);
        gDPSetRenderMode(gfx++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
        gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
        gSPSetGeometryMode(gfx++, G_SHADE | G_SHADING_SMOOTH);
        gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
        gDPSetCombineLERP(gfx++, NOISE, 0, PRIMITIVE_ALPHA, 0, 0, 0, 0, SHADE, TEXEL1, 0, SHADE, COMBINED, 0, 0, 0,
                          SHADE);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, D_8036CB51);
        gDPLoadTextureBlock(gfx++, OS_K0_TO_PHYSICAL(D_8036CB48[arg2]), G_IM_FMT_RGBA, G_IM_SIZ_16b, 40, 40, 0,
                            G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        gSPVertex(gfx++, OS_K0_TO_PHYSICAL(D_802FBD50), 8, 0);
        gSP1Triangle(gfx++, 0, 1, 2, 0);
        gSP1Triangle(gfx++, 0, 2, 3, 0);
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineMode(gfx++, G_CC_MODULATERGBA, G_CC_MODULATERGBA);
        gDPLoadTextureBlock(gfx++, OS_K0_TO_PHYSICAL(D_802FAD50), G_IM_FMT_RGBA, G_IM_SIZ_32b, 32, 32, 0,
                            G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        gSP1Triangle(gfx++, 4, 5, 6, 0);
        gSP1Triangle(gfx++, 4, 6, 7, 0);
        gDPPipeSync(gfx++);
    }
    *arg0 = gfx;
}
