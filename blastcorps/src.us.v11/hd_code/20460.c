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

/* The scheduler's OSScTask, with an extra field before msgQ. */
typedef struct {
    /* 0x00 */ void *next;
    /* 0x04 */ u32 state;
    /* 0x08 */ u32 flags;
    /* 0x0C */ void *framebuffer;
    /* 0x10 */ OSTask list;
    /* 0x50 */ void *unk50;
    /* 0x54 */ OSMesgQueue *msgQ;
    /* 0x58 */ OSMesg msg;
    /* 0x5C */ u32 unk5C;
} UnkScTask; /* size = 0x60 */

typedef struct {
    /* 0x00 */ s16 *data;
    /* 0x04 */ s16 frameSamples;
    /* 0x08 */ UnkScTask task;
} UnkAudioInfo; /* size = 0x68 */

/* The sample audio manager's AMAudioMgr. */
typedef struct {
    /* 0x000 */ Acmd *ACMDList[2];
    /* 0x008 */ UnkAudioInfo *audioInfo[3];
    /* 0x018 */ OSThread thread;
    /* 0x1C8 */ OSMesgQueue audioFrameMsgQ;
    /* 0x1E0 */ OSMesg audioFrameMsgBuf[8];
    /* 0x200 */ OSMesgQueue audioReplyMsgQ;
    /* 0x218 */ OSMesg audioReplyMsgBuf[8];
    /* 0x238 */ ALGlobals g;
} UnkAudioMgr;

typedef struct {
    /* 0x00 */ ALLink node;
    /* 0x08 */ u32 startAddr;
    /* 0x0C */ u32 lastFrame;
    /* 0x10 */ char *ptr;
} UnkDMABuffer; /* size = 0x14 */

/* OSIoMesg from before 2.0I added piHandle. */
typedef struct {
    /* 0x00 */ OSIoMesgHdr hdr;
    /* 0x08 */ void *dramAddr;
    /* 0x0C */ u32 devAddr;
    /* 0x10 */ u32 size;
} UnkIoMesg; /* size = 0x14 */

typedef struct {
    /* 0x0 */ u8 initialized;
    /* 0x4 */ UnkDMABuffer *firstUsed;
    /* 0x8 */ UnkDMABuffer *firstFree;
} UnkDMAState;

/* ALSynConfig, with a u8 fxType. */
typedef struct {
    /* 0x00 */ s32 maxVVoices;
    /* 0x04 */ s32 maxPVoices;
    /* 0x08 */ s32 maxUpdates;
    /* 0x0C */ s32 maxFXbusses;
    /* 0x10 */ void *dmaproc;
    /* 0x14 */ ALHeap *heap;
    /* 0x18 */ s32 outputRate;
    /* 0x1C */ u8 fxType;
    /* 0x20 */ s32 *params;
} UnkSynConfig;

typedef struct {
    /* 0x000 */ s32 v[66];
} UnkFxParams; /* size = 0x108 */

typedef struct {
    /* 0x00 */ u8 unk0[0x12];
    /* 0x12 */ u8 unk12;
} UnkStruct_80267614;

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
void func_80267A9C(void *arg);
void func_80267CDC(UnkAudioInfo *info, UnkAudioInfo *lastInfo);
void func_80267F88(UnkAudioInfo *info);
void func_80261068(void);
void func_802611F0(void);
void func_80261284(void);
void func_802613C8(void);
void func_80261528(void);
void func_802682A4(void);
void func_802D9B60(void *buf, u32 size);
OSMesgQueue *func_80270F74(void *sc);
void func_80270E50(void *sc, void *client, OSMesgQueue *mq, s32 arg3, s32 arg4);
void func_8029A7E4(char *, ...);
ALDMAproc func_80268254(UnkDMAState **state);
s32 func_80267FE0(s32 addr, s32 len, void *state);

extern s32 D_80000300;
extern s32 osViClock;
extern u8 D_802E8BD0;
extern u64 D_802E6820[];
extern u64 D_802E68F0[];
extern u32 D_802F3AF0;
extern u32 D_802F3AF4;
extern s32 D_802F3AF8;
extern s32 D_802F3C04;
extern char D_80309714[];
extern char D_80309740[];
extern char D_80309758[];
extern char D_80309760[];
extern char D_8030978C[];
extern char D_803097CC[];
extern char D_803097D4[];
extern char D_803097F0[];
extern char D_80309818[];
extern u64 D_8030EB90[];
extern s32 D_8036A8C4;
extern UnkFxParams D_802F3AFC;
extern char D_80309700[];
extern s32 D_803156A4;
extern u8 D_80315440[];
extern u8 D_80367728;
extern u8 D_80367729;
extern u8 D_8036772A;
extern s32 D_8036772C;
extern u8 D_80367730;
extern u64 D_80368058;
extern u64 D_80368060;
extern u64 D_80368068;
extern u8 D_803682F8[];
extern u16 D_803C30A8[];
extern UnkAudioMgr D_80368070;
extern u64 D_80368308[];
extern UnkDMAState D_8036A308;
extern UnkDMABuffer D_8036A318[];
extern UnkIoMesg D_8036A8C8[];
extern s32 D_8036AFA0;
extern u32 D_8036A8B8;
extern u32 D_8036A8BC;
extern u32 D_8036A8C0;
extern OSMesgQueue D_8036AE68;
extern OSMesg D_8036AE80[];
extern f32 D_80309640;
extern s32 D_803643E0;
extern s32 D_803643E8;
extern s16 D_8036443C;
extern s16 D_8036443E;
extern s16 D_80368034;
extern s16 D_80368036;
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
extern s32 D_803EF2EC;
extern s32 D_803EF2F4;
extern s32 D_803EF308;
extern s32 D_803EF30C;
extern u8 D_803EF32C;
extern u8 D_803EF32D;
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

void func_80265428(void) {
    s32 i;
    s32 unused;
    s32 x1;
    s32 z1;
    s32 x2;
    s32 z2;
    s32 d1;
    s32 d2;

    for (i = 0; i < 20; i++) {
        if ((D_80367D60[i].unk15 == 1 || D_80367D60[i].unk15 == 4 || D_80367D60[i].unk15 == 2) &&
            func_80265A0C(i) != 0) {
            func_80265B7C(i);
            x1 = D_80367D60[i].unk0 + D_80368034;
            z1 = D_80367D60[i].unk4 + D_80368036;
            x2 = D_80367D60[i].unk0 - D_80368034;
            z2 = D_80367D60[i].unk4 - D_80368036;
            if (x1 < D_80367D60[i].unkA - D_80367D60[i].unkE) {
                x1 = D_80367D60[i].unkA - D_80367D60[i].unkE;
            }
            if (z1 < D_80367D60[i].unkC - D_80367D60[i].unkE) {
                z1 = D_80367D60[i].unkC - D_80367D60[i].unkE;
            }
            if (x1 >= D_80367D60[i].unkA + D_80367D60[i].unkE) {
                x1 = D_80367D60[i].unkA + D_80367D60[i].unkE - 1;
            }
            if (z1 >= D_80367D60[i].unkC + D_80367D60[i].unkE) {
                z1 = D_80367D60[i].unkC + D_80367D60[i].unkE - 1;
            }
            if (x2 < D_80367D60[i].unkA - D_80367D60[i].unkE) {
                x2 = D_80367D60[i].unkA - D_80367D60[i].unkE;
            }
            if (z2 < D_80367D60[i].unkC - D_80367D60[i].unkE) {
                z2 = D_80367D60[i].unkC - D_80367D60[i].unkE;
            }
            if (x2 >= D_80367D60[i].unkA + D_80367D60[i].unkE) {
                x2 = D_80367D60[i].unkA + D_80367D60[i].unkE - 1;
            }
            if (z2 >= D_80367D60[i].unkC + D_80367D60[i].unkE) {
                z2 = D_80367D60[i].unkC + D_80367D60[i].unkE - 1;
            }
            d1 = func_8026A610(D_803643E0 >> 5, D_803643E8 >> 5, x1, z1);
            d2 = func_8026A610(D_803643E0 >> 5, D_803643E8 >> 5, x2, z2);
            if (D_80367D60[i].unk1B != 0) {
                if (D_80367D60[i].unk1A != 0) {
                    d2 = 0;
                } else {
                    d1 = 0;
                }
                D_80367D60[i].unk1B--;
            }
            if (d1 < d2) {
                D_80367D60[i].unk0 = x2;
                D_80367D60[i].unk4 = z2;
                D_80367D60[i].unk18 += 0x800;
                if (D_80367D60[i].unk18 >= 0x1000) {
                    D_80367D60[i].unk18 -= 0xFFF;
                }
                if (D_80367D60[i].unk1A != 0) {
                    D_80367D60[i].unk1B = 5;
                }
                D_80367D60[i].unk1A = 0;
            } else {
                D_80367D60[i].unk0 = x1;
                D_80367D60[i].unk4 = z1;
                if (D_80367D60[i].unk1A == 0) {
                    D_80367D60[i].unk1B = 5;
                }
                D_80367D60[i].unk1A = 1;
            }
            if (i == 1 && D_80367D60[i].unk15 != 4) {
                func_80260650(D_80367738, 0x24, NULL);
            }
            if (D_80367D60[i].unk15 == 2) {
                D_803EF32C = 6;
            }
            D_80367D60[i].unk15 = 4;
        } else if (D_80367D60[i].unk15 == 4) {
            D_80367D60[i].unk15 = 1;
        }
    }
}

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

void func_80265B7C(s32 arg0) {
    s16 angle;
    s16 a;
    s16 sn;
    s16 cs;
    s16 sx;
    s16 sz;
    s32 max;

    max = D_8036443C / 40;
    if (max < 0) {
        max = -max;
    }
    if (D_8036443C != 0 && max == 0) {
        max = 2;
    }
    angle = D_80367D60[arg0].unk16 + D_8036443E + 0x400;
    if (angle >= 0x1000) {
        angle = angle - 0xFFF;
    }
    D_80367D60[arg0].unk18 = angle;
    a = angle % 1024;
    sn = sins(a * 0xFFFF / 4095);
    cs = coss(a * 0xFFFF / 4095);
    if (D_80367D60[arg0].unk1C < max) {
        D_80367D60[arg0].unk1C += 1;
    }
    if (D_80367D60[arg0].unk1C > max) {
        D_80367D60[arg0].unk1C -= 1;
    }
    sx = (D_80367D60[arg0].unk1C * sn) >> 15;
    sz = (D_80367D60[arg0].unk1C * cs) >> 15;
    if (angle < 0x400) {
        D_80368034 = sx;
        D_80368036 = sz;
    }
    if (angle >= 0x400 && angle < 0x800) {
        D_80368034 = sz;
        D_80368036 = -sx;
    }
    if (angle >= 0x800 && angle < 0xC00) {
        D_80368034 = -sx;
        D_80368036 = -sz;
    }
    if (angle >= 0xC00) {
        D_80368034 = -sz;
        D_80368036 = sx;
    }
}

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

s32 func_80267614(UnkStruct_80267614 *arg0) {
    s32 i;
    u8 id;

    i = 0;
    id = arg0->unk12;
    while (D_803C30A8[i] != 0xFFFF) {
        if (D_803C30A8[i++] == id) {
            return 1;
        }
    }
    return 0;
}

void func_802676A0(UnkSynConfig *c, OSPri pri) {
    s32 i;
    f32 fsize;
    s32 unused;
    UnkFxParams params;

    c->dmaproc = func_80268254;
    if (D_80000300 != 1) {
        osViClock = 0x02E6025C;
    }
    c->outputRate = osAiSetFrequency(22050);
    fsize = (f32)c->outputRate * 2.0f / 60.0f;
    D_8036A8BC = (s32)fsize;
    if (D_8036A8BC < fsize) {
        D_8036A8BC++;
    }
    if (D_8036A8BC & 0xF) {
        D_8036A8BC = (D_8036A8BC & ~0xF) + 0x10;
    }
    D_8036A8B8 = D_8036A8BC - 16;
    D_8036A8C0 = D_8036A8BC + 53;
    if (c->fxType == AL_FX_CUSTOM) {
        unused = 0;
        params = D_802F3AFC;
        c->params = params.v;
        alInit(&D_80368070.g, (ALSynConfig *)c);
    } else {
        alInit(&D_80368070.g, (ALSynConfig *)c);
    }
    D_8036A318[0].node.prev = NULL;
    D_8036A318[0].node.next = NULL;
    for (i = 0; i < 71; i++) {
        alLink(&D_8036A318[i + 1].node, &D_8036A318[i].node);
        D_8036A318[i].ptr = alHeapAlloc(c->heap, 1, 0x200);
    }
    D_8036A318[i].ptr = alHeapAlloc(c->heap, 1, 0x200);
    for (i = 0; i < 2; i++) {
        D_80368070.ACMDList[i] = alHeapAlloc(c->heap, 1, 0x55F0);
    }
    for (i = 0; i < 3; i++) {
        D_80368070.audioInfo[i] = alHeapAlloc(c->heap, 1, sizeof(UnkAudioInfo));
        D_80368070.audioInfo[i]->data = alHeapAlloc(c->heap, 1, D_8036A8C0 * 4);
    }
    osCreateMesgQueue(&D_80368070.audioReplyMsgQ, D_80368070.audioReplyMsgBuf, 8);
    osCreateMesgQueue(&D_80368070.audioFrameMsgQ, D_80368070.audioFrameMsgBuf, 8);
    osCreateMesgQueue(&D_8036AE68, D_8036AE80, 0x48);
    osCreateThread(&D_80368070.thread, 4, func_80267A9C, NULL, &D_80368308[0x2000 / sizeof(u64)], pri);
}

void func_80267A74(void) {
    osStartThread(&D_80368070.thread);
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/20460/func_80267A9C.s")

void func_80267CDC(UnkAudioInfo *info, UnkAudioInfo *lastInfo) {
    s16 *audioPtr;
    Acmd *cmdp;
    u32 samplesLeft;
    UnkScTask *t;

    samplesLeft = 0;
    func_802682A4();
    audioPtr = (s16 *)osVirtualToPhysical(info->data);
    if (lastInfo != NULL) {
        func_802D9B60(lastInfo->data, lastInfo->frameSamples << 2);
    }
    samplesLeft = osAiGetLength() >> 2;
    info->frameSamples = (D_8036A8BC - samplesLeft + 53) & ~0xF;
    if (info->frameSamples < D_8036A8B8) {
        info->frameSamples = D_8036A8B8;
    }
    cmdp = alAudioFrame(D_80368070.ACMDList[D_802F3AF8], &D_8036A8C4, audioPtr, info->frameSamples);
    if (D_8036A8C4 > 2750) {
        func_8029A7E4(D_80309714, D_80309740, D_80309758, 0x150);
    }
    t = &info->task;
    t->next = NULL;
    t->msgQ = &D_80368070.audioReplyMsgQ;
    t->msg = (OSMesg)info;
    t->flags = 1;
    t->unk50 = D_803682F8;
    t->list.t.data_ptr = (u64 *)D_80368070.ACMDList[D_802F3AF8];
    t->list.t.data_size = (cmdp - D_80368070.ACMDList[D_802F3AF8]) * sizeof(Acmd);
    t->list.t.type = M_AUDTASK;
    t->list.t.ucode_boot = D_802E6820;
    t->list.t.ucode_boot_size = (s32)D_802E68F0 - (s32)D_802E6820;
    t->list.t.flags = 0;
    t->list.t.ucode = D_802E68F0;
    t->list.t.ucode_data = D_8030EB90;
    t->list.t.ucode_data_size = 0x800;
    t->list.t.yield_data_ptr = NULL;
    t->list.t.yield_data_size = 0;
    osWritebackDCache(t, sizeof(UnkScTask));
    osWritebackDCache(t->list.t.data_ptr, t->list.t.data_size);
    if (osSendMesg(func_80270F74(D_80315440), t, OS_MESG_NOBLOCK) == -1) {
        func_8029A7E4(D_80309760, D_8030978C, D_803097CC, 0x169);
    }
    D_802F3AF8 ^= 1;
}

void func_80267F88(UnkAudioInfo *info) {
    u32 samplesLeft;

    samplesLeft = osAiGetLength() >> 2;
    if (samplesLeft == 0 && D_802F3C04 == 0) {
        func_8029A7E4(D_803097D4);
        D_802F3C04 = 0;
    }
}

s32 func_80267FE0(s32 addr, s32 len, void *state) {
    void *foundBuffer;
    s32 delta;
    s32 addrEnd;
    s32 buffEnd;
    UnkDMABuffer *dmaPtr;
    UnkDMABuffer *lastDmaPtr;
    UnkDMABuffer *cur;
    s32 count;

    count = 0;
    lastDmaPtr = NULL;
    dmaPtr = D_8036A308.firstUsed;
    addrEnd = addr + len;
    delta = addr & 1;
    while (dmaPtr != NULL) {
        cur = dmaPtr;
        buffEnd = dmaPtr->startAddr + 0x200;
        if (dmaPtr->startAddr > addr) {
            break;
        } else if (addrEnd <= buffEnd) {
            dmaPtr->lastFrame = D_802F3AF0;
            foundBuffer = dmaPtr->ptr + addr - dmaPtr->startAddr;
            return osVirtualToPhysical(foundBuffer);
        }
        lastDmaPtr = dmaPtr;
        dmaPtr = (UnkDMABuffer *)dmaPtr->node.next;
        count++;
    }
    if (count > D_8036AFA0) {
        D_8036AFA0 = count;
    }
    dmaPtr = D_8036A308.firstFree;
    if (dmaPtr == NULL) {
        func_8029A7E4(D_803097F0);
    }
    if (dmaPtr == NULL) {
        return osVirtualToPhysical(D_8036A308.firstUsed);
    }
    D_8036A308.firstFree = (UnkDMABuffer *)dmaPtr->node.next;
    alUnlink(&dmaPtr->node);
    if (lastDmaPtr != NULL) {
        alLink(&dmaPtr->node, &lastDmaPtr->node);
    } else if (D_8036A308.firstUsed != NULL) {
        lastDmaPtr = D_8036A308.firstUsed;
        D_8036A308.firstUsed = dmaPtr;
        dmaPtr->node.next = &lastDmaPtr->node;
        dmaPtr->node.prev = NULL;
        lastDmaPtr->node.prev = &dmaPtr->node;
    } else {
        D_8036A308.firstUsed = dmaPtr;
        dmaPtr->node.next = NULL;
        dmaPtr->node.prev = NULL;
    }
    foundBuffer = dmaPtr->ptr;
    addr -= delta;
    dmaPtr->startAddr = addr;
    dmaPtr->lastFrame = D_802F3AF0;
    osPiStartDma((OSIoMesg *)&D_8036A8C8[D_802F3AF4++], OS_MESG_PRI_NORMAL, OS_READ, addr, foundBuffer, 0x200, &D_8036AE68);
    return osVirtualToPhysical(foundBuffer) + delta;
}

ALDMAproc func_80268254(UnkDMAState **state) {
    s32 unused;

    if (!D_8036A308.initialized) {
        D_8036A308.firstUsed = NULL;
        D_8036A308.firstFree = D_8036A318;
        D_8036A308.initialized = 1;
    }
    *state = &D_8036A308;
    return (ALDMAproc)func_80267FE0;
}

void func_802682A4(void) {
    u32 i;
    OSIoMesg *iomsg;
    UnkDMABuffer *dmaPtr;
    UnkDMABuffer *nextPtr;

    for (i = 0; i < D_802F3AF4; i++) {
        if (osRecvMesg(&D_8036AE68, (OSMesg *)&iomsg, OS_MESG_NOBLOCK) == -1) {
            func_8029A7E4(D_80309818);
        }
    }
    dmaPtr = D_8036A308.firstUsed;
    while (dmaPtr != NULL) {
        nextPtr = (UnkDMABuffer *)dmaPtr->node.next;
        if (dmaPtr->lastFrame + 1 < D_802F3AF0) {
            if (D_8036A308.firstUsed == dmaPtr) {
                D_8036A308.firstUsed = (UnkDMABuffer *)dmaPtr->node.next;
            }
            alUnlink(&dmaPtr->node);
            if (D_8036A308.firstFree != NULL) {
                alLink(&dmaPtr->node, &D_8036A308.firstFree->node);
            } else {
                D_8036A308.firstFree = dmaPtr;
                dmaPtr->node.next = NULL;
                dmaPtr->node.prev = NULL;
            }
        }
        dmaPtr = nextPtr;
    }
    D_802F3AF4 = 0;
    D_802F3AF0++;
}
