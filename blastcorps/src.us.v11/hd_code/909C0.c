#include "common.h"

/* perspective.c's pi/180, in hd_code's .rodata (not split yet). */
extern f64 D_8030D9F0;
#define PERSPECTIVE_DTOR D_8030D9F0

#include "src/libultra/gu/perspective.c"
