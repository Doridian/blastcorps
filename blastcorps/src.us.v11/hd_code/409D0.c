#include "common.h"

/* Indexed [D_80364AE8][D_802E8BDC]. */
typedef struct {
    /* 0x00 */ u8 unk0[0x18];
    /* 0x18 */ u8 unk18[0x3C];
    /* 0x54 */ u8 unk54[0x3E];
    /* 0x92 */ u8 unk92[0x6E];
} UnkStruct_80364AF0; /* size = 0x100 */

/* Indexed by D_802E8BDC. */
typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1[0x43];
} UnkStruct_802E8F94; /* size = 0x44 */

typedef struct {
    /* 0x00 */ u16 unk0;
    /* 0x02 */ u8 unk2[0x1A];
} UnkStruct_802F5804; /* size = 0x1C */

typedef struct {
    /* 0x00 */ u8 unk0[0xB0];
    /* 0xB0 */ s32 unkB0;
    /* 0xB4 */ s16 unkB4;
    /* 0xB6 */ u8 unkB6[0xA];
    /* 0xC0 */ s16 unkC0;
} UnkStruct_802F8BDC;

typedef struct {
    /* 0x00 */ u64 unk0;
} UnkStruct_8039C4B8;

extern UnkStruct_80364AF0 D_80364AF0[];
extern u16 D_80364EF0[][16];
extern UnkStruct_802E8F94 D_802E8F94[];
extern UnkStruct_802F5804 D_802F5804[];
extern UnkStruct_802F5804 D_8020C070[];
extern UnkStruct_802F8BDC D_802F8BDC[];
extern UnkStruct_8039C4B8 D_8039C4B8[];
extern s32 D_802E8BDC;
extern u8 D_802E8C44[];
extern s8 D_802E8BD8;
extern u8 D_802E8BF8;
extern u8 D_80364A87;
extern u64 D_80364A90;
extern u64 D_80364A98;
extern u8 D_80364AE8;
extern u8 D_80364AEA;
extern s32 D_80358064;
extern s32 D_80367738;
extern char D_8036B9A8[][0x20];
extern u32 D_8036EA60;
extern u8 D_8036EA68;
extern u8 D_8036EA69;
extern u16 D_8036EA6C;
extern u32 D_8036EA70;
extern s32 D_8036EA74;
extern u8 D_8036EA78;
extern u8 D_8036EA79;
extern s8 D_8036EA7A;
extern u8 D_8036EA7B;
extern u16 D_8036EA7C;
extern u8 D_8036EA80[];
extern u8 D_8036EA90[];
extern u16 D_8036EB90;
extern u8 D_8036EB92;
extern u8 D_8036EB93;
extern u8 D_8036EB94[];
extern s8 D_8036EB98;
extern s8 D_8036EB99;
extern u8 D_8036EB9C[];
extern u8 D_8039C53C[];
extern s32 D_803156C0;
extern u8 D_80370C50;
extern OSMesgQueue D_80219F50;
extern char D_8030C8B0[];
extern char D_8030C8C0[];
extern char D_8030C8C8[];
extern char D_8030C8D8[];
extern char D_8030C8E8[];
extern char D_8030C8F0[];
extern char D_8030C91C[];
extern char D_8030C92C[];
extern char D_8030C93C[];
extern char D_8030C954[];
extern char D_8030C980[];
extern char D_8030C9B4[];

void func_80255DC8(void);
void func_80256A34(UnkStruct_8039C4B8 *);
void func_80260650(s32, s32, s32);
void func_80264A34(char *, s32, s32);
void func_80264C20(UnkStruct_8039C4B8 *);
void func_8026AD30(s32);
void func_8026AF6C(s32);
s32 func_8026B10C(void);
void func_80275270(u64, f32);
void func_8029A7E4(char *, ...);
void func_802C1DD0(s32);
void func_802C4BF0(UnkStruct_8039C4B8 *);
u32 func_802C4E58(UnkStruct_8039C4B8 *, u8);
void func_802CF5B0(void);
void func_80285A78(u8 *, u8 *);
u16 func_8028604C(u32);

void func_80285190(void) {
    s32 i;

    D_8036EA7B = D_80364AF0[D_80364AE8].unk92[D_802E8BDC];
    D_8036EA74 = D_80364EF0[D_80364AE8][D_802E8C44[(D_802E8F94[D_802E8BDC].unk0 == 1) ? 1 : D_8036EA7B]];
    D_8036EA7A = D_80364AF0[D_80364AE8].unk18[D_802E8BDC] % 8;
    for (i = 0; i < 4; i++) {
        D_8036EB94[i] = 0;
    }
    if (D_80364AF0[D_80364AE8].unk18[D_802E8BDC] > 0 && D_80364AF0[D_80364AE8].unk18[D_802E8BDC] < 6) {
        D_8036EB98 = 1;
    } else {
        D_8036EB98 = 0;
    }
}

u32 func_802852EC(void) {
    u32 sp5C;
    u32 sp58;
    u32 sp54;
    u32 i;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    char sp24[0x20];

    sp48 = 0;
    sp44 = 0;
    if (D_8036EB92 != 0) {
        sp5C = (D_8036EA78 * 100) / D_8036EB92;
    } else {
        sp5C = 100;
    }
    if (D_8036EB93 != 0) {
        sp58 = (D_8036EA79 * 100) / D_8036EB93;
    } else {
        sp58 = 100;
    }
    if (D_8036EB90 != 0) {
        sp54 = (D_8036EA7C * 100) / D_8036EB90;
    } else {
        sp54 = 100;
    }
    sprintf(D_8036B9A8[0], D_8030C8B0, D_8036EA78, sp5C, '%');
    sprintf(D_8036B9A8[1], D_8030C8C0, D_8036EA70);
    sprintf(D_8036B9A8[2], D_8030C8C8, D_8036EA79, sp58, '%');
    sprintf(D_8036B9A8[3], D_8030C8D8, D_8036EA7C, sp54, '%');
    func_80264A34(sp24, D_8036EA74, 0);
    sprintf(D_8036B9A8[4], D_8030C8E8, sp24);
    for (i = 18; i < 23; i++) {
        D_802F5804[i].unk0 = 0x400;
    }
    for (i = 14; i < 18; i++) {
        D_8020C070[i].unk0 = 0x400;
    }
    if (D_80364A98 == 0x40) {
        sp48 = 0x100;
    }
    if (D_80364A90 & 0x30C) {
        sp44 = 0x100;
    }
    if (D_8036EA78 > D_8036EA68) {
        sp4C = sp44 | 4;
    } else {
        sp4C = 0;
    }
    D_8020C070[14].unk0 |= sp4C | 0x80;
    D_802F5804[18].unk0 |= sp4C | sp48 | 0x80;
    if (D_8036EA70 > D_8036EA60) {
        sp4C = sp44 | 4;
    } else {
        sp4C = 0;
    }
    D_8020C070[15].unk0 |= sp4C | 0x80;
    D_802F5804[19].unk0 |= sp4C | sp48 | 0x80;
    if (D_8036EA79 > D_8036EA69) {
        sp4C = sp44 | 4;
    } else {
        sp4C = 0;
    }
    D_8020C070[16].unk0 |= sp4C | 0x80;
    D_802F5804[20].unk0 |= sp4C | sp48 | 0x80;
    if (D_8036EA7C > D_8036EA6C) {
        sp4C = sp44 | 4;
    } else {
        sp4C = 0;
    }
    D_8020C070[17].unk0 |= sp4C | 0x80;
    D_802F5804[21].unk0 |= sp4C | sp48 | 0x80;
    D_802F5804[22].unk0 |= sp48 | 0x80;
    if (D_802E8BF8 != 0) {
        return (sp5C + sp54) / 2;
    }
    return (sp5C + sp58 + sp54) / 3;
}

u8 func_80285814(void) {
    u8 sp27;
    u8 sp26;

    sp27 = 0;
    if (D_80370C50 == 0) {
        func_8029A7E4(D_8030C8F0, D_8030C91C, D_8030C92C, 0x8C);
    }
    D_80370C50 = 1;
    func_80255DC8();
    if (D_80364A90 == 0x4000) {
        osRecvMesg(&D_80219F50, NULL, OS_MESG_BLOCK);
    }
    if ((D_80364AF0[D_80364AE8].unk18[D_802E8BDC] > 0 && D_80364AF0[D_80364AE8].unk18[D_802E8BDC] < 6) ? 1 : 0) {
        if (D_802E8F94[D_802E8BDC].unk0 == 1) {
            if (D_8039C4B8[0].unk0 == 0x1234567887654321) {
                func_80256A34(NULL);
                func_8029A7E4(D_8030C93C);
                sp26 = D_80364AF0[D_80364AE8].unk18[D_802E8BDC];
                if (sp26 == 5) {
                    sp26 = 4;
                }
                if (func_802C4E58(D_8039C4B8, sp26) > 60) {
                    func_8029A7E4(D_8030C954, D_8030C980, D_8030C9B4, 0xA1);
                }
                func_802C4BF0(D_8039C4B8);
                func_802C1DD0(0);
                func_80264C20(D_8039C4B8);
                sp27 = 1;
            } else {
                func_80256A34(D_8039C4B8);
            }
        } else {
            func_80256A34(NULL);
        }
    } else {
        func_80256A34(NULL);
    }
    func_80285A78((u8 *) &D_8036EA70, (u8 *) &D_8036EA60);
    func_80285A78((u8 *) &D_8036EA70, D_8036EA80);
    func_80285A78((u8 *) &D_8036EA70, D_8036EA90);
    return sp27;
}

void func_80285A78(u8 *src, u8 *dst) {
    u32 i;

    for (i = 0; i < 16; i++) {
        dst[i] = src[i];
    }
}

void func_80285AB0(u8 arg0) {
    D_80364A87 |= 2;
    D_80364AF0[D_80364AE8].unk54[D_802E8BDC] |= 1 << (arg0 - 1);
}

s32 func_80285B10(u8 arg0) {
    return (D_80364AF0[D_80364AE8].unk54[D_802E8BDC] & (1 << (arg0 - 1))) ? 1 : 0;
}

void func_80285B68(s32 arg0) {
    if (D_80364A90 & 0x104) {
        if (((D_80364AF0[D_80364AE8].unk18[D_802E8BDC] > 0 && D_80364AF0[D_80364AE8].unk18[D_802E8BDC] < 6) ? 1 : 0) &&
            D_802E8F94[D_802E8BDC].unk0 != 1 && D_80364AE8 == D_80364AEA) {
            func_802CF5B0();
            D_802E8BD8 = 1;
            func_80275270(0x4000, 1.25f);
            D_8039C53C[D_80364AE8] = D_802E8BDC + 1;
            D_8036EB99 = 1;
        }
    }
}

void func_80285CA0(void) {
    func_8026AD30(0x47);
}

void func_80285CC0(void) {
    s32 sp34;
    s32 sp30;
    s32 i;

    sp34 = -1;
    sp30 = 0;
    for (i = 0; i < 4; i++) {
        D_8036EB9C[i] = D_8036EB94[i];
        if (D_8036EB94[i] == 0) {
            switch (i) {
                case 0:
                    if (D_8036EB94[i] = (D_8036EA7C == D_8036EB90)) {
                        sp34 = 0x39;
                    }
                    break;
                case 1:
                    if (D_8036EB94[i] = (D_8036EA79 == D_8036EB93)) {
                        sp34 = 0x3A;
                    }
                    break;
                case 2:
                    func_802C1DD0(0);
                    if (D_8036EB94[i] = (D_8036EA78 == D_8036EB92)) {
                        sp34 = 0x3B;
                    }
                    break;
                case 3:
                    if (D_8036EB94[i] = (D_8036EB94[0] && D_8036EB94[2] && D_8036EB94[1])) {
                        sp34 = 0x3C;
                        sp30 = 0xC6;
                    }
                    break;
            }
        }
    }
    if (D_80358064 != 0) {
        if (sp34 != -1 && !(func_8026B10C() & 0x8000)) {
            func_8026AF6C(sp34 | 0x8000);
        }
        if (sp30 != 0) {
            func_80260650(D_80367738, sp30, 0);
        }
    }
}

void func_80285EF4(s32 arg0) {
    s32 sp1C;

    sp1C = func_8028604C(D_803156C0 - arg0);
    func_802C1DD0(0);
    D_8036EA74 += sp1C;
    func_802852EC();
    D_8036EA74 -= sp1C;
    func_80285A78((u8 *) &D_8036EA70, (u8 *) &D_8036EA60);
    D_802F5804[24].unk0 &= ~1;
    D_802F5804[24].unk0 |= 0x800;
    D_802F5804[23].unk0 &= ~1;
    D_802F5804[23].unk0 |= 0x800;
    D_802F5804[17].unk0 |= 1;
    D_802F5804[17].unk0 &= ~0x800;
    D_802F8BDC[0].unkC0 = 0x11;
    D_802F8BDC[0].unkB0 |= 0x80;
    func_8026AF6C(0x8006);
    D_802F8BDC[0].unkB4 = 0;
    D_802E8BD8 = 1;
}

s32 func_80286038(u16 arg0) {
    return arg0 * 6;
}

u16 func_8028604C(u32 arg0) {
    return (arg0 / 6 >= 60000) ? 59999 : arg0 / 6;
}

u8 func_80286090(s32 arg0) {
    return (D_80364AF0[D_80364AE8].unk18[arg0] > 0 && D_80364AF0[D_80364AE8].unk18[arg0] < 6) ? 1 : 0;
}
