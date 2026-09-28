#include "common.h"
#include "gzip.h"

int method = DEFLATED;
int exit_code = 0;

void func_80220714(const char *fmt, ...);

#define GZIP_UNZIP          func_80220360
#define GZIP_PRINTF         func_80220714
#define GZIP_UNKNOWN_METHOD "kiunzip: unknown method %d -- get newer version of gzip\n"

#include "src/gzip_unzip.inc.c"
