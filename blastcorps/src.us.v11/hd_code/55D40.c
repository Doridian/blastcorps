#include "common.h"

typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ char unk6[0x2A];
} UnkStruct_80304A90; /* size = 0x30 */

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 unk7;
} UnkStruct_802F47B0; /* size = 0x8 */

extern UnkStruct_802F47B0 D_802F47B0[];
extern UnkStruct_80304A90 D_80304A90[];
extern u32 D_80358060;
extern u8 D_803643D6;
extern s16 D_8036BB1C;
extern s32 D_803A6B20;
extern s32 D_803A6B24;

void func_80259DC8(s32, char *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_80260EE0(s32);
void func_8026AF6C(s32);
void func_80275270(u64, f32);
s32 func_802753C0(void);

void func_8029A500(void) {
    D_803A6B20 = -0xEF;
    D_803A6B24 = 0;
}

s32 func_8029A518(s32 arg0, s32 arg1) {
    s32 sp64;
    UnkStruct_80304A90 *sp60;
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;

    sp54 = 0;
    sp5C = 0;
    sp64 = arg1;
    do {
        sp60 = &D_80304A90[sp5C];
        if (sp60->unk0 & 1) {
            sp50 = 0xA0;
        } else if (sp60->unk0 & 4) {
            sp50 = 0x6A;
        } else if (sp60->unk0 & 8) {
            sp50 = 0xD5;
        } else {
            sp50 = 0;
        }

        if (sp54 - D_803A6B20 >= -0x31 && sp54 - D_803A6B20 < 0xF0) {
            func_80259DC8(arg0, sp60->unk6, 0, 0, sp50, sp58, sp54 - D_803A6B20, sp60->unk5, sp60->unk5, 1,
                          D_802F47B0[sp60->unk4].unk0, D_802F47B0[sp60->unk4].unk1,
                          D_802F47B0[sp60->unk4].unk2, D_802F47B0[sp60->unk4].unk3,
                          D_802F47B0[sp60->unk4].unk4, D_802F47B0[sp60->unk4].unk5,
                          D_802F47B0[sp60->unk4].unk6, D_802F47B0[sp60->unk4].unk7);
        }
        if (sp60->unk0 & 0x20) {
            sp54 += 0x26;
        }
        if (sp60->unk0 & 0x10) {
            sp54 += 0x16;
        }
        if (sp60->unk0 & 0x40) {
            sp54 += 0x11;
        }
    } while (++sp5C < 0x52);
    if (D_80358060 == 0x64) {
        func_8026AF6C(0x8036);
    }
    if (D_80358060 >= 0x18C) {
        D_803A6B20++;
    }
    if (D_803643D6 != 0) {
        D_803A6B24++;
    }
    if (D_803A6B24 == 0x7D) {
        func_8026AF6C(0x8037);
        func_80260EE0(0x25);
    }
    if (D_803A6B24 >= 0x7E && D_8036BB1C == 1 && func_802753C0() == 0) {
        func_80275270(0x200000000000, 0.75f);
    }
    return sp64;
}
