#include "common.h"

typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ u8 unk4[0x2C];
} UnkStruct_8020D7E4; /* size = 0x30 */

extern UnkStruct_8020D7E4 D_8020D7E4[];

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1[7];
} UnkStruct_802E8F38; /* size = 0x8 */

typedef struct {
    /* 0x000 */ u8 unk0[0x904];
    /* 0x904 */ char *unk904;
} UnkStruct_8020C070;

extern u64 D_80364A98;
extern u8 D_80364AE8;
extern u8 D_80364B80[][0x100];
extern u8 D_80364B81[][0x100];
extern UnkStruct_802E8F38 D_802E8F38[];
extern UnkStruct_8020C070 D_8020C070[];
extern s32 D_80358060;

void func_801ECC8C(void);
void func_80200714(u8);
void func_80255DC8(void);
void func_80260C20(u8, f32);
void func_8026AF6C(s32);

/* .bss, 0x8036EBA0-0x8036EC00 (tools/bss_c.py) */
char D_8036EBA0[0x60];

/* .data, 0x802FDA60-0x802FDA80 (tools/data_c.py) */
u8 D_802FDA60[0x10] = { 0, 0, 5, 5, 5, 4, 6, 4, 0, 5, 5, 9, 6 };
u8 D_802FDA70[0x10] = { 0, 0, 40, 40, 37, 40, 27, 39, 0, 37, 37, 26, 26 };

void func_802860F0(void) {
    u8 sp37;
    s32 sp30;
    s32 sp2C;
    s32 sp28;

    if (D_80364B81[D_80364AE8][0] != 0xD && D_80364B81[D_80364AE8][0] != 8 && D_80364B81[D_80364AE8][0] != 1) {
        D_80364A98 = 0x800000000000;
        func_80255DC8();
        func_80200714(D_802FDA60[D_80364B81[D_80364AE8][0]]);
        switch (D_80364B81[D_80364AE8][0]) {
            case 4:
                sp37 = 0;
                for (sp30 = 0; sp30 < 60 && sp37 == 0; sp30++) {
                    for (sp2C = 0, sp28 = 0; sp2C < 6 && sp28 == 0; sp2C++) {
                        if (D_802E8F38[sp2C].unk0 == sp30) {
                            sp28 = 1;
                            if (!(D_80364B80[D_80364AE8][0] & (1 << sp2C))) {
                                sp37 = 1;
                            }
                        }
                    }
                }
                sprintf(D_8036EBA0, "IN %s.", D_8020D7E4[sp30].unk0);
                D_8020C070[0].unk904 = D_8036EBA0;
                break;
            case 6:
                func_801ECC8C();
                break;
        }
        func_8026AF6C((D_80364B81[D_80364AE8][0] + 0x16) | 0x8000);
    }
}

void func_802862DC(void) {
    if (D_80358060 == 0) {
        func_80260C20(D_802FDA70[D_80364B81[D_80364AE8][0]], 1.0f);
    }
}

extern s32 D_802E8BDC;
extern u8 D_80364AF8[][0x100];
extern u8 D_80370C50;
extern u8 D_803643D5;
void func_8029A7E4(char *, ...);
void func_802995F0(s32);
void func_801F8354(u8);

void func_80286330(void) {
    switch (D_80364B81[D_80364AE8][0]) {
        case 2:
        case 3:
        case 4:
            D_80364A98 = 0x4000;
            break;
        case 5:
            func_802995F0(0);
            D_80364A98 = 0x100000000000;
            break;
        case 6:
            if (D_802E8BDC != 50) {
                func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "levelno==50", "academy.c", 140);
            }
            if (D_80364AF8[D_80364AE8][0] != 50) {
                func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "players[playerNumber].levelno==50", "academy.c", 141);
            }
            if (D_80370C50 == 0) {
                func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "frontEndPresent", "academy.c", 142);
            }
            D_80364A98 = 0x800;
            D_803643D5 = 0;
            func_801F8354(D_80364AE8);
            break;
        case 7:
            func_802995F0(1);
            D_80364A98 = 0x100000000000;
            break;
        case 9:
            func_802995F0(3);
            D_80364A98 = 0x100000000000;
            break;
        case 10:
            D_80364A98 = 0x4000000000000;
            break;
        case 11:
            D_80364A98 = 0x4000;
            break;
        case 12:
            D_80364A98 = 0x4000;
            break;
    }
}

typedef struct {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u16 unkA;
    /* 0x0C */ u8 unkC;
    /* 0x0D */ u8 padD[0xB];
    /* 0x18 */ u8 unk18[60];
    /* 0x54 */ u8 pad54[0x3C];
    /* 0x90 */ u8 unk90;
    /* 0x91 */ u8 unk91;
    /* 0x92 */ u8 pad92[0x6E];
} UnkStruct_80364AF0; /* size = 0x100 */

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 pad2[0x42];
} UnkStruct_802E8F94; /* size = 0x44 */

extern UnkStruct_80364AF0 D_80364AF0[];
extern UnkStruct_802E8F94 D_802E8F94[];
extern u64 D_80364A90;
extern s32 D_802FA26C;
extern u8 D_8039C53C[];
void func_80261570(f32);
void func_8028B3E0(void);
void func_801ECF5C(void);
void func_801ED4B8(void);

u8 func_8028653C(void) {
    s32 sp34;
    UnkStruct_80364AF0 *sp30;
    u8 sp2F;
    u8 sp2E;
    u8 sp2D;
    u8 sp2C;
    u8 sp2B;

    sp30 = &D_80364AF0[D_80364AE8];
    sp2F = 1;
    sp2E = 0;
    sp2D = sp30->unk91;
    do {
        sp2F = 1;
        switch (D_80364AF0[D_80364AE8].unk91) {
            case 0:
                if (D_80364A90 == 0x100000000000) {
                    sp2F = 0;
                }
                break;
            case 1:
            case 2:
            case 3:
                for (sp34 = 0; sp34 < 60 && sp2F != 0; sp34++) {
                    if (D_802E8F94[sp34].unk1 == D_80364AF0[D_80364AE8].unk91) {
                        if ((((D_80364AF0[D_80364AE8].unk18[sp34] > 0 && D_80364AF0[D_80364AE8].unk18[sp34] < 6) ? 1 : 0) == 0) &&
                            D_802E8F94[sp34].unk0 == 1) {
                            sp2F = 0;
                        }
                    }
                }
                break;
            case 4:
                if (sp30->unk90 != 0x3F) {
                    sp2F = 0;
                }
                break;
            case 5:
                if ((((D_80364AF0[D_80364AE8].unk18[49] > 0 && D_80364AF0[D_80364AE8].unk18[49] < 6) ? 1 : 0) == 0)) {
                    sp2F = 0;
                }
                break;
            case 6:
                if ((((D_80364AF0[D_80364AE8].unk18[50] > 0 && D_80364AF0[D_80364AE8].unk18[50] < 6) ? 1 : 0) == 0)) {
                    sp2F = 0;
                }
                break;
            case 7:
                if ((((D_80364AF0[D_80364AE8].unk18[40] > 0 && D_80364AF0[D_80364AE8].unk18[40] < 6) ? 1 : 0) == 0)) {
                    sp2F = 0;
                }
                break;
            case 8:
                if (sp30->unkA < 222) {
                    sp2F = 0;
                }
                break;
            case 9:
                if (sp30->unkA >= 234 || D_802FA26C != 0) {
                    func_80261570(0.0f);
                    func_8028B3E0();
                    func_801ECF5C();
                    sp2E = 1;
                } else {
                    sp2F = 0;
                }
                break;
            case 10:
                break;
            case 11:
                if (sp30->unkA < 297 || D_802FA26C != 0) {
                    sp2F = 0;
                } else {
                    func_80261570(0.0f);
                    func_8028B3E0();
                    func_801ED4B8();
                }
                break;
            case 12:
                if (sp30->unkA >= 354 || D_802FA26C != 0) {
                    sp30->unkA = 360;
                    sp30->unkC = 30;
                    func_8029A7E4(" ***** YOU CAN STOP NOW!! ***** \n");
                } else {
                    sp2F = 0;
                }
                break;
            case 13:
                sp2F = 0;
                break;
            default:
                func_8029A7E4("Undefined gameState case !!!!\n");
                break;
        }
        if (D_802FA26C != 0 && D_80364AF0[D_80364AE8].unk91 != 13) {
            if (D_8039C53C[D_80364AE8] != 0) {
                D_80364AF0[D_80364AE8].unk91++;
            }
        } else {
            if (sp2F != 0) {
                D_80364AF0[D_80364AE8].unk91++;
            }
            func_8029A7E4("going to game state %d\n", D_80364AF0[D_80364AE8].unk91);
        }
    } while (sp2F != 0 && sp2E == 0 && D_802FA26C == 0);
    sp2B = D_80364AF0[D_80364AE8].unk91 != sp2D;
    func_8029A7E4("game state %d to %d\n", sp2D, D_80364AF0[D_80364AE8].unk91);
    return sp2B;
}
