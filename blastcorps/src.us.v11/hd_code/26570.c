#include "common.h"

typedef struct {
    /* 0x0 */ u16 unk0[2];
} UnkStruct_802FA8A0;

typedef struct {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ u8 pad2[2];
    /* 0x4 */ u8 *unk4;
    /* 0x8 */ u8 unk8;
    /* 0x9 */ u8 unk9;
    /* 0xA */ u8 unkA;
    /* 0xB */ u8 unkB;
} UnkStruct_802FA280; /* size = 0xC */

/* The game's variant of the libultra sample scheduler (sched.h). */
typedef struct {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ OSMesgQueue *unk4;
    /* 0x8 */ u32 unk8;
} UnkStruct_SchedTask50;

typedef struct UnkSchedTask {
    /* 0x00 */ struct UnkSchedTask *next;
    /* 0x04 */ s32 state;
    /* 0x08 */ u32 flags;
    /* 0x0C */ void *framebuffer;
    /* 0x10 */ OSTask list;
    /* 0x50 */ UnkStruct_SchedTask50 *unk50;
    /* 0x54 */ OSMesgQueue *msgQ;
    /* 0x58 */ OSMesg msg;
} UnkSchedTask;

typedef struct UnkSchedClient {
    /* 0x0 */ struct UnkSchedClient *next;
    /* 0x4 */ OSMesgQueue *msgQ;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
} UnkSchedClient;

typedef struct {
    /* 0x000 */ OSMesgQueue interruptQ;
    /* 0x018 */ OSMesg intBuf[16];
    /* 0x058 */ OSMesgQueue cmdQ;
    /* 0x070 */ OSMesg cmdMsgBuf[16];
    /* 0x0B0 */ OSThread thread;
    /* 0x260 */ UnkSchedClient *clientList;
    /* 0x264 */ UnkSchedTask *audioListHead;
    /* 0x268 */ UnkSchedTask *gfxListHead;
    /* 0x26C */ UnkSchedTask *audioListTail;
    /* 0x270 */ UnkSchedTask *gfxListTail;
    /* 0x274 */ UnkSchedTask *curRSPTask;
    /* 0x278 */ UnkSchedTask *curRDPTask;
    /* 0x27C */ s32 unk27C;
    /* 0x280 */ s32 unk280;
    /* 0x284 */ u32 unk284;
    /* 0x288 */ OSTime unk288;
    /* 0x290 */ OSTime unk290;
} UnkSched;

typedef struct {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ s32 unk8;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u16 unk10;
    /* 0x12 */ u8 pad12[0xA];
} UnkStruct_802F8BDC; /* size = 0x1C */

/* Element type of the arrays D_8036BB10 points at. */
typedef struct {
    /* 0x00 */ u16 unk0;
    /* 0x02 */ u8 pad2[0xA];
    /* 0x0C */ u8 *unkC;
    /* 0x10 */ u16 *unk10;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[5];
    /* 0x1A */ s8 unk1A;
} UnkStruct_8036BB10; /* size = 0x1C */

typedef struct {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 pad5;
    /* 0x06 */ u8 unk6[0x26];
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ u8 unk2D;
    /* 0x2E */ s8 unk2E;
    /* 0x2F */ u8 pad2F;
} UnkStruct_802F49F4; /* size = 0x30 */

typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ u16 unk2;
} UnkStruct_8026F644;

typedef struct {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
} UnkStruct_8026FBB0; /* size = 0x6 */

typedef struct {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 unk7;
    /* 0x08 */ Vtx unk8[2][4];
} UnkStruct_8036BED8; /* size = 0x88 */

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ char unk1[0xF];
    /* 0x10 */ s32 unk10;
} UnkStruct_802F9934; /* size = 0x14 */

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x02 */ s16 unk2[16];
} UnkStruct_802F48D0; /* size = 0x22 */

typedef struct {
    /* 0x00 */ u8 unk0[0x88];
    /* 0x88 */ u8 unk88[0x78];
} UnkStruct_80364AF0; /* size = 0x100 */

extern s32 D_802E8BDC;
extern f32 D_80364414;
extern Vtx D_802F9A00[];
extern Vtx D_802F9E00[];
extern f64 D_8030BFC8;
extern u16 D_802E8C8C[];
extern u16 D_802E8C90[];
extern u16 D_802E8C94[];
extern u16 D_802E8C98[];
extern u16 D_802E8C9C[];
extern char D_8030BDDC[];
extern char D_8030BE08[];
extern char D_8030BE10[];
extern char D_8030BE20[];
extern char D_8030BE4C[];
extern char D_8030BE54[];
extern u32 D_803156C4;
extern u32 D_8036BAFC;
extern u32 D_8036BB00;
extern u16 D_8036BB48[];
extern Vtx D_802FA820[2][4];
extern UnkStruct_802FA8A0 D_802FA8A0;
extern f64 D_8030C4D0;
extern f64 D_8030C4D8;
extern u8 D_8036BFC5;
extern f32 D_8036BFC8;
extern f32 D_8036BFCC;
extern f32 D_8036BFD0;
extern UnkStruct_802FA280 D_802FA280[][2];
extern f64 D_8030C4E0;
extern f64 D_8030C4E8;
extern f32 D_8036BFC0;
extern u8 D_8036BFC4;
extern u32 D_803BE718;
extern u32 D_803BE71C;
extern u16 D_803BE720;
extern u16 D_803BE722;
extern OSViMode D_80306E70[];
extern char D_8030C0C0[];
extern char D_8030C0EC[];
extern char D_8030C130[];
extern char D_8030C138[];
extern char D_8030C164[];
extern char D_8030C174[];
extern char D_8030C17C[];
extern char D_8030C19C[];
extern char D_8030C1C8[];
extern char D_8030C1DC[];
extern char D_8030C1E4[];
extern char D_8030C200[];
extern char D_8030C22C[];
extern char D_8030C240[];
extern char D_8030C248[];
extern char D_8030C274[];
extern char D_8030C284[];
extern char D_8030C28C[];
extern char D_8030C2B8[];
extern char D_8030C2C8[];
extern char D_8030C2D0[];
extern char D_8030C2FC[];
extern char D_8030C304[];
extern char D_8030C30C[];
extern char D_8030C338[];
extern char D_8030C364[];
extern char D_8030C36C[];
extern char D_8030C398[];
extern char D_8030C3A8[];
extern char D_8030C3B0[];
extern char D_8030C3DC[];
extern char D_8030C3E0[];
extern char D_8030C3E8[];
extern char D_8030C414[];
extern char D_8030C440[];
extern char D_8030C448[];
extern char D_8030C474[];
extern char D_8030C4A4[];
extern u8 D_802FA270;
extern s32 D_80358060;
/*
 * This file's own .bss.  The functions using these only match with them
 * defined here (a u64's halves share one lui), but until .bss is split the
 * addresses still come from the absolute symbols in undefined_syms_auto.
 */
OSTime D_8036BEF0;
OSTime D_8036BEF8;
OSTime D_8036BF00;
extern s32 D_8036BF10;
extern s32 D_8036BF14;
extern s32 D_8036BF18;
extern struct UnkSchedTask *D_8036BF1C;
extern u32 D_8036BF20;
extern u32 D_8036BF24;
extern u32 D_8036BF2C;
OSTime D_8036BF38;
OSTime D_8036BF40;
OSTime D_8036BF48;
OSTime D_8036BF50;
extern OSTimer D_8036BF78;
extern s32 D_8036BFBC;
extern u16 D_803C30A8[];
extern UnkStruct_8036BB10 D_8020C070[];
extern u8 D_802F4868[];
extern u8 D_802F4870[];
extern UnkStruct_802F49F4 D_802F49F4[];
extern UnkStruct_8036BB10 D_802F5804[];
extern UnkStruct_802F8BDC D_802F8BDC[];
extern char D_8030BC98[];
extern char D_8030BCC4[];
extern char D_8030BD04[];
extern char D_8030BD0C[];
extern char D_8030BD38[];
extern char D_8030BD78[];
extern u64 D_80364A98;
extern u32 D_80364AA8;
extern u8 D_8036BA98[];
extern UnkStruct_8036BB10 *D_8036BB10;
extern UnkStruct_8036BB10 *D_8036BB24;
extern u16 D_8036BB04;
extern u16 D_8036BB06;
extern s16 D_8036BB1E;
extern char D_8030BE64[];
extern char D_8030BE90[];
extern char D_8030BE94[];
extern char D_8030BE9C[];
extern UnkStruct_802F9934 D_802F9934[];
extern s32 D_803F7684;
extern u8 D_802E8BD0;
extern s32 D_802FA200[];
extern s32 D_803643E0;
extern s32 D_803643E4;
extern s32 D_803643E8;
extern u8 D_80364456;
extern s32 D_80367738;
extern Vtx D_802F99C0[4];
extern f32 D_8030BFC0;
extern u8 *D_80358070;
extern u16 D_8036BBB0[];
extern s32 D_8036BED4;
extern UnkStruct_8036BED8 *D_8036BED8;
extern f32 D_8036BEDC;
extern u8 D_8036BEE0;
extern u16 D_8036EA7C;
extern u16 D_8036EB90;
extern s32 D_803BE70C;
extern s32 D_803BE710;
extern s16 D_803BE714;
extern s16 D_8036BB18;
extern s16 D_8036BB1C;
extern UnkStruct_802F48D0 D_802F48D0[];
extern u8 D_802F499A[];
extern char D_8030BB50[];
extern char D_8030BB7C[];
extern char D_8030BB8C[];
extern char D_8030BB94[];
extern char D_8030BBA4[];
extern char D_8030BBD0[];
extern char D_8030BBE8[];
extern char D_8030BBF0[];
extern char D_8030BC1C[];
extern char D_8030BC24[];
extern char D_8030BC2C[];
extern char D_8030BC38[];
extern char D_8030BC64[];
extern char D_8030BC74[];
extern char D_8030BC7C[];
extern u64 D_80364A90;
extern u8 D_80364AE8;
extern UnkStruct_80364AF0 D_80364AF0[];
extern u8 D_8036BAA2[];
extern u16 D_8036BB14;
extern s16 D_8036BB1A;

void func_8026AF6C(u16 arg0);
void func_8029A7E4(char *, ...);
s32 func_80270A54(UnkStruct_8036BED8 *arg0);
char *func_8025B558(u16 *);
void func_802A0B00(u16, s32);
void osCreateViManager(s32);
void func_80270F7C(void *);
void func_80271C24(UnkSched *, UnkSchedTask *);
void func_80271CE4(UnkSched *, s32);
void func_80271E88(UnkSched *);
s32 func_80271A84(UnkSched *, UnkSchedTask *);
s32 func_80271F48(OSMesgQueue *, OSMesg, s32);
void func_8026BA7C(UnkStruct_802F8BDC *arg0);
Gfx *func_8026BCE0(Gfx *, s32, s32 *);
s32 func_8026F92C(u64);
u8 func_8026FA38(char **, s32 *);
void func_8026FB50(UnkStruct_802F8BDC *);
u16 func_8026F8A8(u16, u16, u16, u16);
void func_8026A5CC(u64 *dst, u64 *src, s32 size);
s32 func_8026A6F0(s32, s32, s32, s32, s32, s32);
void func_802AC544(s32, s32, s32);
void func_80260650(s32, u16, s32);
s8 func_80272C5C(u8 *, s32, s32, s32, s32, f32);

u8 func_8026AD30(s16 arg0) {
    UnkStruct_802F48D0 *sp2C;
    u8 sp2B;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    sp2B = 0;
    if (!(D_80364A90 & 0x2104)) {
        return 0;
    }
    if (D_80364AF0[D_80364AE8].unk88[9] >= 11) {
        return 0;
    }
    for (sp24 = 0; sp24 < 8 && sp2B == 0; sp24++) {
        sp2C = &D_802F48D0[sp24];
        if (sp2C->unk0 == D_802E8BDC) {
            for (sp20 = 0; sp20 < 16 && sp2B == 0 && sp2C->unk2[sp20] != -1; sp20++) {
                if (sp2C->unk2[sp20] == arg0) {
                    sp1C = D_80364AF0[D_80364AE8].unk88[arg0] < D_802F499A[arg0];
                    sp18 = D_802E8BDC == 0;
                    if (D_8036BAA2[arg0] == 0 && (sp18 || sp1C)) {
                        if (sp1C && !sp18) {
                            D_80364AF0[D_80364AE8].unk88[arg0]++;
                        }
                        D_8036BAA2[arg0] = 1;
                        func_8026AF6C(arg0 | 0x8000 | 0x2000);
                        sp2B = 1;
                    }
                }
            }
        }
    }
    return sp2B;
}

void func_8026AF6C(u16 arg0) {
    u16 sp1E;
    u16 sp1C;

    sp1E = D_8036BB14 & 0xFF;
    sp1C = arg0 & 0xFF;
    if (D_8036BB14) {
        if (D_8036BB14) {
            func_8029A7E4(D_8030BB50, D_8030BB7C, D_8030BB8C, 0x520);
        }
        func_8029A7E4(D_8030BB94, arg0, D_8036BB14);
    }
    if ((arg0 & 0x4000) && (arg0 != 0x4000)) {
        func_8029A7E4(D_8030BBA4, D_8030BBD0, D_8030BBE8, 0x525);
    }
    if ((sp1C == 0x1E) || (sp1C == 0x23) || (sp1C == 5) || (sp1C == 0xE)) {
        D_8036BB1A = -1;
    }
    if ((sp1E == 0x1E) || (sp1E == 0x23) || (sp1E == 5) || (sp1E == 0xE)) {
        func_8029A7E4(D_8030BBF0, D_8030BC1C, D_8030BC24, 0x52C);
        func_8029A7E4(D_8030BC2C);
        return;
    }
    if (D_8036BB14) {
        if (D_8036BB14) {
            func_8029A7E4(D_8030BC38, D_8030BC64, D_8030BC74, 0x533);
        }
        func_8029A7E4(D_8030BC7C, arg0, D_8036BB14);
    }
    D_8036BB14 = arg0;
}

u16 func_8026B10C(void) {
    return D_8036BB14;
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/26570/func_8026B118.s")

void func_8026B8F8(void) {
    if (D_80364AA8 & 0x20) {
        D_8020C070[23].unk0 |= 0x400;
        D_8020C070[26].unk0 |= 0x400;
        D_802F5804[27].unk0 |= 0x400;
        D_802F5804[28].unk0 |= 0x400;
        D_8020C070[23].unk14 = D_8020C070[26].unk14 = D_802F5804[27].unk14 = D_802F5804[28].unk14 = func_8026FA38(NULL, NULL);
        if (D_80364A98 == 0x40) {
            func_8026BA7C(&D_802F8BDC[D_802F4870[func_8026F92C(D_80364AA8)]]);
        } else {
            func_8026BA7C(&D_802F8BDC[D_802F4868[func_8026F92C(D_80364AA8)]]);
        }
    }
}

void func_8026BA7C(UnkStruct_802F8BDC *arg0) {
    UnkStruct_802F49F4 *sp2C;
    s32 sp28;
    u8 sp27;
    UnkStruct_8036BB10 *sp20;

    sp27 = 4;
    func_8026FB50(arg0);
    if (arg0->unk8 & 0x20000) {
        sp27 = 0;
    }
    for (sp28 = arg0->unkE; sp28 < arg0->unkE + arg0->unk10; sp28++) {
        sp20 = &D_8036BB10[sp28];
        if (sp20->unk0 & 0x400) {
            sp2C = &D_802F49F4[sp20->unk14];
            if (sp2C->unk2E == -1) {
                sp20->unk1A = func_80272C5C(sp2C->unk6, 0, sp2C->unk4, sp2C->unk2C, sp2C->unk2D | sp27, 1.0f);
                D_8036BA98[sp20->unk14] = 0;
            } else {
                sp20->unk1A = sp2C->unk2E;
            }
        }
    }
}

void func_8026BBD0(Gfx *arg0, s32 arg1, s32 *arg2) {
    Gfx *gfx;

    gfx = arg0;
    if (D_8036BB1C == 1 && D_8036BB18 != -1) {
        func_8029A7E4(D_8030BC98, D_8030BCC4, D_8030BD04, 0x61F);
    }
    gfx = func_8026BCE0(gfx, arg1, arg2);
    if (D_8036BB1C == 1 && D_8036BB18 != -1) {
        func_8029A7E4(D_8030BD0C, D_8030BD38, D_8030BD78, 0x623);
    }
    gDPPipeSync(gfx++);
    *arg2 += gfx - arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/26570/func_8026BCE0.s")

void func_8026EF70(UnkStruct_802F8BDC *arg0) {
    if (arg0->unk8 & 0x80) {
        D_8036BB04 = func_8026F8A8(arg0->unkE, arg0->unk10, arg0->unkE - 1, 0x100);
        D_8036BB06 = 0;
        if (D_8036BB04 + 1 == arg0->unkE) {
            D_8036BB1E = 0;
        } else {
            D_8036BB1E = 1;
        }
    } else {
        D_8036BB1E = 0;
    }
}

void *func_8026F004(UnkStruct_802F8BDC *arg0, u16 arg1, u8 arg2) {
    UnkStruct_8036BB10 *sp3C;
    u8 sp3B;
    u8 *sp34;
    u16 *sp30;
    u16 sp2E;
    s32 sp28;
    u16 sp26;

    sp3C = &D_8036BB10[arg1];
    if (arg2) {
        sp3B = 1;
    } else {
        sp3B = 0;
    }
    sp34 = sp3C->unkC;
    sp30 = sp3C->unk10;
    D_8036BB48[0] = D_802E8C98[sp3B];
    switch (D_8036BB1E) {
        case 0:
            if (arg2) {
                return sp30;
            }
            return sp34;
        case 1:
            if (D_8036BB1C == 2) {
                D_8036BB1E = 2;
                D_8036BB00 = D_803156C4;
            }
            break;
        case 2:
            if (arg1 < D_8036BB04) {
                if (arg2) {
                    return sp30;
                }
                return sp34;
            }
            if (arg1 <= D_8036BB04) {
                if (D_803156C4 - D_8036BB00 >= 5) {
                    D_8036BB00 = D_803156C4;
                    D_8036BB06++;
                    if (arg2) {
                        sp2E = sp30[D_8036BB06];
                    } else {
                        sp2E = sp34[D_8036BB06];
                    }
                    if (sp2E == D_802E8C90[sp3B]) {
                        func_80260650(D_80367738, 0x91, 0);
                    } else if (sp2E != D_802E8C94[sp3B] && sp2E != D_802E8C98[sp3B] && sp2E != D_802E8C8C[sp3B]) {
                        func_80260650(D_80367738, 0x22, 0);
                    }
                }
                if (arg2) {
                    if (sp30 == NULL) {
                        func_8029A7E4(D_8030BDDC, D_8030BE08, D_8030BE10, 0x46);
                    }
                } else {
                    if (sp34 == NULL) {
                        func_8029A7E4(D_8030BE20, D_8030BE4C, D_8030BE54, 0x46);
                    }
                }
                sp28 = 0;
                if (arg2) {
                    while (sp30[sp28] != D_802E8C98[sp3B]) {
                        D_8036BB48[sp28] = sp30[sp28++];
                    }
                } else {
                    while (sp34[sp28] != D_802E8C98[sp3B]) {
                        D_8036BB48[sp28++] = sp34[sp28];
                    }
                }
                D_8036BB48[sp28] = D_802E8C98[sp3B];
                if (D_8036BB48[D_8036BB06] == D_802E8C98[sp3B]) {
                    sp26 = func_8026F8A8(arg0->unkE, arg0->unk10, D_8036BB04, 0x100);
                    if (sp26 == D_8036BB04) {
                        D_8036BB1E = 0;
                        if ((arg0->unk8 & 0x400000) && D_8036BB1C == 2) {
                            D_8036BAFC = D_803156C4;
                        }
                    } else {
                        func_80260650(D_80367738, 0x23, 0);
                        D_8036BB04 = sp26;
                    }
                    D_8036BB06 = 0;
                } else {
                    D_8036BB48[D_8036BB06] = D_802E8C98[sp3B];
                    if (!(sp3C->unk0 & 0x4000) && D_803156C4 % 10 >= 6) {
                        D_8036BB48[D_8036BB06] = D_802E8C9C[sp3B];
                        D_8036BB48[D_8036BB06 + 1] = D_802E8C98[sp3B];
                    }
                }
                if (arg2) {
                    return D_8036BB48;
                }
                return func_8025B558(D_8036BB48);
            }
            break;
    }
    if ((sp3C->unk0 & 0x100) || (sp3C->unk0 & 0x200)) {
        if (arg2) {
            return D_8036BB48;
        }
        return func_8025B558(D_8036BB48);
    }
    if (arg2) {
        return sp30;
    }
    return sp34;
}

#define ABS(x) ((x) > 0 ? (x) : -(x))
#define F644_VOL0(a, b) (0x200 - (ABS(b) << 9) / ((a)->unk2 / 3))
#define F644_VOL(a, b) (F644_VOL0(a, b) >= 0x100 ? 0xFF : F644_VOL0(a, b))

u8 func_8026F644(UnkStruct_8026F644 *arg0, u16 *arg1, s16 arg2) {
    if (*arg1 & 0x1000) {
        return F644_VOL(arg0, arg2) < 0 ? 0 : F644_VOL(arg0, arg2);
    }
    return 0xFF;
}

u16 func_8026F82C(u16 arg0, u16 arg1, u16 arg2) {
    s32 i;

    for (i = arg1 - 1; i >= arg0; i--) {
        if (D_8036BB10[i].unk0 & arg2) {
            return i;
        }
    }
    return arg1;
}

u16 func_8026F8A8(u16 arg0, u16 arg1, u16 arg2, u16 arg3) {
    s32 i;

    for (i = arg2 + 1; i < arg0 + arg1; i++) {
        if (D_8036BB10[i].unk0 & arg3) {
            return i;
        }
    }
    return arg2;
}

s32 func_8026F92C(u64 arg0) {
    s64 i;

    if (arg0 == 0) {
        func_8029A7E4(D_8030BE64, D_8030BE90, D_8030BE94, 0x8DE);
    }
    if (arg0 == 0) {
        return -1;
    }
    for (i = 0; !(((u64) 1 << i) & arg0); i++) {
    }
    return i;
}

u8 func_8026FA38(char **arg0, s32 *arg1) {
    s32 i;
    s32 sp18;

    sp18 = 0;
    func_8029A7E4(D_8030BE9C, D_803F7684);
    for (i = 0; i < 7 && sp18 == 0; i++) {
        if (D_802F9934[i].unk0 == D_803F7684) {
            sp18 = i + 0x1A;
        }
    }
    if (sp18 == 0) {
        sp18 = 0x1A;
        i = 1;
    }
    if (arg0 != NULL) {
        *arg0 = D_802F9934[i - 1].unk1;
    }
    if (arg1 != NULL) {
        *arg1 = D_802F9934[i - 1].unk10;
    }
    return sp18;
}

void func_8026FB50(UnkStruct_802F8BDC *arg0) {
    if (arg0->unk8 & 0x8000) {
        D_8036BB10 = D_8036BB24;
    } else if (arg0->unk8 & 0x800) {
        D_8036BB10 = D_8020C070;
    } else {
        D_8036BB10 = D_802F5804;
    }
}

void func_8026FBB0(UnkStruct_8026FBB0 *arg0, UnkStruct_8026FBB0 *arg1) {
    s32 pad;

    D_8036EB90 = 0;
    D_8036EA7C = 0;
    if (D_80364A90 != 0x40) {
        D_8036BED4 = D_8036BBB0[0] = 0;
    }
    D_8036BED8 = (UnkStruct_8036BED8 *) D_80358070;
    D_8036BEE0 = 0;
    D_8036BEDC = D_8030BFC0;
    while (arg0 != arg1) {
        D_8036BED8[D_8036EB90].unk0 = arg0->unk0;
        D_8036BED8[D_8036EB90].unk2 = arg0->unk2;
        D_8036BED8[D_8036EB90].unk4 = arg0->unk4;
        D_8036BED8[D_8036EB90].unk6 = 0;
        D_8036BED8[D_8036EB90].unk7 = (arg0->unk4 / (D_803BE710 >> 5)) * D_803BE714 + arg0->unk0 / (D_803BE70C >> 5);
        func_8026A5CC((u64 *) D_8036BED8[D_8036EB90].unk8[0], (u64 *) D_802F99C0, 0x40);
        func_8026A5CC((u64 *) D_8036BED8[D_8036EB90].unk8[1], (u64 *) D_802F99C0, 0x40);
        D_8036EB90++;
        arg0++;
    }
    D_80358070 += D_8036EB90 * sizeof(UnkStruct_8036BED8);
}

u8 func_8026FE6C(s32 arg0) {
    return D_8036BED8[arg0].unk6;
}

void func_8026FE8C(s32 arg0) {
    D_8036BED8[arg0].unk6 = 1;
    D_8036EA7C++;
}

void func_8026FEC4(void) {
    s32 i;
    s32 pad;
    s32 sp2C;
    u8 sp2B;
    u8 sp2A;

    sp2A = 0;
    sp2B = (D_803643E8 / D_803BE710) * D_803BE714 + D_803643E0 / D_803BE70C;
    for (i = 0; i < D_8036EB90; i++) {
        if (D_8036BED8[i].unk7 == sp2B && D_8036BED8[i].unk6 == 0) {
            sp2C = func_8026A6F0(D_803643E0 >> 5, D_803643E4 >> 5, D_803643E8 >> 5, D_8036BED8[i].unk0,
                                 D_8036BED8[i].unk2, D_8036BED8[i].unk4);
            if (sp2C < D_802FA200[D_80364456]) {
                if (++D_8036EA7C >= 4 && D_802E8BD0 == 0) {
                    func_8026AD30(0x46);
                }
                if (D_80364A90 != 0x40) {
                    D_8036BBB0[D_8036BED4] = D_8036BBB0[D_8036BED4 + 1] = i;
                    D_8036BED4++;
                }
                func_802AC544(D_8036BED8[i].unk0, D_8036BED8[i].unk2 + 5, D_8036BED8[i].unk4);
                D_8036BED8[i].unk6 = 1;
                if (sp2A == 0) {
                    sp2A = 1;
                    if (D_80364AA8 == 0x40) {
                        func_80260650(D_80367738, 0x3B, 0);
                    } else {
                        func_80260650(D_80367738, 0x27, 0);
                    }
                }
            }
        }
    }
}

void func_802701A8(Gfx **arg0, s32 arg1) {
    Gfx *gfx;
    s32 i;
    s32 j;
    f32 mf[4][4];
    f32 x[4];
    f32 y[4];
    f32 z[4];

    gfx = *arg0;
    gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
    gSPSetGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetRenderMode(gfx++, G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2);
    gDPSetCombineMode(gfx++, G_CC_MODULATERGBA, G_CC_MODULATERGBA);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    if (D_80364414 != D_8036BEDC) {
        D_8036BEE0 ^= 1;
        guRotateF(mf, D_80364414 - D_8030BFC8, 0.0f, 1.0f, 0.0f);
        for (i = 0; i < 4; i++) {
            guMtxXFMF(mf, D_802F99C0[i].v.ob[0], D_802F99C0[i].v.ob[1], D_802F99C0[i].v.ob[2], &x[i], &y[i], &z[i]);
        }
        for (i = 0; i < D_8036EB90; i++) {
            for (j = 0; j < 4; j++) {
                D_8036BED8[i].unk8[D_8036BEE0][j].v.ob[0] = (s16) x[j] + D_8036BED8[i].unk0;
                D_8036BED8[i].unk8[D_8036BEE0][j].v.ob[1] = (s16) y[j] + D_8036BED8[i].unk2;
                D_8036BED8[i].unk8[D_8036BEE0][j].v.ob[2] = (s16) z[j] + D_8036BED8[i].unk4;
            }
        }
    }
    gDPLoadTextureBlock(gfx++, osVirtualToPhysical(D_802F9A00), G_IM_FMT_RGBA, G_IM_SIZ_32b, 16, 16, 0, G_TX_CLAMP,
                        G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    for (i = 0; i < D_8036EB90; i++) {
        if (D_8036BED8[i].unk6 == 0 && func_80270A54(&D_8036BED8[i])) {
            gSPVertex(gfx++, D_8036BED8[i].unk8[D_8036BEE0], 4, 0);
            gSP1Triangle(gfx++, 0, 1, 2, 0);
            gSP1Triangle(gfx++, 0, 2, 3, 0);
        }
    }
    gDPPipeSync(gfx++);
    gDPLoadTextureBlock(gfx++, osVirtualToPhysical(D_802F9E00), G_IM_FMT_RGBA, G_IM_SIZ_32b, 16, 16, 0, G_TX_CLAMP,
                        G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    for (i = 0; i < D_8036EB90; i++) {
        if (D_8036BED8[i].unk6 != 0 && func_80270A54(&D_8036BED8[i])) {
            gSPVertex(gfx++, D_8036BED8[i].unk8[D_8036BEE0], 4, 0);
            gSP1Triangle(gfx++, 0, 1, 2, 0);
            gSP1Triangle(gfx++, 0, 2, 3, 0);
        }
    }
    gDPPipeSync(gfx++);
    *arg0 = gfx;
    D_8036BEDC = D_80364414;
}

s32 func_80270A54(UnkStruct_8036BED8 *arg0) {
    s32 i;
    u8 spB;

    i = 0;
    spB = arg0->unk7;
    while (D_803C30A8[i] != 0xFFFF) {
        if (D_803C30A8[i++] == spB) {
            return 1;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/26570/func_80270AE0.s")

void func_80270D20(UnkSched *sc, void *stack, OSPri priority, u8 mode, u8 numFields) {
    sc->audioListTail = (UnkSchedTask *) &sc->audioListHead;
    sc->gfxListTail = (UnkSchedTask *) &sc->gfxListHead;
    D_8036BF10 = 0;
    D_8036BF1C = NULL;
    osCreateMesgQueue(&sc->interruptQ, sc->intBuf, 16);
    osCreateMesgQueue(&sc->cmdQ, sc->cmdMsgBuf, 16);
    osCreateViManager(0xFE);
    osViSetMode(&D_80306E70[mode]);
    osViBlack(TRUE);
    osSetEventMesg(OS_EVENT_SP, &sc->interruptQ, (OSMesg) 0x29B);
    osSetEventMesg(OS_EVENT_DP, &sc->interruptQ, (OSMesg) 0x29C);
    osSetEventMesg(OS_EVENT_PRENMI, &sc->interruptQ, (OSMesg) 0x29D);
    osSetEventMesg(OS_EVENT_FAULT, &sc->interruptQ, (OSMesg) 0x2A0);
    osViSetEvent(&sc->interruptQ, (OSMesg) 0x29A, numFields);
    osCreateThread(&sc->thread, 5, func_80270F7C, sc, stack, priority);
    osStartThread(&sc->thread);
}

void func_80270E50(UnkSched *sc, UnkSchedClient *c, OSMesgQueue *msgQ, s32 arg3, s32 arg4) {
    OSIntMask mask;

    mask = osSetIntMask(OS_IM_NONE);
    c->msgQ = msgQ;
    c->next = sc->clientList;
    sc->clientList = c;
    c->unk8 = arg3;
    c->unkC = arg4;
    osSetIntMask(mask);
}

void osScRemoveClient(UnkSched *sc, UnkSchedClient *c) {
    UnkSchedClient *client;
    UnkSchedClient *prev;
    OSIntMask mask;

    client = sc->clientList;
    prev = NULL;
    mask = osSetIntMask(OS_IM_NONE);
    while (client != NULL) {
        if (client == c) {
            if (prev != NULL) {
                prev->next = c->next;
            } else {
                sc->clientList = c->next;
            }
            break;
        }
        prev = client;
        client = client->next;
    }
    osSetIntMask(mask);
}

OSMesgQueue *func_80270F74(UnkSched *sc) {
    return &sc->cmdQ;
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/26570/func_80270F7C.s")

void func_802712B4(UnkSched *sc, UnkSchedTask *t) {
    func_80271C24(sc, t);
    if (sc->curRSPTask == NULL) {
        func_80271CE4(sc, 1);
    }
}

void func_802712FC(UnkSched *sc) {
    if (sc->curRSPTask != NULL) {
        func_80271E88(sc);
    } else {
        D_8036BF00 = 0;
        func_80271CE4(sc, 0);
    }
}

void func_80271358(UnkSched *sc) {
    UnkSchedTask *t;
    UnkSchedClient *client;
    s32 i;
    s32 count;

    sc->unk284++;
    if (D_802E8BD0 == 0) {
        sc->unk280++;
    }
    D_8036BF38 = osGetTime();
    if (D_8036BF1C != NULL) {
        osViSwapBuffer(D_8036BF1C->framebuffer);
        D_8036BF18 = D_8036BF14;
        D_8036BF14 = sc->unk284 + 1;
        osDpSetStatus(DPC_SET_FREEZE);
        if (D_8036BF1C->msgQ != NULL) {
            func_80271F48(D_8036BF1C->msgQ, D_8036BF1C->msg, OS_MESG_NOBLOCK);
        }
        D_8036BF1C = NULL;
    } else if (osViGetCurrentFramebuffer() == osViGetNextFramebuffer() && (osDpGetStatus() & DPC_STATUS_FREEZE)) {
        sc->unk288 = osGetTime();
        osDpSetStatus(DPC_CLR_FREEZE);
    }
    count = sc->cmdQ.validCount;
    for (i = 0; i < count; i++) {
        if (osRecvMesg(&sc->cmdQ, (OSMesg *) &t, OS_MESG_NOBLOCK) == -1) {
            func_8029A7E4(D_8030C0C0, D_8030C0EC, D_8030C130, 0x1BD);
        }
        if (sc->unk284 % t->unk50->unk8 == 0) {
            func_80271C24(sc, t);
        } else {
            osSendMesg(&sc->cmdQ, t, OS_MESG_NOBLOCK);
        }
    }
    if (sc->audioListHead != NULL && !(sc->unk284 & 1)) {
        osSetTimer(&D_8036BF78, 280000, 0, sc->audioListHead->unk50->unk4, (OSMesg) 5);
    }
    for (client = sc->clientList; client != NULL; client = client->next) {
        if (client->unkC == 3) {
            osSendMesg(client->msgQ, (OSMesg) 0x29A, OS_MESG_NOBLOCK);
        }
    }
}

void func_802715DC(UnkSched *sc) {
    UnkSchedTask *t;
    OSTime time;

    if (sc->curRSPTask == NULL) {
        func_8029A7E4(D_8030C138, D_8030C164, D_8030C174, 0x1F2);
    }
    t = sc->curRSPTask;
    sc->curRSPTask = NULL;
    if (t->state == 3) {
        D_8036BF00 = osGetTime() - D_8036BEF0;
        if (D_8036BF00 > 0x86470) {
            func_8029A7E4(D_8030C17C, D_8036BF00);
        }
        if (D_8036BF00 > D_8036BEF8) {
            D_8036BEF8 = D_8036BF00;
        }
        if (!osSpTaskYielded(&t->list)) {
            t->state = 2;
            t->flags |= 4;
            func_80271A84(sc, t);
        }
        if (sc->audioListHead == NULL) {
            func_8029A7E4(D_8030C19C, D_8030C1C8, D_8030C1DC, 0x21A);
        }
        if (sc->audioListHead == NULL) {
            func_8029A7E4(D_8030C1E4, D_8036BF00, D_8036BEF8);
        }
        func_80271CE4(sc, 0);
        return;
    }
    if (t->flags & 0x40) {
        time = osGetTime();
        D_8036BF24 = (time - sc->unk290) / 7825;
        D_802FA270 = 1;
    } else if (t->list.t.type == M_AUDTASK) {
        D_8036BF50 = osGetTime();
        D_8036BF40 = D_8036BF48;
    }
    t->state = 2;
    t->flags |= 4;
    if (sc->curRSPTask != NULL) {
        func_8029A7E4(D_8030C200, D_8030C22C, D_8030C240, 0x230);
    }
    if (func_80271A84(sc, t)) {
        if (sc->gfxListHead != NULL && sc->gfxListHead->flags != 0x47) {
            func_80271CE4(sc, 1);
        }
    }
}

void func_80271904(UnkSched *sc) {
    UnkSchedTask *t;
    s32 pad;
    OSTime time;

    if (sc->curRDPTask == NULL) {
        func_8029A7E4(D_8030C248, D_8030C274, D_8030C284, 0x24A);
    }
    t = sc->curRDPTask;
    sc->curRDPTask = NULL;
    t->flags |= 8;
    if (sc->unk284 != D_8036BF14 || (D_80364A90 & 0xC9FD0FE79BFF80B0)) {
        D_8036BF1C = NULL;
        osViSwapBuffer(t->framebuffer);
        D_8036BF18 = D_8036BF14;
        D_8036BF14 = sc->unk284 + 1;
        osDpSetStatus(DPC_SET_FREEZE);
    } else {
        D_8036BF1C = t;
    }
    time = osGetTime();
    D_8036BF20 = (time - sc->unk288) / 7825;
    if (D_80358060 == 3) {
        osViBlack(FALSE);
    }
    func_80271A84(sc, t);
}

s32 func_80271A84(UnkSched *sc, UnkSchedTask *t) {
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    sp20 = t->flags & 3;
    sp1C = (t->flags >> 2) & 3;
    sp18 = t->list.t.type;
    if (!(t->flags & 0x40)) {
        sp20 &= 1;
        sp1C &= 1;
    }
    if (sp20 == sp1C) {
        if (sp18 == M_GFXTASK) {
            if (sc->gfxListHead == NULL) {
                func_8029A7E4(D_8030C28C, D_8030C2B8, D_8030C2C8, 0x27C);
            }
            sc->gfxListHead = sc->gfxListHead->next;
            if (sc->gfxListHead == NULL) {
                sc->gfxListTail = (UnkSchedTask *) &sc->gfxListHead;
            }
        }
        if (t->msgQ != NULL && (D_8036BF1C == NULL || sp18 != M_GFXTASK)) {
            if (t->flags & 0x40) {
                sp24 = func_80271F48(t->msgQ, t->msg, OS_MESG_NOBLOCK);
            } else {
                sp24 = osSendMesg(t->msgQ, t->msg, OS_MESG_NOBLOCK);
            }
            if (sp24 == -1) {
                func_8029A7E4(D_8030C2D0, D_8030C2FC, D_8030C304, 0x289);
            }
        }
        D_8036BFBC = 1;
    } else {
        D_8036BFBC = 0;
    }
    return D_8036BFBC;
}

void func_80271C24(UnkSched *sc, UnkSchedTask *t) {
    s32 type;

    type = t->list.t.type;
    if (type != M_AUDTASK && type != M_GFXTASK) {
        func_8029A7E4(D_8030C30C, D_8030C338, D_8030C364, 0x29C);
    }
    if (type == M_AUDTASK) {
        sc->audioListTail->next = t;
        sc->audioListTail = t;
    } else {
        sc->gfxListTail->next = t;
        sc->gfxListTail = t;
    }
    t->next = NULL;
    t->state = 2;
}

void func_80271CE4(UnkSched *sc, s32 arg1) {
    UnkSchedTask *t;
    OSTime time;

    if (sc->curRSPTask != NULL) {
        func_8029A7E4(D_8030C36C, D_8030C398, D_8030C3A8, 0x2B8);
    }
    if (arg1 == 0) {
        t = sc->audioListHead;
        if (t == NULL) {
            func_8029A7E4(D_8030C3B0, D_8030C3DC, D_8030C3E0, 0x2BD);
        }
        if (t == NULL) {
            return;
        }
        sc->audioListHead = sc->audioListHead->next;
        if (sc->audioListHead == NULL) {
            sc->audioListTail = (UnkSchedTask *) &sc->audioListHead;
        }
        D_8036BF48 = osGetTime();
    } else {
        t = sc->gfxListHead;
        if (D_802FA270 != 0) {
            sc->unk290 = osGetTime();
            time = osGetTime();
            D_8036BF2C = (time - D_8036BF38) / 7825;
            D_802FA270 = 0;
        }
    }
    t->state = 1;
    osSpTaskLoad(&t->list);
    osSpTaskStartGo(&t->list);
    sc->curRSPTask = t;
    if (t->flags & 0x40) {
        sc->curRDPTask = t;
    }
}

void func_80271E88(UnkSched *sc) {
    if (sc->curRSPTask->list.t.type == M_AUDTASK) {
        func_8029A7E4(D_8030C3E8, D_8030C414, D_8030C440, 0x2DF);
    }
    if (sc->curRSPTask->list.t.type == M_GFXTASK) {
        if (sc->curRSPTask->state == 3) {
            func_8029A7E4(D_8030C448, D_8030C474, D_8030C4A4, 0x2E3);
        }
        sc->curRSPTask->state = 3;
        D_8036BEF0 = osGetTime();
        osSpTaskYield();
    }
}

s32 func_80271F48(OSMesgQueue *mq, OSMesg msg, s32 flag) {
    OSTime sp28;
    OSTime sp20;
    s32 sp1C;

    sp28 = D_8036BF38 + 391250 - osGetTime();
    sp20 = osGetTime();
    sp1C = 0;
    osSendMesg(mq, msg, flag);
}

Gfx *func_80271FD0(Gfx *arg0, s32 arg1, u16 arg2, s16 arg3, s16 arg4, s32 *arg5) {
    Gfx *gfx;
    UnkStruct_802FA8A0 sp78;
    s32 i;
    UnkStruct_802FA280 *sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;

    gfx = arg0;
    sp78 = D_802FA8A0;
    if (D_8036BFC4 == 0) {
        *arg5 = 0;
        return gfx;
    }
    sp6C = 120.0 - (f32) arg4 * D_8030C4D0 + D_8036BFC0;
    D_8036BFCC = (0.0 > sp6C) ? 0.0 : sp6C;
    D_8036BFD0 = (0.0 > -sp6C) ? 0.0 : -sp6C;
    *arg5 = D_8036BFCC;
    if (*arg5 <= 0) {
        return gfx;
    }
    D_8036BFC8 = (arg3 - 2048.0) * 0.5;
    D_802FA820[D_8036BFC5][2].v.ob[1] = D_8036BFCC * 4.0 - 1.0;
    D_802FA820[D_8036BFC5][3].v.ob[1] = D_8036BFCC * 4.0 - 1.0;
    gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
    gSPSetGeometryMode(gfx++, G_SHADE | G_SHADING_SMOOTH);
    gSPTexture(gfx++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL1, TEXEL0, TEXEL1_ALPHA, TEXEL0, TEXEL1, TEXEL0, TEXEL0, TEXEL0, 0, 0, 0,
                      COMBINED, 0, 0, 0, COMBINED);
    gDPSetCycleType(gfx++, G_CYC_2CYCLE);
    gDPSetRenderMode(gfx++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    for (i = 0; i < 2; i++) {
        sp70 = &D_802FA280[arg2][i];
        gDPSetTextureImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, sp70->unk4);
        gDPTileSync(gfx++);
        gDPSetTile(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, i << 8, G_TX_LOADTILE, 0, 0, 0, 0, 0, 0, 0);
        gDPLoadSync(gfx++);
        gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, 0, 0x3FF, 0x100);
    }
    gSPMatrix(gfx++, OS_PHYSICAL_TO_K0(arg1 + 0x100), G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPMatrix(gfx++, OS_PHYSICAL_TO_K0(arg1 + 0x1C0), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gDPTileSync(gfx++);
    gDPSetTextureLOD(gfx++, G_TL_TILE);
    for (i = 0; i < 2; i++) {
        sp70 = &D_802FA280[arg2][i];
        gDPSetTile(gfx++, sp78.unk0[i], G_IM_SIZ_16b, 8, i << 8, i, 0, sp70->unkB & 3, 5, i, sp70->unkA & 3, 5, i);
        gDPSetTileSize(gfx++, i, 0, 0, 0x7C, 0x7C);
    }
    sp68 = (D_8036BFC8 + 16.0f) / (1 << sp70->unk8);
    sp60 = D_8030C4D8 / (f32) (1 << sp70->unk8);
    D_802FA820[D_8036BFC5][0].v.tc[0] = sp68 * 32.0;
    D_802FA820[D_8036BFC5][1].v.tc[0] = (sp68 + sp60) * 32.0;
    D_802FA820[D_8036BFC5][2].v.tc[0] = sp68 * 32.0;
    D_802FA820[D_8036BFC5][3].v.tc[0] = (sp68 + sp60) * 32.0;
    sp64 = (D_8036BFCC - D_8036BFC0 - D_8036BFD0) / (1 << sp70->unk9);
    sp5C = (D_8036BFCC - 1.0) / (f32) (1 << sp70->unk9);
    D_802FA820[D_8036BFC5][0].v.tc[1] = sp64 * 32.0;
    D_802FA820[D_8036BFC5][1].v.tc[1] = sp64 * 32.0;
    D_802FA820[D_8036BFC5][2].v.tc[1] = (sp64 - sp5C) * 32.0;
    D_802FA820[D_8036BFC5][3].v.tc[1] = (sp64 - sp5C) * 32.0;
    gSPVertex(gfx++, D_802FA820[D_8036BFC5], 4, 0);
    gDPPipeSync(gfx++);
    gSP1Triangle(gfx++, 0, 1, 2, 0);
    gSP1Triangle(gfx++, 1, 2, 3, 0);
    D_8036BFC5 ^= 1;
    return gfx;
}

void func_802729F0(u16 arg0, u16 arg1) {
    s32 i;
    f32 sp28;
    u16 sp26;

    sp28 = D_803BE720 * D_803BE718;
    sp28 = (D_803BE722 * D_803BE71C + sp28) / 32.0f;
    D_8036BFC4 = 1;
    switch (arg0) {
        case 0:
        case 1:
        case 2:
        case 0x40:
        case 0x800:
        case 0x1000:
            D_8036BFC0 = D_8030C4E0 / sp28;
            break;
        case 4:
        case 0x100:
        case 0x2000:
            D_8036BFC0 = D_8030C4E8 / sp28;
            break;
        default:
            D_8036BFC0 = 0.0f;
            break;
    }
    if (arg1 == 0x34 || arg1 == 0x3B || arg1 == 0x26 || arg1 == 0x11) {
        D_8036BFC0 += 32.0f;
    }
    for (i = 0; i < 2; i++) {
        D_802FA280[arg1][i].unk4 = D_80358070;
        sp26 = D_802FA280[arg1][i].unk0;
        if (sp26 != 0) {
            func_802A0B00(sp26, 0);
        } else {
            D_8036BFC4 = 0;
        }
    }
}

void func_80272C40(s32 arg0) {
}
