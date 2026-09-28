#include "common.h"
#include "gzip.h"

#define DEFLATED     8
#define ERROR        1

#define CONTINUATION 0x02
#define EXTRA_FIELD  0x04
#define ORIG_NAME    0x08
#define COMMENT      0x10

/* "kiunzip: unknown method %d -- get newer version of gzip\n" */
extern char D_802228D0[];

void func_80220714(const char *fmt, ...);

/* Inflate the gzip member at *src to *dst, advancing both past it.  heap is
 * where huft_build puts its tables. */
void func_80220360(uch **src, uch **dst, struct huft *heap) {
    inbuf = *src;
    window = *dst;
    huft_heap = heap;

    clear_bufs();

    if (*(inbuf + inptr) != 0x1F) {
        inptr += 1;
    }
    method = get_method();
    if (method >= 0) {
        inflate();
        *src += inptr;
        *dst += outcnt;
    }
}

/* gzip 1.2.4, gzip.c, with the magic check, the other formats and the file
 * name handling gone. */
int get_method(void) {
    uch flags;
    unsigned len;

    inptr += 2; /* magic */
    method = -1;
    header_bytes = 0;

    method = (int)get_byte();
    if (method != DEFLATED) {
        func_80220714(D_802228D0, method);
        exit_code = ERROR;
        return -1;
    }
    flags = (uch)get_byte();

    inptr += 6; /* time stamp, extra flags, OS type */

    if ((flags & CONTINUATION) != 0) {
        inptr += 2;
    }
    if ((flags & EXTRA_FIELD) != 0) {
        len = (unsigned)get_byte();
        len |= ((unsigned)get_byte()) << 8;
        inptr += len;
    }
    if ((flags & ORIG_NAME) != 0) {
        while (get_byte() != 0)
            ;
    }
    if ((flags & COMMENT) != 0) {
        while (get_byte() != 0)
            ;
    }
    header_bytes = inptr + 2 * sizeof(long);
    return method;
}

/* gzip 1.2.4, bits.c */
unsigned bi_reverse(unsigned code, int len) {
    register unsigned res = 0;
    do {
        res |= code & 1;
        code >>= 1, res <<= 1;
    } while (--len > 0);
    return res >> 1;
}

/* gzip 1.2.4, util.c */
void clear_bufs(void) {
    outcnt = 0;
    insize = inptr = 0;
    bytes_in = bytes_out = 0;
}
