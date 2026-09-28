#include "common.h"

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1[0x43];
} UnkStruct_802E8F94; /* size = 0x44 */

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

/* Menu entries, sorted with func_801F7FF4. */
typedef struct {
    /* 0x00 */ u16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s16 unk8;
    /* 0x0C */ char *unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ u8 unk14;
    /* 0x16 */ u16 unk16;
    /* 0x18 */ u8 unk18;
    /* 0x19 */ u8 unk19;
    /* 0x1A */ u8 unk1A;
} UnkStruct_8036BB24; /* size = 0x1C */

void func_8029A7E4(char *, ...);
u8 func_8028FCD4(OSMesgQueue *, u8 *);
u8 func_8028A370(void);
s32 func_8025B300(u8 *);
void func_80270E50(void *sc, void *client, OSMesgQueue *mq, s32 arg3, s32 arg4);
u8 __osContDataCrc(u8 *);
void func_801F58E8(void *);
void func_801F74B0(u8 *);

extern OSThread D_80218D30;
extern u8 D_80218EE0[];
extern u8 D_80218EF8[];
extern OSMesgQueue D_80219EF8;
extern OSMesg D_80219F10[];
extern OSMesgQueue D_80219F30;
extern OSMesg D_80219F48[];
extern OSMesgQueue D_80219F50;
extern OSMesg D_80219F68[];
extern u8 D_80315440[];
extern u8 D_8020C000[];
extern u8 D_8020C014[];
extern u8 D_8020C01C[];
extern char D_8020F0B0[];
extern char D_8020F0D4[];
extern char D_8020F0FC[];
extern char D_8020F128[];
extern char D_8020F140[];
extern char D_8020F1E0[];
extern char D_8020F20C[];
extern char D_8020F214[];
extern char D_8020F224[];
extern char D_8020F250[];
extern char D_8020F258[];
extern s32 D_80370C00;
extern OSMesgQueue D_80370BF8;
extern OSPfs D_8039B630;
extern s32 D_8039B698[];
extern s8 D_8039C538;
extern OSPfsState D_80218B20[];
extern s32 D_80218D28;
extern s32 D_802E8BDC;
extern UnkStruct_802E8F94 D_802E8F94[];
extern UnkStruct_80364AF0 D_80364AF0[];
extern u8 D_80364AEA;
extern u32 D_8021A828;
extern u8 D_8021A7E8[];


typedef struct {
    /* 0x00 */ u8 unk0[0x10];
    /* 0x10 */ s16 unk10;
    /* 0x12 */ u8 unk12[6];
    /* 0x18 */ u16 unk18;
} UnkStruct_802F8BDC_268;

typedef struct {
    /* 0x000 */ u8 unk0[0x208];
    /* 0x208 */ s16 unk208;
    /* 0x20A */ u8 unk20A[6];
    /* 0x210 */ s16 unk210;
    /* 0x212 */ u8 unk212[0x56];
    /* 0x268 */ UnkStruct_802F8BDC_268 unk268;
} UnkStruct_802F8BDC;

typedef struct {
    /* 0x000 */ u8 unk0[0x124];
    /* 0x124 */ char *unk124;
    /* 0x128 */ void *unk128;
    /* 0x12C */ u8 unk12C[0x2B4];
    /* 0x3E0 */ char *unk3E0;
    /* 0x3E4 */ u8 unk3E4[0x18];
    /* 0x3FC */ char *unk3FC;
    /* 0x400 */ u8 unk400[0x18];
    /* 0x418 */ char *unk418;
} UnkStruct_8020C070;

typedef struct {
    /* 0x00 */ char *unk0;
    /* 0x04 */ u8 unk4[0x18];
} UnkStruct_8020C488; /* size = 0x1C */

Gfx *func_80272ED8(Gfx *, s32, s32, s32, s32, s32, f32);
Gfx *func_80274868(Gfx *);
Gfx *func_80274AA4(Gfx *);
void func_80260650(s32, s32, s32);
void func_801E8EB8(u8, s32);
s32 func_801F81B4(u8);
void func_801F8228(void);

extern u8 D_802E8BF8;
extern u64 D_80364A90;
extern char D_8020F35C[];
extern char D_8020F374[];
extern char D_8020FF34[];
extern char D_8020FF60[];
extern char D_8020FF70[];
extern u8 D_80370C50;
extern u8 D_802E8C44[];
extern u16 D_80364EF0[][16];
extern u8 D_80364AE8;
extern u8 D_80365060[];
extern s32 D_80367738;
extern u16 D_80370C28;
extern u16 D_80370C2A;
extern UnkStruct_8036BB24 *D_8036BB24;
extern UnkStruct_802F8BDC D_802F8BDC[];
extern u8 D_8021A7D0[];
extern u8 D_8021A8F0;
extern u8 D_8039B6B0[];
extern u8 D_8039C4B8[];
extern u8 D_8020BEE0[];
extern char D_8020F268[];
extern char D_8020F270[];
extern char D_8020F2C8[];
extern s32 D_8039C4B4;
extern s32 D_802FA264;
extern u16 D_80364F70[];
extern s32 D_80218EF0;
extern u8 D_802189C0[][0x11];
extern u8 D_80218AD0[][5];
extern char D_80218740[][0x28];
extern UnkStruct_8020C070 D_8020C070[];
extern UnkStruct_8020C488 D_8020C488[];
extern char D_80219F90[];
extern char D_80219FB0[];
extern char D_8020F38C[];
extern char D_8020F39C[];
extern char D_8020F3A0[];
extern char D_8020F3A4[];
extern char D_8020F3A8[];
extern char D_8020F3AC[];
extern char D_8020F3B8[];
extern char D_8020F3C8[];
extern char D_8020F3E0[];
extern u8 D_80301080[];
void func_801F7410(u8 *);
void func_801F8354(u8);
s32 func_801F7F74();
s32 func_801F7FF4(UnkStruct_8036BB24 *, UnkStruct_8036BB24 *);
s32 func_801EF2BC(u16, s32, u8);
void func_801FDE50(void);
void func_802595E0(void *, s32, s32, void *);
void func_80264A34(char *, u16, s32);

extern s32 D_80358070;
extern u8 D_8039C53C[];
extern char D_80219FD0[][0x20];
extern char D_8020D800[][4];
extern char D_8020FF20[];
extern char D_8020FF2C[];
extern char D_8020F2DC[];
extern char D_8020F308[];
extern char D_8020F320[];
extern char D_8020F330[];
extern char D_8020F348[];

s32 func_801F75A4(u8 *, s32);
s32 func_801F76E4(u8 *, s32);
s32 func_801F6BD0(u8, u64 *);
void func_802042D0(OSMesgQueue *, s32, void *, s32);
void func_80204410(OSMesgQueue *, s32, void *, s32);

void func_801F57B0(void) {
    s32 sp24;

    sp24 = 0xDE0;
    osCreateThread(&D_80218D30, 2, func_801F58E8, NULL, D_80218EF8 + 0x1000, 0xB);
    osCreateMesgQueue(&D_80219EF8, D_80219F10, 8);
    osCreateMesgQueue(&D_80219F30, D_80219F48, 1);
    osCreateMesgQueue(&D_80219F50, D_80219F68, 8);
    func_801F74B0(D_8020C000);
    func_801F74B0(D_8020C014);
    func_8029A7E4(D_8020F0B0, sp24);
    func_8029A7E4(D_8020F0D4, 0x100);
    func_80270E50(D_80315440, D_80218EE0, &D_80219F30, 1, 3);
    if (sp24 >= 0xE00) {
        func_8029A7E4(D_8020F0FC, D_8020F128, D_8020F140, 0x68);
    }
    osStartThread(&D_80218D30);
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_front_end/E7B0/func_801F58E8.s")

s32 func_801F5FE4(void) {
    s32 sp24;
    u8 sp23;
    OSMesg sp1C;

    sp1C = NULL;
    if (D_80370C00 != 0) {
        func_8029A7E4(D_8020F1E0, D_8020F20C, D_8020F214, 0x190);
        osRecvMesg(&D_80370BF8, &sp1C, OS_MESG_NOBLOCK);
    }
    if (func_8028FCD4(&D_80370BF8, &sp23) != 0) {
        sp24 = 1;
    } else if (!(sp23 & 1)) {
        sp24 = 1;
    } else {
        sp24 = 0;
    }
    if (sp1C != NULL) {
        func_8029A7E4(D_8020F224, D_8020F250, D_8020F258, 0x19E);
        osSendMesg(&D_80370BF8, sp1C, OS_MESG_NOBLOCK);
    }
    return sp24;
}

s32 func_801F60C8(void) {
    u8 sp1F;
    s32 sp18;

    sp18 = 0;
    D_8039C538 = 4;
    if (func_8028FCD4(&D_80370BF8, &sp1F) != 0) {
        sp18 = 1;
    } else if (!(sp1F & 1)) {
        sp18 = 1;
    }
    if (sp18 == 0) {
        sp18 = osPfsInit(&D_80370BF8, &D_8039B630, 0);
    }
    func_8028A370();
    return sp18;
}

void func_801F6160(u8 arg0) {
    osPfsAllocateFile(&D_8039B630, 0x3031, 0x4E424345, D_8020C000, D_8020C014, 0xE00, &D_8039B698[arg0]);
}

void func_801F61C8(s32 arg0) {
    osPfsDeleteFile(&D_8039B630, 0x3031, 0x4E424345, D_8020C000, D_8020C014);
}

s32 func_801F6210(u8 arg0) {
    s32 sp24;

    sp24 = osPfsDeleteFile(&D_8039B630, D_80218B20[arg0 - 37].company_code, D_80218B20[arg0 - 37].game_code,
                           (u8 *)D_80218B20[arg0 - 37].game_name, (u8 *)D_80218B20[arg0 - 37].ext_name);
    return sp24;
}

s32 func_801F6264(u8 arg0, u8 arg1) {
    s32 sp3C;
    s32 sp38;
    u32 sp34;
    s32 sp30;
    s32 sp2C;
    u8 *sp28;
    u64 sp20;

    sp3C = 0;
    sp28 = (u8 *)&D_80364AF0[arg0];
    for (sp34 = 0; sp34 < 0x100 && arg1 == 1; sp34++) {
        func_8029A7E4(D_8020F268, sp28[sp34]);
    }
    func_8029A7E4(D_8020F270);
    if (arg1 == 1) {
        func_801F75A4(sp28, 0x100);
    }
    if (D_802E8BF8 != 0 || D_80364A90 == 0x40000000000000) {
        if (D_8039C4B4 == 0 || D_802FA264 != 0) {
            for (sp34 = 0; sp34 < 0x100; sp34++) {
                if (arg1 == 1) {
                    D_8039B6B0[sp34] = sp28[sp34];
                    D_8020BEE0[sp34] = sp28[sp34];
                } else {
                    D_8039B6B0[sp34] = D_8020BEE0[sp34];
                    sp28[sp34] = D_8039B6B0[sp34];
                }
            }
        } else if (arg1 == 1) {
            func_802042D0(&D_80370BF8, 0, sp28, 0x100);
        } else {
            func_80204410(&D_80370BF8, 0, sp28, 0x100);
        }
    } else {
        sp2C = 0;
        do {
            sp3C = osPfsFindFile(&D_8039B630, 0x3031, 0x4E424345, D_8020C000, D_8020C014, &D_8039B698[arg0]);
            sp2C++;
        } while (sp3C != 0 && sp2C < 3);
        if (sp3C == 0) {
            sp2C = 0;
            do {
                sp3C = osPfsReadWriteFile(&D_8039B630, D_8039B698[arg0], arg1, 0, 0x100, sp28);
                sp2C++;
            } while (sp3C != 0 && sp2C < 3);
        }
    }
    if (sp3C == 0 && arg1 == 0) {
        sp3C = func_801F76E4(sp28, 0x100);
    }
    if (sp3C == 0 && arg1 == 0) {
        func_801F6BD0(arg0, &sp20);
        if (sp20 != 0x87569AB6CD076AEC) {
            sp3C = 0x6E382;
        }
    }
    return sp3C;
}

s32 func_801F65C4(u8 arg0, u8 arg1, u8 arg2) {
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    u32 sp28;
    u8 *sp24;

    sp34 = 0;
    sp24 = (u8 *)D_80364EF0[arg0];
    sp28 = (arg1 << 5) + 0x100;
    if (arg2 == 1) {
        func_801F75A4(sp24, 0x20);
    }
    if (D_802E8BF8 != 0) {
        for (sp30 = sp28; sp30 < sp28 + 0x20; sp30++) {
            if (arg2 == 1) {
                D_8039B6B0[sp30] = sp24[sp30 - sp28];
            } else {
                sp24[sp30 - sp28] = D_8039B6B0[sp30];
            }
        }
    } else {
        sp34 = osPfsFindFile(&D_8039B630, 0x3031, 0x4E424345, D_8020C000, D_8020C014, &D_8039B698[arg0]);
        if (sp34 == 0) {
            sp34 = osPfsReadWriteFile(&D_8039B630, D_8039B698[arg0], arg2, sp28, 0x20, sp24);
        }
        for (sp30 = 0; sp30 < 0xE; sp30++) {
            func_8029A7E4(D_8020F2C8, arg2, sp30, D_80364EF0[arg0][D_802E8C44[sp30]]);
        }
    }
    if (sp34 == 0 && arg2 == 0) {
        sp34 = func_801F76E4(sp24, 0x20);
    }
    return sp34;
}

s32 func_801F67E4(u8 arg0, u8 arg1, u8 arg2) {
    s32 sp3C;
    s32 sp38;
    u8 sp37;
    u16 *sp30;

    sp3C = 0;
    sp37 = arg1 * 2;
    sp30 = &D_80364F70[sp37 & ~3];
    if (D_802E8BF8 != 0) {
        if (arg0 != D_80364AEA) {
            func_8029A7E4(D_8020F2DC, D_8020F308, D_8020F320, 0x25C);
        }
        if (arg2 == 1) {
            D_80364F70[sp37] = D_80364EF0[arg0][D_802E8C44[D_80364AF0[arg0].unk92[arg1]]];
            D_80364F70[sp37 + 1] = D_80364F70[sp37] ^ 0x55AA;
            func_8029A7E4(D_8020F330, arg1, D_80364F70[sp37], (u32)(sp37 * 2 + 0x100) >> 3, sp30);
            osEepromWrite(&D_80370BF8, (u32)(sp37 * 2 + 0x100) >> 3, sp30);
        } else {
            osEepromRead(&D_80370BF8, (u32)(sp37 * 2 + 0x100) >> 3, sp30);
            for (sp38 = 0; sp38 < 2; sp38++, arg1++) {
                if (((D_80364AF0[arg0].unk18[arg1] > 0 && D_80364AF0[arg0].unk18[arg1] < 6) ? 1 : 0) &&
                    arg1 != 0x31 && arg1 != 0x2F && arg1 != 0x26) {
                    D_80364EF0[arg0][D_802E8C44[D_80364AF0[arg0].unk92[arg1]]] = D_80364F70[arg1 * 2];
                    func_8029A7E4(D_8020F348, arg1, D_80364F70[arg1 * 2], D_80364F70[arg1 * 2 + 1] ^ 0x55AA);
                    if (D_80364F70[arg1 * 2] != (D_80364F70[arg1 * 2 + 1] ^ 0x55AA)) {
                        sp3C = 0x6E382;
                    }
                }
            }
        }
    }
    return sp3C;
}

s32 func_801F6AF4(u8 arg0, u64 arg2) {
    s32 sp24;
    UnkStruct_80364AF0 *sp20;

    sp24 = 0;
    sp20 = &D_80364AF0[arg0];
    if (D_802E8BF8 != 0 || D_80364A90 == 0x40000000000000) {
        osEepromWrite(&D_80370BF8, 0x3F, &arg2);
    } else {
        func_8029A7E4(D_8020F35C, arg2);
        sp24 = osPfsReadWriteFile(&D_8039B630, D_8039B698[arg0], 1, 0xDE0, 0x20, (u8 *)&arg2);
    }
    return sp24;
}

s32 func_801F6BD0(u8 arg0, u64 *arg1) {
    s32 sp44;
    UnkStruct_80364AF0 *sp40;
    u64 sp20[4];

    sp44 = 0;
    sp40 = &D_80364AF0[arg0];
    if (D_802E8BF8 != 0) {
        osEepromRead(&D_80370BF8, 0x3F, arg1);
    } else {
        sp44 = osPfsReadWriteFile(&D_8039B630, D_8039B698[arg0], 0, 0xDE0, 0x20, (u8 *)sp20);
        *arg1 = sp20[0];
        func_8029A7E4(D_8020F374, *arg1);
    }
    return sp44;
}

s32 func_801F6CA4(u8 arg0, u8 arg1, u8 arg2) {
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;

    sp34 = 0;
    sp28 = 0;
    for (sp2C = 0; sp2C < arg1; sp2C++) {
        if (D_802E8F94[sp2C].unk0 == 1 && sp2C != 0x31 && sp2C != 0x2F && sp2C != 0x26) {
            sp28++;
        }
    }
    sp24 = (sp28 << 6) + 0x880;
    if (arg2 == 1) {
        func_801F75A4(D_8039C4B8, 0x40);
    }
    if (D_802E8BF8 != 0) {
        for (sp2C = sp24; sp2C < sp24 + 0x40; sp2C++) {
            if (arg2 == 1) {
                D_8039B6B0[sp2C] = D_8039C4B8[sp2C - sp24];
            } else {
                D_8039C4B8[sp2C - sp24] = D_8039B6B0[sp2C];
            }
        }
    } else {
        sp30 = osPfsFindFile(&D_8039B630, 0x3031, 0x4E424345, D_8020C000, D_8020C014, &D_8039B698[arg0]);
        sp34 = sp30;
        if (sp30 == 0) {
            sp34 = osPfsReadWriteFile(&D_8039B630, D_8039B698[arg0], arg2, sp24, 0x40, D_8039C4B8);
        }
    }
    if (sp34 == 0 && arg2 == 0) {
        sp34 = func_801F76E4(D_8039C4B8, 0x40);
    }
    return sp34;
}

void func_801F6ED4(u8 arg0) {
    osPfsFileState(&D_8039B630, arg0, &D_80218B20[D_80218D28]);
}

s32 func_801F6F18(void) {
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    OSMesg sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;

    D_80218D28 = 0;
    for (sp44 = 0; sp44 < 0x10; sp44++) {
        do {
            osSendMesg(&D_80219EF8, (OSMesg)((u32)((u32)(sp44 << 16) | 0x11) | 0x01000000), OS_MESG_BLOCK);
            osRecvMesg(&D_80219F50, &sp38, OS_MESG_BLOCK);
            if (sp38 != NULL) {
                sp44++;
            }
        } while (sp38 != NULL && sp44 < 0x10);
        if (sp44 < 0x10) {
            bcopy(D_80218B20[D_80218D28].game_name, D_802189C0[D_80218D28], 0x11);
            bcopy(D_80218B20[D_80218D28].ext_name, D_80218AD0[D_80218D28], 5);
            D_802189C0[D_80218D28][0x10] = 0;
            D_80218AD0[D_80218D28][4] = 0;
            sp34 = D_80218B20[D_80218D28].file_size >> 5 >> 3;
            sp30 = D_80218AD0[D_80218D28][0];
            func_801F7410(D_802189C0[D_80218D28]);
            func_801F7410(D_80218AD0[D_80218D28]);
            sprintf(D_80218740[sp44], D_8020F38C, D_802189C0[D_80218D28], sp30 ? '.' : ' ', D_80218AD0[D_80218D28],
                    sp34);
            func_8029A7E4(D_8020F39C, D_80218740[sp44]);
            if (sp34 < 0x63) {
                sprintf(D_80218740[sp44], D_8020F3A0, D_80218740[sp44]);
            }
            if (sp34 < 9) {
                sprintf(D_80218740[sp44], D_8020F3A4, D_80218740[sp44]);
            }
            D_8020C488[D_80218D28].unk0 = D_80218740[sp44];
            D_80218D28++;
        }
    }
    if (D_80218D28 == 0) {
        sprintf(D_80218740[0], D_8020F3A8, D_8020F3AC);
        D_8020C070[0].unk418 = D_80218740[0];
        sp2C = 1;
    } else {
        sp2C = 0;
    }
    D_802F8BDC[0].unk210 = (D_80218D28 + sp2C + 1) / 2 + 0x24;
    D_802F8BDC[0].unk208 = D_80218D28 + sp2C + 4;
    osSendMesg(&D_80219EF8, (OSMesg)0x0100000E, OS_MESG_BLOCK);
    osRecvMesg(&D_80219F50, NULL, OS_MESG_BLOCK);
    sprintf(D_80219F90, D_8020F3B8, D_80218EF0 / 32 / 8);
    D_8020C070[0].unk3E0 = D_80219F90;
    sprintf(D_80219FB0, D_8020F3C8, 0xE);
    D_8020C070[0].unk3FC = D_80219FB0;
    D_8020C070[0].unk124 = D_8020F3E0;
    D_8020C070[0].unk128 = D_80301080;
    return D_80218D28 != 0;
}

s32 func_801F73FC(void) {
    return D_80218D28 != 0;
}

void func_801F7410(u8 *arg0) {
    s32 sp1C;

    for (sp1C = 0; sp1C < func_8025B300(arg0); sp1C++) {
        if (arg0[sp1C] < 0x45) {
            arg0[sp1C] = D_8020C01C[arg0[sp1C]];
        } else {
            arg0[sp1C] = '-';
        }
    }
}

void func_801F74B0(u8 *arg0) {
    s32 sp1C;
    s32 sp18;

    for (sp1C = 0; sp1C < func_8025B300(arg0); sp1C++) {
        sp18 = 0;
        if (D_8020C01C[0] != arg0[sp1C]) {
            do {
            } while (++sp18 < 0x45 && D_8020C01C[sp18] != arg0[sp1C]);
        }
        if (sp18 != 0x45) {
            arg0[sp1C] = sp18;
        } else {
            arg0[sp1C] = 0xF;
        }
    }
}

s32 func_801F75A4(u8 *arg0, s32 arg1) {
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    u8 sp28[4];
    s32 sp24;

    sp2C = (arg1 + 0x7F) >> 7;
    for (sp34 = 0; sp34 < 4; sp34++) {
        sp28[sp34] = 0;
        arg0[arg1 + sp34 - 4] = sp28[sp34];
    }
    for (sp34 = 0; sp34 < sp2C; sp34++) {
        for (sp30 = 0; sp30 < 4; sp30++) {
            if ((sp24 = (sp34 << 7) + (sp30 << 5)) < arg1) {
                sp28[sp30] += __osContDataCrc(arg0 + sp24);
            }
        }
    }
    for (sp34 = 0; sp34 < 4; sp34++) {
        arg0[arg1 + sp34 - 4] = sp28[sp34];
    }
    return 0;
}

s32 func_801F76E4(u8 *arg0, s32 arg1) {
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    u8 sp30[4];
    u8 sp2C[4];
    s32 sp28;

    sp34 = (arg1 + 0x7F) >> 7;
    for (sp3C = 0; sp3C < 4; sp3C++) {
        sp30[sp3C] = arg0[arg1 + sp3C - 4];
        sp2C[sp3C] = 0;
        arg0[arg1 + sp3C - 4] = sp2C[sp3C];
    }
    for (sp3C = 0; sp3C < sp34; sp3C++) {
        for (sp38 = 0; sp38 < 4; sp38++) {
            if ((sp28 = (sp3C << 7) + (sp38 << 5)) < arg1) {
                sp2C[sp38] += __osContDataCrc(arg0 + sp28);
            }
        }
    }
    for (sp3C = 0; sp3C < 4; sp3C++) {
        if (sp2C[sp3C] != sp30[sp3C]) {
            return 0x6E382;
        }
    }
    return 0;
}

void func_801F7850(void) {
    UnkStruct_80364AF0 *sp7C;
    UnkStruct_802F8BDC_268 *sp78;
    UnkStruct_8036BB24 *sp74;
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    char sp48[0x20];
    char sp28[0x20];

    sp7C = &D_80364AF0[D_80364AE8];
    sp78 = &D_802F8BDC[0].unk268;
    D_8036BB24 = (UnkStruct_8036BB24 *)D_80358070;
    D_80358070 += 0x71C;
    for (sp6C = 0; sp6C < 4; sp6C++) {
        if (D_80365060[sp6C] == 1 && D_8039C53C[sp6C] == 0 &&
            ((D_80364AF0[sp6C].unk18[D_802E8BDC] > 0 && D_80364AF0[sp6C].unk18[D_802E8BDC] < 6) ? 1 : 0)) {
            osSendMesg(&D_80219EF8, (OSMesg)((u32)((D_802E8BDC << 8) | 8 | (sp6C << 16)) | 0x01000000),
                       OS_MESG_BLOCK);
            osRecvMesg(&D_80219F50, NULL, OS_MESG_BLOCK);
        } else {
            func_801F8354(sp6C);
        }
    }
    for (sp70 = 0, sp68 = 0; sp70 < 0x10; sp70++) {
        if (func_801F7F74(sp70) != 0 && D_80364EF0[D_80364AEA][D_802E8C44[sp70]] > 0) {
            for (sp6C = 0; sp6C < 4; sp6C++) {
                sp74 = &D_8036BB24[sp68 * 4 + sp6C];
                sp7C = &D_80364AF0[sp6C];
                if (D_80365060[sp6C] == 1 && D_80364EF0[sp6C][D_802E8C44[sp70]] > 0 &&
                    (D_802E8F94[D_802E8BDC].unk0 != 0x80 || sp7C->unk91 >= 0xB)) {
                    func_80264A34(sp48, D_80364EF0[sp6C][D_802E8C44[sp70]], 0);
                    sprintf(D_80219FD0[sp68 * 4 + sp6C], D_8020FF20, sp7C, sp48);
                    sp74->unkC = D_80219FD0[sp68 * 4 + sp6C];
                    sp74->unk10 = 0;
                    sp74->unk14 =
                        func_801EF2BC(D_80364EF0[sp6C][D_802E8C44[sp70]], D_802E8BDC, D_80364AF0[sp6C].unk91) % 5 +
                        0x12;
                    sp74->unk18 = sp6C;
                } else {
                    sp74->unkC = NULL;
                    sp74->unk10 = 0;
                    sp74->unk14 = 0;
                    sp74->unk18 = 4;
                }
                sp74->unk0 = 0x1400;
                sp74->unk2 = 0x24;
                sp74->unk6 = 0x10;
                sp74->unk8 = 0x11;
                sp74->unk16 = D_80364EF0[sp6C][D_802E8C44[sp70]];
                sp74->unk1A = sp70;
            }
            func_802595E0(&D_8036BB24[sp68 * 4], 4, sizeof(UnkStruct_8036BB24), func_801F7FF4);
            for (sp6C = 0; sp6C < 4; sp6C++) {
                sp74 = &D_8036BB24[sp68 * 4 + sp6C];
                sp74->unk4 = sp6C * 0x11;
                if (sp6C == 2) {
                    sp74->unk0 |= 1;
                }
                if (sp74->unkC != NULL) {
                    bcopy(sp74->unkC, sp28, func_8025B300((u8 *)sp74->unkC) + 1);
                    sprintf(sp74->unkC, D_8020FF2C, D_8020D800[sp6C], sp28);
                }
            }
            sp68++;
        }
    }
    func_802595E0(D_8036BB24, sp68, 4 * sizeof(UnkStruct_8036BB24), func_801F7FF4);
    for (sp70 = 0; sp70 < sp68 * 4; sp70++) {
        sp74 = &D_8036BB24[sp70];
        D_8021A7E8[sp70] = sp74->unk18;
        if (!(sp70 & 3)) {
            D_8021A7D0[sp70 / 4] = sp74->unk1A;
        }
        sp74->unk16 = 0x1E;
        sp74->unk4 += (sp70 / 4) * 0x64;
    }
    if (D_802E8F94[D_802E8BDC].unk0 == 0x80) {
        sp74 = &D_8036BB24[sp70];
        sp74->unkC = NULL;
        sp74->unk10 = 0;
        sp74->unk0 = 0x400;
        sp74->unk2 = -0x20;
        sp74->unk4 = 0x28;
        sp74->unk14 = 0xD;
        sp74->unk16 = sp74->unk1A = 0;
        sp78->unk10 = sp68 * 4 + 1;
    } else {
        sp78->unk10 = sp68 * 4;
    }
    sp78->unk18 = 2;
    D_8021A828 = sp68 * 4;
    func_801F8228();
    func_801FDE50();
}

/* K&R: callers pass the index unconverted. */
s32 func_801F7F74(arg0)
    u8 arg0;
{
    if (D_802E8F94[D_802E8BDC].unk0 == 0x80) {
        return arg0 == 0;
    }
    return (D_80364AF0[D_80364AEA].unk10 & (1 << arg0)) ? 1 : 0;
}

s32 func_801F7FF4(UnkStruct_8036BB24 *arg0, UnkStruct_8036BB24 *arg1) {
    if (arg0->unkC != 0 && arg1->unkC != 0) {
        return arg0->unk16 - arg1->unk16;
    }
    if (arg0->unkC != 0) {
        return -1;
    }
    return 1;
}

void func_801F803C(void) {
    s32 sp1C;
    s32 sp18;

    if ((D_80370C28 & 0x2010) && !(D_80370C2A & 0x2010)) {
        sp1C = (D_80364AE8 + 1) % 4;
        for (sp18 = 0; sp18 < 4 && (D_80365060[sp1C % 4] != 1 || func_801F81B4(sp1C % 4) == 0);
             sp18++, sp1C = (sp1C + 1) % 4) {
        }
        if (D_80364AE8 != sp1C) {
            func_80260650(D_80367738, 0x1D, 0);
            func_801E8EB8(D_80364AE8 = sp1C, 1);
            func_801F8228();
        } else {
            func_80260650(D_80367738, 0xD0, 0);
        }
    }
}

s32 func_801F81B4(u8 arg0) {
    u32 sp4;
    u32 sp0;

    sp0 = 0;
    sp4 = D_8021A828;
    if (sp4 != 0 && D_8021A7E8[0] != arg0) {
        do {
        } while (++sp0 < sp4 && D_8021A7E8[sp0] != arg0);
    }
    return sp0 != sp4;
}

void func_801F8228(void) {
    UnkStruct_8036BB24 *sp4;
    u32 sp0;

    for (sp0 = 0; sp0 < D_8021A828; sp0++) {
        sp4 = &D_8036BB24[sp0];
        if (D_8021A7E8[sp0] == D_80364AE8) {
            sp4->unk0 |= 4;
        } else {
            sp4->unk0 &= ~4;
        }
        if (D_8021A7E8[sp0] == D_80364AEA) {
            sp4->unk18 = sp4->unk19 = 6;
        } else if (D_8021A7E8[sp0] == D_80364AE8) {
            sp4->unk18 = sp4->unk19 = 2;
        } else {
            sp4->unk18 = sp4->unk19 = 7;
        }
    }
}

void func_801F8354(u8 arg0) {
    s32 sp24;

    if (D_80370C50 == 0) {
        func_8029A7E4(D_8020FF34, D_8020FF60, D_8020FF70, 0x117);
    }
    if (((D_80364AF0[arg0].unk18[D_802E8BDC] > 0 && D_80364AF0[arg0].unk18[D_802E8BDC] < 6) ? 1 : 0) == 0) {
        for (sp24 = 0; sp24 < 0x10; sp24++) {
            D_80364EF0[arg0][D_802E8C44[sp24]] = 0;
        }
    }
}

Gfx *func_801F8440(s32 arg0, Gfx *arg1) {
    Gfx *sp2C;
    s16 sp2A;

    sp2A = 0;
    sp2C = arg1;
    if (D_802E8F94[D_802E8BDC].unk0 != 0x80) {
        sp2C = func_80274868(sp2C);
        sp2C = func_80272ED8(sp2C, D_8021A7D0[D_802F8BDC[0].unk268.unk18 / 4] + D_8021A8F0, 0x18 - sp2A, 0x64,
                             0xFF - sp2A * 2, 1, 1.0f);
        sp2C = func_80274AA4(sp2C);
    }
    return sp2C;
}
