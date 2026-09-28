/* libultra os/initialize.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "ultra_internal.h"

void osInitialize(void) {
    u32 pifdata;
    u32 clock = 0;

    __osFinalrom = TRUE;
    __osSetSR(__osGetSR() | SR_CU1);
    __osSetFpcCsr(FPCSR_FS | FPCSR_EV);
    while (__osSiRawReadIo(PIF_RAM_END - 3, &pifdata)) {
        ;
    }
    while (__osSiRawWriteIo(PIF_RAM_END - 3, pifdata | 8)) {
        ;
    }
    *(__osExceptionVector *)UT_VEC = *__osExceptionPreamble;
    *(__osExceptionVector *)XUT_VEC = *__osExceptionPreamble;
    *(__osExceptionVector *)ECC_VEC = *__osExceptionPreamble;
    *(__osExceptionVector *)E_VEC = *__osExceptionPreamble;
    osWritebackDCache((void *)UT_VEC, E_VEC - UT_VEC + sizeof(__osExceptionVector));
    osInvalICache((void *)UT_VEC, E_VEC - UT_VEC + sizeof(__osExceptionVector));
    osMapTLBRdb();
    osPiRawReadIo(4, &clock);
    clock &= ~0xf;
    if (clock != 0) {
        osClockRate = clock;
    }
    osClockRate = osClockRate * 3 / 4;
    if (osResetType == 0) {
        bzero(osAppNMIBuffer, OS_APP_NMI_BUFSIZE);
    }
}
