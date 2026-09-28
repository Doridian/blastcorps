#include "common.h"

#include "src/libultra/io/sptaskyielded.c"

/* sptask.c's static tmp_task, in hd_code's .bss. */
extern OSTask D_803FF200;
#define tmp_task D_803FF200

#include "src/libultra/io/sptask.c"

