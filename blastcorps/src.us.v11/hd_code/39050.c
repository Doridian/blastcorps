#include "common.h"

typedef struct {
    /* 0x00 */ u8 unk0[0x5C];
    /* 0x5C */ s32 unk5C;
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ s32 unk70;
} UnkStruct_80364460; /* size = 0x74 */

extern s32 D_802FC51C;
extern f64 D_8030C750;
extern f64 D_8030C758;
extern UnkStruct_80364460 D_80364460[];
extern UnkStruct_80364460 *D_803649D0;
extern s32 D_803649E8;

f32 func_8027DB5C(s32 *arg0, s32 *arg1, s32 arg2);
f32 func_8027DD88(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3);
s32 func_8027E164(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3);
f32 func_8027E228(s32);
s16 *func_802C1EE0(s32);
void func_802C1F30(s32, s32, s32, s32, s32);
s32 func_802AC4C4(s32, s32, s32, s32, s32, s32, s32, s32);

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ u8 unk12[2];
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ u8 unk24;
    /* 0x25 */ u8 unk25;
    /* 0x26 */ s16 unk26;
    /* 0x28 */ u8 unk28[9];
    /* 0x31 */ u8 unk31;
    /* 0x32 */ u8 unk32[2];
} UnkStruct_802FC3F0; /* size = 0x34 */

extern UnkStruct_802FC3F0 D_802FC3F0[];
extern s16 D_802FC48C[];
extern u8 *D_80358070;
extern Vtx *D_8036DCA0[];
extern Vtx *D_8036DCA8[2];
extern s32 D_8036DCB0;
extern u8 *D_8036DCB8[3];
extern u8 *D_8036DCC8[2];
extern u8 D_8036DCD0;
extern s16 D_8036DCD2;
extern u8 D_8036DCD4;
extern u8 D_8036DCD5;
extern u8 D_8036DCD6;
extern u8 D_8036DCD7;
extern u8 D_802E8BD0;

s32 func_802A0CC8(s32, s32);

/* 0x50-byte records: a position and the four vertices of a quad placed there. */
typedef struct {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ u8 unk6[2];
    /* 0x08 */ Vtx unk8[4];
    /* 0x48 */ u8 unk48;
    /* 0x49 */ u8 unk49[7];
} UnkStruct_8036E380; /* size = 0x50 */

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
} UnkStruct_802FC520; /* size = 0x8 */

extern UnkStruct_802FC520 D_802FC520[];
extern Vtx D_802FC528[];
extern s32 D_803643E0;
extern s32 D_803643E4;
extern s32 D_803643E8;
extern s32 D_80367738;
extern s32 D_8036DCD8;
extern UnkStruct_8036E380 D_8036E380[];
extern s32 D_8036E4C0;
extern u8 *D_8036E4C4;
extern s16 D_8036E4C8;
extern u8 D_8036E4CA;
extern u8 *D_8036E4CC;
extern s16 D_8036E4D0;
extern u8 D_8036E4D2;
extern u8 D_8036E4D3;
extern u32 D_8036E4D4;
extern Vtx D_802FC568[];
extern s16 D_80367BD6;
/* Segment 2 base, reached through a relocation, not a constant. */
extern Mtx D_02000000[];
extern Gfx D_802FFF38[];
extern Gfx D_80300A68[];
extern f32 D_8030C7D8;
extern f64 D_8030C7E0;
extern f32 D_8030C7E8;
extern f32 D_8030C7EC;
extern u32 D_803156C4;
extern u8 D_803643D6;
extern Mtx D_8036E4D8[][2];
extern f32 D_8036E5D8[];
extern s32 D_803EF6DC;
extern s32 D_803EF6E0;
extern s32 D_803EF6E4;
extern u8 D_803EF6FF;

void func_8026A5CC(u64 *dst, u64 *src, s32 size);
s32 func_8026A6F0(s32, s32, s32, s32, s32, s32);
void func_80260650(s32, s32, s32 *);
void func_802A0B00(u16, s32);
s32 func_8029DBF0(u8);
void func_802AC1A0(s32);

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/39050/func_8027D810.s")

void func_8027D8F4(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 j;
    f32 step;
    f32 s;
    f32 angle;

    j = 1;
    step = D_8030C750 / (arg1 + 1);
    angle = D_802FC51C / 20.0;
    for (i = D_802FC51C; i < arg1 + D_802FC51C; i++) {
        s = sinf(angle);
        func_802C1F30(arg0, j++, 0, -s * arg2, 0);
        angle += step;
    }
    D_802FC51C++;
}

void func_8027DA10(s32 arg0, s32 arg1, s32 arg2) {
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    s32 i;
    s16 *sp54;
    s32 pad[5];
    s32 sp30[4];
    s32 sp20[4];

    sp54 = func_802C1EE0(arg0);
    for (i = 0; i < 4; i++) {
        sp30[i] = sp54[i * 2] << 5;
        sp20[i] = sp54[i * 2 + 1] << 5;
    }
    sp64 = func_8027DB5C(sp30, sp20, arg2);
    i = 0;
    sp5C = D_8030C758 / (arg1 + 1);
    for (; i < arg1; i++) {
        sp60 = sinf((i + 1) * sp5C);
        func_802C1F30(arg0, i + 1, 0, -sp60 * sp64, 0);
    }
}

f32 func_8027DB5C(s32 *arg0, s32 *arg1, s32 arg2) {
    s32 i;
    f32 max;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    s32 sp18;

    i = 0;
    max = 0.0f;
    while (&D_80364460[i] != D_803649D0) {
        if ((sp18 = D_80364460[i].unk5C) != 0xFE && (sp18 != 0 || D_803649E8 == 0)) {
            if (func_8027E164(D_80364460[i].unk64, D_80364460[i].unk6C, arg0, arg1) != 0) {
                if (D_80364460[i].unk70 != 0) {
                    sp1C = func_8027DD88(D_80364460[i].unk64, D_80364460[i].unk6C, arg0, arg1);
                    if (sp1C <= 0.5) {
                        sp1C = sp1C * 2.0;
                    } else {
                        sp1C = (1.0 - sp1C) * 2.0;
                    }
                    sp20 = func_8027E228(D_80364460[i].unk5C);
                    sp24 = sp1C * sp20;
                    if (max < sp24) {
                        max = sp24;
                    }
                }
            }
        }
        i++;
    }
    return arg2 * max;
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/39050/func_8027DD88.s")

s32 func_8027E164(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    if (func_802AC4C4(arg0, arg1, arg2[0], arg3[0], arg2[1], arg3[1], arg2[2], arg3[2]) != 0) {
        return 1;
    }
    if (func_802AC4C4(arg0, arg1, arg2[0], arg3[0], arg2[2], arg3[2], arg2[3], arg3[3]) != 0) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/39050/func_8027E228.s")

void func_8027E344(s32 arg0) {
    s32 dx;
    s32 dz;
    s32 x;
    s32 z;
    s32 i;
    s32 j;
    s32 n;
    s32 t;
    s32 sp24;
    s32 size;
    u8 found;

    n = 0;
    t = 0;
    sp24 = 0;
    found = 0;
    D_8036DCD6 = 0;
    do {
        if (D_802FC3F0[D_8036DCD6].unk0 == arg0) {
            found = 1;
        } else {
            D_8036DCD6++;
        }
    } while (!found && D_8036DCD6 < 3);
    if (!found) {
        D_8036DCD4 = 0;
        return;
    }
    D_8036DCD4 = 1;
    D_8036DCA0[0] = (Vtx *)D_80358070;
    D_80358070 += (D_802FC3F0[D_8036DCD6].unk1 + 1) * (D_802FC3F0[D_8036DCD6].unk2 + 1) * sizeof(Vtx);
    D_8036DCA0[1] = (Vtx *)D_80358070;
    D_8036DCA8[0] = (Vtx *)(D_80358070 += (D_802FC3F0[D_8036DCD6].unk1 + 1) * (D_802FC3F0[D_8036DCD6].unk2 + 1) * sizeof(Vtx));
    D_8036DCA8[1] = (Vtx *)(D_80358070 += 0x12C0);
    D_80358070 += 0x12C0;
    size = D_802FC3F0[D_8036DCD6].unk1 * D_802FC3F0[D_8036DCD6].unk2 * 2 * 8;
    size += ((D_802FC3F0[D_8036DCD6].unk1 / 8) + 1) * D_802FC3F0[D_8036DCD6].unk2 * 8;
    size += 0x1C20;
    D_8036DCC8[0] = D_80358070;
    D_8036DCC8[1] = D_80358070 += size;
    D_80358070 += size;
    D_8036DCD7 = D_802FC3F0[D_8036DCD6].unk31;
    if (D_8036DCD5 = D_802FC3F0[D_8036DCD6].unk24) {
        D_8036DCB8[0] = D_80358070;
        func_802A0CC8(D_802FC3F0[D_8036DCD6].unk26, 0);
    } else {
        for (i = 0; i < 3; i++) {
            D_8036DCB8[i] = D_80358070;
            func_802A0CC8(D_802FC48C[i], 0);
        }
    }
    D_8036DCD0 = 0;
    D_8036DCD2 = 0;
    dx = (D_802FC3F0[D_8036DCD6].unk8 - D_802FC3F0[D_8036DCD6].unk4) / D_802FC3F0[D_8036DCD6].unk1;
    dz = (D_802FC3F0[D_8036DCD6].unkA - D_802FC3F0[D_8036DCD6].unk6) / D_802FC3F0[D_8036DCD6].unk2;
    x = D_802FC3F0[D_8036DCD6].unk4;
    z = D_802FC3F0[D_8036DCD6].unk6;
    for (i = 0; i <= D_802FC3F0[D_8036DCD6].unk2; i++) {
        sp24 = 0;
        for (j = 0; j <= D_802FC3F0[D_8036DCD6].unk1; j++) {
            D_8036DCA0[0][n].v.ob[0] = x;
            D_8036DCA0[0][n].v.ob[2] = z;
            D_8036DCA0[1][n].v.ob[0] = x;
            D_8036DCA0[1][n].v.ob[2] = z;
            D_8036DCA0[0][n].v.tc[0] = t << 5;
            D_8036DCA0[0][n].v.tc[1] = sp24 << 5;
            D_8036DCA0[1][n].v.tc[0] = t << 5;
            D_8036DCA0[1][n].v.tc[1] = sp24 << 5;
            sp24 ^= 0x1F;
            n++;
            x += dx;
        }
        t ^= 0x1F;
        x = D_802FC3F0[D_8036DCD6].unk4;
        z += dz;
    }
    D_8036DCB0 = 0;
}

void func_8027E9B8(u8 arg0) {
    s32 i;
    s32 j;
    s32 dx;
    s32 dz;
    register f32 s;

    if (D_8036DCD4 != 0 && D_802E8BD0 == 0) {
        D_8036DCB0++;
        D_8036DCD2 += 0xF;
        if (D_8036DCD2 >= 0xFF) {
            D_8036DCD2 = 0;
            D_8036DCD0++;
            if (D_8036DCD0 >= 3) {
                D_8036DCD0 = 0;
            }
        }
    }
    if (D_8036DCD4 != 0) {
        dx = (D_802FC3F0[D_8036DCD6].unk8 - D_802FC3F0[D_8036DCD6].unk4) / D_802FC3F0[D_8036DCD6].unk1;
        for (i = 0; i <= D_802FC3F0[D_8036DCD6].unk1; i++) {
            for (j = 0; j <= D_802FC3F0[D_8036DCD6].unk2; j++) {
                s = sinf((f32)((i + 1) * dx) / D_802FC3F0[D_8036DCD6].unk1C +
                         (f32)D_8036DCB0 / D_802FC3F0[D_8036DCD6].unk14);
                D_8036DCA0[arg0][i + j * (D_802FC3F0[D_8036DCD6].unk2 + 1)].v.ob[1] =
                    D_802FC3F0[D_8036DCD6].unkE * s + D_802FC3F0[D_8036DCD6].unkC;
            }
        }
        dz = (D_802FC3F0[D_8036DCD6].unkA - D_802FC3F0[D_8036DCD6].unk6) / D_802FC3F0[D_8036DCD6].unk2;
        for (i = 0; i <= D_802FC3F0[D_8036DCD6].unk2; i++) {
            for (j = 0; j <= D_802FC3F0[D_8036DCD6].unk1; j++) {
                s = sinf((f32)((i + 1) * dz) / D_802FC3F0[D_8036DCD6].unk20 +
                         (f32)D_8036DCB0 / D_802FC3F0[D_8036DCD6].unk18);
                D_8036DCA0[arg0][(D_802FC3F0[D_8036DCD6].unk2 + 1) * i + j].v.ob[1] =
                    D_802FC3F0[D_8036DCD6].unk10 * s +
                    D_8036DCA0[arg0][(D_802FC3F0[D_8036DCD6].unk2 + 1) * i + j].v.ob[1];
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/39050/func_8027EED8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/39050/func_8027F1F8.s")

void func_802802D4(Vtx *arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 a[3];
    f32 b[3];
    f32 pad[3];
    f32 scale;
    f32 nx;
    f32 ny;
    f32 nz;
    f32 len;

    a[0] = arg0[arg3].v.ob[0] - arg0[arg1].v.ob[0];
    a[1] = arg0[arg3].v.ob[1] - arg0[arg1].v.ob[1];
    a[2] = arg0[arg3].v.ob[2] - arg0[arg1].v.ob[2];
    b[0] = arg0[arg2].v.ob[0] - arg0[arg1].v.ob[0];
    b[1] = arg0[arg2].v.ob[1] - arg0[arg1].v.ob[1];
    b[2] = arg0[arg2].v.ob[2] - arg0[arg1].v.ob[2];
    nx = a[1] * b[2] - a[2] * b[1];
    ny = a[2] * b[0] - a[0] * b[2];
    nz = a[0] * b[1] - a[1] * b[0];
    len = sqrtf(nx * nx + ny * ny + nz * nz);
    if (len < 1.0) {
        len = 1.0f;
    }
    scale = 120.0 / len;
    nx *= scale;
    ny *= scale;
    nz *= scale;
    arg0[arg1].v.cn[0] = (s8)nx;
    arg0[arg1].v.cn[1] = (s8)ny;
    arg0[arg1].v.cn[2] = (s8)nz;
    arg0[arg1].v.cn[3] = 0;
    arg0[arg2].v.cn[0] = (s8)nx;
    arg0[arg2].v.cn[1] = (s8)ny;
    arg0[arg2].v.cn[2] = (s8)nz;
    arg0[arg2].v.cn[3] = 0;
    arg0[arg3].v.cn[0] = (s8)nx;
    arg0[arg3].v.cn[1] = (s8)ny;
    arg0[arg3].v.cn[2] = (s8)nz;
    arg0[arg3].v.cn[3] = 0;
}

void func_8028072C(Vtx *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6) {
    arg0[0].v.ob[0] = arg1;
    arg0[0].v.ob[1] = arg2;
    arg0[0].v.ob[2] = arg3;
    arg0[1].v.ob[0] = arg1;
    arg0[1].v.ob[1] = arg5;
    arg0[1].v.ob[2] = arg3;
    arg0[2].v.ob[0] = arg4;
    arg0[2].v.ob[1] = arg2;
    arg0[2].v.ob[2] = arg3;
    arg0[3].v.ob[0] = arg4;
    arg0[3].v.ob[1] = arg5;
    arg0[3].v.ob[2] = arg3;
    arg0[4].v.ob[0] = arg1;
    arg0[4].v.ob[1] = arg2;
    arg0[4].v.ob[2] = arg6;
    arg0[5].v.ob[0] = arg1;
    arg0[5].v.ob[1] = arg5;
    arg0[5].v.ob[2] = arg6;
    arg0[6].v.ob[0] = arg4;
    arg0[6].v.ob[1] = arg2;
    arg0[6].v.ob[2] = arg6;
    arg0[7].v.ob[0] = arg4;
    arg0[7].v.ob[1] = arg5;
    arg0[7].v.ob[2] = arg6;
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/39050/func_802807D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/39050/func_80280F34.s")

void func_80281A70(s32 arg0) {
    s32 i;
    s32 j;

    D_8036E4C0 = 0;
    for (i = 0; i < 1; i++) {
        if (D_802FC520[i].unk0 == arg0) {
            D_8036E380[D_8036E4C0].unk0 = D_802FC520[i].unk2;
            D_8036E380[D_8036E4C0].unk2 = D_802FC520[i].unk4;
            D_8036E380[D_8036E4C0].unk4 = D_802FC520[i].unk6;
            func_8026A5CC((u64 *)D_8036E380[D_8036E4C0].unk8, (u64 *)D_802FC528, sizeof(D_8036E380[0].unk8));
            for (j = 0; j < 4; j++) {
                D_8036E380[D_8036E4C0].unk8[j].v.ob[0] += D_8036E380[D_8036E4C0].unk0;
                D_8036E380[D_8036E4C0].unk8[j].v.ob[1] += D_8036E380[D_8036E4C0].unk2;
                D_8036E380[D_8036E4C0].unk8[j].v.ob[2] += D_8036E380[D_8036E4C0].unk4;
            }
            D_8036E380[D_8036E4C0].unk48 = 1;
            D_8036E4C0++;
        }
    }
    if (D_8036E4C0 != 0) {
        D_8036E4C4 = (u8 *)func_802A0CC8(0x546, 0);
    }
    D_8036E4C8 = 0;
    D_8036E4CA = 0;
}

void func_80281CE4(void) {
    s32 i;
    s32 dist;

    D_8036E4CA = 0;
    if (D_8036E4C8 != 0) {
        D_8036E4C8--;
    }
    for (i = 0; i < D_8036E4C0; i++) {
        if (D_8036E380[i].unk48 != 0) {
            dist = func_8026A6F0(D_803643E0 >> 5, D_803643E4 >> 5, D_803643E8 >> 5, D_8036E380[i].unk0,
                                 D_8036E380[i].unk2, D_8036E380[i].unk4);
            if (dist < 0x28) {
                D_8036E4C8 = 0x190;
                D_8036E4CA = 1;
                D_8036E380[i].unk48 = 0;
                func_80260650(D_80367738, 0xB0, NULL);
                if (D_8036DCD8 == 0) {
                    func_80260650(D_80367738, 0xCF, &D_8036DCD8);
                }
            }
        }
    }
}

void func_80281E44(Gfx **arg0) {
    Gfx *gfx = *arg0;
    s32 i;

    if (D_8036E4C0 != 0) {
        gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
        gSPSetGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gDPSetRenderMode(gfx++, G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2);
        gDPSetCombineMode(gfx++, G_CC_MODULATERGBA, G_CC_MODULATERGBA);
        gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
        gDPLoadTextureBlock(gfx++, D_8036E4C4, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_CLAMP, G_TX_CLAMP,
                            G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        for (i = 0; i < D_8036E4C0; i++) {
            if (D_8036E380[i].unk48 != 0) {
                gSPVertex(gfx++, D_8036E380[i].unk8, 4, 0);
                gSP1Triangle(gfx++, 0, 1, 2, 0);
                gSP1Triangle(gfx++, 0, 2, 3, 0);
            }
        }
        gDPPipeSync(gfx++);
    }
    *arg0 = gfx;
}

void func_802821D0(void) {
    D_8036E4CC = D_80358070;
    func_802A0B00(0xA98, 0);
    D_80358070 += 0x800;
    D_8036E4D0 = 0;
    D_8036E4D2 = 0;
}

void func_80282224(Gfx **arg0, u8 arg1) {
    Gfx *gfx = *arg0;
    u8 sp7B;
    u8 sp7A;

    sp7B = arg1 == 7 || arg1 == 11 || arg1 == 17 || arg1 == 18;
    if (D_8036E4D2 != 0 && !sp7B) {
        D_8036E4D0 -= 10;
        if (D_8036E4D0 < 0) {
            D_8036E4D0 = 0;
        }
    } else {
        if (sp7B) {
            sp7A = !func_8029DBF0(arg1);
        }
        if (sp7B && sp7A) {
            D_8036E4D0 = 0xFF;
            D_8036E4D2 = 1;
        } else {
            D_8036E4D0 = 0;
        }
    }
    if (D_8036E4D0 == 0) {
        D_8036E4D2 = 0;
    }
    if (D_8036E4D2 != 0) {
        gSPMatrix(gfx++, &D_02000000[3], G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
        gSPMatrix(gfx++, &D_02000000[7], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
        gSPSetGeometryMode(gfx++, G_SHADE | G_SHADING_SMOOTH);
        gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
        gDPSetCombineMode(gfx++, G_CC_MODULATERGBA_PRIM, G_CC_MODULATERGBA_PRIM);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, (D_8036E4D0 < D_80367BD6) ? D_8036E4D0 : D_80367BD6);
        gDPLoadTextureBlock(gfx++, OS_K0_TO_PHYSICAL(D_8036E4CC), G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                            G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSPVertex(gfx++, OS_K0_TO_PHYSICAL(D_802FC568), 4, 0);
        gSP1Triangle(gfx++, 0, 1, 2, 0);
        gSP1Triangle(gfx++, 0, 2, 3, 0);
        gDPPipeSync(gfx++);
    }
    *arg0 = gfx;
}

void func_80282728(void) {
    D_8036E4D3 = 0;
    D_8036E4D4 = 0;
}

void func_8028273C(Gfx **arg0, u8 arg1) {
    Gfx *gfx = *arg0;
    f32 sp9C[4][4];
    f32 sp5C[4][4];
    s32 i;

    if (D_803643D6 != 0) {
        if (D_803EF6FF != 0 && D_8036E4D3 == 0) {
            D_8036E4D3 = 1;
            D_8036E5D8[0] = D_8030C7D8;
            D_8036E4D4 = D_803156C4;
        }
        gDPPipeSync(gfx++);
        gDPSetColorDither(gfx++, G_CD_DISABLE);
        if (D_8036E4D3 != 0) {
            gDPPipeSync(gfx++);
            gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
            gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
            gDPSetPrimColor(gfx++, 0, 0, 0x37, 0, 0, 0x9B);
            gDPFillRectangle(gfx++, 0, 0, 319, 239);
        }
        for (i = 0; i < D_8036E4D3; i++) {
            guTranslateF(sp9C, D_803EF6DC / 32.0f, D_803EF6E0 / 32.0f, D_803EF6E4 / 32.0f);
            guScaleF(sp5C, D_8036E5D8[i], D_8036E5D8[i], D_8036E5D8[i]);
            D_8036E5D8[i] += D_8030C7E0;
            guMtxCatF(sp5C, sp9C, sp9C);
            guMtxF2L(sp9C, &D_8036E4D8[arg1][i]);
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 0xFF, 0, 0, 0x64);
            gSPMatrix(gfx++, osVirtualToPhysical(&D_8036E4D8[arg1][i]), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
            gSPSegment(gfx++, 6, osVirtualToPhysical(D_802FFF38));
            gSPDisplayList(gfx++, osVirtualToPhysical(D_80300A68));
            gSPMatrix(gfx++, &D_02000000[7], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
        }
        if (D_8036E4D4 + 10 < D_803156C4 && D_8036E4D3 != 0 && D_8036E4D3 < 2) {
            D_8036E4D4 = D_803156C4;
            D_8036E5D8[D_8036E4D3] = D_8030C7E8;
            D_8036E4D3++;
        }
        gDPPipeSync(gfx++);
        gDPSetColorDither(gfx++, G_CD_MAGICSQ);
        gDPPipeSync(gfx++);
        if (D_8036E4D3 != 0) {
            func_802AC1A0(D_8036E5D8[0] * D_8030C7EC);
        }
    }
    *arg0 = gfx;
}
