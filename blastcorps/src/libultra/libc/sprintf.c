/* libultra libc/sprintf.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "ultra_internal.h"
#include <string.h>

static void *proutSprintf(void *s, const char *buf, size_t n);

int sprintf(char *s, const char *fmt, ...) {
    int ans;
    va_list ap;

    va_start(ap, fmt);
    ans = _Printf(proutSprintf, s, fmt, ap);
    if (ans >= 0) {
        s[ans] = 0;
    }
    return ans;
}

static void *proutSprintf(void *s, const char *buf, size_t n) {
    return (char *)memcpy(s, buf, n) + n;
}
