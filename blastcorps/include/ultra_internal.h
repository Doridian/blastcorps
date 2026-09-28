#ifndef ULTRA_INTERNAL_H
#define ULTRA_INTERNAL_H

/*
 * The parts of libultra's private headers (piint.h, siint.h, osint.h) that
 * the SDK doesn't ship, after decompals/ultralib.  Blast Corps links an older
 * libultra than any ultralib builds, so some names differ: osPiRawStartDma
 * and osPiRawReadIo, for example, have no leading underscores yet.
 */
#include <PR/os_internal.h>
#include <PR/rcp.h>
#include <PR/R4300.h>

#define WAIT_ON_IOBUSY(stat)                                    \
    {                                                           \
        stat = IO_READ(PI_STATUS_REG);                          \
        while (stat & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) \
            stat = IO_READ(PI_STATUS_REG);                      \
    } (void)0

typedef struct {
    OSMesgQueue *messageQueue;
    OSMesg message;
} __OSEventState;

extern __OSEventState __osEventStateTab[];

/*
 * The RDB packet header as this libultra has it: a 2-bit type at the top of
 * the byte, where the 2.0I rdb.h's rdbPacket has 6 bits.
 */
typedef struct {
    u8 type : 2;
    u8 pad : 4;
    u8 length : 2;
    u8 buf[3];
} __OSRdbPacket;

typedef struct {
    unsigned int inst1;
    unsigned int inst2;
    unsigned int inst3;
    unsigned int inst4;
} __osExceptionVector;

extern __osExceptionVector __osExceptionPreamble[];

extern OSThread *__osRunningThread;
extern OSThread *__osActiveQueue;
extern void __osDispatchThread(void);
extern void __osDequeueThread(OSThread **queue, OSThread *t);
extern int __osAtomicDec(unsigned int *p);
extern u32 __osGetCause(void);
extern void __osSetSR(u32);
extern u32 __osGetSR(void);
extern u32 __osSetFpcCsr(u32);
extern s32 __osSiRawReadIo(u32, u32 *);
extern s32 __osSiRawWriteIo(u32, u32);
extern u32 __osFinalrom;

extern u32 __osProbeTLB(void *);
extern int __osSiDeviceBusy(void);

/*
 * Thread queues and the exception handler's scheduling entry points (osint.h).
 * __osThreadTail's struct is left incomplete: init/3590.c defines it along
 * with the variable.
 */
extern struct __osThreadTail __osThreadTail;
extern OSThread *__osRunQueue;
extern OSThread *__osFaultedThread;
extern void __osEnqueueAndYield(OSThread **);
extern void __osEnqueueThread(OSThread **, OSThread *);
extern OSThread *__osPopThread(OSThread **);
extern void __osCleanupThread(void);

/* Timers (osint.h). */
extern OSTimer *__osTimerList;
extern OSTimer __osBaseTimer;
extern OSTime __osCurrentTime;
extern u32 __osBaseCounter;
extern u32 __osViIntrCount;
extern u32 __osTimerCounter;
extern void __osSetTimerIntr(OSTime);
extern OSTime __osInsertTimer(OSTimer *);
extern void __osTimerInterrupt(void);
extern void __osTimerServicesInit(void);

/* The VI manager's double-buffered state (viint.h). */
#define VI_STATE_MODE_UPDATED 0x01
#define VI_STATE_XSCALE_UPDATED 0x02
#define VI_STATE_YSCALE_UPDATED 0x04
#define VI_STATE_CTRL_UPDATED 0x08
#define VI_STATE_BUFFER_UPDATED 0x10
#define VI_STATE_BLACK 0x20
#define VI_STATE_REPEATLINE 0x40
#define VI_STATE_FADE 0x80

#define VI_SCALE_MASK 0xFFF
#define VI_2_10_FPART_MASK 0x3FF
#define VI_SUBPIXEL_SH 0x10

typedef struct {
    /* 0x0 */ f32 factor;
    /* 0x4 */ u16 offset;
    /* 0x8 */ u32 scale;
} __OSViScale;

typedef struct {
    /* 0x00 */ u16 state;
    /* 0x02 */ u16 retraceCount;
    /* 0x04 */ void *framep;
    /* 0x08 */ OSViMode *modep;
    /* 0x0C */ u32 control;
    /* 0x10 */ OSMesgQueue *msgq;
    /* 0x14 */ OSMesg msg;
    /* 0x18 */ __OSViScale x;
    /* 0x24 */ __OSViScale y;
} __OSViContext;

extern __OSViContext *__osViCurr;
extern __OSViContext *__osViNext;
extern void __osViSwapContext(void);
extern __OSViContext *__osViGetCurrentContext(void);

/* Controllers over the SI (controller.h). */
#define CHNL_ERR(format) (((format).rxsize & CHNL_ERR_MASK) >> 4)

typedef struct {
    /* 0x00 */ u32 ramarray[15];
    /* 0x3C */ u32 pifstatus;
} OSPifRam;

typedef struct {
    /* 0x0 */ u8 dummy;
    /* 0x1 */ u8 txsize;
    /* 0x2 */ u8 rxsize;
    /* 0x3 */ u8 cmd;
    /* 0x4 */ u8 typeh;
    /* 0x5 */ u8 typel;
    /* 0x6 */ u8 status;
    /* 0x7 */ u8 dummy1;
} __OSContRequesFormat;

typedef struct {
    /* 0x0 */ u8 dummy;
    /* 0x1 */ u8 txsize;
    /* 0x2 */ u8 rxsize;
    /* 0x3 */ u8 cmd;
    /* 0x4 */ u16 button;
    /* 0x6 */ s8 stick_x;
    /* 0x7 */ s8 stick_y;
} __OSContReadFormat;

#define CONT_CMD_REQUEST_STATUS 0
#define CONT_CMD_READ_BUTTON 1
#define CONT_CMD_READ_BUTTON_TX 1
#define CONT_CMD_READ_BUTTON_RX 4
#define CONT_CMD_RESET 0xFF
#define CONT_CMD_RESET_TX 1
#define CONT_CMD_RESET_RX 3
#define CONT_CMD_NOP 0xFF
#define CONT_CMD_END 0xFE
#define CONT_CMD_EXE 1

extern OSPifRam __osContPifRam;
extern u8 __osContLastCmd;
extern u8 __osMaxControllers;
extern void __osContGetInitData(u8 *, OSContStatus *);
extern void __osPackRequestData(u8);
extern void __osSiGetAccess(void);
extern void __osSiRelAccess(void);
extern void __osSiCreateAccessQueue(void);

/* Device managers and clocks (piint.h, and aisetfreq.c's own extern). */
extern OSDevMgr __osPiDevMgr;
extern OSMesgQueue *osPiGetCmdQueue(void);
extern u32 __osPiAccessQueueEnabled;
extern OSMesgQueue __osPiAccessQueue;
extern void __osPiCreateAccessQueue(void);
extern void __osDevMgrMain(void *);
extern s32 osViClock;
extern s32 __osAiDeviceBusy(void);

/* libc's printf engine (xstdio.h), with char spelled unsigned char as libultra was built. */
#include <stdarg.h>
#include <string.h>

typedef double ldouble; /* IDO has no long double */

typedef struct {
    /* 0x00 */ union {
        /* 0x0 */ long long ll;
        /* 0x0 */ ldouble ld;
    } v;
    /* 0x08 */ unsigned char *s;
    /* 0x0C */ int n0;
    /* 0x10 */ int nz0;
    /* 0x14 */ int n1;
    /* 0x18 */ int nz1;
    /* 0x1C */ int n2;
    /* 0x20 */ int nz2;
    /* 0x24 */ int prec;
    /* 0x28 */ int width;
    /* 0x2C */ size_t nchar;
    /* 0x30 */ unsigned int flags;
    /* 0x34 */ unsigned char qual;
} _Pft;

#define FLAGS_SPACE 1
#define FLAGS_PLUS 2
#define FLAGS_MINUS 4
#define FLAGS_HASH 8
#define FLAGS_ZERO 16

extern int _Printf(void *pfn(void *, const char *, size_t), void *arg, const char *fmt, va_list ap);
extern void _Litob(_Pft *px, unsigned char code);
extern void _Ldtob(_Pft *px, unsigned char code);

/* The graphics utilities' private header (gu/guint.h). */
typedef union {
    struct {
        unsigned int hi;
        unsigned int lo;
    } word;
    double d;
} du;

typedef union {
    unsigned int i;
    float f;
} fu;

typedef float Matrix[4][4];

#define ROUND(d) (int)(((d) >= 0.0) ? ((d) + 0.5) : ((d) - 0.5))
#define ABS(d) ((d) > 0) ? (d) : -(d)

extern float __libm_qnan_f;

/* This libultra's cosine is only fcos (cosf.c's own name); 2.0I adds cosf. */
extern float fcos(float);
#define cosf fcos

#endif
