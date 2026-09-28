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

void func_80267A9C(void *arg);
void func_80267CDC(UnkAudioInfo *info, UnkAudioInfo *lastInfo);
void func_80267F88(UnkAudioInfo *info);
void func_802682A4(void);
OSMesgQueue *func_80270F74(void *sc);
void func_8029A7E4(char *, ...);
ALDMAproc func_80268254(UnkDMAState **state);
s32 func_80267FE0(s32 addr, s32 len, void *state);

extern s32 D_80000300;
extern s32 osViClock;
extern u64 D_802E6820[];
extern u64 D_802E68F0[];
extern u32 D_802F3AF0;
extern u32 D_802F3AF4;
extern s32 D_802F3AF8;
extern s32 D_802F3C04;
extern u64 D_8030EB90[];
extern s32 D_8036A8C4;
extern UnkFxParams D_802F3AFC;
extern u8 D_80315440[];
extern u8 D_803682F8[];
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

extern s32 D_803156A4;
extern u8 D_80367728;
extern u8 D_80367729;
extern u8 D_8036772A;
extern s32 D_8036772C;
extern u8 D_80367730;
/*
 * This file's own .bss: the u64 halves share one lui only with these defined
 * here.  The addresses still come from the absolute symbols in undefined_syms.
 */
OSTime D_80368058;
OSTime D_80368060;
OSTime D_80368068;

void func_80270E50(void *, void *, OSMesgQueue *, s32, s32);
void func_80261068(void);
void func_802611F0(void);
void func_80261284(void);
void func_802613C8(void);
void func_80261528(void);

void func_80267A9C(void *arg) {
    s32 done;
    s32 msg;
    UnkAudioInfo *lastInfo;
    s32 first;

    done = 0;
    lastInfo = NULL;
    first = 1;
    func_80270E50(D_80315440, D_803682F8, &D_80368070.audioFrameMsgQ, 2, 2);
    osSendMesg(&D_80368070.audioFrameMsgQ, (OSMesg)5, OS_MESG_NOBLOCK);
    while (!done) {
        osRecvMesg(&D_80368070.audioFrameMsgQ, (OSMesg *)&msg, OS_MESG_BLOCK);
        switch (msg) {
            case 5:
                if (D_803156A4 != 0) {
                    osSendMesg((OSMesgQueue *)D_80315440, (OSMesg)0x29E, OS_MESG_BLOCK);
                }
                D_80368060 = osGetTime();
                func_80267CDC(D_80368070.audioInfo[D_802F3AF0 % 3], lastInfo);
                D_80368068 = osGetTime();
                D_80368058 = D_80368060;
                if (!first) {
                    osRecvMesg(&D_80368070.audioReplyMsgQ, (OSMesg *)&lastInfo, OS_MESG_BLOCK);
                    func_80267F88(lastInfo);
                }
                first = 0;
                if (D_8036772A != 0) {
                    func_802613C8();
                }
                if (D_80367728 != 0) {
                    func_80261068();
                }
                if (D_80367729 != 0) {
                    func_80261284();
                }
                if (D_80367730 == 0) {
                    func_802611F0();
                }
                if (D_8036772C != 0) {
                    func_80261528();
                }
                break;
            case 4:
                break;
            case 10:
                done = 1;
                break;
            case 6:
                func_8029A7E4("No samples left\n");
                break;
        }
    }
    alClose(&D_80368070.g);
}

void func_80267CDC(UnkAudioInfo *info, UnkAudioInfo *lastInfo) {
    s16 *audioPtr;
    Acmd *cmdp;
    u32 samplesLeft;
    UnkScTask *t;

    samplesLeft = 0;
    func_802682A4();
    audioPtr = (s16 *)osVirtualToPhysical(info->data);
    if (lastInfo != NULL) {
        osAiSetNextBuffer(lastInfo->data, lastInfo->frameSamples << 2);
    }
    samplesLeft = osAiGetLength() >> 2;
    info->frameSamples = (D_8036A8BC - samplesLeft + 53) & ~0xF;
    if (info->frameSamples < D_8036A8B8) {
        info->frameSamples = D_8036A8B8;
    }
    cmdp = alAudioFrame(D_80368070.ACMDList[D_802F3AF8], &D_8036A8C4, audioPtr, info->frameSamples);
    if (D_8036A8C4 > 2750) {
        func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "cmdLen <= MAX_RSP_CMDS", "audio.c", 0x150);
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
        func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "osSendMesg(osScGetCmdQ(&sc), (OSMesg) t, OS_MESG_NOBLOCK)!=-1", "audio.c", 0x169);
    }
    D_802F3AF8 ^= 1;
}

void func_80267F88(UnkAudioInfo *info) {
    u32 samplesLeft;

    samplesLeft = osAiGetLength() >> 2;
    if (samplesLeft == 0 && D_802F3C04 == 0) {
        func_8029A7E4("audio: ai out of samples\n");
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
        func_8029A7E4("OH DEAR - No audio DMA buffers left\n");
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
            func_8029A7E4("Dma not done\n");
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
