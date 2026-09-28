#include "common.h"

/* 12-byte sort records: a u16 key, a quad index and a texture address. */
typedef struct {
    /* 0x0 */ u16 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
} UnkStruct_80365340; /* size = 0xC */

extern s32 D_802E8BDC;
extern s32 D_802E8C70;
extern s32 D_802E8C74;
extern s32 D_802E8C78;
extern u8 D_8035805C;
extern u8 *D_80358070;
extern u64 D_80364A98;
extern UnkStruct_80365340 *D_80365340;
extern Vtx *D_80365348[2];
extern s32 D_80365350;

void func_8025B070(void);
void func_802597D8(u8 *arg0, u8 *arg1, s32 arg2);
s32 func_80259814(u16 *arg0, u16 *arg1);
void func_8025946C(Gfx **arg0, s32 arg1);
void func_80259824(Gfx **arg0, s32 arg1);

void func_802592F0(void) {
    s32 sp1C;

    if ((D_80364A98 & 0xC9FD8FE7DBFF8080) || (D_80364A98 == 0x100000000000) || (D_80364A98 == 2) ||
        (D_802E8BDC == 0x28) || (D_802E8BDC == 0x32)) {
        D_80365350 = 0x200;
    } else if (D_80364A98 == 0x40) {
        D_80365350 = 0x9C;
    } else {
        D_80365350 = 0xAC;
    }
    for (sp1C = 0; sp1C < 2; sp1C++) {
        D_80365348[sp1C] = (Vtx *)D_80358070;
        D_80358070 += D_80365350 * 0x10 * 4;
    }
    D_80365340 = (UnkStruct_80365340 *)D_80358070;
    D_80358070 += D_80365350 * 0xC;
    func_8025B070();
}

void func_80259450(void) {
    D_802E8C70 = 0;
    D_802E8C74 = 0;
    D_802E8C78 = 0;
}

void func_8025946C(Gfx **arg0, s32 arg1) {
    Gfx *gfx = *arg0;

    gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
    gSPSetGeometryMode(gfx++, G_SHADE | G_SHADING_SMOOTH);
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(gfx++, G_CC_MODULATERGBA, G_CC_MODULATERGBA);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    *arg0 = gfx;
}

/* Shell sort. */
void func_802595E0(u8 *arg0, s32 arg1, s32 arg2, s32 (*arg3)(void *, void *)) {
    s32 sp124;
    s32 sp120;
    s32 sp11C;
    u8 *sp118;
    u8 sp18[0x100];

    sp118 = arg0;
    for (sp11C = 1; sp11C <= arg1 / 9; sp11C = sp11C * 3 + 1) {
    }
    for (; sp11C > 0; sp11C /= 3) {
        for (sp124 = sp11C; sp124 < arg1; sp124++) {
            func_802597D8(sp18, sp118 + arg2 * sp124, arg2);
            sp120 = sp124;
            while ((sp120 >= sp11C) && (arg3(sp118 + (sp120 - sp11C) * arg2, sp18) > 0)) {
                func_802597D8(sp118 + arg2 * sp120, sp118 + (sp120 - sp11C) * arg2, arg2);
                sp120 -= sp11C;
            }
            func_802597D8(sp118 + arg2 * sp120, sp18, arg2);
        }
    }
}

void func_802597D8(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 sp4;

    for (sp4 = 0; sp4 < arg2; sp4++) {
        arg0[sp4] = arg1[sp4];
    }
}

s32 func_80259814(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}

void func_80259824(Gfx **arg0, s32 arg1) {
    s32 sp54;
    Gfx *gfx;
    s32 sp4C;

    sp54 = 0;
    gfx = *arg0;
    func_802595E0((u8 *)&D_80365340[D_802E8C70], D_802E8C74 - D_802E8C70, sizeof(UnkStruct_80365340),
                  (s32(*)(void *, void *))func_80259814);
    for (sp4C = D_802E8C70; sp4C < D_802E8C74; sp4C++) {
        if (D_80365340[sp4C].unk8 != sp54) {
            sp54 = D_80365340[sp4C].unk8;
            if (sp4C == D_802E8C70) {
                gDPLoadTextureBlock_4b(gfx++, OS_PHYSICAL_TO_K0(sp54), G_IM_FMT_I, 32, 32, 0,
                                       G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                                       G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            } else {
                gDPSetTextureImage(gfx++, G_IM_FMT_I, G_IM_SIZ_16b, 1, OS_PHYSICAL_TO_K0(sp54));
                gDPLoadSync(gfx++);
                gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, 0, 255, 1024);
            }
        }
        gSPVertex(gfx++, &D_80365348[D_8035805C][D_80365340[sp4C].unk4 * 4], 4, 0);
        gSP1Triangle(gfx++, 0, 1, 2, 0);
        gSP1Triangle(gfx++, 0, 2, 3, 0);
    }
    osWritebackDCache(&D_80365348[D_8035805C][D_802E8C70 * 4], (D_802E8C74 - D_802E8C70) << 6);
    D_802E8C70 = D_802E8C74;
    *arg0 = gfx;
}

void func_80259BD4(Gfx **arg0, s32 arg1) {
    Gfx *sp1C;

    sp1C = *arg0;
    func_8025946C(&sp1C, arg1);
    func_80259824(&sp1C, arg1);
    *arg0 = sp1C;
}

void func_80259C24(Gfx **arg0, s32 arg1) {
    Gfx *gfx = *arg0;

    gSPMatrix(gfx++, arg1 + 0xC0, G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPMatrix(gfx++, arg1 + 0x1C0, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    func_8025946C(&gfx, arg1);
    func_80259824(&gfx, arg1);
    *arg0 = gfx;
}

void func_80259EC4(s32, s32, s32, u8, s32, f32, s32, f32, s32, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8,
                   u8, u8, u8, u8);

void func_80259CCC(s32 arg0, s32 arg1, s32 arg2, u8 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, u8 arg9,
                   u8 arg10, u8 arg11, u8 arg12, u8 arg13) {
    func_80259EC4(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg10, arg11,
                  arg12, arg13, arg10, arg11, arg12, arg13, arg10, arg11, arg12, arg13);
}

void func_80259DC8(s32 arg0, s32 arg1, s32 arg2, u8 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, u8 arg9,
                   u8 arg10, u8 arg11, u8 arg12, u8 arg13, u8 arg14, u8 arg15, u8 arg16, u8 arg17) {
    func_80259EC4(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg10, arg11,
                  arg12, arg13, arg14, arg15, arg16, arg17, arg14, arg15, arg16, arg17);
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/14B30/func_80259EC4.s")
