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

#endif
