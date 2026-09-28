#include "common.h"

/* This libultra's osPfsInit and __osPfsGetStatus, both in its pfsinit.c. */
#define osPfsInit func_80203350
#define __osPfsGetStatus func_80203404
/* func_80203BF8 is pfsallocatefile.c's static __osClearPage. */
#define __osClearPage func_80203BF8

#include "src/libultra/io/pfschecker.c"

#include "src/libultra/io/pfsinit.c"

#include "src/libultra/io/pfsallocatefile.c"
