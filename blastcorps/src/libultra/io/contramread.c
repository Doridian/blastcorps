/* libultra io/contramread.c: the functions.  Its data, if any, is defined by the includer. */
/*
 * Older than ultralib's 2.0I: each read first fills all 16 words of the PIF
 * RAM with 0xFF, a channel error is returned as it is, and the packer clears
 * the PIF RAM before building the command.
 */
#include "common.h"
#include "ultra_internal.h"

#define READFORMAT(ptr) ((__OSContRamReadFormat *)(ptr))

static void __osPackRamReadData(int channel, u16 address);

s32 __osContRamRead(OSMesgQueue *mq, int channel, u16 address, u8 *buffer) {
    s32 ret = 0;
    int i;
    u8 *ptr = (u8 *)&__osPfsPifRam;
    __OSContRamReadFormat ramreadformat;
    int retry = 2;

    __osSiGetAccess();
    __osContLastCmd = CONT_CMD_READ_PAK;
    __osPackRamReadData(channel, address);
    ret = __osSiRawStartDma(OS_WRITE, &__osPfsPifRam);
    osRecvMesg(mq, NULL, OS_MESG_BLOCK);

    do {
        for (i = 0; i < 16; i++) {
            ((u32 *)&__osPfsPifRam)[i] = 0xFF;
        }
        __osPfsPifRam.pifstatus = 0;
        ret = __osSiRawStartDma(OS_READ, &__osPfsPifRam);
        osRecvMesg(mq, NULL, OS_MESG_BLOCK);
        ptr = (u8 *)&__osPfsPifRam;

        if (channel != 0) {
            for (i = 0; i < channel; i++) {
                ptr++;
            }
        }

        ramreadformat = *READFORMAT(ptr);

        ret = CHNL_ERR(ramreadformat);
        if (ret == 0) {
            u8 c = __osContDataCrc((u8 *)&ramreadformat.data);
            if (c != ramreadformat.datacrc) {
                ret = __osPfsGetStatus(mq, channel);

                if (ret != 0) {
                    __osSiRelAccess();
                    return ret;
                }

                ret = PFS_ERR_CONTRFAIL;
            } else {
                for (i = 0; i < ARRLEN(ramreadformat.data); i++) {
                    *buffer++ = ramreadformat.data[i];
                }
            }
        }
    } while ((ret == PFS_ERR_CONTRFAIL) && retry-- >= 0);

    __osSiRelAccess();

    return ret;
}

static void __osPackRamReadData(int channel, u16 address) {
    u8 *ptr;
    __OSContRamReadFormat ramreadformat;
    int i;

    ptr = (u8 *)__osPfsPifRam.ramarray;
    for (i = 0; i < 16; i++) {
        ((u32 *)&__osPfsPifRam)[i] = 0;
    }
    __osPfsPifRam.pifstatus = CONT_CMD_EXE;
    ramreadformat.dummy = CONT_CMD_NOP;
    ramreadformat.txsize = CONT_CMD_READ_PAK_TX;
    ramreadformat.rxsize = CONT_CMD_READ_PAK_RX;
    ramreadformat.cmd = CONT_CMD_READ_PAK;
    ramreadformat.address = (address << 0x5) | __osContAddressCrc(address);
    ramreadformat.datacrc = CONT_CMD_NOP;

    for (i = 0; i < ARRLEN(ramreadformat.data); i++) {
        ramreadformat.data[i] = CONT_CMD_NOP;
    }

    if (channel != 0) {
        for (i = 0; i < channel; i++) {
            *ptr++ = CONT_CMD_REQUEST_STATUS;
        }
    }

    *(__OSContRamReadFormat *)ptr = ramreadformat;
    ptr += sizeof(__OSContRamReadFormat);
    ptr[0] = CONT_CMD_END;
}
