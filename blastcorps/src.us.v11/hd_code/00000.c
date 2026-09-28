#include "common.h"

typedef struct {
    /* 0x00 */ void *unk0;
    /* 0x04 */ void *unk4;
    /* 0x08 */ void *unk8;
    /* 0x0C */ void *unkC;
    /* 0x10 */ void *unk10;
    /* 0x14 */ void *unk14;
    /* 0x18 */ u8 pad18[0x18];
    /* 0x30 */ void *unk30;
    /* 0x34 */ void *unk34;
    /* 0x38 */ void *unk38;
    /* 0x3C */ u8 pad3C[0x18];
    /* 0x54 */ Gfx *unk54;
    /* 0x58 */ u8 pad58[4];
    /* 0x5C */ s32 unk5C;
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ s32 unk70;
} UnkStruct_80364460; /* size = 0x74 */

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1[0x43];
} UnkStruct_802E8F94; /* size = 0x44 */

typedef struct {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 unk6;
    /* 0x8 */ u8 unk8;
    /* 0x9 */ u8 unk9;
} UnkStruct_80364A00; /* size = 0xC */

/*
 * The per-frame buffer: D_803156F8 holds two of these, picked by D_8035805C,
 * and segment 2 points at the current one (see 30C70.c).
 */
typedef struct {
    /* 0x00000 */ Mtx unk0[11];
    /* 0x002C0 */ Mtx unk2C0[60];
    /* 0x011C0 */ u8 unk11C0[0x340];
    /* 0x01500 */ Mtx unk1500;
    /* 0x01540 */ Mtx unk1540;
    /* 0x01580 */ Vtx unk1580[4];
    /* 0x015C0 */ Vtx unk15C0[48];
    /* 0x018C0 */ Vtx unk18C0[4];
    /* 0x01900 */ u8 unk1900[0x2300];
    /* 0x03C00 */ LookAt unk3C00;
    /* 0x03C20 */ u8 unk3C20[0xC90];
    /* 0x048B0 */ Gfx unk48B0[0xB5E];
    /* 0x0A3A0 */ u8 unkA3A0[0x140];
    /* 0x0A4E0 */ Gfx unkA4E0[20];
    /* 0x0A580 */ Gfx unkA580[115];
    /* 0x0A918 */ Gfx unkA918[0x2D5F];
    /* 0x21410 */ Gfx unk21410[13];
    /* 0x21478 */ Gfx unk21478[4];
} UnkStruct_02000000; /* size = 0x21498 */

/* 0x1040-byte records; D_803643C8 is the first (see 13A70.c). */
typedef struct {
    /* 0x0000 */ u8 unk0[0x1000];
    /* 0x1000 */ f32 unk1000;
    /* 0x1004 */ s32 unk1004;
    /* 0x1008 */ s32 unk1008;
    /* 0x100C */ s32 unk100C;
    /* 0x1010 */ s32 unk1010;
    /* 0x1014 */ s32 unk1014;
    /* 0x1018 */ s16 unk1018;
    /* 0x101A */ s16 unk101A;
    /* 0x101C */ s16 unk101C;
    /* 0x101E */ s16 unk101E;
    /* 0x1020 */ s16 unk1020;
    /* 0x1022 */ u8 unk1022;
    /* 0x1023 */ u8 unk1023;
    /* 0x1024 */ u8 unk1024[0x1C];
} UnkStruct_803643C8; /* size = 0x1040 */

typedef struct {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ u8 unk18[0x79];
    /* 0x91 */ u8 unk91;
    /* 0x92 */ u8 unk92[0x6E];
} UnkStruct_80364AF0; /* size = 0x100 */

/*
 * .bss used here, defined in this file: the functions only match with them
 * defined (a u64's halves share one lui).  The addresses still come from
 * the absolute symbols in undefined_syms_auto until .bss is split.
 */
u64 D_80310D80[0x2000 / sizeof(u64)];
u64 D_80364A90;
u64 D_80364A98;

extern u8 D_00787F40[];
extern u8 D_00788000[];
extern Gfx D_01000010[];
extern Gfx D_01000038[];
extern UnkStruct_02000000 D_02000000;
extern s32 D_80000300;
extern u16 D_80000400[][320 * 240];
extern OSThread D_80218D30;
extern u8 D_80218EE0[];
extern s32 D_80219F58;
extern u8 D_8021ED00[];
extern u8 D_802E8BD0;
extern u8 D_802E8BD4;
extern u8 D_802E8BD8;
extern s32 D_802E8BDC;
extern u8 D_802E8BE4;
extern s32 D_802E8BE8;
extern s32 D_802E8BEC;
extern u8 D_802E8BF0;
extern u8 D_802E8BF4[];
extern u8 D_802E8BF8;
extern UnkStruct_802E8F94 D_802E8F94[];
extern s32 D_802FA254;
extern u8 D_802FA940[];
extern u8 D_802FDB14;
extern u8 D_802FDBD0;
extern u8 D_802FDBD4;
extern u16 D_80304904[];
extern u16 D_80304910[];
extern u16 D_8030491C[];
extern u16 D_80304938[];
extern char D_8030821C[];
extern char D_80308228[];
extern char D_80308240[];
extern char D_80308254[];
extern char D_80308264[];
extern char D_80308274[];
extern char D_803082A0[];
extern char D_803082BC[];
extern char D_803082C4[];
extern char D_803082D4[];
extern char D_803082E4[];
extern char D_80308310[];
extern char D_80308330[];
extern char D_80308358[];
extern char D_80308384[];
extern char D_80308390[];
extern char D_80308398[];
extern char D_803083C4[];
extern char D_803083E4[];
extern char D_803083EC[];
extern char D_80308418[];
extern char D_80308440[];
extern f32 D_80308798;
extern f32 D_8030879C;
extern f32 D_803087A0;
extern f32 D_803087A4;
extern f32 D_803087A8;
extern f32 D_803087AC;
extern f32 D_803087B0;
extern f64 D_803087B8;
extern f64 D_803087C0;
extern f64 D_803087C8;
extern f64 D_803087D0;
extern f64 D_803087D8;
extern f64 D_803087E0;
extern f64 D_803087E8;
extern f64 D_80308B28;
extern f64 D_80308B30;
extern f64 D_80308B38;
extern f64 D_80308B40;
extern f64 D_80308B48;
extern f64 D_80308B50;
extern f64 D_80308B58;
extern f64 D_80308B60;
extern f64 D_80308B68;
extern f64 D_80308B70;
extern f64 D_80308B78;
extern f64 D_80308B80;
extern f64 D_80308B88;
extern f64 D_80308B90;
extern OSThread D_80310820;
extern u64 D_803109D0[];
extern OSThread D_80310BD0;
extern u64 D_80312D80[];
extern OSMesgQueue D_80314D80;
extern OSMesg D_80314D98[];
extern OSMesgQueue D_803150A0;
extern OSMesg D_803150B8[];
extern OSMesgQueue D_80315180;
extern OSMesg D_80315198[];
extern OSMesgQueue D_803153D8;
extern OSMesg D_803153F8[];
extern u8 D_80315440[];
extern u32 D_803156C4;
extern u8 D_803156D8[];
extern s32 D_803156F0;
extern u8 D_803156F5;
extern u8 D_803156F8[];
extern Gfx *D_80358030[2];
extern Gfx *D_80358038[2];
extern Gfx *D_80358040[2];
extern Gfx *D_80358048[2];
extern u32 D_80358050[];
extern u32 D_80358058;
extern u8 D_8035805C;
extern u32 D_80358060;
extern s32 D_80358064;
extern s32 D_80358068;
extern u8 *D_8035806C;
extern u8 *D_80358070;
extern s32 D_80358074;
extern s32 D_80358078;
extern u16 D_8035807C;
extern u8 D_80358088[];
extern UnkStruct_803643C8 *D_803643C8;
extern UnkStruct_803643C8 *D_803643CC;
extern u8 D_803643D6;
extern u8 D_803643D7;
extern u8 D_803643D8;
extern u8 D_803643D9;
extern u8 D_803643DA;
extern u8 D_803643DB;
extern u8 D_803643DC;
extern s32 D_803643E0;
extern s32 D_803643E4;
extern s32 D_803643E8;
extern s32 D_803643F8;
extern s32 D_803643FC;
extern s32 D_80364400;
extern u8 D_80364410;
extern f32 D_80364414;
extern f32 D_80364418;
extern u8 D_8036441C;
extern u8 D_8036441D;
extern s32 D_80364420;
extern u8 D_80364434;
extern f32 D_80364438;
extern s16 D_8036443C;
extern s16 D_8036443E;
extern s16 D_80364440;
extern f32 D_80364444;
extern f32 D_80364448;
extern s16 D_80364452;
extern s16 D_80364454;
extern u8 D_80364456;
extern u32 D_80364458;
extern UnkStruct_80364460 D_80364460[];
extern UnkStruct_80364460 *D_803649D0;
extern s32 D_803649E8;
extern u8 D_803649EC;
extern u8 D_803649ED;
extern s8 D_803649EE;
extern u32 D_803649F0;
extern u32 D_803649F4;
extern f32 D_803649F8;
extern UnkStruct_80364A00 D_80364A00[5];
extern u8 D_80364A3C;
extern u8 D_80364A3D;
extern s32 D_80364A40;
extern s32 D_80364A44;
extern u8 D_80364A48;
extern s16 D_80364A4A;
extern s16 D_80364A4C;
extern u8 D_80364A4E;
extern s32 D_80364A58;
extern s32 D_80364A5C;
extern u8 D_80364A68;
extern u8 D_80364A69;
extern u8 D_80364A6A;
extern u8 D_80364A6B;
extern u8 D_80364A6C;
extern u8 D_80364A6D;
extern u8 D_80364A6F;
extern u8 D_80364A70;
extern u8 D_80364A84;
extern u8 D_80364A86;
extern s32 D_80364AA8;
extern f32 D_80364AB4;
extern f32 D_80364AB8;
extern f32 D_80364ABC;
extern u8 D_80364AC0;
extern u8 D_80364AC1;
extern u8 D_80364AE8;
extern UnkStruct_80364AF0 D_80364AF0[];
extern s32 D_8036506C;
extern u8 D_80365580;
extern s32 D_803669B4;
extern u16 D_80366A12;
extern s32 D_80367738;
extern s16 D_80367BD6;
extern u8 D_80367BFF;
extern s16 D_8036BB18;
extern s16 D_8036BB1C;
extern u64 *D_8036E694;
extern s32 D_8036EA70;
extern u8 D_8036EB99;
extern u8 D_80370C1E;
extern u8 D_80370C21;
extern u8 D_80370C24;
extern u8 D_80370C27;
extern u16 D_80370C28;
extern u8 D_80370C50;
extern u8 D_8039C4B0;
extern u8 D_8039CA60;
extern u8 D_8039CA61;
extern u8 D_8039CA62;
extern u8 D_8039CAA2;
extern u8 D_8039CAB7;
extern u8 D_803A6B04;
extern u8 D_803A7430;
extern u8 D_803B9888;
extern Gfx *D_803BE6E0;
extern Gfx *D_803BE6E4;
extern Gfx *D_803BE6E8;
extern Gfx *D_803BE6EC;
extern u8 D_803C5770[];
extern u8 D_803C6370[];
extern u8 D_803C6F70[];
extern u8 D_803C7B70[];
extern s8 D_803ED3F5;
extern u8 D_803ED40D;
extern s32 D_803ED808;
extern s32 D_803ED80C;
extern s32 D_803ED810;
extern s16 D_803EF326;
extern s32 D_803EF6DC;
extern s32 D_803EF6E0;
extern s32 D_803EF6E4;
extern u8 D_803EF6FF;
extern void *D_803F7820;
extern void *D_803F7824;
extern u8 D_803FF600[];

void func_801F7850(void);
void func_80244870(void *);
void func_80244930(void *);
s32 func_8024AFA8(u8);
void func_8024F520(Gfx **, UnkStruct_02000000 *);
/* K&R definitions below: they read their u8 argument back from its stack slot. */
void func_8024E4F4();
void func_8024FC2C();
void func_802502EC(void);
void func_802507C8(Mtx *, LookAt *, Mtx *);
u8 func_80255628(void);
void func_802558C8(Gfx *, s32 *);
void func_802559F8(Gfx *, s32 *);
void func_8025615C(s32, u8 *, s32 *);
void func_80257234(void);
void func_80257490(s32 *, s32);
void func_80258544(void *, s32, s32, s32, f32, Gfx *, void *, void *);
void func_80258B78(Gfx **, void *);
void func_802592F0(void);
void func_80259450(void);
void func_80259C24(Gfx **, void *);
void func_80259CCC(void *, char *, u16 *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_8025BD98(void);
void func_8025E2CC(Gfx **, void *, s32);
void func_8025E67C(Gfx **, void *, u8);
u8 func_80260634(s32);
void func_80260650(s32, s32, s32 *);
void func_80261588(void);
u8 func_80261A44(u64);
void func_80262150(u8);
void func_802621DC(u8);
void func_80262238(u8);
void func_80262320(s32);
void func_80264C20(s32);
void func_80266248(Gfx **, void *);
void func_80268664(s32);
void func_8026A378(s32, char *);
void func_8026A8BC(void);
void func_8026A974(void);
void func_8026A988(void);
void func_8026AD30(s32);
void func_8026B118(s32);
s32 func_8026F92C(u64);
void func_802701A8(Gfx **, void *);
void func_80270AE0(u32 *);
void func_80270D20(void *, void *, OSPri, u8, u8);
void func_80270E50(void *, void *, OSMesgQueue *, s32, s32);
Gfx *func_80271FD0(Gfx *, void *, u16, s16, s16, s32 *);
void func_802729F0(u16, u16);
void func_80272C50(void);
s8 func_80272C5C(u8 *, s32, s32, s32, s32, f32);
void func_80274B40(Gfx **, void *, u8, s16, s16);
s32 func_802753C0(void);
void func_80275430(void);
void func_80275478(void *, Gfx **, u8);
void func_80276E50(Gfx **, void *, u8, s32, s32, s32);
void func_802775C0(void);
void func_80278324(Gfx **, void *, u8);
void func_80278E3C(void);
void func_802794E4(void);
void func_80279EE8(Gfx **, void *, u8);
void func_8027BE4C(void);
void func_8027C4C8(Gfx **, void *);
void func_8027E344(s32);
void func_8027F1F8(Gfx **, u8, u8);
void func_802807D8(u8);
void func_80280F34(Gfx **, u8);
void func_80281A70(s32);
void func_80281E44(Gfx **);
void func_802821D0(void);
void func_80282224(Gfx **, u8);
void func_80282728(void);
void func_8028273C(Gfx **, u8);
void func_80282C80(Gfx **, void *, s32, s32, s32, s32, s32, s32);
void func_8028376C(Gfx **, void *, u8, s32, s32, s32, s32);
void func_80284DB0(void);
void func_80285110(u32);
void func_80285190(void);
void func_80285CC0(void);
void func_80286A00(void);
void func_80286C60(Gfx **, void *, u8, u8);
void func_802873AC(void);
void func_80287530(Gfx **, void *, s32, u8);
void func_80287AE4(void);
void func_80287C68(Gfx **, void *, s32, u8);
void func_80288220(void);
void func_80288DF0(Gfx **, u8);
u8 func_8028A370(void);
void func_8028A42C(void);
void func_8028AE88(void);
void func_8028B3E0(void);
void func_8028B4C4(u8 *, u8 *, s32 *, s32, s32, s32);
void func_8028B720(void);
void func_8028CB30(Gfx **, void *);
void func_8028E9E4(Gfx **, void *);
void func_8028F6B4(u8);
void func_8028FC10(void);
void func_802917B0(Gfx **, void *);
void func_80291ED8(u8);
void func_80292240(void);
void func_80292EB8(Gfx **, void *);
void func_80294E30(void);
void func_80294E88(void);
void func_80294EB8(void);
void func_80295120(Gfx **, void *);
void func_80297530(u8);
void func_802976E8(Gfx **);
void func_802979E0(u8);
void func_8029A7E4(char *, ...);
void func_802A0700(void);
void func_802A1674(u8 *, s32);
void func_802A45D4(s32);
void func_802A467C(s32, Gfx *, Vtx *, s32);
void func_802A56C4(void);
void func_802A5FA8(void);
void func_802AB478(u8);
void func_802AB670(u8);
s32 func_802AB878(u8);
s32 func_802AC4C4(s32, s32, s32, s32, s32, s32, s32, s32);
void func_802AC61C(s32, s32, s32, s32, s32);
void func_802AE860(void);
void func_802C1DD0(s32);
void func_802CE840(void);
Gfx *func_802CEEFC(Gfx *, u8, void *, void *);
void func_802CF628(void);
void osCreatePiManager(OSPri, OSMesgQueue *, OSMesg *, s32);
f32 sqrtf(f32);
float fcos(float);
void osScRemoveClient(void *, void *);

void func_802447C0(void) {
    u32 sp74;
    s32 pad[2];
    s32 sp68;
    u32 sp28[16];
    s32 pad2;

    osInitialize();
    sp68 = 0xFFB000;
    for (sp74 = 0; sp74 < 16; sp74++, sp68 += 4) {
        osPiRawReadIo(sp68, &sp28[sp74]);
    }
    func_80270AE0(sp28);
    osCreateThread(&D_80310820, 1, func_80244870, NULL, &D_803109D0[0x200 / sizeof(u64)], 10);
    osStartThread(&D_80310820);
}

void func_80244870(void *arg0) {
    s32 pad[2];

    osDpSetStatus(4);
    osCreatePiManager(150, &D_80314D80, D_80314D98, 194);
    osCreateThread(&D_80310BD0, 3, func_80244930, arg0, &D_80310D80[0x2000 / sizeof(u64)], 10);
    osStartThread(&D_80310BD0);
    if (D_802FA254 == 0) {
        osStartThread(&D_80310BD0);
    }
    osSetThreadPri(NULL, 0);
    for (;;) {
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/00000/func_80244930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/00000/func_802475D8.s")

void func_8024A348(void) {
    if (D_80364A40 != 0) {
        if (D_80364A3D + 1 != D_80364A3C && (D_80364A3D != 4 || D_80364A3C != 0)) {
            D_80364A00[D_80364A3D].unk0 = D_80364A40;
            D_80364A00[D_80364A3D].unk9 = 30;
            if (D_8036443E >= 0xE00 || D_8036443E < 0x200) {
                if (D_80364AA8 == 8) {
                    D_80364A00[D_80364A3D].unk4 = 30;
                    D_80364A00[D_80364A3D].unk6 = 60;
                    D_80364A00[D_80364A3D].unk8 = 1;
                } else {
                    D_80364A00[D_80364A3D].unk4 = 30;
                    D_80364A00[D_80364A3D].unk6 = 30;
                    D_80364A00[D_80364A3D].unk8 = 1;
                }
            }
            if (D_8036443E >= 0x200 && D_8036443E < 0x600) {
                D_80364A00[D_80364A3D].unk4 = 30;
                D_80364A00[D_80364A3D].unk6 = 160;
                D_80364A00[D_80364A3D].unk8 = 1;
            }
            if (D_8036443E >= 0x600 && D_8036443E < 0xA00) {
                D_80364A00[D_80364A3D].unk4 = 250;
                D_80364A00[D_80364A3D].unk6 = 160;
                D_80364A00[D_80364A3D].unk8 = 0;
            }
            if (D_8036443E >= 0xA00 && D_8036443E < 0xE00) {
                D_80364A00[D_80364A3D].unk4 = 250;
                D_80364A00[D_80364A3D].unk6 = 37;
                D_80364A00[D_80364A3D].unk8 = 0;
            }
            D_80364A3D++;
            if (D_80364A3D == 5) {
                D_80364A3D = 0;
            }
        }
        D_80364A40 = 0;
    }
    if (D_80364A3C != D_80364A3D) {
        D_80364A44 = D_80364A00[D_80364A3C].unk0;
        D_80364A4A = D_80364A00[D_80364A3C].unk4;
        D_80364A4C = D_80364A00[D_80364A3C].unk6;
        D_80364A4E = D_80364A00[D_80364A3C].unk8;
        if (D_80364A00[D_80364A3C].unk9 >= 16) {
            D_80364A48 = 255.0f - ((D_80364A00[D_80364A3C].unk9 - 15) / 15.0f) * 255.0f;
        } else {
            D_80364A48 = (D_80364A00[D_80364A3C].unk9 / 15.0f) * 255.0f;
        }
        if (!(D_80364A00[D_80364A3C].unk9--)) {
            D_80364A3C++;
            if (D_80364A3C == 5) {
                D_80364A3C = 0;
            }
        }
    } else {
        D_80364A44 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/00000/func_8024A92C.s")

void func_8024ADD8(void) {
    u32 sp4;

    D_803649F4 = (sp4 = D_803649F0 - D_803649F4) / 10 + D_803649F4;
    D_803649F4 = D_803649F4 + 10;
    if (D_803649F0 < D_803649F4) {
        D_803649F4 = D_803649F0;
    }
}

void func_8024AE2C(void) {
    s32 pad;

    if (D_803649ED != 0 && D_803649ED != 0xFF) {
        if (func_802AB878(D_803649ED) == 0) {
            func_802AB478(D_803649ED);
            func_8028F6B4(D_803649ED);
            func_80291ED8(D_803649ED);
            func_8028B720();
            func_802794E4();
            if (func_8024AFA8(D_803649ED) != 0) {
                D_80364456 = D_803649ED;
                func_802AE860();
                if (D_802E8BD0 == 0 && D_80358060 >= 11 &&
                    (D_80364456 == 8 || D_80364456 == 15 || D_80364456 == 13 || D_80364456 == 14)) {
                    func_8026AD30(0x4A);
                }
            }
            D_80364AF0[D_80364AE8].unk10 |= 1 << D_80364456;
            D_803649E8 = 1;
            D_803649EC = 1;
            D_803649EE = 1;
        } else if (func_80260634(D_803156F0) == 0) {
            func_80260650(D_80367738, 0x2B, &D_803156F0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/00000/func_8024AFA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/00000/func_8024B188.s")

s32 func_8024B418(u8 arg0) {
    s32 sp4;

    sp4 = 0;
    while (&D_80364460[sp4] != D_803649D0) {
        if (D_80364460[sp4].unk5C == arg0) {
            return 1;
        }
        sp4++;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/00000/func_8024B4B8.s")

void func_8024B5E8(void) {
    D_803ED3F5 = 1;
    func_802AB670(D_80364456);
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/00000/func_8024B618.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/00000/func_8024B7AC.s")

void func_8024B8F4(Mtx *arg0, Mtx *arg1) {
    Gfx spF8[50];
    Gfx *gfx = spF8;
    Vtx sp70[8];
    s32 sp6C;

    for (sp6C = 0; sp6C < 8; sp6C++) {
        sp70[sp6C].v.flag = 0;
        sp70[sp6C].v.tc[0] = 0;
        sp70[sp6C].v.tc[1] = 0;
        sp70[sp6C].v.cn[0] = 0;
        sp70[sp6C].v.cn[1] = 0;
        sp70[sp6C].v.cn[2] = 0;
        sp70[sp6C].v.cn[3] = 0;
    }
    gSPSegment(gfx++, 0, 0);
    gSPSegment(gfx++, 1, osVirtualToPhysical(D_8035806C));
    gSPDisplayList(gfx++, D_01000010);
    gSPMatrix(gfx++, K0_TO_PHYS(arg0), G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPPerspNormalize(gfx++, D_8035807C);
    gSPMatrix(gfx++, K0_TO_PHYS(arg1), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPVertex(gfx++, K0_TO_PHYS(sp70), 8, 0);
    gSP1Triangle(gfx++, 0, 1, 4, 0);
    gSP1Triangle(gfx++, 1, 4, 5, 0);
    gSP1Triangle(gfx++, 0, 3, 4, 0);
    gSP1Triangle(gfx++, 3, 4, 7, 0);
    gSP1Triangle(gfx++, 2, 3, 7, 0);
    gSP1Triangle(gfx++, 2, 6, 7, 0);
    gSP1Triangle(gfx++, 1, 2, 5, 0);
    gSP1Triangle(gfx++, 2, 5, 6, 0);
    gSP1Triangle(gfx++, 4, 5, 6, 0);
    gSP1Triangle(gfx++, 4, 6, 7, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);
    gSP1Triangle(gfx++, 0, 2, 3, 0);
    gDPTileSync(gfx++);
    gSPEndDisplayList(gfx++);
    osWritebackDCache(spF8, (s32)(gfx - spF8) * sizeof(Gfx));
    osWritebackDCache(arg0, sizeof(Mtx));
    osWritebackDCache(arg1, sizeof(Mtx));
    func_802A467C(D_80358074, spF8, sp70, (s32)(gfx - spF8) * sizeof(Gfx));
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/00000/func_8024BDA4.s")

s32 func_8024C404(s32 arg0, s32 arg1, s32 *arg2) {
    *arg2 = 0;
    return arg0;
}

Gfx *func_8024C414(UnkStruct_02000000 *arg0, s32 *arg1) {
    Gfx *gfx = arg0->unk48B0;
    char sp194[16];
    char sp184[16];
    s32 sp180;

    gSPSegment(gfx++, 0, 0);
    gSPSegment(gfx++, 2, osVirtualToPhysical(arg0));
    gSPSegment(gfx++, 1, osVirtualToPhysical(D_8035806C));
    gSPDisplayList(gfx++, D_01000038);
    gSPDisplayList(gfx++, D_01000010);
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_FILL);
    gSPClearGeometryMode(gfx++, G_ZBUFFER);
    gDPSetDepthImage(gfx++, D_80358058);
    gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, D_80358058);
    gDPSetFillColor(gfx++, 0xFFFCFFFC);
    gDPFillRectangle(gfx++, 0, 0, 319, 239);
    guTranslate(&arg0->unk0[7], 0.0f, 0.0f, 0.0f);
    guOrtho(&arg0->unk0[3], 0.0f, 319.0f, 239.0f, 0.0f, D_80308798, D_8030879C, 1.0f);
    guOrtho(&arg0->unk0[4], 0.0f, 1279.0f, 959.0f, 0.0f, D_803087A0, D_803087A4, 1.0f);
    func_802507C8(&arg0->unk0[5], &arg0->unk3C00, &arg0->unk0[6]);
    gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, D_80358050[D_8035805C]);
    gfx = func_80271FD0(gfx, arg0, D_802E8BDC, D_80364452, D_80364454, &sp180);
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_FILL);
    switch (D_802E8BDC) {
        case 13:
        case 14:
        case 16:
        case 52:
            gDPSetFillColor(gfx++, 0xD55FD55F);
            break;
        case 15:
            gDPSetFillColor(gfx++, 0x10511051);
            break;
        default:
            gDPSetFillColor(gfx++, 0x00010001);
            break;
    }
    gDPPipeSync(gfx++);
    gDPFillRectangle(gfx++, 0, (sp180 <= 0) ? 0 : sp180 - 1, 319, 239);
    gDPPipeSync(gfx++);
    gSPLookAt(gfx++, &D_02000000.unk3C00);
    gSPMatrix(gfx++, &D_02000000.unk0[2], G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPMatrix(gfx++, &D_02000000.unk0[5], G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH);
    gSPMatrix(gfx++, &D_02000000.unk0[7], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPPerspNormalize(gfx++, D_8035807C);
    switch (D_80364A90) {
        case 0x40:
        case 0x400:
            guPerspective(&arg0->unk0[2], &D_8035807C, D_80364438, 4.0f / 3.0f, 10.0f, D_803087A8, 1.0f);
            break;
        case 1:
        case 0x800:
        case 0x1000:
            guPerspective(&arg0->unk0[2], &D_8035807C, D_80364438, 4.0f / 3.0f, 10.0f, D_803087AC, 1.0f);
            break;
        default:
            guPerspective(&arg0->unk0[2], &D_8035807C, D_80364438, 4.0f / 3.0f, 10.0f, D_803087B0, 1.0f);
            break;
    }
    gDPSetColorDither(gfx++, G_CD_MAGICSQ);
    gSPClipRatio(gfx++, FRUSTRATIO_3);
    func_8027F1F8(&gfx, D_8035805C, 0);
    gSPSegment(gfx++, 8, K0_TO_PHYS(D_80364458));
    gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
    gSPDisplayList(gfx++, osVirtualToPhysical(D_80358030[D_8035805C]));
    gSPDisplayList(gfx++, D_803BE6E0);
    gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
    gSPSetGeometryMode(gfx++, G_ZBUFFER);
    gSPDisplayList(gfx++, osVirtualToPhysical(D_80358038[D_8035805C]));
    gSPDisplayList(gfx++, D_803BE6E4);
    if (D_803643D6 == 0 && D_803643D7 == 0) {
        gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
        gSPSetGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH | G_CULL_BACK | G_LOD);
        gSPDisplayList(gfx++, D_02000000.unk21410);
        gDPPipeSync(gfx++);
    }
    switch (D_8035805C) {
        case 0:
            gSPSegment(gfx++, 10, osVirtualToPhysical(D_803F7820));
            break;
        case 1:
            gSPSegment(gfx++, 10, osVirtualToPhysical(D_803F7824));
            break;
    }
    gDPPipeSync(gfx++);
    gSPSetGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH | G_CULL_BACK);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetCombineMode(gfx++, G_CC_SHADE, G_CC_SHADE);
    gSPDisplayList(gfx++, D_02000000.unkA4E0);
    if (!(D_80364A90 & 0x440)) {
        func_8027C4C8(&gfx, arg0);
    }
    func_802502EC();
    func_8024E4F4(&gfx, arg0, 0);
    func_80258B78(&gfx, arg0);
    if (D_802E8BD0 == 0 && D_80364AA8 != 0x40 && !(D_80364A90 & 0x440) && D_80364A84 == 0) {
        func_80279EE8(&gfx, arg0, D_8035805C);
    }
    gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
    gSPSetGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH | G_CULL_BACK | G_LOD);
    gSPDisplayList(gfx++, D_02000000.unkA580);
    gDPPipeSync(gfx++);
    gfx = func_802CEEFC(gfx, D_8035805C, arg0->unkA3A0, arg0->unk11C0);
    func_8024E4F4(&gfx, arg0, 1);
    if (D_803643DC != 0) {
        func_8024F520(&gfx, arg0);
    }
    func_802701A8(&gfx, arg0);
    func_80281E44(&gfx);
    func_8028E9E4(&gfx, arg0);
    func_802917B0(&gfx, arg0);
    func_80292EB8(&gfx, arg0);
    func_8028CB30(&gfx, arg0);
    switch (D_8035805C) {
        case 0:
            gSPDisplayList(gfx++, osVirtualToPhysical(D_803C5770));
            break;
        case 1:
            gSPDisplayList(gfx++, osVirtualToPhysical(D_803C6370));
            break;
    }
    func_80288DF0(&gfx, D_8035805C);
    if (!(D_80364A90 & 2) || D_802E8BF0 == 0) {
        func_8024FC2C(&gfx, 0);
    }
    func_802976E8(&gfx);
    gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
    gSPSetGeometryMode(gfx++, G_ZBUFFER);
    gSPDisplayList(gfx++, osVirtualToPhysical(D_80358040[D_8035805C]));
    gSPDisplayList(gfx++, D_803BE6E8);
    if (!(D_80364A90 & 2) || D_802E8BF0 == 0) {
        func_8024FC2C(&gfx, 1);
    }
    gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
    gSPSetGeometryMode(gfx++, G_ZBUFFER);
    gSPDisplayList(gfx++, osVirtualToPhysical(D_80358048[D_8035805C]));
    gSPDisplayList(gfx++, D_803BE6EC);
    gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
    gSPSetGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH | G_CULL_BACK | G_LOD);
    gSPDisplayList(gfx++, D_02000000.unkA918);
    gDPPipeSync(gfx++);
    if (D_803643D6 == 0 && D_803643D7 == 0) {
        gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
        gSPSetGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH | G_CULL_BACK | G_LOD);
        gSPDisplayList(gfx++, D_02000000.unk21478);
        gDPPipeSync(gfx++);
    }
    if (!(D_80364A90 & 2) || D_802E8BF0 == 0) {
        func_8024FC2C(&gfx, 2);
    }
    func_80295120(&gfx, arg0);
    if (D_80364A90 & 0x2000001000003905LL) {
        func_80280F34(&gfx, D_8035805C);
    }
    func_8027F1F8(&gfx, D_8035805C, 1);
    func_8024E4F4(&gfx, arg0, 2);
    if (D_803643DC != 0) {
        func_80266248(&gfx, arg0);
    }
    switch (D_8035805C) {
        case 0:
            gSPDisplayList(gfx++, osVirtualToPhysical(D_803C6F70));
            break;
        case 1:
            gSPDisplayList(gfx++, osVirtualToPhysical(D_803C7B70));
            break;
    }
    if (D_803643DB != 0) {
        func_8028273C(&gfx, D_8035805C);
    }
    if (D_80364A68 != 0 && (D_80364A90 & 0x104)) {
        func_80286C60(&gfx, arg0, D_8035805C, D_80364456);
    }
    if (D_80364A90 & 0x200000000400220CLL) {
        func_80278324(&gfx, arg0, D_8035805C);
    }
    if (D_80364A90 == 0x100 && D_803643DB != 0) {
        func_80276E50(&gfx, arg0, D_8035805C, D_803643E0, D_803643E4, D_803643E8);
    }
    func_80259450();
    if (D_80364A6A != 0 && (D_80364A90 & 0x104)) {
        func_80287530(&gfx, arg0, D_8035805C, D_80364456);
    }
    if (D_80364A6C != 0 && (D_80364A90 & 0x104)) {
        func_80287C68(&gfx, arg0, D_8035805C, D_80364456);
    }
    if (D_80364A90 & 0x104) {
        func_80282224(&gfx, D_80364456);
    }
    if ((D_80364AA8 & 1) && (D_80364A90 & 0x0400030C)) {
        func_8026A378(D_803649F4, &sp194[1]);
        sp194[0] = 0x24;
        func_80259CCC(arg0, sp194, NULL, 1, 0, 280, 18, 20, 20, 0, 0xFF, 0xFF, 0xFF, D_80367BD6);
        if (D_80364A44 != 0 && D_802E8BD0 == 0) {
            func_8026A378(D_80364A44, &sp184[1]);
            sp184[0] = 0x24;
            func_80259CCC(arg0, sp184, NULL, 1, 0, D_80364A4A, D_80364A4C, 35, 35, D_80364A4E, 0xFF, 0xFF, 0xFF,
                          D_80364A48);
        }
    }
    if ((D_80364A90 & 0x2000000000000104LL) && (!(D_80364AA8 & 0x81) || D_803643DB != 0 || D_80364AC1 != 0)) {
        func_80275478(arg0, &gfx, (D_80364A90 & 0x100) != 0 || D_8036BB18 == 0x4D || D_8036BB18 == 0x49);
    }
    if (D_80364A98 == 0 && func_802753C0() == 0) {
        if (!(D_80364A90 & 0x200000100400230CLL) && (D_803156C4 % 50) * 60 / 60 >= 21 && D_8036BB1C == 1 &&
            (!(D_80364A90 & 2) || (D_802E8BEC != 0 && (D_80366A12 == 3 || D_802E8BEC == 1))) &&
            (D_80364A90 != 0x100000000000LL || D_803A6B04 != 0) &&
            (!(D_80364A90 & 0x1801) || D_80364AF0[D_80364AE8].unk91 != 0) && D_802E8BDC != 0x2F) {
            func_80259CCC(arg0, D_8030821C, NULL, 1, 0, 92, 196, 26, 26, 1, 0xFF, 0xFF, 0xFF, 0xFF);
        }
        if ((D_803156C4 % 40) * 60 / 60 >= 16) {
            if (D_802E8BD0 != 0) {
                if (D_80364A90 == 0x2000000000000000LL && D_8036BB1C == 2) {
                    func_80259CCC(arg0, D_80308228, D_8030491C, 0, 0, 24, 20, 15, 15, 1, 0xFF, 0xFF, 0xFF, 0xFF);
                } else if (D_80364A90 == 0x100 && D_8036BB18 == 0 && D_8036BB1C == 2 && D_803643DB != 0 &&
                           !(D_80370C28 & 0x2010)) {
                    func_80259CCC(arg0, D_80308240, D_80304938, 0, 0, 24, 20, 15, 15, 1, 0xFF, 0xFF, 0xFF, 0xFF);
                }
            } else if (D_80364A90 == 0x100) {
                if (D_80364AC1 != 0) {
                    func_80259CCC(arg0, D_80308254, D_80304904, 0, 0, 24, 20, 15, 15, 1, 0xFF, 0xFF, 0xFF, 0xFF);
                } else {
                    func_80259CCC(arg0, D_80308264, D_80304910, 0, 0, 24, 20, 15, 15, 1, 0xFF, 0xFF, 0xFF, 0xFF);
                }
            }
        }
    }
    if (((D_80364A90 & 0x440) || D_802E8BDC == 0x26) && D_8036BB1C == 1 && func_802753C0() == 0) {
        if ((D_80364A90 & 0x440) && D_80364AA8 != 1) {
            func_80274B40(&gfx, arg0, D_80365580, 264, 18);
        } else {
            func_80274B40(&gfx, arg0, D_80365580, 24, 18);
        }
    }
    if ((D_80364A90 & 0x104) && D_80364410 != 0) {
        func_80274B40(&gfx, arg0, D_80364A86, 264, 190);
    }
    if ((D_80364A90 & 0x104) && D_80364AA8 == 1 && D_802E8BD0 == 0) {
        func_80285CC0();
    }
    if (D_803643DB != 0 && D_80364A90 == 4) {
        func_80282C80(&gfx, arg0, D_803643E0, D_803643E4, D_803643E8, D_803EF6DC, D_803EF6E0, D_803EF6E4);
    }
    if ((D_802E8F94[D_802E8BDC].unk0 & 0x81) && D_80364A90 == 4) {
        if (D_802E8BDC != 0x32 ||
            ((D_80364AF0[D_80364AE8].unk18[0x32] > 0 && D_80364AF0[D_80364AE8].unk18[0x32] < 6) ? 1 : 0)) {
            func_8028376C(&gfx, arg0, D_8035805C, D_803643E0, D_803643E8, D_803EF6DC, D_803EF6E4);
        }
    }
    if (D_803643DB != 0 || D_80364AC1 != 0) {
        switch (D_80364A90) {
            case 4:
            case 0x100:
            case 0x200:
            case 0x100000000000LL:
                func_8025E2CC(&gfx, arg0, D_8035805C);
                func_8025E67C(&gfx, arg0, D_8035805C);
            case 0x40:
            case 0x400:
                if ((D_803643D6 != 0 || D_803643D7 != 0 || D_803643D9 != 0 || D_803643DA != 0) &&
                    (D_80364A90 & 0x144)) {
                    func_802A45D4(50);
                    if (D_80364A90 == 0x40) {
                        D_80364A98 = 0x400;
                    } else {
                        D_80364A98 = 0x200;
                    }
                }
                break;
        }
    }
    func_80259C24(&gfx, arg0);
    *arg1 = ((u8 *)gfx - (u8 *)arg0 - 0x48B0) >> 3;
    return gfx;
}

void func_8024E4F4(arg0, arg1, arg2)
    Gfx **arg0;
    UnkStruct_02000000 *arg1;
    u8 arg2;
{
    Gfx *gfx = *arg0;
    s32 sp140;
    s16 pad;
    s16 sp13C;
    s16 sp13A;
    s16 sp138;
    s16 sp136;
    s16 sp134;
    u8 sp133;
    f32 spF0[4][4];
    f32 spB0[4][4];
    s16 spAE;
    s16 spAC;
    u8 spAB;

    if (arg2 == 0) {
        D_8036506C = 0;
    }
    gDPPipeSync(gfx++);
    gDPSetTexturePersp(gfx++, G_TP_PERSP);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
    gSPSetGeometryMode(gfx++, G_SHADE | G_SHADING_SMOOTH | G_CULL_BACK | G_LOD);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetCombineMode(gfx++, G_CC_MODULATEIA, G_CC_MODULATEIA);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gDPSetRenderMode(gfx++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
    sp133 = D_803649E8 == 0 && (D_803649EC != 0 || (D_80364A90 & 0x1801) != 0);
    sp140 = 0;
    while (&D_803643C8[sp140] != D_803643CC) {
        if ((D_803643C8[sp140].unk1022 != 0 || sp133 != 0) && D_803643C8[sp140].unk1022 != 0xFE &&
            (D_803643C8[sp140].unk1022 != 0xFF || D_803EF6FF == 0) &&
            (D_803643C8[sp140].unk1022 == 0xFD || D_80364A84 == 0 || D_80364AC1 == 0) &&
            D_803643C8[sp140].unk1023 == arg2) {
            sp13C = D_803643C8[sp140].unk1004 >> 5;
            sp13A = D_803643C8[sp140].unk1008 >> 5;
            sp138 = D_803643C8[sp140].unk100C >> 5;
            sp136 = D_803643C8[sp140].unk1018;
            sp134 = D_803643C8[sp140].unk101A;
            spAB = D_803643C8[sp140].unk1022 == D_80364456 && D_803ED40D == 0x65;
            if (spAB != 0) {
                guRotateF(spB0, (f32)D_80364440 * D_803087B8 / 4096.0, 0.0f, 1.0f, 0.0f);
            }
            guRotateF(spF0, (f32)-D_803643C8[sp140].unk101E * D_803087C0 / 4096.0, 0.0f, 1.0f, 0.0f);
            if (spAB != 0) {
                guMtxCatF(spB0, spF0, spF0);
            }
            guRotateF(spB0, (f32)D_803643C8[sp140].unk101C * D_803087C8 / 4096.0, 1.0f, 0.0f, 0.0f);
            guMtxCatF(spF0, spB0, spB0);
            guRotateF(spF0, (f32)D_803643C8[sp140].unk1020 * D_803087D0 / 4096.0, 0.0f, 0.0f, 1.0f);
            guMtxCatF(spB0, spF0, spF0);
            guRotateF(spB0, (f32)D_803643C8[sp140].unk101E * D_803087D8 / 4096.0, 0.0f, 1.0f, 0.0f);
            guMtxCatF(spF0, spB0, spF0);
            guTranslateF(spB0, sp13C, sp13A, sp138);
            guMtxCatF(spF0, spB0, spF0);
            guMtxF2L(spF0, &arg1->unk2C0[sp140]);
            if (spAB != 0) {
                gDPLoadTextureBlock(gfx++, OS_K0_TO_PHYSICAL(D_802FA940), G_IM_FMT_IA, G_IM_SIZ_8b, 32, 32, 0,
                                    G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                spAE = 32, spAC = 32;
            } else {
                gDPLoadTextureBlock(gfx++, K0_TO_PHYS(D_803643C8[sp140].unk0), G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64, 0,
                                    G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                spAE = 64, spAC = 64;
            }
            arg1->unk15C0[D_8036506C].v.ob[0] = -sp136;
            arg1->unk15C0[D_8036506C].v.ob[1] = 0;
            arg1->unk15C0[D_8036506C].v.ob[2] = sp134;
            arg1->unk15C0[D_8036506C].v.flag = 0;
            arg1->unk15C0[D_8036506C].v.tc[0] = (spAE - 1) << 5;
            arg1->unk15C0[D_8036506C].v.tc[1] = (spAC - 1) << 5;
            arg1->unk15C0[D_8036506C].v.cn[0] = 10;
            arg1->unk15C0[D_8036506C].v.cn[1] = 10;
            arg1->unk15C0[D_8036506C].v.cn[2] = 10;
            arg1->unk15C0[D_8036506C].v.cn[3] = 140;
            D_8036506C++;
            arg1->unk15C0[D_8036506C].v.ob[0] = sp136;
            arg1->unk15C0[D_8036506C].v.ob[1] = 0;
            arg1->unk15C0[D_8036506C].v.ob[2] = sp134;
            arg1->unk15C0[D_8036506C].v.flag = 0;
            arg1->unk15C0[D_8036506C].v.tc[0] = 0;
            arg1->unk15C0[D_8036506C].v.tc[1] = (spAC - 1) << 5;
            arg1->unk15C0[D_8036506C].v.cn[0] = 10;
            arg1->unk15C0[D_8036506C].v.cn[1] = 10;
            arg1->unk15C0[D_8036506C].v.cn[2] = 10;
            arg1->unk15C0[D_8036506C].v.cn[3] = 140;
            D_8036506C++;
            arg1->unk15C0[D_8036506C].v.ob[0] = sp136;
            arg1->unk15C0[D_8036506C].v.ob[1] = 0;
            arg1->unk15C0[D_8036506C].v.ob[2] = -sp134;
            arg1->unk15C0[D_8036506C].v.flag = 0;
            arg1->unk15C0[D_8036506C].v.tc[0] = 0;
            arg1->unk15C0[D_8036506C].v.tc[1] = 0;
            arg1->unk15C0[D_8036506C].v.cn[0] = 10;
            arg1->unk15C0[D_8036506C].v.cn[1] = 10;
            arg1->unk15C0[D_8036506C].v.cn[2] = 10;
            arg1->unk15C0[D_8036506C].v.cn[3] = 140;
            D_8036506C++;
            arg1->unk15C0[D_8036506C].v.ob[0] = -sp136;
            arg1->unk15C0[D_8036506C].v.ob[1] = 0;
            arg1->unk15C0[D_8036506C].v.ob[2] = -sp134;
            arg1->unk15C0[D_8036506C].v.flag = 0;
            arg1->unk15C0[D_8036506C].v.tc[0] = (spAE - 1) << 5;
            arg1->unk15C0[D_8036506C].v.tc[1] = 0;
            arg1->unk15C0[D_8036506C].v.cn[0] = 10;
            arg1->unk15C0[D_8036506C].v.cn[1] = 10;
            arg1->unk15C0[D_8036506C].v.cn[2] = 10;
            arg1->unk15C0[D_8036506C].v.cn[3] = 140;
            D_8036506C++;
            if (D_803643D6 != 0 && !(D_80364AA8 & 0x81) && D_803643C8[sp140].unk1022 == D_80364456) {
                gSPMatrix(gfx++, &D_02000000.unk1540, G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
            }
            gSPMatrix(gfx++, &D_02000000.unk2C0[sp140], G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
            gSPVertex(gfx++, &D_02000000.unk15C0[D_8036506C - 4], 4, 0);
            gSP1Triangle(gfx++, 0, 1, 2, 0);
            gSP1Triangle(gfx++, 0, 2, 3, 0);
            gSPPopMatrix(gfx++, G_MTX_MODELVIEW);
            if (D_803643D6 != 0 && !(D_80364AA8 & 0x81) && D_803643C8[sp140].unk1022 == D_80364456) {
                gSPPopMatrix(gfx++, G_MTX_MODELVIEW);
            }
            gDPPipeSync(gfx++);
        }
        sp140++;
    }
    *arg0 = gfx;
}

void func_8024F520(Gfx **arg0, UnkStruct_02000000 *arg1) {
    Gfx *gfx = *arg0;
    s32 sp88;
    u8 sp87;
    s16 sp84;
    s16 sp82;
    s16 sp80;
    s16 sp7E;
    s16 sp7C;

    gDPPipeSync(gfx++);
    gDPSetTexturePersp(gfx++, G_TP_PERSP);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
    gSPSetGeometryMode(gfx++, G_SHADE | G_SHADING_SMOOTH | G_CULL_BACK | G_LOD);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetCombineMode(gfx++, G_CC_MODULATEIA, G_CC_MODULATEIA);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gDPSetRenderMode(gfx++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
    sp87 = 0;
    sp88 = 0;
    do {
        if (D_803643C8[sp88].unk1022 == 0xFE) {
            sp87 = 1;
        } else {
            sp88++;
        }
    } while (sp87 == 0);
    gDPLoadTextureBlock(gfx++, K0_TO_PHYS(D_803643C8[sp88].unk0), G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64, 0,
                        G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    sp84 = D_803643C8[sp88].unk1004 >> 5;
    sp82 = D_803643C8[sp88].unk1008 >> 5;
    sp80 = D_803643C8[sp88].unk100C >> 5;
    sp7E = D_803643C8[sp88].unk1018;
    sp7C = D_803643C8[sp88].unk101A;
    arg1->unk18C0[0].v.ob[0] = -sp7E;
    arg1->unk18C0[0].v.ob[1] = 0;
    arg1->unk18C0[0].v.ob[2] = sp7C;
    arg1->unk18C0[0].v.flag = 0;
    arg1->unk18C0[0].v.tc[0] = 0x7E0;
    arg1->unk18C0[0].v.tc[1] = 0x7E0;
    arg1->unk18C0[0].v.cn[0] = 10;
    arg1->unk18C0[0].v.cn[1] = 10;
    arg1->unk18C0[0].v.cn[2] = 10;
    arg1->unk18C0[0].v.cn[3] = 140;
    arg1->unk18C0[1].v.ob[0] = sp7E;
    arg1->unk18C0[1].v.ob[1] = 0;
    arg1->unk18C0[1].v.ob[2] = sp7C;
    arg1->unk18C0[1].v.flag = 0;
    arg1->unk18C0[1].v.tc[0] = 0;
    arg1->unk18C0[1].v.tc[1] = 0x7E0;
    arg1->unk18C0[1].v.cn[0] = 10;
    arg1->unk18C0[1].v.cn[1] = 10;
    arg1->unk18C0[1].v.cn[2] = 10;
    arg1->unk18C0[1].v.cn[3] = 140;
    arg1->unk18C0[2].v.ob[0] = sp7E;
    arg1->unk18C0[2].v.ob[1] = 0;
    arg1->unk18C0[2].v.ob[2] = -sp7C;
    arg1->unk18C0[2].v.flag = 0;
    arg1->unk18C0[2].v.tc[0] = 0;
    arg1->unk18C0[2].v.tc[1] = 0;
    arg1->unk18C0[2].v.cn[0] = 10;
    arg1->unk18C0[2].v.cn[1] = 10;
    arg1->unk18C0[2].v.cn[2] = 10;
    arg1->unk18C0[2].v.cn[3] = 140;
    arg1->unk18C0[3].v.ob[0] = -sp7E;
    arg1->unk18C0[3].v.ob[1] = 0;
    arg1->unk18C0[3].v.ob[2] = -sp7C;
    arg1->unk18C0[3].v.flag = 0;
    arg1->unk18C0[3].v.tc[0] = 0x7E0;
    arg1->unk18C0[3].v.tc[1] = 0;
    arg1->unk18C0[3].v.cn[0] = 10;
    arg1->unk18C0[3].v.cn[1] = 10;
    arg1->unk18C0[3].v.cn[2] = 10;
    arg1->unk18C0[3].v.cn[3] = 140;
    guTranslate(&arg1->unk0[9], sp84, sp82, sp80);
    guRotate(&arg1->unk0[10], (f32)D_803EF326 * D_803087E0 / 4096.0, 0.0f, 1.0f, 0.0f);
    gSPMatrix(gfx++, &D_02000000.unk0[9], G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    gSPMatrix(gfx++, &D_02000000.unk0[10], G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
    gSPVertex(gfx++, D_02000000.unk18C0, 4, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);
    gSP1Triangle(gfx++, 0, 2, 3, 0);
    gSPPopMatrix(gfx++, G_MTX_MODELVIEW);
    *arg0 = gfx;
}

void func_8024FC2C(arg0, arg1)
    Gfx **arg0;
    u8 arg1;
{
    Gfx *gfx = *arg0;
    s32 sp60;
    u8 pad;
    u8 sp5E;
    u8 sp5D;

    sp5D = D_803649E8 == 0 && (D_803649EC != 0 || (D_80364A90 & 0x1801) != 0);
    sp60 = 0;
    while (&D_80364460[sp60] != D_803649D0) {
        if ((D_80364460[sp60].unk5C != 0 || sp5D != 0) && (D_80364460[sp60].unk5C != 0xFF || D_803EF6FF == 0) &&
            (D_80364460[sp60].unk5C == 0xFD || D_80364A84 == 0 || D_80364AC1 == 0)) {
            gSPSegment(gfx++, 6, osVirtualToPhysical(D_80364460[sp60].unk0));
            if ((D_80364A90 & 0x1801) && (D_80364460[sp60].unk5C == 0xFE || D_80364460[sp60].unk5C == 0)) {
                sp5E = D_8035805C;
            } else {
                sp5E = D_803156F5;
            }
            if (sp5E != 0) {
                gSPSegment(gfx++, 7, osVirtualToPhysical(D_80364460[sp60].unk4));
            } else {
                gSPSegment(gfx++, 7, osVirtualToPhysical(D_80364460[sp60].unk8));
            }
            gDPPipeSync(gfx++);
            gDPSetEnvColor(gfx++, 0, 0, 0, D_80364460[sp60].unk60);
            gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
            if (D_803643D6 != 0 && !(D_80364AA8 & 0x81) && D_80364460[sp60].unk5C == D_80364456) {
                gSPMatrix(gfx++, &D_02000000.unk1500, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
            }
            if (sp5E != 0) {
                switch (arg1) {
                    case 0:
                        gSPDisplayList(gfx++, osVirtualToPhysical(D_80364460[sp60].unkC));
                        break;
                    case 1:
                        gSPDisplayList(gfx++, osVirtualToPhysical(D_80364460[sp60].unk10));
                        break;
                    case 2:
                        gSPDisplayList(gfx++, osVirtualToPhysical(D_80364460[sp60].unk14));
                        break;
                }
            } else {
                switch (arg1) {
                    case 0:
                        gSPDisplayList(gfx++, osVirtualToPhysical(D_80364460[sp60].unk30));
                        break;
                    case 1:
                        gSPDisplayList(gfx++, osVirtualToPhysical(D_80364460[sp60].unk34));
                        break;
                    case 2:
                        gSPDisplayList(gfx++, osVirtualToPhysical(D_80364460[sp60].unk38));
                        break;
                }
            }
            gSPMatrix(gfx++, &D_02000000.unk0[7], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
        }
        sp60++;
    }
    *arg0 = gfx;
}

void func_802502EC(void) {
    f32 sp70[4][4];
    f32 sp30[4][4];
    s32 sp2C;
    s16 sp2A;
    s16 sp28;
    s16 sp26;

    if (D_803643D6 != 0 && !(D_80364AA8 & 0x81)) {
        guTranslateF(sp70, -(f32)D_803643E0 / 32.0, -(f32)D_803643E4 / 32.0, -(f32)D_803643E8 / 32.0);
        guScaleF(sp30, D_80364ABC, D_80364ABC, D_80364ABC);
        guMtxCatF(sp70, sp30, sp70);
        guRotateF(sp30, D_80364AB4, 0.0f, 1.0f, 0.0f);
        guMtxCatF(sp70, sp30, sp70);
        guTranslateF(sp30, (f32)D_803643E0 / 32.0, (f32)D_803643E4 / 32.0, (f32)D_803643E8 / 32.0);
        guMtxCatF(sp70, sp30, sp70);
        guMtxF2L(sp70, (Mtx *)(&D_803156F8[D_8035805C * 0x21498] + 0x1500));
        sp2C = 0;
        while (D_803643C8[sp2C].unk1022 != D_80364456) {
            sp2C++;
        }
        sp2A = D_803643C8[sp2C].unk1004 >> 5;
        sp28 = D_803643C8[sp2C].unk1008 >> 5;
        sp26 = D_803643C8[sp2C].unk100C >> 5;
        guTranslateF(sp70, -sp2A, -sp28, -sp26);
        guScaleF(sp30, D_80364ABC, D_80364ABC, D_80364ABC);
        guMtxCatF(sp70, sp30, sp70);
        guRotateF(sp30, D_80364AB4, 0.0f, 1.0f, 0.0f);
        guMtxCatF(sp70, sp30, sp70);
        guTranslateF(sp30, sp2A, sp28, sp26);
        guMtxCatF(sp70, sp30, sp70);
        guMtxF2L(sp70, (Mtx *)(&D_803156F8[D_8035805C * 0x21498] + 0x1540));
        if (D_80364AC0 == 0) {
            D_80364ABC = D_80364ABC - D_803087E8;
            if (D_80364ABC < 0.0) {
                D_80364ABC = 0.0f;
            }
        }
        if (D_80364ABC == 0.0 && D_80364AC0 == 0) {
            func_802AC61C(D_803643E0, D_803643E4, D_803643E8, 0x13, 400000);
            D_80364AC0 = 1;
        }
        D_80364AB4 += D_80364AB8;
        D_80364AB8 = D_80364AB8 + 3.0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/00000/func_802507C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/00000/func_80254E54.s")

void func_80255034(s32 arg0, f32 arg1, s32 *arg2, s32 *arg3) {
    f32 sp2C;
    f32 sp28;
    s32 sp24;
    s32 sp20;
    f32 sp1C;

    sp28 = arg0 * arg0;
    sp2C = sqrtf(sp28 + sp28);
    sp1C = arg1;
    sp1C = sp1C / D_80308B28;
    sp1C = sp1C * D_80308B30;
    sp24 = sinf(sp1C) * sp2C;
    sp20 = sqrtf(sp2C * sp2C - sp24 * sp24);
    if (arg1 >= D_80308B38 && arg1 < D_80308B40) {
        sp20 = 0.0 - sp20;
    }
    if (sp20 >= -100 && sp20 <= 100) {
        sp20 = 0;
    }
    *arg2 = sp24;
    *arg3 = sp20;
}

void func_80255190(void) {
    u8 sp1F;

    if (D_802E8BD0 == 0) {
        sp1F = func_80255628();
        if (sp1F != 0 && ((D_80370C21 != 0 && D_80370C27 == 0) || (D_80370C1E != 0 && D_80370C24 == 0)) &&
            (D_80364A90 & 0x104)) {
            func_80260650(D_80367738, 0xD0, NULL);
        }
        if (D_80370C21 != 0 && D_80370C27 == 0 && D_8036441C == 0 && D_8036441D == 0 && sp1F == 0 &&
            D_80364A90 != 0x2000) {
            D_80364418 = D_80364414 + D_80308B48;
            if (D_80364418 >= D_80308B50) {
                D_80364418 = D_80364418 - D_80308B58;
            }
            D_8036441C = 1;
            if (D_80364A90 != 0x40) {
                func_80260650(D_80367738, 0xDD, NULL);
            }
        }
        if (D_8036441C != 0) {
            if (D_80364414 < D_80364418) {
                D_80364414 = D_80364414 + 3.0;
                if (D_80364414 >= D_80364418) {
                    D_8036441C = 0;
                    D_80364414 = D_80364418;
                }
            } else {
                D_80364414 = D_80364414 + 3.0;
                if (D_80364414 >= D_80308B60) {
                    D_80364414 = D_80364414 - D_80308B68;
                    if (D_80364414 >= D_80364418) {
                        D_8036441C = 0;
                        D_80364414 = D_80364418;
                    }
                }
            }
        }
        if (D_80370C1E != 0 && D_80370C24 == 0 && D_8036441C == 0 && D_8036441D == 0 && sp1F == 0 &&
            D_80364A90 != 0x2000) {
            D_80364418 = D_80364414 - D_80308B70;
            if (D_80364418 < 0.0) {
                D_80364418 = D_80364418 + D_80308B78;
            }
            D_8036441D = 1;
            if (D_80364A90 != 0x40) {
                func_80260650(D_80367738, 0xDC, NULL);
            }
        }
        if (D_8036441D != 0) {
            if (D_80364414 > D_80364418) {
                D_80364414 = D_80364414 - 3.0;
                if (D_80364414 <= D_80364418) {
                    D_8036441D = 0;
                    D_80364414 = D_80364418;
                }
            } else {
                D_80364414 = D_80364414 - 3.0;
                if (D_80364414 < 0.0) {
                    D_80364414 = D_80364414 + D_80308B80;
                    if (D_80364414 <= D_80364418) {
                        D_8036441D = 0;
                        D_80364414 = D_80364418;
                    }
                }
            }
        }
        if (D_8036441D != 0 || D_8036441C != 0) {
            func_802A45D4(2);
        }
    }
}

u8 func_80255628(void) {
    u8 sp37 = 0;

    if (D_80364A90 == 0x100000000000LL || D_80364A90 == 2) {
        sp37 = 1;
    } else {
        switch (D_802E8BDC) {
            case 4:
                if (func_802AC4C4(D_803643E0 >> 5, D_803643E8 >> 5, 0xE56, 0x8EC, 0xBB8, 0x6A4, 0x1068, 0x1F4) != 0 ||
                    func_802AC4C4(D_803643E0 >> 5, D_803643E8 >> 5, 0xE56, 0x8EC, 0x1068, 0x1F4, 0x1324, 0x4B0) != 0) {
                    sp37 = 1;
                }
                break;
            case 16:
                if (D_803643E0 > 0x46500 && D_803643E8 > 0x3E800) {
                    sp37 = 1;
                }
                break;
            case 13:
                if (D_803643E0 > 0x42680 && D_803643E8 > 0x46500) {
                    sp37 = 1;
                }
                break;
            case 59:
                sp37 = 1;
                break;
        }
    }
    if (sp37 != 0 && (D_80364418 < D_80308B88 || D_80364418 > 136.0)) {
        D_8036441D = 0;
        D_8036441C = 0;
        D_80364418 = 135.0f;
        if (D_80364414 > D_80364418) {
            if (D_80364414 - D_80364418 > D_80308B90) {
                D_8036441C = 1;
            } else {
                D_8036441D = 1;
            }
        } else {
            D_8036441C = 1;
        }
    }
    return sp37;
}

void func_802558C8(Gfx *arg0, s32 *arg1) {
    Gfx *gfx = arg0;

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_FILL);
    gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, D_80358050[D_8035805C]);
    gDPSetFillColor(gfx++, 0x10001);
    gDPPipeSync(gfx++);
    gDPFillRectangle(gfx++, 0, 0, 319, 239);
    *arg1 += gfx - arg0;
}

void func_802559F8(Gfx *arg0, s32 *arg1) {
    Gfx *gfx = arg0;

    gDPFullSync(gfx++);
    gSPEndDisplayList(gfx++);
    *arg1 = ((u8 *)gfx - &D_803156F8[D_8035805C * 0x21498] - 0x48B0) >> 3;
    if (*arg1 >= 0xB5E) {
        func_8029A7E4(D_80308274, D_803082A0, D_803082BC, 3665);
    }
}

void func_80255AD0(void) {
    s32 sp44;
    f32 sp40;
    s32 pad[4];
    u8 sp2F;

    sp40 = 1.0f;
    D_80364A90 = 0x20;
    osCreateMesgQueue(&D_803150A0, D_803150B8, 50);
    osCreateMesgQueue(&D_80315180, D_80315198, 144);
    func_80270D20(D_80315440, &D_80312D80[0x2000 / sizeof(u64)], 13,
                  (D_80000300 != 1) ? OS_VI_PAL_LAN1 : OS_VI_NTSC_LAN1, 1);
    osCreateMesgQueue(&D_803153D8, D_803153F8, 16);
    func_80270E50(D_80315440, D_803156D8, &D_803153D8, 1, 1);
    sp2F = func_8028A370();
    func_80261588();
    func_8029A7E4(D_803082C4);
    osViSetSpecialFeatures(OS_VI_GAMMA_OFF);
    osViSetSpecialFeatures(OS_VI_DITHER_FILTER_ON);
    D_80358050[0] = K0_TO_PHYS(D_80000400[0]);
    D_80358050[1] = K0_TO_PHYS(D_80000400[1]);
    D_80358058 = K0_TO_PHYS(D_8021ED00);
    func_80284DB0();
    osWritebackDCacheAll();
    func_8028FC10();
    if (!(sp2F & 1)) {
        D_80364A98 = 0x0800000000000000LL;
    } else if (D_802FDBD0 != 0) {
        D_80364A98 = 0x0000080000000000LL;
    } else if (D_802FDBD4 != 0) {
        D_80364A98 = 0x0040000000000000LL;
    } else {
        D_80364A98 = 0x10;
    }
    sp44 = 0x1FF;
    do {
        D_80310D80[sp44] = 0x1122334455667788LL;
    } while (--sp44 >= 0);
}

void func_80255D34(void) {
    u8 sp1F = 0;
    s32 sp18 = 0x1FF;

    do {
        if (D_80310D80[sp18] != 0x1122334455667788LL) {
            sp1F = 1;
            func_8029A7E4(D_803082D4, sp18);
        }
    } while (--sp18 >= 0 && sp1F == 0);
}

void func_80255DC8(void) {
    u8 *sp2C;
    s32 pad;
    s32 sp24;
    u8 *sp20;

    sp24 = D_00788000 - D_00787F40;
    osViBlack(TRUE);
    D_80364A70 = func_80261A44(D_80364A98);
    osWritebackDCacheAll();
    osInvalDCache((void *)0x80000000, 0x400000);
    D_803649F4 = 0;
    D_80358068 = 0;
    D_80358064 = 0;
    D_80358060 = 0;
    D_8035805C = 0;
    D_80367BD6 = 0;
    func_8026A8BC();
    func_8026A974();
    func_8028AE88();
    func_8028B720();
    D_8035806C = D_803FF600;
    func_8028B4C4(D_00787F40, D_803FF600, &sp24, 10, 0, 2);
    sp2C = D_803FF600 + (D_00788000 - D_00787F40);
    func_8029A7E4(D_803082E4, sp2C, 0x80400000 - (u32)sp2C, 0x80400000 - (u32)sp2C);
    D_80358078 = 0;
    func_802558C8((Gfx *)(&D_803156F8[D_8035805C * 0x21498] + 0x48B0), &D_80358078);
    func_802559F8((Gfx *)(&D_803156F8[D_8035805C * 0x21498] + 0x48B0), &D_80358078);
    D_80358070 = (u8 *)0x8004B400;
    func_80257490((s32 *)&D_80358070, 16);
    D_8036E694 = (u64 *)D_80358070;
    D_80358070 += 0xA000;
    if (D_802E8F94[D_802E8BDC].unk0 == 2 && !(D_80364A98 & 0x100000000002LL)) {
        func_8029A7E4(D_80308310);
        D_80358070 += 0x20000;
    }
    D_803B9888 = 0;
    func_802A0700();
    D_803643C8 = (UnkStruct_803643C8 *)((u32)&D_80358088[0x40] & ~0x3F);
    func_80278E3C();
    D_803643D9 = 0;
    D_803643DA = 0;
    D_803643D8 = 0;
    D_803643D6 = 0;
    D_803643D7 = 0;
    D_802E8BD8 = 0;
    D_802E8BD4 = 0;
    D_802E8BD0 = 0;
    D_8036EB99 = 0;
    D_803669B4 = 0;
    if (D_80364A98 & 0xC9FD8FE7FBFFC0B0LL) {
        func_8028B3E0();
    }
    func_80297530(D_802E8BDC);
    func_80272C50();
    if (D_80364A98 == 0x40000000000LL) {
        func_801F7850();
    }
    sp20 = D_80358070;
    func_8026B118(0);
    func_8029A7E4(D_80308330, D_80358070 - sp20, D_80358070);
    D_803649D0 = D_80364460;
    func_8028A42C();
    func_802592F0();
    D_8039CAA2 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/00000/func_8025615C.s")

void func_80256A34(s32 arg0) {
    s32 sp4C;
    s32 sp48;
    UnkStruct_803643C8 *sp44;
    u8 sp43;
    u8 *sp3C;

    D_80364A68 = 0;
    D_80364A69 = 0;
    D_80364A6A = 0;
    D_80364A6B = 0;
    D_80364A6C = 0;
    D_80364A6D = 0;
    D_803649E8 = 0;
    D_803649EC = 0;
    D_803643CC = D_803643C8;
    D_80364AA8 = D_802E8F94[D_802E8BDC].unk0;
    D_802E8BE4 = 0;
    D_802E8BE8 = 0;
    D_803643E0 = 0;
    D_803643E4 = 0;
    D_803643E8 = 0;
    D_8036443C = 0;
    D_80364414 = 135.0f;
    D_80364418 = 135.0f;
    D_8036441C = 0;
    D_8036441D = 0;
    D_80364420 = 3000;
    D_80364434 = 1;
    D_803A7430 = 0;
    D_803649EE = 0;
    D_80364A84 = 0;
    D_80364456 = 0;
    if (D_80370C50 != 0) {
        if (D_8039C4B0 != 0) {
            func_8029A7E4(D_80308358, D_80308384, D_80308390, 4162);
        }
        if (D_80219F58 != 0) {
            func_8029A7E4(D_80308398, D_803083C4, D_803083E4, 4163);
        }
        osScRemoveClient(D_80315440, D_80218EE0);
        osDestroyThread(&D_80218D30);
    }
    D_8039CA62 = 0;
    D_8039CA61 = 0;
    if (D_80364AA8 == 2 && D_80364A98 == 0x2000) {
        if (D_8039CA60 == 0) {
            func_80294E30();
        }
        func_80294E88();
        func_80294EB8();
    }
    func_8025615C(D_802E8BDC, D_80358070, &sp48);
    D_80358074 = (s32)D_80358070;
    D_80358070 += sp48;
    func_80257490((s32 *)&D_80358070, 16);
    func_80285190();
    func_80275430();
    func_802621DC(D_802E8BDC);
    func_80262238(D_802E8BDC);
    func_80262150(D_802E8BDC);
    D_80367BFF = 0;
    func_802CE840();
    func_8029A7E4(D_803083EC, func_8026F92C(D_80364A90), func_8026F92C(D_80364A98));
    sp3C = D_80358070;
    func_802A1674((u8 *)D_80358074, arg0);
    func_8029A7E4(D_80308418, D_80358070 - sp3C, D_80358070);
    func_80257234();
    if (D_80364A98 != 2) {
        if ((D_80364AF0[D_80364AE8].unk18[D_802E8BDC] > 0 && D_80364AF0[D_80364AE8].unk18[D_802E8BDC] < 6) ? 1 : 0) {
            func_802CF628();
        }
    }
    func_802C1DD0(D_80364AA8 == 0x20 || D_80364AA8 == 0x80);
    func_80262320(D_802E8BDC);
    if (D_80364410 != 0) {
        D_80364A86 = func_80272C5C(D_802E8BF4, 0, 1, 1, 1, 1.0f);
    }
    func_802775C0();
    if (D_80364A69 != 0) {
        func_80286A00();
    }
    if (D_80364A6B != 0) {
        func_802873AC();
    }
    if (D_80364A6D != 0) {
        func_80287AE4();
    }
    func_802821D0();
    func_80282728();
    func_80281A70(D_802E8BDC);
    if (D_802E8F94[D_802E8BDC].unk0 == 1) {
        func_80264C20(arg0);
    }
    func_80288220();
    func_8027BE4C();
    func_80292240();
    func_8027E344(D_802E8BDC);
    func_802807D8(D_802E8BDC);
    func_80268664(D_802E8BDC);
    func_8026A988();
    sp44 = D_803643C8;
    while (sp44 != D_803643CC) {
        sp4C = 0;
        sp43 = 0;
        do {
            if (D_80364460[sp4C].unk5C == sp44->unk1022) {
                sp43 = 1;
            } else {
                sp4C++;
            }
        } while (sp43 == 0);
        func_80258544(sp44, sp44->unk1004, sp44->unk1010, sp44->unk100C, sp44->unk1000, D_80364460[sp4C].unk54,
                      D_80364460[sp4C].unk0, D_80364460[sp4C].unk4);
        func_80285110(0x61F);
        sp44++;
    }
    func_802729F0(D_80364A98, D_802E8BDC);
    D_80364452 = 0x2000;
    D_80364454 = 0x2000;
    D_80364456 = 0;
    D_803649ED = 0;
    D_803643F8 = 0;
    D_803643FC = 0;
    D_80364400 = 0;
    D_80364444 = 0.0f;
    D_80364448 = 0.0f;
    D_803649F8 = 1.0f;
    D_80364A3C = 0;
    D_80364A3D = 0;
    D_80364A40 = 0;
    D_80364A44 = 0;
    D_80364A6F = 0;
    D_80364AB4 = 0.0f;
    D_80364AB8 = 1.0f;
    D_80364ABC = 1.0f;
    D_80364AC0 = 0;
    D_803643E0 = D_803ED808;
    D_803643E4 = D_803ED80C;
    D_803643E8 = D_803ED810;
    D_802FDB14 = 0;
    if (D_802E8BF8 != 0) {
        D_803649F0 = D_8036EA70;
    } else {
        D_803649F0 = D_80364AF0[D_80364AE8].unk14;
    }
    D_80364A5C = 0;
    D_80364A58 = 0;
    if (D_803669B4 != 0) {
        func_8025BD98();
    }
    func_8029A7E4(D_80308440, D_802E8BDC, D_80358070, 0x802447C0, 0x8021ED00 - (u32)D_80358070);
    if (D_8039CAB7 != 0) {
        func_802979E0(D_802E8BDC);
    }
    func_802A56C4();
    func_802A5FA8();
}

#pragma GLOBAL_ASM("asm/nonmatchings/hd_code/00000/func_80257234.s")

void func_80257490(s32 *arg0, s32 arg1) {
    s32 sp4 = *arg0 % arg1;

    if (sp4 != 0) {
        sp4 = arg1 - sp4;
    }
    *arg0 += sp4;
}

void func_802574F0(f32 arg0) {
    sinf(arg0);
}

void func_80257514(f32 arg0) {
    fcos(arg0);
}
