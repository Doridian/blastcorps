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

typedef struct {
    /* 0x0000 */ u8 unk0[0x2000];
    /* 0x2000 */ Vtx unk2000[451];
    /* 0x3C30 */ Gfx unk3C30[1];
} UnkStruct_8027C4C8;

void func_8027D350(s16 x0, s16 y0, s16 z0, s16 x1, s16 y1, s16 z1, Vtx *vtx, s32 i);
void func_8027D5AC(void);
s32 func_802AC4C4(s32, s32, s32, s32, s32, s32, s32, s32);

extern UnkStruct_8027C4C8 D_02000000;
extern s32 D_802E8BDC;
extern s32 D_80358060;
extern UnkStruct_802FC360 D_802FC360[11];

/* .bss, 0x8036D3D0-0x8036DCA0 (tools/bss_c.py) */
UnkStruct_8036D3D0 D_8036D3D0[80];
u8 D_8036DC90;
u8 D_8036DC91;
u8 D_8036DC92;
s32 D_8036DC94;

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
        guRotateF(mf, (f32)arg8 / 4095.0 * 360.0, 0.0f, 1.0f, 0.0f);
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

void func_8027C4C8(Gfx **arg0, UnkStruct_8027C4C8 *arg1) {
    Gfx *gfx;
    u8 idx;
    u8 start;
    u8 end;
    u8 j;
    u8 done;
    Gfx *sub;
    s32 subCount;
    s32 vtxStart;
    s32 vtxIdx;
    s16 minX;
    s16 minY;
    s16 minZ;
    s16 maxX;
    s16 maxY;
    s16 maxZ;
    u8 k;
    u8 n;
    s32 count;
    s32 sp6C;
    u8 flag;

    gfx = *arg0;
    idx = D_8036DC90;
    done = FALSE;
    sub = arg1->unk3C30;
    subCount = 0;
    vtxStart = 0;
    func_8027D5AC();
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetRenderMode(gfx++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
    gSPSetGeometryMode(gfx++, G_SHADE | G_SHADING_SMOOTH);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
    gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, 0, 0, 0, SHADE, 0, 0, 0, PRIMITIVE, 0, 0, 0, SHADE);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 0);
    while (!done) {
        start = idx;
        flag = D_8036D3D0[idx].unk1B;
        while (idx != D_8036DC91 && D_8036D3D0[idx].unk1A == 0) {
            if (++idx == 80) {
                idx = 0;
            }
        }
        end = idx;
        if (idx == D_8036DC91) {
            done = TRUE;
        }
        if (start != end) {
            gSPDisplayList(gfx++, &D_02000000.unk3C30[subCount]);
            minX = 0x7FFF, minY = 0x7FFF, minZ = 0x7FFF;
            maxX = -0x8000, maxY = -0x8000, maxZ = -0x8000;
            vtxIdx = vtxStart;
            j = start;
            while (j != end) {
                arg1->unk2000[vtxIdx].v.ob[0] = D_8036D3D0[j].unk0;
                arg1->unk2000[vtxIdx].v.ob[1] = D_8036D3D0[j].unk2;
                arg1->unk2000[vtxIdx].v.ob[2] = D_8036D3D0[j].unk4;
                arg1->unk2000[vtxIdx].v.cn[3] = D_8036D3D0[j].unk18;
                vtxIdx++;
                arg1->unk2000[vtxIdx].v.ob[0] = D_8036D3D0[j].unk6;
                arg1->unk2000[vtxIdx].v.ob[1] = D_8036D3D0[j].unk8;
                arg1->unk2000[vtxIdx].v.ob[2] = D_8036D3D0[j].unkA;
                arg1->unk2000[vtxIdx].v.cn[3] = D_8036D3D0[j].unk18;
                vtxIdx++;
                if (D_8036D3D0[j].unk0 < minX) {
                    minX = D_8036D3D0[j].unk0;
                }
                if (D_8036D3D0[j].unk2 < minY) {
                    minY = D_8036D3D0[j].unk2;
                }
                if (D_8036D3D0[j].unk4 < minZ) {
                    minZ = D_8036D3D0[j].unk4;
                }
                if (D_8036D3D0[j].unk0 > maxX) {
                    maxX = D_8036D3D0[j].unk0;
                }
                if (D_8036D3D0[j].unk2 > maxY) {
                    maxY = D_8036D3D0[j].unk2;
                }
                if (D_8036D3D0[j].unk4 > maxZ) {
                    maxZ = D_8036D3D0[j].unk4;
                }
                if (D_8036D3D0[j].unk6 < minX) {
                    minX = D_8036D3D0[j].unk6;
                }
                if (D_8036D3D0[j].unk8 < minY) {
                    minY = D_8036D3D0[j].unk8;
                }
                if (D_8036D3D0[j].unkA < minZ) {
                    minZ = D_8036D3D0[j].unkA;
                }
                if (D_8036D3D0[j].unk6 > maxX) {
                    maxX = D_8036D3D0[j].unk6;
                }
                if (D_8036D3D0[j].unk8 > maxY) {
                    maxY = D_8036D3D0[j].unk8;
                }
                if (D_8036D3D0[j].unkA > maxZ) {
                    maxZ = D_8036D3D0[j].unkA;
                }
                if (++j == 80) {
                    j = 0;
                }
            }
            if (flag == 0) {
                j = start;
                while (j != end) {
                    arg1->unk2000[vtxIdx].v.ob[0] = D_8036D3D0[j].unkC;
                    arg1->unk2000[vtxIdx].v.ob[1] = D_8036D3D0[j].unkE;
                    arg1->unk2000[vtxIdx].v.ob[2] = D_8036D3D0[j].unk10;
                    arg1->unk2000[vtxIdx].v.cn[3] = D_8036D3D0[j].unk19;
                    vtxIdx++;
                    arg1->unk2000[vtxIdx].v.ob[0] = D_8036D3D0[j].unk12;
                    arg1->unk2000[vtxIdx].v.ob[1] = D_8036D3D0[j].unk14;
                    arg1->unk2000[vtxIdx].v.ob[2] = D_8036D3D0[j].unk16;
                    arg1->unk2000[vtxIdx].v.cn[3] = D_8036D3D0[j].unk19;
                    vtxIdx++;
                    if (D_8036D3D0[j].unkC < minX) {
                        minX = D_8036D3D0[j].unkC;
                    }
                    if (D_8036D3D0[j].unkE < minY) {
                        minY = D_8036D3D0[j].unkE;
                    }
                    if (D_8036D3D0[j].unk10 < minZ) {
                        minZ = D_8036D3D0[j].unk10;
                    }
                    if (D_8036D3D0[j].unk12 > maxX) {
                        maxX = D_8036D3D0[j].unk12;
                    }
                    if (D_8036D3D0[j].unk14 > maxY) {
                        maxY = D_8036D3D0[j].unk14;
                    }
                    if (D_8036D3D0[j].unk16 > maxZ) {
                        maxZ = D_8036D3D0[j].unk16;
                    }
                    if (D_8036D3D0[j].unkC < minX) {
                        minX = D_8036D3D0[j].unkC;
                    }
                    if (D_8036D3D0[j].unkE < minY) {
                        minY = D_8036D3D0[j].unkE;
                    }
                    if (D_8036D3D0[j].unk10 < minZ) {
                        minZ = D_8036D3D0[j].unk10;
                    }
                    if (D_8036D3D0[j].unk12 > maxX) {
                        maxX = D_8036D3D0[j].unk12;
                    }
                    if (D_8036D3D0[j].unk14 > maxY) {
                        maxY = D_8036D3D0[j].unk14;
                    }
                    if (D_8036D3D0[j].unk16 > maxZ) {
                        maxZ = D_8036D3D0[j].unk16;
                    }
                    if (++j == 80) {
                        j = 0;
                    }
                }
            }
            count = vtxIdx - vtxStart;
            if (flag != 0) {
                sp6C = 0;
            } else {
                sp6C = count >> 1;
            }
            if (count > 40) {
                func_8027D350(minX, minY, minZ, maxX, maxY, maxZ, arg1->unk2000, vtxIdx);
                gSPVertex(sub++, &D_02000000.unk2000[vtxIdx], 8, 0);
                gSPCullDisplayList(sub++, 0, 7);
                subCount += 2;
                vtxIdx += 8;
            }
            while (count >= 3) {
                if (count > 16) {
                    n = 16;
                } else {
                    n = count;
                }
                gSPVertex(sub++, &D_02000000.unk2000[vtxStart], n, 0);
                k = 0;
                vtxStart += n - 2;
                subCount++;
                while (k < n - 2) {
                    if (sp6C != 2) {
                        gSP1Triangle(sub++, k, k + 1, k + 2, 0);
                        gSP1Triangle(sub++, k + 1, k + 2, k + 3, 0);
                        subCount += 2;
                        sp6C -= 2;
                        k += 2;
                    } else {
                        sp6C = 0;
                        k += 4;
                    }
                }
                count = count - n + 2;
            }
            vtxStart = vtxIdx;
            gSPEndDisplayList(sub++);
            subCount++;
        }
        if (++idx == 80) {
            idx = 0;
        }
    }
    gDPPipeSync(gfx++);
    *arg0 = gfx;
}

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
