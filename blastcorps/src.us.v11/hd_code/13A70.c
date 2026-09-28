#include "common.h"

/* 0x1040-byte records; D_803643C8 is the first, D_803643CC the next free. */
typedef struct {
    /* 0x0000 */ u8 unk0[0x1000];
    /* 0x1000 */ f32 unk1000;
    /* 0x1004 */ s32 unk1004;
    /* 0x1008 */ s32 unk1008;
    /* 0x100C */ s32 unk100C;
    /* 0x1010 */ s32 unk1010;
    /* 0x1014 */ s32 unk1014;
    /* 0x1018 */ s16 unk1018;
    /* 0x101A */ s16 unk101A;
    /* 0x101C */ s16 unk101C;
    /* 0x101E */ s16 unk101E;
    /* 0x1020 */ s16 unk1020;
    /* 0x1022 */ u8 unk1022;
    /* 0x1023 */ u8 unk1023;
    /* 0x1024 */ u8 unk1024[0x1C];
} UnkStruct_803643C8; /* size = 0x1040 */

extern UnkStruct_803643C8 *D_803643C8;
extern UnkStruct_803643C8 *D_803643CC;
extern s32 D_803EBBF8;
extern Vp D_802E8C60;
extern Gfx D_803650B0[];
extern Mtx D_803651F0;
extern Mtx D_80365230;
extern Mtx D_80365270;
extern Mtx D_803652B0;
extern Mtx D_803652F0;

void func_80284E54(Gfx *, s32, s32, s32, s32, s32);

u8 func_8027EED8(s32, s32, s16 *);
u8 func_802ABEDC(s32, s32, s32);

void func_80258230(u8 arg0, s32 arg1, s16 arg2, s16 arg3) {
    D_803643CC->unk1022 = arg0;
    D_803643CC->unk1023 = 0;
    D_803643CC->unk1000 = arg1;
    D_803643CC->unk1018 = arg2;
    D_803643CC->unk101A = arg3;
    D_803643CC->unk101C = 0;
    D_803643CC->unk101E = 0;
    D_803643CC->unk1020 = 0;
    D_803643CC++;
}

void func_802582C4(u8 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    u8 sp37;
    UnkStruct_803643C8 *sp30;
    u8 sp2F;
    u8 sp2E;
    u8 sp2D;
    s16 sp2A;
    s32 sp24;
    s32 sp20;
    s32 sp1C;

    sp37 = 0;
    sp2F = 0;
    sp2E = 0;
    if (arg0 == 9) {
        sp2F = func_802ABEDC(arg1, arg4, arg3);
        if (sp2F != 0) {
            sp2E = 1;
        }
        sp2D = func_8027EED8(arg1 >> 5, arg3 >> 5, &sp2A);
        if (sp2D != 0) {
            sp24 = arg4 - (sp2A << 5);
            sp1C = arg4 - arg2;
            if (sp2F != 0) {
                sp20 = arg4 - D_803EBBF8;
            } else {
                sp20 = 9999999;
            }
            if ((sp24 > 0) && (sp24 < sp20) && (sp24 < sp1C)) {
                D_803EBBF8 = sp2A << 5;
                sp2E = 2;
            }
        }
    }
    sp30 = D_803643C8;
    while (sp37 == 0) {
        if (sp30->unk1022 == arg0) {
            sp30->unk1004 = arg1;
            if (sp2E != 0) {
                sp30->unk1008 = D_803EBBF8;
            } else {
                sp30->unk1008 = arg2;
            }
            sp30->unk100C = arg3;
            sp30->unk1014 = arg2;
            sp30->unk101C = arg5;
            sp30->unk101E = arg7;
            sp30->unk1020 = arg6;
            sp30->unk1010 = arg4;
            sp30->unk1023 = sp2E;
            sp37 = 1;
        } else {
            sp30++;
        }
    }
}

s32 func_802584BC(u8 arg0) {
    UnkStruct_803643C8 *sp4 = D_803643C8;

    for (;;) {
        if (sp4->unk1022 == arg0) {
            return sp4->unk1008;
        }
        sp4++;
    }
}

s32 func_80258500(u8 arg0) {
    UnkStruct_803643C8 *sp4 = D_803643C8;

    for (;;) {
        if (sp4->unk1022 == arg0) {
            return sp4->unk1014;
        }
        sp4++;
    }
}

/*
 * Renders dl into a 64x64 8-bit image, seen from 45 degrees at distance
 * dist, looking at (x, y, z) / 32 in world units.
 */
void func_80258544(void *image, s32 x, s32 y, s32 z, f32 dist, Gfx *dl, void *seg6, void *seg7) {
    Gfx *gfx;
    u16 perspNorm;
    s32 unused;

    gfx = D_803650B0;
    gSPViewport(gfx++, K0_TO_PHYS(&D_802E8C60));
    gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
    gSPSegment(gfx++, 0, 0);
    gSPSegment(gfx++, 6, K0_TO_PHYS(seg6));
    gSPSegment(gfx++, 7, K0_TO_PHYS(seg7));
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 0, 0, 63, 63);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetColorDither(gfx++, G_CD_DISABLE);
    gDPSetCycleType(gfx++, G_CYC_FILL);
    gDPSetColorImage(gfx++, G_IM_FMT_CI, G_IM_SIZ_8b, 64, K0_TO_PHYS(image));
    gDPSetFillColor(gfx++, 0x00010001);
    gDPFillRectangle(gfx++, 0, 0, 63, 63);
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetRenderMode(gfx++, G_RM_PASS, GBL_c2(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1));
    gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    guPerspective(&D_803651F0, &perspNorm, 45.0f, 1.0f, 1.0f, 1000.0f, 1.0f);
    gSPMatrix(gfx++, K0_TO_PHYS(&D_803651F0), G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPPerspNormalize(gfx++, perspNorm);
    guTranslate(&D_803652F0, 0.0f, 0.0f, -dist);
    gSPMatrix(gfx++, K0_TO_PHYS(&D_803652F0), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    guRotate(&D_80365270, -90.0f, 1.0f, 0.0f, 0.0f);
    gSPMatrix(gfx++, K0_TO_PHYS(&D_80365270), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
    guRotate(&D_803652B0, 180.0f, 0.0f, 1.0f, 0.0f);
    gSPMatrix(gfx++, K0_TO_PHYS(&D_803652B0), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
    guTranslate(&D_80365230, -(x / 32.0f), -(y / 32.0f), -(z / 32.0f));
    gSPMatrix(gfx++, K0_TO_PHYS(&D_80365230), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
    gSPDisplayList(gfx++, K0_TO_PHYS(dl));
    gSPEndDisplayList(gfx++);
    osWritebackDCache(&D_803651F0, 5 * sizeof(Mtx));
    func_80284E54(D_803650B0, gfx - D_803650B0, 1, 0, 0x61F, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/13A70/func_80258B78.s")
