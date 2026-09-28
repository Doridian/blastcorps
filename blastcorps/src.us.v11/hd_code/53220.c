#include "common.h"

typedef struct {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ u16 unk10;
    /* 0x12 */ u8 pad12[6];
    /* 0x18 */ s16 unk18;
    /* 0x1A */ u8 pad1A[2];
} UnkStruct_802F8BDC; /* size = 0x1C */

typedef struct {
    /* 0x0 */ u8 *unk0;
    /* 0x4 */ u16 *unk4;
} UnkStruct_802FF188; /* size = 0x8 */

typedef struct {
    /* 0x00 */ u16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ u8 padA[2];
    /* 0x0C */ u8 *unkC;
    /* 0x10 */ u16 *unk10;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ u8 unk18;
    /* 0x19 */ u8 unk19;
    /* 0x1A */ s8 unk1A;
} UnkStruct_8036BB10; /* size = 0x1C */

typedef struct {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 pad5;
    /* 0x06 */ u8 unk6[0x26];
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ u8 unk2D;
    /* 0x2E */ s8 unk2E;
    /* 0x2F */ u8 pad2F;
} UnkStruct_802F49F4; /* size = 0x30 */

extern UnkStruct_802F49F4 D_802F49F4[];
extern UnkStruct_802F8BDC D_802F8BDC[];
extern u8 D_802FF180[6];
extern UnkStruct_802FF188 D_802FF188[][20];
extern u8 D_802FF5E8[][5];
extern u8 *D_80358070;
extern u8 D_80364AE8;
extern u8 D_80364B80[][0x100];
extern UnkStruct_8036BB10 *D_8036BB24;
extern u8 D_8039CAB6;
extern u8 D_8039CAD0;

s32 func_8025B300(u8 *);
s8 func_80272C5C(u8 *, s32, s32, s32, s32, f32);
u8 func_8029766C(u8, u8 *);
u8 func_80297EF8(u8);
u8 func_80297F74(void);

void func_802979E0(u8 arg0) {
    UnkStruct_802F8BDC *sp4C = &D_802F8BDC[21];
    UnkStruct_8036BB10 *sp48;
    UnkStruct_802F49F4 *sp44;
    u8 sp43;
    u8 sp42;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    u8 sp2F;
    u8 *sp28;
    u16 *sp24;

    sp43 = func_80297F74();
    sp42 = 0;
    if (sp43 == 1 && func_80297EF8(arg0) == 0) {
        sp43--;
    }
    if (sp43 == 0) {
        D_8039CAD0 = 6;
    } else {
        sp2F = 0;
        for (sp3C = D_8039CAB6; sp3C < D_8039CAB6 + 6 && sp2F == 0;) {
            if (func_80297EF8(D_802FF180[sp3C % 6]) == 0 && D_802FF180[sp3C % 6] != arg0) {
                sp2F = 1;
            } else {
                sp3C++;
            }
        }
        D_8039CAD0 = sp3C % 6;
    }
    sp3C = 0;
    D_8036BB24 = (UnkStruct_8036BB10 *)D_80358070;
    D_80358070 += 0x24C;
    sp34 = 0;
    sp30 = 0;
    sp2F = 0;
    for (; sp3C < 20 && sp2F == 0; sp3C++) {
        sp28 = D_802FF188[D_8039CAD0][sp3C].unk0;
        sp24 = D_802FF188[D_8039CAD0][sp3C].unk4;
        sp48 = &D_8036BB24[sp3C];
        if (sp28 != NULL) {
            sp30++;
            sp48->unk0 = 0x1020;
            if (D_802FF5E8[D_8039CAD0][sp34] == sp3C) {
                sp48->unk0 |= 1;
                sp34++;
            }
            sp48->unk4 = sp3C * 16;
            sp48->unk6 = 16;
            sp48->unk8 = 16;
            sp48->unkC = sp28;
            sp48->unk10 = sp24;
            sp48->unk14 = 0;
            sp48->unk16 = 0;
            sp48->unk18 = 7;
            sp48->unk19 = 7;
            sp48->unk1A = 0;
        } else {
            sp2F = 1;
        }
    }
    sp48 = &D_8036BB24[sp30];
    sp48->unkC = NULL;
    sp48->unk10 = NULL;
    sp48->unk0 = 0x400;
    sp48->unk2 = -0x20;
    sp48->unk4 = 0x26;
    sp48->unk14 = 0x18;
    sp48->unk1A = 0;
    sp48->unk16 = (u8)sp48->unk1A;
    sp44 = &D_802F49F4[sp48->unk14];
    sp48->unk1A = func_80272C5C(sp44->unk6, 0, sp44->unk4, sp44->unk2C, sp44->unk2D | 4, 1.0f);
    sp4C->unk10 = sp30 + 1;
    sp4C->unk18 = D_802FF5E8[D_8039CAD0][0];
    if (func_80297EF8(arg0) == 0) {
        sp43--;
    }
    for (sp3C = 0; sp3C < sp4C->unk10 && sp42 == 0; sp3C++) {
        sp48 = &D_8036BB24[sp3C];
        for (sp38 = 0; sp38 < func_8025B300(sp48->unkC) && sp42 == 0; sp38++) {
            if (sp48->unkC[sp38] >= '0' && sp48->unkC[sp38] < '6') {
                sp48->unkC[sp38] = sp43 + '0';
                sp42 = 1;
            }
        }
    }
}

void func_80297ECC(void) {
    D_802F8BDC[21].unk18 = D_802FF5E8[D_8039CAD0][0];
}

u8 func_80297EF8(u8 arg0) {
    u8 sp27;
    u8 sp26;

    sp26 = func_8029766C(arg0, &sp27);
    return (sp26 != 0 && (D_80364B80[D_80364AE8][0] & (1 << sp27))) ? 1 : 0;
}

u8 func_80297F74(void) {
    s32 sp4;
    s32 sp0 = 6;

    for (sp4 = 0; sp4 < 6; sp4++) {
        if (D_80364B80[D_80364AE8][0] & (1 << sp4)) {
            sp0--;
        }
    }
    return sp0;
}

/* hd_code's copy of Rare's gzip inflate, for hd_front_end.  Its tables are
 * in hd_code's .data, which isn't split yet. */
#include "gzip.h"

extern uch border[];
extern ush cplens[];
extern uch cplext[];
extern ush cpdist[];
extern uch cpdext[];

#include "src/gzip_inflate.inc.c"
