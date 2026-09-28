#include "common.h"


extern Mtx D_02000000[];
extern u16 D_802FCEB0[];
extern Vtx D_802FD9B8[];
extern f64 D_8030C7F0;
extern f64 D_8030C7F8;
extern f64 D_8030C800;
extern f64 D_8030C808;
extern f64 D_8030C810;
extern f64 D_8030C818;
extern f32 D_8030C820;
extern f32 D_8030C824;
extern u32 D_803156C4;
extern u16 D_8035807C;
extern s16 D_80364452;
extern s16 D_80367BD6;
extern s32 D_803F7660;
extern s32 D_803F7670;
extern s32 D_803F7678;

extern u16 D_802FC5B0[];
extern u16 D_802FC6B0[];
extern u8 D_802FD6B0[];
extern Vtx D_802FD7B0[];
extern Vtx D_802FD7F0[];
extern Vtx D_802FD830[][12];
extern f32 D_802FD9B0;
extern u8 D_803643DB;
extern f32 D_80364414;
extern Mtx D_8036E5E0[];
extern s16 D_803F767C;
extern s16 D_803F7680;

s32 func_802AD7D4(s32);
s32 func_8026A610(s32, s32, s32, s32);
void func_802C1B9C(void);
f32 func_80284ADC();

/* Nearly matches; IDO reloads the operands of the second (arg7 - pz) in the second sqrtf. */
#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/3E4C0/func_80282C80.s")

void func_8028376C(Gfx **arg0, Mtx *arg1, u8 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    Gfx *gfx = *arg0;
    s32 dist;
    u8 shift;
    s32 scale;
    s16 x;
    s16 y;
    s16 px;
    s16 py;
    Mtx sp1C8;
    f32 sp188[4][4];
    f32 sp148[4][4];
    f32 ox;
    f32 oy;
    f32 oz;
    f32 angle;

    dist = func_8026A610(arg3, arg4, arg5, arg6);
    if (dist < 0x55F0) {
        shift = 10;
        scale = 1200;
    }
    if (dist >= 0x55F0 && dist < 0xABE0) {
        shift = 0;
        scale = 2400;
    }
    if (dist >= 0xABE0) {
        shift = 15;
        scale = 4800;
    }
    if (D_803643DB == 0) {
        shift = 10;
        scale = 1200;
    }
    guRotateF(sp188, 360.0 - (D_80364414 - 180.0), 0.0f, 1.0f, 0.0f);
    guMtxXFMF(sp188, (arg3 - arg5) / scale, 0.0f, (arg4 - arg6) / scale, &ox, &oy, &oz);
    x = 58.0f + ox;
    y = 195.0f + oz;
    D_802FD830[arg2][0].v.ob[0] = x - 2;
    D_802FD830[arg2][0].v.ob[1] = y - 2;
    D_802FD830[arg2][1].v.ob[0] = x - 2;
    D_802FD830[arg2][1].v.ob[1] = y + 1;
    D_802FD830[arg2][2].v.ob[0] = x + 1;
    D_802FD830[arg2][2].v.ob[1] = y + 1;
    D_802FD830[arg2][3].v.ob[0] = x + 1;
    D_802FD830[arg2][3].v.ob[1] = y - 2;
    func_802C1B9C();
    guMtxXFMF(sp188, (arg3 - D_803F7670) / scale, 0.0f, (arg4 - D_803F7678) / scale, &ox, &oy, &oz);
    px = 58.0f + ox;
    py = 195.0f + oz;
    D_802FD830[arg2][4].v.ob[0] = px - 2;
    D_802FD830[arg2][4].v.ob[1] = py - 2;
    D_802FD830[arg2][5].v.ob[0] = px - 2;
    D_802FD830[arg2][5].v.ob[1] = py + 1;
    D_802FD830[arg2][6].v.ob[0] = px + 1;
    D_802FD830[arg2][6].v.ob[1] = py + 1;
    D_802FD830[arg2][7].v.ob[0] = px + 1;
    D_802FD830[arg2][7].v.ob[1] = py - 2;
    gSPMatrix(gfx++, &D_02000000[3], G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPMatrix(gfx++, &D_02000000[7], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
    gSPSetGeometryMode(gfx++, G_SHADE | G_SHADING_SMOOTH);
    gDPPipeSync(gfx++);
    gDPSetTextureLOD(gfx++, G_TL_TILE);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTextureImage(gfx++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, OS_K0_TO_PHYSICAL(D_802FC5B0));
    gDPSetTile(gfx++, G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, 0, 0, 0, 0, 0, 0);
    gDPLoadSync(gfx++);
    gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, 0, 0x7F, 0x400);
    gDPSetTextureImage(gfx++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, OS_K0_TO_PHYSICAL(D_802FC6B0));
    gDPTileSync(gfx++);
    gDPSetTile(gfx++, G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0x100, G_TX_LOADTILE, 0, 0, 0, 0, 0, 0, 0);
    gDPLoadSync(gfx++);
    gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, 0, 0x3FF, 0x200);
    gDPSetTile(gfx++, G_IM_FMT_IA, G_IM_SIZ_8b, 2, 0, G_TX_RENDERTILE, 0, G_TX_MIRROR, 4, G_TX_NOLOD, G_TX_MIRROR, 4,
               G_TX_NOLOD);
    gDPSetTileSize(gfx++, G_TX_RENDERTILE, 2, 2, 0x3E, 0x3E);
    gDPSetTile(gfx++, G_IM_FMT_IA, G_IM_SIZ_4b, 4, 0x100, G_TX_RENDERTILE + 1, 0, G_TX_MIRROR, 6, shift, G_TX_MIRROR,
               6, shift);
    gDPSetTileSize(gfx++, G_TX_RENDERTILE + 1, 2, 2, 0xFC, 0xFC);
    gDPSetCycleType(gfx++, G_CYC_2CYCLE);
    gDPSetRenderMode(gfx++, G_RM_PASS, G_RM_CLD_SURF2);
    gDPSetCombineLERP(gfx++, PRIMITIVE, SHADE, TEXEL1_ALPHA, SHADE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0,
                      0, COMBINED);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, (D_80367BD6 < 0x3F) ? D_80367BD6 : 0x3F);
    gSPVertex(gfx++, osVirtualToPhysical(D_802FD7B0), 4, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);
    gSP1Triangle(gfx++, 0, 2, 3, 0);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetCombineLERP(gfx++, 0, 0, 0, SHADE, 0, 0, 0, PRIMITIVE, 0, 0, 0, SHADE, 0, 0, 0, PRIMITIVE);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, D_80367BD6);
    if (D_803643DB != 0) {
        gDPSetRenderMode(gfx++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
        if ((D_803156C4 % 40 > 20 || shift != 10) && x >= 0x22 && x < 0x53 && y >= 0xAB && y < 0xDC) {
            gSPVertex(gfx++, osVirtualToPhysical(D_802FD830[arg2]), 4, 0);
            gSP1Triangle(gfx++, 0, 1, 2, 0);
            gSP1Triangle(gfx++, 0, 2, 3, 0);
        }
        if (px >= 0x22 && px < 0x53 && py >= 0xB0 && py < 0xD7 && D_803F7660 != 9999999) {
            gSPVertex(gfx++, osVirtualToPhysical(&D_802FD830[arg2][4]), 4, 0);
            gSP1Triangle(gfx++, 0, 1, 2, 0);
            gSP1Triangle(gfx++, 0, 2, 3, 0);
        }
    }
    angle = func_80284ADC(arg3 >> 5, arg4 >> 5, D_803F767C, D_803F7680);
    guRotateF(sp188, -((360.0 - (D_80364414 - 180.0)) + (angle + 180.0)), 0.0f, 0.0f, 1.0f);
    guTranslateF(sp148, 58.0f, 195.0f, 0.0f);
    guMtxCatF(sp188, sp148, sp188);
    guMtxF2L(sp188, &D_8036E5E0[arg2]);
    gDPPipeSync(gfx++);
    if (D_80367BD6 == 0xFF) {
        gDPSetRenderMode(gfx++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
    } else {
        gDPSetRenderMode(gfx++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    }
    gSPMatrix(gfx++, osVirtualToPhysical(&D_8036E5E0[arg2]), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    gSPVertex(gfx++, osVirtualToPhysical(&D_802FD830[arg2][8]), 4, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);
    gSP1Triangle(gfx++, 0, 2, 3, 0);
    gSPPopMatrix(gfx++, G_MTX_MODELVIEW);
    if (D_803643DB != 0) {
        gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gDPSetRenderMode(gfx++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
        gDPSetCombineLERP(gfx++, 0, 0, 0, SHADE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, SHADE, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, (D_80367BD6 >= 0x80) ? 0x7F : D_80367BD6);
        gDPLoadTextureBlock(gfx++, OS_K0_TO_PHYSICAL(D_802FD6B0), G_IM_FMT_IA, G_IM_SIZ_8b, 8, 32, 0, G_TX_CLAMP,
                            G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        guRotate(&arg1[23], D_802FD9B0, 0.0f, 0.0f, 1.0f);
        guTranslate(&sp1C8, 58.0f, 195.0f, 0.0f);
        guMtxCatL(&arg1[23], &sp1C8, &arg1[23]);
        D_802FD9B0 += 4.0;
        gSPMatrix(gfx++, &D_02000000[23], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
        gSPVertex(gfx++, osVirtualToPhysical(D_802FD7F0), 4, 0);
        gSP1Triangle(gfx++, 0, 1, 2, 0);
        gSP1Triangle(gfx++, 1, 2, 3, 0);
    }
    gDPPipeSync(gfx++);
    *arg0 = gfx;
}

/* K&R definition: callers pass the coordinates as ints. */
f32 func_80284ADC(arg0, arg1, arg2, arg3)
    s16 arg0;
    s16 arg1;
    s16 arg2;
    s16 arg3;
{
    f32 dist;

    dist = sqrtf((arg2 - arg0) * (arg2 - arg0) + (arg3 - arg1) * (arg3 - arg1));
    if (dist < 1.0) {
        return 0.0f;
    }
    if (arg2 >= arg0 && arg3 >= arg1) {
        return func_802AD7D4((arg2 - arg0) * 65535.9 / dist) / 65536.0 * 360.0;
    }
    if (arg2 >= arg0 && arg3 < arg1) {
        return (func_802AD7D4((arg1 - arg3) * 65535.9 / dist) + 0x4000) / 65536.0 * 360.0;
    }
    if (arg2 < arg0 && arg3 < arg1) {
        return (func_802AD7D4((arg0 - arg2) * 65535.9 / dist) + 0x8000) / 65536.0 * 360.0;
    }
    if (arg2 < arg0 && arg3 >= arg1) {
        return (func_802AD7D4((arg3 - arg1) * 65535.9 / dist) + 0xC000) / 65536.0 * 360.0;
    }
}
