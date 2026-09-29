/*
 * libultra's libc for the game, on the host's.  The game's names are
 * renamed (port_game.h) so these don't interpose on the host libc.
 *
 * sprintf formats with the host's vsprintf: it has va_start, so BEPass
 * leaves it alone and the arguments are read as the native call passed
 * them.  The output is bytes, which need no swapping.
 *
 * The copies charge the CPU about what libultra's unrolled bcopy/bzero
 * take (half and a quarter of an instruction a byte): being host calls,
 * BEPass's instruction count doesn't see inside them.
 */
#include <stdarg.h>
#include "common.h"
#include "port.h"

typedef unsigned int port_size_t;
extern int vsprintf(char *, const char *, va_list);
extern void *memmove(void *, const void *, port_size_t);
extern void *memset(void *, int, port_size_t);

int n64_sprintf(char *buf, const char *fmt, ...) {
    va_list ap;
    int n;

    va_start(ap, fmt);
    n = vsprintf(buf, fmt, ap);
    va_end(ap);
    return n;
}

void n64_bcopy(const void *src, void *dst, int n) {
    host_cpu_charge(n / 2);
    memmove(dst, src, n);
}

void n64_bzero(void *p, int n) {
    host_cpu_charge(n / 4);
    memset(p, 0, n);
}

void *n64_memcpy(void *dst, const void *src, port_size_t n) {
    host_cpu_charge(n / 2);
    return memmove(dst, src, n);
}

port_size_t n64_strlen(const char *s) {
    const char *p = s;
    while (*p)
        p++;
    return p - s;
}

char *n64_strchr(const char *s, int c) {
    for (;; s++) {
        if (*s == (char)c)
            return (char *)s;
        if (*s == 0)
            return NULL;
    }
}
