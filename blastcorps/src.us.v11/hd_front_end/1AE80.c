#include "common.h"

/* D_80364AF0's 0x100-byte records, indexed by D_80364AE8. */
typedef struct {
    /* 0x00 */ u8 unk0[0x18];
    /* 0x18 */ u8 unk18[0x7A];
    /* 0x92 */ u8 unk92[0x6E];
} UnkStruct_80364AF0; /* size = 0x100 */

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1[0x43];
} UnkStruct_802E8F94; /* size = 0x44 */

void func_801F8354(u8);
void func_8029A7E4(char *, ...);

extern char D_80210670[];
extern OSMesgQueue D_80219EF8;
extern OSMesgQueue D_80219F50;
extern u8 D_802E8C44[];
extern UnkStruct_802E8F94 D_802E8F94[];
extern u8 D_80364AE8;
extern UnkStruct_80364AF0 D_80364AF0[];
extern u16 D_80364EF0[][16];
extern u16 D_80364F70[];
extern u8 D_8039C4B8[];

s32 func_80201E80(void) {
    u8 i;
    s32 ret;

    ret = 0;
    func_8029A7E4(D_80210670);
    for (i = 0; i < 60 && ret == 0; i++) {
        if (!(i & 1)) {
            osSendMesg(&D_80219EF8, (OSMesg)((i << 8) | 0xA | (D_80364AE8 << 16) | 0x01000000), OS_MESG_BLOCK);
            osRecvMesg(&D_80219F50, (OSMesg *)&ret, OS_MESG_BLOCK);
        }
        if (((D_80364AF0[D_80364AE8].unk18[i] > 0 && D_80364AF0[D_80364AE8].unk18[i] < 6) ? TRUE : FALSE) &&
            i != 0x31 && i != 0x2F && i != 0x26 && ret == 0) {
            if (D_802E8F94[i].unk0 == 1) {
                *(u64 *)D_8039C4B8 = 0x1234567887654321;
                osSendMesg(&D_80219EF8, (OSMesg)((i << 8) | 0xD | (D_80364AE8 << 16) | 0x01000000),
                           OS_MESG_BLOCK);
                osRecvMesg(&D_80219F50, NULL, OS_MESG_BLOCK);
            }
            func_801F8354(D_80364AE8);
            D_80364EF0[D_80364AE8][D_802E8C44[D_80364AF0[D_80364AE8].unk92[i]]] = D_80364F70[i * 2];
            osSendMesg(&D_80219EF8, (OSMesg)((i << 8) | 9 | (D_80364AE8 << 16) | 0x01000000), OS_MESG_BLOCK);
            osRecvMesg(&D_80219F50, NULL, OS_MESG_BLOCK);
        }
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_front_end/1AE80/func_80202100.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_front_end/1AE80/func_802021FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_front_end/1AE80/func_80202270.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_front_end/1AE80/func_802022EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_front_end/1AE80/func_80202380.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_front_end/1AE80/func_802025D0.s")
