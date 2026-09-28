/* libultra gu/cosf.c: the functions.  Its data, if any, is defined by the includer. */
/*
 * This libultra has only the name fcos (ultralib makes it __cosf with weak
 * fcos and cosf).  The includer provides the P, rpi, pihi, pilo and zero
 * constants.
 */
#include "common.h"
#include "ultra_internal.h"

float fcos(float x) {
    float absx;
    double dx, xsq, poly;
    double dn;
    int n;
    double result;
    int ix, xpt;

    ix = *(int *)&x;
    xpt = (ix >> 22);
    xpt &= 0x1ff;

    /* xpt is exponent(x) + 1 bit of mantissa */

    if (xpt < 0x136) {
        /* |x| < 2^28 */

        /* use the standard algorithm from Cody and Waite, doing
           the computations in double precision
        */

        absx = ABS(x);

        dx = absx;

        dn = dx * rpi.d + 0.5;
        n = ROUND(dn);
        dn = n;

        dn -= 0.5;

        dx = dx - dn * pihi.d;
        dx = dx - dn * pilo.d; /* dx = x - (n - 0.5)*pi */

        xsq = dx * dx;

        poly = ((P[4].d * xsq + P[3].d) * xsq + P[2].d) * xsq + P[1].d;

        result = dx + (dx * xsq) * poly;

        /* negate result if n is odd */

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
