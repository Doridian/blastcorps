#include "common.h"

typedef struct {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ s16 unk18;
    /* 0x1A */ u8 unk1A;
    /* 0x1B */ u8 unk1B;
    /* 0x1C */ u8 unk1C;
    /* 0x20 */ f32 unk20;
} UnkStruct_80367D60; /* size = 0x24 */

typedef struct UnkSndState_s UnkSndState;
typedef struct UnkSndBank_s UnkSndBank;

UnkSndState *func_80260650(UnkSndBank *bank, s16 id, UnkSndState **handle);
void func_80260AB8(UnkSndState *state, s16 type, s32 param);
void func_80265428(void);
void func_8026513C(void);
s32 func_80265A0C(s32 arg0);
void func_80265B7C(s32 arg0);
void func_80265E48(void);
s32 func_8026A610(s32, s32, s32, s32);
s32 func_8026A8E0(s32, s32);
void func_8026AD30(s32);

extern u8 D_802E8BD0;
extern f32 D_80309640;
extern s32 D_803643E0;
extern s32 D_803643E8;
extern UnkSndBank *D_80367738;
extern UnkStruct_80367D60 D_80367D60[20];
extern s32 D_80368030;
extern s32 D_80368038;
extern s32 D_8036803C;
extern s32 D_80368040;
extern s32 D_80368044;
extern s32 D_80368048;
extern s32 D_8036B968;
extern u8 D_8036EA79;
extern s32 D_803EF308;
extern s32 D_803EF30C;
extern u8 D_803EF32C;
extern s32 D_803EF6DC;
extern s32 D_803EF6E4;

void func_80264C20(s32 arg0) {
    s32 i;

    for (i = 0; i < 20; i++) {
        D_80367D60[i].unk15 = 0;
    }
    D_8036B968 = osGetCount();
    D_80368038 = 99999999;
    if (arg0 != 0) {
        D_8036EA79 = D_80368040;
    } else {
        D_8036EA79 = 0;
    }
}

void func_80264CB4(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, s32 arg5) {
    s32 unused;
    s32 count;
    s32 i;
    u8 found;
    s16 r;

    i = 0;
    count = 0;
    D_8036EA79 += arg5;
    if (arg5 != 0 && D_802E8BD0 == 0) {
        func_8026AD30(0x48);
    }
    if (arg3 > 200) {
        arg3 = 200;
    }
    while (count < arg5 && i < 20) {
        if (count == 2) {
            func_80260650(D_80367738, 0x24, NULL);
        }
        found = 0;
        while (i < 20 && found == 0) {
            if (D_80367D60[i].unk15 == 0) {
                found = 1;
            } else {
                i++;
            }
        }
        if (found) {
            D_80367D60[i].unk0 = arg0;
            D_80367D60[i].unk4 = arg2;
            D_80367D60[i].unk2 = arg1;
            r = arg3 / 5;
            D_80367D60[i].unkA = func_8026A8E0(-r, r) + (arg0 - arg3);
            D_80367D60[i].unkC = func_8026A8E0(-r, r) + (arg2 + arg3);
            D_80367D60[i].unk10 = arg3 * 3 / 2;
            D_80367D60[i].unkE = arg3;
            D_80367D60[i].unk6 = D_80367D60[i].unkA + func_8026A8E0(-arg3, arg3);
            D_80367D60[i].unk8 = D_80367D60[i].unkC + func_8026A8E0(-arg3, arg3);
            D_80367D60[i].unk13 = 0;
            D_80367D60[i].unk14 = 0;
            D_80367D60[i].unk16 = func_8026A8E0(-500, 500);
            D_80367D60[i].unk12 = arg4;
            D_80367D60[i].unk1C = 0;
            D_80367D60[i].unk15 = 5;
            D_80367D60[i].unk18 = 4000;
            D_80367D60[i].unk20 = D_80309640;
            D_80367D60[i].unk1B = 0;
        }
        i++;
        count++;
    }
}

void func_8026510C(void) {
    func_80265428();
    func_8026513C();
    func_80265E48();
}

void func_8026513C(void) {
    s16 dx;
    s16 dz;
    s16 adx;
    s16 adz;
    f32 dist;
    s16 sx;
    s16 sz;
    s32 i;

    for (i = 0; i < 20; i++) {
        if (D_80367D60[i].unk15 == 5) {
            dx = D_80367D60[i].unk6 - D_80367D60[i].unk0;
            if (dx >= 0) {
                adx = dx;
            } else {
                adx = -dx;
            }
            dz = D_80367D60[i].unk8 - D_80367D60[i].unk4;
            if (dz >= 0) {
                adz = dz;
            } else {
                adz = -dz;
            }
            dist = func_8026A610(D_80367D60[i].unk6, D_80367D60[i].unk8, D_80367D60[i].unk0, D_80367D60[i].unk4);
            if (dist < 1.0 || D_80367D60[i].unk20 < dist) {
                D_80367D60[i].unk15 = 1;
            } else {
                D_80367D60[i].unk20 = dist;
                sx = adx / dist * 5.0f;
                sz = adz / dist * 5.0f;
                if (dx >= 0) {
                    D_80367D60[i].unk0 = D_80367D60[i].unk0 + sx;
                } else {
                    D_80367D60[i].unk0 -= sx;
                }
                if (dz >= 0) {
                    D_80367D60[i].unk4 += sz;
                } else {
                    D_80367D60[i].unk4 -= sz;
                }
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/20460/func_80265428.s")

s32 func_80265A0C(s32 arg0) {
    s16 px;
    s16 pz;
    s16 x;
    s16 z;

    x = D_80367D60[arg0].unkA - D_80367D60[arg0].unk10;
    z = D_80367D60[arg0].unkC - D_80367D60[arg0].unk10;
    px = D_803643E0 >> 5, pz = D_803643E8 >> 5;
    if (px < x || pz < z) {
        return 0;
    }
    x = D_80367D60[arg0].unkA + D_80367D60[arg0].unk10;
    z = D_80367D60[arg0].unkC + D_80367D60[arg0].unk10;
    if (px >= x || pz >= z) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/20460/func_80265B7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/20460/func_80265E48.s")

void func_802661EC(void) {
    D_803EF308 = D_803EF6DC;
    D_803EF30C = D_803EF6E4;
    D_80368044 = D_803643E0;
    D_80368048 = D_803643E8;
    D_803EF32C = 1;
    D_80368038 = 2000;
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/20460/func_80266248.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/20460/func_80267614.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/20460/func_802676A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/20460/func_80267A74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/20460/func_80267A9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/20460/func_80267CDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/20460/func_80267F88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/20460/func_80267FE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/20460/func_80268254.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/20460/func_802682A4.s")
