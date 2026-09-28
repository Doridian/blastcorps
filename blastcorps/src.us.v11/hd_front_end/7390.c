#include "common.h"

/* Per-frame buffer, double-buffered by D_8035805C. */
typedef struct {
    /* 0x00000 */ u8 unk0[0x48B0];
    /* 0x048B0 */ Gfx unk48B0[0x397D];
} UnkStruct_803156F8; /* size = 0x21498 */

void func_80259450(void);
void func_8025B2B8(void);
void func_80260A10(void);
void func_8026AF6C(s32);
Gfx *func_8026BBD0(Gfx *, UnkStruct_803156F8 *, s32 *);
void func_80284E54(Gfx *, s32, s32, s32, s32, s32);
void func_80285110(s32);
void func_802A5720(void);
void func_802A57AC(void);

extern Gfx D_01000010[];
extern Gfx D_01000038[];
extern s32 D_802159C0;
extern OSMesgQueue D_80315180;
extern UnkStruct_803156F8 D_803156F8[];
extern void *D_80358050[];
extern u8 D_8035805C;
extern void *D_8035806C;
extern s32 D_80358078;
extern s32 D_80358080;
extern s32 D_80358084;
extern s16 D_8036BB18;

void func_801EE390(void) {
}

void func_801EE398(s32 arg0) {
    UnkStruct_803156F8 *sp5C;
    Gfx *gfx;
    s32 sp54;

    sp5C = &D_803156F8[D_8035805C ^ 1];
    D_80358080 = 0;
    D_80358084 = 0;
    gfx = sp5C->unk48B0;
    func_802A5720();
    func_8025B2B8();
    if (D_8036BB18 != arg0) {
        func_8026AF6C(arg0 | 0x8000 | 0x2000);
        func_80260A10();
        D_802159C0 = 0;
    }
    if (D_802159C0 == 2) {
        osViBlack(0);
    }
    func_80259450();
    func_80284E54(D_803156F8[D_8035805C].unk48B0, D_80358078, 1, 1, 0x4D2, 0);
    D_8035805C ^= 1;
    gSPSegment(gfx++, 0, 0);
    gSPSegment(gfx++, 2, osVirtualToPhysical(sp5C));
    gSPSegment(gfx++, 1, osVirtualToPhysical(D_8035806C));
    gSPDisplayList(gfx++, D_01000038);
    gSPDisplayList(gfx++, D_01000010);
    gDPSetCycleType(gfx++, G_CYC_FILL);
    gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, D_80358050[D_8035805C]);
    gDPPipeSync(gfx++);
    gDPSetFillColor(gfx++, 0x10001);
    gDPFillRectangle(gfx++, 0, 0, 319, 239);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gfx = func_8026BBD0(gfx, &D_803156F8[D_8035805C], &D_80358078);
    gDPFullSync(gfx++);
    gSPEndDisplayList(gfx++);
    D_80358078 = gfx - sp5C->unk48B0;
    for (sp54 = 0; sp54 < D_80358080; sp54++) {
        osRecvMesg(&D_80315180, NULL, OS_MESG_BLOCK);
    }
    for (sp54 = 0; sp54 < D_80358080 - D_80358084; sp54++) {
        func_802A57AC();
    }
    func_80285110(0x4D2);
    D_802159C0++;
}
