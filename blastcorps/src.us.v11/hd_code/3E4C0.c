#include "common.h"

extern f64 D_8030C850;
extern f64 D_8030C858;
extern f64 D_8030C860;
extern f64 D_8030C868;
extern f64 D_8030C870;
extern f64 D_8030C878;
extern f64 D_8030C880;
extern f64 D_8030C888;

s32 func_802AD7D4(s32);

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/3E4C0/func_80282C80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/3E4C0/func_8028376C.s")

/* K&R definition: callers pass the coordinates as ints. */
f32 func_80284ADC(arg0, arg1, arg2, arg3)
    s16 arg0;
    s16 arg1;
    s16 arg2;
    s16 arg3;
{
    f32 dist;

    dist = sqrtf((arg2 - arg0) * (arg2 - arg0) + (arg3 - arg1) * (arg3 - arg1));
    if (dist < 1.0) {
        return 0.0f;
    }
    if (arg2 >= arg0 && arg3 >= arg1) {
        return func_802AD7D4((arg2 - arg0) * D_8030C850 / dist) / 65536.0 * D_8030C858;
    }
    if (arg2 >= arg0 && arg3 < arg1) {
        return (func_802AD7D4((arg1 - arg3) * D_8030C860 / dist) + 0x4000) / 65536.0 * D_8030C868;
    }
    if (arg2 < arg0 && arg3 < arg1) {
        return (func_802AD7D4((arg0 - arg2) * D_8030C870 / dist) + 0x8000) / 65536.0 * D_8030C878;
    }
    if (arg2 < arg0 && arg3 >= arg1) {
        return (func_802AD7D4((arg3 - arg1) * D_8030C880 / dist) + 0xC000) / 65536.0 * D_8030C888;
    }
}
