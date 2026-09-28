#include "common.h"

typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6[2];
    /* 0x08 */ f32 unk8;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ u8 unkE[6];
} UnkStruct_802F41E8; /* size = 0x14 */

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ s16 unk12;
} UnkStruct_802F3C10; /* size = 0x14 */

typedef struct {
    /* 0x00 */ u8 unk0[0x5C];
    /* 0x5C */ s32 unk5C;
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ s32 unk70;
} UnkStruct_80364460; /* size = 0x74 */

typedef struct {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ f32 unk4;
    /* 0x8 */ u8 unk8;
} UnkStruct_802F3C24; /* size = 0xC */

typedef struct {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ u8 unk4;
    /* 0x6 */ s16 unk6;
    /* 0x8 */ s16 unk8;
    /* 0xA */ s16 unkA;
    /* 0xC */ u8 unkC;
} UnkStruct_802F3C48; /* size = 0x10 */

typedef struct {
    /* 0x00 */ u8 unk0[0x18];
    /* 0x18 */ u8 unk18[0xE8];
} UnkStruct_80364AF0; /* size = 0x100 */

extern s32 D_802E8BDC;
extern UnkStruct_802F3C10 D_802F3C10[];
extern UnkStruct_802F3C24 D_802F3C24[];
extern UnkStruct_802F3C48 D_802F3C48[];
extern UnkStruct_802F41E8 D_802F41E8[];
extern char D_80309830[];
extern char D_8030985C[];
extern char D_80309864[];
extern f64 D_80309928;
extern f64 D_803099A0;
extern f64 D_803099A8;
extern f64 D_803099B0;
extern f64 D_803099B8;
extern f64 D_803099C0;
extern f64 D_803099C8;
extern u8 D_8036B8B0;
extern s32 D_8036B8B4;
extern s32 D_8036B8B8;
extern s32 D_8036B8BC;
extern u8 D_8036B8C0;
extern f32 D_8036B8C8[4][4];
extern s32 D_8036B908;
extern u8 D_8036B90C;
extern f32 D_8036B910[4][4];
extern s32 D_803643E0;
extern s32 D_803643E4;
extern s32 D_803643E8;
extern u8 D_803643D6;
extern u8 D_803643D7;
extern u8 D_80364456;
extern UnkStruct_80364460 D_80364460[];
extern UnkStruct_80364460 *D_803649D0;
extern u8 D_803649ED;
extern s64 D_80364A98;
extern u8 D_80364AE8;
extern UnkStruct_80364AF0 D_80364AF0[];
extern s32 D_8036B950;
extern u8 D_8036B954;
extern u8 D_8036B955;
extern u8 D_8036B958[4];
extern u8 D_8036B95C;
extern u8 D_8036B964;
extern u8 D_8036B965;
extern u8 D_8036B966;
extern u32 D_8036B968;
extern u8 D_8036C7CC;
extern u8 D_8036EB98;
extern u8 D_803A7430;
extern u8 D_803EFECB;
extern u32 D_8036B96C;
extern u8 D_8036B970;
extern u8 D_8036B971;
extern s32 D_8036B974;
extern u8 D_8036B978;
extern u8 D_8036B979;
extern u8 D_803ED826;
extern s32 D_803FCD60;
extern u8 D_803FCD75;

f32 func_80268D84(f32, f32, f32, f32, f32, f32, f32);
s32 func_8026A610(s32, s32, s32, s32);
s32 func_8026A6F0(s32, s32, s32, s32, s32, s32);
s32 func_8026AD30(s32);
s32 func_802AB3C0(s32);
s32 func_802753C0(void);
void func_8029A7E4(char *, ...);
s32 func_802AC4C4(s32, s32, s32, s32, s32, s32, s32, s32);

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/23C20/func_802683E0.s")

void func_80268664(s32 arg0) {
    f32 t;

    D_8036B8B0 = 0;
    D_8036B8C0 = 0;
    do {
        if (D_802F3C24[D_8036B8C0].unk0 == arg0) {
            D_8036B8B0 = 1;
        } else {
            D_8036B8C0++;
        }
    } while (D_8036B8C0 < 3 && D_8036B8B0 == 0);
    if (D_8036B8B0 != 0) {
        t = D_802F3C24[D_8036B8C0].unk4;
        D_8036B8C8[0][0] = -t;
        D_8036B8C8[0][1] = t * 2.0;
        D_8036B8C8[0][2] = -t;
        D_8036B8C8[0][3] = 0.0f;
        D_8036B8C8[1][0] = 2.0 - t;
        D_8036B8C8[1][1] = t - 3.0;
        D_8036B8C8[1][2] = 0.0f;
        D_8036B8C8[1][3] = 1.0f;
        D_8036B8C8[2][0] = t - 2.0;
        D_8036B8C8[2][1] = 3.0 - t * 2.0;
        D_8036B8C8[2][2] = t;
        D_8036B8C8[2][3] = 0.0f;
        D_8036B8C8[3][0] = t;
        D_8036B8C8[3][1] = -t;
        D_8036B8C8[3][2] = 0.0f;
        D_8036B8C8[3][3] = 0.0f;
        D_8036B908 = 0;
        D_8036B90C = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/23C20/func_802688C4.s")

f32 func_80268D84(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    s32 spC;
    s32 sp8;
    s32 sp4;
    s32 sp0;

    spC = D_8036B8C8[0][0] * arg0 + D_8036B8C8[1][0] * arg1 + D_8036B8C8[2][0] * arg2 + D_8036B8C8[3][0] * arg3;
    sp8 = D_8036B8C8[0][1] * arg0 + D_8036B8C8[1][1] * arg1 + D_8036B8C8[2][1] * arg2 + D_8036B8C8[3][1] * arg3;
    sp4 = D_8036B8C8[0][2] * arg0 + D_8036B8C8[1][2] * arg1 + D_8036B8C8[2][2] * arg2 + D_8036B8C8[3][2] * arg3;
    sp0 = D_8036B8C8[0][3] * arg0 + D_8036B8C8[1][3] * arg1 + D_8036B8C8[2][3] * arg2 + D_8036B8C8[3][3] * arg3;
    return (f32)spC * arg6 + arg5 * (f32)sp8 + arg4 * (f32)sp4 + (f32)sp0;
}

s32 func_80268EE8(s32 arg0) {
    s32 i;

    i = 0;
    do {
        if (D_802F41E8[i].unk0 == arg0) {
            D_803FCD75 = D_802F41E8[i].unk5;
            return 1;
        }
        i++;
    } while (i < 3);
    return 0;
}

void func_80268F54(void) {
    u8 found;
    f32 t;

    found = 0;
    if (D_80364A98 == 0x800) {
        D_8036B966 = 0;
    } else {
        D_8036B966 = 1;
    }
    D_8036B955 = 0;
    while (found == 0) {
        if (D_802F41E8[D_8036B955].unk0 == D_802E8BDC && D_802F41E8[D_8036B955].unk4 == D_8036B966) {
            found = 1;
        } else {
            D_8036B955++;
        }
    }
    t = D_802F41E8[D_8036B955].unk8;
    D_8036B910[0][0] = -t;
    D_8036B910[0][1] = t * 2.0;
    D_8036B910[0][2] = -t;
    D_8036B910[0][3] = 0.0f;
    D_8036B910[1][0] = 2.0 - t;
    D_8036B910[1][1] = t - 3.0;
    D_8036B910[1][2] = 0.0f;
    D_8036B910[1][3] = 1.0f;
    D_8036B910[2][0] = t - 2.0;
    D_8036B910[2][1] = 3.0 - t * 2.0;
    D_8036B910[2][2] = t;
    D_8036B910[2][3] = 0.0f;
    D_8036B910[3][0] = t;
    D_8036B910[3][1] = -t;
    D_8036B910[3][2] = 0.0f;
    D_8036B910[3][3] = 0.0f;
    D_803FCD60 = D_802F41E8[D_8036B955].unkC << 5;
    D_8036B950 = 0;
    D_8036B954 = 1;
    D_8036B958[0] = 0;
    D_8036B958[1] = 0;
    D_8036B958[2] = 0;
    D_8036B958[3] = 0;
    D_8036B95C = 0;
    D_8036B964 = 0;
    D_8036B965 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/23C20/func_80269258.s")

f32 func_8026A184(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    s32 spC;
    s32 sp8;
    s32 sp4;
    s32 sp0;

    spC = D_8036B910[0][0] * arg0 + D_8036B910[1][0] * arg1 + D_8036B910[2][0] * arg2 + D_8036B910[3][0] * arg3;
    sp8 = D_8036B910[0][1] * arg0 + D_8036B910[1][1] * arg1 + D_8036B910[2][1] * arg2 + D_8036B910[3][1] * arg3;
    sp4 = D_8036B910[0][2] * arg0 + D_8036B910[1][2] * arg1 + D_8036B910[2][2] * arg2 + D_8036B910[3][2] * arg3;
    sp0 = D_8036B910[0][3] * arg0 + D_8036B910[1][3] * arg1 + D_8036B910[2][3] * arg2 + D_8036B910[3][3] * arg3;
    return (f32)spC * arg6 + arg5 * (f32)sp8 + arg4 * (f32)sp4 + (f32)sp0;
}

void func_8026A2E8(f32 arg0, f32 *arg1) {
    f32 d;

    d = *arg1 - arg0;
    if (d > D_803099A0) {
        *arg1 -= D_803099A8;
    } else if (d < D_803099B0) {
        *arg1 += D_803099B8;
    }
}

void func_8026A378(s32 n, char *buf) {
    s32 div;
    u8 digit;
    u8 printed;
    u8 started;

    div = 100000000;
    printed = 0;
    started = 0;
    do {
        digit = n / div;
        if (started != 0 || digit != 0) {
            *buf++ = digit + '0';
            started = printed = 1;
        }
        n -= digit * div;
        div /= 10;
    } while (div != 0);
    if (printed == 0) {
        *buf++ = '0';
    }
    *buf = 0;
}

void func_8026A454(s16 x, s16 y, s16 z, s16 arg3, s16 arg4, Mtx *arg5) {
    f32 sp60[4][4];
    f32 sp20[4][4];

    guTranslateF(sp60, -x, -y, -z);
    guRotateF(sp20, (f32)arg3 / D_803099C0, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp60, sp20, sp60);
    guRotateF(sp20, (f32)arg4 / D_803099C8, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp60, sp20, sp60);
    guTranslateF(sp20, x, y, z);
    guMtxCatF(sp60, sp20, sp60);
    guMtxF2L(sp60, arg5);
}

void func_8026A5CC(u64 *dst, u64 *src, s32 size) {
    size >>= 3;
    while (size--) {
        *dst++ = *src++;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/23C20/func_8026A610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/23C20/func_8026A6F0.s")

s32 func_8026A828(s32 lo, s32 hi) {
    f32 f;

    D_8036B968 = D_8036B968 * 0x41C64E6D + 0x3039;
    f = (f32)(s32)(D_8036B968 & 0x7FFFFFFF) / 2147483648.0f;
    f = (hi - lo) * f + lo;
    return f + 0.5;
}

void func_8026A8BC(void) {
    D_8036B968 = osGetCount();
}

s32 func_8026A8E0(s32 lo, s32 hi) {
    f32 f;

    D_8036B96C = D_8036B96C * 0x41C64E6D + 0x3039;
    f = (f32)(s32)(D_8036B96C & 0x7FFFFFFF) / 2147483648.0f;
    f = (hi - lo) * f + lo;
    return f + 0.5;
}

void func_8026A974(void) {
    D_8036B96C = 0x9BA0D;
}

void func_8026A988(void) {
    D_8036B970 = 0;
    D_8036B971 = 0;
    D_8036B974 = 0;
    D_8036B978 = 0;
    D_8036B979 = 0;
}

void func_8026A9B4(void) {
    UnkStruct_80364460 *p;
    u8 hit;
    s32 min;
    s32 d;
    register s32 ok;

    min = 999999;
    if (D_803A7430 == 15) {
        func_8026AD30(0x50);
    }
    if (D_802E8BDC == 0x12 && (D_803643E0 >> 5) < 1400 &&
        func_8026A610(D_803643E0 >> 5, D_803643E8 >> 5, 1329, 4193) < 130) {
        func_8026AD30(0x51);
    }
    if (D_80364456 != D_8036B979) {
        D_8036B978 = D_8036B979;
    }
    if (D_80364456 != 0) {
        D_8036B979 = D_80364456;
    }
    p = D_80364460;
    hit = 0;
    while (hit == 0 && D_803649D0 != p) {
        if (p->unk5C != D_8036B978 && p->unk5C != D_80364456 && D_80364456 != 0 && p->unk5C != 0 &&
            p->unk5C != 0xFE && p->unk5C != 0xFF && p->unk5C != 7 && p->unk5C != 6) {
            d = func_8026A6F0(D_803643E0 >> 5, D_803643E4 >> 5, D_803643E8 >> 5, p->unk64 >> 5, p->unk68 >> 5,
                              p->unk6C >> 5);
            if (d < min) {
                min = d;
            }
            if (d < 100 && D_8036B970 == 0 && (func_802AB3C0(p->unk5C) == 0 || D_803EFECB == 0)) {
                func_8026AD30(0x4C);
                D_8036B970 = 1;
                hit = 1;
            }
        }
        p++;
    }
    if (D_8036B970 != 0 && min > 400) {
        D_8036B970 = 0;
    }
    if (D_802E8BDC == 0 && D_8036C7CC >= 2) {
        func_8026AD30(0x4D);
    }
    if (D_802E8BDC == 0 && D_80364456 == 7 && (D_803643E0 >> 5) >= 0x899) {
        func_8026AD30(0x53);
    }
    if (D_8036B971 != 0) {
        if (D_80364AF0[D_80364AE8].unk18[D_802E8BDC] > 0 && D_80364AF0[D_80364AE8].unk18[D_802E8BDC] < 6) {
            ok = 1;
        } else {
            ok = 0;
        }
        if (ok == 0 && D_8036EB98 == 0) {
            if (func_8026AD30(0x4E) == 0) {
                func_8026AD30(0x4F);
            }
            D_8036B971 = 0;
        }
    }
}
