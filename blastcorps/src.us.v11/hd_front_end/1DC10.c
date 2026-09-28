#include "common.h"

/* The EEPROM's PIF RAM, in hd_front_end's .bss (ultra_internal.h declares it). */
#define __osEepPifRam D_8021ABB0

/* conteepwrite.c's functions, with its statics. */
#define osEepromWrite func_80204C10
#define __osPackEepWriteData func_80204DC0
#define __osEepStatus func_80204ECC
/* conteepread.c's. */
#define osEepromRead func_802050F0
#define __osPackEepReadData func_802052E0

#include "src/libultra/io/conteepwrite.c"

#include "src/libultra/io/conteepread.c"
