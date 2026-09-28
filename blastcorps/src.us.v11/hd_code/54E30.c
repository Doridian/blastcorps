#include "common.h"

extern s32 D_802E8BDC;
extern u8 D_803A6B02;

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/54E30/func_802995F0.s")

void func_80299C0C(void) {
    D_802E8BDC = D_803A6B02;
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/54E30/func_80299C20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/54E30/func_80299E10.s")

void func_802995F0(s32);
u64 func_801ECA50(u8);
s32 func_8026F92C(u64);
void func_8029A7E4(char *, ...);

u64 func_80299FE8(u8 arg0) {
    u64 sp28;
    register s32 world;

    switch (arg0) {
        case 38:
            sp28 = 0x100000000000;
            func_802995F0(1);
            break;
        case 55:
            sp28 = 0x100000000000;
            func_802995F0(5);
            break;
        case 28:
            sp28 = 0x100000000000;
            func_802995F0(6);
            break;
        case 53:
            sp28 = 0x100000000000;
            func_802995F0(7);
            break;
        case 7:
            sp28 = 0x100000000000;
            func_802995F0(8);
            break;
        case 19:
            sp28 = 0x100000000000;
            func_802995F0(9);
            break;
        default:
            sp28 = func_801ECA50(arg0);
            break;
    }
    world = func_8026F92C(sp28);
    func_8029A7E4("get loop done for world %d\n", world);
    return sp28;
}
