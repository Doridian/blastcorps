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
                    sprintf(D_80219FD0[sp68 * 4 + sp6C], "%-7.7s %s", sp7C, sp48);
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
                    sprintf(sp74->unkC, "%s %s", D_8020D800[sp6C], sp28);
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
        func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "frontEndPresent", "bestTimes.c", 0x117);
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
