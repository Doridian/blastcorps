#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/53220/func_802979E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/53220/func_80297ECC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/53220/func_80297EF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/53220/func_80297F74.s")

/* hd_code's copy of Rare's gzip inflate, for hd_front_end.  Its tables are
 * in hd_code's .data, which isn't split yet. */
#include "gzip.h"

extern uch border[];
extern ush cplens[];
extern uch cplext[];
extern ush cpdist[];
extern uch cpdext[];

#include "src/gzip_inflate.inc.c"
