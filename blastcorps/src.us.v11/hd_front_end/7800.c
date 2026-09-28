#include "common.h"

/* Per-frame buffer, double-buffered by D_8035805C. */
typedef struct {
    /* 0x00000 */ u8 unk0[0x140];
    /* 0x00140 */ Mtx unk140;
    /* 0x00180 */ u8 unk180[0x10C0];
    /* 0x01240 */ Mtx unk1240;
    /* 0x01280 */ Mtx unk1280;
    /* 0x012C0 */ Mtx unk12C0;
    /* 0x01300 */ Mtx unk1300;
    /* 0x01340 */ u8 unk1340[0x28C0];
    /* 0x03C00 */ LookAt unk3C00;
    /* 0x03C20 */ u8 unk3C20[0xC90];
    /* 0x048B0 */ Gfx unk48B0[0x397D];
} UnkStruct_803156F8; /* size = 0x21498 */

typedef struct {
    /* 0x00 */ u8 unk0[0xA];
    /* 0x0A */ u16 unkA;
    /* 0x0C */ u8 unkC;
    /* 0x0D */ u8 unkD[7];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ u8 unk18[0x3C];
    /* 0x54 */ u8 unk54[0x3D];
    /* 0x91 */ u8 unk91;
    /* 0x92 */ u8 unk92[0x6E];
} UnkStruct_80364AF0; /* size = 0x100 */

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1[0x2F];
    /* 0x30 */ u16 unk30;
    /* 0x32 */ u16 unk32;
    /* 0x34 */ u16 unk34;
    /* 0x36 */ u16 unk36;
    /* 0x38 */ u8 unk38[0xC];
} UnkStruct_802E8F94; /* size = 0x44 */

typedef struct {
    /* 0x00 */ u8 unk0[4];
    /* 0x04 */ char *unk4;
    /* 0x08 */ u8 unk8[0x10];
    /* 0x18 */ s8 unk18[0x18];
} UnkStruct_8020D810; /* size = 0x30 */

/* 0x1C-byte records; hd_code walks the same array through D_8036BB10. */
typedef struct {
    /* 0x00 */ u16 unk0;
    /* 0x02 */ u8 unk2[0xA];
    /* 0x0C */ char *unkC;
    /* 0x10 */ u16 *unk10;
    /* 0x14 */ u8 unk14[6];
    /* 0x1A */ s8 unk1A;
    /* 0x1B */ u8 unk1B;
} UnkStruct_8020C070; /* size = 0x1C */

typedef struct {
    /* 0x00 */ u8 unk0[4];
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u16 unk6[0x13];
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ u8 unk2D;
    /* 0x2E */ s8 unk2E;
    /* 0x2F */ u8 unk2F;
} UnkStruct_802F49F4; /* size = 0x30 */

void func_801E8DCC(u8);
u8 func_801EEDB4(u8, u8, u8);
u8 func_801EF2BC(u16, u8, u8);
Gfx *func_801F4FBC(UnkStruct_803156F8 *, Gfx *);
void func_80260650(s32, s32, s32);
void func_80264A34(char *, u16, s32);
u8 func_80272C5C(u16 *, u16 *, u8, u8, u8, f32);
void func_80284E54(Gfx *, s32, s32, s32, s32, s32);
u32 func_802852EC(void);
s32 func_80286038(u16);
void func_8028A3E4(void);
void func_8028A470(void);
void func_80295A20(s32);
void func_8029A7E4(char *, ...);

extern Gfx D_01000010[];
extern Gfx D_01000038[];
extern char *D_802084D0[];
extern u16 *D_802084E0[];
extern UnkStruct_8020C070 D_8020C070[];
extern UnkStruct_8020D810 D_8020D810[];
extern char D_8020EDB0[];
extern char D_8020EDF8[];
extern char D_8020EE40[];
extern char D_8020EE88[];
extern char D_8020EED0[];
extern char D_8020EEDC[];
extern char D_8020EEE8[];
extern char D_8020EEEC[];
extern char D_8020EF18[];
extern char D_8020EF30[];
extern char D_8020EF38[];
extern char D_8020EF88[];
extern char D_8020EF90[];
extern f64 D_8020EFB0;
extern u16 D_802159D0;
extern u8 *D_802159D4;
extern u8 *D_802159D8;
extern u16 D_802159DC;
extern f32 D_802159E0;
extern f32 D_802159E4;
extern Mtx D_802182D0[];
extern s32 D_802E8BDC;
extern u8 D_802E8C44[];
extern UnkStruct_802E8F94 D_802E8F94[];
extern UnkStruct_802F49F4 D_802F49F4[];
extern s32 D_802FA268;
extern UnkStruct_803156F8 D_803156F8[];
extern void *D_80358050[];
extern void *D_80358058;
extern u8 D_8035805C;
extern u32 D_80358060;
extern void *D_8035806C;
extern s32 D_80358078;
extern u16 D_8035807C;
extern u8 D_803643D4;
extern u8 D_803643D5;
extern s32 D_803649F0;
extern u64 D_80364A90;
extern u64 D_80364A98;
extern u8 D_80364AE8;
extern u8 D_80364AEA;
extern UnkStruct_80364AF0 D_80364AF0[];
extern u16 D_80364EF0[][16];
extern s32 D_80367738;
extern char D_8036B980[];
extern char D_8036B9A8[];
extern u32 D_8036EA60;
extern u32 D_8036EA64;
extern u8 D_8036EA68;
extern u8 D_8036EA69;
extern u8 D_8036EA6A;
extern u8 D_8036EA6B;
extern u16 D_8036EA6C;
extern u32 D_8036EA70;
extern u32 D_8036EA74;
extern u8 D_8036EA78;
extern u8 D_8036EA79;
extern u8 D_8036EA7A;
extern u8 D_8036EA7B;
extern u16 D_8036EA7C;
extern u32 D_8036EA80;
extern u32 D_8036EA84;
extern u8 D_8036EA88;
extern u8 D_8036EA89;
extern u8 D_8036EA8A;
extern u8 D_8036EA8B;
extern u16 D_8036EA8C;
extern u32 D_8036EA90;
extern u32 D_8036EA94;
extern u8 D_8036EA98;
extern u8 D_8036EA99;
extern u8 D_8036EA9A;
extern u8 D_8036EA9B;
extern u16 D_8036EA9C;

u8 func_801EE800(u8 *arg0, u8 arg1, u8 arg2) {
    UnkStruct_80364AF0 *sp3C;
    UnkStruct_802E8F94 *sp38;
    u32 sp34;
    u8 sp33;
    s32 sp2C;
    s32 sp28;

    sp3C = &D_80364AF0[D_80364AE8];
    sp38 = &D_802E8F94[D_802E8BDC];
    func_8029A7E4(D_8020EDB0, D_8036EA70, D_8036EA74, D_8036EA78, D_8036EA79,
                  D_8036EA7C, D_8036EA7A, D_8036EA7B);
    func_8029A7E4(D_8020EDF8, D_8036EA60, D_8036EA64, D_8036EA68, D_8036EA69,
                  D_8036EA6C, D_8036EA6A, D_8036EA6B);
    func_8029A7E4(D_8020EE40, D_8036EA80, D_8036EA84, D_8036EA88, D_8036EA89,
                  D_8036EA8C, D_8036EA8A, D_8036EA8B);
    func_8029A7E4(D_8020EE88, D_8036EA90, D_8036EA94, D_8036EA98, D_8036EA99,
                  D_8036EA9C, D_8036EA9A, D_8036EA9B);
    func_8029A7E4(D_8020EED0, sp3C->unkA);
    if (D_802E8F94[D_802E8BDC].unk0 == 1) {
        sp34 = func_802852EC();
        if (arg2) {
            if (arg1) {
                if (sp34 >= 100) {
                    D_8036EA7A = 3;
                } else if (sp34 >= 90) {
                    D_8036EA7A = 2;
                } else if (sp34 >= 70) {
                    D_8036EA7A = 1;
                } else {
                    D_8036EA7A = 5;
                }
                if (D_803643D5 != 0) {
                    func_8029A7E4(D_8020EEDC);
                    sp3C->unkA += 3;
                }
                D_8036EA7B = 1;
            } else {
                D_8036EA7A = 0;
            }
        }
        sp33 = D_8036EA7A;
    } else {
        sp33 = func_801EEDB4(D_802E8BDC, arg1, arg2);
    }
    sprintf(D_8036B980, D_8020EEE8, D_8020D810[D_802E8BDC].unk4);
    *arg0 = 0;
    if (arg1 && arg2) {
        if (D_802E8BDC == 0x31 || D_802E8BDC == 0x2F || D_802E8BDC == 0x26) {
            func_8029A7E4(D_8020EEEC, D_8020EF18, D_8020EF30, 0x5E);
        }
        if (D_802E8F94[D_802E8BDC].unk0 == 1) {
            sp3C->unk14 = D_803649F0;
        }
        if (sp3C->unkA < 360) {
            func_8029A7E4(D_8020EF38, D_8036EA7A % 5 - D_8036EA6A % 5);
            sp3C->unkA += D_8036EA7A % 5 - D_8036EA6A % 5;
        }
        if (sp3C->unkA == 354) {
            sp3C->unkA += 6;
        }
        if (sp3C->unkA / 12 > sp3C->unkC) {
            *arg0 = 1;
            sp3C->unkC++;
        }
        if (!(D_802E8F94[D_802E8BDC].unk0 & 0x81)) {
            sp3C->unk92[D_802E8BDC] = D_8036EA7B;
        }
        D_80364EF0[D_80364AE8][D_802E8C44[D_8036EA7B]] = D_8036EA74;
        if (D_803643D5 != 0 && D_802E8F94[D_802E8BDC].unk0 == 1) {
            D_80364EF0[D_80364AE8][D_802E8C44[0]] = D_8036EA74;
        }
        sp3C->unk18[D_802E8BDC] = sp33;
        func_801E8DCC(D_80364AE8);
    }
    return sp33;
}

u8 func_801EEDB4(u8 arg0, u8 arg1, u8 arg2) {
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    UnkStruct_80364AF0 *sp60;
    UnkStruct_802E8F94 *sp5C;
    UnkStruct_802F49F4 *sp58;
    UnkStruct_8020C070 *sp54;
    char sp34[0x20];
    u16 sp32;

    sp60 = &D_80364AF0[D_80364AE8];
    sp5C = &D_802E8F94[arg0];
    if (D_80364A98 == 0x08000000 && arg1 && sp5C->unk0 == 2) {
        func_80295A20(func_80286038(D_8036EA74));
    }
    if (arg2 && arg1) {
        if (D_802E8F94[arg0].unk0 == 0x80) {
            D_8036EA7B = 0;
        } else if (D_8036EA74 <= D_8036EA64) {
            D_8036EA7B = D_803643D4;
        } else if (D_8036EA74 != 0xFFFF) {
            if ((sp32 = D_80364EF0[D_80364AE8][D_802E8C44[D_803643D4]]) == 0 || D_8036EA74 < sp32) {
                D_80364EF0[D_80364AE8][D_802E8C44[D_803643D4]] = D_8036EA74;
            }
        }
    }
    if (D_8036EA74 <= D_8036EA64 && arg1) {
        D_8036EA7A = func_801EF2BC(D_8036EA74, arg0, D_80364AF0[D_80364AE8].unk91);
    } else {
        D_8036EA74 = D_8036EA64;
    }
    if (D_8036EA74 < D_8036EA64 && D_803643D5 == 0) {
        sp6C = 0x484;
        if (arg2) {
            sp6C = 0x584;
        }
    } else {
        sp6C = 0x480;
    }
    func_80264A34(sp34, D_8036EA74, 0);
    sprintf(D_8036B9A8 + 0x80, D_8020EF88, sp34);
    if (arg1) {
        sp54 = &D_8020C070[25];
        D_8020C070[25].unk0 = sp6C;
        func_8029A7E4(D_8020EF90, D_8036EA7B);
        sp54->unk14[0] = D_8036EA7B + 0x22;
        sp58 = &D_802F49F4[sp54->unk14[0]];
        sp54->unk1A = func_80272C5C(sp58->unk6, NULL, sp58->unk4, sp58->unk2C, sp58->unk2D | 4, 1.0f);
        if (D_80364AE8 != D_80364AEA) {
            sp64 = 3;
        } else if (D_80364A98 == 0x80 || D_803643D5 != 0) {
            sp64 = 1;
        } else if (D_8036EA74 < D_8036EA64) {
            sp64 = 0;
        } else {
            sp64 = 2;
        }
        D_8020C070[24].unkC = D_802084D0[sp64];
        D_8020C070[24].unk10 = D_802084E0[sp64];
    }
    return D_8036EA7A;
}

s8 func_801EF1E0(void) {
    UnkStruct_8020D810 *spC;
    s32 sp8;
    s32 sp4;

    spC = &D_8020D810[D_802E8BDC];
    if (spC->unk18[0] == -1) {
        return -1;
    }
    for (sp8 = 0, sp4 = 0; spC->unk18[sp8] != -1 && sp8 < 2; sp8++) {
        if (D_80364AF0[D_80364AE8].unk54[D_802E8BDC] & (1 << sp8)) {
            sp4++;
        }
    }
    return sp4;
}

u8 func_801EF2BC(u16 arg0, u8 arg1, u8 arg2) {
    u8 sp7;
    UnkStruct_802E8F94 *sp0;

    sp0 = &D_802E8F94[arg1];
    if (sp0->unk30 >= arg0 && arg2 >= 12) {
        sp7 = 4;
    } else if (sp0->unk32 >= arg0) {
        sp7 = 3;
    } else if (sp0->unk34 >= arg0) {
        sp7 = 2;
    } else if (sp0->unk36 >= arg0) {
        sp7 = 1;
    } else {
        sp7 = 5;
    }
    return sp7;
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_front_end/7800/func_801EF380.s")

void func_801EF4AC(void) {
    UnkStruct_803156F8 *sp12C;
    Gfx *gfx;
    s32 sp124;
    s32 sp120;
    s32 sp11C;
    s16 sp11A;

    sp12C = &D_803156F8[D_8035805C ^ 1];
    gfx = sp12C->unk48B0;
    func_8028A470();
    func_80284E54(D_803156F8[D_8035805C].unk48B0, D_80358078, 1, 1, 0x4D2, 0);
    D_8035805C ^= 1;
    gSPSegment(gfx++, 0, 0);
    gSPSegment(gfx++, 2, osVirtualToPhysical(sp12C));
    gSPSegment(gfx++, 1, osVirtualToPhysical(D_8035806C));
    gSPDisplayList(gfx++, D_01000038);
    gSPDisplayList(gfx++, D_01000010);
    gDPSetCycleType(gfx++, G_CYC_FILL);
    gDPSetDepthImage(gfx++, D_80358058);
    gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, D_80358058);
    gDPSetFillColor(gfx++, 0xFFFCFFFC);
    gDPFillRectangle(gfx++, 0, 0, 319, 239);
    gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, D_80358050[D_8035805C]);
    gDPPipeSync(gfx++);
    if (D_802159DC == 1) {
        if (D_80358060 * 185 / 20 > 185) {
            sp11A = 185;
        } else {
            sp11A = D_80358060 * 185 / 20;
        }
    } else {
        sp11A = 0;
    }
    gDPSetFillColor(gfx++, (GPACK_RGBA5551(sp11A, sp11A, sp11A, 1) << 16) | GPACK_RGBA5551(sp11A, sp11A, sp11A, 1));
    gDPFillRectangle(gfx++, 0, 0, 319, 239);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    func_8028A3E4();
    if (D_80358060 == 250) {
        if (D_80364A90 == 0x10) {
            D_80364A98 = 0x20;
        } else {
            D_80364A98 = 0x0400000000000000;
            if (D_802FA268 != 0) {
                func_80260650(D_80367738, 0x68, 0);
            }
        }
    }
    if (D_80358060 < 2) {
        guPerspective(&sp12C->unk1240, &D_8035807C, 45.0f, 4.0f / 3.0f, 40.0f, 8000.0f, 0.25f);
        if (D_802159DC == 1) {
            guTranslate(&sp12C->unk1280, 0.0f, -130.0f, 0.0f);
            guRotate(&sp12C->unk12C0, 35.0f, 0.1f, 0.0f, 0.0f);
        } else {
            guTranslate(&sp12C->unk1280, 0.0f, 0.0f, 0.0f);
            guRotate(&sp12C->unk12C0, -10.0f, 0.1f, 0.0f, 0.0f);
        }
    }
    if (D_80358060 >= 20) {
        if (D_80358060 == 20 && D_802159DC == 1) {
            func_80260650(D_80367738, 0xBA, 0);
        } else if (D_80358060 == 20 && D_802159DC == 2) {
            func_80260650(D_80367738, 0xBD, 0);
        }
        if (D_80358060 < 80) {
            D_802159E0 = (80 - D_80358060) * D_8020EFB0 / 60.0 + 400.0;
        }
        if (D_80358060 == 75 && D_802159DC == 2) {
            func_80260650(D_80367738, 0xB8, 0);
        } else if (D_80358060 == 75 && D_802159DC == 1) {
            func_80260650(D_80367738, 0xBB, 0);
        }
        guLookAtReflect(&sp12C->unk140, &sp12C->unk3C00, 1.0f, 0.0f, D_802159E0, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
        D_802159D0 += D_802159E4;
        guRotate(&D_802182D0[D_8035805C], D_802159D0 % 360, 0.0f, 1.0f, 0.0f);
        guScale(&sp12C->unk1300, 1.5f, 1.5f, 1.5f);
        gDPSetRenderMode(gfx++, G_RM_AA_ZB_OPA_INTER, G_RM_NOOP2);
        gfx = func_801F4FBC(sp12C, gfx);
    }
    if (D_80358060 > 80 && D_802159DC == 1) {
        gDPPipeSync(gfx++);
        gSPTexture(gfx++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
        gDPSetTexturePersp(gfx++, G_TP_NONE);
        gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineMode(gfx++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetPrimColor(gfx++, 0, 0, 0x28, 0x00, 0xFF, (D_80358060 * 6 - 480 < 255) ? D_80358060 * 6 - 480 : 255);
        sp120 = 26, sp11C = 42;
        for (sp124 = 0; sp124 < 256; sp124 += 32) {
            gDPLoadTextureTile(gfx++, D_802159D4, G_IM_FMT_IA, G_IM_SIZ_8b, 256, 0, sp124, 0, sp124 + 31, 31, 0,
                               G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gfx++, (sp124 + sp120) << 2, sp11C << 2, (sp124 + sp120 + 32) << 2, (sp11C + 32) << 2,
                                G_TX_RENDERTILE, sp124 << 5, 0, 1 << 10, 1 << 10);
        }
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0xFF, 0x00, 0x28, (D_80358060 * 4 - 320 < 255) ? D_80358060 * 4 - 320 : 255);
        gDPLoadTextureBlock(gfx++, D_802159D8, G_IM_FMT_IA, G_IM_SIZ_8b, 40, 24, 0, G_TX_CLAMP, G_TX_CLAMP,
                            G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gfx++, 256 << 2, 20 << 2, 296 << 2, 44 << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
        gDPSetTexturePersp(gfx++, G_TP_PERSP);
    }
    if (D_80358060 >= 221) {
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, (D_80358060 - 220) * 255 / 30);
        gDPFillRectangle(gfx++, 0, 0, 319, 239);
    }
    gDPFullSync(gfx++);
    gSPEndDisplayList(gfx++);
    D_80358078 = gfx - sp12C->unk48B0;
}
