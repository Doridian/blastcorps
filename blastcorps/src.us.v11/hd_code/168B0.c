#include "common.h"

/* 5-byte records: a u16 value (big-endian), a repeat count, and two s8s. */
typedef struct {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ u8 unk2;
    /* 0x3 */ s8 unk3;
    /* 0x4 */ s8 unk4;
} UnkStruct_80365588; /* size = 0x5 */

extern u8 D_802E8BD0;
extern u8 D_802E8BD8;
extern f32 D_802E8C84[];
extern u8 D_802E8CB0[];
extern char D_80308EE0[];
extern char D_80308F0C[];
extern char D_80308F14[];
extern char D_80308F1C[];
extern char D_80308F90[];
extern char D_80308FA8[];
extern char D_80308FD4[];
extern char D_80308FDC[];
extern u8 D_803643D6;
extern u8 D_803643DB;
extern u8 D_80364A50;
extern u64 D_80364A90;
extern u64 D_80364A98;
extern u8 D_80365360[];
extern u16 D_803653B0[];
extern char D_80365458[];
extern s8 D_80365580;
extern UnkStruct_80365588 D_80365588[];
extern u8 D_8036698C;
extern s32 D_80366990;
extern s32 D_80366994;
extern s32 D_80366998;
extern s32 D_8036699C;
extern s32 D_803669A0;
extern u16 D_803669A4;
extern s8 D_803669A6;
extern s8 D_803669A7;
extern u8 D_803669A8;
extern UnkStruct_80365588 *D_803669AC;
extern s16 D_8036BB1C;
extern u16 D_80370C30;
extern s8 D_80370C32;
extern s8 D_80370C33;
extern u8 D_8039CAF0[][0x200];

void func_8029A7E4(char *, ...);
void func_802A1040(u16, u8 *, s32);
s8 func_80272C5C(u8 *, s32, s32, s32, s32, f32);
void func_80275270(u64, f32);
void func_80275390(u64);
s32 func_802753C0(void);
s32 func_8025B300(u8 *arg0);
s32 func_8025B370(u16 *arg0);

void func_8025B070(void) {
    s32 sp4;

    for (sp4 = 0; sp4 < 0x50; sp4++) {
        D_80365360[sp4] = 0;
        D_803653B0[sp4] = 0;
    }
}

u8 *func_8025B0B8(u16 arg0) {
    s32 sp1C;
    u8 sp1B;

    sp1B = 0;
    sp1C = 0;
    while (sp1C < 0x50 && sp1B == 0) {
        if (D_803653B0[sp1C] == arg0) {
            sp1B = 1;
        } else {
            sp1C++;
        }
    }
    if (!sp1B) {
        sp1C = 0;
        while (sp1C < 0x50 && sp1B == 0) {
            if (D_803653B0[sp1C] == 0) {
                func_802A1040(arg0, D_8039CAF0[sp1C], 0);
                D_803653B0[sp1C] = arg0;
                sp1B = 1;
            } else {
                sp1C++;
            }
        }
    }
    if (!sp1B) {
        sp1C = 0;
        while (sp1C < 0x50 && sp1B == 0) {
            if (D_80365360[sp1C] == 0) {
                func_802A1040(arg0, D_8039CAF0[sp1C], 0);
                D_803653B0[sp1C] = arg0;
                sp1B = 1;
            } else {
                sp1C++;
            }
        }
    }
    if (sp1B == 0) {
        func_8029A7E4(D_80308EE0, D_80308F0C, D_80308F14, 0x51);
    }
    if (sp1B != 0) {
        D_80365360[sp1C] = 3;
    }
    return D_8039CAF0[sp1C];
}

void func_8025B2B8(void) {
    s32 sp4;

    for (sp4 = 0; sp4 < 0x50; sp4++) {
        if (D_80365360[sp4] != 0) {
            D_80365360[sp4]--;
        }
    }
}

s32 func_8025B300(u8 *arg0) {
    s32 sp4;
    s32 sp0;

    sp4 = 0;
    sp0 = 0;
    if (arg0 != NULL && *arg0 != 0) {
        do {
            if (arg0[sp4] == '*') {
                sp0++;
            }
        } while (arg0[++sp4] != 0);
    }
    return sp4 - sp0;
}

s32 func_8025B370(u16 *arg0) {
    s32 sp4;
    s32 sp0;

    sp4 = 0;
    sp0 = 0;
    if (arg0 != NULL) {
        for (; arg0[sp4] != 0xFFE; sp4++) {
            if (arg0[sp4] == 0x1000) {
                sp0++;
            }
        }
    }
    return sp4 - sp0;
}

s32 func_8025B3F0(u8 *arg0, u8 *arg1) {
    s32 sp2C;
    s32 sp28;

    if ((sp28 = func_8025B300(arg0)) != func_8025B300(arg1)) {
        return 1;
    }
    for (sp2C = 0; sp2C < sp28; sp2C++) {
        if (arg0[sp2C] != arg1[sp2C]) {
            return 1;
        }
    }
    return 0;
}

s32 func_8025B498(s16 arg0, u16 arg1, u8 *arg2, s32 arg3) {
    s32 sp2C;
    s16 sp2A;
    register s32 len;

    sp2C = 0;
    len = func_8025B300(arg2);
    sp2A = arg0 - ((*D_802E8C84 * (len - 1) + 1.0f) * arg1) / 2.0;
    if (sp2C) {
    }
    return sp2A;
}

char *func_8025B558(u16 *arg0) {
    s32 sp4;

    sp4 = 0;
    while (arg0[sp4] != 0 && sp4 < 0xFF) {
        D_80365458[sp4] = arg0[sp4++];
    }
    D_80365458[sp4] = 0;
    return D_80365458;
}

u16 *func_8025B5D4(u16 *arg0, u16 *arg1, u16 *arg2, s32 arg3) {
    u8 sp34[12];
    s32 sp30;
    s32 sp2C;
    s32 sp28;

    sp30 = 0;
    sp2C = 0;
    do {
        switch (arg1[sp30]) {
            case 0x1003:
                for (sp28 = 0; arg2[sp28] != 0xFFE; sp28++, sp2C++) {
                    arg0[sp2C] = arg2[sp28];
                }
                break;
            case 0x1004:
                sprintf((char *)sp34, D_80308F1C, arg3);
                for (sp28 = 0; sp34[sp28] != 0; sp28++, sp2C++) {
                    arg0[sp2C] = sp34[sp28] - 0x20;
                }
                break;
            default:
                arg0[sp2C] = arg1[sp30];
                sp2C++;
                break;
        }
        sp30++;
    } while (arg1[sp30] != 0xFFE);
    arg0[sp2C] = 0xFFE;
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/168B0/func_8025B7AC.s")

void func_8025B918(u16 *arg0, u16 *arg1) {
    s32 sp1C;
    s32 sp18;

    for (sp1C = 0, sp18 = func_8025B370(arg0); sp1C < func_8025B370(arg1); sp1C++, sp18++) {
        arg0[sp18] = arg1[sp1C];
    }
    arg0[sp18] = 0xFFE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/168B0/func_8025B9D0.s")

void func_8025BB38(void) {
    D_80366990 = 0;
    D_803669A8 = 1;
}

void func_8025BB50(void) {
    D_80366998 = D_80366990;
    D_80366994 = 0;
    D_803669AC = D_80365588;
    D_80365580 = func_80272C5C(D_802E8CB0, 0, 1, 1, 1, 1.0f);
    D_803669A0 = D_803669AC[D_80366994].unk2;
}

void func_8025BBE8(u16 arg0, s8 arg1, s8 arg2) {
    if (D_803669A8 == 0) {
        if ((arg0 != D_803669A4) || (arg1 != D_803669A6) || (arg2 != D_803669A7) || (D_8036699C == 0xFF) ||
            (D_80364A98 != 0)) {
            if (D_80366990 < 0x400) {
                D_80365588[D_80366990].unk0 = D_803669A4 >> 8;
                D_80365588[D_80366990].unk1 = D_803669A4 & 0xFF;
                D_80365588[D_80366990].unk3 = D_803669A6;
                D_80365588[D_80366990].unk4 = D_803669A7;
                D_80365588[D_80366990].unk2 = D_8036699C;
                D_80366990++;
                D_8036699C = 0;
            }
        } else {
            D_8036699C++;
        }
    } else {
        D_8036699C = 0;
    }
    D_803669A4 = arg0;
    D_803669A6 = arg1;
    D_803669A7 = arg2;
    D_803669A8 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/168B0/func_8025BD98.s")

void func_8025BEF8(void) {
    s32 sp24;
    s32 sp20;

    if ((D_80366994 > D_80366998) || (D_803643DB != 0 && D_803643D6 != 0 && (D_80364A90 & 0x440))) {
        if ((D_8036BB1C != 1) || ((D_80364A90 & 0x440) && (D_80364A50 == 0))) {
            if (D_802E8BD0 == 0) {
                D_802E8BD8 = 1;
            }
        } else if (func_802753C0() == 0) {
            switch (D_80364A90) {
                case 0x2:
                    func_80275270(0x2, 0.25f);
                    break;
                case 0x100000000000:
                    func_8029A7E4(D_80308F90);
                    func_80275390(0x200000000000);
                    break;
                case 0x40:
                case 0x400:
                    D_802E8BD8 = 1;
                    if (D_80364A90 == 0x400) {
                        func_80275270(0x40, 1.25f);
                    } else {
                        func_80275270(0x40, 0.5f);
                    }
                    break;
                default:
                    func_8029A7E4(D_80308FA8, D_80308FD4, D_80308FDC, 0x184);
                    break;
            }
        }
    } else {
        D_80370C30 = (D_803669AC[D_80366994].unk0 << 8) + D_803669AC[D_80366994].unk1;
        D_80370C32 = D_803669AC[D_80366994].unk3;
        D_80370C33 = D_803669AC[D_80366994].unk4;
        if (--D_803669A0 < 0) {
            D_80366994++;
            D_803669A0 = D_803669AC[D_80366994].unk2;
        }
        if ((D_80364A90 & 0x100000000002) && (D_8036698C != 9)) {
            if ((D_80370C30 & 0xC000) == 0x8000) {
                D_80370C30 &= ~0x8000;
                D_80370C30 |= 0x4000;
            }
            if ((D_80370C30 & 0xC000) == 0x4000) {
                D_80370C30 &= ~0x4000;
                D_80370C30 |= 0x8000;
            }
        }
    }
}
