/* libultra libc/xprintf.c: the functions.  Its data, if any, is defined by the includer. */
/*
 * Older than ultralib's _Printf: the scan for '%' runs while the (unsigned)
 * character is > 0, as in the libultra SM64 links.  The includer provides
 * spaces, zeroes, fchar and fbit, the "hlL" string as PRINTF_QUALS, and
 * _Putfld (its switch is a jump table, so it is still asm).
 */
#include "common.h"
#include "ultra_internal.h"

#define isdigit(x) ((x >= '0' && x <= '9'))

#define ATOI(dst, src)                   \
    for (dst = 0; isdigit(*src); ++src) { \
        if (dst < 999)                   \
            dst = dst * 10 + *src - '0'; \
    }

#define PUT(s, n)                                \
    if (0 < (n)) {                               \
        if ((arg = (*pfn)(arg, s, n)) != NULL)   \
            x.nchar += (n);                      \
        else                                     \
            return x.nchar;                      \
    }

#define PAD(i, n, j, s, cond)                                 \
    if ((cond) && 0 < (n))                                    \
        for (i = (n); 0 < i; i -= j) {                        \
            if ((unsigned int)i > 32)                         \
                j = 32;                                       \
            else                                              \
                j = i;                                        \
            PUT(s, j);                                        \
        }

#ifndef PRINTF_QUALS
#define PRINTF_QUALS "hlL"
#endif

void _Putfld(_Pft *px, va_list *pap, unsigned char code, unsigned char *ac);

int _Printf(void *pfn(void *, const char *, size_t), void *arg, const char *fmt, va_list ap) {
    _Pft x;
    const unsigned char *s;
    unsigned char c;
    const char *t;
    unsigned char ac[32];
    int i0, j0, i1, j1, i2, j2, i3, j3, i4, j4;

    x.nchar = 0;
    while (TRUE) {
        s = (const unsigned char *)fmt;
        while ((c = *s++) > 0) {
            if (c == '%') {
                s--;
                break;
            }
        }
        PUT(fmt, s - (const unsigned char *)fmt);
        if (c == 0) {
            return x.nchar;
        }
        fmt = (const char *)++s;
        x.flags = 0;
        for (; (t = strchr(fchar, *s)) != NULL; s++) {
            x.flags |= fbit[t - fchar];
        }
        if (*s == '*') {
            x.width = va_arg(ap, int);
            if (x.width < 0) {
                x.width = -x.width;
                x.flags |= FLAGS_MINUS;
            }
            s++;
        } else {
            ATOI(x.width, s);
        }
        if (*s != '.') {
            x.prec = -1;
        } else {
            s++;
            if (*s == '*') {
                x.prec = va_arg(ap, int);
                s++;
            } else {
                ATOI(x.prec, s);
            }
        }
        x.qual = strchr(PRINTF_QUALS, *s) != NULL ? *s++ : '\0';
        if (x.qual == 'l' && *s == 'l') {
            x.qual = 'L';
            s++;
        }
        _Putfld(&x, &ap, *s, ac);
        x.width -= x.n0 + x.nz0 + x.n1 + x.nz1 + x.n2 + x.nz2;
        PAD(j0, x.width, i0, spaces, !(x.flags & FLAGS_MINUS));
        PUT((char *)ac, x.n0);
        PAD(j1, x.nz0, i1, zeroes, 1);
        PUT((char *)x.s, x.n1);
        PAD(j2, x.nz1, i2, zeroes, 1);
        PUT((char *)&x.s[x.n1], x.n2);
        PAD(j3, x.nz2, i3, zeroes, 1);
        PAD(j4, x.width, i4, spaces, x.flags & FLAGS_MINUS);
        fmt = (const char *)s + 1;
    }
}
