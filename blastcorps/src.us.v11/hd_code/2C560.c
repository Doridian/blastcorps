#include "common.h"

typedef struct {
    /* 0x0 */ u16 unk0[2];
} UnkStruct_802FA8A0;

typedef struct {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ u8 pad2[2];
    /* 0x4 */ u8 *unk4;
    /* 0x8 */ u8 unk8;
    /* 0x9 */ u8 unk9;
    /* 0xA */ u8 unkA;
    /* 0xB */ u8 unkB;
} UnkStruct_802FA280; /* size = 0xC */

/* The game's variant of the libultra sample scheduler (sched.h). */
typedef struct {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ OSMesgQueue *unk4;
    /* 0x8 */ u32 unk8;
} UnkStruct_SchedTask50;

typedef struct UnkSchedTask {
    /* 0x00 */ struct UnkSchedTask *next;
    /* 0x04 */ s32 state;
    /* 0x08 */ u32 flags;
    /* 0x0C */ void *framebuffer;
    /* 0x10 */ OSTask list;
    /* 0x50 */ UnkStruct_SchedTask50 *unk50;
    /* 0x54 */ OSMesgQueue *msgQ;
    /* 0x58 */ OSMesg msg;
} UnkSchedTask;

typedef struct UnkSchedClient {
    /* 0x0 */ struct UnkSchedClient *next;
    /* 0x4 */ OSMesgQueue *msgQ;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
} UnkSchedClient;

typedef struct {
    /* 0x000 */ OSMesgQueue interruptQ;
    /* 0x018 */ OSMesg intBuf[16];
    /* 0x058 */ OSMesgQueue cmdQ;
    /* 0x070 */ OSMesg cmdMsgBuf[16];
    /* 0x0B0 */ OSThread thread;
    /* 0x260 */ UnkSchedClient *clientList;
    /* 0x264 */ UnkSchedTask *audioListHead;
    /* 0x268 */ UnkSchedTask *gfxListHead;
    /* 0x26C */ UnkSchedTask *audioListTail;
    /* 0x270 */ UnkSchedTask *gfxListTail;
    /* 0x274 */ UnkSchedTask *curRSPTask;
    /* 0x278 */ UnkSchedTask *curRDPTask;
    /* 0x27C */ s32 unk27C;
    /* 0x280 */ s32 unk280;
    /* 0x284 */ u32 unk284;
    /* 0x288 */ OSTime unk288;
    /* 0x290 */ OSTime unk290;
} UnkSched;

typedef struct {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ s32 unk8;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u16 unk10;
    /* 0x12 */ u8 pad12[0xA];
} UnkStruct_802F8BDC; /* size = 0x1C */

/* Element type of the arrays D_8036BB10 points at. */
typedef struct {
    /* 0x00 */ u16 unk0;
    /* 0x02 */ u8 pad2[0xA];
    /* 0x0C */ u8 *unkC;
    /* 0x10 */ u16 *unk10;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[5];
    /* 0x1A */ s8 unk1A;
} UnkStruct_8036BB10; /* size = 0x1C */

typedef struct {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 pad5;
    /* 0x06 */ u8 unk6[0x26];
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ u8 unk2D;
    /* 0x2E */ s8 unk2E;
    /* 0x2F */ u8 pad2F;
} UnkStruct_802F49F4; /* size = 0x30 */

typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ u16 unk2;
} UnkStruct_8026F644;

typedef struct {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
} UnkStruct_8026FBB0; /* size = 0x6 */

typedef struct {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 unk7;
    /* 0x08 */ Vtx unk8[2][4];
} UnkStruct_8036BED8; /* size = 0x88 */

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ char unk1[0xF];
    /* 0x10 */ s32 unk10;
} UnkStruct_802F9934; /* size = 0x14 */

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x02 */ s16 unk2[16];
} UnkStruct_802F48D0; /* size = 0x22 */

typedef struct {
    /* 0x00 */ u8 unk0[0x88];
    /* 0x88 */ u8 unk88[0x78];
} UnkStruct_80364AF0; /* size = 0x100 */

extern OSViMode D_80306E70[];
extern u8 D_802FA270;
extern s32 D_80358060;
/*
 * This file's own .bss.  The functions using these only match with them
 * defined here (a u64's halves share one lui), but until .bss is split the
 * addresses still come from the absolute symbols in undefined_syms_auto.
 */
OSTime D_8036BEF0;
OSTime D_8036BEF8;
OSTime D_8036BF00;
extern s32 D_8036BF10;
extern s32 D_8036BF14;
extern s32 D_8036BF18;
extern struct UnkSchedTask *D_8036BF1C;
extern u32 D_8036BF20;
extern u32 D_8036BF24;
extern u32 D_8036BF2C;
OSTime D_8036BF38;
OSTime D_8036BF40;
OSTime D_8036BF48;
OSTime D_8036BF50;
extern OSTimer D_8036BF78;
extern s32 D_8036BFBC;
extern UnkStruct_8036BB10 *D_8036BB10;
extern u8 D_802E8BD0;
extern u64 D_80364A90;

void func_8029A7E4(char *, ...);
void osCreateViManager(s32);
void func_80270F7C(void *);
void func_80271C24(UnkSched *, UnkSchedTask *);
void func_80271CE4(UnkSched *, s32);
void func_80271E88(UnkSched *);
s32 func_80271A84(UnkSched *, UnkSchedTask *);
s32 func_80271F48(OSMesgQueue *, OSMesg, s32);

void func_80270D20(UnkSched *sc, void *stack, OSPri priority, u8 mode, u8 numFields) {
    sc->audioListTail = (UnkSchedTask *) &sc->audioListHead;
    sc->gfxListTail = (UnkSchedTask *) &sc->gfxListHead;
    D_8036BF10 = 0;
    D_8036BF1C = NULL;
    osCreateMesgQueue(&sc->interruptQ, sc->intBuf, 16);
    osCreateMesgQueue(&sc->cmdQ, sc->cmdMsgBuf, 16);
    osCreateViManager(0xFE);
    osViSetMode(&D_80306E70[mode]);
    osViBlack(TRUE);
    osSetEventMesg(OS_EVENT_SP, &sc->interruptQ, (OSMesg) 0x29B);
    osSetEventMesg(OS_EVENT_DP, &sc->interruptQ, (OSMesg) 0x29C);
    osSetEventMesg(OS_EVENT_PRENMI, &sc->interruptQ, (OSMesg) 0x29D);
    osSetEventMesg(OS_EVENT_FAULT, &sc->interruptQ, (OSMesg) 0x2A0);
    osViSetEvent(&sc->interruptQ, (OSMesg) 0x29A, numFields);
    osCreateThread(&sc->thread, 5, func_80270F7C, sc, stack, priority);
    osStartThread(&sc->thread);
}

void func_80270E50(UnkSched *sc, UnkSchedClient *c, OSMesgQueue *msgQ, s32 arg3, s32 arg4) {
    OSIntMask mask;

    mask = osSetIntMask(OS_IM_NONE);
    c->msgQ = msgQ;
    c->next = sc->clientList;
    sc->clientList = c;
    c->unk8 = arg3;
    c->unkC = arg4;
    osSetIntMask(mask);
}

void osScRemoveClient(UnkSched *sc, UnkSchedClient *c) {
    UnkSchedClient *client;
    UnkSchedClient *prev;
    OSIntMask mask;

    client = sc->clientList;
    prev = NULL;
    mask = osSetIntMask(OS_IM_NONE);
    while (client != NULL) {
        if (client == c) {
            if (prev != NULL) {
                prev->next = c->next;
            } else {
                sc->clientList = c->next;
            }
            break;
        }
        prev = client;
        client = client->next;
    }
    osSetIntMask(mask);
}

OSMesgQueue *func_80270F74(UnkSched *sc) {
    return &sc->cmdQ;
}

extern u32 D_8036BFB8;
extern s32 D_8036BF08;
extern s32 D_8036BF0C;
extern OSMesgQueue *D_8036BF90;
extern OSMesg D_8036BF94;
u32 func_802A1320(void);
void func_802712B4(UnkSched *, UnkSchedTask *);
void func_802712FC(UnkSched *);
void func_80271358(UnkSched *);
void func_802715DC(UnkSched *);
void func_80271904(UnkSched *);

void func_80270F7C(void *arg) {
    OSMesg msg;
    UnkSched *sc;
    UnkSchedClient *client;

    sc = arg;
    for (;;) {
        osRecvMesg(&sc->interruptQ, &msg, OS_MESG_BLOCK);
        if (!(func_802A1320() & 0x1000)) {
            for (client = sc->clientList; client != NULL; client = client->next) {
                osSendMesg(client->msgQ, (OSMesg) 0x29D, OS_MESG_NOBLOCK);
            }
            D_8036BF10 = 1;
            osViBlack(TRUE);
            func_8029A7E4("GO %x\n", osDpGetStatus());
            osDpSetStatus(DPC_CLR_FREEZE);
            func_8029A7E4("current=%x start=%x end=%x dpstat=%x spstat=%x\n", IO_READ(DPC_CURRENT_REG),
                          IO_READ(DPC_START_REG), IO_READ(DPC_END_REG), IO_READ(DPC_STATUS_REG),
                          IO_READ(SP_STATUS_REG));
            func_8029A7E4("GO %x\n", osDpGetStatus());
            for (;;) {
            }
        }
        switch ((s32) msg) {
            case 0x29A:
                if (++D_8036BFB8 % 480 == 0) {
                    D_8036BEF8 = D_8036BF00;
                    D_8036BF08 = D_8036BF0C;
                }
                func_80271358(sc);
                break;
            case 0x29E:
                func_802712FC(sc);
                break;
            case 0x29B:
                func_802715DC(sc);
                break;
            case 0x29C:
                func_80271904(sc);
                break;
            case 0x29F:
                osSendMesg(D_8036BF90, D_8036BF94, OS_MESG_BLOCK);
                break;
            case 0x29D:
                for (client = sc->clientList; client != NULL; client = client->next) {
                    osSendMesg(client->msgQ, (OSMesg) 0x29D, OS_MESG_NOBLOCK);
                }
                D_8036BF10 = 1;
                osViBlack(TRUE);
                func_8029A7E4("%x\n", osDpGetStatus());
                osDpSetStatus(DPC_CLR_FREEZE);
                func_8029A7E4("current=%x start=%x end=%x dpstat=%x spstat=%x\n", IO_READ(DPC_CURRENT_REG),
                              IO_READ(DPC_START_REG), IO_READ(DPC_END_REG), IO_READ(DPC_STATUS_REG),
                              IO_READ(SP_STATUS_REG));
                func_8029A7E4("%x\n", osDpGetStatus());
                for (;;) {
                }
            case 0x2A0:
                func_8029A7E4(" *** CPU FAULT *** - UNFREEZING RDP?\n");
                while (osViGetCurrentFramebuffer() != osViGetNextFramebuffer()) {
                }
                osDpSetStatus(DPC_CLR_FREEZE);
                for (;;) {
                }
            default:
                func_802712B4(sc, (UnkSchedTask *) msg);
                break;
        }
    }
}

void func_802712B4(UnkSched *sc, UnkSchedTask *t) {
    func_80271C24(sc, t);
    if (sc->curRSPTask == NULL) {
        func_80271CE4(sc, 1);
    }
}

void func_802712FC(UnkSched *sc) {
    if (sc->curRSPTask != NULL) {
        func_80271E88(sc);
    } else {
        D_8036BF00 = 0;
        func_80271CE4(sc, 0);
    }
}

void func_80271358(UnkSched *sc) {
    UnkSchedTask *t;
    UnkSchedClient *client;
    s32 i;
    s32 count;

    sc->unk284++;
    if (D_802E8BD0 == 0) {
        sc->unk280++;
    }
    D_8036BF38 = osGetTime();
    if (D_8036BF1C != NULL) {
        osViSwapBuffer(D_8036BF1C->framebuffer);
        D_8036BF18 = D_8036BF14;
        D_8036BF14 = sc->unk284 + 1;
        osDpSetStatus(DPC_SET_FREEZE);
        if (D_8036BF1C->msgQ != NULL) {
            func_80271F48(D_8036BF1C->msgQ, D_8036BF1C->msg, OS_MESG_NOBLOCK);
        }
        D_8036BF1C = NULL;
    } else if (osViGetCurrentFramebuffer() == osViGetNextFramebuffer() && (osDpGetStatus() & DPC_STATUS_FREEZE)) {
        sc->unk288 = osGetTime();
        osDpSetStatus(DPC_CLR_FREEZE);
    }
    count = sc->cmdQ.validCount;
    for (i = 0; i < count; i++) {
        if (osRecvMesg(&sc->cmdQ, (OSMesg *) &t, OS_MESG_NOBLOCK) == -1) {
            func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "osRecvMesg(&sc->cmdQ, (OSMesg *)&rspTask, OS_MESG_NOBLOCK) != -1", "sched.c", 0x1BD);
        }
        if (sc->unk284 % t->unk50->unk8 == 0) {
            func_80271C24(sc, t);
        } else {
            osSendMesg(&sc->cmdQ, t, OS_MESG_NOBLOCK);
        }
    }
    if (sc->audioListHead != NULL && !(sc->unk284 & 1)) {
        osSetTimer(&D_8036BF78, 280000, 0, sc->audioListHead->unk50->unk4, (OSMesg) 5);
    }
    for (client = sc->clientList; client != NULL; client = client->next) {
        if (client->unkC == 3) {
            osSendMesg(client->msgQ, (OSMesg) 0x29A, OS_MESG_NOBLOCK);
        }
    }
}

void func_802715DC(UnkSched *sc) {
    UnkSchedTask *t;
    OSTime time;

    if (sc->curRSPTask == NULL) {
        func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "sc->curRSPTask", "sched.c", 0x1F2);
    }
    t = sc->curRSPTask;
    sc->curRSPTask = NULL;
    if (t->state == 3) {
        D_8036BF00 = osGetTime() - D_8036BEF0;
        if (D_8036BF00 > 0x86470) {
            func_8029A7E4("Silly yield time of %llu ticks\n", D_8036BF00);
        }
        if (D_8036BF00 > D_8036BEF8) {
            D_8036BEF8 = D_8036BF00;
        }
        if (!osSpTaskYielded(&t->list)) {
            t->state = 2;
            t->flags |= 4;
            func_80271A84(sc, t);
        }
        if (sc->audioListHead == NULL) {
            func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "sc->audioListHead", "sched.c", 0x21A);
        }
        if (sc->audioListHead == NULL) {
            func_8029A7E4("Yield took %llu, max %llu\n", D_8036BF00, D_8036BEF8);
        }
        func_80271CE4(sc, 0);
        return;
    }
    if (t->flags & 0x40) {
        time = osGetTime();
        D_8036BF24 = (time - sc->unk290) / 7825;
        D_802FA270 = 1;
    } else if (t->list.t.type == M_AUDTASK) {
        D_8036BF50 = osGetTime();
        D_8036BF40 = D_8036BF48;
    }
    t->state = 2;
    t->flags |= 4;
    if (sc->curRSPTask != NULL) {
        func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "sc->curRSPTask==0", "sched.c", 0x230);
    }
    if (func_80271A84(sc, t)) {
        if (sc->gfxListHead != NULL && sc->gfxListHead->flags != 0x47) {
            func_80271CE4(sc, 1);
        }
    }
}

void func_80271904(UnkSched *sc) {
    UnkSchedTask *t;
    s32 pad;
    OSTime time;

    if (sc->curRDPTask == NULL) {
        func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "sc->curRDPTask", "sched.c", 0x24A);
    }
    t = sc->curRDPTask;
    sc->curRDPTask = NULL;
    t->flags |= 8;
    if (sc->unk284 != D_8036BF14 || (D_80364A90 & 0xC9FD0FE79BFF80B0)) {
        D_8036BF1C = NULL;
        osViSwapBuffer(t->framebuffer);
        D_8036BF18 = D_8036BF14;
        D_8036BF14 = sc->unk284 + 1;
        osDpSetStatus(DPC_SET_FREEZE);
    } else {
        D_8036BF1C = t;
    }
    time = osGetTime();
    D_8036BF20 = (time - sc->unk288) / 7825;
    if (D_80358060 == 3) {
        osViBlack(FALSE);
    }
    func_80271A84(sc, t);
}

s32 func_80271A84(UnkSched *sc, UnkSchedTask *t) {
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    sp20 = t->flags & 3;
    sp1C = (t->flags >> 2) & 3;
    sp18 = t->list.t.type;
    if (!(t->flags & 0x40)) {
        sp20 &= 1;
        sp1C &= 1;
    }
    if (sp20 == sp1C) {
        if (sp18 == M_GFXTASK) {
            if (sc->gfxListHead == NULL) {
                func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "sc->gfxListHead", "sched.c", 0x27C);
            }
            sc->gfxListHead = sc->gfxListHead->next;
            if (sc->gfxListHead == NULL) {
                sc->gfxListTail = (UnkSchedTask *) &sc->gfxListHead;
            }
        }
        if (t->msgQ != NULL && (D_8036BF1C == NULL || sp18 != M_GFXTASK)) {
            if (t->flags & 0x40) {
                sp24 = func_80271F48(t->msgQ, t->msg, OS_MESG_NOBLOCK);
            } else {
                sp24 = osSendMesg(t->msgQ, t->msg, OS_MESG_NOBLOCK);
            }
            if (sp24 == -1) {
                func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "rv!=-1", "sched.c", 0x289);
            }
        }
        D_8036BFBC = 1;
    } else {
        D_8036BFBC = 0;
    }
    return D_8036BFBC;
}

void func_80271C24(UnkSched *sc, UnkSchedTask *t) {
    s32 type;

    type = t->list.t.type;
    if (type != M_AUDTASK && type != M_GFXTASK) {
        func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "(type == M_AUDTASK) || (type == M_GFXTASK)", "sched.c", 0x29C);
    }
    if (type == M_AUDTASK) {
        sc->audioListTail->next = t;
        sc->audioListTail = t;
    } else {
        sc->gfxListTail->next = t;
        sc->gfxListTail = t;
    }
    t->next = NULL;
    t->state = 2;
}

void func_80271CE4(UnkSched *sc, s32 arg1) {
    UnkSchedTask *t;
    OSTime time;

    if (sc->curRSPTask != NULL) {
        func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "!sc->curRSPTask", "sched.c", 0x2B8);
    }
    if (arg1 == 0) {
        t = sc->audioListHead;
        if (t == NULL) {
            func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "t", "sched.c", 0x2BD);
        }
        if (t == NULL) {
            return;
        }
        sc->audioListHead = sc->audioListHead->next;
        if (sc->audioListHead == NULL) {
            sc->audioListTail = (UnkSchedTask *) &sc->audioListHead;
        }
        D_8036BF48 = osGetTime();
    } else {
        t = sc->gfxListHead;
        if (D_802FA270 != 0) {
            sc->unk290 = osGetTime();
            time = osGetTime();
            D_8036BF2C = (time - D_8036BF38) / 7825;
            D_802FA270 = 0;
        }
    }
    t->state = 1;
    osSpTaskLoad(&t->list);
    osSpTaskStartGo(&t->list);
    sc->curRSPTask = t;
    if (t->flags & 0x40) {
        sc->curRDPTask = t;
    }
}

void func_80271E88(UnkSched *sc) {
    if (sc->curRSPTask->list.t.type == M_AUDTASK) {
        func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "sc->curRSPTask->list.t.type != M_AUDTASK", "sched.c", 0x2DF);
    }
    if (sc->curRSPTask->list.t.type == M_GFXTASK) {
        if (sc->curRSPTask->state == 3) {
            func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "sc->curRSPTask->state != RSP_STATE_SUSPENDED", "sched.c", 0x2E3);
        }
        sc->curRSPTask->state = 3;
        D_8036BEF0 = osGetTime();
        osSpTaskYield();
    }
}

s32 func_80271F48(OSMesgQueue *mq, OSMesg msg, s32 flag) {
    OSTime sp28;
    OSTime sp20;
    s32 sp1C;

    sp28 = D_8036BF38 + 391250 - osGetTime();
    sp20 = osGetTime();
    sp1C = 0;
    osSendMesg(mq, msg, flag);
}
