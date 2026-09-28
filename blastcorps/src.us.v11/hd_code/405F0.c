#include "common.h"

/* An RSP task with the bookkeeping sent along with it: 0x60 bytes, two per
 * task slot (double-buffered by D_8035805C). */
typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ u16 *unkC;
    /* 0x10 */ OSTask task;
    /* 0x50 */ void *unk50;
    /* 0x54 */ OSMesgQueue *unk54;
    /* 0x58 */ s32 unk58;
    /* 0x5C */ s32 unk5C;
} UnkStruct_8036E698; /* size = 0x60 */

extern u16 D_80000400[][320 * 240];
extern u64 D_80207090[];
extern u64 D_80210690[];
extern u64 D_802E53F0[];
extern u64 D_802E6820[];
extern u64 D_802E68F0[];
extern char D_8030C890[];
extern u64 D_8030E390[];
extern OSMesgQueue D_803153D8;
extern OSMesgQueue D_80315440;
extern u8 D_803156D8[];
extern u8 D_803156F8[];
extern u8 D_8035805C;
extern u64 D_80367750[];
extern u64 D_8036AFB0[];
extern u64 *D_8036E660[];
extern u64 *D_8036E678[];
extern u8 D_8036E68C[];
extern u64 *D_8036E694;
extern UnkStruct_8036E698 D_8036E698[][2];

void func_8029A7E4(char *, ...);

void func_80284DB0(void) {
    D_8036E660[0] = D_80207090;
    D_8036E678[0] = D_80210690;
    D_8036E660[1] = D_802E53F0;
    D_8036E678[1] = D_8030E390;
    D_8036E660[2] = D_802E53F0;
    D_8036E678[2] = D_8030E390;
    D_8036E660[3] = D_802E53F0;
    D_8036E678[3] = D_8030E390;
}

void func_80284E54(Gfx *arg0, s32 arg1, u8 arg2, u8 arg3, s32 arg4, u8 arg5) {
    UnkStruct_8036E698 *t;
    s32 size;

    size = arg1 * 8;
    t = &D_8036E698[arg2][D_8035805C];
    D_8036E68C[arg2] = 1;
    t->task.t.type = M_GFXTASK;
    if (arg2 == 4) {
        t->task.t.flags = 2;
    } else {
        t->task.t.flags = 0;
    }
    t->task.t.ucode_boot = D_802E6820;
    t->task.t.ucode_boot_size = (u8 *)D_802E68F0 - (u8 *)D_802E6820;
    t->task.t.ucode = D_8036E660[arg2];
    t->task.t.ucode_data = D_8036E678[arg2];
    t->task.t.ucode_size = 0x1000;
    t->task.t.ucode_data_size = 0x800;
    t->task.t.dram_stack = D_80367750;
    t->task.t.dram_stack_size = 0x400;
    t->task.t.output_buff = D_8036E694;
    t->task.t.output_buff_size = (u64 *)((u8 *)D_8036E694 + 0xA000);
    t->task.t.data_ptr = (u64 *)arg0;
    t->task.t.data_size = size;
    t->task.t.yield_data_ptr = D_8036AFB0;
    t->task.t.yield_data_size = 0x900;
    t->unk0 = 0;
    t->unk54 = &D_803153D8;
    t->unk58 = (arg2 << 16) | arg4;
    t->unk8 = 3;
    if (arg3) {
        t->unk8 |= 0x40;
    }
    t->unkC = D_80000400[D_8035805C];
    t->unk50 = D_803156D8;
    if (arg5) {
        osWritebackDCacheAll();
    } else {
        osWritebackDCache(t, 0x60);
        osWritebackDCache(arg0, size);
        osWritebackDCache(D_803156F8 + D_8035805C * 0x21498, 0x21498);
    }
    osSendMesg(&D_80315440, t, OS_MESG_BLOCK);
}

void func_80285110(u32 arg0) {
    u32 msg;

    do {
        osRecvMesg(&D_803153D8, (OSMesg *)&msg, OS_MESG_BLOCK);
        D_8036E68C[msg >> 16] = 0;
        msg &= 0xFFFF;
        if (msg != arg0) {
            func_8029A7E4(D_8030C890, arg0, msg);
        }
    } while (msg != arg0);
}
