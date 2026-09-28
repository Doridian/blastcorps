#include "common.h"

/* Saved sequence state: a copy of the player's 16 channel states, the
 * sequence position and tempo, and the song number. */
typedef struct {
    /* 0x000 */ u32 chanState[0x40];
    /* 0x100 */ ALCSeqMarker marker;
    /* 0x1EC */ s32 tempo;
    /* 0x1F0 */ u8 unk1F0;
} UnkStruct_80366C30; /* size = 0x1F4 */

/* 0x44-byte records, one per level (indexed by D_802E8BDC). */
typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1[0x43];
} UnkStruct_802E8F94; /* size = 0x44 */

extern s16 D_802E8D00[];
extern u8 D_802E8D8C[];
extern UnkStruct_802E8F94 D_802E8F94[];
extern u64 D_80364A90;
extern u8 D_802E8D84;
extern f32 D_802E8D88;
extern s32 D_802E8BDC;
extern u8 D_802E8DC8[];
extern u8 D_802E8E04[];
extern u8 D_802E8E40[];
extern u16 D_802E8E7C[];
extern s32 D_802E8EB4[][6];
extern s32 D_803156C4;
extern UnkStruct_80366C30 D_80366C30[];
extern UnkStruct_80366C30 *D_80367400;
extern s32 D_80367408[];
extern u8 *D_80367510;
extern ALSeqFile *D_80367514;
extern ALCSeq D_80367518[];
extern u8 D_80367708;
extern f32 D_8036770C;
extern f32 D_80367710;
extern f32 D_80367714;
extern u8 D_80367728;
extern u8 D_80367729;
extern u8 D_8036772A;
extern s32 D_8036772C;
extern u8 D_80367730;
extern ALCSPlayer *D_80367734;
extern s32 D_80367738;
extern s32 D_80367740;

void func_8028B4C4(s32, u8 *, s32 *, s32, s32, s32);
void func_8029A7E4(char *, ...);
void func_80260650(s32, u16, s32);
void func_80260B40(s32, s32);
void func_802609F0(void);
void func_80260A10(void);
void func_80260A30(s32);
s32 func_80264BA4(s32);
void func_802D76C0(ALCSPlayer *);
void func_802D81B0(ALCSPlayer *, ALCSeq *);
void func_802D81F0(ALCSPlayer *);
void alCSPSetTempo(ALCSPlayer *, s32);
s32 func_802D4E10(ALCSPlayer *);

void func_80260EE0(u8 arg0);
void func_80260F60(f32 arg0);
void func_8026101C(void);
void func_80261570(f32 arg0);
void func_80261FB0(u8 arg0);
void func_80261E9C(u64 arg0);

void func_80260C20(u8 arg0, f32 arg1) {
    s32 sp24;

    D_802E8D84 ^= 1;
    func_802D76C0(D_80367734);
    D_8036772A = 0;
    D_8036770C = arg1;
    D_80367708 = arg0;
    sp24 = (s32)D_80367514->seqArray[arg0].offset;
    func_8028B4C4(sp24, D_80367510, &D_80367408[arg0], 0, 0, 0);
    alCSeqNew(&D_80367518[D_802E8D84], D_80367510);
    func_802D81B0(D_80367734, &D_80367518[D_802E8D84]);
    func_802D81F0(D_80367734);
    alCSPSetVol(D_80367734, D_802E8D00[D_80367708] * D_8036770C * D_802E8D88);
}

void func_80260D7C(f32 arg0) {
    D_802E8D88 = arg0;
    alCSPSetVol(D_80367734, D_802E8D00[D_80367708] * D_8036770C * arg0);
}

f32 func_80260DF0(void) {
    return D_802E8D88;
}

void func_80260DFC(void) {
    func_80260EE0(D_802E8DC8[D_802E8BDC]);
}

void func_80260E2C(void) {
    D_80367740 = D_803156C4;
    D_8036772C = alCSPGetTempo(D_80367734);
    func_80261FB0(D_802E8E04[D_802E8BDC]);
}

void func_80260E80(void) {
    D_80367740 = D_803156C4;
    func_80261FB0(D_802E8E40[D_802E8BDC]);
}

void func_80260EC0(void) {
    func_80260DFC();
}

void func_80260EE0(u8 arg0) {
    if (D_80367728 != 0) {
        func_8029A7E4("OH DEAR - pushing tune but we're still popping!\n");
    } else {
        func_8029A7E4("push tune %d\n", arg0);
        D_80367400->unk1F0 = D_80367708;
        D_80367708 = arg0;
        D_80367730 = 0;
        D_80367729 = 1;
    }
}

void func_80260F60(f32 arg0) {
    func_8029A7E4("1 pop tune");
    if (D_80366C30 == D_80367400) {
        return;
    }
    D_80367400--;
    if (D_80366C30 == D_80367400) {
        D_80367730 = 1;
    }
    func_8029A7E4("2 pop tune %d\n", D_80367400->unk1F0);
    D_80367708 = D_80367400->unk1F0;
    func_802D76C0(D_80367734);
    D_80367728 = 2;
    D_80367714 = arg0;
}

void func_8026101C(void) {
    func_80260F60(0.0f);
}

void func_80261040(void) {
    func_80260F60(1.0f);
}

void func_80261068(void) {
    u32 sp114;
    ALCSeqMarker sp28;

    switch (D_80367728) {
        case 2:
            if (func_802D4E10(D_80367734) == 0) {
                func_80260C20(D_80367708, D_80367714);
                D_80367728 = 1;
            }
            break;
        case 1:
            alCSeqGetLoc(&D_80367518[D_802E8D84], &sp28);
            if ((func_802D4E10(D_80367734) == 1) && (sp28.lastTicks != 0)) {
                alCSeqSetLoc(&D_80367518[D_802E8D84], &D_80367400->marker);
                alCSPSetTempo(D_80367734, D_80367400->tempo);
                for (sp114 = 0; sp114 < 0x40; sp114++) {
                    ((u32 *)D_80367734->chanState)[sp114] = D_80367400->chanState[sp114];
                }
                D_80367728 = 0;
                if (D_80367714 != 1.0) {
                    func_80261570(1.0f);
                }
            }
            break;
    }
}

void func_802611F0(void) {
    ALCSeqMarker sp1C;

    alCSeqGetLoc(&D_80367518[D_802E8D84], &sp1C);
    if ((D_80367729 == 0) && (D_80367728 == 0) && (func_802D4E10(D_80367734) == 0) && (sp1C.lastTicks != 0)) {
        func_8029A7E4("auto popping\n");
        func_8026101C();
    }
}

void func_80261284(void) {
    u32 sp24;

    switch (D_80367729) {
        case 1:
            if (func_802D4E10(D_80367734) == 1) {
                alCSeqGetLoc(&D_80367518[D_802E8D84], &D_80367400->marker);
                D_80367400->tempo = alCSPGetTempo(D_80367734);
                for (sp24 = 0; sp24 < 0x40; sp24++) {
                    D_80367400->chanState[sp24] = ((u32 *)D_80367734->chanState)[sp24];
                }
                func_802D76C0(D_80367734);
                D_80367400++;
                D_80367729 = 2;
            }
            break;
        case 2:
            if (func_802D4E10(D_80367734) == 0) {
                func_80260C20(D_80367708, 1.0f);
                D_80367729 = 0;
            }
            break;
    }
}

#define ABS(x) (((x) > 0.0f) ? (x) : -(x))

void func_802613C8(void) {
    f32 sp2C;
    f32 sp28;
    s16 sp26;

    sp2C = alCSPGetVol(D_80367734);
    sp28 = D_802E8D00[D_80367708] * D_802E8D88;
    sp26 = sp2C + (sp28 * D_8036770C - sp2C) * 0.075;
    if (ABS(sp26 - sp28 * D_8036770C) < 10.0f) {
        sp26 = sp28 * D_8036770C;
        D_8036772A = 0;
    }
    alCSPSetVol(D_80367734, sp26);
}

void func_80261528(void) {
    if (D_80367734->state == 1) {
        alCSPSetTempo(D_80367734, D_8036772C);
        D_8036772C = 0;
    }
}

void func_80261570(f32 arg0) {
    D_8036770C = arg0;
    D_8036772A = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/1C460/func_80261588.s")

void func_802619D0(u32 arg0) {
    if (arg0 >= 0x1C) {
        func_8029A7E4("effect id %d out of range!\n", arg0);
    } else if (D_802E8E7C[arg0] != 0) {
        func_80260650(D_80367738, D_802E8E7C[arg0], 0);
    }
}

u8 func_80261A44(u64 arg0) {
    u8 sp27;
    u8 sp26;

    sp26 = 0;
    sp27 = D_80367708;
    if (arg0 != 4) {
        func_80260A10();
    }
    func_802609F0();
    func_80261E9C(arg0);
    if (D_80364A90 & 0xC9FD8FE7FBFFC0B0) {
        func_80260A30(0);
        func_80260A30(5);
    }
    D_80367710 = 1.0f;
    switch (arg0) {
        case 0x2:
            sp27 = 0x11;
            break;
        case 0x40:
            sp27 = 0xA;
            break;
        case 0x800:
        case 0x1000:
            sp27 = 3;
            break;
        case 0x10000:
            sp27 = 0x21;
            break;
        case 0x20000:
        case 0x40000:
        case 0x100000000:
        case 0x200000000:
        case 0x40000000000000:
            sp27 = 0x21;
            break;
        case 0x80000000:
            func_80261570(0.0f);
            break;
        case 0x8000000:
            sp27 = 0xE;
            break;
        case 0x80:
        case 0x4000:
            if (func_80264BA4(D_802E8BDC) == 3) {
                sp27 = 0xC;
            } else {
                sp27 = 0x13;
            }
            break;
        case 0x40000000:
            sp27 = 0xF;
            break;
        case 0x2000:
            if (D_802E8F94[D_802E8BDC].unk0 != 1) {
                func_80261570(0.0f);
                break;
            }
            /* fallthrough */
        case 0x4:
            sp27 = D_802E8D8C[D_802E8BDC];
            sp26 = 1;
            break;
        case 0x20000000:
            sp27 = 0x1D;
            break;
        case 0x100000000000:
            sp27 = D_802E8D8C[D_802E8BDC];
            sp26 = 1;
            if (D_802E8BDC == 0x26) {
                D_80367710 = 0.7f;
            }
            break;
        case 0x4000000000000:
            func_80261570(0.0f);
            break;
        case 0x10000000000000:
            sp27 = 0x28;
            break;
        case 0x800000000000:
            func_80261570(0.0f);
            break;
        case 0x4000000000000000:
            break;
    }
    if ((sp27 != D_80367708) || (sp26 != 0)) {
        func_80261570(0.0f);
        return sp27;
    }
    return 0;
}

void func_80261E9C(u64 arg0) {
    switch (arg0) {
        case 0x2:
            func_80260B40(0, 0x5DC0);
            func_80260B40(5, 0x5DC0);
            break;
        case 0x20000000:
            func_80260B40(0, 0x61A8);
            break;
        case 0x40:
            func_80260B40(0, 0x4E20);
            func_80260B40(5, 0x4E20);
            break;
        case 0x800:
        case 0x1000:
            func_80260B40(0, 0x6D60);
            func_80260B40(5, 0x6D60);
            break;
        default:
            func_80260B40(0, 0x7FFF);
            func_80260B40(5, 0x7FFF);
            break;
    }
}

void func_80261FB0(u8 arg0) {
    D_80367728 = 0;
    D_80367729 = 0;
    D_80367400 = D_80366C30;
    D_80367730 = 1;
    func_80260C20(arg0, D_80367710);
}

void func_80262008(u8 arg0, f32 arg1) {
    D_80367400 = D_80366C30;
    D_80367730 = 1;
    func_80260C20(arg0, arg1);
}

u8 func_80262050(void) {
    return D_80367708;
}

s32 func_8026205C(s32 arg0) {
    u32 sp2C;
    s32 sp28;

    sp2C = 0;
    for (sp28 = 0; sp28 < 5 && D_802E8EB4[arg0][sp28] != -1; sp28++, sp2C++) {
    }
    return D_802E8EB4[arg0][osGetCount() % sp2C];
}
