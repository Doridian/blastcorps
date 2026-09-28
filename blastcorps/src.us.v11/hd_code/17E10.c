#include "common.h"

/*
 * The game's older gbi.h sends a texture rectangle's s/t with G_RDPHALF_2
 * and dsdx/dtdy with G_RDPHALF_CONT (2.0I uses G_RDPHALF_1 and G_RDPHALF_2),
 * and its scissoring variant clamps without 2.0I's s16 casts and sign tests.
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

#undef gSPScisTextureRectangle
#define gSPScisTextureRectangle(pkt, xl, yl, xh, yh, tile, s, t, dsdx, dtdy) \
{                                                                           \
    Gfx *_g = (Gfx *)(pkt);                                                 \
                                                                            \
    _g->words.w0 = (_SHIFTL(G_TEXRECT, 24, 8) | _SHIFTL(MAX(xh, 0), 12, 12) | \
                    _SHIFTL(MAX(yh, 0), 0, 12));                            \
    _g->words.w1 = (_SHIFTL(tile, 24, 3) | _SHIFTL(MAX(xl, 0), 12, 12) |    \
                    _SHIFTL(MAX(yl, 0), 0, 12));                            \
    gImmp1(pkt, G_RDPHALF_2,                                                \
           (_SHIFTL((s) - MIN(((xl) * (dsdx)) >> 7, 0), 16, 16) |           \
            _SHIFTL((t) - MIN(((yl) * (dtdy)) >> 7, 0), 0, 16)));           \
    gImmp1(pkt, G_RDPHALF_CONT, (_SHIFTL(dsdx, 16, 16) | _SHIFTL(dtdy, 0, 16))); \
}

/* Rare's sound player, derived from libaudio's sndplayer.c. */
typedef struct UnkSndState_s {
    /* 0x00 */ ALLink node;
    /* 0x08 */ ALSound *sound;
    /* 0x0C */ ALVoice voice;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 pitch;
    /* 0x30 */ struct UnkSndState_s **unk30;
    /* 0x34 */ s16 unk34;
    /* 0x36 */ u8 unk36;
    /* 0x38 */ s32 unk38;
    /* 0x3C */ u8 unk3C;
    /* 0x3D */ u8 unk3D;
    /* 0x3E */ u8 unk3E;
    /* 0x3F */ u8 unk3F;
} UnkSndState; /* size = 0x40 */

typedef struct {
    /* 0x00 */ u16 type;
    /* 0x04 */ UnkSndState *state;
    /* 0x08 */ s32 param;
    /* 0x0C */ void *unkC;
} UnkSndEvent; /* size = 0x10, an ALEvent */

typedef struct {
    /* 0x00 */ u8 unk0[0xC];
    /* 0x0C */ ALSound *soundArray[1];
} UnkSndInst;

typedef struct {
    /* 0x00 */ u8 unk0[0xC];
    /* 0x0C */ UnkSndInst *unkC;
} UnkSndBank;

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1[0x43];
} UnkStruct_802E8F94; /* size = 0x44 */

typedef struct {
    /* 0x00 */ u8 unk0[0x18];
    /* 0x18 */ u8 unk18[0xE8];
} UnkStruct_80364AF0; /* size = 0x100 */

typedef struct {
    /* 0x00 */ u32 maxSounds;
    /* 0x04 */ s32 maxEvents;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ ALHeap *heap;
    /* 0x10 */ u16 unk10;
} UnkSndConfig;

typedef struct {
    /* 0x00 */ ALPlayer node;
    /* 0x14 */ ALEventQueue evtq;
    /* 0x28 */ ALEvent nextEvent;
    /* 0x38 */ ALSynth *drvr;
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ UnkSndState *unk40;
    /* 0x44 */ UnkSndState *unk44;
    /* 0x48 */ s32 unk48;
    /* 0x4C */ ALMicroTime frameTime;
    /* 0x50 */ ALMicroTime nextDelta;
    /* 0x54 */ ALMicroTime curTime;
} UnkSndPlayer;

typedef struct {
    /* 0x0 */ UnkSndState *head;
    /* 0x4 */ UnkSndState *tail;
    /* 0x8 */ UnkSndState *freeList;
} UnkStruct_802E8CE0;

void func_8029A7E4(char *, ...);
void func_8024FC2C(Gfx **gfxp, s32 arg1);
Gfx *func_8025D2B4(Gfx *gfx, s32 arg1, s32 *arg2);
void func_8025E1E0(Gfx **gfxp);
ALMicroTime func_8025F044(void *node);
void func_8025F0F0(UnkSndPlayer *sndp, UnkSndEvent *event);
void func_80260148(ALEventQueue *evtq, UnkSndState *state, u16 eventType);
UnkSndState *func_80260300(UnkSndBank *bank, ALSound *sound);
UnkSndState *func_80260650(UnkSndBank *bank, s16 id, UnkSndState **handle);
void func_802609D0(void);
void func_802609F0(void);
void func_80260A10(void);
void func_802604FC(UnkSndState *state);
void func_802608C8(UnkSndState *state);
void func_80260934(u8 arg0);
void func_80260DFC(void);
void func_80261570(f32);
s32 func_8026B10C(void);
void func_80275390(u64);
void func_80260E2C(void);
void func_80260EE0(s32);
s32 func_8026205C(s32);
void func_8026AF6C(s32);
void func_80275270(u64, f32);
s32 func_802753C0(void);
void func_80277EDC(s32, s32, s32, s32);
void func_80278318(void);
void func_802C1DD0(s32);
s32 func_802D4E10(ALCSPlayer *);
void func_8028B4C4(u32 romAddr, void *dest, s32 *size, s32 arg3, s32 arg4, s32 arg5);

/* Segment 2 base and three ROM addresses, reached through relocations. */
extern Mtx D_02000000[];
extern u8 D_00487050[];
extern u8 D_00489E70[];
extern u8 D_0048F5A0[];
extern s8 D_802E8BD8;
extern u8 D_802E8BF0;
extern UnkSndState *D_802E8CE0;
extern UnkSndState *D_802E8CE4;
extern UnkSndState *D_802E8CE8;
extern UnkSndPlayer *D_802E8CEC;
extern s16 D_802E8CF0;
extern u32 D_802E8CD0[];
extern UnkStruct_802E8F94 D_802E8F94[];
extern u8 D_803643D6;
extern u8 D_803643D7;
extern u8 D_803643D8;
extern f64 D_80309098;
extern s32 D_80364AA8;
extern u8 D_80364AE8;
extern UnkStruct_80364AF0 D_80364AF0[];
extern u32 D_80366BB8;
extern u8 D_80366BC0;
extern u16 D_80366BC2;
extern u8 D_80366BC4;
extern u8 D_80366BC5;
extern ALCSPlayer *D_80367734;
extern UnkSndBank *D_80367738;
extern u32 D_80367740;
extern s16 D_8036BB18;
extern s16 D_8036BB1A;
extern s16 D_8036BB1C;
extern s32 D_802E8BDC;
extern char D_80309124[];
extern char D_8030914C[];
extern char D_8030917C[];
extern Vtx D_802FA8B0[][4];
extern u32 D_803156C4;
extern u32 D_80358060;
extern u8 *D_80358070;
extern u64 D_80364A90;
extern u64 D_80364A98;
extern s16 D_80366A00;
extern s16 D_80366A02;
extern s16 D_80366A04;
extern s8 D_80366A10;
extern s8 D_80366A11;
extern u16 D_80366A12;
extern s16 D_80366A14;
extern s16 D_80366A16;
extern Vtx *D_80366BA0;
extern u8 *D_80366BA4;
extern s32 D_80366BA8;
extern u32 D_80366BB0[];
extern s16 D_8039CAA0;
extern u32 D_80366BBC;
extern u16 *D_80366C28;

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/17E10/func_8025C5D0.s")

Gfx *func_8025C878(Gfx *arg0, s32 arg1, u8 arg2, s32 *arg3) {
    u8 *sp6C;
    u32 sp68;
    Gfx *gfx;
    s32 i;

    sp68 = D_803156C4;
    gfx = arg0;
    if (D_802E8BF0 != 0 && (D_80364A90 & 2)) {
        if (arg2 != 0) {
            sp6C = D_80366BA4;
        } else {
            sp6C = D_80366BA4 + 0x3C0;
        }
        D_80366BA8 = 0;
        if (D_80358060 == 0) {
            D_80366A10 = 0;
            D_80366A11 = 0;
        }
        if (D_80358060 > D_80366A04) {
            if (sp68 < D_80366BBC + 0x78) {
                gDPPipeSync(gfx++);
                gSPMatrix(gfx++, &D_02000000[3], G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
                gSPMatrix(gfx++, &D_02000000[7], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
                gDPSetRenderMode(gfx++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
                gDPSetCombineMode(gfx++, G_CC_SHADE, G_CC_SHADE);
                gSPSetGeometryMode(gfx++, G_SHADE | G_SHADING_SMOOTH);
                gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
                gSPVertex(gfx++, (u32)D_802FA8B0[arg2] + 0x80000000, 4, 0);
                gSP1Triangle(gfx++, 0, 1, 2, 0);
                gSP1Triangle(gfx++, 0, 2, 3, 0);
                for (i = 0; i < 4; i++) {
                    D_802FA8B0[arg2][i].v.cn[0] = 0;
                    D_802FA8B0[arg2][i].v.cn[1] = 0;
                    D_802FA8B0[arg2][i].v.cn[2] = 0;
                    D_802FA8B0[arg2][i].v.cn[3] = (sp68 - D_80366BBC) * 2.125;
                }
                func_8025E1E0(&gfx);
            } else {
                gDPPipeSync(gfx++);
                gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
                gDPSetRenderMode(gfx++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
                gDPSetCycleType(gfx++, G_CYC_FILL);
                gDPSetFillColor(gfx++, 0x00010001);
                gDPFillRectangle(gfx++, 0, 0, 319, 239);
                gDPPipeSync(gfx++);
                gDPSetCycleType(gfx++, G_CYC_1CYCLE);
                func_8025E1E0(&gfx);
            }
        } else {
            if (D_80366A04 == D_80358060) {
                D_80366BBC = sp68;
            }
            func_8025E1E0(&gfx);
        }
    } else {
        gfx = func_8025D2B4(gfx, arg1, arg3);
    }
    *arg3 += gfx - arg0;
    return gfx;
}

void func_8025CE74(void) {
    D_80366BA0 = (Vtx *)D_80358070;
    D_80358070 += 4 * sizeof(Vtx);
    D_80366BA0[0].v.ob[0] = 0;
    D_80366BA0[0].v.ob[1] = 0;
    D_80366BA0[0].v.ob[2] = 0;
    D_80366BA0[0].v.flag = 0;
    D_80366BA0[0].v.tc[0] = 0;
    D_80366BA0[0].v.tc[1] = 0x9E0;
    D_80366BA0[0].v.cn[0] = 0;
    D_80366BA0[0].v.cn[1] = 0;
    D_80366BA0[0].v.cn[2] = 0;
    D_80366BA0[0].v.cn[3] = 0;
    D_80366BA0[1].v.ob[0] = 0x14;
    D_80366BA0[1].v.ob[1] = 0;
    D_80366BA0[1].v.ob[2] = 0;
    D_80366BA0[1].v.flag = 0;
    D_80366BA0[1].v.tc[0] = 0x280;
    D_80366BA0[1].v.tc[1] = 0x9E0;
    D_80366BA0[1].v.cn[0] = 0;
    D_80366BA0[1].v.cn[1] = 0;
    D_80366BA0[1].v.cn[2] = 0;
    D_80366BA0[1].v.cn[3] = 0;
    D_80366BA0[2].v.ob[0] = 0x14;
    D_80366BA0[2].v.ob[1] = 0x4F;
    D_80366BA0[2].v.ob[2] = 0;
    D_80366BA0[2].v.flag = 0;
    D_80366BA0[2].v.tc[0] = 0x280;
    D_80366BA0[2].v.tc[1] = 0;
    D_80366BA0[2].v.cn[0] = 0;
    D_80366BA0[2].v.cn[1] = 0;
    D_80366BA0[2].v.cn[2] = 0;
    D_80366BA0[2].v.cn[3] = 0;
    D_80366BA0[3].v.ob[0] = 0;
    D_80366BA0[3].v.ob[1] = 0x4F;
    D_80366BA0[3].v.ob[2] = 0;
    D_80366BA0[3].v.flag = 0;
    D_80366BA0[3].v.tc[0] = 0;
    D_80366BA0[3].v.tc[1] = 0;
    D_80366BA0[3].v.cn[0] = 0;
    D_80366BA0[3].v.cn[1] = 0;
    D_80366BA0[3].v.cn[2] = 0;
    D_80366BA0[3].v.cn[3] = 0;
    D_80366BA4 = D_80358070;
    D_80358070 += 0x780;
}

void func_8025D0B0(u8 arg0) {
    u32 romAddr;
    s32 size;

    switch (arg0) {
        case 1:
            romAddr = (u32)D_00489E70;
            size = D_0048F5A0 - D_00489E70;
            break;
        case 0:
            romAddr = (u32)D_00487050;
            size = D_00489E70 - D_00487050;
            break;
    }
    func_8028B4C4(romAddr, D_80358070, &size, 0xC, 0, 1);
    D_80366BB0[arg0] = K0_TO_PHYS(D_80358070);
    D_80358070 += size;
}

void func_8025D184(void) {
    if (D_80364A98 & 2) {
        func_8025D0B0(1);
        func_8025D0B0(0);
        D_80366A16 = 0xFF;
        D_80366A12 = 0;
        D_80366A00 = 0xA5;
        D_80366A02 = 0xD;
    } else if (D_80364A98 & 0x40000) {
        D_80366A16 = 0;
        D_80366A12 = 4;
        D_80366A02 = 0x2A;
    } else if (D_80364A98 & 0x10000) {
        D_80366A16 = 0;
        D_80366A12 = 3;
    } else {
        func_8025D0B0(1);
        func_8025D0B0(0);
        D_80366A12 = 3;
        D_80366A14 = 0;
        D_80366A00 = 0x10;
    }
}

Gfx *func_8025D2B4(Gfx *arg0, s32 arg1, s32 *arg2) {
    Gfx *gfx;
    s32 x;
    s32 y;
    s32 xoff;
    s16 yoff;

    gfx = arg0;
    if (D_80364A90 & 0x08040E2110418002) {
        D_80366A14 += 10;
        if (D_80366A14 >= 0x100) {
            D_80366A14 = 0xFF;
        }
    } else if (D_80364A90 & 0x0188004203160000) {
        D_80366A14 -= 10;
        if (D_80366A14 <= 0) {
            D_80366A14 = 0;
        }
    }
    switch (D_80366A12) {
        case 0:
            if (D_80358060 == 60) {
                D_80366A12 = 1;
            }
            break;
        case 1:
            D_80366A16 -= 8;
            if (D_80366A16 < 0) {
                D_80366A16 = 0;
                D_80366A12 = 2;
            }
            break;
        case 2:
            D_80366A00 -= 10;
            if (D_80366A00 <= 0x10) {
                D_80366A00 = 0x10;
                D_80366A12 = 3;
            }
            break;
        case 4:
            if (D_8036BB1C == 2) {
                if (D_80366A16 + 4 > 0x80) {
                    D_80366A16 = 0x80;
                } else {
                    D_80366A16 += 4;
                }
            } else if (D_80364A90 == 0x200000) {
                if (D_80366A16 - 6 < 0) {
                    D_80366A16 = 0;
                } else {
                    D_80366A16 -= 6;
                }
            }
            break;
    }
    gDPPipeSync(gfx++);
    gSPTexture(gfx++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gDPSetTexturePersp(gfx++, G_TP_NONE);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineLERP(gfx++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
    if (D_80364A90 == 2 && D_8036BB1C != 1) {
        if ((yoff = D_80366A00 - (0xFF - D_8039CAA0) / 4) + 63 == D_80366A00) {
            yoff = -100;
        }
    } else {
        yoff = D_80366A00;
    }
    switch (D_80366A12) {
        case 0:
        case 1:
        case 4:
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, D_80366A16);
            xoff = 82;
            for (x = 0; x < 150; x += 31) {
                for (y = 0; y < 150; y += 31) {
                    gDPLoadTextureTile(gfx++, D_80366BB0[1], G_IM_FMT_RGBA, G_IM_SIZ_16b, 156, 0, x, y, x + 31,
                                       y + 31, 0, G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                                       G_TX_NOLOD);
                    gSPTextureRectangle(gfx++, (x + xoff) << 2, (y + D_80366A02) << 2, (x + xoff + 31) << 2,
                                        (y + D_80366A02 + 31) << 2, G_TX_RENDERTILE, x << 5, y << 5, 1 << 10,
                                        1 << 10);
                }
            }
            if (D_80366A12 == 4) {
                break;
            }
            /* fallthrough */
        default:
            gDPPipeSync(gfx++);
            gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0,
                              PRIMITIVE, 0);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, D_80366A14 / 2);
            xoff = 20;
            for (x = 0; x < 272; x += 31) {
                gDPLoadTextureTile(gfx++, D_80366BB0[0], G_IM_FMT_RGBA, G_IM_SIZ_16b, 280, 0, x, 0, x + 31, 63, 0,
                                   G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                gDPPipeSync(gfx++);
                gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
                gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0,
                                  PRIMITIVE, 0);
                gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, D_80366A14 / 2);
                gSPScisTextureRectangle(gfx++, (x + xoff) << 2, (yoff + 6) << 2, (x + xoff + 31) << 2,
                                        (yoff + 69) << 2, G_TX_RENDERTILE, x << 5, 0, 1 << 10, 1 << 10);
                gDPPipeSync(gfx++);
                if (D_80366A14 == 0xFF && (D_80364A90 & 0xC9FD0FE79BFF80B0)) {
                    gDPSetRenderMode(gfx++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
                }
                gDPSetCombineLERP(gfx++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0,
                                  PRIMITIVE, 0);
                gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, D_80366A14);
                gSPScisTextureRectangle(gfx++, (x + xoff) << 2, yoff << 2, (x + xoff + 31) << 2, (yoff + 63) << 2,
                                        G_TX_RENDERTILE, x << 5, 0, 1 << 10, 1 << 10);
            }
            break;
    }
    gDPPipeSync(gfx++);
    gDPSetTexturePersp(gfx++, G_TP_PERSP);
    *arg2 += gfx - arg0;
    return gfx;
}

void func_8025E1E0(Gfx **gfxp) {
    Gfx *gfx;

    gfx = *gfxp;
    gSPMatrix(gfx++, &D_02000000[2], G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPMatrix(gfx++, &D_02000000[5], G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH);
    gSPMatrix(gfx++, &D_02000000[7], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    func_8024FC2C(&gfx, 0);
    func_8024FC2C(&gfx, 1);
    func_8024FC2C(&gfx, 2);
    *gfxp = gfx;
}

void func_8025E2CC(Gfx **gfxp, s32 arg1, s32 arg2) {
    Gfx *gfx;

    gfx = *gfxp;
    if (D_803643D7 != 0 && func_802753C0() == 0) {
        if (D_80366BC0 == 0) {
            func_802C1DD0(D_802E8F94[D_802E8BDC].unk0 == 0x20 || D_802E8F94[D_802E8BDC].unk0 == 0x80);
            D_80366BB8 = 0;
            if ((D_80364AF0[D_80364AE8].unk18[D_802E8BDC] > 0 && D_80364AF0[D_80364AE8].unk18[D_802E8BDC] < 6) ? 1 : 0) {
                func_802609F0();
                func_80260A10();
                D_80366BC2 = 5;
                D_80366BC4 = 0;
                if (D_80364AA8 != 1) {
                    func_80260E2C();
                    D_80366BC4 = 1;
                }
            } else {
                switch (D_802E8BDC) {
                    case 40:
                        func_80260A10();
                        func_80260DFC();
                        D_80366BC2 = 0x1E;
                        D_80366BC4 = 0;
                        break;
                    case 50:
                        func_80260A10();
                        func_80260EE0(0x25);
                        D_80366BC2 = 0x23;
                        D_80366BC4 = 0;
                        break;
                    default:
                        func_80260A10();
                        D_80366BC2 = 5;
                        func_80260E2C();
                        D_80366BC4 = 1;
                        break;
                }
            }
            func_8026AF6C(D_80366BC2 | 0x8000 | 0x2000);
            D_8036BB1A = -1;
            if (D_80366BC2 == 5) {
                func_80260650(D_80367738, func_8026205C(2), NULL);
            }
        }
        D_80366BC0 = D_803643D7;
        if (D_80366BB8 == 0) {
            if (D_8036BB1C == 8 && D_8036BB18 == D_80366BC2) {
                D_80366BB8 = D_803156C4;
                func_80278318();
                func_80277EDC(2, 1, 2, func_8026205C(3));
            }
        } else if (func_802D4E10(D_80367734) == 0 ||
                   (D_80366BC4 != 0 && D_803156C4 - D_80367740 > 480) ||
                   (D_80366BC4 == 0 && D_803156C4 - D_80366BB8 > D_802E8CD0[(D_80364AA8 & 0x81) ? 1 : 0])) {
            func_80275270(0x08000000, 0.75f);
            D_80366BB8 = 0;
            D_80366BC0 = 0;
        }
    }
    *gfxp = gfx;
}

void func_8025E67C(Gfx **gfxp, s32 arg1, u8 arg2) {
    Gfx *gfx;
    u32 now;
    u32 i;
    u32 j;
    s32 unused;
    u32 alpha;

    gfx = *gfxp;
    now = D_803156C4;
    if (D_803643D6 != 0) {
        if (D_803643D8 == 0) {
            func_802609D0();
            func_802C1DD0(D_802E8F94[D_802E8BDC].unk0 == 0x20 || D_802E8F94[D_802E8BDC].unk0 == 0x80);
            switch (D_802E8BDC) {
                case 49:
                    func_80260650(D_80367738, 0x31, NULL);
                    func_80261570(0.0f);
                    break;
                case 50:
                    D_8036BB1A = -1;
                    func_8026AF6C(0xA00E);
                    func_80261570(0.0f);
                    break;
                default:
                    func_80260650(D_80367738, 0x31, NULL);
                    D_802E8BD8 = 1;
                    if (D_8036BB18 != -1 || func_8026B10C() != 0) {
                        func_8026AF6C(0x4000);
                    }
                    D_8036BB1A = -1;
                    func_80261570(0.0f);
                    break;
            }
            D_80366BB8 = now;
            D_80366BC5 = 0;
        }
        if ((i = now - D_80366BB8) >= 180) {
            switch (D_802E8BDC) {
                case 49:
                    if (D_80366BC5 == 0) {
                        func_80260650(D_80367738, 0x32, NULL);
                        D_80366BC5 = 1;
                    }
                    break;
                case 50:
                    if (D_8036BB1C == 1 && func_802753C0() == 0) {
                        if ((D_80364AF0[D_80364AE8].unk18[D_802E8BDC] > 0 && D_80364AF0[D_80364AE8].unk18[D_802E8BDC] < 6) ? 1 : 0) {
                            func_80275390(0x08000000);
                        } else {
                            func_80275390(0x40);
                        }
                    }
                    break;
                default:
                    if (D_80366BC5 == 0) {
                        func_80260650(D_80367738, 0x32, NULL);
                        D_80366BC5 = 1;
                    }
                    gSPMatrix(gfx++, &D_02000000[3], G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
                    gSPMatrix(gfx++, &D_02000000[7], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
                    gDPPipeSync(gfx++);
                    gDPSetRenderMode(gfx++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
                    gDPSetCombineMode(gfx++, G_CC_SHADE, G_CC_SHADE);
                    gSPSetGeometryMode(gfx++, G_SHADE | G_SHADING_SMOOTH);
                    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
                    gSPVertex(gfx++, (u32)D_802FA8B0[arg2] + 0x80000000, 4, 0);
                    gSP1Triangle(gfx++, 0, 1, 2, 0);
                    gSP1Triangle(gfx++, 0, 2, 3, 0);
                    gDPPipeSync(gfx++);
                    if (func_802753C0() == 0) {
                        if (now - D_80366BB8 - 180 < 90) {
                            alpha = (now - D_80366BB8 - 180) * D_80309098;
                            for (i = 0; i < 4; i++) {
                                for (j = 0; j < 4; j++) {
                                    D_802FA8B0[arg2][i].v.cn[j] = alpha;
                                }
                            }
                        } else if (now - D_80366BB8 - 270 >= 46) {
                            if (D_80364A90 == 0x100000000000) {
                                D_80364A98 = 0x200000000000;
                            } else if ((D_80364AF0[D_80364AE8].unk18[D_802E8BDC] > 0 && D_80364AF0[D_80364AE8].unk18[D_802E8BDC] < 6) ? 1 : 0) {
                                func_80275390(0x08000000);
                            } else {
                                func_80275390(0x40);
                            }
                        } else {
                            for (i = 0; i < 4; i++) {
                                for (j = 0; j < 4; j++) {
                                    D_802FA8B0[arg2][i].v.cn[j] = 0xFF;
                                }
                            }
                        }
                    }
                    break;
            }
        }
    }
    *gfxp = gfx;
}

void func_8025EDF0(UnkSndConfig *c) {
    u32 i;
    u8 *ptr;
    UnkSndEvent evt;
    UnkSndState *sState;

    D_802E8CEC->unk48 = c->unk8;
    D_802E8CEC->unk40 = NULL;
    D_802E8CEC->frameTime = 33000;
    ptr = alHeapAlloc(c->heap, 1, c->maxSounds * sizeof(UnkSndState));
    D_802E8CEC->unk44 = (UnkSndState *)ptr;
    ptr = alHeapAlloc(c->heap, 1, c->maxEvents * sizeof(ALEventListItem));
    alEvtqNew(&D_802E8CEC->evtq, (ALEventListItem *)ptr, c->maxEvents);
    D_802E8CE8 = D_802E8CEC->unk44;
    for (i = 1; i < c->maxSounds; i++) {
        sState = D_802E8CEC->unk44;
        alLink((ALLink *)(sState + i), (ALLink *)(sState + i - 1));
    }
    D_80366C28 = alHeapAlloc(c->heap, 2, c->unk10);
    for (i = 0; i < c->unk10; i++) {
        D_80366C28[i] = 0x7FFF;
    }
    D_802E8CEC->drvr = &alGlobals->drvr;
    D_802E8CEC->node.next = NULL;
    D_802E8CEC->node.handler = func_8025F044;
    D_802E8CEC->node.clientData = D_802E8CEC;
    alSynAddPlayer(D_802E8CEC->drvr, &D_802E8CEC->node);
    evt.type = 0x20;
    alEvtqPostEvent(&D_802E8CEC->evtq, (ALEvent *)&evt, D_802E8CEC->frameTime);
    D_802E8CEC->nextDelta = alEvtqNextEvent(&D_802E8CEC->evtq, &D_802E8CEC->nextEvent);
}

ALMicroTime func_8025F044(void *node) {
    UnkSndPlayer *sndp = (UnkSndPlayer *)node;
    UnkSndEvent evt;

    do {
        switch (sndp->nextEvent.type) {
            case 0x20:
                evt.type = 0x20;
                alEvtqPostEvent(&sndp->evtq, (ALEvent *)&evt, sndp->frameTime);
                break;
            default:
                func_8025F0F0(sndp, (UnkSndEvent *)&sndp->nextEvent);
                break;
        }
        sndp->nextDelta = alEvtqNextEvent(&sndp->evtq, &sndp->nextEvent);
    } while (sndp->nextDelta == 0);
    sndp->curTime += sndp->nextDelta;
    return sndp->nextDelta;
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/17E10/func_8025F0F0.s")

void func_8026005C(UnkSndState *state) {
    if (state->unk3E & 4) {
        alSynStopVoice(D_802E8CEC->drvr, &state->voice);
        alSynFreeVoice(D_802E8CEC->drvr, &state->voice);
    }
    func_802604FC(state);
    func_80260148(&D_802E8CEC->evtq, state, 0xFFFF);
}

void func_802600D8(UnkSndState *state) {
    UnkSndEvent evt;
    f32 pitch;

    pitch = alCents2Ratio(state->sound->keyMap->detune) * state->pitch;
    evt.type = 0x10;
    evt.state = state;
    evt.param = *(s32 *)&pitch;
    alEvtqPostEvent(&D_802E8CEC->evtq, (ALEvent *)&evt, 0x8235);
}

void func_80260148(ALEventQueue *evtq, UnkSndState *state, u16 eventType) {
    ALLink *thisNode;
    ALLink *nextNode;
    ALEventListItem *thisItem;
    ALEventListItem *nextItem;
    UnkSndEvent *thisEvent;
    OSIntMask mask;

    mask = osSetIntMask(OS_IM_NONE);
    thisNode = evtq->allocList.next;
    while (thisNode != NULL) {
        nextNode = thisNode->next;
        thisItem = (ALEventListItem *)thisNode;
        nextItem = (ALEventListItem *)nextNode;
        thisEvent = (UnkSndEvent *)&thisItem->evt;
        if (thisEvent->state == state && (thisEvent->type & eventType)) {
            if (nextItem != NULL) {
                nextItem->delta += thisItem->delta;
            }
            alUnlink(thisNode);
            alLink(thisNode, &evtq->freeList);
        }
        thisNode = nextNode;
    }
    osSetIntMask(mask);
}

u16 func_80260210(u16 *arg0, u16 *arg1) {
    OSIntMask mask;
    u16 count1;
    u16 count2;
    u16 count3;
    UnkSndState *p1;
    UnkSndState *p2;
    UnkSndState *p3;

    mask = osSetIntMask(OS_IM_NONE);
    count1 = 0;
    p1 = D_802E8CE0;
    p2 = D_802E8CE8;
    p3 = D_802E8CE4;
    if (p1 != NULL) {
        do {
            count1++;
        } while ((p1 = (UnkSndState *)p1->node.next) != NULL);
    }
    count2 = 0;
    if (p2 != NULL) {
        do {
            count2++;
        } while ((p2 = (UnkSndState *)p2->node.next) != NULL);
    }
    count3 = 0;
    if (p3 != NULL) {
        do {
            count3++;
        } while ((p3 = (UnkSndState *)p3->node.prev) != NULL);
    }
    *arg0 = count2;
    *arg1 = count1;
    osSetIntMask(mask);
    return count3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/17E10/func_80260300.s")

void func_802604FC(UnkSndState *state) {
    if (D_802E8CE0 == state) {
        D_802E8CE0 = (UnkSndState *)state->node.next;
    }
    if (D_802E8CE4 == state) {
        D_802E8CE4 = (UnkSndState *)state->node.prev;
    }
    alUnlink(&state->node);
    if (D_802E8CE8 != NULL) {
        state->node.next = &D_802E8CE8->node;
        state->node.prev = NULL;
        D_802E8CE8->node.prev = &state->node;
        D_802E8CE8 = state;
    } else {
        state->node.next = state->node.prev = NULL;
        D_802E8CE8 = state;
    }
    if (state->unk3E & 4) {
        D_802E8CF0--;
    }
    state->unk3F = 0;
    if (state->unk30 != NULL) {
        if (*state->unk30 == state) {
            *state->unk30 = NULL;
        }
        state->unk30 = NULL;
    }
}

void func_80260618(UnkSndState *state, u8 arg1) {
    if (state != NULL) {
        state->unk36 = (s16)arg1;
    }
}

u8 func_80260634(UnkSndState *state) {
    if (state != NULL) {
        return state->unk3F;
    }
    return 0;
}

UnkSndState *func_80260650(UnkSndBank *bank, s16 id, UnkSndState **handle) {
    UnkSndState *state;
    UnkSndState *result;
    ALKeyMap *keyMap;
    ALSound *sound;
    s16 firstId;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    UnkSndEvent evt;
    UnkSndEvent evt2;

    result = NULL;
    firstId = 0;
    sp38 = 0;
    if (id == 0 || (D_80358060 == 0 && id == 0xC) ||
        ((id == 0x14 || id == 0x15) && (D_802E8BDC == 0x26 || D_802E8BDC == 0x31))) {
        return NULL;
    }
    do {
        sound = bank->unkC->soundArray[id];
        state = func_80260300(bank, sound);
        if (state != NULL) {
            D_802E8CEC->unk40 = state;
            evt.type = 1;
            evt.state = state;
            sp3C = sound->keyMap->velocityMax * 33333;
            if (state->unk3E & 0x10) {
                state->unk3E &= ~0x10;
                alEvtqPostEvent(&D_802E8CEC->evtq, (ALEvent *)&evt, sp38 + 1);
                sp40 = sp3C + 1;
                firstId = id;
            } else {
                alEvtqPostEvent(&D_802E8CEC->evtq, (ALEvent *)&evt, sp3C + 1);
            }
            result = state;
        } else {
            func_8029A7E4(D_80309124, id);
        }
        sp38 += sp3C;
        keyMap = sound->keyMap;
        id = keyMap->velocityMin + (keyMap->keyMin & 0xC0) * 4;
    } while (id != 0 && state != NULL);
    if (result != NULL) {
        result->unk3E |= 1;
        result->unk30 = handle;
        if (firstId != 0) {
            result->unk3E |= 0x10;
            evt2.type = 0x200;
            evt2.state = result;
            evt2.param = firstId;
            evt2.unkC = bank;
            alEvtqPostEvent(&D_802E8CEC->evtq, (ALEvent *)&evt2, sp40);
        }
    }
    if (handle != NULL) {
        *handle = result;
    }
    return result;
}

void func_802608C8(UnkSndState *state) {
    UnkSndEvent evt;

    evt.type = 0x400;
    evt.state = state;
    if (state != NULL) {
        state->unk3E &= ~0x10;
        alEvtqPostEvent(&D_802E8CEC->evtq, (ALEvent *)&evt, 0);
    } else {
        func_8029A7E4(D_8030914C);
    }
}

void func_80260934(u8 arg0) {
    OSIntMask mask;
    UnkSndEvent evt;
    UnkSndState *state;

    mask = osSetIntMask(OS_IM_NONE);
    state = D_802E8CE0;
    while (state != NULL) {
        evt.type = 0x400;
        evt.state = state;
        if ((state->unk3E & arg0) == arg0) {
            state->unk3E &= ~0x10;
            alEvtqPostEvent(&D_802E8CEC->evtq, (ALEvent *)&evt, 0);
        }
        state = (UnkSndState *)state->node.next;
    }
    osSetIntMask(mask);
}

void func_802609D0(void) {
    func_80260934(1);
}

void func_802609F0(void) {
    func_80260934(0x11);
}

void func_80260A10(void) {
    func_80260934(3);
}

void func_80260A30(u8 arg0) {
    OSIntMask mask;
    UnkSndState *state;
    s32 i;

    mask = osSetIntMask(OS_IM_NONE);
    i = 0;
    state = D_802E8CE0;
    if (state != NULL) {
        do {
            if ((state->sound->keyMap->keyMin & 0x3F) == arg0) {
                func_802608C8(state);
            }
            i++;
        } while ((state = (UnkSndState *)state->node.next) != NULL);
    }
    osSetIntMask(mask);
}

void func_80260AB8(UnkSndState *state, s16 type, s32 param) {
    UnkSndEvent evt;

    evt.type = type;
    evt.state = state;
    evt.param = param;
    if (state != NULL) {
        alEvtqPostEvent(&D_802E8CEC->evtq, (ALEvent *)&evt, 0);
    } else {
        func_8029A7E4(D_8030917C);
    }
}

u16 func_80260B24(u8 arg0) {
    return D_80366C28[arg0];
}

void func_80260B40(u8 arg0, u16 arg1) {
    OSIntMask mask;
    UnkSndState *state;
    s32 i;
    UnkSndEvent evt;

    mask = osSetIntMask(OS_IM_NONE);
    state = D_802E8CE0;
    D_80366C28[arg0] = arg1;
    i = 0;
    while (state != NULL) {
        if ((state->sound->keyMap->keyMin & 0x3F) == arg0) {
            evt.type = 0x800;
            evt.state = state;
            alEvtqPostEvent(&D_802E8CEC->evtq, (ALEvent *)&evt, 0);
        }
        i++;
        state = (UnkSndState *)state->node.next;
    }
    osSetIntMask(mask);
}
