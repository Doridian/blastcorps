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
void func_801F58E8();
void func_801F74B0(u8 *);
void func_801EE390(void);
void func_801EE398(s32);
void func_8028A42C(void);
s32 func_801F5FE4(void);
s32 func_801F60C8(void);
s32 func_801F6160(u8);
s32 func_801F61C8(s32);
s32 func_801F6210(u8);
s32 func_801F6264(u8, u8);
s32 func_801F65C4(u8, u8, u8);
s32 func_801F67E4(u8, u8, u8);
s32 func_801F6AF4(u8, u64);
s32 func_801F6CA4(u8, u8, u8);
s32 func_801F6ED4(u8);
extern s8 D_8039C4B0;
extern s32 D_8036BF10;
extern s32 D_80218D24;
extern s32 D_80219F88;
extern OSThread D_80310BD0;
extern u64 D_80364A98;
extern s16 D_8036BB18;
extern s16 D_8036BB1C;

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
extern s32 D_80370C00;
extern OSMesgQueue D_80370BF8;
extern OSPfs D_8039B630;
extern s32 D_8039B698[];
extern u8 D_8039C538;
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
    func_8029A7E4("current pak file size is %d bytes\n", sp24);
    func_8029A7E4("current playerInfo size is %d bytes\n", 0x100);
    func_80270E50(D_80315440, D_80218EE0, &D_80219F30, 1, 3);
    if (sp24 >= 0xE00) {
        func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "filesize<PFS_FILE_SIZE", "pfsHandler.c", 0x68);
    }
    osStartThread(&D_80218D30);
}

/* The Controller Pak thread (commands from D_80219EF8, replies on D_80219F50). */
void func_801F58E8(void) {
    OSMesg sp3C;
    s32 sp38;
    s32 sp34;
    u8 sp33; /* unused */
    u8 sp32;
    u8 sp31;
    u8 sp30;
    u8 sp2F;
    u8 sp2E;
    u8 sp2D;
    s32 sp28;
    u32 sp24;

    for (;;) {
        D_8039C4B0 = 0;
        sp24 = 0;
        osSetEventMesg(OS_EVENT_SI, &D_80370BF8, NULL);
        osRecvMesg(&D_80219EF8, &sp3C, OS_MESG_BLOCK);
        osSetEventMesg(OS_EVENT_SI, &D_80370BF8, NULL);
        while (D_8036BF10 != 0) {
        }
        sp2F = (u32)sp3C & 0xFF;
        sp31 = ((u32)sp3C >> 8) & 0xFF;
        sp32 = ((u32)sp3C >> 16) & 0xFF;
        sp30 = ((u32)sp3C >> 24) & 0xFF;
        D_8020C014[0] = sp32 + 0x11;
        D_8039C4B0 = 1;
        func_8028A42C();
        func_801EE390();
        D_80218D24 = 0;
        do {
            sp2D = 0;
            sp2E = 0;
            sp28 = 0x5B;
            sp34 = 0;
            switch (sp2F) {
                case 1:
                case 2:
                    sp38 = func_801F60C8();
                    break;
                case 3:
                    sp38 = func_801F6160(sp32);
                    break;
                case 4:
                    sp38 = func_801F61C8(sp32);
                    break;
                case 5:
                    sp38 = func_801F6210(sp32);
                    break;
                case 6:
                    sp38 = func_801F6264(sp32, 0);
                    break;
                case 7:
                    sp38 = func_801F6264(sp32, 1);
                    break;
                case 8:
                    sp38 = func_801F65C4(sp32, sp31, 0);
                    break;
                case 9:
                    sp38 = func_801F65C4(sp32, sp31, 1);
                    break;
                case 10:
                    sp38 = func_801F67E4(sp32, sp31, 0);
                    break;
                case 11:
                    sp38 = func_801F67E4(sp32, sp31, 1);
                    break;
                case 12:
                    sp38 = func_801F6CA4(sp32, sp31, 0);
                    break;
                case 13:
                    sp38 = func_801F6CA4(sp32, sp31, 1);
                    break;
                case 14:
                    sp38 = osPfsFreeBlocks(&D_8039B630, &D_80218EF0);
                    break;
                case 15:
                    sp38 = func_801F5FE4();
                    break;
                case 16:
                    sp2D = 1;
                    sp38 = osEepromProbe(&D_80370BF8);
                    break;
                case 17:
                    sp38 = func_801F6ED4(sp32);
                    break;
                case 18:
                    sp38 = osPfsChecker(&D_8039B630);
                    break;
                case 19:
                    sp38 = 10;
                    break;
                case 20:
                    sp38 = func_801F6AF4(sp32, 0x2704197125121981);
                    break;
                case 21:
                    sp38 = func_801F6AF4(sp32, 0x87569AB6CD076AEC);
                    break;
                case 22:
                    sp38 = 0;
                    break;
                default:
                    func_8029A7E4("Nonsense pak message\n");
                    break;
            }
            func_8029A7E4("pak command %d returned %d\n", sp2F, sp38);
            switch (sp38) {
                case 0x6E382:
                    if ((D_80364A90 & 0x10E18000) || (D_80364A98 & 0x20000000000000)) {
                        sp2D = 1;
                        break;
                    }
                    /* fallthrough */
                case 6:
                case 10:
                case 11:
                    if (sp24 >= 4) {
                        if (sp2F != 0x13) {
                            if (sp38 == 0x6E382) {
                                D_80219F88 = 0x5D;
                            } else {
                                D_80219F88 = 0x5C;
                            }
                            func_801F6AF4(sp32, 0x2704197125121981);
                            sp2E = 0x13;
                        }
                        sp28 = D_80219F88;
                    } else {
                        sp28 = 0;
                        sp24++;
                    }
                    break;
                case 0:
                case 5:
                case 9:
                    sp2D = 1;
                    break;
                case 8:
                    if (!(D_80364A90 & 0x10E18000) || func_801F5FE4() != 0) {
                        break;
                    }
                    /* fallthrough */
                case 7:
                    D_8039C538 = (sp32 < D_8039C538) ? sp32 : D_8039C538;
                    sp2D = 1;
                    break;
                case 3:
                    if (sp24 >= 4) {
                        if (sp2F != 0x13) {
                            func_801F6AF4(sp32, 0x2704197125121981);
                            sp2E = 0x13;
                        }
                        sp28 = 0x5C;
                    } else {
                        func_8029A7E4("trying to fix pak ...\n");
                        if (sp2F != 0x12) {
                            osSendMesg(&D_80219EF8, (OSMesg)(sp2F | (sp31 << 8) | (sp32 << 16) | (sp30 << 24)),
                                       OS_MESG_NOBLOCK);
                        }
                        sp2E = 0x12;
                        sp30 = 0;
                        sp24++;
                    }
                    break;
                case 2:
                    if (sp34 == 8 && !(D_80364A90 & 0x10E18000)) {
                        func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "1==0", "pfsHandler.c", 342);
                        sp2D = 1;
                    }
                    break;
                case 1:
                    if (D_80364A98 & 0x20000000000000) {
                        sp2D = 1;
                    }
                    break;
            }
            /*
             * Dead code IDO still branches over: without it case 1's last
             * `b` to the next instruction is dropped.  Probably a compiled-out
             * debug macro in the original.
             */
            while (0) {
                sp2D = 1;
            }
            sp34 = sp38;
            if (D_8036BF10 == 0 && sp28 != 0 && sp2D == 0 && sp2E == 0 && &D_80310BD0 == D_80219F50.mtqueue) {
                func_801EE398(sp28);
                D_80218D24 = 1;
            }
            if (sp2E != 0) {
                sp2F = sp2E;
                sp2E = 0;
            }
            osRecvMesg(&D_80219F30, NULL, OS_MESG_BLOCK);
        } while (sp2D == 0);
        if (D_80218D24 != 0) {
            D_8036BB1C = 1;
            D_8036BB18 = -1;
        }
        if (sp30 != 0) {
            osSendMesg(&D_80219F50, (OSMesg)sp38, OS_MESG_BLOCK);
        }
    }
}

s32 func_801F5FE4(void) {
    s32 sp24;
    u8 sp23;
    OSMesg sp1C;

    sp1C = NULL;
    if (D_80370C00 != 0) {
        func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "1==0", "pfsHandler.c", 0x190);
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
        func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "1==0", "pfsHandler.c", 0x19E);
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

/*
 * func_801F6160, func_801F61C8 and func_801F6ED4 return nothing, but the pak
 * thread stores what they leave in $v0, so they are int functions with no
 * return statement.
 */
s32 func_801F6160(u8 arg0) {
    osPfsAllocateFile(&D_8039B630, 0x3031, 0x4E424345, D_8020C000, D_8020C014, 0xE00, &D_8039B698[arg0]);
}

s32 func_801F61C8(s32 arg0) {
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
        func_8029A7E4("0x%x, ", sp28[sp34]);
    }
    func_8029A7E4("\n");
    /* An assert that folds away; only its strings are left. */
    if (sizeof(UnkStruct_80364AF0) > 512) {
        func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "sizeof(playerInfo)<=512", "pfsHandler.c", 0);
    }
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
            func_8029A7E4("%d TIME %d = %d\n", arg2, sp30, D_80364EF0[arg0][D_802E8C44[sp30]]);
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
            func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "pn==playerNumberAtStart", "pfsHandler.c", 0x25C);
        }
        if (arg2 == 1) {
            D_80364F70[sp37] = D_80364EF0[arg0][D_802E8C44[D_80364AF0[arg0].unk92[arg1]]];
            D_80364F70[sp37 + 1] = D_80364F70[sp37] ^ 0x55AA;
            func_8029A7E4("%d %d EEWRITE %x %x\n", arg1, D_80364F70[sp37], (u32)(sp37 * 2 + 0x100) >> 3, sp30);
            osEepromWrite(&D_80370BF8, (u32)(sp37 * 2 + 0x100) >> 3, sp30);
        } else {
            osEepromRead(&D_80370BF8, (u32)(sp37 * 2 + 0x100) >> 3, sp30);
            for (sp38 = 0; sp38 < 2; sp38++, arg1++) {
                if (((D_80364AF0[arg0].unk18[arg1] > 0 && D_80364AF0[arg0].unk18[arg1] < 6) ? 1 : 0) &&
                    arg1 != 0x31 && arg1 != 0x2F && arg1 != 0x26) {
                    D_80364EF0[arg0][D_802E8C44[D_80364AF0[arg0].unk92[arg1]]] = D_80364F70[arg1 * 2];
                    func_8029A7E4("%d EETIMES: %d %d\n", arg1, D_80364F70[arg1 * 2], D_80364F70[arg1 * 2 + 1] ^ 0x55AA);
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
        func_8029A7E4("PUTTING SEMAPHORE %llu\n", arg2);
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
        func_8029A7E4("Getting SEMAPHORE %llu\n", *arg1);
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

s32 func_801F6ED4(u8 arg0) {
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
            sprintf(D_80218740[sp44], "%16s%c%-4s (%d)", D_802189C0[D_80218D28], sp30 ? '.' : ' ', D_80218AD0[D_80218D28],
                    sp34);
            func_8029A7E4("%s\n", D_80218740[sp44]);
            if (sp34 < 0x63) {
                sprintf(D_80218740[sp44], "%s ", D_80218740[sp44]);
            }
            if (sp34 < 9) {
                sprintf(D_80218740[sp44], "%s ", D_80218740[sp44]);
            }
            D_8020C488[D_80218D28].unk0 = D_80218740[sp44];
            D_80218D28++;
        }
    }
    if (D_80218D28 == 0) {
        sprintf(D_80218740[0], "%s", "PAK EMPTY!");
        D_8020C070[0].unk418 = D_80218740[0];
        sp2C = 1;
    } else {
        sp2C = 0;
    }
    D_802F8BDC[0].unk210 = (D_80218D28 + sp2C + 1) / 2 + 0x24;
    D_802F8BDC[0].unk208 = D_80218D28 + sp2C + 4;
    osSendMesg(&D_80219EF8, (OSMesg)0x0100000E, OS_MESG_BLOCK);
    osRecvMesg(&D_80219F50, NULL, OS_MESG_BLOCK);
    sprintf(D_80219F90, "%d PAGES FREE", D_80218EF0 / 32 / 8);
    D_8020C070[0].unk3E0 = D_80219F90;
    sprintf(D_80219FB0, "%d NEEDED PER PLAYER", 0xE);
    D_8020C070[0].unk3FC = D_80219FB0;
    D_8020C070[0].unk124 = "DELETE THIS FILE?";
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
