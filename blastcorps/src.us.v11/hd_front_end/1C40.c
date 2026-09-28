#include "common.h"

typedef struct {
    /* 0x00 */ u8 unk0[8];
    /* 0x08 */ s8 unk8;
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u16 unkA;
    /* 0x0C */ u8 unkC;
    /* 0x0D */ u8 unkD[3];
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ u8 unk18[0x79];
    /* 0x91 */ u8 unk91;
    /* 0x92 */ u8 unk92[0x6E];
} UnkStruct_80364AF0; /* size = 0x100 */

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1[0x2F];
    /* 0x30 */ u16 unk30[4];
    /* 0x38 */ u8 unk38[0xC];
} UnkStruct_802E8F94; /* size = 0x44 */

typedef struct {
    /* 0x00000 */ u8 unk0[0x80];
    /* 0x00080 */ Mtx unk80;
    /* 0x000C0 */ u8 unkC0[0xC0];
    /* 0x00180 */ Mtx unk180;
    /* 0x001C0 */ u8 unk1C0[0x400];
    /* 0x005C0 */ Mtx unk5C0;
    /* 0x00600 */ u8 unk600[0x1800];
    /* 0x01E00 */ Vtx unk1E00[0x1E0];
    /* 0x03C00 */ u8 unk3C00[0x1D898];
} UnkStruct_803156F8; /* size = 0x21498 */

typedef struct {
    /* 0x00 */ char *unk0[4];
} UnkStruct_80208358; /* size = 0x10 */

typedef struct {
    /* 0x0 */ u8 unk0[5];
} UnkStruct_8020849C; /* size = 0x5 */

/* 0x1C-byte records; hd_code walks the same array through D_8036BB10. */
typedef struct {
    /* 0x00 */ u16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ u16 unk6;
    /* 0x08 */ u16 unk8;
    /* 0x0A */ u8 unkA[2];
    /* 0x0C */ char *unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ u8 unk14[4];
    /* 0x18 */ u8 unk18;
    /* 0x19 */ u8 unk19;
    /* 0x1A */ u8 unk1A[2];
} UnkStruct_8020C070; /* size = 0x1C */

typedef struct {
    /* 0x00 */ u8 unk0[8];
    /* 0x08 */ s32 unk8;
    /* 0x0C */ u8 unkC[0xC];
    /* 0x18 */ s16 unk18;
    /* 0x1A */ u8 unk1A[2];
} UnkStruct_802F8BDC; /* size = 0x1C */

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 unk7;
} UnkStruct_802F47B0; /* size = 0x8 */

void func_801E8DCC(u8);
void func_801E8EB8(u8, u8);
void func_801E93DC(u8);
u16 func_801E9528(void);
void func_801EA268(UnkStruct_80364AF0 *);
Gfx *func_801EC49C(Gfx *, s32, s32, u8);
void func_801ED480(u8 *, u8 *);
u8 func_801EF2BC(u16, u8, u8);
void func_801F8354(u8);
void func_801FE018(s32);
void func_80259BD4(Gfx **, UnkStruct_803156F8 *);
void func_80259CCC(s32, char *, u16 *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_80259DC8(s32, char *, u16 *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_8025B300(u8 *);
s32 func_8025B370(u16 *);
s32 func_8025B3F0(u8 *, u8 *);
char *func_8025B558(u16 *);
void func_80260650(s32, s32, s32);
void func_80261570(f32);
void func_80264A34(char *, u16, s32);
void func_8026AF6C(s32);
u8 func_80272C5C(u16 *, u16 *, u8, u8, u8, f32);
Gfx *func_80272ED8(Gfx *, u8, s16, s16, u8, u8, f32);
Gfx *func_80274868(Gfx *);
Gfx *func_80274AA4(Gfx *);
void func_80275270(u64, f32);
s32 func_802753C0(void);
Gfx *func_80275DA4(Gfx *, u8);
s32 func_80276080(UnkStruct_803156F8 *, u8, s32, s32, s32, s32, s32, u8, u8, u8, u8);
s32 func_80276130(UnkStruct_803156F8 *, u8, s32, s32, s32, s32, s32, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8,
                  u8, u8, u8, u8);
void func_8029A7E4(char *, ...);

extern char *D_802081C0[][2];
extern u16 D_802082D8[];
extern u16 D_802082E4[];
extern u16 D_802082E8[];
extern u16 D_802082EC[];
extern u16 D_802082F8[];
extern u8 D_802082FC[];
extern u8 D_80208314[];
extern u32 D_80208350[];
extern UnkStruct_80208358 D_80208358;
extern UnkStruct_80208358 D_80208368;
extern char *D_80208378[];
extern Vtx D_80208380[];
extern Gfx D_80208400[];
extern Lights2 D_80208448;
extern u8 D_80208498[];
extern UnkStruct_8020849C D_8020849C;
extern UnkStruct_8020C070 D_8020C070[];
extern f32 D_80215440;
extern f32 D_80215444;
extern f32 D_80215448;
extern f32 D_8021544C;
extern f32 D_80215450;
extern f32 D_80215454;
extern s32 D_80215458;
extern f32 D_8021545C;
extern f32 D_80215460;
extern f32 D_80215464;
extern f32 D_80215468;
extern s16 D_8021546C;
extern char D_80215470[];
extern char D_80215480[][0x10];
extern u8 D_802154B0;
extern s16 D_802154B2;
extern s16 D_802154B4;
extern s16 D_802154B6;
extern s16 D_802154B8;
extern s16 D_802154BA;
extern u8 D_802154BC;
extern s16 D_802154BE;
extern s16 D_802154C0;
extern s32 D_802154C4;
extern s32 D_802154C8;
extern s32 D_802154CC;
extern u8 D_802154D0;
extern s16 D_802154D2;
extern s16 D_802154D4;
extern s32 D_802154D8;
extern s32 D_802154DC;
extern f32 D_802154E0;
extern f32 D_802154E4;
extern s32 D_802154E8;
extern s32 D_802154EC;
extern s32 D_802154F0[];
extern s32 D_80215508[];
extern char D_80215520[][0x19];
extern u8 D_802155A0[];
extern u16 *D_802158A0;
extern u16 D_802158A8[];
extern u8 D_80215900[];
extern u8 D_80215902[];
extern s32 D_80215908[];
extern s16 D_80215910[];
extern u8 D_80215914;
extern u8 D_80215915;
extern u8 D_80215916;
extern s16 D_80215918;
extern s16 D_8021591A;
extern u16 D_8021591C;
extern s32 D_80215920;
extern u8 D_80215924;
extern char *D_80215928;
extern s16 D_8021592C;
extern u8 D_8021592E;
extern u16 D_80215930[];
extern s16 D_8021593C;
extern s32 D_80215940;
extern f32 D_80215944;
extern f32 D_80215948;
extern f32 D_8021594C;
extern f32 D_80215950;
extern OSMesgQueue D_80219EF8;
extern OSMesgQueue D_80219F50;
extern s32 D_802E8BDC;
extern u8 D_802E8BF8;
extern u8 D_802E8C44[];
extern u16 D_802E8C94[];
extern u16 D_802E8C98[];
extern UnkStruct_802E8F94 D_802E8F94[];
extern UnkStruct_802F47B0 D_802F47B0[];
extern UnkStruct_802F8BDC D_802F8BDC[];
extern char D_803046F8[];
extern char D_80304710[];
extern char D_80304730[];
extern u32 D_803156C4;
extern UnkStruct_803156F8 D_803156F8[];
extern s8 D_803643D5;
extern s8 D_80364A87;
extern u64 D_80364A90;
extern u64 D_80364A98;
extern s32 D_80364AA8;
extern u8 D_80364AE8;
extern u8 D_80364AEA;
extern UnkStruct_80364AF0 D_80364AF0[];
extern u16 D_80364EF0[][16];
extern u8 D_80365060[];
extern s32 D_80367738;
extern s16 D_8036BB1C;
extern s16 D_8036BB20;
extern u16 D_80370C28;
extern u16 D_80370C2A;
extern s8 D_80370C2C;
extern u8 D_8039C538;
extern u8 D_8039C53C[];
extern u8 D_8039C540;

void func_801E8C40(u8 arg0) {
    UnkStruct_803156F8 *sp34;
    s32 sp30;

    D_80364AE8 = arg0;
    D_80215915 = func_80272C5C(D_802082F8, NULL, 1, 1, 1, 1.0f);
    D_80215916 = func_80272C5C(D_802082EC, NULL, 5, 1, 0, 1.0f);
    for (sp30 = 0; sp30 < 2; sp30++) {
        sp34 = &D_803156F8[sp30];
        guPerspective(&sp34->unk80, &D_8021591C, 45.0f, 4.0f / 3.0f, 10.0f, 1e+04f, 1.0f);
        guLookAt(&sp34->unk180, 0.0f, 277.0f, 480.0f, 0.0f, 189.0f, 200.0f, 0.0f, 0.0f, 1.0f);
        guTranslate(&sp34->unk5C0, 0.0f, 88.0f, 0.0f);
    }
    D_8021593C = 0;
    func_801E8DCC(D_80364AE8);
}

void func_801E8DCC(u8 arg0) {
    s32 sp1C;

    func_801E8EB8(arg0, 0);
    for (sp1C = 0; sp1C < 0x1B; sp1C++) {
        D_802158A8[sp1C] = D_802E8C94[D_8021592E];
    }
    D_802158A8[sp1C] = D_802E8C98[D_8021592E];
    D_802154D8 = 0;
    D_802154E8 = 9999;
    for (sp1C = 1; sp1C < 5; sp1C++) {
        D_802154F0[sp1C] = 9999;
    }
    D_802154E4 = 3.0f;
}

const char D_8020E4D0[] = "ROOKIE WRECKER";

const char D_8020E4E0[] = "TRAINED CRUSHER";

const char D_8020E4F0[] = "EXPERIENCED RAVAGER";

const char D_8020E504[] = "DECORATED DAMAGER";

const char D_8020E518[] = "PROFESSIONAL RAZER";

const char D_8020E52C[] = "EXPERT DESTROYER";

const char D_8020E540[] = "GIFTED RUINER";

const char D_8020E550[] = "ACCOMPLISHED CONQUEROR";

const char D_8020E568[] = "MASTER DESPOILER";

const char D_8020E57C[] = "DEMOLITION FANATIC";

const char D_8020E590[] = "GRAND ERADICATOR";

const char D_8020E5A4[] = "HEAVY DUTY WASTER";

const char D_8020E5B8[] = "TOTAL PULVERISER";

const char D_8020E5CC[] = "CHAMPION RANSACKER";

const char D_8020E5E0[] = "MECHANICAL MAESTRO";

const char D_8020E5F4[] = "CHIEF OBLITERATOR";

const char D_8020E608[] = "COMMANDING DESOLATOR";

const char D_8020E620[] = "SUPREME DEVASTATOR";

const char D_8020E634[] = "ULTIMATE ANNIHILATOR";

const char D_8020E64C[] = "LEVELING LEGEND";

const char D_8020E65C[] = "DESTRUCTIVE PSYCHOPATH";

const char D_8020E674[] = "MINDLESS DESECRATOR";

const char D_8020E688[] = "HYSTERICAL CLAUSTROPHOBE";

const char D_8020E6A4[] = "UNCONTROLLABLE MADMAN";

const char D_8020E6BC[] = "WORLD CLASS MEGALOMANIAC";

const char D_8020E6D8[] = "CAPTAIN OF CARNAGE";

const char D_8020E6EC[] = "SINGLE MINDED CHAOSMONGER";

const char D_8020E708[] = "GRAND HIGH SLAUGHTERMASTER";

const char D_8020E724[] = "LUNATIC LORD OF HAVOC";

const char D_8020E73C[] = "ARMAGEDDON ADEPT";

const char D_8020E750[] = "YOU CAN STOP NOW.";

const char D_8020E764[] = "";

const char D_8020E768[] = "GUEST: ";

const char D_8020E770[] = ".................... LEADER OF THE ARMY BASE WALKOUT YEARS AGO. AMBER'S SHARP MIND AND BRIGHT, SELFLESS OUTLOOK MAKE HER THE NEAREST THING BLAST CORPS HAS TO A LEADER ....................";

const char D_8020E82C[] = ".................... A GENIUS IN HEAVY VEHICLE DESIGN. WHILE SOMETIMES OVERLY POSSESSIVE OF HIS CREATIONS, CLARK HAS TALENTS VITAL TO BLAST CORPS' SURVIVAL AND SUCCESS ....................";

const char D_8020E8EC[] = ".................... HEAD MECHANIC OF THE BLAST CORPS TEAM. WITH YEARS OF EXPERIENCE AND A GRUFF PRIDE IN HIS WORK, SPIKE ENSURES THAT THE DOZERS ARE BUILT TO PERFECTION ..................";

const char D_8020E9AC[] = ".................... A FEARLESS ARMY DAREDEVIL UNTIL HIS DISABLING ACCIDENT. WESLEY'S REJECTION BY HIS SUPERIORS TRIGGERED THE REBELLION THAT LED TO THE RISE OF BLAST CORPS ...............";

void func_801E8EB8(u8 arg0, u8 arg1) {
    s32 sp4C;
    UnkStruct_80364AF0 *sp48;
    u8 sp47;
    UnkStruct_80208358 sp34;
    UnkStruct_80208358 sp24;

    sp48 = &D_80364AF0[arg0];
    sp47 = 0;
    sp34 = D_80208358;
    sp24 = D_80208368;
    if (!(D_80364A90 & 0x10E18000) && arg0 != D_80364AEA) {
        sp47 = 1;
    }
    D_802154EC = -1;
    for (sp4C = 1; sp4C < 5; sp4C++) {
        D_80215508[sp4C] = -1;
    }
    if (arg0 < 4) {
        func_801E93DC(arg0);
    }
    if (D_80364A98 == 0x0001000000000000) {
        D_802158A0 = NULL;
        sprintf((char *)D_802155A0, "%s", sp34.unk0[arg0]);
    } else {
        D_802158A0 = NULL;
        if (arg0 < 4) {
            if (D_80365060[arg0] == 1) {
                sprintf((char *)D_802155A0, " ..... %s%s (%s) ... ", D_80208378[sp47], sp48, D_802081C0[sp48->unkC][0]);
                if (D_80364AF0[arg0].unk91 >= 12) {
                    sp4C = 4;
                } else {
                    sp4C = 3;
                }
                for (; sp4C > 0; sp4C--) {
                    D_80215508[sp4C] = func_8025B300(D_802155A0);
                    if (sp4C != 1) {
                        sprintf((char *)D_802155A0, "%s  %d .. ", D_802155A0, D_80215930[sp4C]);
                    }
                }
                sprintf((char *)D_802155A0, "%s  %d ... ", D_802155A0, D_80215930[1]);
                if (D_802E8BF8 == 0) {
                    sprintf((char *)D_802155A0, "%s$%d ... ", D_802155A0, sp48->unk14);
                }
                D_802154EC = func_8025B300(D_802155A0);
                sprintf((char *)D_802155A0, "%s  %d", D_802155A0, sp48->unkC);
                if ((D_80364A98 & 0x0200040000000000) || (D_80364A90 & 0x0100000000000000)) {
                    sprintf((char *)D_802155A0, "%s ..... %s", D_802155A0, "USE Z/R TO CHANGE PLAYER, THEN A TO SELECT!");
                }
            } else {
                sprintf((char *)D_802155A0, " ... NEW GAME");
            }
        } else {
            sprintf((char *)D_802155A0, " ");
        }
    }
    if (D_802158A0 != NULL) {
        D_802154D2 = func_8025B370(D_802158A0);
        D_8021592E = 1;
        D_80215458 = 19;
        if (arg0 == 4) {
            D_802154D4 = 22;
        } else {
            D_802154D4 = 14;
        }
    } else {
        D_802154D2 = func_8025B300(D_802155A0);
        D_8021592E = 0;
        D_80215458 = 12;
        if (arg0 == 4) {
            D_802154D4 = 36;
        } else {
            D_802154D4 = 22;
        }
    }
    if (D_802154D2 >= 0x100) {
        func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "sslen<TOTAL_SCROLL_LENGTH", "player.c", 400);
    }
    D_802154DC = -1;
    if (arg1 || arg0 == 4) {
        D_802154E0 = 12.0f;
    } else {
        D_802154E0 = 8.0f;
    }
}

void func_801E93DC(u8 arg0) {
    s32 spC;
    UnkStruct_80364AF0 *sp8;

    sp8 = &D_80364AF0[arg0];
    for (spC = 0; spC < 6; spC++) {
        D_80215930[spC] = 0;
    }
    for (spC = 0; spC < 0x3C; spC++) {
        if (sp8->unk18[spC] > 0 && sp8->unk18[spC] < 5) {
            D_80215930[sp8->unk18[spC]]++;
        }
        if (((D_80364AF0[arg0].unk18[spC] > 0 && D_80364AF0[arg0].unk18[spC] < 6) ? 1 : 0) &&
            (D_802E8F94[spC].unk0 & 0x81) && spC != 0x31 && spC != 0x2F && spC != 0x26) {
            D_80215930[3]++;
        }
    }
}

u16 func_801E9528(void) {
    s32 sp4;

    D_802154DC = (D_802154DC + 1) % D_802154D2;
    if (D_802154DC == D_802154EC) {
        D_802154E8 = 0;
    }
    for (sp4 = 1; sp4 <= ((D_80364AF0[D_80364AE8].unk91 >= 12) ? 4 : 3); sp4++) {
        if (D_80215508[sp4] == D_802154DC) {
            D_802154F0[sp4] = 0;
        }
    }
    if (D_802154D4) {
        D_802154D4--;
        if (!D_802154D4) {
            D_802154E0 = 3.0f;
        }
    }
    D_802154E4 = (D_802154E0 - D_802154E4) * 0.2 + D_802154E4;
    if (D_802158A0 != NULL) {
        return D_802158A0[D_802154DC];
    }
    return D_802155A0[D_802154DC];
}

s32 func_801E96F8(void) {
    return D_802154D2 == D_802154DC + 8;
}

Gfx *func_801E9718(Gfx *arg0, UnkStruct_803156F8 *arg1, s32 arg2) {
    Gfx *gfx;

    gfx = arg0;
    gSPMatrix(gfx++, &arg1->unk80, G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPMatrix(gfx++, &arg1->unk180, G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH);
    gSPMatrix(gfx++, &arg1->unk5C0, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPPerspNormalize(gfx++, D_8021591C);
    gDPPipeSync(gfx++);
    gSPTexture(gfx++, 0x07C0, 0x07C0, 0, G_TX_RENDERTILE, G_OFF);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
    gSPSetGeometryMode(gfx++, G_SHADE | G_SHADING_SMOOTH | G_LIGHTING);
    /* The nested blocks reproduce the original's stack layout. */
    {
        s32 pad[4];

        gSPSetLights2(gfx++, D_80208448);
        gDPSetRenderMode(gfx++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
        gDPSetCombineMode(gfx++, G_CC_SHADE, G_CC_SHADE);
        {
            s32 sp84;
            s32 sp80;

            if ((D_80364A90 & 0x0005040008010080) != 0) {
                D_8021593C += 16;
                if (D_8021593C >= 0x100) {
                    D_8021593C = 0xFF;
                }
            } else if ((D_80364A90 & 0x0008000202020000) != 0) {
                if ((D_8021593C -= 16) <= 0) {
                    D_8021593C = 0;
                }
            }
            for (sp80 = 0; sp80 < 4; sp80++) {
                D_80208380[sp80].v.cn[3] = (D_8021593C * 40) / 255;
            }
            for (sp80 = 4; sp80 < 7; sp80++) {
                D_80208380[sp80].v.cn[3] = (D_8021593C * 180) / 255;
            }
            osWritebackDCache(D_80208380, 0x80);
            if (D_8021593C != 0) {
                gSPDisplayList(gfx++, D_80208400);
            }
            gDPPipeSync(gfx++);
            gSPClearGeometryMode(gfx++, G_LIGHTING);
            if ((D_802154D8 += D_802154E4) >= D_80215458) {
                D_802154D8 -= D_80215458;
                for (sp80 = 1; D_802158A8[sp80] != D_802E8C98[D_8021592E]; sp80++) {
                    D_802158A8[sp80 - 1] = D_802158A8[sp80];
                }
                sp80--;
                D_802158A8[sp80] = func_801E9528();
                D_802158A8[sp80 + 1] = D_802E8C98[D_8021592E];
            }
            gfx = func_80274868(gfx);
            sp84 = 310 - (D_802154E8 += D_802154E4);
            if (sp84 >= -31 && sp84 < 320) {
                gfx = func_80272ED8(gfx, D_80215915, sp84, 194, D_8021593C, 1, 1.0f);
            }
            for (sp80 = 1; sp80 < 5; sp80++) {
                D_802154F0[sp80] += D_802154E4;
                sp84 = 310 - D_802154F0[sp80];
                if (sp84 >= -31 && sp84 < 320) {
                    gfx = func_80272ED8(gfx, D_80215916 + sp80, sp84, 194, D_8021593C, 1, 1.0f);
                }
            }
            gfx = func_80274AA4(gfx);
            func_80259CCC((s32)arg1, (D_8021592E == 1) ? NULL : func_8025B558(D_802158A8),
                          (D_8021592E == 1) ? D_802158A8 : NULL, 0, 0, -D_802154D8 % D_80215458 - 3, 201, 20, 20, 1,
                          0, 0, 0, (D_8021593C / 2 - 27 < 0) ? 0 : D_8021593C / 2 - 27);
            func_80259DC8((s32)arg1, (D_8021592E == 1) ? NULL : func_8025B558(D_802158A8),
                          (D_8021592E == 1) ? D_802158A8 : NULL, 0, 0, -D_802154D8 % D_80215458, 199, 20, 20, 1,
                          0xFF, 0xFF, 0xFF, D_8021593C, 0xFF, 0xFF, 0xFF, D_8021593C);
            gDPPipeSync(gfx++);
            return gfx;
        }
    }
}

void func_801EA108(u8 arg0, u8 arg1, u8 arg2) {
    UnkStruct_80364AF0 *sp2C;
    u32 sp28;

    sp2C = &D_80364AF0[arg0];
    for (sp28 = 0; sp28 < 0x100; sp28++) {
        ((u8 *)sp2C)[sp28] = 0;
    }
    func_801EA268(sp2C);
    sprintf((char *)sp2C, "%s", "NEW GAME");
    D_80365060[arg0] = 2;
    osSendMesg(&D_80219EF8, (OSMesg)((arg0 << 16) | 7), OS_MESG_BLOCK);
    if (arg1) {
        osSendMesg(&D_80219EF8, (OSMesg)((arg2 ? 0x14 : 0x15) | (arg0 << 16) | 0x01000000), OS_MESG_BLOCK);
        osRecvMesg(&D_80219F50, NULL, OS_MESG_BLOCK);
    } else {
        osSendMesg(&D_80219EF8, (OSMesg)((arg2 ? 0x14 : 0x15) | (arg0 << 16)), OS_MESG_BLOCK);
    }
}

void func_801EA268(UnkStruct_80364AF0 *arg0) {
    arg0->unk10 = 0x1063E;
}

void func_801EA278(void) {
    s32 sp1C;
    s32 sp18;

    for (sp1C = 0; sp1C < 4; sp1C++) {
        osSendMesg(&D_80219EF8, (OSMesg)((sp1C << 16) | 6 | 0x01000000), OS_MESG_BLOCK);
        osRecvMesg(&D_80219F50, (OSMesg *)&sp18, OS_MESG_BLOCK);
        if (sp18 == 0) {
            if (func_8025B3F0((u8 *)&D_80364AF0[sp1C], (u8 *)"NEW GAME")) {
                D_80365060[sp1C] = 1;
            } else {
                D_80365060[sp1C] = 2;
            }
        } else if (sp18 != 0x6E382) {
            if (sp1C < D_8039C538) {
                osSendMesg(&D_80219EF8, (OSMesg)((sp1C << 16) | 3 | 0x01000000), OS_MESG_BLOCK);
                osRecvMesg(&D_80219F50, (OSMesg *)&sp18, OS_MESG_BLOCK);
            }
            if (sp18 != 0 || sp1C >= D_8039C538) {
                D_80365060[sp1C] = 0;
                sprintf(D_80215520[sp1C], "%d : %s", sp1C + 1, "PAK FULL");
            } else {
                func_801EA108(sp1C, 1, 0);
            }
        } else {
            func_801EA108(sp1C, 1, 0);
        }
        if (D_80365060[sp1C] == 1 || D_80365060[sp1C] == 2) {
            sprintf(D_80215520[sp1C], "%d : %s", sp1C + 1, &D_80364AF0[sp1C]);
        }
    }
}

void func_801EA4B8(void) {
    s32 sp1C;

    func_801EA278();
    D_802154B0 = 0;
    for (sp1C = 0; sp1C < 4; sp1C++) {
        D_8020C070[sp1C + 2].unkC = D_80215520[sp1C];
        D_8020C070[sp1C + 2].unk0 |= 0x81;
        D_8020C070[sp1C + 2].unk0 &= ~0x20;
        D_8020C070[sp1C + 2].unk18 = 7;
        D_8020C070[sp1C + 2].unk19 = 4;
        D_8020C070[sp1C + 2].unk2 = 0x50;
        switch (D_80365060[sp1C]) {
            case 0:
                D_8020C070[sp1C + 2].unk0 &= ~0x81;
                D_8020C070[sp1C + 2].unk18 = 8;
                D_802154B0++;
                break;
        }
    }
    if (D_802154B0 != 4) {
        D_8020C070[6].unkC = "ERASE GAME";
        D_8020C070[6].unk10 = (s32)D_803046F8;
    } else {
        D_8020C070[6].unkC = "IGNORE PAK";
        D_8020C070[6].unk10 = (s32)D_80304710;
    }
    D_8020C070[6].unk19 = 2;
    D_802F8BDC[10].unk8 &= ~0x400;
}

void func_801EA6E8(void) {
    s32 sp24;

    func_801EA278();
    for (sp24 = 0; sp24 < 4; sp24++) {
        D_8020C070[sp24 + 2].unk2 = 0x40;
        switch (D_80365060[sp24]) {
            case 1:
                sprintf(D_80215520[sp24], "ERASE %d : %s", sp24 + 1, &D_80364AF0[sp24]);
                D_8020C070[sp24 + 2].unk0 |= 0x81;
                D_8020C070[sp24 + 2].unk0 &= ~0x20;
                D_8020C070[sp24 + 2].unk18 = 7;
                D_8020C070[sp24 + 2].unk19 = 4;
                break;
            case 0:
            case 2:
                D_8020C070[sp24 + 2].unk18 = 8;
                D_8020C070[sp24 + 2].unk0 |= 0x20;
                D_8020C070[sp24 + 2].unk0 &= ~0x81;
                D_8020C070[sp24 + 2].unk18 = 8;
                break;
        }
    }
    D_8020C070[6].unkC = "GO BACK";
    D_8020C070[6].unk10 = (s32)D_80304730;
    D_8020C070[6].unk19 = 2;
    D_802F8BDC[10].unk8 |= 0x400;
    D_802F8BDC[10].unk18 = 6;
}

void func_801EA93C(char *arg0, s32 arg1, u8 arg2, u8 arg3, char *arg4) {
    D_802154B2 = 0x7FFF;
    D_802154B4 = 0x7FFF;
    D_80215918 = 0;
    D_802154B8 = 0;
    D_802154B6 = 0;
    D_802154BA = -1;
    D_802154BC = 0;
    D_802154BE = 0;
    D_802154C0 = 1;
    D_8020C070[7].unk6 = arg3;
    D_8020C070[7].unk8 = arg3;
    D_802154CC = arg3;
    D_802154C8 = (arg3 * 3) / 5;
    D_80215928 = arg4;
    *arg4 = 0;
    D_8020C070[7].unkC = D_80215928;
    D_8020C070[7].unk2 = D_802154C4 = 160 - D_802154C8 / 2;
    D_8020C070[8].unkC = arg0;
    D_8020C070[8].unk10 = arg1;
    D_80215924 = arg2;
    D_802154D0 = 1;
    D_8021591A = 0;
    D_80215920 = 1;
    D_8021592C = 0;
}

Gfx *func_801EAA7C(Gfx *arg0, UnkStruct_803156F8 *arg1, s32 *arg2) {
    Gfx *spFC;
    UnkStruct_8020C070 *spF8;
    u8 spF7;
    s32 spF0;
    s32 spEC;
    s16 spEA;
    s32 spE4;
    s32 spE0;
    s32 spDC;
    s32 spD8;
    s32 spD4;
    s32 spD0;
    s32 spCC;
    s32 spC8;
    UnkStruct_802F47B0 *spC4;
    UnkStruct_802F47B0 *spC0;
    s16 spBE;
    s16 spBC;
    u8 spBB;

    spFC = arg0;
    spF8 = &D_8020C070[7];
    spCC = 0;
    spC8 = func_8025B300((u8 *)D_80215928);
    spC4 = &D_802F47B0[16];
    if ((D_80370C28 & 0x300) && !(D_80370C2A & 0x300)) {
        func_80260650(D_80367738, 0xC, 0);
    }
    D_8021546C = D_8021591A;
    D_8021591A = D_80370C2C;
    if (((D_8021591A > 0) ? D_8021591A : -D_8021591A) < 10) {
        D_8021591A = 0;
    } else {
        D_8021591A *= (D_8021591A > 0) ? D_8021591A : -D_8021591A;
    }
    if (D_8021591A != 0) {
        if (D_8021546C == 0) {
            D_80215918 = D_802154B6;
        }
        D_802154B4 -= D_8021591A >> 3;
    } else {
        if (D_8021546C != 0 && D_802154B6 == D_80215918) {
            D_802154B6 += (D_8021546C >= 0) ? 1 : -1;
            if (D_802154B6 < 0) {
                D_802154B6 += 33;
            }
            if (D_802154B6 >= 33) {
                D_802154B6 -= 33;
            }
            D_802154B2 = 0x7FFF - D_802154B6 * 1986;
        }
        spEA = D_802154B4 - D_802154B2;
        D_802154B4 -= spEA >> 4;
    }
    D_802154B6 = (0x83E0 - D_802154B4) / 1986;
    if (D_802154B6 == 33) {
        D_802154B6 = 0;
    }
    if (D_8021591A != 0) {
        D_802154B2 = 0x7FFF - D_802154B6 * 1986;
    }
    if (D_802154D0 != 0) {
        D_802154B8 = D_802154B6;
        D_802154D0 = 0;
    }
    if (D_802154B6 != D_802154B8) {
        func_80260650(D_80367738, 0x90, 0);
    }
    D_802154B8 = D_802154B6;
    for (spEC = 0; spEC < 2; spEC++) {
        for (spF0 = 0; spF0 < 33; spF0++) {
            spBE = D_802154B4 + spF0 * 1986 - 0x6000;
            spBC = spBE - 0x2000;
            spBC += 0x7FFF;
            spBC += 0x2000;
            spBC += 0x7FFF;
            spE4 = sins(spBC) * 120.0 / 32768.0 - 7.0;
            spE0 = coss(spBC) * 96.0 / 32768.0 - 10.0;
            if (spF0 < D_80208350[0]) {
                D_80208498[0] = D_80208314[spF0];
            } else {
                D_80208498[0] = D_802082FC[spF0 - D_80208350[0]];
            }
            if (D_80208498[0] != D_802154BA) {
                if (spEC != 0) {
                    if (D_802154B6 == spF0) {
                        spF7 = D_80208498[0], spDC = spE4, spD8 = spE0, spD4 = 24, spD0 = 20;
                    } else {
                        func_80259DC8((s32)arg1, (char *)D_80208498, NULL, 1, 0, spE4, spE0, 24, 20, 1, 200, 200, 200,
                                      D_8036BB20, 0xFF, 0xFF, 0xFF, D_8036BB20);
                    }
                } else if (D_802154B6 == spF0) {
                    func_80259CCC((s32)arg1, (char *)D_80208498, NULL, 1, 0, spE4 - 11, spE0, 48, 40, 1, 0, 0, 0,
                                  D_8036BB20 / 2);
                } else {
                    func_80259CCC((s32)arg1, (char *)D_80208498, NULL, 1, 0, spE4 - 4, spE0 + 3, 24, 20, 1, 0, 0, 0,
                                  D_8036BB20 / 2);
                }
            }
        }
    }
    if (spF7 != D_802154BA && D_802154BA == -1) {
        if (D_803156C4 % 20 < 15) {
            spBB = D_8036BB20;
        } else {
            spBB = D_8036BB20 / 3;
        }
        D_80208498[0] = spF7;
        func_80259BD4(&spFC, arg1);
        func_80259DC8((s32)arg1, (char *)D_80208498, NULL, 1, 0, spDC - 5, spD8 - 5, spD4 * 2, spD0 * 2, 1, spC4->unk0,
                      spC4->unk1, spC4->unk2, spBB, spC4->unk4, spC4->unk5, spC4->unk6, spBB);
    }
    if (D_8036BB1C == 2 && (D_80370C28 & 0x1000) && !(D_80370C2A & 0x1000) && func_802753C0() == 0) {
        if (D_802154BC != 0) {
            D_80364A98 = 0x01000000;
            D_80365060[D_80364AE8] = 1;
            func_8026AF6C(0x4000);
        } else {
            func_80260650(D_80367738, 0x2B, 0);
        }
    }
    switch (D_802154BE) {
        case 0:
            if (D_8036BB1C == 2 && (D_80370C28 & 0xC000) && !(D_80370C2A & 0xC000) && func_802753C0() == 0) {
                if (D_80370C28 & 0x4000) {
                    spF7 = 0x7F;
                }
                if (spF7 == 0x7F) {
                    if (D_802154BC == 0) {
                        if (D_80370C28 & 0x4000) {
                            if (D_802E8BF8 != 0) {
                                func_80275270(0x0400000000000000, 0.5f);
                            } else {
                                D_80364A98 = 0x200000;
                            }
                            func_80260650(D_80367738, 0xDE, 0);
                            func_8026AF6C(0x4000);
                        } else {
                            func_80260650(D_80367738, 0x2B, 0);
                        }
                    } else {
                        D_802154BC--;
                        D_80215928[D_802154BC] = 0;
                        func_80260650(D_80367738, 0xE4, 0);
                        D_802154C0 = 0;
                        D_80215464 = spF8->unk6;
                        D_80215468 = D_802154CC;
                        spF0 = D_80215468;
                        spF0 = spF0 * 3 / 5;
                        D_80215450 = spF8->unk2;
                        D_80215454 = -((spC8 - 1) * spF0 / 2) - spF0 / 2 + 160;
                        D_8021545C = D_802154C4;
                        D_80215460 = (spC8 - 1) * spF0 / 2 - spF0 / 2 + 160;
                    }
                } else if (D_802154BC < D_80215924) {
                    func_80260650(D_80367738, 0x91, 0);
                    D_802154BE = 1;
                    D_802154C0 = 0;
                    D_802154BA = spF7;
                    D_80215464 = spF8->unk6;
                    D_80215468 = D_802154CC;
                    spF0 = D_80215468;
                    spF0 = spF0 * 3 / 5;
                    D_80215450 = spF8->unk2;
                    D_80215454 = -((spC8 + 1) * spF0 / 2) - spF0 / 2 + 160;
                    D_8021545C = D_802154C4;
                    D_80215460 = (spC8 + 1) * spF0 / 2 - spF0 / 2 + 160;
                    D_80215944 = spDC - 5;
                    D_80215948 = spD8 - 5;
                    D_8021594C = D_80215460 - 160.0f - spF0;
                    D_80215950 = spF8->unk4 - 120;
                    D_80215440 = 48.0f;
                    D_80215444 = 40.0f;
                    D_80215448 = D_80215468;
                    D_8021544C = D_80215468;
                } else {
                    func_80260650(D_80367738, 0x2B, 0);
                }
            }
            break;
        case 1:
            D_80215944 += (D_8021594C - D_80215944) * 0.2;
            D_80215948 += (D_80215950 - D_80215948) * 0.2;
            D_80215440 += (D_80215448 - D_80215440) * 0.2;
            D_80215444 += (D_8021544C - D_80215444) * 0.2;
            D_80208498[0] = D_802154BA;
            func_80259CCC((s32)arg1, (char *)D_80208498, NULL, 0, 0, D_80215944 - 4.0f, D_80215948 + 4.0f, D_80215440,
                          D_80215444, 1, 0, 0, 0, D_8036BB20 / 2);
            func_80259DC8((s32)arg1, (char *)D_80208498, NULL, 0, 0, D_80215944, D_80215948, D_80215440, D_80215444, 1,
                          spC4->unk0, spC4->unk1, spC4->unk2, D_8036BB20, spC4->unk4, spC4->unk5, spC4->unk6,
                          D_8036BB20);
            if (((D_80215944 - D_8021594C > 0.0f) ? D_80215944 - D_8021594C : -(D_80215944 - D_8021594C)) <
                    0.15 &&
                ((D_80215948 - D_80215950 > 0.0f) ? D_80215948 - D_80215950 : -(D_80215948 - D_80215950)) <
                    0.15) {
                func_80260650(D_80367738, 1, 0);
                D_802154BE = 0;
                D_802154C0 = 0;
                D_80215928[D_802154BC] = D_80208498[0];
                D_80215928[++D_802154BC] = 0;
                D_802154BA = -1;
            }
            break;
    }
    func_80259BD4(&spFC, arg1);
    D_80215940 += D_80215920;
    if (D_80215920 < 0) {
        D_80215940 += D_80215920 * 2;
    }
    if (D_80215940 < 0 || D_80215940 >= 16) {
        D_80215940 -= D_80215920 * 2;
        D_80215920 = -D_80215920;
    }
    D_8021592C = (D_8036BB1C == 2) ? ((D_8021592C + 16 < 255) ? D_8021592C + 16 : 255) : 0;
    spC0 = &D_802F47B0[19];
    spCC = func_80276130(arg1, 3, spCC, D_802154C4 + D_802154C8 + D_80215940, spF8->unk4 + spF8->unk8 / 2,
                         spF8->unk6 / 3 + D_80215940 / 2, spF8->unk8 / 2 + 3, D_802F47B0[19].unk0, D_802F47B0[19].unk1,
                         D_802F47B0[19].unk2, D_8021592C, D_802F47B0[19].unk4, D_802F47B0[19].unk5, D_802F47B0[19].unk6,
                         D_8021592C, D_802F47B0[19].unk0, D_802F47B0[19].unk1, D_802F47B0[19].unk2, D_8021592C,
                         D_802F47B0[19].unk4, D_802F47B0[19].unk5, D_802F47B0[19].unk6, D_8021592C);
    spCC = func_80276080(arg1, 3, spCC, D_802154C4 + D_802154C8 + D_80215940 + 4, spF8->unk4 + spF8->unk8 / 2 + 3,
                         spF8->unk6 / 3 + D_80215940 / 2, spF8->unk8 / 2 + 3, 0, 0, 0, D_8021592C / 2);
    spFC = func_80275DA4(spFC, 0);
    gSPVertex(spFC++, arg1->unk1E00, 8, 0);
    gSP1Triangle(spFC++, 4, 5, 6, 0);
    gSP1Triangle(spFC++, 4, 6, 7, 0);
    gSP1Triangle(spFC++, 0, 1, 2, 0);
    gSP1Triangle(spFC++, 0, 2, 3, 0);
    spCC = func_80276130(arg1, 2, spCC, spF8->unk2 - D_80215940 - 4, spF8->unk4 + spF8->unk8 / 2,
                         spF8->unk6 / 3 + D_80215940 / 2, spF8->unk8 / 2 + 3, spC0->unk0, spC0->unk1, spC0->unk2,
                         D_8021592C, spC0->unk4, spC0->unk5, spC0->unk6, D_8021592C, spC0->unk0, spC0->unk1,
                         spC0->unk2, D_8021592C, spC0->unk4, spC0->unk5, spC0->unk6, D_8021592C);
    spCC = func_80276080(arg1, 2, spCC, spF8->unk2 - D_80215940 - 8, spF8->unk4 + spF8->unk8 / 2 + 3,
                         spF8->unk6 / 3 + D_80215940 / 2, spF8->unk8 / 2 + 3, 0, 0, 0, D_8021592C / 2);
    spFC = func_80275DA4(spFC, 0);
    gSPVertex(spFC++, &arg1->unk1E00[spCC - 8], 8, 0);
    gSP1Triangle(spFC++, 4, 5, 6, 0);
    gSP1Triangle(spFC++, 4, 6, 7, 0);
    gSP1Triangle(spFC++, 0, 1, 2, 0);
    gSP1Triangle(spFC++, 0, 2, 3, 0);
    switch (D_802154C0) {
        case 0:
            D_80215450 += (D_80215454 - D_80215450) * 0.2;
            spF8->unk2 = D_80215450;
            D_8021545C += (D_80215460 - D_8021545C) * 0.2;
            D_802154C4 = D_8021545C;
            break;
        case 1:
            break;
    }
    *arg2 += spFC - arg0;
    return spFC;
}

void func_801EC288(u8 arg0) {
    s32 sp4;

    D_80215902[0] = 3;
    D_80215902[1] = arg0;
    for (sp4 = 0; sp4 < 2; sp4++) {
        D_80215900[sp4] = 4;
        D_80215908[sp4] = 50;
        D_80215910[sp4] = 0;
    }
}

void func_801EC30C(u8 arg0) {
    s32 sp24;
    s32 sp20;

    D_80215914 = func_80272C5C(D_802082E4, D_802082D8, 4, 2, 0, 1.0f);
    func_80272C5C(D_802082E8, NULL, 1, 2, 1, 1.0f);
    D_80215902[0] = 3;
    D_80215902[1] = arg0;
    if (D_802E8F94[D_802E8BDC].unk0 == 1) {
        sp24 = 0;
    } else {
        sp24 = 1;
    }
    for (sp20 = 0; sp24 < 2; sp24++, sp20++) {
        D_80215900[sp24] = 0;
        D_80215908[sp24] = sp20 * 60 + 40;
        D_80215910[sp24] = 0;
    }
}

void func_801EC464(void) {
    s32 sp4;

    for (sp4 = 0; sp4 < 2; sp4++) {
        D_80215900[sp4] = 3;
    }
}

Gfx *func_801EC49C(Gfx *arg0, s32 arg1, s32 arg2, u8 arg3) {
    Gfx *gfx;
    s32 pad;
    s32 sp2C;

    gfx = arg0;
    if (D_8036BB1C == 8) {
        D_80215900[arg3] = 3;
    }
    switch (D_80215900[arg3]) {
        case 0:
            D_80215908[arg3]--;
            if (D_80215908[arg3] == 0) {
                D_80215900[arg3] = 1;
                if (D_80215902[arg3] == 5) {
                    func_80260650(D_80367738, 0xEA, 0);
                } else {
                    func_80260650(D_80367738, 0xE6, 0);
                }
            }
            break;
        case 4:
            D_80215908[arg3]--;
            if (D_80215908[arg3] == 0) {
                D_80215900[arg3] = 1;
            }
            break;
        case 1:
            D_80215910[arg3] += 0x10;
            if (D_80215910[arg3] >= 0x100) {
                D_80215910[arg3] = 0xFF;
                D_80215900[arg3] = 2;
            }
            break;
        case 3:
            D_80215910[arg3] -= 0x20;
            if (D_80215910[arg3] < 0) {
                D_80215910[arg3] = 0;
            }
            break;
        case 2:
            break;
    }
    if (D_80215900[arg3] == 0) {
        return gfx;
    }
    if (D_80215902[arg3] == 5) {
        sp2C = 2;
    } else {
        sp2C = 1;
    }
    gfx = func_80272ED8(gfx, D_80215902[arg3] % 5 + D_80215914, arg1, arg2, D_80215910[arg3], sp2C, 1.0f);
    return gfx;
}

Gfx *func_801EC770(Gfx *arg0, s32 arg1, s32 *arg2) {
    Gfx *sp64;
    u8 sp63;

    sp64 = arg0;
    sp64 = func_80274868(sp64);
    if (D_80364AA8 == 1) {
        sp64 = func_801EC49C(sp64, 0x5C, 0x68, 0);
        if (D_80215902[1] != 0) {
            sp64 = func_801EC49C(sp64, 0xA8, 0x68, 1);
        }
    } else {
        if (D_80215902[1] == 5) {
            sp63 = 1;
        } else {
            sp63 = (((D_80364AF0[D_80364AE8].unk91 >= 12) ? 4 : 3) < D_80215902[1] + 1)
                       ? ((D_80364AF0[D_80364AE8].unk91 >= 12) ? 4 : 3)
                       : D_80215902[1] + 1;
        }
        sp64 = func_801EC49C(sp64, 0x82, 0x68, 1);
        sp64 = func_80272ED8(sp64, sp63 + D_80215914, 0x2E, 0x6C, (D_80215910[1] * 3) / 4, 0, 0.75f);
    }
    sp64 = func_80274AA4(sp64);
    if (D_80364AA8 != 1) {
        func_80264A34(D_80215470, D_802E8F94[D_802E8BDC].unk30[4 - sp63], 0);
        D_80215470[5] = 0;
        func_80259DC8(arg1, D_80215470, 0, 0, 0, 0x29, 0x7D, 0x10, 0x10, 1, 0xFF, 0xB4, 0, D_80215910[1], 0xFF, 0x78, 0,
                      D_80215910[1]);
    }
    *arg2 += sp64 - arg0;
    return sp64;
}

u64 func_801ECA50(u8 arg0) {
    u64 sp8;

    if ((D_80364AF0[D_80364AE8].unk18[arg0] > 0 && D_80364AF0[D_80364AE8].unk18[arg0] < 6) ? 1 : 0) {
        sp8 = 0x80;
    } else if (D_802E8F94[arg0].unk0 & 0x81) {
        sp8 = 0x800;
    } else {
        sp8 = 0x20000000;
    }
    return sp8;
}

void func_801ECB18(void) {
    func_801FE018(8);
    D_80364A87 = 0;
    D_803643D5 = 0;
    if ((D_80364AF0[D_80364AE8].unk18[D_802E8BDC] > 0 && D_80364AF0[D_80364AE8].unk18[D_802E8BDC] < 6) ? 1 : 0) {
        if (D_802E8F94[D_802E8BDC].unk0 == 1) {
            osSendMesg(&D_80219EF8, (OSMesg)((D_802E8BDC << 8) | 0xC | (D_80364AE8 << 16)), OS_MESG_BLOCK);
        }
        osSendMesg(&D_80219EF8, (OSMesg)((D_802E8BDC << 8) | 8 | (D_80364AE8 << 16) | 0x01000000), OS_MESG_BLOCK);
    } else {
        osSendMesg(&D_80219EF8, (OSMesg)((D_802E8BDC << 8) | 0x16 | (D_80364AE8 << 16) | 0x01000000), OS_MESG_BLOCK);
        func_801F8354(D_80364AE8);
    }
}

void func_801ECC8C(void) {
    s32 sp1C;
    s32 sp18;

    sp18 = 0;
    for (sp1C = 0; sp1C < 4; sp1C++) {
        if (D_8039C53C[sp1C] != 0) {
            if (sp18 == 0) {
                func_80261570(0.0f);
                sp18 = 1;
            }
            osSendMesg(&D_80219EF8, (OSMesg)((sp1C << 16) | 0x14), OS_MESG_BLOCK);
            func_8029A7E4("saving player %d on level %d\n", sp1C, D_8039C53C[sp1C] - 1);
            D_80364AF0[sp1C].unk8 = D_802E8BDC;
            osSendMesg(&D_80219EF8, (OSMesg)(((D_8039C53C[sp1C] - 1) << 8) | 7 | (sp1C << 16)), OS_MESG_BLOCK);
            osSendMesg(&D_80219EF8, (OSMesg)(((D_8039C53C[sp1C] - 1) << 8) | 9 | (sp1C << 16)), OS_MESG_BLOCK);
            osSendMesg(&D_80219EF8, (OSMesg)(((D_8039C53C[sp1C] - 1) << 8) | 0xB | (sp1C << 16)), OS_MESG_BLOCK);
            if (D_8039C540 != 0 && D_80364AE8 == sp1C) {
                osSendMesg(&D_80219EF8, (OSMesg)(((D_8039C540 - 1) << 8) | 0xD | (D_80364AE8 << 16)), OS_MESG_BLOCK);
                D_8039C540 = 0;
            }
            osSendMesg(&D_80219EF8, (OSMesg)((sp1C << 16) | 0x15 | 0x01000000), OS_MESG_BLOCK);
            osRecvMesg(&D_80219F50, NULL, OS_MESG_BLOCK);
            D_8039C53C[sp1C] = 0;
        }
    }
}

void func_801ECE9C(void) {
    s32 sp4;

    for (sp4 = 0; sp4 < 0x3C; sp4++) {
        if (D_802E8F94[sp4].unk0 & 0x81) {
            if (D_80364AF0[D_80364AE8].unk91 >= 11 && D_80364A98 == 0x4000) {
                D_802E8F94[sp4].unk0 = 0x80;
            } else {
                D_802E8F94[sp4].unk0 = 1;
            }
        }
    }
}

void func_801ECF5C(void) {
    UnkStruct_80364AF0 *sp6C;
    u8 sp4C[0x20];
    UnkStruct_802E8F94 *sp48;
    UnkStruct_8020849C sp40;
    u8 sp3F;
    u16 sp3C;
    s32 sp38;
    s32 sp34;
    u16 sp32;
    u8 sp31;
    u8 sp30;

    sp6C = &D_80364AF0[D_80364AE8];
    sp40 = D_8020849C;
    sp3C = sp6C->unkA;
    func_801ED480((u8 *)D_80364EF0[D_80364AE8], sp4C);
    if (D_8039C53C[D_80364AE8] == 0) {
        func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "saveIt[playerNumber]", "player.c", 0x568);
    }
    for (sp30 = 0; sp30 < 0x3C; sp30++) {
        if ((D_80364AF0[D_80364AE8].unk18[sp30] > 0 && D_80364AF0[D_80364AE8].unk18[sp30] < 6) ? 1 : 0) {
            if (D_802E8F94[sp30].unk0 == 1 && sp30 != 0x31 && sp30 != 0x2F && sp30 != 0x26) {
                sp48 = &D_802E8F94[sp30];
                if (D_8039C53C[D_80364AE8] != sp30 + 1) {
                    osSendMesg(&D_80219EF8, (OSMesg)((sp30 << 8) | 8 | (D_80364AE8 << 16) | 0x01000000), OS_MESG_BLOCK);
                    osRecvMesg(&D_80219F50, NULL, OS_MESG_BLOCK);
                } else {
                    func_801ED480(sp4C, (u8 *)D_80364EF0[D_80364AE8]);
                }
                sp32 = D_80364EF0[D_80364AE8][D_802E8C44[0]];
                func_8029A7E4("level %d time is %d\n", sp30, sp32);
                sp31 = func_801EF2BC(sp32, sp30, D_80364AF0[D_80364AE8].unk91);
                sp6C->unk18[sp30] = sp31;
                sp40.unk0[sp31 - 1]++;
            }
        }
    }
    func_801ED480(sp4C, (u8 *)D_80364EF0[D_80364AE8]);
    D_802E8BDC = 0;
    func_8029A7E4(" %d %d %d %d %d\n", sp40.unk0[2] * 3, sp40.unk0[1] * 2, sp40.unk0[0], sp6C->unkA, sp3C);
    sp6C->unkA += sp40.unk0[2] * 3 + sp40.unk0[1] * 2 + sp40.unk0[0];
    sp3F = sp6C->unkA / 12 - sp3C / 12;
    sp6C->unkC += sp3F;
    func_8029A7E4("%d stars\n", sp3F);
    for (sp38 = 0, sp34 = (320 - (sp3F << 5)) / 2 + 40; sp38 < sp3F; sp38++, sp34 += 32) {
        D_8020C070[sp38 + 189].unk0 |= 0x100;
        D_8020C070[sp38 + 189].unk2 = sp34;
        D_8020C070[sp38 + 189].unk14[0] = 0x33;
    }
    for (; sp38 < 6; sp38++) {
        D_8020C070[sp38 + 189].unk0 &= ~0x100;
        D_8020C070[sp38 + 189].unk14[0] = 0;
    }
    for (sp38 = 0; sp38 < 3; sp38++) {
        sprintf(D_80215480[sp38], "*******%-2d**", sp40.unk0[2 - sp38]);
        D_8020C070[sp38 + 185].unkC = D_80215480[sp38];
    }
}

void func_801ED480(u8 *arg0, u8 *arg1) {
    u32 sp4;

    for (sp4 = 0; sp4 < 0x20; sp4++) {
        arg1[sp4] = arg0[sp4];
    }
}

void func_801ED4B8(void) {
    UnkStruct_80364AF0 *sp54;
    u8 sp34[0x20];
    UnkStruct_802E8F94 *sp30;
    u8 sp2F;
    u16 sp2C;
    s32 sp28;
    u8 sp27;
    u8 sp26;

    sp54 = &D_80364AF0[D_80364AE8];
    sp2C = sp54->unkA;
    func_801ED480((u8 *)D_80364EF0[D_80364AE8], sp34);
    if (D_8039C53C[D_80364AE8] == 0) {
        func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "saveIt[playerNumber]", "player.c", 0x5C0);
    }
    for (sp26 = 0; sp26 < 0x3C; sp26++) {
        if (((D_80364AF0[D_80364AE8].unk18[sp26] > 0 && D_80364AF0[D_80364AE8].unk18[sp26] < 6) ? 1 : 0) &&
            sp26 != 0x31 && sp26 != 0x2F && sp26 != 0x26) {
            sp30 = &D_802E8F94[sp26];
            if (D_8039C53C[D_80364AE8] != sp26 + 1) {
                osSendMesg(&D_80219EF8, (OSMesg)((sp26 << 8) | 8 | (D_80364AE8 << 16) | 0x01000000), OS_MESG_BLOCK);
                osRecvMesg(&D_80219F50, NULL, OS_MESG_BLOCK);
            } else {
                func_801ED480(sp34, (u8 *)D_80364EF0[D_80364AE8]);
            }
            sp27 = func_801EF2BC(D_80364EF0[D_80364AE8][D_802E8C44[D_80364AF0[D_80364AE8].unk92[sp26]]], sp26,
                                 D_80364AF0[D_80364AE8].unk91 + 1);
            sp54->unk18[sp26] = sp27;
            if (sp27 == 4) {
                sp54->unkA++;
            }
        }
    }
    func_801ED480(sp34, (u8 *)D_80364EF0[D_80364AE8]);
    D_802E8BDC = 0;
    sp2F = sp54->unkA / 12 - sp2C / 12;
    sp54->unkC += sp2F;
    func_8029A7E4("cmo destroy %d stars\n", sp2F);
}
