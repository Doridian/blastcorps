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

/* The controller pak file system (controller.h and os_pfs.h, as 2.0I has them). */
#define ARRLEN(x) ((s32)(sizeof(x) / sizeof(x[0])))

#define CONT_CMD_READ_PAK 2
#define CONT_CMD_WRITE_PAK 3
#define CONT_CMD_REQUEST_STATUS_TX 1
#define CONT_CMD_REQUEST_STATUS_RX 3
#define CONT_CMD_READ_PAK_TX 3
#define CONT_CMD_READ_PAK_RX 33
#define CONT_CMD_WRITE_PAK_TX 35
#define CONT_CMD_WRITE_PAK_RX 1

#define DIR_STATUS_EMPTY 0
#define DIR_STATUS_UNKNOWN 1
#define DIR_STATUS_OCCUPIED 2

#define CONT_ADDR_DETECT 0x8000
#define CONT_BLOCKS(x) ((x) / BLOCKSIZE)
#define CONT_BLOCK_DETECT CONT_BLOCKS(CONT_ADDR_DETECT)

#define PFS_INODE_SIZE_PER_PAGE 128
#define PFS_EOF 1
#define PFS_PAGE_NOT_EXIST 2
#define PFS_PAGE_NOT_USED 3
#define PFS_WRITTEN 2
#define DEF_DIR_PAGES 2
#define PFS_ID_0AREA 1
#define PFS_ID_1AREA 3
#define PFS_ID_2AREA 4
#define PFS_ID_3AREA 6
#define PFS_LABEL_AREA 7
#define PFS_BANK_LAPPED_BY 8
#define PFS_SECTOR_PER_BANK 32
#define PFS_INODE_DIST_MAP (PFS_BANK_LAPPED_BY * PFS_SECTOR_PER_BANK)
#define PFS_SECTOR_SIZE (PFS_INODE_SIZE_PER_PAGE / PFS_SECTOR_PER_BANK)

typedef struct {
    /* 0x0 */ u8 txsize;
    /* 0x1 */ u8 rxsize;
    /* 0x2 */ u8 cmd;
    /* 0x3 */ u8 typeh;
    /* 0x4 */ u8 typel;
    /* 0x5 */ u8 status;
} __OSContRequesFormatShort;

typedef struct {
    /* 0x00 */ u8 dummy;
    /* 0x01 */ u8 txsize;
    /* 0x02 */ u8 rxsize;
    /* 0x03 */ u8 cmd;
    /* 0x04 */ u16 address;
    /* 0x06 */ u8 data[BLOCKSIZE];
    /* 0x26 */ u8 datacrc;
} __OSContRamReadFormat;

typedef union {
    /* 0x0 */ struct {
        /* 0x0 */ u8 bank;
        /* 0x1 */ u8 page;
    } inode_t;
    /* 0x0 */ u16 ipage;
} __OSInodeUnit;

typedef struct {
    /* 0x00 */ u32 game_code;
    /* 0x04 */ u16 company_code;
    /* 0x06 */ __OSInodeUnit start_page;
    /* 0x08 */ u8 status;
    /* 0x09 */ s8 reserved;
    /* 0x0A */ u16 data_sum;
    /* 0x0C */ u8 ext_name[PFS_FILE_EXT_LEN];
    /* 0x10 */ u8 game_name[PFS_FILE_NAME_LEN];
} __OSDir;

typedef struct {
    /* 0x0 */ __OSInodeUnit inode_page[128];
} __OSInode;

typedef struct {
    /* 0x00 */ u32 repaired;
    /* 0x04 */ u32 random;
    /* 0x08 */ u64 serial_mid;
    /* 0x10 */ u64 serial_low;
    /* 0x18 */ u16 deviceid;
    /* 0x1A */ u8 banks;
    /* 0x1B */ u8 version;
    /* 0x1C */ u16 checksum;
    /* 0x1E */ u16 inverted_checksum;
} __OSPackId;

typedef struct {
    /* 0x000 */ __OSInode inode;
    /* 0x100 */ u8 bank;
    /* 0x101 */ u8 map[PFS_INODE_DIST_MAP];
} __OSInodeCache;

typedef struct {
    /* 0x0 */ u8 txsize;
    /* 0x1 */ u8 rxsize;
    /* 0x2 */ u8 cmd;
    /* 0x3 */ u8 address;
    /* 0x4 */ u8 data[EEPROM_BLOCK_SIZE];
} __OSContEepromFormat;

#define CONT_CMD_READ_EEPROM 4
#define CONT_CMD_WRITE_EEPROM 5
#define CONT_CMD_READ_EEPROM_TX 2
#define CONT_CMD_READ_EEPROM_RX 8
#define CONT_CMD_WRITE_EEPROM_TX 10
#define CONT_CMD_WRITE_EEPROM_RX 1

extern OSPifRam __osPfsPifRam;
extern OSPifRam __osEepPifRam;
extern OSTimer __osEepromTimer;
extern OSMesgQueue __osEepromTimerQ;
extern OSMesg __osEepromTimerMsg;
extern s32 __osEepStatus(OSMesgQueue *, OSContStatus *);

extern u16 __osSumcalc(u8 *ptr, int length);
extern s32 __osIdCheckSum(u16 *ptr, u16 *csum, u16 *icsum);
extern s32 __osRepairPackId(OSPfs *pfs, __OSPackId *badid, __OSPackId *newid);
extern s32 __osCheckPackId(OSPfs *pfs, __OSPackId *temp);
extern s32 __osGetId(OSPfs *pfs);
extern s32 __osCheckId(OSPfs *pfs);
extern s32 __osPfsRWInode(OSPfs *pfs, __OSInode *inode, u8 flag, u8 bank);
extern s32 __osPfsSelectBank(OSPfs *pfs);
extern s32 __osPfsDeclearPage(OSPfs *pfs, __OSInode *inode, int file_size_in_pages, int *first_page, u8 bank,
                              int *decleared, int *last_page);
extern s32 __osPfsReleasePages(OSPfs *pfs, __OSInode *inode, u8 start_page, u16 *sum, u8 bank,
                               __OSInodeUnit *last_page, int flag);
extern s32 __osBlockSum(OSPfs *pfs, u8 page_no, u16 *sum, u8 bank);
extern s32 __osContRamRead(OSMesgQueue *mq, int channel, u16 address, u8 *buffer);
extern s32 __osContRamWrite(OSMesgQueue *mq, int channel, u16 address, u8 *buffer, int force);
extern void __osPfsRequestData(u8 cmd);
extern void __osPfsGetInitData(u8 *pattern, OSContStatus *data);
extern u8 __osContAddressCrc(u16 addr);
extern u8 __osContDataCrc(u8 *data);
extern s32 __osPfsGetStatus(OSMesgQueue *queue, int channel);

#define ERRCK(fn) \
    ret = fn;     \
    if (ret != 0) \
    return ret

#define SELECT_BANK(pfs, bank) (pfs->activebank = (bank), __osPfsSelectBank((pfs)))

#define SET_ACTIVEBANK_TO_ZERO()           \
    if (pfs->activebank != 0) {            \
        pfs->activebank = 0;               \
        ERRCK(__osPfsSelectBank(pfs));     \
    } (void)0

#define PFS_CHECK_ID()                        \
    if (__osCheckId(pfs) == PFS_ERR_NEW_PACK) \
    return PFS_ERR_NEW_PACK

#define PFS_CHECK_STATUS()                    \
    if ((pfs->status & PFS_INITIALIZED) == 0) \
    return PFS_ERR_INVALID

#define PFS_GET_STATUS()                    \
    __osSiGetAccess();                      \
    ret = __osPfsGetStatus(queue, channel); \
    __osSiRelAccess();                      \
    if (ret != 0)                           \
    return ret

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
