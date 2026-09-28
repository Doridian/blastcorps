#include "common.h"

/*
 * The game's older gbi.h sends a texture rectangle's s/t with G_RDPHALF_2
 * and dsdx/dtdy with G_RDPHALF_CONT (see hd_code/17E10.c).
 */
#undef gSPTextureRectangle
#define gSPTextureRectangle(pkt, xl, yl, xh, yh, tile, s, t, dsdx, dtdy)    \
{                                                                           \
    Gfx *_g = (Gfx *)(pkt);                                                 \
                                                                            \
    _g->words.w0 = (_SHIFTL(G_TEXRECT, 24, 8) | _SHIFTL(xh, 12, 12) |       \
                    _SHIFTL(yh, 0, 12));                                    \
    _g->words.w1 = (_SHIFTL(tile, 24, 3) | _SHIFTL(xl, 12, 12) |            \
                    _SHIFTL(yl, 0, 12));                                    \
    gImmp1(pkt, G_RDPHALF_2, (_SHIFTL(s, 16, 16) | _SHIFTL(t, 0, 16)));     \
    gImmp1(pkt, G_RDPHALF_CONT, (_SHIFTL(dsdx, 16, 16) | _SHIFTL(dtdy, 0, 16))); \
}

/*
 * gen_symbols matched these to libultra's osViExtendVStart and its
 * __additional_scanline, but they are the game's own: D_8021AB80 holds a
 * 320x240 RGBA16 image that func_80200BE0 draws.
 */
extern u32 __additional_scanline;
extern u8 D_8021AB84;
extern u64 D_80364A90;

void func_80200714(u8);

void func_802006F0(void) {
    func_80200714(D_8021AB84);
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_front_end/196F0/func_80200714.s")

void osViExtendVStart(u32 value) {
    __additional_scanline = value;
}

Gfx *func_80200BE0(Gfx *arg0, s32 arg1, s32 *arg2) {
    Gfx *gfx = arg0;
    s32 x;
    s32 y;
    u8 alpha;

    gDPPipeSync(gfx++);
    gSPTexture(gfx++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gDPSetTexturePersp(gfx++, G_TP_NONE);
    if (D_80364A90 & 0x000C000000000000) {
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gDPSetRenderMode(gfx++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
        gDPSetCombineLERP(gfx++, TEXEL0, 0, PRIMITIVE_ALPHA, 0, 0, 0, 0, 1, TEXEL0, 0, PRIMITIVE_ALPHA, 0, 0, 0, 0,
                          1);
        switch (D_80364A90) {
            case 0x0004000000000000:
            case 0x0008000000000000:
                alpha = 0x60;
                break;
            default:
                alpha = 0xFF;
                break;
        }
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, alpha);
    } else {
        gDPSetCycleType(gfx++, G_CYC_COPY);
        gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
    }
    for (x = 0; x < 320; x += 64) {
        for (y = 0; y < 240; y += 16) {
            gDPLoadTextureTile(gfx++, __additional_scanline, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, 240, x, y, x + 63,
                               y + 15, 0, G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            if (D_80364A90 & 0x000C000000000000) {
                gSPTextureRectangle(gfx++, x << 2, y << 2, (x + 64) << 2, (y + 16) << 2, G_TX_RENDERTILE, x << 5,
                                    y << 5, 1 << 10, 1 << 10);
            } else {
                gSPTextureRectangle(gfx++, x << 2, y << 2, (x + 63) << 2, (y + 15) << 2, G_TX_RENDERTILE, x << 5,
                                    y << 5, 4 << 10, 1 << 10);
            }
        }
    }
    gDPSetTexturePersp(gfx++, G_TP_PERSP);
    *arg2 += gfx - arg0;
    return gfx;
}
