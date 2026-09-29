#include "common.h"
#include "game/camera.h"


extern Mtx D_02000000[];
extern u32 D_803156C4;
extern u16 D_8035807C;
extern s16 D_80367BD6;
extern s32 D_803F7660;
extern s32 D_803F7670;
extern s32 D_803F7678;

extern u8 D_803643DB;
extern f32 D_80364414;
extern s16 D_803F767C;
extern s16 D_803F7680;

s32 func_802AD7D4(s32);
s32 func_8026A610(s32, s32, s32, s32);
void func_802C1B9C(void);
f32 func_80284ADC();

/* .bss, 0x8036E5E0-0x8036E660 (tools/bss_c.py) */
Mtx D_8036E5E0[2];

/* .data, 0x802FC5B0-0x802FDA60 (tools/data_c.py) */
u16 D_802FC5B0[0x80] = {
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFF44, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFF22, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFF00,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xCC00, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF, 0x8800, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x3300,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFCC, 0, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFF33, 0, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xAA00, 0, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFDD, 0, 0, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xEE22,
    0, 0, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xEEDD, 0x1100, 0, 0, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    0xAA00, 0, 0, 0, 0xFFFF, 0xFFFF, 0xFFFF, 0xBB33, 0, 0, 0, 0, 0xFFFF, 0xFFCC, 0x8833, 0, 0, 0,
    0, 0, 0x3322,
};
u16 D_802FC6B0[0x400] = {
    17, 0x11EF, 0, 0xEF00, 239, 0, 0xEF00, 239, 0, 0xEF00, 239, 0, 0xEF00, 239, 0, 0xEF00, 17,
    0x11EF, 0, 0xEF00, 239, 0, 0xEF00, 239, 0, 0xEF00, 239, 0, 0xEF00, 239, 0, 0xEF00, 0, 239, 0,
    0xEF00, 239, 0, 0xEF00, 239, 0, 0xEF00, 239, 0, 0xEF00, 239, 0, 0xEF00, 0, 0, 0, 0xEF00, 239,
    0, 0xEF00, 239, 0, 0xEF00, 239, 0, 0xEF00, 239, 0, 0xEF00, 0, 0, 0, 0, 239, 0, 0xEF00, 239, 0,
    0xEF00, 239, 0, 0xEF00, 239, 0, 0xEF00, 0, 0, 0, 0, 0, 0, 0xEF00, 239, 0, 0xEF00, 239, 0,
    0xEF00, 239, 0, 0xEF00, 0xEEE0, 0, 0, 0, 0, 0, 0, 239, 0, 0xEF00, 239, 0, 0xEF00, 239, 0,
    0xEF00, 0xFFF0, 0, 0, 0, 0, 0, 0, 0, 0, 0xEF00, 239, 0, 0xEF00, 239, 0, 0xEF00, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 239, 0, 0xEF00, 239, 0, 0xEF00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xEF00, 239,
    0, 0xEF00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 239, 0, 0xEF00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0xEF00, 0xEEEE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xFFFF, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xEEE, 0xE000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0xFFFF, 0xF000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xEEEE, 0xEE00, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0xFFFF, 0xFF00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xEEEE,
    0xEEE0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xFFFF, 0xFFF0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0xEEEE, 0xEEEE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xFFFF, 0xFFFF, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xEEEE, 0xEEEE, 0xE000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0xFFFF, 0xFFFF, 0xF000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xEEEE, 0xEEEE, 0xEE00, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xFFFF, 0xFFFF, 0xFF00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0xEEEE, 0xEEEE, 0xEEE0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xFFFF, 0xFFFF, 0xFFF0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xEEEE, 0xEEEE, 0xEEEE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0xFFFF, 0xFFFF, 0xFFFF,
};
u16 D_802FCEB0[0x400] = {
    0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x210B, 0x20CB,
    0x104D, 0x104B, 0x104D, 0x104F, 0x1051, 0x1091, 0x1891, 0x188F, 0x18D1, 0x210F, 0x294B, 0x294B,
    0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B,
    0x294B, 0x294B, 0x294B, 0x294B, 0x210B, 0x184B, 0x84B, 0x100D, 0x84F, 0x1051, 0x1093, 0x1095,
    0x1097, 0x18D7, 0x1919, 0x10D9, 0x1897, 0x10D5, 0x1095, 0x210F, 0x294B, 0x294B, 0x294B, 0x294B,
    0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x188B,
    0x80B, 0x104D, 0x80F, 0x1091, 0x1095, 0x1097, 0x191D, 0x115D, 0x219F, 0x19E1, 0x21E1, 0x21E1,
    0x21E1, 0x199F, 0x191B, 0x10D9, 0x1897, 0x214D, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B,
    0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x210B, 0x104D, 0x104D, 0x104F, 0x851, 0x1095, 0x1099,
    0x111B, 0x195F, 0x2223, 0x2A65, 0x2AE7, 0x4369, 0x436B, 0x4BAB, 0x4369, 0x3B29, 0x2AA5, 0x19E1,
    0x191D, 0x18D9, 0x1911, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B,
    0x210D, 0x104D, 0x80D, 0x1051, 0x1093, 0x1095, 0x10D9, 0x111D, 0x19A1, 0x2265, 0x2AE7, 0x3B69,
    0x53ED, 0x6471, 0x74F1, 0x7D33, 0x7CF3, 0x74B1, 0x5C2D, 0x3B69, 0x2AA7, 0x199F, 0x191D, 0x1911,
    0x294D, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x104F, 0x104F, 0x1051, 0x1095,
    0x1097, 0x1119, 0x191F, 0x19E1, 0x2265, 0x2AE9, 0x3BAB, 0x542F, 0x6CF1, 0x8533, 0x9DF9, 0xB639,
    0xBEBB, 0xAE3B, 0x95B5, 0x6CB1, 0x542D, 0x32E9, 0x2223, 0x195F, 0x1913, 0x294B, 0x294B, 0x294B,
    0x294B, 0x294B, 0x294B, 0x1051, 0x1051, 0x853, 0x1095, 0x1097, 0x10DB, 0x115F, 0x19A1, 0x2265,
    0x2AE7, 0x336B, 0x542F, 0x64F1, 0x7D35, 0x95B7, 0xB67B, 0xCF3D, 0xE77F, 0xD7BF, 0xC6BD, 0x9DB7,
    0x7533, 0x5C2F, 0x332B, 0x2263, 0x195F, 0x2151, 0x294B, 0x294B, 0x294B, 0x294B, 0x20CF, 0x893,
    0x1055, 0x1097, 0x10D7, 0x191D, 0x111D, 0x19A1, 0x2265, 0x22A7, 0x336B, 0x43EB, 0x5471, 0x6CF3,
    0x8575, 0x9DF9, 0xB6BB, 0xCF3F, 0xEFBF, 0xE7FF, 0xD73F, 0xB67D, 0x9DF7, 0x7533, 0x5C6F, 0x336B,
    0x2A65, 0x199F, 0x294D, 0x294B, 0x294B, 0x294D, 0x855, 0x1095, 0x1099, 0x10D9, 0x195D, 0x195F,
    0x19A1, 0x1A23, 0x22A7, 0x2B29, 0x3BAD, 0x442D, 0x5CB3, 0x7533, 0x8DB7, 0x9DF9, 0xB67B, 0xBEFD,
    0xD77F, 0xDF7F, 0xCF3F, 0xC6BD, 0xA67B, 0x95B7, 0x7533, 0x4C2F, 0x3B6B, 0x2265, 0x2195, 0x294B,
    0x294B, 0x18D3, 0x1097, 0x10D9, 0x111D, 0x191D, 0x1161, 0x19E1, 0x2225, 0x22A5, 0x22E9, 0x33AB,
    0x43EF, 0x546F, 0x64F3, 0x7D75, 0x85B7, 0x9DF9, 0xAE7B, 0xBEBB, 0xBEFF, 0xCF3D, 0xC73F, 0xBEBD,
    0xB6BB, 0x9DF9, 0x8DB7, 0x6CF3, 0x442F, 0x3329, 0x2221, 0x294B, 0x294B, 0x18D7, 0x10DD, 0x111D,
    0x1161, 0x19A1, 0x2225, 0x1A65, 0x22A7, 0x2B29, 0x336B, 0x43ED, 0x4C6F, 0x5CF3, 0x74F3, 0x85B5,
    0x8DF9, 0x9E39, 0xAE7B, 0xB67B, 0xC6FD, 0xBEFD, 0xC6FF, 0xBEFD, 0xB6BD, 0xAE39, 0x9639, 0x7D75,
    0x64B3, 0x43EB, 0x22E9, 0x2993, 0x294D, 0x10DD, 0x115F, 0x19A1, 0x19E3, 0x2265, 0x22A7, 0x22E7,
    0x3329, 0x33AD, 0x43ED, 0x4C6F, 0x5CF1, 0x6CF3, 0x85B7, 0x8DB7, 0x9639, 0xA639, 0xAE7B, 0xBEFD,
    0xBEBD, 0xC6FD, 0xBEFD, 0xC6FD, 0xBEFD, 0xAE7D, 0xA679, 0x95B9, 0x7533, 0x54B1, 0x336B, 0x221D,
    0x2153, 0x1961, 0x19E1, 0x1A25, 0x22A7, 0x2AE9, 0x2B69, 0x3BAB, 0x43EB, 0x442F, 0x5C6F, 0x64F1,
    0x7533, 0x8575, 0x8DF7, 0xA639, 0xA63B, 0xB6BB, 0xBEBB, 0xBEFD, 0xC6FF, 0xCF3D, 0xC73F, 0xCEFD,
    0xC6FD, 0xBEFD, 0xAE7B, 0x9E39, 0x8DB7, 0x64F1, 0x4C2F, 0x2AA1, 0x195B, 0x1A23, 0x2267, 0x2AE7,
    0x2B6B, 0x3BAB, 0x43ED, 0x4C2D, 0x542D, 0x5C6B, 0x646D, 0x6CAF, 0x74ED, 0x84F1, 0x8D71, 0x9DF5,
    0xA5F9, 0xA637, 0xB679, 0xBEBB, 0xCF3F, 0xD73D, 0xCF7F, 0xD73D, 0xC6FD, 0xC6FD, 0xBEBD, 0xAE79,
    0x95F9, 0x7D73, 0x5C71, 0x3327, 0x21E1, 0x22A5, 0x2B29, 0x3B6B, 0x43ED, 0x4BE9, 0x3A59, 0x298F,
    0x298D, 0x2909, 0x290D, 0x294D, 0x3219, 0x6BE7, 0x5BE7, 0x63E7, 0x5BE7, 0x7429, 0x6C6D, 0x8D71,
    0xAE37, 0xC6BB, 0xD73D, 0xBE7B, 0xAE35, 0x9575, 0x8571, 0x95B5, 0xA639, 0x8D75, 0x6CF1, 0x43EB,
    0x2265, 0x3327, 0x329F, 0x3A59, 0x294B, 0x28C7, 0x1885, 0x1843, 0x20C5, 0x20C9, 0x310B, 0x4A55,
    0x7BE3, 0x4A99, 0x4A97, 0x3109, 0x5B1D, 0x5B19, 0x529B, 0x7423, 0x84A9, 0x8465, 0x8CA9, 0x310B,
    0x635F, 0x8531, 0x6CAD, 0x4BA9, 0x4BE9, 0x642B, 0x74F1, 0x4C2F, 0x2AA5, 0x325D, 0x318B, 0x28C7,
    0x2907, 0x1885, 0x2085, 0x2083, 0x3149, 0x5A0D, 0x520B, 0x5189, 0x498B, 0x49CB, 0x49C9, 0x520D,
    0x4149, 0x498B, 0x2947, 0x498B, 0x3949, 0x520F, 0x5A91, 0x498B, 0x20C7, 0x84ED, 0x8D31, 0x4B65,
    0x3B23, 0x2AA1, 0x4B67, 0x542D, 0x299B, 0x318B, 0x3989, 0x2907, 0x20C5, 0x2107, 0x398B, 0x4187,
    0x4189, 0x49CB, 0x4147, 0x49C9, 0x41CB, 0x3947, 0x4A0B, 0x3989, 0x49CB, 0x51CB, 0x4149, 0x3107,
    0x2945, 0x6AD5, 0x4A0B, 0x49CD, 0x39CB, 0x6B5D, 0x9DB5, 0x6BE7, 0x4B63, 0x325F, 0x2A5D, 0x4369,
    0x29D9, 0x3989, 0x3107, 0x2907, 0x3107, 0x39CB, 0x41CB, 0x520B, 0x524D, 0x5A4B, 0x4187, 0x4147,
    0x4149, 0x520B, 0x520D, 0x49CB, 0x49CB, 0x418B, 0x51CD, 0x41CB, 0x3107, 0x3147, 0x6AD3, 0x49CD,
    0x5A4F, 0x49CD, 0x5AD9, 0x7CAB, 0x4B21, 0x84ED, 0x329D, 0x325F, 0x29D3, 0x3107, 0x4A0D, 0x420D,
    0x524F, 0x62D1, 0x41C9, 0x49C9, 0x3987, 0x49C9, 0x49C9, 0x520B, 0x5A4F, 0x51C9, 0x624D, 0x6291,
    0x4A0F, 0x62D3, 0x4189, 0x49CB, 0x4149, 0x3149, 0x520D, 0x4187, 0x5A91, 0x3949, 0x30C7, 0x398D,
    0x431F, 0x42DF, 0x63E7, 0x3A9F, 0x294B, 0x49CD, 0x524D, 0x7313, 0x5A8F, 0x6B97, 0x7313, 0x5A8D,
    0x3945, 0x5985, 0x4187, 0x3985, 0x498B, 0x51CB, 0x4189, 0x41C9, 0x3105, 0x7B59, 0x520D, 0x3947,
    0x1885, 0x3147, 0x6B15, 0x6291, 0x520D, 0x498B, 0x41CD, 0x2907, 0x4A97, 0x20CB, 0x5B63, 0x4ADB,
    0x294B, 0x4A0D, 0x6291, 0x7355, 0x6313, 0x7B57, 0x6AD3, 0x62CF, 0x6A91, 0x49C9, 0x3145, 0x4189,
    0x4987, 0x4987, 0x3907, 0x3905, 0x51CB, 0x49C9, 0x49CB, 0x3947, 0x20C5, 0x2885, 0x3189, 0x3107,
    0x5A0D, 0x520F, 0x49CD, 0x3947, 0x41D1, 0x210B, 0x746B, 0x298F, 0x294B, 0x294B, 0x6291, 0x7313,
    0x6B11, 0x6B13, 0x628F, 0x83D9, 0x8399, 0x6ACB, 0x3947, 0x2883, 0x2903, 0x3107, 0x28C3, 0x4105,
    0x28C3, 0x30C3, 0x2085, 0x3105, 0x4189, 0x4189, 0x498B, 0x3105, 0x30C5, 0x3147, 0x5A0D, 0x28C5,
    0x4A53, 0x39D5, 0x3A57, 0x294B, 0x294B, 0x294B, 0x41CD, 0x6291, 0x7311, 0x6B53, 0x8B9B, 0x62CD,
    0x728D, 0x524D, 0x49C9, 0x3147, 0x3105, 0x49CB, 0x20C3, 0x30C5, 0x20C3, 0x28C5, 0x41CB, 0x3105,
    0x3989, 0x6AD5, 0x4189, 0x38C7, 0x4989, 0x2905, 0x30C5, 0x5291, 0x3109, 0x3A19, 0x4213, 0x294B,
    0x294B, 0x294B, 0x318D, 0x5ACF, 0x6AD1, 0x7BD9, 0x6B11, 0x7313, 0x8355, 0x5A49, 0x6291, 0x3107,
    0x2903, 0x5A91, 0x49CB, 0x20C3, 0x28C3, 0x20C3, 0x41CD, 0x4189, 0x6AD3, 0x624F, 0x4189, 0x7315,
    0x6AD3, 0x5A4F, 0x4989, 0x4189, 0x314F, 0x63A1, 0x298B, 0x294B, 0x294B, 0x294B, 0x294B, 0x318B,
    0x83DD, 0x7355, 0x7313, 0x6B53, 0x7B53, 0x62CD, 0x5A53, 0x2903, 0x3187, 0x3947, 0x3105, 0x30C5,
    0x5A8F, 0x3947, 0x7355, 0x8BDD, 0x4987, 0x30C5, 0x41C9, 0x3947, 0x49C9, 0x51CB, 0x4149, 0x20C5,
    0x4A57, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x62D7, 0x6B53, 0x8C5F, 0x9CA1,
    0x8BDB, 0x7BD7, 0x839B, 0x6AD1, 0x6A8F, 0x8399, 0x5189, 0x5209, 0x4989, 0x3985, 0x3147, 0x5A4D,
    0x4989, 0x4989, 0x3105, 0x624D, 0x6A91, 0x3945, 0x3947, 0x4A13, 0x298F, 0x294B, 0x294B, 0x294B,
    0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x5A93, 0x7357, 0x949F, 0x8BDB, 0x8397, 0x9CA1, 0x5A4D,
    0x8397, 0x6AD1, 0x6ACF, 0x6A8F, 0x7B13, 0x520B, 0x3107, 0x5209, 0x5A0F, 0x5A4D, 0x4987, 0x28C5,
    0x28C5, 0x3987, 0x394B, 0x318D, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B,
    0x294B, 0x294B, 0x4A51, 0x7B17, 0x7355, 0x9C61, 0xA529, 0x734F, 0x62D1, 0x6AD3, 0x7313, 0x7355,
    0x41C9, 0x3945, 0x4209, 0x4989, 0x3145, 0x51CB, 0x624D, 0x7B17, 0x3947, 0x4189, 0x294B, 0x294B,
    0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x39CF,
    0x62D3, 0x6B11, 0x8BDB, 0x7351, 0x7B99, 0x7313, 0x9C63, 0xA4A3, 0x7355, 0x4A09, 0x420B, 0x524D,
    0x72D1, 0x41CB, 0x4189, 0x4189, 0x3149, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B,
    0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x39CF, 0x6B55, 0x7B55,
    0x7315, 0x6B11, 0x6B11, 0x6B55, 0x7B95, 0x5A4F, 0x41C9, 0x41CB, 0x41CD, 0x3987, 0x314B, 0x294B,
    0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B,
    0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x39CF, 0x5251, 0x6B17, 0x62D1,
    0x7B55, 0x7315, 0x4A11, 0x41CD, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B, 0x294B,
    0x294B, 0x294B, 0x294B, 0x294B,
};
u8 D_802FD6B0[0x100] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0,
    0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 2, 29, 0, 0, 0, 0, 0, 0, 4, 28, 2, 0, 0, 0, 0, 0, 5, 12, 4,
    0, 0, 0, 0, 0, 7, 12, 5, 0, 0, 0, 0, 0, 8, 11, 7, 0, 0, 0, 0, 0, 9, 11, 9, 0, 0, 0, 0, 1, 9,
    10, 11, 0, 0, 0, 0, 2, 8, 10, 28, 0, 0, 0, 0, 3, 8, 9, 30, 0, 0, 0, 0, 5, 8, 9, 31, 0, 0, 0, 0,
    6, 7, 9, 31, 2, 0, 0, 0, 6, 7, 8, 31, 4, 0, 0, 1, 6, 7, 8, 31, 5, 0, 0, 1, 6, 7, 8, 31, 8, 0,
    0, 2, 5, 6, 7, 30, 9, 0, 0, 3, 5, 6, 7, 30, 11, 0, 0, 3, 5, 6, 7, 30, 29, 0, 0, 4, 5, 6, 6, 29,
    30, 0, 0, 3, 4, 5, 6, 29, 31, 0, 0, 3, 4, 5, 6, 29, 31, 2, 1, 3, 4, 5, 6, 29, 31, 4, 1, 3, 3,
    4, 5, 12, 31, 6, 1, 2, 3, 4, 5, 12, 31, 8, 0, 1, 2, 4, 5, 11, 31, 9, 0, 0, 0, 0, 1, 3, 2,
};
Vtx D_802FD7B0[4] = {
    { { { 31, 220, -5 }, 0, { 480, -480 }, { 0, 143, 0, 63 } } },
    { { { 84, 220, -5 }, 0, { -480, -480 }, { 0, 143, 0, 63 } } },
    { { { 84, 170, -5 }, 0, { -480, 480 }, { 0, 143, 0, 63 } } },
    { { { 31, 170, -5 }, 0, { 480, 480 }, { 0, 143, 0, 63 } } },
};
Vtx D_802FD7F0[4] = {
    { { { -4, 0, -5 }, 0, { 224 }, { 255, 255, 255, 127 } } },
    { { { 4, 0, -5 }, 0, { 0 }, { 255, 255, 255, 127 } } },
    { { { -4, 28, -5 }, 0, { 224, 992 }, { 255, 255, 255, 127 } } },
    { { { 4, 28, -5 }, 0, { 0, 992 }, { 255, 255, 255, 127 } } },
};
Vtx D_802FD830[2][12] = {
    {
        { { { 0, 0, -5 }, 0, { 0 }, { 255, 0, 0, 255 } } },
        { { { 0, 0, -5 }, 0, { 0 }, { 255, 0, 0, 255 } } },
        { { { 0, 0, -5 }, 0, { 0 }, { 255, 0, 0, 255 } } },
        { { { 0, 0, -5 }, 0, { 0 }, { 255, 0, 0, 255 } } },
        { { { 0, 0, -5 }, 0, { 0 }, { 0, 0, 255, 255 } } },
        { { { 0, 0, -5 }, 0, { 0 }, { 0, 0, 255, 255 } } },
        { { { 0, 0, -5 }, 0, { 0 }, { 0, 0, 255, 255 } } },
        { { { 0, 0, -5 }, 0, { 0 }, { 0, 0, 255, 255 } } },
        { { { -4, 26, -5 }, 0, { 0 }, { 255, 255, 0, 255 } } },
        { { { -4, 28, -5 }, 0, { 0 }, { 255, 255, 0, 255 } } },
        { { { 4, 28, -5 }, 0, { 0 }, { 255, 255, 0, 255 } } },
        { { { 4, 26, -5 }, 0, { 0 }, { 255, 255, 0, 255 } } },
    },
    {
        { { { 0, 0, -5 }, 0, { 0 }, { 255, 0, 0, 255 } } },
        { { { 0, 0, -5 }, 0, { 0 }, { 255, 0, 0, 255 } } },
        { { { 0, 0, -5 }, 0, { 0 }, { 255, 0, 0, 255 } } },
        { { { 0, 0, -5 }, 0, { 0 }, { 255, 0, 0, 255 } } },
        { { { 0, 0, -5 }, 0, { 0 }, { 0, 0, 255, 255 } } },
        { { { 0, 0, -5 }, 0, { 0 }, { 0, 0, 255, 255 } } },
        { { { 0, 0, -5 }, 0, { 0 }, { 0, 0, 255, 255 } } },
        { { { 0, 0, -5 }, 0, { 0 }, { 0, 0, 255, 255 } } },
        { { { -4, 26, -5 }, 0, { 0 }, { 255, 255, 0, 255 } } },
        { { { -4, 28, -5 }, 0, { 0 }, { 255, 255, 0, 255 } } },
        { { { 4, 28, -5 }, 0, { 0 }, { 255, 255, 0, 255 } } },
        { { { 4, 26, -5 }, 0, { 0 }, { 255, 255, 0, 255 } } },
    },
};
f32 D_802FD9B0 = 0.0f;
Vtx D_802FD9B8[0xa] = {
    { { { 0, 6, -3 }, 0, { 416, 640 }, { 0, 20, 138 } } },
    { { { 8, 21, 4 }, 0, { 128, 768 }, { 45, 18, 147 } } },
    { { { 0, -45, -3 }, 0, { 544, 192 }, { 0, 243, 137 } } },
    { { { -12, 21, 4 }, 0, { 608, 768 }, { 211, 18, 147 } } },
    { { { 10, -60, 4 }, 0, { 352, 64 }, { 36, 227, 146 } } },
    { { { -10, -60, 4 }, 0, { 768, 64 }, { 220, 227, 146 } } },
    { { { 25, 21, 4 }, 0, { -96, 768 }, { 30, 205, 152 } } },
    { { { -24, 21, 4 }, 0, { 864, 768 }, { 226, 205, 152 } } },
    { { { 0, 24, -4 }, 0, { 352, 800 }, { 0, 240, 138 } } },
    { { { 0, 51, 4 }, 0, { 288, 1024 }, { 0, 40, 143 } } },
};

void func_80282C80(Gfx **arg0, Mtx *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    Gfx *gfx;
    f32 dist;
    f32 angle;
    u8 r;
    u8 g;
    s16 v;
    f32 mf[4][4];
    f32 mf2[4][4];
    s32 px;
    s32 pz;
    u8 near;

    gfx = *arg0;
    arg2 >>= 5;
    arg3 >>= 5;
    arg4 >>= 5;
    arg5 >>= 5;
    arg6 >>= 5;
    arg7 >>= 5;
    px = D_803F7670 >> 5;
    pz = D_803F7678 >> 5;
    dist = sqrtf((px - arg2) * (px - arg2) + (pz - arg4) * (pz - arg4));
    if (dist < 1.0) {
        dist = 1.0f;
    }
    if (px >= arg2 && pz >= arg4) {
        angle = func_802AD7D4((px - arg2) / dist * 65536.0) >> 4;
    }
    if (px >= arg2 && pz < arg4) {
        angle = (func_802AD7D4((arg4 - pz) / dist * 65536.0) >> 4) + 0x400;
    }
    if (px < arg2 && pz < arg4) {
        angle = (func_802AD7D4((arg2 - px) / dist * 65536.0) >> 4) + 0x800;
    }
    if (px < arg2 && pz >= arg4) {
        angle = (func_802AD7D4((pz - arg4) / dist * 65536.0) >> 4) + 0xC00;
    }
    angle = angle * (360.0 / 4095.0);
    angle = 360.0 - angle - 45.0;
    angle += D_80364452 * 360.0 / 4095.0 - 135.0;
    dist = sqrtf((arg5 - px) * (arg5 - px) + (arg7 - pz) * (arg7 - pz));
    if (dist > 1500.0f) {
        g = 0xFF;
        r = 0;
    } else if (dist < 500.0f) {
        r = 0xFF;
        g = 0;
    } else {
        v = (dist - 500.0f) / 1000.0f * 511.0f;
        if (v < 0x100) {
            g = v, r = 0xFF;
        } else {
            g = 0xFF, r = 0x1FE - v;
        }
    }
    if (dist < 250.0f) {
        near = 1;
    } else {
        near = 0;
    }
    if ((D_803156C4 % 30 >= 16 || near == 0) && D_803F7660 != 9999999) {
        guRotateF(mf, 20.0f, 1.0f, 0.0f, 0.0f);
        guRotateF(mf2, -angle, 0.0f, 0.0f, 1.0f);
        guMtxCatF(mf, mf2, mf);
        guTranslateF(mf2, -150.0f, -230.0f, -800.0f);
        guMtxCatF(mf, mf2, mf);
        guMtxF2L(mf, &arg1[86]);
        gSPMatrix(gfx++, &D_02000000[2], G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
        gSPPerspNormalize(gfx++, D_8035807C);
        gSPMatrix(gfx++, &D_02000000[86], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
        gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
        gSPSetGeometryMode(gfx++, G_SHADE | G_SHADING_SMOOTH | G_CULL_FRONT | G_LIGHTING | G_TEXTURE_GEN);
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        if (D_80367BD6 == 0xFF) {
            gDPSetRenderMode(gfx++, G_RM_RA_OPA_SURF, G_RM_RA_OPA_SURF2);
        } else {
            gDPSetRenderMode(gfx++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
        }
        gDPSetCombineMode(gfx++, G_CC_MODULATERGBA_PRIM, G_CC_MODULATERGBA_PRIM);
        gDPSetPrimColor(gfx++, 0, 0, r, g, 0, D_80367BD6);
        gSPTexture(gfx++, 0x07C0, 0x07C0, 0, G_TX_RENDERTILE, G_ON);
        gDPLoadTextureBlock(gfx++, OS_K0_TO_PHYSICAL(D_802FCEB0), G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                            G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPVertex(gfx++, osVirtualToPhysical(D_802FD9B8), 10, 0);
        gSP1Triangle(gfx++, 0, 1, 2, 0);
        gSP1Triangle(gfx++, 0, 2, 3, 0);
        gSP1Triangle(gfx++, 3, 1, 0, 0);
        gSP1Triangle(gfx++, 1, 4, 2, 0);
        gSP1Triangle(gfx++, 4, 5, 2, 0);
        gSP1Triangle(gfx++, 5, 3, 2, 0);
        gSP1Triangle(gfx++, 6, 7, 8, 0);
        gSP1Triangle(gfx++, 9, 6, 8, 0);
        gSP1Triangle(gfx++, 7, 9, 8, 0);
        gDPPipeSync(gfx++);
    }
    *arg0 = gfx;
}

void func_8028376C(Gfx **arg0, Mtx *arg1, u8 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    Gfx *gfx = *arg0;
    s32 dist;
    u8 shift;
    s32 scale;
    s16 x;
    s16 y;
    s16 px;
    s16 py;
    Mtx sp1C8;
    f32 sp188[4][4];
    f32 sp148[4][4];
    f32 ox;
    f32 oy;
    f32 oz;
    f32 angle;

    dist = func_8026A610(arg3, arg4, arg5, arg6);
    if (dist < 0x55F0) {
        shift = 10;
        scale = 1200;
    }
    if (dist >= 0x55F0 && dist < 0xABE0) {
        shift = 0;
        scale = 2400;
    }
    if (dist >= 0xABE0) {
        shift = 15;
        scale = 4800;
    }
    if (D_803643DB == 0) {
        shift = 10;
        scale = 1200;
    }
    guRotateF(sp188, 360.0 - (D_80364414 - 180.0), 0.0f, 1.0f, 0.0f);
    guMtxXFMF(sp188, (arg3 - arg5) / scale, 0.0f, (arg4 - arg6) / scale, &ox, &oy, &oz);
    x = 58.0f + ox;
    y = 195.0f + oz;
    D_802FD830[arg2][0].v.ob[0] = x - 2;
    D_802FD830[arg2][0].v.ob[1] = y - 2;
    D_802FD830[arg2][1].v.ob[0] = x - 2;
    D_802FD830[arg2][1].v.ob[1] = y + 1;
    D_802FD830[arg2][2].v.ob[0] = x + 1;
    D_802FD830[arg2][2].v.ob[1] = y + 1;
    D_802FD830[arg2][3].v.ob[0] = x + 1;
    D_802FD830[arg2][3].v.ob[1] = y - 2;
    func_802C1B9C();
    guMtxXFMF(sp188, (arg3 - D_803F7670) / scale, 0.0f, (arg4 - D_803F7678) / scale, &ox, &oy, &oz);
    px = 58.0f + ox;
    py = 195.0f + oz;
    D_802FD830[arg2][4].v.ob[0] = px - 2;
    D_802FD830[arg2][4].v.ob[1] = py - 2;
    D_802FD830[arg2][5].v.ob[0] = px - 2;
    D_802FD830[arg2][5].v.ob[1] = py + 1;
    D_802FD830[arg2][6].v.ob[0] = px + 1;
    D_802FD830[arg2][6].v.ob[1] = py + 1;
    D_802FD830[arg2][7].v.ob[0] = px + 1;
    D_802FD830[arg2][7].v.ob[1] = py - 2;
    gSPMatrix(gfx++, &D_02000000[3], G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPMatrix(gfx++, &D_02000000[7], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
    gSPSetGeometryMode(gfx++, G_SHADE | G_SHADING_SMOOTH);
    gDPPipeSync(gfx++);
    gDPSetTextureLOD(gfx++, G_TL_TILE);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTextureImage(gfx++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, OS_K0_TO_PHYSICAL(D_802FC5B0));
    gDPSetTile(gfx++, G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, 0, 0, 0, 0, 0, 0);
    gDPLoadSync(gfx++);
    gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, 0, 0x7F, 0x400);
    gDPSetTextureImage(gfx++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, OS_K0_TO_PHYSICAL(D_802FC6B0));
    gDPTileSync(gfx++);
    gDPSetTile(gfx++, G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0x100, G_TX_LOADTILE, 0, 0, 0, 0, 0, 0, 0);
    gDPLoadSync(gfx++);
    gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, 0, 0x3FF, 0x200);
    gDPSetTile(gfx++, G_IM_FMT_IA, G_IM_SIZ_8b, 2, 0, G_TX_RENDERTILE, 0, G_TX_MIRROR, 4, G_TX_NOLOD, G_TX_MIRROR, 4,
               G_TX_NOLOD);
    gDPSetTileSize(gfx++, G_TX_RENDERTILE, 2, 2, 0x3E, 0x3E);
    gDPSetTile(gfx++, G_IM_FMT_IA, G_IM_SIZ_4b, 4, 0x100, G_TX_RENDERTILE + 1, 0, G_TX_MIRROR, 6, shift, G_TX_MIRROR,
               6, shift);
    gDPSetTileSize(gfx++, G_TX_RENDERTILE + 1, 2, 2, 0xFC, 0xFC);
    gDPSetCycleType(gfx++, G_CYC_2CYCLE);
    gDPSetRenderMode(gfx++, G_RM_PASS, G_RM_CLD_SURF2);
    gDPSetCombineLERP(gfx++, PRIMITIVE, SHADE, TEXEL1_ALPHA, SHADE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0,
                      0, COMBINED);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, (D_80367BD6 < 0x3F) ? D_80367BD6 : 0x3F);
    gSPVertex(gfx++, osVirtualToPhysical(D_802FD7B0), 4, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);
    gSP1Triangle(gfx++, 0, 2, 3, 0);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetCombineLERP(gfx++, 0, 0, 0, SHADE, 0, 0, 0, PRIMITIVE, 0, 0, 0, SHADE, 0, 0, 0, PRIMITIVE);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, D_80367BD6);
    if (D_803643DB != 0) {
        gDPSetRenderMode(gfx++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
        if ((D_803156C4 % 40 > 20 || shift != 10) && x >= 0x22 && x < 0x53 && y >= 0xAB && y < 0xDC) {
            gSPVertex(gfx++, osVirtualToPhysical(D_802FD830[arg2]), 4, 0);
            gSP1Triangle(gfx++, 0, 1, 2, 0);
            gSP1Triangle(gfx++, 0, 2, 3, 0);
        }
        if (px >= 0x22 && px < 0x53 && py >= 0xB0 && py < 0xD7 && D_803F7660 != 9999999) {
            gSPVertex(gfx++, osVirtualToPhysical(&D_802FD830[arg2][4]), 4, 0);
            gSP1Triangle(gfx++, 0, 1, 2, 0);
            gSP1Triangle(gfx++, 0, 2, 3, 0);
        }
    }
    angle = func_80284ADC(arg3 >> 5, arg4 >> 5, D_803F767C, D_803F7680);
    guRotateF(sp188, -((360.0 - (D_80364414 - 180.0)) + (angle + 180.0)), 0.0f, 0.0f, 1.0f);
    guTranslateF(sp148, 58.0f, 195.0f, 0.0f);
    guMtxCatF(sp188, sp148, sp188);
    guMtxF2L(sp188, &D_8036E5E0[arg2]);
    gDPPipeSync(gfx++);
    if (D_80367BD6 == 0xFF) {
        gDPSetRenderMode(gfx++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
    } else {
        gDPSetRenderMode(gfx++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    }
    gSPMatrix(gfx++, osVirtualToPhysical(&D_8036E5E0[arg2]), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    gSPVertex(gfx++, osVirtualToPhysical(&D_802FD830[arg2][8]), 4, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);
    gSP1Triangle(gfx++, 0, 2, 3, 0);
    gSPPopMatrix(gfx++, G_MTX_MODELVIEW);
    if (D_803643DB != 0) {
        gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gDPSetRenderMode(gfx++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
        gDPSetCombineLERP(gfx++, 0, 0, 0, SHADE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, SHADE, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, (D_80367BD6 >= 0x80) ? 0x7F : D_80367BD6);
        gDPLoadTextureBlock(gfx++, OS_K0_TO_PHYSICAL(D_802FD6B0), G_IM_FMT_IA, G_IM_SIZ_8b, 8, 32, 0, G_TX_CLAMP,
                            G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        guRotate(&arg1[23], D_802FD9B0, 0.0f, 0.0f, 1.0f);
        guTranslate(&sp1C8, 58.0f, 195.0f, 0.0f);
        guMtxCatL(&arg1[23], &sp1C8, &arg1[23]);
        D_802FD9B0 += 4.0;
        gSPMatrix(gfx++, &D_02000000[23], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
        gSPVertex(gfx++, osVirtualToPhysical(D_802FD7F0), 4, 0);
        gSP1Triangle(gfx++, 0, 1, 2, 0);
        gSP1Triangle(gfx++, 1, 2, 3, 0);
    }
    gDPPipeSync(gfx++);
    *arg0 = gfx;
}

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
        return func_802AD7D4((arg2 - arg0) * 65535.9 / dist) / 65536.0 * 360.0;
    }
    if (arg2 >= arg0 && arg3 < arg1) {
        return (func_802AD7D4((arg1 - arg3) * 65535.9 / dist) + 0x4000) / 65536.0 * 360.0;
    }
    if (arg2 < arg0 && arg3 < arg1) {
        return (func_802AD7D4((arg0 - arg2) * 65535.9 / dist) + 0x8000) / 65536.0 * 360.0;
    }
    if (arg2 < arg0 && arg3 >= arg1) {
        return (func_802AD7D4((arg3 - arg1) * 65535.9 / dist) + 0xC000) / 65536.0 * 360.0;
    }
}
