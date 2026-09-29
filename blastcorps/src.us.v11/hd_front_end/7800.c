#include "common.h"
#include "game/frame.h"
#include "game/audio.h"
#include "game/game.h"
#include "game/yoshi.h"
#include "game/level.h"
#include "game/player.h"

/* Per-frame buffer, double-buffered by D_8035805C. */
void func_801E8DCC(u8);
u8 func_801EEDB4(u8, u8, u8);
u8 func_801EF2BC(u16, u8, u8);
Gfx *func_801F4FBC(FrameBuf *, Gfx *);
void func_80260650(SndBank *, s32, s32);
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
extern Mtx D_802182D0[];
extern s32 D_802FA268;
extern FrameBuf D_803156F8[];
extern void *D_80358050[];
extern void *D_80358058;
extern u32 D_80358060;
extern void *D_8035806C;
extern s32 D_80358078;
extern u16 D_8035807C;
extern u8 D_803643D4;
extern u8 D_803643D5;
extern s32 D_803649F0;
extern char D_8036B980[];
extern char D_8036B9A8[];

/* .bss, 0x802159D0-0x80215A70 (tools/bss_c.py) */
u16 D_802159D0;
u8 *D_802159D4;
u8 *D_802159D8;
u16 D_802159DC;
f32 D_802159E0;
f32 D_802159E4;
u8 D_802159E8[8];
u8 D_802159F0[0x80];

u8 func_801EE800(u8 *arg0, u8 arg1, u8 arg2) {
    PlayerInfo *sp3C;
    LevelInfo *sp38;
    u32 sp34;
    u8 sp33;
    s32 sp2C;
    s32 sp28;

    sp3C = &D_80364AF0[D_80364AE8];
    sp38 = &D_802E8F94[D_802E8BDC];
    func_8029A7E4("new ip=%8d : tc=%5d : bd=%2d : cr=%2d : rt=%3d : coin=%1d : bdn=%1d\n", D_8036EA70.ip, D_8036EA70.tc, D_8036EA70.bd, D_8036EA70.cr,
                  D_8036EA70.rt, D_8036EA70.coin, D_8036EA70.bdn);
    func_8029A7E4("old ip=%8d : tc=%5d : bd=%2d : cr=%2d : rt=%3d : coin=%1d : bdn=%1d\n", D_8036EA60.ip, D_8036EA60.tc, D_8036EA60.bd, D_8036EA60.cr,
                  D_8036EA60.rt, D_8036EA60.coin, D_8036EA60.bdn);
    func_8029A7E4("res ip=%8d : tc=%5d : bd=%2d : cr=%2d : rt=%3d : coin=%1d : bdn=%1d\n", D_8036EA80.ip, D_8036EA80.tc, D_8036EA80.bd, D_8036EA80.cr,
                  D_8036EA80.rt, D_8036EA80.coin, D_8036EA80.bdn);
    func_8029A7E4("rs2 ip=%8d : tc=%5d : bd=%2d : cr=%2d : rt=%3d : coin=%1d : bdn=%1d\n", D_8036EA90.ip, D_8036EA90.tc, D_8036EA90.bd, D_8036EA90.cr,
                  D_8036EA90.rt, D_8036EA90.coin, D_8036EA90.bdn);
    func_8029A7E4("units %d\n", sp3C->units);
    if (D_802E8F94[D_802E8BDC].unk0 == 1) {
        sp34 = func_802852EC();
        if (arg2) {
            if (arg1) {
                if (sp34 >= 100) {
                    D_8036EA70.coin = 3;
                } else if (sp34 >= 90) {
                    D_8036EA70.coin = 2;
                } else if (sp34 >= 70) {
                    D_8036EA70.coin = 1;
                } else {
                    D_8036EA70.coin = 5;
                }
                if (D_803643D5 != 0) {
                    func_8029A7E4("Units up 3\n");
                    sp3C->units += 3;
                }
                D_8036EA70.bdn = 1;
            } else {
                D_8036EA70.coin = 0;
            }
        }
        sp33 = D_8036EA70.coin;
    } else {
        sp33 = func_801EEDB4(D_802E8BDC, arg1, arg2);
    }
    sprintf(D_8036B980, "%s", D_8020D810[D_802E8BDC].name);
    *arg0 = 0;
    if (arg1 && arg2) {
        if (DUMMY_LEVELS(D_802E8BDC)) {
            func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "!DUMMY_LEVELS(levelno)", "stats.c", 0x5E);
        }
        if (D_802E8F94[D_802E8BDC].unk0 == 1) {
            sp3C->unk14 = D_803649F0;
        }
        if (sp3C->units < 360) {
            func_8029A7E4("UNITS UP %d\n", D_8036EA70.coin % 5 - D_8036EA60.coin % 5);
            sp3C->units += D_8036EA70.coin % 5 - D_8036EA60.coin % 5;
        }
        if (sp3C->units == 354) {
            sp3C->units += 6;
        }
        if (sp3C->units / 12 > sp3C->unkC) {
            *arg0 = 1;
            sp3C->unkC++;
        }
        if (!(D_802E8F94[D_802E8BDC].unk0 & 0x81)) {
            sp3C->unk92[D_802E8BDC] = D_8036EA70.bdn;
        }
        D_80364EF0[D_80364AE8][D_802E8C44[D_8036EA70.bdn]] = D_8036EA70.tc;
        if (D_803643D5 != 0 && D_802E8F94[D_802E8BDC].unk0 == 1) {
            D_80364EF0[D_80364AE8][D_802E8C44[0]] = D_8036EA70.tc;
        }
        sp3C->medal[D_802E8BDC] = sp33;
        func_801E8DCC(D_80364AE8);
    }
    return sp33;
}

extern u16 D_80303B3C[];
extern u16 D_80303B48[];
extern u16 D_80303B58[];
extern u16 D_80303B68[];
/* .data, 0x802084D0-0x802084F0 (tools/data_c.py) */
char *D_802084D0[4] = { "YOUR NEW BEST!", "BEST TO DATE", "YOUR BEST STAYS", "GUEST BEST IS" };
u16 *D_802084E0[4] = { D_80303B3C, D_80303B48, D_80303B58, D_80303B68 };

u8 func_801EEDB4(u8 arg0, u8 arg1, u8 arg2) {
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    PlayerInfo *sp60;
    LevelInfo *sp5C;
    YoshiIcon *sp58;
    YoshiEntry *sp54;
    char sp34[0x20];
    u16 sp32;

    sp60 = &D_80364AF0[D_80364AE8];
    sp5C = &D_802E8F94[arg0];
    if (D_80364A98 == 0x08000000 && arg1 && sp5C->unk0 == 2) {
        func_80295A20(func_80286038(D_8036EA70.tc));
    }
    if (arg2 && arg1) {
        if (D_802E8F94[arg0].unk0 == 0x80) {
            D_8036EA70.bdn = 0;
        } else if (D_8036EA70.tc <= D_8036EA60.tc) {
            D_8036EA70.bdn = D_803643D4;
        } else if (D_8036EA70.tc != 0xFFFF) {
            if ((sp32 = D_80364EF0[D_80364AE8][D_802E8C44[D_803643D4]]) == 0 || D_8036EA70.tc < sp32) {
                D_80364EF0[D_80364AE8][D_802E8C44[D_803643D4]] = D_8036EA70.tc;
            }
        }
    }
    if (D_8036EA70.tc <= D_8036EA60.tc && arg1) {
        D_8036EA70.coin = func_801EF2BC(D_8036EA70.tc, arg0, D_80364AF0[D_80364AE8].gameState);
    } else {
        D_8036EA70.tc = D_8036EA60.tc;
    }
    if (D_8036EA70.tc < D_8036EA60.tc && D_803643D5 == 0) {
        sp6C = 0x484;
        if (arg2) {
            sp6C = 0x584;
        }
    } else {
        sp6C = 0x480;
    }
    func_80264A34(sp34, D_8036EA70.tc, 0);
    sprintf(D_8036B9A8 + 0x80, "****%s*", sp34);
    if (arg1) {
        sp54 = &D_8020C070[25];
        D_8020C070[25].flags = sp6C;
        func_8029A7E4("getting icon %d\n", D_8036EA70.bdn);
        sp54->unk14 = D_8036EA70.bdn + 0x22;
        sp58 = &D_802F49F4[sp54->unk14];
        sp54->unk1A = func_80272C5C((u16 *)sp58->unk6, NULL, sp58->unk4, sp58->unk2C, sp58->unk2D | 4, 1.0f);
        if (D_80364AE8 != D_80364AEA) {
            sp64 = 3;
        } else if (D_80364A98 == 0x80 || D_803643D5 != 0) {
            sp64 = 1;
        } else if (D_8036EA70.tc < D_8036EA60.tc) {
            sp64 = 0;
        } else {
            sp64 = 2;
        }
        D_8020C070[24].text = D_802084D0[sp64];
        D_8020C070[24].unk10 = D_802084E0[sp64];
    }
    return D_8036EA70.coin;
}

/* Nothing references these; the original .rodata has 12 zero bytes here. */
const char D_8020EFA4[12] = { 0 };

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
    LevelInfo *sp0;

    sp0 = &D_802E8F94[arg1];
    if (sp0->medalTimes[0] >= arg0 && arg2 >= 12) {
        sp7 = 4;
    } else if (sp0->medalTimes[1] >= arg0) {
        sp7 = 3;
    } else if (sp0->medalTimes[2] >= arg0) {
        sp7 = 2;
    } else if (sp0->medalTimes[3] >= arg0) {
        sp7 = 1;
    } else {
        sp7 = 5;
    }
    return sp7;
}

extern u8 D_0048F5A0[];
extern u8 D_0048F970[];
extern u8 D_0048F970_2[]; /* same address as D_0048F970: see undefined_syms */
extern u8 D_0048FA70[];
void func_801F4E70(s32);
void func_8028B4C4(u8 *romStart, u8 *dst, u32 *size, u8, u8, u8);

void func_801EF380(s32 arg0) {
    u32 sp24;
    u32 sp20;

    sp24 = D_0048F970 - D_0048F5A0;
    sp20 = D_0048FA70 - D_0048F970_2;
    func_801F4E70(arg0);
    if (arg0 == 2) {
        D_802159D0 = 90;
    } else {
        D_802159D0 = 0;
    }
    func_8028B4C4(D_0048F5A0, D_80358070, &sp24, 12, 0, 1);
    D_802159D4 = D_80358070;
    D_80358070 += sp24;
    func_8028B4C4(D_0048F970, D_80358070, &sp20, 12, 0, 1);
    D_802159D8 = D_80358070;
    D_80358070 += sp20;
    D_802159DC = arg0;
    D_802159E0 = 0.0f;
    D_802159E4 = 3.0f;
}

void func_801EF4AC(void) {
    FrameBuf *sp12C;
    Gfx *gfx;
    s32 sp124;
    s32 sp120;
    s32 sp11C;
    s16 sp11A;

    sp12C = &D_803156F8[D_8035805C ^ 1];
    gfx = sp12C->dl;
    func_8028A470();
    func_80284E54(D_803156F8[D_8035805C].dl, D_80358078, 1, 1, 0x4D2, 0);
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
        guPerspective(&sp12C->mtx[73], &D_8035807C, 45.0f, 4.0f / 3.0f, 40.0f, 8000.0f, 0.25f);
        if (D_802159DC == 1) {
            guTranslate(&sp12C->mtx[74], 0.0f, -130.0f, 0.0f);
            guRotate(&sp12C->mtx[75], 35.0f, 0.1f, 0.0f, 0.0f);
        } else {
            guTranslate(&sp12C->mtx[74], 0.0f, 0.0f, 0.0f);
            guRotate(&sp12C->mtx[75], -10.0f, 0.1f, 0.0f, 0.0f);
        }
    }
    if (D_80358060 >= 20) {
        if (D_80358060 == 20 && D_802159DC == 1) {
            func_80260650(D_80367738, 0xBA, 0);
        } else if (D_80358060 == 20 && D_802159DC == 2) {
            func_80260650(D_80367738, 0xBD, 0);
        }
        if (D_80358060 < 80) {
            D_802159E0 = (80 - D_80358060) * 7600.0 / 60.0 + 400.0;
        }
        if (D_80358060 == 75 && D_802159DC == 2) {
            func_80260650(D_80367738, 0xB8, 0);
        } else if (D_80358060 == 75 && D_802159DC == 1) {
            func_80260650(D_80367738, 0xBB, 0);
        }
        guLookAtReflect(&sp12C->mtx[5], &sp12C->lookAt, 1.0f, 0.0f, D_802159E0, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
        D_802159D0 += D_802159E4;
        guRotate(&D_802182D0[D_8035805C], D_802159D0 % 360, 0.0f, 1.0f, 0.0f);
        guScale(&sp12C->mtx[76], 1.5f, 1.5f, 1.5f);
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
    D_80358078 = gfx - sp12C->dl;
}
