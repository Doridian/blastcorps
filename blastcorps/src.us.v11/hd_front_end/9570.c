#include "common.h"

/* A node of the front end's object tree, 0x3C bytes. */
typedef struct UnkStruct_8020BD30 {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ struct UnkStruct_8020BD30 *unk10;
    /* 0x14 */ struct UnkStruct_8020BD30 *unk14;
    /* 0x18 */ u8 unk18;
    /* 0x19 */ u8 unk19;
    /* 0x1A */ u8 unk1A;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
} UnkStruct_8020BD30; /* size = 0x3C */

typedef struct {
    /* 0x00 */ u8 unk0[0x10];
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u8 unk14[4];
    /* 0x18 */ u8 unk18[0x3C];
    /* 0x54 */ u8 unk54[0x3C];
    /* 0x90 */ u8 unk90;
    /* 0x91 */ u8 unk91;
    /* 0x92 */ u8 unk92[0x6E];
} UnkStruct_80364AF0; /* size = 0x100 */

typedef struct {
    /* 0x00 */ u8 unk0[0x18];
    /* 0x18 */ s8 unk18[4];
    /* 0x1C */ s8 unk1C[8];
    /* 0x24 */ u8 unk24[0xC];
} UnkStruct_8020D810; /* size = 0x30 */

typedef struct {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ Gfx *unk4;
} UnkStruct_80218270; /* size = 0x8 */

/* gDPSetPrimColor with the colour word ORed as b | (r | g) | a. */
#define gDPSetPrimColorB(pkt, m, l, r, g, b, a)                                                         \
    {                                                                                                  \
        Gfx *_g = (Gfx *)(pkt);                                                                        \
                                                                                                       \
        _g->words.w0 = (_SHIFTL(G_SETPRIMCOLOR, 24, 8) | _SHIFTL(m, 8, 8) | _SHIFTL(l, 0, 8));         \
        _g->words.w1 = (_SHIFTL(b, 8, 8) | (_SHIFTL(r, 24, 8) | _SHIFTL(g, 16, 8)) | _SHIFTL(a, 0, 8)); \
    }

f32 sqrtf(f32);
s32 func_801FE760(s32);
s32 func_80264BA4(s32);
void func_801FD484(f32 *, f32 *, f32 *, f32 *, f32 *, f32);
void func_802595E0(void *, s32, s32, void *);
void func_801F374C(UnkStruct_8020BD30 *);
void func_801F4878(Gfx *, u8 *);
void func_801F4C3C(UnkStruct_8020BD30 *, f32);
s32 func_801F36B0(s32 *, s32 *);

extern UnkStruct_8020BD30 D_8020BD30[];
extern UnkStruct_8020BD30 D_8020BE98; /* D_8020BD30[6] */
extern f32 D_8020BDE4;
extern f32 D_8020BDEC;
extern f64 D_8020F090; /* 360.0 */
extern f64 D_8020F098; /* 1800.0 */
extern f32 D_80217A10[][4][4];
extern s32 D_80217B50;
extern f32 D_80217B54;
extern f32 D_80217B58;
extern f32 D_80217B5C;
extern f32 D_80217B60;
extern f32 D_80217B64;
extern f32 D_80217B68;
extern s32 D_80217B6C;
extern Mtx D_80217B70[][4];
extern UnkStruct_80218270 D_80218270[];
extern s16 D_802182A8;
extern u8 D_8035805C;
extern u16 D_8035807C;
extern f32 D_8021A918;
extern f32 D_8021A91C;
extern f32 D_8021A920;
extern u8 D_80364AE8;
extern UnkStruct_80364AF0 D_80364AF0[];
extern UnkStruct_8020D810 D_8020D810[];

Gfx *func_801F3964(Gfx *, u8 *, UnkStruct_8020BD30 *, f32);
Gfx *func_801F4110(Gfx *, u8 *, UnkStruct_8020BD30 *, f32);
Gfx *func_801FE238(Gfx *, u8 *);
void func_801FCE74(Vtx *, s32, f32, f32, s32, s32, f32, s32);

extern u8 *D_80358070;
extern Gfx D_8020BC88[];
extern u8 D_802E8F38[][8];
extern u8 D_803156F8[];
extern u16 D_80217288;
extern u16 *D_8021728C;
extern Vtx D_02000000[];

s32 func_8026A828(s32, s32);
void func_801FDCA4(Vtx *, s32, s32);
void func_8027690C(u8 *arg0, f32 x, f32 y, f32 z, s16 *outX, s16 *outY, Mtx *arg6, Mtx *arg7, Mtx *arg8, f32 arg9);

extern Vtx D_80217690[][2][4];
extern f64 D_8020F0A0; /* 10000.0 */
extern f64 D_8020F0A8; /* 10000.0 */
extern u8 *D_80215A7C;
extern u8 *D_80215A80;
extern u8 *D_80215A84;
extern u8 D_0066C900[];
extern u8 D_0068B550[];
extern u16 *D_80215A70[];
extern Vtx D_80215A88[];
extern s32 D_80217290[];
extern s32 D_80217390[];
extern s32 D_80217490[];
extern s32 D_80217590[];

void func_8028B4C4(u32 arg0, u8 *arg1, u32 *arg2, u8 arg3, u8 arg4, u8 arg5);
void func_801F0570(void);

/* This function's sqrtf is the intrinsic (sqrt.s); the rest of the file calls the libm one. */
#pragma intrinsic(sqrtf)
void func_801F0570(void) {
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    s32 sp4;
    s32 sp0;

    sp1C = 250.0f;
    sp18 = sp1C * 2.0 / 7.0;
    for (sp28 = 0; sp28 < 8; sp28++) {
        for (sp2C = 0; sp2C < 8; sp2C++) {
            D_80217290[sp2C + sp28 * 8] = sp2C * sp18 - sp1C;
            D_80217390[sp2C + sp28 * 8] = sp28 * sp18 - sp1C;
            D_80217490[sp2C + sp28 * 8] = (sp2C << 5) << 5;
            D_80217590[sp2C + sp28 * 8] = (sp28 << 5) << 5;
        }
    }
    for (sp24 = 0; sp24 < 0x40; sp24++) {
        sp10 = D_80217290[sp24];
        spC = D_80217390[sp24];
        sp8 = 250.0f;
        sp14 = sqrtf(sp10 * sp10 + spC * spC + sp8 * sp8);
        D_80215A88[sp24].n.ob[0] = sp10 / sp14 * 250.0;
        D_80215A88[sp24].n.ob[1] = spC / sp14 * 250.0;
        D_80215A88[sp24].n.ob[2] = sp8 / sp14 * 250.0;
        D_80215A88[sp24].n.tc[0] = D_80217490[sp24];
        D_80215A88[sp24].n.tc[1] = D_80217590[sp24];
        D_80215A88[sp24].n.n[0] = sp10 / sp14 * 127.0f;
        D_80215A88[sp24].n.n[1] = spC / sp14 * 127.0f;
        D_80215A88[sp24].n.n[2] = sp8 / sp14 * 127.0f;
        D_80215A88[sp24].n.a = 0xFF;
    }
    sp20 = 0x40;
    for (sp24 = 0; sp24 < 0x40; sp24++) {
        sp10 = D_80217290[sp24];
        spC = D_80217390[sp24];
        sp8 = 250.0f;
        sp14 = sqrtf(sp10 * sp10 + spC * spC + sp8 * sp8);
        D_80215A88[sp20 + sp24].n.ob[0] = sp10 / sp14 * 250.0;
        D_80215A88[sp20 + sp24].n.ob[1] = spC / sp14 * 250.0;
        D_80215A88[sp20 + sp24].n.ob[2] = -sp8 / sp14 * 250.0;
        D_80215A88[sp20 + sp24].n.tc[0] = D_80217490[sp24];
        D_80215A88[sp20 + sp24].n.tc[1] = D_80217590[sp24];
        D_80215A88[sp20 + sp24].n.n[0] = sp10 / sp14 * 127.0f;
        D_80215A88[sp20 + sp24].n.n[1] = spC / sp14 * 127.0f;
        D_80215A88[sp20 + sp24].n.n[2] = -sp8 / sp14 * 127.0f;
        D_80215A88[sp20 + sp24].n.a = 0xFF;
    }
    sp20 = 0x80;
    for (sp24 = 0; sp24 < 0x40; sp24++) {
        sp10 = D_80217290[sp24];
        spC = D_80217390[sp24];
        sp8 = 250.0f;
        sp14 = sqrtf(sp10 * sp10 + spC * spC + sp8 * sp8);
        D_80215A88[sp20 + sp24].n.ob[0] = sp10 / sp14 * 250.0;
        D_80215A88[sp20 + sp24].n.ob[1] = sp8 / sp14 * 250.0;
        D_80215A88[sp20 + sp24].n.ob[2] = spC / sp14 * 250.0;
        D_80215A88[sp20 + sp24].n.tc[0] = D_80217490[sp24];
        D_80215A88[sp20 + sp24].n.tc[1] = D_80217590[sp24];
        D_80215A88[sp20 + sp24].n.n[0] = sp10 / sp14 * 127.0f;
        D_80215A88[sp20 + sp24].n.n[1] = sp8 / sp14 * 127.0f;
        D_80215A88[sp20 + sp24].n.n[2] = spC / sp14 * 127.0f;
        D_80215A88[sp20 + sp24].n.a = 0xFF;
    }
    sp20 = 0xC0;
    for (sp24 = 0; sp24 < 0x40; sp24++) {
        sp10 = D_80217290[sp24];
        spC = D_80217390[sp24];
        sp8 = 250.0f;
        sp14 = sqrtf(sp10 * sp10 + spC * spC + sp8 * sp8);
        D_80215A88[sp20 + sp24].n.ob[0] = sp10 / sp14 * 250.0;
        D_80215A88[sp20 + sp24].n.ob[1] = -sp8 / sp14 * 250.0;
        D_80215A88[sp20 + sp24].n.ob[2] = spC / sp14 * 250.0;
        D_80215A88[sp20 + sp24].n.tc[0] = D_80217490[sp24];
        D_80215A88[sp20 + sp24].n.tc[1] = D_80217590[sp24];
        D_80215A88[sp20 + sp24].n.n[0] = sp10 / sp14 * 127.0f;
        D_80215A88[sp20 + sp24].n.n[1] = -sp8 / sp14 * 127.0f;
        D_80215A88[sp20 + sp24].n.n[2] = spC / sp14 * 127.0f;
        D_80215A88[sp20 + sp24].n.a = 0xFF;
    }
    sp20 = 0x100;
    for (sp24 = 0; sp24 < 0x40; sp24++) {
        sp10 = D_80217290[sp24];
        spC = D_80217390[sp24];
        sp8 = 250.0f;
        sp14 = sqrtf(sp10 * sp10 + spC * spC + sp8 * sp8);
        D_80215A88[sp20 + sp24].n.ob[0] = sp8 / sp14 * 250.0;
        D_80215A88[sp20 + sp24].n.ob[1] = sp10 / sp14 * 250.0;
        D_80215A88[sp20 + sp24].n.ob[2] = spC / sp14 * 250.0;
        D_80215A88[sp20 + sp24].n.tc[0] = D_80217490[sp24];
        D_80215A88[sp20 + sp24].n.tc[1] = D_80217590[sp24];
        D_80215A88[sp20 + sp24].n.n[0] = sp8 / sp14 * 127.0f;
        D_80215A88[sp20 + sp24].n.n[1] = sp10 / sp14 * 127.0f;
        D_80215A88[sp20 + sp24].n.n[2] = spC / sp14 * 127.0f;
        D_80215A88[sp20 + sp24].n.a = 0xFF;
    }
    sp20 = 0x140;
    for (sp24 = 0; sp24 < 0x40; sp24++) {
        sp10 = D_80217290[sp24];
        spC = D_80217390[sp24];
        sp8 = 250.0f;
        sp14 = sqrtf(sp10 * sp10 + spC * spC + sp8 * sp8);
        D_80215A88[sp20 + sp24].n.ob[0] = -sp8 / sp14 * 250.0;
        D_80215A88[sp20 + sp24].n.ob[1] = sp10 / sp14 * 250.0;
        D_80215A88[sp20 + sp24].n.ob[2] = spC / sp14 * 250.0;
        D_80215A88[sp20 + sp24].n.tc[0] = D_80217490[sp24];
        D_80215A88[sp20 + sp24].n.tc[1] = D_80217590[sp24];
        D_80215A88[sp20 + sp24].n.n[0] = -sp8 / sp14 * 127.0f;
        D_80215A88[sp20 + sp24].n.n[1] = sp10 / sp14 * 127.0f;
        D_80215A88[sp20 + sp24].n.n[2] = spC / sp14 * 127.0f;
        D_80215A88[sp20 + sp24].n.a = 0xFF;
    }
}
#pragma function(sqrtf)

Gfx *func_801F1568(void) {
    u16 (*spAC)[7 * 7][0x1A4];
    u32 spA8;
    s32 spA4;
    s32 spA0;
    s32 sp9C;
    s32 sp98;
    s32 sp94;
    s32 sp90;
    s32 sp8C;
    s32 sp88;
    s32 sp84;
    s32 sp80;
    s32 sp7C;
    s32 sp78;
    s32 sp74;
    s32 sp70;
    s32 sp6C;
    Gfx *gfx;
    Gfx *sp64;

    spAC = (void *)D_80358070;
    spA8 = D_0068B550 - D_0066C900;
    func_8028B4C4((u32)D_0066C900, D_80358070, &spA8, 0xD, 0, 1);
    D_80358070 += spA8;
    D_8021728C = (u16 *)(D_80358070 - 0x6600);
    for (sp9C = 0; sp9C < 3; sp9C++) {
        D_80215A70[sp9C] = (u16 *)D_80358070 - (3 - sp9C) * 0x800 - 0x1800;
    }
    D_80215A7C = D_80358070 - 0x3000;
    D_80215A80 = D_80358070 - 0x2000;
    D_80215A84 = D_80358070 - 0x1000;
    sp64 = gfx = (Gfx *)D_80358070;
    func_801F0570();
    gSPTexture(gfx++, 0x8000, 0x8000, 4, G_TX_RENDERTILE, G_ON);
    for (sp90 = 0; sp90 < 6; sp90++) {
        sp8C = sp90 << 6;
        gSPVertex(gfx++, &D_80215A88[sp8C], 8, 0);
        sp88 = 8;
        for (sp9C = 0; sp9C < 7; sp9C++) {
            gSPVertex(gfx++, &D_80215A88[sp8C + sp9C * 8] + 8, 8, sp88);
            for (sp98 = 0; sp98 < 7; sp98++) {
                sp84 = 0;
                sp94 = sp9C * 7 + sp98;
                sp7C = 0;
                sp80 = 0;
                for (; sp84 < 5; sp84++, sp7C += sp78, sp80 = sp80 + sp6C + 3) {
                    sp74 = (16 >> sp84) + 1;
                    sp70 = (sp74 + 3) >> 2;
                    sp78 = sp74 * sp70;
                    sp6C = sp74 * sp74;
                    gDPSetTextureImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, sp74,
                                       &spAC[sp90][sp94][sp80]);
                    gDPSetTile(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, sp70, sp7C, G_TX_LOADTILE, 0, 0, 0, 0, 0, 0, 0);
                    gDPLoadTile(gfx++, G_TX_LOADTILE, 0, 0, sp74 << G_TEXTURE_IMAGE_FRAC,
                                sp74 << G_TEXTURE_IMAGE_FRAC);
                    gDPSetTile(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, sp70, sp7C, sp84, 0, 0, 0, sp84, 0, 0, sp84);
                    gDPSetTileSize(gfx++, sp84, ((sp98 * 16) << G_TEXTURE_IMAGE_FRAC) >> sp84,
                                   ((sp9C * 16) << G_TEXTURE_IMAGE_FRAC) >> sp84,
                                   ((sp98 * 16 + 16) << G_TEXTURE_IMAGE_FRAC) >> sp84,
                                   ((sp9C * 16 + 16) << G_TEXTURE_IMAGE_FRAC) >> sp84);
                }
                if (sp90 == 1 || sp90 == 2 || sp90 == 5) {
                    if (sp88 == 8) {
                        gSP1Triangle(gfx++, sp98, sp98 + 8, sp98 + 9, 0);
                        gSP1Triangle(gfx++, sp98, sp98 + 9, sp98 + 1, 0);
                    } else {
                        gSP1Triangle(gfx++, sp98 + 8, sp98, sp98 + 1, 0);
                        gSP1Triangle(gfx++, sp98 + 8, sp98 + 1, sp98 + 9, 0);
                    }
                } else if (sp88 == 8) {
                    gSP1Triangle(gfx++, sp98, sp98 + 9, sp98 + 8, 0);
                    gSP1Triangle(gfx++, sp98, sp98 + 1, sp98 + 9, 0);
                } else {
                    gSP1Triangle(gfx++, sp98 + 8, sp98 + 1, sp98, 0);
                    gSP1Triangle(gfx++, sp98 + 8, sp98 + 9, sp98 + 1, 0);
                }
            }
            sp88 ^= 8;
        }
    }
    gSPEndDisplayList(gfx++);
    D_80358070 += (gfx - sp64) * sizeof(Gfx);
    return sp64;
}

s32 func_801F1DA8(s32 arg0) {
    UnkStruct_8020D810 *sp2C;
    s32 sp28;
    s32 sp24;

    if (func_801FE760(arg0) != 0) {
        return 0;
    }
    if (func_80264BA4(arg0) != 3) {
        return 0;
    }
    if (((D_80364AF0[D_80364AE8].unk18[arg0] > 0 && D_80364AF0[D_80364AE8].unk18[arg0] < 6) ? 1 : 0) ||
        arg0 == 0) {
        return 1;
    }
    for (sp28 = 0; sp28 < 0x3C; sp28++) {
        if ((D_80364AF0[D_80364AE8].unk18[sp28] > 0 && D_80364AF0[D_80364AE8].unk18[sp28] < 6) ? 1 : 0) {
            sp2C = &D_8020D810[sp28];
            for (sp24 = 0; sp24 < 8 && sp2C->unk1C[sp24] != -1; sp24++) {
                if (sp2C->unk1C[sp24] == arg0) {
                    return 1;
                }
            }
            for (sp24 = 0; sp24 < 4 && sp2C->unk18[sp24] != -1; sp24++) {
                if (sp2C->unk18[sp24] == arg0 && (D_80364AF0[D_80364AE8].unk54[sp28] & (1 << sp24))) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

Gfx *func_801F2000(void) {
    Vtx *sp84;
    Vtx *sp80;
    Gfx *sp7C;
    Gfx *gfx;
    s32 sp74;
    s32 sp70;

    sp84 = (Vtx *)D_80358070;
    sp80 = sp84;
    D_80358070 += 0x30 * sizeof(Vtx);
    sp7C = gfx = (Gfx *)D_80358070;
    gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
    gSPSetGeometryMode(gfx++, G_SHADE | G_SHADING_SMOOTH | G_CULL_BACK);
    gSPTexture(gfx++, 0x8000, 0x8000, 5, G_TX_RENDERTILE, G_ON);
    gDPSetTextureLOD(gfx++, G_TL_LOD);
    gDPSetCycleType(gfx++, G_CYC_2CYCLE);
    gDPSetRenderMode(gfx++, G_RM_PASS, G_RM_XLU_SURF2);
    for (sp70 = 0; sp70 < 2; sp70++) {
        gDPPipeSync(gfx++);
        if (sp70 != 0) {
            gDPSetCombineLERP(gfx++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,
                              COMBINED, 0, PRIMITIVE_ALPHA, 0, COMBINED, 0, PRIMITIVE, 0);
        } else {
            gSPDisplayList(gfx++, D_8020BC88);
            gDPSetCombineLERP(gfx++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 0, 0,
                              0, PRIMITIVE, COMBINED, 0, ENVIRONMENT, 0);
        }
        for (sp74 = 0; sp74 < 0x3C; sp74++) {
            s32 sp44;
            s32 sp40;

            for (sp44 = 0, sp40 = 0; sp44 < 6 && sp40 == 0; sp44++) {
                if (D_802E8F38[sp44][0] == sp74) {
                    sp40 = 1;
                }
            }
            if (sp40 != 0 && (D_80364AF0[D_80364AE8].unk90 & (1 << (sp44 + 0x1F)))) {
                func_801FCE74(sp84, sp74, sp70 * 1.5 + 2.5, sp70 * 1.5 + 4.0, 0x20, 0x20, 2.25f, 1);
                gSPVertex(gfx++, sp84, 4, 0);
                gSP1Triangle(gfx++, 0, 1, 2, 0);
                gSP1Triangle(gfx++, 2, 3, 0, 0);
                sp84 += 4;
            }
        }
    }
    gDPPipeSync(gfx++);
    gSPEndDisplayList(gfx++);
    D_80358070 = (u8 *)gfx;
    osWritebackDCache(sp80, 0x30 * sizeof(Vtx));
    return sp7C;
}

typedef struct {
    /* 0x00 */ Gfx *unk0[9];
} UnkStruct_8020BD08; /* size = 0x24 */

extern UnkStruct_8020BD08 D_8020BD08;
extern u8 D_802E8F94[][0x44];

/*
 * The colour of each vertex batch is set as r, g, b, a in one comma group
 * (sp97..sp94): IDO stores a comma group in reverse, which is the order the
 * original writes them.
 */
Gfx *func_801F2428(void) {
    UnkStruct_8020D810 *spEC;
    Vtx *spE8;
    Gfx *gfx;
    Gfx *spE0;
    s32 spDC;
    s32 spD8;
    s32 spD4;
    s32 spD0;
    s32 spCC;
    u8 spCB;
    s8 spCA;
    u8 spC9;
    f32 spC4;
    UnkStruct_8020BD08 spA0;
    Gfx *sp9C;
    Gfx *sp98;
    u8 sp97;
    u8 sp96;
    u8 sp95;
    u8 sp94;

    spD4 = 0;
    spD0 = 0;
    spE8 = (Vtx *)D_80358070;
    spA0 = D_8020BD08;
    sp98 = NULL;
    D_80358070 += 0x1E0 * sizeof(Vtx);
    spE0 = gfx = (Gfx *)D_80358070;
    gDPPipeSync(gfx++);
    gDPSetTextureLOD(gfx++, G_TL_LOD);
    gDPSetCycleType(gfx++, G_CYC_2CYCLE);
    gDPSetRenderMode(gfx++, G_RM_PASS, G_RM_XLU_SURF2);
    gSPTexture(gfx++, 0x8000, 0x8000, 5, G_TX_RENDERTILE, G_ON);
    spCA = 8;
    do {
        sp9C = spA0.unk0[spCA];
        if (sp9C != sp98) {
            gSPDisplayList(gfx++, sp9C);
        }
        sp98 = sp9C;
        gDPPipeSync(gfx++);
        /* (u32) makes IDO load spCA with lbu, as the original does; (u8) adds an andi. */
        switch ((u32)spCA) {
            case 0:
            case 8:
                gDPSetCombineLERP(gfx++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 0,
                                  0, 0, SHADE, COMBINED, 0, ENVIRONMENT, 0);
                sp97 = 0, sp96 = 0, sp95 = 0, sp94 = 0xFF;
                break;
            case 1:
            case 2:
            case 3:
            case 4:
                gDPSetCombineLERP(gfx++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0,
                                  COMBINED, 0, PRIMITIVE_ALPHA, 0, COMBINED, 0, PRIMITIVE, 0);
                sp97 = 0, sp96 = 0, sp95 = 0, sp94 = 0xFF;
                break;
            case 5:
                gDPSetCombineLERP(gfx++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 0,
                                  0, 0, SHADE, COMBINED, 0, PRIMITIVE, 0);
                sp97 = 0x50, sp96 = 0x50, sp95 = 0x50, sp94 = 0xFF;
                break;
            case 6:
                gDPSetCombineLERP(gfx++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 0,
                                  0, 0, SHADE, COMBINED, 0, PRIMITIVE, 0);
                sp97 = 0xFF, sp96 = 0, sp95 = 0, sp94 = 0xFF;
                break;
            case 7:
                gDPSetCombineLERP(gfx++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 0,
                                  0, 0, SHADE, COMBINED, 0, PRIMITIVE, 0);
                sp97 = 0, sp96 = 0xFF, sp95 = 0, sp94 = 0xFF;
                break;
        }
        for (spDC = 0; spDC < 0x3C; spDC++) {
            spC9 = (spCA == 6 || spCA == 7) &&
                   ((D_80364AF0[D_80364AE8].unk18[spDC] > 0 && D_80364AF0[D_80364AE8].unk18[spDC] < 6) ? 1 : 0) &&
                   D_80364AF0[D_80364AE8].unk18[spDC] != 4;
            if (D_80364AF0[D_80364AE8].unk18[spDC] != spCA && !spC9) {
                continue;
            }
            spEC = &D_8020D810[spDC];
            if (func_801F1DA8(spDC) == 0) {
                continue;
            }
            if (spC9 != 0) {
                spD8 = 0;
                spCB = 0;
                for (; spD8 < 4 && spEC->unk18[spD8] != -1 && spCB == 0; spD8++) {
                    if (!(D_80364AF0[D_80364AE8].unk54[spDC] & (1 << spD8))) {
                        spCB = 1;
                    }
                }
                if ((spCB != 0 && spCA == 6) || (spCB == 0 && spCA == 7)) {
                    continue;
                }
            }
            if (D_802E8F94[spDC][0] & 0x81) {
                spC4 = 1.75f;
            } else {
                spC4 = 1.0f;
            }
            if (spC9 != 0) {
                spC4 += 0.3;
            }
            func_801FCE74(&spE8[spD4], spDC, 0.0f, 0.0f, 0x20, 0x20, spC4, 0);
            for (spD8 = 0; spD8 < 4; spD8++) {
                spE8[spD4 + spD8].v.cn[0] = sp97;
                spE8[spD4 + spD8].v.cn[1] = sp96;
                spE8[spD4 + spD8].v.cn[2] = sp95;
                spE8[spD4 + spD8].v.cn[3] = sp94;
            }
            spD4 += 4;
            spCC = spD4 - spD0;
            if (spCC % 16 == 0) {
                Vtx *sp60 = &spE8[spD4 - 16];

                gSPVertex(gfx++, sp60, 16, 0);
                for (spD8 = 0; spD8 < 16; spD8 += 4) {
                    gSP1Triangle(gfx++, spD8, spD8 + 1, spD8 + 2, 0);
                    gSP1Triangle(gfx++, spD8 + 2, spD8 + 3, spD8, 0);
                }
            }
        }
        spCC = spD4 - spD0;
        if (spCC % 16) {
            Vtx *sp50 = &spE8[spD4 - spCC % 16];

            gSPVertex(gfx++, sp50, spCC % 16, 0);
            for (spD8 = 0; spD8 < spCC % 16; spD8 += 4) {
                gSP1Triangle(gfx++, spD8, spD8 + 1, spD8 + 2, 0);
                gSP1Triangle(gfx++, spD8 + 2, spD8 + 3, spD8, 0);
            }
            spD0 = spD4;
        }
    } while (--spCA >= 0);
    gDPPipeSync(gfx++);
    gSPEndDisplayList(gfx++);
    D_80358070 = (u8 *)gfx;
    osWritebackDCache(spE8, 0x1E0 * sizeof(Vtx));
    return spE0;
}

Gfx *func_801F2E20(void) {
    Vtx *spCC;
    Vtx *spC8;
    Mtx *spC4;
    Gfx *gfx;
    Gfx *spBC;
    s32 spB8;
    s32 spB4;
    s32 spB0;
    s32 spAC;
    s32 spA8;
    s32 spA4;
    s32 spA0;
    s32 pad[7];

    spCC = (Vtx *)(D_803156F8 + 0x15C0);
    spC8 = (Vtx *)(D_803156F8 + 0x22A58);
    spC4 = (Mtx *)D_80358070;
    D_80358070 += 2 * sizeof(Mtx);
    spBC = gfx = (Gfx *)D_80358070;
    guPerspective(spC4, &D_80217288, 45.0f, 4.0f / 3.0f, 100.0f, 2.5e+04f, 1.0f);
    guLookAt(&spC4[1], 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f);
    gSPPerspNormalize(gfx++, D_80217288);
    gSPMatrix(gfx++, spC4, G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPMatrix(gfx++, &spC4[1], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPTexture(gfx++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    spA0 = 0;
    for (spB8 = 0; spB8 < 0x200; spB8 += 0x10) {
        gSPVertex(gfx++, &D_02000000[spB8 + 0x15C], 16, 0);
        gDPPipeSync(gfx++);
        for (spB4 = 0; spB4 < 0x10; spB4 += 4) {
            if (((spB8 + spB4) >> 2) % 43 == 0) {
                gDPLoadTextureBlock(gfx++, D_8021728C + (spA0 << 8), G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0,
                                    G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                spA0++;
            }
            func_801FDCA4(spCC, (spB8 + spB4) / 4, func_8026A828(0, 25000));
            spCC[spB8 + spB4].v.tc[0] = 0;
            spCC[spB8 + spB4].v.tc[1] = 0;
            spCC[spB8 + spB4 + 1].v.tc[0] = 0;
            spCC[spB8 + spB4 + 1].v.tc[1] = 0x3C0;
            spCC[spB8 + spB4 + 2].v.tc[0] = 0x3C0;
            spCC[spB8 + spB4 + 2].v.tc[1] = 0x3C0;
            spCC[spB8 + spB4 + 3].v.tc[0] = 0x3C0;
            spCC[spB8 + spB4 + 3].v.tc[1] = 0;
            gSP1Triangle(gfx++, spB4, spB4 + 1, spB4 + 2, 0);
            gSP1Triangle(gfx++, spB4, spB4 + 2, spB4 + 3, 0);
        }
    }
    for (spB8 = 0; spB8 < 0x200 * sizeof(Vtx); spB8++) {
        ((u8 *)spC8)[spB8] = ((u8 *)spCC)[spB8];
    }
    gDPPipeSync(gfx++);
    gSPEndDisplayList(gfx++);
    D_80358070 += (gfx - spBC) * sizeof(Gfx);
    osWritebackDCache(spCC, 0x200 * sizeof(Vtx));
    return spBC;
}

