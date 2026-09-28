/* libultra libc/xprintf.c, with its data. */
/*
 * Older than ultralib's _Printf: the scan for '%' runs while the (unsigned)
 * character is > 0, as in the libultra SM64 links.
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

#define LDSIGN(x) (((unsigned short *)&(x))[0] & 0x8000)

static char spaces[] = "                                ";
static char zeroes[] = "00000000000000000000000000000000";

static void _Putfld(_Pft *px, va_list *pap, unsigned char code, unsigned char *ac);

int _Printf(void *pfn(void *, const char *, size_t), void *arg, const char *fmt, va_list ap) {
    _Pft x;
    const unsigned char *s;
    unsigned char c;
    const char *t;
    unsigned char ac[32];
    int i0, j0, i1, j1, i2, j2, i3, j3, i4, j4;
    static const char fchar[] = { ' ', '+', '-', '#', '0', '\0' };
    static const unsigned int fbit[] = { FLAGS_SPACE, FLAGS_PLUS, FLAGS_MINUS, FLAGS_HASH, FLAGS_ZERO, 0 };

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
        x.qual = strchr("hlL", *s) != NULL ? *s++ : '\0';
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

static void _Putfld(_Pft *px, va_list *pap, unsigned char code, unsigned char *ac) {
    px->n0 = px->nz0 = px->n1 = px->nz1 = px->n2 = px->nz2 = 0;

    switch (code) {
        case 'c':
            ac[px->n0++] = va_arg(*pap, int);
            break;
        case 'd':
        case 'i':
            if (px->qual == 'l') {
                px->v.ll = va_arg(*pap, long);
            } else if (px->qual == 'L') {
                px->v.ll = va_arg(*pap, long long);
            } else {
                px->v.ll = va_arg(*pap, int);
            }

            if (px->qual == 'h') {
                px->v.ll = (short)px->v.ll;
            }

            if (px->v.ll < 0) {
                ac[px->n0++] = '-';
            } else if (px->flags & FLAGS_PLUS) {
                ac[px->n0++] = '+';
            } else if (px->flags & FLAGS_SPACE) {
                ac[px->n0++] = ' ';
            }

            px->s = &ac[px->n0];

            _Litob(px, code);
            break;
        case 'x':
        case 'X':
        case 'u':
        case 'o':
            if (px->qual == 'l') {
                px->v.ll = va_arg(*pap, long);
            } else if (px->qual == 'L') {
                px->v.ll = va_arg(*pap, long long);
            } else {
                px->v.ll = va_arg(*pap, int);
            }

            if (px->qual == 'h') {
                px->v.ll = (unsigned short)px->v.ll;
            } else if (px->qual == 0) {
                px->v.ll = (unsigned int)px->v.ll;
            }

            if (px->flags & FLAGS_HASH) {
                ac[px->n0++] = '0';

                if (code == 'x' || code == 'X') {
                    ac[px->n0++] = code;
                }
            }

            px->s = &ac[px->n0];
            _Litob(px, code);
            break;
        case 'e':
        case 'f':
        case 'g':
        case 'E':
        case 'G':
            px->v.ld = px->qual == 'L' ? va_arg(*pap, ldouble) : va_arg(*pap, double);

            if (LDSIGN(px->v.ld)) {
                ac[px->n0++] = '-';
            } else if (px->flags & FLAGS_PLUS) {
                ac[px->n0++] = '+';
            } else if (px->flags & FLAGS_SPACE) {
                ac[px->n0++] = ' ';
            }

            px->s = &ac[px->n0];
            _Ldtob(px, code);
            break;
        case 'n':
            if (px->qual == 'h') {
                *va_arg(*pap, unsigned short *) = px->nchar;
            } else if (px->qual == 'l') {
                *va_arg(*pap, unsigned long *) = px->nchar;
            } else if (px->qual == 'L') {
                *va_arg(*pap, unsigned long long *) = px->nchar;
            } else {
                *va_arg(*pap, unsigned int *) = px->nchar;
            }
            break;
        case 'p':
            px->v.ll = (long)va_arg(*pap, void *);
            px->s = &ac[px->n0];
            _Litob(px, 'x');
            break;
        case 's':
            px->s = va_arg(*pap, unsigned char *);
            px->n1 = strlen((char *)px->s);

            if (px->prec >= 0 && px->prec < px->n1) {
                px->n1 = px->prec;
            }
            break;
        case '%':
            ac[px->n0++] = '%';
            break;
        default:
            ac[px->n0++] = code;
            break;
    }
}
