/* libultra debug/kdebugserver.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "ultra_internal.h"
#include <PR/rdb.h>

void u32_to_string(u32 i, u8 *str) {
    str[0] = (i >> 0x18) & 0xFF;
    str[1] = (i >> 0x10) & 0xFF;
    str[2] = (i >> 0x8) & 0xFF;
    str[3] = i & 0xFF;
}

u32 string_to_u32(u8 *str) {
    u32 i;

    i = (str[0] & 0xFF) << 0x18;
    i |= (str[1] & 0xFF) << 0x10;
    i |= (str[2] & 0xFF) << 0x8;
    i |= (str[3] & 0xFF);
    return i;
}

void send_packet(u8 *s, s32 n) {
    __OSRdbPacket packet;
    s32 i;

    packet.type = 2;
    packet.length = n;
    for (i = 0; i < n; i++) {
        packet.buf[i] = s[i];
    }
    *(vu32 *)RDB_BASE_REG = *(u32 *)&packet;
    while (!(__osGetCause() & CAUSE_IP6)) {
        ;
    }
    *(vu32 *)RDB_READ_INTR_REG = 0;
}

void send(u8 *buf, s32 len) {
    s32 i;
    s32 end;
    s32 rem;

    if (!__osRdbWriteOK) {
        while (!(__osGetCause() & CAUSE_IP6)) {
            ;
        }
        *(vu32 *)RDB_READ_INTR_REG = 0;
        __osRdbWriteOK = 1;
    }
    i = 0;
    rem = len % 3;
    end = len - rem;
    for (; i < end; i += 3) {
        send_packet(&buf[i], 3);
    }
    if (rem > 0) {
        send_packet(&buf[end], rem);
    }
}

void process_command_memory(void) {
    u32 addr;
    u32 length;

    addr = string_to_u32(&debugBuffer[1]);
    length = string_to_u32(&debugBuffer[5]);
    send((u8 *)addr, length);
}

void process_command_register(void) {
    send((u8 *)&__osThreadSave.context, sizeof(__OSThreadContext));
}

void kdebugserver(u32 msg) {
    u32 i;
    __OSRdbPacket packet;

    *(u32 *)&packet = msg;
    for (i = 0; i < packet.length; i++) {
        debugBuffer[numChars] = packet.buf[i];
        numChars++;
    }
    numCharsToReceive -= packet.length;
    switch (debugState) {
        case 0:
            switch (packet.buf[0]) {
                case 1:
                    debugState = 1;
                    numCharsToReceive = 9 - packet.length;
                    break;
                case 2:
                    process_command_register();
                    debugState = 0;
                    numChars = 0;
                    numCharsToReceive = 0;
                    break;
                default:
                    debugState = 0;
                    numChars = 0;
                    numCharsToReceive = 0;
                    break;
            }
            break;
        case 1:
            if (numCharsToReceive <= 0) {
                if (debugBuffer[0] == 1) {
                    process_command_memory();
                    debugState = 0;
                    numChars = 0;
                    numCharsToReceive = 0;
                } else {
                    debugState = 0;
                    numChars = 0;
                    numCharsToReceive = 0;
                }
            }
            break;
        default:
            debugState = 0;
            numChars = 0;
            numCharsToReceive = 0;
            break;
    }
}
