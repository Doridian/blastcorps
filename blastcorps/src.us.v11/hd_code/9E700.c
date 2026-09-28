#include "common.h"
#include "ultra_internal.h"

/* xlitob.c's digit strings, in hd_code's .data (not split yet). */
extern unsigned char D_80307B50[];
extern unsigned char D_80307B64[];
#define ldigs D_80307B50
#define udigs D_80307B64

#include "src/libultra/libc/xlitob.c"

/* xldtob.c's constants, in hd_code's .rodata (not split yet). */
extern const ldouble D_8030E2F0[];
extern unsigned char D_8030E338[];
extern unsigned char D_8030E33C[];
extern unsigned char D_8030E340[];
extern const f64 D_8030E348;
#define pows D_8030E2F0
#define LDTOB_NAN D_8030E338
#define LDTOB_INF D_8030E33C
#define LDTOB_ZERO D_8030E340
#define LDTOB_1E8 D_8030E348

/* _Ldunscale and _Genld are xldtob.c's static _Ldunscale and _Genld. */
#include "src/libultra/libc/xldtob.c"

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/9E700/alSeqGetLoc.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/9E700/alSeqSetLoc.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/9E700/alSeqGetTicks.s")

void func_802E3FD0(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/9E700/func_802E3FD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/9E700/alSeqNextEvent.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/9E700/alSeqNewMarker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/9E700/alSeqSecToTicks.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/9E700/alSeqTicksToSec.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/9E700/__alSeqNextDelta.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/9E700/func_802E4458.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/9E700/func_802E44A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/9E700/alSeqNew.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/9E700/alSynSetPriority.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/9E700/alFilterNew.s")
