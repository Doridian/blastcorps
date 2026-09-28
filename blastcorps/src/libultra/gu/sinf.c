/* libultra gu/sinf.c: the functions.  Its data, if any, is defined by the includer. */
/*
 * This libultra has only the name sinf (ultralib makes it __sinf with weak
 * fsin and sinf).  The includer provides the P, rpi, pihi, pilo and zero
 * constants.
 */
#include "common.h"
#include "ultra_internal.h"

float sinf(float x) {
    double dx, xsq, poly;
    double dn;
    int n;
    double result;
    int ix, xpt;

    ix = *(int *)&x;
    xpt = (ix >> 22);
    xpt &= 0x1ff;

    /* xpt is exponent(x) + 1 bit of mantissa */

    if (xpt < 0xff) {
        /* |x| < 1.5 */

        dx = x;

        if (xpt >= 0xe6) {
            /* |x| >= 2^(-12) */

            /* compute sin(x) with a standard polynomial approximation */

            xsq = dx * dx;

            poly = ((P[4].d * xsq + P[3].d) * xsq + P[2].d) * xsq + P[1].d;

            result = dx + (dx * xsq) * poly;

            return ((float)result);
        }

        return (x);
    }

    if (xpt < 0x136) {
        /* |x| < 2^28 */

        dx = x;

        /*  reduce argument to +/- pi/2  */

        dn = dx * rpi.d;

        n = ROUND(dn);
        dn = n;

        dx = dx - dn * pihi.d;
        dx = dx - dn * pilo.d; /* dx = x - n*pi */

        /* compute sin(dx) as before, negating result if n is odd
         */

        xsq = dx * dx;

        poly = ((P[4].d * xsq + P[3].d) * xsq + P[2].d) * xsq + P[1].d;

        result = dx + (dx * xsq) * poly;

        if ((n & 1) == 0) {
            return ((float)result);
        }

        return (-(float)result);
    }

    if (x != x) {
        /* x is a NaN; return a quiet NaN */
        return (__libm_qnan_f);
    }

    /* just give up and return 0.0 */

    return (zero.f);
}
