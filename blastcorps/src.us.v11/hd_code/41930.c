#include "common.h"

typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ u8 unk4[0x2C];
} UnkStruct_8020D7E4; /* size = 0x30 */

extern u8 D_802FDA60[];
extern u8 D_802FDA70[];
extern UnkStruct_8020D7E4 D_8020D7E4[];

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1[7];
} UnkStruct_802E8F38; /* size = 0x8 */

typedef struct {
    /* 0x000 */ u8 unk0[0x904];
    /* 0x904 */ char *unk904;
} UnkStruct_8020C070;

extern u64 D_80364A98;
extern u8 D_80364AE8;
extern u8 D_80364B80[][0x100];
extern u8 D_80364B81[][0x100];
extern UnkStruct_802E8F38 D_802E8F38[];
extern UnkStruct_8020C070 D_8020C070[];
extern char D_8036EBA0[];
extern s32 D_80358060;

void func_801ECC8C(void);
void func_80200714(u8);
void func_80255DC8(void);
void func_80260C20(u8, f32);
void func_8026AF6C(s32);

void func_802860F0(void) {
    u8 sp37;
    s32 sp30;
    s32 sp2C;
    s32 sp28;

    if (D_80364B81[D_80364AE8][0] != 0xD && D_80364B81[D_80364AE8][0] != 8 && D_80364B81[D_80364AE8][0] != 1) {
        D_80364A98 = 0x800000000000;
        func_80255DC8();
        func_80200714(D_802FDA60[D_80364B81[D_80364AE8][0]]);
        switch (D_80364B81[D_80364AE8][0]) {
            case 4:
                sp37 = 0;
                for (sp30 = 0; sp30 < 60 && sp37 == 0; sp30++) {
                    for (sp2C = 0, sp28 = 0; sp2C < 6 && sp28 == 0; sp2C++) {
                        if (D_802E8F38[sp2C].unk0 == sp30) {
                            sp28 = 1;
                            if (!(D_80364B80[D_80364AE8][0] & (1 << sp2C))) {
                                sp37 = 1;
                            }
                        }
                    }
                }
                sprintf(D_8036EBA0, "IN %s.", D_8020D7E4[sp30].unk0);
                D_8020C070[0].unk904 = D_8036EBA0;
                break;
            case 6:
                func_801ECC8C();
                break;
        }
        func_8026AF6C((D_80364B81[D_80364AE8][0] + 0x16) | 0x8000);
    }
}

void func_802862DC(void) {
    if (D_80358060 == 0) {
        func_80260C20(D_802FDA70[D_80364B81[D_80364AE8][0]], 1.0f);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/41930/func_80286330.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/41930/func_8028653C.s")
