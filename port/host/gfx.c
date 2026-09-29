/*
 * The RSP's graphics tasks: Fast3D (gbi 2.0D) display lists, run by a small
 * software renderer that draws into the game's own framebuffer in RDRAM,
 * as the RDP would.
 *
 * RSP side: the matrix stack, vertex transform and lighting, clipping,
 * the moveword/movemem state.  RDP side: TMEM loads (linear, without the
 * odd-row swizzle, on both the load and the sampling side), the tiles, the
 * color combiner (both cycles, all inputs but noise and keying), a
 * simplified blender, alpha compare and a float z-buffer tied to the z
 * image.  Point sampling only.  What the game sees is the same as on the
 * hardware: pixels in the color image, and OS_EVENT_DP only for a list that
 * ends in gDPFullSync.
 *
 * This is the first renderer, meant to be simple and faithful rather than
 * fast or pretty; an accelerated one can replace it at host_gfx_task().
 */
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "host.h"

/* ---- state ------------------------------------------------------------------- */

typedef struct {
    float x, y, z, w;           /* clip space */
    float s, t;                 /* texels */
    float r, g, b, a;           /* 0..255 */
} Vtx4;

typedef struct {
    int fmt, siz, line, tmem, pal;
    int cms, cmt, masks, maskt, shifts, shiftt;
    int uls, ult, lrs, lrt;     /* 10.2 */
} Tile;

static struct {
    uint32_t seg[16];
    float mv[10][4][4];
    int mv_top;
    float proj[4][4];
    float mvp[4][4];
    int mvp_dirty;
    Vtx4 v[16];
    uint32_t geom;
    uint32_t om_h, om_l;
    uint32_t cc0, cc1;
    uint8_t fill_hi[4];
    uint32_t fill;
    uint8_t fog[4], blend[4], prim[4], env[4];
    uint8_t prim_lod;
    float tex_s, tex_t;
    int tex_tile, tex_on;
    Tile tile[8];
    uint32_t timg_addr;
    int timg_fmt, timg_siz, timg_w;
    uint32_t cimg_addr;
    int cimg_siz, cimg_w;
    uint32_t zimg_addr;
    int sc_x0, sc_y0, sc_x1, sc_y1;
    float vp_scale[3], vp_trans[3];
    int nlights;
    uint8_t lcol[8][3];
    float ldir[8][3];
    uint32_t half1, half2;
    int sync;
} g;

static uint8_t tmem[4096];
static float zbuf[640 * 480];
int host_gfx_stats[256];
static unsigned long long st_tris, st_raster, st_tested, st_drawn;

static uint32_t seg_to_k0(uint32_t a) {
    uint32_t seg = (a >> 24) & 0x0F;
    return 0x80000000u | ((g.seg[seg] + (a & 0x00FFFFFFu)) & 0x1FFFFFFFu);
}

static void mtx_mul(float r[4][4], float a[4][4], float b[4][4]) {
    float t[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            t[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j] + a[i][3] * b[3][j];
    memcpy(r, t, sizeof t);
}

static void load_mtx(float m[4][4], uint32_t addr) {
    const uint8_t *p = port_ptr(addr);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            int k = i * 4 + j;
            int16_t hi = (int16_t)port_be16(p + 2 * k);
            uint16_t lo = port_be16(p + 32 + 2 * k);
            m[i][j] = (float)(((int32_t)hi << 16) | lo) / 65536.0f;
        }
}

/* ---- the RSP ----------------------------------------------------------------- */

static void do_mtx(uint32_t w0, uint32_t w1) {
    int p = (w0 >> 16) & 0xFF;
    float m[4][4];
    load_mtx(m, seg_to_k0(w1));
    if (p & 1) {                        /* projection */
        if (p & 2)
            memcpy(g.proj, m, sizeof m);
        else
            mtx_mul(g.proj, m, g.proj);
    } else {
        if ((p & 4) && g.mv_top < 9) {
            memcpy(g.mv[g.mv_top + 1], g.mv[g.mv_top], sizeof m);
            g.mv_top++;
        }
        if (p & 2)
            memcpy(g.mv[g.mv_top], m, sizeof m);
        else
            mtx_mul(g.mv[g.mv_top], m, g.mv[g.mv_top]);
    }
    g.mvp_dirty = 1;
}

static void do_vtx(uint32_t w0, uint32_t w1) {
    int n = ((w0 >> 20) & 0xF) + 1, v0 = (w0 >> 16) & 0xF;
    const uint8_t *p = port_ptr(seg_to_k0(w1));
    if (g.mvp_dirty) {
        mtx_mul(g.mvp, g.mv[g.mv_top], g.proj);
        g.mvp_dirty = 0;
    }
    float (*mv)[4] = g.mv[g.mv_top];
    float ldir[8][3];
    if (g.geom & 0x20000) {             /* G_LIGHTING: lights into model space */
        for (int l = 0; l < g.nlights; l++) {
            float d[3];
            for (int j = 0; j < 3; j++)
                d[j] = mv[j][0] * g.ldir[l][0] + mv[j][1] * g.ldir[l][1] + mv[j][2] * g.ldir[l][2];
            float len = sqrtf(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);
            if (len > 0)
                for (int j = 0; j < 3; j++)
                    d[j] /= len;
            memcpy(ldir[l], d, sizeof d);
        }
    }
    for (int i = 0; i < n && v0 + i < 16; i++, p += 16) {
        Vtx4 *v = &g.v[v0 + i];
        float x = (int16_t)port_be16(p), y = (int16_t)port_be16(p + 2), z = (int16_t)port_be16(p + 4);
        v->x = x * g.mvp[0][0] + y * g.mvp[1][0] + z * g.mvp[2][0] + g.mvp[3][0];
        v->y = x * g.mvp[0][1] + y * g.mvp[1][1] + z * g.mvp[2][1] + g.mvp[3][1];
        v->z = x * g.mvp[0][2] + y * g.mvp[1][2] + z * g.mvp[2][2] + g.mvp[3][2];
        v->w = x * g.mvp[0][3] + y * g.mvp[1][3] + z * g.mvp[2][3] + g.mvp[3][3];
        float s = (int16_t)port_be16(p + 8), t = (int16_t)port_be16(p + 10);
        if (g.geom & 0x20000) {
            float nx = (int8_t)p[12], ny = (int8_t)p[13], nz = (int8_t)p[14];
            float len = sqrtf(nx * nx + ny * ny + nz * nz);
            if (len > 0) { nx /= len; ny /= len; nz /= len; }
            float c[3] = { g.lcol[g.nlights][0], g.lcol[g.nlights][1], g.lcol[g.nlights][2] };
            for (int l = 0; l < g.nlights; l++) {
                float d = nx * ldir[l][0] + ny * ldir[l][1] + nz * ldir[l][2];
                if (d > 0)
                    for (int j = 0; j < 3; j++)
                        c[j] += d * g.lcol[l][j];
            }
            v->r = c[0] > 255 ? 255 : c[0];
            v->g = c[1] > 255 ? 255 : c[1];
            v->b = c[2] > 255 ? 255 : c[2];
            if (g.geom & 0x40000) {     /* G_TEXTURE_GEN: sphere map */
                float ex = nx * mv[0][0] + ny * mv[1][0] + nz * mv[2][0];
                float ey = nx * mv[0][1] + ny * mv[1][1] + nz * mv[2][1];
                float el = sqrtf(ex * ex + ey * ey + 1e-9f);
                if (el > 1) { ex /= el; ey /= el; }
                s = (ex * 0.5f + 0.5f) * 32 * 32 * 64;
                t = (ey * 0.5f + 0.5f) * 32 * 32 * 64;
            }
        } else {
            v->r = p[12];
            v->g = p[13];
            v->b = p[14];
        }
        v->a = p[15];
        v->s = s * g.tex_s / 32.0f;
        v->t = t * g.tex_t / 32.0f;
    }
}

/* ---- the RDP: textures ---------------------------------------------------------- */

static int bytes_per_texel_x2(int siz) { return siz == 0 ? 1 : siz == 1 ? 2 : siz == 2 ? 4 : 8; }

static void load_block(uint32_t w0, uint32_t w1) {
    Tile *t = &g.tile[(w1 >> 24) & 7];
    int uls = (w0 >> 12) & 0xFFF, ult = w0 & 0xFFF, lrs = (w1 >> 12) & 0xFFF;
    int bpt2 = bytes_per_texel_x2(g.timg_siz);
    uint32_t bytes = (uint32_t)(lrs - uls + 1) * bpt2 / 2;
    uint32_t src = g.timg_addr + ((uint32_t)ult * g.timg_w + uls) * bpt2 / 2;
    uint32_t dst = t->tmem * 8;
    const uint8_t *p = port_ptr(src);
    for (uint32_t i = 0; i < bytes && dst + i < 4096; i++)
        tmem[dst + i] = p[i];
}

static void load_tile(uint32_t w0, uint32_t w1) {
    Tile *t = &g.tile[(w1 >> 24) & 7];
    int uls = ((w0 >> 12) & 0xFFF) >> 2, ult = (w0 & 0xFFF) >> 2;
    int lrs = ((w1 >> 12) & 0xFFF) >> 2, lrt = (w1 & 0xFFF) >> 2;
    int bpt2 = bytes_per_texel_x2(g.timg_siz);
    t->uls = uls << 2; t->ult = ult << 2; t->lrs = lrs << 2; t->lrt = lrt << 2;
    uint32_t rowbytes = (uint32_t)(lrs - uls + 1) * bpt2 / 2;
    for (int y = ult; y <= lrt; y++) {
        const uint8_t *p = port_ptr(g.timg_addr + ((uint32_t)y * g.timg_w + uls) * bpt2 / 2);
        uint32_t dst = t->tmem * 8 + (uint32_t)(y - ult) * t->line * 8;
        for (uint32_t i = 0; i < rowbytes && dst + i < 4096; i++)
            tmem[dst + i] = p[i];
    }
}

static void load_tlut(uint32_t w0, uint32_t w1) {
    Tile *t = &g.tile[(w1 >> 24) & 7];
    int uls = ((w0 >> 12) & 0xFFF) >> 2, lrs = ((w1 >> 12) & 0xFFF) >> 2;
    const uint8_t *p = port_ptr(g.timg_addr + (uint32_t)uls * 2);
    uint32_t dst = t->tmem * 8;
    for (int i = 0; i <= lrs - uls && dst + 2 * i + 1 < 4096; i++) {
        tmem[dst + 2 * i] = p[2 * i];
        tmem[dst + 2 * i + 1] = p[2 * i + 1];
    }
}

static int wrap(int c, int cm, int mask, int size) {
    if ((cm & 2) || !mask) {            /* clamp */
        if (!mask || (cm & 2)) {
            if (c < 0) c = 0;
            if (c > size) c = size;
        }
    }
    if (mask) {
        int m = (1 << mask) - 1;
        int mir = (cm & 1) && (c & (1 << mask));
        c &= m;
        if (mir)
            c = m - c;
    }
    return c;
}

static void rgba16(uint16_t c, uint8_t *o) {
    o[0] = ((c >> 11) & 31) * 255 / 31;
    o[1] = ((c >> 6) & 31) * 255 / 31;
    o[2] = ((c >> 1) & 31) * 255 / 31;
    o[3] = (c & 1) ? 255 : 0;
}

static void tlut(int idx, uint8_t *o) {
    uint16_t c = port_be16(tmem + 0x800 + (idx & 0xFF) * 2);
    if ((g.om_h >> 14 & 3) == 3) {      /* IA16 */
        o[0] = o[1] = o[2] = c >> 8;
        o[3] = c & 0xFF;
    } else {
        rgba16(c, o);
    }
}

static inline int ifloor(float f) {
    int i = (int)f;
    return i - (f < (float)i);
}

/* does the combiner read TEXEL1 (in either cycle)? */
static int uses_tex1(void) {
    uint32_t w0 = g.cc0, w1 = g.cc1;
    int sel[] = { (w0 >> 20) & 15, (w1 >> 28) & 15, (w0 >> 15) & 31, (w1 >> 15) & 7,
                  (w0 >> 5) & 15, (w1 >> 24) & 15, w0 & 31, (w1 >> 6) & 7 };
    int asel[] = { (w0 >> 12) & 7, (w1 >> 12) & 7, (w0 >> 9) & 7, (w1 >> 9) & 7,
                   (w1 >> 21) & 7, (w1 >> 3) & 7, (w1 >> 18) & 7, w1 & 7 };
    for (int i = 0; i < 8; i++)
        if (sel[i] == 2 || asel[i] == 2 || ((i & 3) == 2 && sel[i] == 9))
            return 1;
    return 0;
}

static void sample(int tile, float fs, float ft, uint8_t *o) {
    Tile *t = &g.tile[tile & 7];
    if (t->shifts) fs = t->shifts < 11 ? fs / (1 << t->shifts) : fs * (1 << (16 - t->shifts));
    if (t->shiftt) ft = t->shiftt < 11 ? ft / (1 << t->shiftt) : ft * (1 << (16 - t->shiftt));
    int s = ifloor(fs - t->uls * 0.25f), tt = ifloor(ft - t->ult * 0.25f);
    s = wrap(s, t->cms, t->masks, (t->lrs - t->uls) >> 2);
    tt = wrap(tt, t->cmt, t->maskt, (t->lrt - t->ult) >> 2);
    uint32_t row = t->tmem * 8 + (uint32_t)tt * t->line * 8;
    int fmt = t->fmt;
    switch (t->siz) {
    case 0: {                                       /* 4-bit */
        uint8_t b = tmem[(row + s / 2) & 4095];
        int v = (s & 1) ? b & 15 : b >> 4;
        if (fmt == 2) { tlut(v | (t->pal << 4), o); return; }
        if (fmt == 3) {                             /* IA4 */
            o[0] = o[1] = o[2] = (v >> 1) * 255 / 7;
            o[3] = (v & 1) ? 255 : 0;
            return;
        }
        o[0] = o[1] = o[2] = o[3] = v * 17;         /* I4 */
        return;
    }
    case 1: {                                       /* 8-bit */
        uint8_t v = tmem[(row + s) & 4095];
        if (fmt == 2) { tlut(v, o); return; }
        if (fmt == 3) {                             /* IA8 */
            o[0] = o[1] = o[2] = (v >> 4) * 17;
            o[3] = (v & 15) * 17;
            return;
        }
        o[0] = o[1] = o[2] = o[3] = v;
        return;
    }
    case 2: {                                       /* 16-bit */
        uint32_t a = (row + s * 2) & 4094;
        uint16_t c = (uint16_t)(tmem[a] << 8 | tmem[a + 1]);
        if (fmt == 3) {                             /* IA16 */
            o[0] = o[1] = o[2] = c >> 8;
            o[3] = c & 0xFF;
            return;
        }
        if (fmt == 2) { tlut(c >> 8, o); return; }
        rgba16(c, o);
        return;
    }
    default: {                                      /* 32-bit, linear */
        uint32_t a = (row + s * 4) & 4092;
        memcpy(o, tmem + a, 4);
        return;
    }
    }
}

/* ---- the RDP: combiner, blender, pixels ------------------------------------------ */

typedef struct {
    float shade[4];
    uint8_t t0[4], t1[4];
} Inputs;

static inline float clamp255(float v) { return v < 0 ? 0 : v > 255 ? 255 : v; }

/* The combiner: (A - B) * C + D per channel, both cycles.  The selectors
   are turned into indices into one table of inputs when the mode changes. */
enum { I_COMB, I_T0, I_T1, I_PRIM, I_SHADE, I_ENV, I_ONE, I_ZERO, I_COMB_A, I_T0_A, I_T1_A,
       I_PRIM_A, I_SHADE_A, I_ENV_A, I_LOD, I_PRIM_LOD, I_N };

static uint8_t cc_idx[2][8];
static int cc_cycles;
static uint32_t cc_key0 = 1, cc_key1, cc_keyh;

static int map_a(int s) { return s <= 5 ? s : s == 6 ? I_ONE : I_ZERO; }
static int map_b(int s) { return s <= 5 ? s : I_ZERO; }
static int map_c(int s) {
    static const uint8_t m[] = { I_COMB, I_T0, I_T1, I_PRIM, I_SHADE, I_ENV, I_ZERO, I_COMB_A, I_T0_A,
                                 I_T1_A, I_PRIM_A, I_SHADE_A, I_ENV_A, I_LOD, I_PRIM_LOD };
    return s < 15 ? m[s] : I_ZERO;
}
static int map_d(int s) { return s <= 5 ? s : s == 6 ? I_ONE : I_ZERO; }
static int map_aa(int s) { return s <= 5 ? s : s == 6 ? I_ONE : I_ZERO; }
static int map_ac(int s) { return s == 0 ? I_LOD : s <= 5 ? s : s == 6 ? I_PRIM_LOD : I_ZERO; }

static void cc_prepare(void) {
    uint32_t w0 = g.cc0, w1 = g.cc1;
    int sel[2][8] = {
        { (w0 >> 20) & 15, (w1 >> 28) & 15, (w0 >> 15) & 31, (w1 >> 15) & 7,
          (w0 >> 12) & 7, (w1 >> 12) & 7, (w0 >> 9) & 7, (w1 >> 9) & 7 },
        { (w0 >> 5) & 15, (w1 >> 24) & 15, w0 & 31, (w1 >> 6) & 7,
          (w1 >> 21) & 7, (w1 >> 3) & 7, (w1 >> 18) & 7, w1 & 7 },
    };
    for (int c = 0; c < 2; c++) {
        cc_idx[c][0] = map_a(sel[c][0]);
        cc_idx[c][1] = map_b(sel[c][1]);
        cc_idx[c][2] = map_c(sel[c][2]);
        cc_idx[c][3] = map_d(sel[c][3]);
        cc_idx[c][4] = map_aa(sel[c][4]);
        cc_idx[c][5] = map_aa(sel[c][5]);
        cc_idx[c][6] = map_ac(sel[c][6]);
        cc_idx[c][7] = map_aa(sel[c][7]);
    }
    cc_cycles = ((g.om_h >> 20) & 3) == 1 ? 2 : 1;
    cc_key0 = w0;
    cc_key1 = w1;
    cc_keyh = g.om_h;
}

static inline void splat(float *d, float v) { d[0] = d[1] = d[2] = d[3] = v; }

static void combine(const Inputs *in, float *out) {
    if (g.cc0 != cc_key0 || g.cc1 != cc_key1 || g.om_h != cc_keyh)
        cc_prepare();
    float t[I_N][4];
    for (int ch = 0; ch < 4; ch++) {
        t[I_COMB][ch] = 0;
        t[I_T0][ch] = in->t0[ch];
        t[I_T1][ch] = in->t1[ch];
        t[I_PRIM][ch] = g.prim[ch];
        t[I_SHADE][ch] = in->shade[ch];
        t[I_ENV][ch] = g.env[ch];
    }
    splat(t[I_ONE], 255);
    splat(t[I_ZERO], 0);
    splat(t[I_COMB_A], 0);
    splat(t[I_T0_A], in->t0[3]);
    splat(t[I_T1_A], in->t1[3]);
    splat(t[I_PRIM_A], g.prim[3]);
    splat(t[I_SHADE_A], in->shade[3]);
    splat(t[I_ENV_A], g.env[3]);
    splat(t[I_LOD], 255);
    splat(t[I_PRIM_LOD], g.prim_lod);
    for (int c = 0; c < cc_cycles; c++) {
        const uint8_t *k = cc_idx[c];
        float r[4];
        for (int ch = 0; ch < 3; ch++)
            r[ch] = clamp255((t[k[0]][ch] - t[k[1]][ch]) * t[k[2]][ch] * (1.0f / 255.0f) + t[k[3]][ch]);
        r[3] = clamp255((t[k[4]][3] - t[k[5]][3]) * t[k[6]][3] * (1.0f / 255.0f) + t[k[7]][3]);
        memcpy(t[I_COMB], r, sizeof r);
        splat(t[I_COMB_A], r[3]);
    }
    memcpy(out, t[I_COMB], 4 * sizeof(float));
}

static void read_pixel(int x, int y, float *c) {
    uint8_t *p = port_ptr(g.cimg_addr);
    if (g.cimg_siz == 1) {
        c[0] = c[1] = c[2] = c[3] = p[y * g.cimg_w + x];
    } else if (g.cimg_siz == 3) {
        uint8_t *q = p + 4 * (y * g.cimg_w + x);
        c[0] = q[0]; c[1] = q[1]; c[2] = q[2]; c[3] = q[3];
    } else {
        uint8_t o[4];
        rgba16(port_be16(p + 2 * (y * g.cimg_w + x)), o);
        c[0] = o[0]; c[1] = o[1]; c[2] = o[2]; c[3] = 255;
    }
}

static void write_pixel(int x, int y, const float *c) {
    uint8_t *p = port_ptr(g.cimg_addr);
    if (g.cimg_siz == 1) {
        p[y * g.cimg_w + x] = c[0];
    } else if (g.cimg_siz == 3) {
        uint8_t *q = p + 4 * (y * g.cimg_w + x);
        q[0] = c[0]; q[1] = c[1]; q[2] = c[2]; q[3] = c[3];
    } else {
        uint16_t v = (uint16_t)(((int)c[0] >> 3) << 11 | ((int)c[1] >> 3) << 6 | ((int)c[2] >> 3) << 1 | 1);
        port_wbe16(p + 2 * (y * g.cimg_w + x), v);
    }
}

/* the blender, for the common modes: returns 0 to drop the pixel */
static int blend(int x, int y, float *c, const float *shade) {
    uint32_t l = g.om_l;
    if ((l & 3) == 1 && c[3] < g.blend[3])          /* alpha compare: threshold */
        return 0;
    if ((l & 0x1000) && !(l & 0x4000) && c[3] < 128) /* coverage from alpha */
        return 0;
    if (!(l & 0x4000))                              /* no FORCE_BL: the input */
        return 1;
    int cyc = ((g.om_h >> 20) & 3) == 1 ? 2 : 1;
    float in[4] = { c[0], c[1], c[2], c[3] };
    for (int k = 0; k < cyc; k++) {
        int sh = k == 0 ? 0 : 2;
        int P = (l >> (30 - sh)) & 3, A = (l >> (26 - sh)) & 3, M = (l >> (22 - sh)) & 3, B = (l >> (18 - sh)) & 3;
        float mem[4], pc[3], mc[3], a, b;
        read_pixel(x, y, mem);
        const float *src[4] = { in, mem, NULL, NULL };
        float bl[3] = { g.blend[0], g.blend[1], g.blend[2] }, fg[3] = { g.fog[0], g.fog[1], g.fog[2] };
        for (int ch = 0; ch < 3; ch++) {
            pc[ch] = P == 0 ? in[ch] : P == 1 ? mem[ch] : P == 2 ? bl[ch] : fg[ch];
            mc[ch] = M == 0 ? in[ch] : M == 1 ? mem[ch] : M == 2 ? bl[ch] : fg[ch];
        }
        (void)src;
        a = A == 0 ? in[3] : A == 1 ? g.fog[3] : A == 2 ? shade[3] : 0;
        b = B == 0 ? 255 - a : B == 1 ? mem[3] : B == 2 ? 255 : 0;
        float sum = a + b;
        for (int ch = 0; ch < 3; ch++)
            in[ch] = sum > 0 ? (pc[ch] * a + mc[ch] * b) / sum : pc[ch];
    }
    c[0] = in[0]; c[1] = in[1]; c[2] = in[2];
    return 1;
}

static int zbuf_ok(void) { return g.zimg_addr && g.cimg_w <= 640; }

/* ---- triangles ---------------------------------------------------------------------- */

typedef struct {
    float x, y, z, iw;          /* screen, z 0..1, 1/w */
    float s, t, r, gg, b, a;    /* divided by w */
} SV;

static void raster(const SV *v0, const SV *v1, const SV *v2, const float *flat) {
    float minx = fminf(v0->x, fminf(v1->x, v2->x)), maxx = fmaxf(v0->x, fmaxf(v1->x, v2->x));
    float miny = fminf(v0->y, fminf(v1->y, v2->y)), maxy = fmaxf(v0->y, fmaxf(v1->y, v2->y));
    int x0 = (int)floorf(minx), x1 = (int)ceilf(maxx), y0 = (int)floorf(miny), y1 = (int)ceilf(maxy);
    if (x0 < g.sc_x0) x0 = g.sc_x0;
    if (y0 < g.sc_y0) y0 = g.sc_y0;
    if (x1 > g.sc_x1) x1 = g.sc_x1;
    if (y1 > g.sc_y1) y1 = g.sc_y1;
    float area = (v1->x - v0->x) * (v2->y - v0->y) - (v1->y - v0->y) * (v2->x - v0->x);
    if (fabsf(area) < 1e-6f)
        return;
    int zcmp = (g.geom & 1) && (g.om_l & 0x10) && zbuf_ok();
    int zupd = (g.geom & 1) && (g.om_l & 0x20) && zbuf_ok();
    int decal = ((g.om_l >> 10) & 3) == 3;
    int textured = g.tex_on;
    int tile = g.tex_tile;
    int tex1 = textured && uses_tex1();
    st_raster++;
    float ia = 1.0f / area;
    /* barycentrics are linear in x: step them */
    float d0x = (v1->y - v2->y) * ia, d1x = (v2->y - v0->y) * ia;
    for (int y = y0; y < y1; y++) {
        float py = y + 0.5f, px0 = x0 + 0.5f;
        float w0 = ((v1->x - px0) * (v2->y - py) - (v1->y - py) * (v2->x - px0)) * ia;
        float w1 = ((v2->x - px0) * (v0->y - py) - (v2->y - py) * (v0->x - px0)) * ia;
        w0 -= d0x;
        w1 -= d1x;
        for (int x = x0; x < x1; x++) {
            w0 += d0x;
            w1 += d1x;
            float w2 = 1 - w0 - w1;
            st_tested++;
            if (w0 < 0 || w1 < 0 || w2 < 0)
                continue;
            st_drawn++;
            float z = w0 * v0->z + w1 * v1->z + w2 * v2->z;
            int zi = y * g.cimg_w + x;
            if (zcmp) {
                if (decal ? z > zbuf[zi] + 0.0005f : z > zbuf[zi])
                    continue;
            }
            float iw = w0 * v0->iw + w1 * v1->iw + w2 * v2->iw;
            float wv = iw != 0 ? 1.0f / iw : 0;
            Inputs in;
            if (flat) {
                memcpy(in.shade, flat, sizeof in.shade);
            } else {
                in.shade[0] = (w0 * v0->r + w1 * v1->r + w2 * v2->r) * wv;
                in.shade[1] = (w0 * v0->gg + w1 * v1->gg + w2 * v2->gg) * wv;
                in.shade[2] = (w0 * v0->b + w1 * v1->b + w2 * v2->b) * wv;
                in.shade[3] = (w0 * v0->a + w1 * v1->a + w2 * v2->a) * wv;
            }
            if (textured) {
                float s = (w0 * v0->s + w1 * v1->s + w2 * v2->s) * wv;
                float t = (w0 * v0->t + w1 * v1->t + w2 * v2->t) * wv;
                sample(tile, s, t, in.t0);
                if (tex1)
                    sample(tile + 1, s, t, in.t1);
                else
                    memset(in.t1, 0, 4);
            } else {
                memset(in.t0, 0, 4);
                memset(in.t1, 0, 4);
            }
            float c[4];
            combine(&in, c);
            if (!blend(x, y, c, in.shade))
                continue;
            write_pixel(x, y, c);
            if (zupd)
                zbuf[zi] = z;
        }
    }
}

static void to_screen(const Vtx4 *v, SV *o) {
    float iw = 1.0f / v->w;
    o->x = g.vp_trans[0] + v->x * iw * g.vp_scale[0];
    o->y = g.vp_trans[1] - v->y * iw * g.vp_scale[1];
    o->z = (v->z * iw) * 0.5f + 0.5f;
    o->iw = iw;
    o->s = v->s * iw; o->t = v->t * iw;
    o->r = v->r * iw; o->gg = v->g * iw; o->b = v->b * iw; o->a = v->a * iw;
}

static void lerp(Vtx4 *o, const Vtx4 *a, const Vtx4 *b, float t) {
    float *po = (float *)o;
    const float *pa = (const float *)a, *pb = (const float *)b;
    for (unsigned i = 0; i < sizeof(Vtx4) / sizeof(float); i++)
        po[i] = pa[i] + (pb[i] - pa[i]) * t;
}

/* clip a polygon against plane dot(p, v) >= 0 */
static int clip_poly(Vtx4 *in, int n, Vtx4 *out, int plane) {
    int m = 0;
    for (int i = 0; i < n; i++) {
        Vtx4 *a = &in[i], *b = &in[(i + 1) % n];
        float da = plane == 0 ? a->w - 1e-3f : a->z + a->w;
        float db = plane == 0 ? b->w - 1e-3f : b->z + b->w;
        if (da >= 0)
            out[m++] = *a;
        if ((da >= 0) != (db >= 0))
            lerp(&out[m++], a, b, da / (da - db));
    }
    return m;
}

static void tri(int i0, int i1, int i2, int flag) {
    st_tris++;
    Vtx4 *a = &g.v[i0 & 15], *b = &g.v[i1 & 15], *c = &g.v[i2 & 15];
    float flat[4];
    const float *fl = NULL;
    if (!(g.geom & 0x200) || !(g.geom & 0x4)) {
        const Vtx4 *f = flag == 1 ? b : flag == 2 ? c : a;
        flat[0] = f->r; flat[1] = f->g; flat[2] = f->b; flat[3] = f->a;
        if (!(g.geom & 0x4)) {
            flat[0] = flat[1] = flat[2] = flat[3] = 0;
            flat[3] = 255;
        }
        fl = flat;
    }
    /* culling, in normalized device coordinates */
    if (a->w > 0 && b->w > 0 && c->w > 0 && (g.geom & 0x3000)) {
        float ax = a->x / a->w, ay = a->y / a->w, bx = b->x / b->w, by = b->y / b->w;
        float cx = c->x / c->w, cy = c->y / c->w;
        float cross = (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);
        if ((g.geom & 0x2000) && cross < 0)
            return;
        if ((g.geom & 0x1000) && cross > 0)
            return;
    }
    Vtx4 p0[3] = { *a, *b, *c }, p1[9], p2[9];
    int n = clip_poly(p0, 3, p1, 0);
    n = clip_poly(p1, n, p2, 1);
    if (n < 3)
        return;
    SV s[9];
    for (int i = 0; i < n; i++)
        to_screen(&p2[i], &s[i]);
    for (int i = 1; i + 1 < n; i++)
        raster(&s[0], &s[i], &s[i + 1], fl);
}

/* ---- rectangles ------------------------------------------------------------------------ */

static void fill_rect(uint32_t w0, uint32_t w1) {
    int lrx = ((w0 >> 12) & 0xFFF) >> 2, lry = (w0 & 0xFFF) >> 2;
    int ulx = ((w1 >> 12) & 0xFFF) >> 2, uly = (w1 & 0xFFF) >> 2;
    int cyc = (g.om_h >> 20) & 3;
    if (cyc == 3 || cyc == 2) { lrx++; lry++; }
    if (ulx < g.sc_x0) ulx = g.sc_x0;
    if (uly < g.sc_y0) uly = g.sc_y0;
    if (lrx > g.sc_x1) lrx = g.sc_x1;
    if (lry > g.sc_y1) lry = g.sc_y1;
    if (g.cimg_addr == g.zimg_addr && zbuf_ok()) {  /* clearing the z-buffer */
        for (int y = uly; y < lry; y++)
            for (int x = ulx; x < lrx; x++)
                zbuf[y * g.cimg_w + x] = 1.0f;
    }
    uint8_t *p = port_ptr(g.cimg_addr);
    for (int y = uly; y < lry; y++)
        for (int x = ulx; x < lrx; x++) {
            if (cyc == 3) {
                if (g.cimg_siz == 1)
                    p[y * g.cimg_w + x] = g.fill >> (24 - 8 * (x & 3));
                else if (g.cimg_siz == 3)
                    port_wbe32(p + 4 * (y * g.cimg_w + x), g.fill);
                else
                    port_wbe16(p + 2 * (y * g.cimg_w + x), (x & 1) ? g.fill & 0xFFFF : g.fill >> 16);
            } else {
                Inputs in;
                memset(&in, 0, sizeof in);
                float c[4];
                combine(&in, c);
                if (blend(x, y, c, in.shade))
                    write_pixel(x, y, c);
            }
        }
}

static void tex_rect(uint32_t w0, uint32_t w1, uint32_t h2, uint32_t hc, int flip) {
    float lrx = ((w0 >> 12) & 0xFFF) / 4.0f, lry = (w0 & 0xFFF) / 4.0f;
    float ulx = ((w1 >> 12) & 0xFFF) / 4.0f, uly = (w1 & 0xFFF) / 4.0f;
    int tile = (w1 >> 24) & 7;
    float s0 = (int16_t)(h2 >> 16) / 32.0f, t0 = (int16_t)(h2 & 0xFFFF) / 32.0f;
    float dsdx = (int16_t)(hc >> 16) / 1024.0f, dtdy = (int16_t)(hc & 0xFFFF) / 1024.0f;
    int cyc = (g.om_h >> 20) & 3;
    if (cyc == 2) {                     /* copy mode: 4 texels per step, inclusive */
        dsdx /= 4;
        lrx += 1;
        lry += 1;
    }
    int x0 = (int)ulx, y0 = (int)uly, x1 = (int)lrx, y1 = (int)lry;
    if (x0 < g.sc_x0) x0 = g.sc_x0;
    if (y0 < g.sc_y0) y0 = g.sc_y0;
    if (x1 > g.sc_x1) x1 = g.sc_x1;
    if (y1 > g.sc_y1) y1 = g.sc_y1;
    for (int y = y0; y < y1; y++)
        for (int x = x0; x < x1; x++) {
            float fx = x - ulx, fy = y - uly;
            float s = s0 + (flip ? fy : fx) * dsdx, t = t0 + (flip ? fx : fy) * dtdy;
            Inputs in;
            memset(&in, 0, sizeof in);
            sample(tile, s, t, in.t0);
            sample(tile + 1, s, t, in.t1);
            float c[4];
            if (cyc == 2) {
                c[0] = in.t0[0]; c[1] = in.t0[1]; c[2] = in.t0[2]; c[3] = in.t0[3];
                if ((g.om_l & 3) == 1 && c[3] < 128)
                    continue;
            } else {
                combine(&in, c);
                if (!blend(x, y, c, in.shade))
                    continue;
            }
            write_pixel(x, y, c);
        }
}

/* ---- the display list ------------------------------------------------------------------- */

static void run(uint32_t dl, int depth) {
    for (int n = 0; n < 1000000; n++, dl += 8) {
        const uint8_t *p = port_ptr(dl);
        uint32_t w0 = port_be32(p), w1 = port_be32(p + 4);
        uint8_t op = w0 >> 24;
        host_gfx_stats[op]++;
        switch (op) {
        case 0x01: do_mtx(w0, w1); break;                       /* G_MTX */
        case 0x03: {                                            /* G_MOVEMEM */
            int idx = (w0 >> 16) & 0xFF;
            const uint8_t *m = port_ptr(seg_to_k0(w1));
            if (idx == 0x80) {                                  /* viewport */
                for (int i = 0; i < 3; i++) {
                    g.vp_scale[i] = (int16_t)port_be16(m + 2 * i) / 4.0f;
                    g.vp_trans[i] = (int16_t)port_be16(m + 8 + 2 * i) / 4.0f;
                }
            } else if (idx >= 0x86 && idx <= 0x94) {            /* light */
                int l = (idx - 0x86) / 2;
                memcpy(g.lcol[l], m, 3);
                for (int j = 0; j < 3; j++)
                    g.ldir[l][j] = (int8_t)m[8 + j] / 127.0f;
            }
            break;
        }
        case 0x04: do_vtx(w0, w1); break;                       /* G_VTX */
        case 0x06:                                              /* G_DL */
            if (depth < 16) {
                if ((w0 >> 16) & 1) {
                    run(seg_to_k0(w1), depth + 1);
                    return;
                }
                run(seg_to_k0(w1), depth + 1);
            }
            break;
        case 0xB2: case 0xB3: case 0xB4: case 0xC0: break;      /* halves, nop */
        case 0xB6: g.geom &= ~w1; break;                        /* G_CLEARGEOMETRYMODE */
        case 0xB7: g.geom |= w1; break;                         /* G_SETGEOMETRYMODE */
        case 0xB8: return;                                      /* G_ENDDL */
        case 0xB9: case 0xBA: {                                 /* G_SETOTHERMODE_L/H */
            int sft = (w0 >> 8) & 0xFF, len = w0 & 0xFF;
            uint32_t mask = (len >= 32 ? 0xFFFFFFFFu : ((1u << len) - 1)) << sft;
            uint32_t *om = op == 0xB9 ? &g.om_l : &g.om_h;
            *om = (*om & ~mask) | (w1 & mask);
            break;
        }
        case 0xBB:                                              /* G_TEXTURE */
            g.tex_s = (w1 >> 16) / 65536.0f;
            g.tex_t = (w1 & 0xFFFF) / 65536.0f;
            g.tex_tile = (w0 >> 8) & 7;
            g.tex_on = w0 & 0xFF;
            break;
        case 0xBC: {                                            /* G_MOVEWORD */
            int idx = w0 & 0xFF, off = (w0 >> 8) & 0xFFFF;
            if (idx == 0x06)
                g.seg[(off / 4) & 15] = w1 & 0x00FFFFFFu;
            else if (idx == 0x02)
                g.nlights = (int)((w1 - 0x80000000u) / 32) - 1;
            if (g.nlights < 0) g.nlights = 0;
            if (g.nlights > 7) g.nlights = 7;
            break;
        }
        case 0xBD:                                              /* G_POPMTX */
            if (g.mv_top > 0)
                g.mv_top--;
            g.mvp_dirty = 1;
            break;
        case 0xBE: break;                                       /* G_CULLDL */
        case 0xBF:                                              /* G_TRI1 */
            tri(((w1 >> 16) & 0xFF) / 10, ((w1 >> 8) & 0xFF) / 10, (w1 & 0xFF) / 10, w1 >> 24);
            break;
        case 0xE4: case 0xE5: {                                 /* texture rectangle */
            const uint8_t *q = port_ptr(dl + 8);
            uint32_t h2 = port_be32(q + 4), hc = port_be32(q + 12);
            tex_rect(w0, w1, h2, hc, op == 0xE5);
            dl += 16;
            break;
        }
        case 0xE6: case 0xE7: case 0xE8: break;                 /* syncs */
        case 0xE9: g.sync = 1; break;                           /* G_RDPFULLSYNC */
        case 0xED:                                              /* G_SETSCISSOR */
            g.sc_x0 = ((w0 >> 12) & 0xFFF) >> 2; g.sc_y0 = (w0 & 0xFFF) >> 2;
            g.sc_x1 = ((w1 >> 12) & 0xFFF) >> 2; g.sc_y1 = (w1 & 0xFFF) >> 2;
            break;
        case 0xEF: g.om_h = w0 & 0xFFFFFF; g.om_l = w1; break;  /* G_RDPSETOTHERMODE */
        case 0xF0: load_tlut(w0, w1); break;
        case 0xF2: {                                            /* G_SETTILESIZE */
            Tile *t = &g.tile[(w1 >> 24) & 7];
            t->uls = (w0 >> 12) & 0xFFF; t->ult = w0 & 0xFFF;
            t->lrs = (w1 >> 12) & 0xFFF; t->lrt = w1 & 0xFFF;
            break;
        }
        case 0xF3: load_block(w0, w1); break;
        case 0xF4: load_tile(w0, w1); break;
        case 0xF5: {                                            /* G_SETTILE */
            Tile *t = &g.tile[(w1 >> 24) & 7];
            t->fmt = (w0 >> 21) & 7; t->siz = (w0 >> 19) & 3;
            t->line = (w0 >> 9) & 0x1FF; t->tmem = w0 & 0x1FF;
            t->pal = (w1 >> 20) & 15;
            t->cmt = (w1 >> 18) & 3; t->maskt = (w1 >> 14) & 15; t->shiftt = (w1 >> 10) & 15;
            t->cms = (w1 >> 8) & 3; t->masks = (w1 >> 4) & 15; t->shifts = w1 & 15;
            break;
        }
        case 0xF6: fill_rect(w0, w1); break;
        case 0xF7: g.fill = w1; break;
        case 0xF8: port_wbe32(g.fog, w1); break;
        case 0xF9: port_wbe32(g.blend, w1); break;
        case 0xFA: port_wbe32(g.prim, w1); g.prim_lod = w0 & 0xFF; break;
        case 0xFB: port_wbe32(g.env, w1); break;
        case 0xFC: g.cc0 = w0 & 0xFFFFFF; g.cc1 = w1; break;
        case 0xFD:                                              /* G_SETTIMG */
            g.timg_fmt = (w0 >> 21) & 7; g.timg_siz = (w0 >> 19) & 3;
            g.timg_w = (w0 & 0xFFF) + 1;
            g.timg_addr = seg_to_k0(w1);
            break;
        case 0xFE: g.zimg_addr = seg_to_k0(w1); break;
        case 0xFF:                                              /* G_SETCIMG */
            g.cimg_siz = (w0 >> 19) & 3;
            g.cimg_w = (w0 & 0xFFF) + 1;
            g.cimg_addr = seg_to_k0(w1);
            if (getenv("PORT_GFXLOG"))
                host_log("cimg %08X w %d siz %d (w1 %08X)\n", g.cimg_addr, g.cimg_w, g.cimg_siz, w1);
            break;
        default:
            break;
        }
    }
    host_log("gfx: display list at %08X doesn't end\n", dl);
}

static int gfx_tasks;

int host_gfx_task(uint32_t dl, uint32_t size, uint32_t ucode) {
    (void)ucode;
    gfx_tasks++;
    memset(g.seg, 0, sizeof g.seg);
    g.sync = 0;
    g.mv_top = 0;
    g.mvp_dirty = 1;
    if (!g.sc_x1) {
        g.sc_x1 = 320;
        g.sc_y1 = 240;
    }
    unsigned long long drawn = st_drawn;
    run(dl, 0);
    /* --deterministic: the RDP's time, roughly (a pixel per 2 cycles) */
    host_charge(500000 + (st_drawn - drawn) * 30);
    if (host_verbose && (gfx_tasks < 5 || gfx_tasks % 300 == 0))
        host_log("gfx task %d: dl %08X size %X%s\n", gfx_tasks, dl, size, g.sync ? " (full sync)" : "");
    return g.sync;
}

void host_gfx_dump_stats(void) {
    host_log("gfx opcode counts:");
    for (int i = 0; i < 256; i++)
        if (host_gfx_stats[i])
            host_log(" %02X:%d", i, host_gfx_stats[i]);
    host_log("\ntris %llu rastered %llu pixels tested %llu inside %llu over %d tasks\n",
             st_tris, st_raster, st_tested, st_drawn, gfx_tasks);
}
