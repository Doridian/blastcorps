/*
 * libultra io/pimgr.c, older than any ultralib builds: no EPI DMA, no
 * __osPiTable or __osCurrentHandle, and no ramrom thread.  The includer
 * defines __osPiDevMgr and names the thread, stack and event queue.
 */
#include "common.h"
#include "ultra_internal.h"

void osCreatePiManager(OSPri pri, OSMesgQueue *cmdQ, OSMesg *cmdBuf, s32 cmdMsgCnt) {
    u32 savedMask;
    OSPri oldPri;
    OSPri myPri;

    if (__osPiDevMgr.active) {
        return;
    }
    osCreateMesgQueue(cmdQ, cmdBuf, cmdMsgCnt);
    osCreateMesgQueue(&piEventQueue, (OSMesg *)piEventBuf, 1);

    if (!__osPiAccessQueueEnabled) {
        __osPiCreateAccessQueue();
    }

    osSetEventMesg(OS_EVENT_PI, &piEventQueue, (OSMesg)0x22222222);
    oldPri = -1;
    myPri = osGetThreadPri(NULL);

    if (myPri < pri) {
        oldPri = myPri;
        osSetThreadPri(NULL, pri);
    }

    savedMask = __osDisableInt();
    __osPiDevMgr.active = 1;
    __osPiDevMgr.thread = &piThread;
    __osPiDevMgr.cmdQueue = cmdQ;
    __osPiDevMgr.evtQueue = &piEventQueue;
    __osPiDevMgr.acsQueue = &__osPiAccessQueue;
    __osPiDevMgr.dma = osPiRawStartDma;
    osCreateThread(&piThread, 0, __osDevMgrMain, &__osPiDevMgr, piThreadStack + PI_STACKSIZE, pri);
    osStartThread(&piThread);
    __osRestoreInt(savedMask);

    if (oldPri != -1) {
        osSetThreadPri(NULL, oldPri);
    }
}
