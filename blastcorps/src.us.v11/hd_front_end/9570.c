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
extern f32 D_8020F080; /* 25000.0f */
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
extern f64 D_8020EFC0; /* 250.0 */
extern f64 D_8020EFC8; /* 250.0 */
extern f64 D_8020EFD0; /* 250.0 */
extern f64 D_8020EFD8; /* 250.0 */
extern f64 D_8020EFE0; /* 250.0 */
extern f64 D_8020EFE8; /* 250.0 */
extern f64 D_8020EFF0; /* 250.0 */
extern f64 D_8020EFF8; /* 250.0 */
extern f64 D_8020F000; /* 250.0 */
extern f64 D_8020F008; /* 250.0 */
extern f64 D_8020F010; /* 250.0 */
extern f64 D_8020F018; /* 250.0 */
extern f64 D_8020F020; /* 250.0 */
extern f64 D_8020F028; /* 250.0 */
extern f64 D_8020F030; /* 250.0 */
extern f64 D_8020F038; /* 250.0 */
extern f64 D_8020F040; /* 250.0 */
extern f64 D_8020F048; /* 250.0 */

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
        D_80215A88[sp24].n.ob[0] = sp10 / sp14 * D_8020EFC0;
        D_80215A88[sp24].n.ob[1] = spC / sp14 * D_8020EFC8;
        D_80215A88[sp24].n.ob[2] = sp8 / sp14 * D_8020EFD0;
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
        D_80215A88[sp20 + sp24].n.ob[0] = sp10 / sp14 * D_8020EFD8;
        D_80215A88[sp20 + sp24].n.ob[1] = spC / sp14 * D_8020EFE0;
        D_80215A88[sp20 + sp24].n.ob[2] = -sp8 / sp14 * D_8020EFE8;
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
        D_80215A88[sp20 + sp24].n.ob[0] = sp10 / sp14 * D_8020EFF0;
        D_80215A88[sp20 + sp24].n.ob[1] = sp8 / sp14 * D_8020EFF8;
        D_80215A88[sp20 + sp24].n.ob[2] = spC / sp14 * D_8020F000;
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
        D_80215A88[sp20 + sp24].n.ob[0] = sp10 / sp14 * D_8020F008;
        D_80215A88[sp20 + sp24].n.ob[1] = -sp8 / sp14 * D_8020F010;
        D_80215A88[sp20 + sp24].n.ob[2] = spC / sp14 * D_8020F018;
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
        D_80215A88[sp20 + sp24].n.ob[0] = sp8 / sp14 * D_8020F020;
        D_80215A88[sp20 + sp24].n.ob[1] = sp10 / sp14 * D_8020F028;
        D_80215A88[sp20 + sp24].n.ob[2] = spC / sp14 * D_8020F030;
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
        D_80215A88[sp20 + sp24].n.ob[0] = -sp8 / sp14 * D_8020F038;
        D_80215A88[sp20 + sp24].n.ob[1] = sp10 / sp14 * D_8020F040;
        D_80215A88[sp20 + sp24].n.ob[2] = spC / sp14 * D_8020F048;
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

#pragma GLOBAL_ASM("asm/nonmatchings/hd_front_end/9570/func_801F2428.s")

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
    guPerspective(spC4, &D_80217288, 45.0f, 4.0f / 3.0f, 100.0f, D_8020F080, 1.0f);
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

Gfx *func_801F3450(Gfx *arg0, u8 *arg1) {
    Gfx *gfx = arg0;
    UnkStruct_8020BD30 *sp48;
    UnkStruct_8020BD30 *sp44;
    u8 sp43;
    s32 sp3C;

    sp48 = D_8020BD30;
    sp44 = &sp48[&sp48[D_80217B6C] - sp48];
    gSPPerspNormalize(gfx++, D_8035807C);
    D_80217B50 = 4;
    guMtxIdentF(D_80217A10[4]);
    func_801F374C(&D_8020BE98);
    if (D_802182A8 != 1) {
        D_80217B54 = sp44->unk2C;
        D_80217B58 = sp44->unk30;
        D_80217B5C = sp44->unk34;
        D_80217B60 = sp44->unk20;
        D_80217B64 = sp44->unk24;
        D_80217B68 = sp44->unk28;
    }
    guLookAt((Mtx *)(arg1 + 0x140), D_80217B54 + 1.0f, D_80217B58, D_80217B5C, D_80217B60, D_80217B64, D_80217B68,
             0.0f, 1.0f, 0.0f);
    func_801F4878((Gfx *)(arg1 + 0xACB0), arg1);
    func_802595E0(D_80218270, 7, sizeof(UnkStruct_80218270), func_801F36B0);
    for (sp3C = 0, sp43 = 0; sp3C < 7; sp3C++) {
        if (sp43 == 0 || D_80217B6C != 3) {
            gSPDisplayList(gfx++, D_80218270[sp3C].unk4);
        }
        if (D_80218270[sp3C].unk0 == 3) {
            sp43 = 1;
        }
    }
    return gfx;
}

s32 func_801F36B0(s32 *arg0, s32 *arg1) {
    UnkStruct_8020BD30 *spC;
    UnkStruct_8020BD30 *sp8;
    UnkStruct_8020BD30 *sp4;

    spC = D_8020BD30;
    sp8 = &spC[&spC[*arg0] - spC];
    sp4 = &spC[&spC[*arg1] - spC];
    return sp4->unk38 - sp8->unk38;
}

void func_801F374C(UnkStruct_8020BD30 *arg0) {
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    Mtx *sp60;
    f32 sp20[4][4];

    while (arg0 != NULL) {
        sp74 = arg0->unk0 / D_8020BDE4;
        sp60 = D_80217B70[arg0 - D_8020BD30];
        sp64 = 0.0f;
        if (arg0->unk8 != 0.0f) {
            arg0->unk1C += D_8020BDEC * D_8020F090 / arg0->unk8 / D_8020F098 * 60.0 / 60.0;
        }
        func_801FD484(&sp64, &arg0->unk1C, &sp70, &sp6C, &sp68, arg0->unkC);
        guTranslateF(sp20, -sp70, -sp6C, -sp68);
        guScale(&sp60[D_8035805C + 2], sp74, sp74, sp74);
        guMtxCatF(D_80217A10[D_80217B50], sp20, D_80217A10[D_80217B50 - 1]);
        D_80217B50--;
        guMtxF2L(D_80217A10[D_80217B50], &sp60[D_8035805C]);
        osWritebackDCache(sp60, 4 * sizeof(Mtx));
        func_801F4C3C(arg0, sp74);
        func_801F374C(arg0->unk14);
        D_80217B50++;
        arg0 = arg0->unk10;
    }
}

Gfx *func_801F3964(Gfx *arg0, u8 *arg1, UnkStruct_8020BD30 *arg2, f32 arg3) {
    Gfx *gfx = arg0;
    f32 spA0;
    s16 sp9E;
    s16 sp9C;
    u8 *sp98;
    Vtx *sp94;
    s32 sp90;

    spA0 = arg2->unk0 * 64.0 / D_8020BDE4;
    sp94 = D_80217690[arg2 - D_8020BD30][D_8035805C];
    gDPPipeSync(gfx++);
    gDPSetPrimColorB(gfx++, 0xFF, 0xFF, arg2->unk18, arg2->unk19, arg2->unk1A, 0xFF);
    gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
    gSPSetGeometryMode(gfx++, G_SHADE | G_SHADING_SMOOTH);
    gSPTexture(gfx++, 0x2000, 0x2000, 0, G_TX_RENDERTILE, G_ON);
    gDPSetCombineLERP(gfx++, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0);
    switch (arg2 - D_8020BD30) {
        case 1:
        case 4:
            sp98 = D_80215A80;
            break;
        default:
            sp98 = D_80215A7C;
            break;
    }
    if (arg2->unk38 > 1.0) {
        spA0 = spA0 * D_8020F0A0 / arg2->unk38;
    }
    sp90 = spA0;
    func_8027690C(arg1, 0.0f, 0.0f, 0.0f, &sp9E, &sp9C, &D_80217B70[arg2 - D_8020BD30][D_8035805C],
                  &D_80217B70[arg2 - D_8020BD30][D_8035805C] + 2, (Mtx *)(arg1 + 0x1280), 4.0f);
    if (((sp9E > 0) ? sp9E : -sp9E) + spA0 / 2.0 < 4096.0 && ((sp9C > 0) ? sp9C : -sp9C) + spA0 / 2.0 < 4096.0) {
        gDPLoadTextureBlock(gfx++, sp98, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64, 0, G_TX_CLAMP, G_TX_MIRROR, G_TX_NOMASK,
                            6, G_TX_NOLOD, G_TX_NOLOD);
        sp94[0].v.ob[0] = sp9E - sp90 / 2;
        sp94[0].v.ob[1] = sp9C - sp90 / 2;
        sp94[0].v.ob[2] = -10;
        sp94[0].v.tc[0] = 0;
        sp94[0].v.tc[1] = 0;
        sp94[1].v.ob[0] = sp9E - sp90 / 2;
        sp94[1].v.ob[1] = sp9C + sp90 / 2;
        sp94[1].v.ob[2] = -10;
        sp94[1].v.tc[0] = 0;
        sp94[1].v.tc[1] = 0x3F00;
        sp94[2].v.ob[0] = sp9E + sp90 / 2;
        sp94[2].v.ob[1] = sp9C + sp90 / 2;
        sp94[2].v.ob[2] = -10;
        sp94[2].v.tc[0] = 0x3F00;
        sp94[2].v.tc[1] = 0x3F00;
        sp94[3].v.ob[0] = sp9E + sp90 / 2;
        sp94[3].v.ob[1] = sp9C - sp90 / 2;
        sp94[3].v.ob[2] = -10;
        sp94[3].v.tc[0] = 0x3F00;
        sp94[3].v.tc[1] = 0;
        gSPVertex(gfx++, sp94, 4, 0);
        gSP1Triangle(gfx++, 0, 1, 2, 0);
        gSP1Triangle(gfx++, 0, 3, 2, 0);
        gDPPipeSync(gfx++);
    }
    gDPPipeSync(gfx++);
    osWritebackDCache(sp94, 4 * sizeof(Vtx));
    return gfx;
}

Gfx *func_801F4110(Gfx *arg0, u8 *arg1, UnkStruct_8020BD30 *arg2, f32 arg3) {
    Gfx *gfx = arg0;
    f32 spA0;
    s16 sp9E;
    s16 sp9C;
    Vtx *sp98;
    s32 sp94;

    spA0 = arg2->unk0 * 64.0 / D_8020BDE4;
    sp98 = D_80217690[arg2 - D_8020BD30][D_8035805C];
    gDPPipeSync(gfx++);
    gDPSetPrimColorB(gfx++, 0xFF, 0xFF, arg2->unk18, arg2->unk19, arg2->unk1A, 0xFF);
    gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
    gSPSetGeometryMode(gfx++, G_SHADE | G_SHADING_SMOOTH);
    gSPTexture(gfx++, 0x1000, 0x1000, 0, G_TX_RENDERTILE, G_ON);
    gDPSetCombineLERP(gfx++, 0, 0, 0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0);
    if (arg2->unk38 > 1.0) {
        spA0 = spA0 * D_8020F0A8 / arg2->unk38;
    }
    sp94 = spA0;
    func_8027690C(arg1, 0.0f, 0.0f, 0.0f, &sp9E, &sp9C, &D_80217B70[arg2 - D_8020BD30][D_8035805C],
                  &D_80217B70[arg2 - D_8020BD30][D_8035805C] + 2, (Mtx *)(arg1 + 0x1280), 4.0f);
    if (((sp9E > 0) ? sp9E : -sp9E) + spA0 / 2.0 < 4096.0 && ((sp9C > 0) ? sp9C : -sp9C) + spA0 / 2.0 < 4096.0) {
        gDPLoadTextureBlock(gfx++, D_80215A84, G_IM_FMT_RGBA, G_IM_SIZ_32b, 32, 32, 0, G_TX_CLAMP, G_TX_CLAMP,
                            G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        sp98[0].v.ob[0] = sp9E - sp94 / 2;
        sp98[0].v.ob[1] = sp9C - sp94 / 2;
        sp98[0].v.ob[2] = -10;
        sp98[0].v.tc[0] = 0;
        sp98[0].v.tc[1] = 0;
        sp98[1].v.ob[0] = sp9E - sp94 / 2;
        sp98[1].v.ob[1] = sp9C + sp94 / 2;
        sp98[1].v.ob[2] = -10;
        sp98[1].v.tc[0] = 0;
        sp98[1].v.tc[1] = 0x3E00;
        sp98[2].v.ob[0] = sp9E + sp94 / 2;
        sp98[2].v.ob[1] = sp9C + sp94 / 2;
        sp98[2].v.ob[2] = -10;
        sp98[2].v.tc[0] = 0x3E00;
        sp98[2].v.tc[1] = 0x3E00;
        sp98[3].v.ob[0] = sp9E + sp94 / 2;
        sp98[3].v.ob[1] = sp9C - sp94 / 2;
        sp98[3].v.ob[2] = -10;
        sp98[3].v.tc[0] = 0x3E00;
        sp98[3].v.tc[1] = 0;
        gSPVertex(gfx++, sp98, 4, 0);
        gSP1Triangle(gfx++, 0, 1, 2, 0);
        gSP1Triangle(gfx++, 0, 3, 2, 0);
        gDPPipeSync(gfx++);
    }
    gDPPipeSync(gfx++);
    osWritebackDCache(sp98, 4 * sizeof(Vtx));
    return gfx;
}

void func_801F4878(Gfx *arg0, u8 *arg1) {
    Gfx *gfx = arg0;
    s32 sp68;
    UnkStruct_8020BD30 *sp64;
    UnkStruct_8020BD30 *sp60;
    Mtx *sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;

    for (sp68 = 0; sp68 < 7; sp68++) {
        sp64 = D_8020BD30;
        sp60 = &sp64[&sp64[sp68] - sp64];
        sp5C = D_80217B70[sp68];
        sp58 = sp60->unk0 / D_8020BDE4;
        sp54 = sp60->unk20 - D_80217B54;
        sp50 = sp60->unk24 - D_80217B58;
        sp4C = sp60->unk28 - D_80217B5C;
        sp60->unk38 = sqrtf(sp54 * sp54 + sp50 * sp50 + sp4C * sp4C);
        D_80218270[sp60 - D_8020BD30].unk0 = sp60 - D_8020BD30;
        D_80218270[sp60 - D_8020BD30].unk4 = gfx;
        switch (sp68) {
            case 3:
                gSPMatrix(gfx++, arg1 + 0x80, G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
                gSPMatrix(gfx++, arg1 + 0x140, G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH);
                gSPMatrix(gfx++, &sp5C[D_8035805C], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
                gSPMatrix(gfx++, &sp5C[D_8035805C + 2], G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
                gSPMatrix(gfx++, arg1 + 0x1280, G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
                gfx = func_801FE238(gfx, arg1);
                break;
            case 6:
                gSPMatrix(gfx++, arg1 + 0x100, G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
                gSPMatrix(gfx++, arg1 + 0x1C0, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
                gfx = func_801F4110(gfx, arg1, sp60, sp58);
                break;
            default:
                gSPMatrix(gfx++, arg1 + 0x100, G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
                gSPMatrix(gfx++, arg1 + 0x1C0, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
                gfx = func_801F3964(gfx, arg1, sp60, sp58);
                break;
        }
        gSPEndDisplayList(gfx++);
    }
}

void func_801F4C3C(UnkStruct_8020BD30 *arg0, f32 arg1) {
    f32 sp2C;
    f32 sp28;
    f32 sp24;

    sp28 = 0.0f;
    sp24 = 0.0f;
    if (arg0 - D_8020BD30 != 6) {
        sp2C = D_80217A10[D_80217B50][3][3];
        arg0->unk20 = D_80217A10[D_80217B50][3][0] / sp2C;
        arg0->unk24 = D_80217A10[D_80217B50][3][1] / sp2C;
        arg0->unk28 = D_80217A10[D_80217B50][3][2] / sp2C;
    }
    if (arg0 - D_8020BD30 == 3) {
        if (arg0) {
        }
        func_801FD484(&D_8021A920, &D_8021A91C, &arg0->unk2C, &arg0->unk30, &arg0->unk34, arg1 * D_8021A918);
        arg0->unk2C += arg0->unk20;
        arg0->unk30 += arg0->unk24;
        arg0->unk34 += arg0->unk28;
        return;
    }
    func_801FD484(&sp28, &sp24, &arg0->unk2C, &arg0->unk30, &arg0->unk34, arg1 * D_8021A918);
    arg0->unk2C += arg0->unk20;
    arg0->unk30 += arg0->unk24;
    arg0->unk34 += arg0->unk28;
}

void func_801F4E1C(s32 *arg0, s32 *arg1) {
    s32 *spC = arg0;
    s32 *sp8 = arg1;
    u32 sp4;

    for (sp4 = 0; sp4 < 16; sp4++) {
        sp8[sp4] = spC[sp4];
    }
}
