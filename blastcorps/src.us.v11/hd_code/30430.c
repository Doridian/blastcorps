#include "common.h"

/*
 * D_8036C770..D_8036C784 are this file's own .bss: func_80274BF0 and
 * func_80275270 store D_8036C778 (a u64) through one shared lui, which IDO
 * only does for a symbol it knows is local.  Until .bss is split they stay
 * as asm.
 */
extern u16 D_8036C770;
extern u64 D_8036C778;

void func_80275270(u64 arg0, f32 arg2);

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/30430/func_80274BF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/30430/func_80275270.s")

void func_80275390(u64 arg0) {
    func_80275270(arg0, 0.25f);
}

s32 func_802753C0(void) {
    return (D_8036C778 != 0) ? 1 : 0;
}

s32 func_802753F8(void) {
    return (D_8036C770 != 0) ? 1 : 0;
}
