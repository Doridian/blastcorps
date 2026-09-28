#include "common.h"

typedef struct {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 unk6;
    /* 0x8 */ s16 unk8;
    /* 0xA */ s16 unkA;
    /* 0xC */ s16 unkC;
    /* 0xE */ s16 unkE;
} UnkStruct_8027BCF0; /* size = 0x10 */

typedef struct {
    /* 0x0 */ UnkStruct_8027BCF0 *unk0;
    /* 0x4 */ UnkStruct_8027BCF0 *unk4;
    /* 0x8 */ u8 unk8;
} UnkStruct_802FC360; /* size = 0xC */

typedef struct {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ s16 unk12;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ u8 unk18;
    /* 0x19 */ u8 unk19;
    /* 0x1A */ u8 unk1A;
    /* 0x1B */ u8 unk1B;
} UnkStruct_8036D3D0; /* size = 0x1C */

s32 func_802AC4C4(s32, s32, s32, s32, s32, s32, s32, s32);

extern s32 D_802E8BDC;
extern f64 D_8030C6D0;
extern f64 D_8030C6D8;
extern s32 D_80358060;
extern UnkStruct_802FC360 D_802FC360[11];

extern UnkStruct_8036D3D0 D_8036D3D0[80];
extern u8 D_8036DC90;
extern u8 D_8036DC91;
extern u8 D_8036DC92;
extern s32 D_8036DC94;

s32 func_8027BCF0(s16 arg0, s16 arg1, s16 arg2) {
    s32 i;
    u8 found;
    UnkStruct_8027BCF0 *p;
    UnkStruct_8027BCF0 *end;

    i = 0;
    found = FALSE;
    while (i < 11 && !found) {
        if (D_802FC360[i].unk8 == D_802E8BDC) {
            found = TRUE;
        } else {
            i++;
        }
    }
    if (!found) {
        return 0;
    }
    p = D_802FC360[i].unk0;
    end = D_802FC360[i].unk4;
    while (p != end) {
        if (arg1 >= p->unkC && arg1 <= p->unkE) {
            if (func_802AC4C4(arg0, arg2, p->unk0, p->unk2, p->unk4, p->unk6, p->unk8, p->unkA) != 0) {
                return 1;
            }
        }
        p++;
    }
    return 0;
}

void func_8027BE4C(void) {
    s32 sp4;

    D_8036DC90 = 0;
    D_8036DC91 = 0;
    D_8036DC92 = 0;
    D_8036DC94 = -1;
}

void func_8027BE7C(u8 arg0, s32 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s32 arg6, s32 arg7, s16 arg8, u8 arg9,
                   u8 arg10, u8 arg11, u8 arg12) {
    f32 mf[4][4];
    f32 x0;
    f32 z0;
    f32 x1;
    f32 z1;
    f32 y;
    f32 dx;
    f32 dz;
    s16 ax;
    s16 az;
    s16 bx;
    s16 bz;

    if (func_8027BCF0(arg6 >> 5, arg1 >> 5, arg7 >> 5) == 0) {
        guRotateF(mf, (f32)arg8 / D_8030C6D0 * D_8030C6D8, 0.0f, 1.0f, 0.0f);
        guMtxXFMF(mf, arg2, 0.0f, arg3, &x0, &y, &z0);
        guMtxXFMF(mf, arg4, 0.0f, arg5, &x1, &y, &z1);
        ax = (s32)(arg6 + x0) >> 5;
        az = (s32)(arg7 + z0) >> 5;
        bx = (s32)(arg6 + x1) >> 5;
        bz = (s32)(arg7 + z1) >> 5;
        arg1 >>= 5;
        guMtxXFMF(mf, (u32)arg9, 0.0f, 0.0f, &dx, &y, &dz);
        if (D_8036DC94 + 1 != D_80358060 || D_8036DC94 == -1) {
            D_8036D3D0[D_8036DC91].unk1A = 1;
            if (++D_8036DC91 == 80) {
                D_8036DC91 = 0;
            }
            if (D_8036DC91 == D_8036DC90) {
                if (++D_8036DC90 == 80) {
                    D_8036DC90 = 0;
                }
            }
        }
        D_8036D3D0[D_8036DC91].unk1B = arg12;
        D_8036D3D0[D_8036DC91].unk0 = ax + (s16)dx;
        D_8036D3D0[D_8036DC91].unk2 = arg1;
        D_8036D3D0[D_8036DC91].unk4 = az + (s16)dz;
        D_8036D3D0[D_8036DC91].unk6 = ax - (s16)dx;
        D_8036D3D0[D_8036DC91].unk8 = arg1;
        D_8036D3D0[D_8036DC91].unkA = az - (s16)dz;
        D_8036D3D0[D_8036DC91].unkC = bx + (s16)dx;
        D_8036D3D0[D_8036DC91].unkE = arg1;
        D_8036D3D0[D_8036DC91].unk10 = bz + (s16)dz;
        D_8036D3D0[D_8036DC91].unk12 = bx - (s16)dx;
        D_8036D3D0[D_8036DC91].unk14 = arg1;
        D_8036D3D0[D_8036DC91].unk16 = bz - (s16)dz;
        D_8036D3D0[D_8036DC91].unk18 = arg10;
        D_8036D3D0[D_8036DC91].unk19 = arg11;
        if (++D_8036DC92 >= arg0) {
            D_8036DC92 = 0;
            D_8036D3D0[D_8036DC91].unk1A = 0;
            if (++D_8036DC91 == 80) {
                D_8036DC91 = 0;
            }
            if (D_8036DC91 == D_8036DC90) {
                if (++D_8036DC90 == 80) {
                    D_8036DC90 = 0;
                }
            }
        }
        D_8036DC94 = D_80358060;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/37530/func_8027C4C8.s")

void func_8027D350(s16 x0, s16 y0, s16 z0, s16 x1, s16 y1, s16 z1, Vtx *vtx, s32 i) {
    vtx[i].v.ob[0] = x0;
    vtx[i].v.ob[1] = y0;
    vtx[i].v.ob[2] = z0;
    i++;
    vtx[i].v.ob[0] = x0;
    vtx[i].v.ob[1] = y1;
    vtx[i].v.ob[2] = z0;
    i++;
    vtx[i].v.ob[0] = x1;
    vtx[i].v.ob[1] = y0;
    vtx[i].v.ob[2] = z0;
    i++;
    vtx[i].v.ob[0] = x1;
    vtx[i].v.ob[1] = y1;
    vtx[i].v.ob[2] = z0;
    i++;
    vtx[i].v.ob[0] = x0;
    vtx[i].v.ob[1] = y0;
    vtx[i].v.ob[2] = z1;
    i++;
    vtx[i].v.ob[0] = x0;
    vtx[i].v.ob[1] = y1;
    vtx[i].v.ob[2] = z1;
    i++;
    vtx[i].v.ob[0] = x1;
    vtx[i].v.ob[1] = y0;
    vtx[i].v.ob[2] = z1;
    i++;
    vtx[i].v.ob[0] = x1;
    vtx[i].v.ob[1] = y1;
    vtx[i].v.ob[2] = z1;
}

void func_8027D5AC(void) {
    s32 count;
    u8 next;

    if (D_8036DC91 >= D_8036DC90) {
        count = D_8036DC91 - D_8036DC90;
    } else {
        count = D_8036DC91 - D_8036DC90 + 80;
    }
    if (count >= 71) {
        if (D_8036D3D0[D_8036DC90].unk18 <= 0) {
            D_8036D3D0[D_8036DC90].unk18 = 0;
        } else {
            D_8036D3D0[D_8036DC90].unk18--;
        }
        if (D_8036D3D0[D_8036DC90].unk19 <= 0) {
            D_8036D3D0[D_8036DC90].unk19 = 0;
        } else {
            D_8036D3D0[D_8036DC90].unk19--;
        }
        if (D_8036D3D0[D_8036DC90].unk18 == 0 && D_8036D3D0[D_8036DC90].unk19 == 0) {
            next = D_8036DC90 + 1;
            if (next == 80) {
                next = 0;
            }
            if (D_8036D3D0[next].unk18 <= 0) {
                D_8036D3D0[next].unk18 = 0;
            } else {
                D_8036D3D0[next].unk18--;
            }
            if (D_8036D3D0[next].unk19 <= 0) {
                D_8036D3D0[next].unk19 = 0;
            } else {
                D_8036D3D0[next].unk19--;
            }
            if (D_8036D3D0[next].unk18 == 0 && D_8036D3D0[next].unk19 == 0) {
                D_8036DC90 = next;
            }
        }
    }
}
