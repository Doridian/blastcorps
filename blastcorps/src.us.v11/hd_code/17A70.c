#include "common.h"
#include "gzip.h"

/* hd_code's copy of Rare's gzip driver (see src/gzip_unzip.inc.c).  Its
 * message is in hd_code's .data, which isn't split yet. */

/* "kiunzip: unknown method %d -- get newer version of gzip\n" */

void func_8029A7E4(char *, ...);

#define GZIP_UNZIP          func_8025C230
#define GZIP_PRINTF         func_8029A7E4
#define GZIP_UNKNOWN_METHOD "kiunzip: unknown method %d -- get newer version of gzip\n"

#include "src/gzip_unzip.inc.c"
