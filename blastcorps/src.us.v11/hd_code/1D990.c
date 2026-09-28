#include "common.h"

typedef struct {
    /* 0x00 */ u8 unk0[0x26];
    /* 0x26 */ s16 unk26;
    /* 0x28 */ s16 unk28;
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ u8 unk2C[0x18];
} UnkStruct_802E8F94; /* size = 0x44 */

typedef struct {
    /* 0x0 */ u8 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 unk6;
    /* 0x8 */ s16 unk8;
} UnkStruct_802E8F68; /* size = 0xA */

typedef struct {
    /* 0x00 */ u16 unk0;
    /* 0x02 */ u16 unk2;
    /* 0x04 */ u16 unk4;
    /* 0x06 */ u16 unk6;
    /* 0x08 */ u16 unk8;
    /* 0x0A */ u16 unkA;
    /* 0x0C */ u16 unkC;
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u16 unk10;
    /* 0x12 */ u8 unk12[4];
    /* 0x16 */ u8 unk16[2];
    /* 0x18 */ u32 unk18;
    /* 0x1C */ u8 unk1C[0x8];
    /* 0x24 */ s16 unk24;
    /* 0x26 */ u8 unk26[0x10];
    /* 0x36 */ u16 unk36;
} UnkStruct_80367C04;

extern u8 D_802E8BD0;
extern s32 D_802E8BDC;
extern char *D_802F5804[];
extern u8 D_802E8F30[];
extern UnkStruct_802E8F68 D_802E8F68[];
extern UnkStruct_802E8F94 D_802E8F94[];
extern char D_8030934C[];
extern char D_80309354[];
extern char D_8030935C[];
extern char D_80309364[];
extern char D_8030936C[];
extern char D_80309374[];
extern char D_80309380[];
extern char D_80309390[];
extern char D_803093A4[];
extern char D_803093B0[];
extern char D_803093C0[];
extern f64 D_80309588;
extern s32 D_803156C0;
extern char D_803093D8[];
extern s32 D_80358064;
extern f32 D_80364438;
extern s8 D_803643D9;
extern s8 D_803643DA;
extern s32 D_803643E0;
extern s32 D_803643E4;
extern s32 D_803643E8;
extern s32 D_80364A58;
extern s32 D_80364AA8;
extern ALCSPlayer *D_80367734;
extern s32 D_80367B50;
extern u8 D_80367B54;
extern u16 D_80367B58[];
extern char D_80367B60[];
extern s32 D_80367BBC;
extern u16 D_80367BF6;
extern u8 D_80367BF8;
extern u8 D_80367BF9;
extern u8 D_80367BFA;
extern u8 D_80367BFB;
extern u16 D_80367BFC;
extern u8 D_80367BFE;
extern s8 D_80367BFF;
extern UnkStruct_80367C04 *D_80367C04;
extern u8 D_80367C10;
extern char D_80367D10[];
extern char D_80367D28[];
extern u8 D_8036DCD4;
extern u32 D_8036EA70;
extern u8 D_8036EA78;
extern u16 D_8036EA7C;
extern u8 D_8036EB92;
extern s32 D_803EF2EC;
extern s32 D_803EF2F0;
extern s32 D_803EF2F4;
extern s32 D_803EFEB0;
extern s32 D_803EFEB4;
extern s32 D_803EFEB8;
extern s32 D_803EFEBC;
extern s8 D_803EFEC8;
extern u16 D_80370C28;
extern u8 D_803F7806;

u8 func_8027EED8(s32, s32, s16 *);
s32 func_8026394C();
void func_80264A34(char *, u16, s32);
void func_8026AF6C(s32);
s16 func_8028604C(s32);
void func_8029A7E4(char *, ...);
void func_802D82A0(ALCSPlayer *, s32);
u8 func_802C1B1C(void);
void func_802C1DD0(s32);

void func_80262150(u8 arg0) {
    s32 i;

    D_80364438 = 45.0f;
    i = 0;
    D_80367C10 = 0;
    do {
        if (D_802E8F30[i] == arg0) {
            D_80364438 = 80.0f;
            D_80367C10 = 1;
        } else {
            i++;
        }
    } while (i < 5 && D_80367C10 == 0);
}

void func_802621DC(u8 arg0) {
    UnkStruct_802E8F94 *p;

    p = &D_802E8F94[arg0];
    D_803EF2EC = p->unk26 << 5;
    D_803EF2F0 = p->unk28 << 5;
    D_803EF2F4 = p->unk2A << 5;
}

void func_80262238(u8 arg0) {
    s32 i;
    u8 found;

    i = 0;
    found = 0;
    D_803EFEC8 = 0;
    do {
        if (D_802E8F68[i].unk0 == arg0) {
            found = 1;
        } else {
            i++;
        }
    } while (found == 0 && i <= 0);
    if (found != 0) {
        D_803EFEC8 = 1;
        D_803EFEB0 = D_802E8F68[i].unk2 << 5;
        D_803EFEB4 = D_802E8F68[i].unk4 << 5;
        D_803EFEB8 = D_802E8F68[i].unk6 << 5;
        D_803EFEBC = D_802E8F68[i].unk8 << 5;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/1D990/func_80262320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/1D990/func_80262840.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/1D990/func_80262BF4.s")

void func_80262FD0(void) {
    if (D_8036EA7C >= D_80367C04->unk18) {
        D_803643DA = 1;
    }
    sprintf(D_80367B60, D_8030934C, D_8036EA7C, D_80367C04->unk18);
}

void func_8026303C(void) {
    s16 sp1E;

    func_802C1DD0(0);
    if (D_8036EA78 >= D_80367C04->unk18) {
        D_803643DA = 1;
    }
    if (D_8036DCD4 != 0) {
        func_8027EED8(D_803643E0 >> 5, D_803643E8 >> 5, &sp1E);
        if (sp1E > (D_803643E4 >> 5)) {
            D_803643D9 = 1;
        }
    } else if (D_80367C04->unk24 > (D_803643E4 >> 5)) {
        D_803643D9 = 1;
    }
    sprintf(D_80367B60, D_80309354, D_8036EA78, D_8036EB92);
}

void func_80263140(void) {
    s16 sp2E;

    func_802C1DD0(1);
    switch (D_80364AA8) {
        case 0x20:
            if (D_8036EA78 >= D_8036EB92) {
                D_803643DA = 1;
            }
            break;
        case 0x80:
            if (D_803F7806 != 0 || (D_802E8BDC == 0x32 && D_8036EA78 >= D_8036EB92)) {
                D_803643DA = 1;
            }
            break;
    }
    if (D_8036DCD4 != 0) {
        func_8027EED8(D_803643E0 >> 5, D_803643E8 >> 5, &sp2E);
        if (sp2E > (D_803643E4 >> 5)) {
            D_803643D9 = 1;
        }
    } else if (D_80367C04->unk24 > (D_803643E4 >> 5)) {
        D_803643D9 = 1;
    }
    switch (D_80364AA8) {
        case 0x20:
            sprintf(D_80367B60, D_8030935C, D_8036EA78, D_8036EB92);
            break;
        case 0x80:
            if (D_802E8BDC == 0x32) {
                sprintf(D_80367B60, D_80309364, D_8036EA78, D_8036EB92);
            } else {
                sprintf(D_80367B60, D_8030936C, func_802C1B1C(), D_8036EB92);
            }
            break;
    }
}

void func_80263358(void) {
    s32 sp1C;

    func_802C1DD0(0);
    if (D_8036EA70 >= D_80367C04->unk18) {
        D_803643DA = 1;
    }
    sp1C = D_80367C04->unk18 - D_8036EA70;
    if (sp1C < 0) {
        sp1C = 0;
    }
    sprintf(D_80367B60, D_80309374, sp1C);
}

void func_802633E0(void) {
    s32 i;
    u8 sp33;

    if (D_80367B54 == 0) {
        if (func_8026394C(D_803643E0 >> 5, D_803643E8 >> 5, D_80367C04->unkA, D_80367C04->unkC, D_80367C04->unkE,
                          D_80367C04->unk10) != 0) {
            D_80367B54 = 1;
            D_80367BF8 = 0;
            D_80367BF9 = D_80367C04->unk12[0];
            D_80367BBC = D_803156C0;
            D_80367BFB = 1;
            D_80367BFC = 0xFFFF;
        }
    } else {
        D_80367BFA = ((D_803643E8 >> 5) - D_80367C04->unk4) / ((D_80367C04->unk8 - D_80367C04->unk4) >> 1);
        D_80367BFA *= 2;
        D_80367BFA += ((D_803643E0 >> 5) - D_80367C04->unk2) / ((D_80367C04->unk6 - D_80367C04->unk2) >> 1);
        D_80367B58[D_80367B54 - 1] = func_8028604C(D_803156C0 - D_80364A58);
        for (i = D_80367B54 - 2; i >= 0; i--) {
            D_80367B58[D_80367B54 - 1] -= D_80367B58[i];
        }
        if (D_80370C28 & 0x2000) {
            func_8029A7E4(D_80309380, D_80367BFA);
        }
        if (D_80367BF8 == 4) {
            if (func_8026394C(D_803643E0 >> 5, D_803643E8 >> 5, D_80367C04->unkA, D_80367C04->unkC, D_80367C04->unkE,
                              D_80367C04->unk10) != 0) {
                if (D_80367B58[D_80367B54 - 1] < D_80367BFC) {
                    func_8029A7E4(D_80309390, D_80367BFC, D_80367B58[D_80367B54 - 1]);
                    D_80367BFB = D_80367B54;
                    D_80367BFC = D_80367B58[D_80367B54 - 1];
                }
                if (D_80367C04->unk18 - 1 < D_80367B54) {
                    D_803643DA = 1;
                } else {
                    sp33 = D_80367C04->unk18 - D_80367B54;
                    if (D_802E8BD0 == 0) {
                        func_8026AF6C(0x8008);
                    }
                    if (sp33 == 1) {
                        sprintf(D_80367D10, D_803093A4);
                    } else {
                        sprintf(D_80367D10, D_803093B0, sp33);
                    }
                    D_802F5804[0x3E0 / 4] = D_80367D10;
                    D_802F5804[0x3E4 / 4] = D_80367D28;
                    func_802D82A0(D_80367734, alCSPGetTempo(D_80367734) * D_80309588);
                }
                D_80367B54++;
                D_80367BF8 = 0;
            }
        } else if (D_80367C04->unk12[D_80367BF8] == D_80367BF9 &&
                   D_80367C04->unk12[(D_80367BF8 + 1) % 4] == D_80367BFA) {
            func_8029A7E4(D_803093C0, D_80367BF9, D_80367BFA);
            D_80367BF8++;
        }
        D_80367BF9 = D_80367BFA;
    }
    for (i = 0; i < D_80367B54 && i < D_80367C04->unk18; i++) {
        func_80264A34(D_80367B60 + i * 0x14, D_80367B58[i], D_80367B54 == i + 1);
    }
}

s32 func_8026394C(x, y, x0, y0, x1, y1)
    s16 x;
    s16 y;
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;
{
    if (x >= x0 && y >= y0 && x < x1 && y < y1) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/1D990/func_802639B4.s")

void func_8026420C(void) {
    if (D_80367BFE != 0 && D_80358064 == D_80367B50) {
        func_8029A7E4(D_803093D8);
        D_80367BFF = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/1D990/func_80264264.s")

void func_80264A34(char *buf, u16 t, s32 arg2) {
    buf[0] = t / 6000 + '0';
    t %= 6000;
    buf[1] = t / 600 + '0';
    buf[2] = ':';
    t %= 600;
    buf[3] = t / 100 + '0';
    t %= 100;
    buf[4] = t / 10 + '0';
    t %= 10;
    buf[5] = '.';
    buf[6] = t + '0';
    buf[7] = 0;
}

void func_80264AEC(void) {
    s32 i;
    u16 sum;

    sum = 0;
    if (D_80364AA8 == 2 && D_80367B54 >= 2) {
        for (i = 0; i < D_80367B54 - 1; i++) {
            sum += D_80367B58[i];
        }
        D_80367BF6 = D_80367C04->unk36 - sum;
    }
    if (D_80367BF6 >= 60000) {
        D_80367BF6 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/1D990/func_80264BA4.s")
