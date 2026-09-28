#ifndef COMMON_H
#define COMMON_H

#include <ultra64.h>

/*
 * The game was built against an older gbi.h than the 2.0I one here.  Where
 * the two build different display-list words, the older form is redefined.
 */

/* Fast3D 2.0D takes the perspective normalization as a command of its own
 * (0xB4, G_RDPHALF_1 in 2.0I); 2.0I moves it with G_MW_PERSPNORM. */
#undef gSPPerspNormalize
#define gSPPerspNormalize(pkt, s) gImmp1(pkt, G_RDPHALF_1, (s))

#endif
