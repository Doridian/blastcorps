#include "common.h"

typedef struct {
    /* 0x0 */ u16 unk0[2];
} UnkStruct_802FA8A0;

typedef struct {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ u8 pad2[2];
    /* 0x4 */ u8 *unk4;
    /* 0x8 */ u8 unk8;
    /* 0x9 */ u8 unk9;
    /* 0xA */ u8 unkA;
    /* 0xB */ u8 unkB;
} UnkStruct_802FA280; /* size = 0xC */

/* The game's variant of the libultra sample scheduler (sched.h). */
typedef struct {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ OSMesgQueue *unk4;
    /* 0x8 */ u32 unk8;
} UnkStruct_SchedTask50;

typedef struct UnkSchedTask {
    /* 0x00 */ struct UnkSchedTask *next;
    /* 0x04 */ s32 state;
    /* 0x08 */ u32 flags;
    /* 0x0C */ void *framebuffer;
    /* 0x10 */ OSTask list;
    /* 0x50 */ UnkStruct_SchedTask50 *unk50;
    /* 0x54 */ OSMesgQueue *msgQ;
    /* 0x58 */ OSMesg msg;
} UnkSchedTask;

typedef struct UnkSchedClient {
    /* 0x0 */ struct UnkSchedClient *next;
    /* 0x4 */ OSMesgQueue *msgQ;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
} UnkSchedClient;

typedef struct {
    /* 0x000 */ OSMesgQueue interruptQ;
    /* 0x018 */ OSMesg intBuf[16];
    /* 0x058 */ OSMesgQueue cmdQ;
    /* 0x070 */ OSMesg cmdMsgBuf[16];
    /* 0x0B0 */ OSThread thread;
    /* 0x260 */ UnkSchedClient *clientList;
    /* 0x264 */ UnkSchedTask *audioListHead;
    /* 0x268 */ UnkSchedTask *gfxListHead;
    /* 0x26C */ UnkSchedTask *audioListTail;
    /* 0x270 */ UnkSchedTask *gfxListTail;
    /* 0x274 */ UnkSchedTask *curRSPTask;
    /* 0x278 */ UnkSchedTask *curRDPTask;
    /* 0x27C */ s32 unk27C;
    /* 0x280 */ s32 unk280;
    /* 0x284 */ u32 unk284;
    /* 0x288 */ OSTime unk288;
    /* 0x290 */ OSTime unk290;
} UnkSched;

typedef struct {
    /* 0x00 */ u16 unk0;
    /* 0x02 */ u16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ u16 unkC;
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u16 unk10;
    /* 0x12 */ u16 unk12;
    /* 0x14 */ u16 unk14;
    /* 0x16 */ u16 unk16;
    /* 0x18 */ u16 unk18;
    /* 0x1A */ u8 unk1A;
    /* 0x1B */ u8 pad1B;
} UnkStruct_802F8BDC; /* size = 0x1C */

/* Element type of the arrays D_8036BB10 points at. */
typedef struct {
    /* 0x00 */ u16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ u16 unk6;
    /* 0x08 */ u16 unk8;
    /* 0x0A */ u8 padA[2];
    /* 0x0C */ char *unkC;
    /* 0x10 */ u16 *unk10;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15;
    /* 0x16 */ u16 unk16;
    /* 0x18 */ u8 unk18;
    /* 0x19 */ u8 unk19;
    /* 0x1A */ u8 unk1A;
} UnkStruct_8036BB10; /* size = 0x1C */

typedef struct {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 pad5;
    /* 0x06 */ u8 unk6[0x14];
    /* 0x1A */ u8 unk1A;
    /* 0x1B */ u8 unk1B[10];
    /* 0x25 */ u8 unk25;
    /* 0x26 */ u8 unk26;
    /* 0x27 */ u8 pad27;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ u8 unk2D;
    /* 0x2E */ s8 unk2E;
    /* 0x2F */ u8 pad2F;
} UnkStruct_802F49F4; /* size = 0x30 */

typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ u16 unk2;
} UnkStruct_8026F644;

typedef struct {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
} UnkStruct_8026FBB0; /* size = 0x6 */

typedef struct {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 unk7;
    /* 0x08 */ Vtx unk8[2][4];
} UnkStruct_8036BED8; /* size = 0x88 */

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ char unk1[0xF];
    /* 0x10 */ u16 *unk10;
} UnkStruct_802F9934; /* size = 0x14 */

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x02 */ s16 unk2[16];
} UnkStruct_802F48D0; /* size = 0x22 */

typedef struct {
    /* 0x00 */ u8 unk0[0x88];
    /* 0x88 */ u8 unk88[0x78];
} UnkStruct_80364AF0; /* size = 0x100 */

extern s32 D_802E8BDC;
extern f32 D_80364414;
extern u16 D_802E8C8C[];
extern u16 D_802E8C90[];
extern u16 D_802E8C94[];
extern u16 D_802E8C98[];
extern u16 D_802E8C9C[];
extern u32 D_803156C4;
extern u16 D_803C30A8[];
extern UnkStruct_8036BB10 D_8020C070[];
extern u64 D_80364A98;
extern u32 D_80364AA8;
extern s32 D_803F7684;
extern u8 D_802E8BD0;
extern s32 D_803643E0;
extern s32 D_803643E4;
extern s32 D_803643E8;
extern u8 D_80364456;
extern s32 D_80367738;
extern u8 *D_80358070;
extern u16 D_8036EA7C;
extern u16 D_8036EB90;
extern s32 D_803BE70C;
extern s32 D_803BE710;
extern s16 D_803BE714;
extern u8 D_802F499A[];
extern u64 D_80364A90;
extern u8 D_80364AE8;
extern UnkStruct_80364AF0 D_80364AF0[];

void func_8026AF6C(u16 arg0);
void func_8029A7E4(char *, ...);
s32 func_80270A54(UnkStruct_8036BED8 *arg0);
char *func_8025B558(u16 *);
void func_8026BA7C(UnkStruct_802F8BDC *arg0);
s32 func_8026F92C(u64);
u8 func_8026FA38(char **, u16 **);
void func_8026FB50(UnkStruct_802F8BDC *);
u16 func_8026F8A8(u16, u16, u16, u16);
void func_8026A5CC(u64 *dst, u64 *src, s32 size);
s32 func_8026A6F0(s32, s32, s32, s32, s32, s32);
void func_802AC544(s32, s32, s32);
void func_80260650(s32, u16, s32);
s8 func_80272C5C(u8 *, s32, s32, s32, s32, f32);

/*
 * Menu and dialogue text, reached only through the pointer tables in this
 * file's .data (still asm), so they are defined here to keep their place at
 * the start of the .rodata.
 */

typedef struct {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ u8 unk2;
    /* 0x3 */ u8 unk3;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u8 unk5;
    /* 0x6 */ u8 unk6;
    /* 0x7 */ u8 unk7;
} UnkStruct_802F47B0; /* size = 0x8 */

/* .bss, 0x8036B980-0x8036BEF0 (tools/bss_c.py) */
char D_8036B980[0x28];
char D_8036B9A8[0x20];
char D_8036B9C8[0x20];
char D_8036B9E8[0x20];
char D_8036BA08[0x20];
char D_8036BA28[0x20];
u8 D_8036BA48[0x50];
u8 D_8036BA98[0xa];
u8 D_8036BAA2[3];
u8 D_8036BAA5[1];
u8 D_8036BAA6[2];
u8 D_8036BAA8[0x40];
u8 D_8036BAE8[0x14];
u32 D_8036BAFC;
u32 D_8036BB00;
u16 D_8036BB04;
u16 D_8036BB06;
f32 D_8036BB08;
s16 D_8036BB0C;
s8 D_8036BB0E;
UnkStruct_8036BB10 *D_8036BB10;
u16 D_8036BB14;
u16 D_8036BB16;
s16 D_8036BB18;
s16 D_8036BB1A;
s16 D_8036BB1C;
s16 D_8036BB1E;
s16 D_8036BB20;
UnkStruct_8036BB10 *D_8036BB24;
f32 D_8036BB28;
f32 D_8036BB2C;
s32 D_8036BB30;
f32 D_8036BB34;
f32 D_8036BB38;
u16 D_8036BB3C;
u16 D_8036BB3E;
u32 D_8036BB40;
s32 D_8036BB44;
u16 D_8036BB48[1];
u8 D_8036BB4A[2];
u8 D_8036BB4C[4];
u8 D_8036BB50[0x60];
u16 D_8036BBB0[1];
u8 D_8036BBB2[2];
u8 D_8036BBB4[4];
u8 D_8036BBB8[0x31C];
s32 D_8036BED4;
UnkStruct_8036BED8 *D_8036BED8;
f32 D_8036BEDC;
u8 D_8036BEE0;

typedef struct {
    /* 0x00 */ u16 unk0;
    /* 0x02 */ u8 unk2[0x1A];
} UnkStruct_802F8BF4; /* size = 0x1C */

extern u16 D_80301098[];
extern u16 D_803010A0[];
extern u16 D_803010A8[];
extern u16 D_803010BC[];
extern u16 D_803010C0[];
extern u16 D_80301488[];
extern u16 D_80301498[];
extern u16 D_803014B0[];
extern u16 D_803014C4[];
extern u16 D_803014DC[];
extern u16 D_803014FC[];
extern u16 D_80301518[];
extern u16 D_80301530[];
extern u16 D_80301534[];
extern u16 D_80301538[];
extern u16 D_8030153C[];
extern u16 D_80301540[];
extern u16 D_80301558[];
extern u16 D_80301570[];
extern u16 D_80301588[];
extern u16 D_803015A4[];
extern u16 D_803015A8[];
extern u16 D_803015AC[];
extern u16 D_803015B0[];
extern u16 D_803015C8[];
extern u16 D_803015E4[];
extern u16 D_80301600[];
extern u16 D_80301620[];
extern u16 D_80301634[];
extern u16 D_80301638[];
extern u16 D_8030163C[];
extern u16 D_80301640[];
extern u16 D_8030165C[];
extern u16 D_80301674[];
extern u16 D_80301694[];
extern u16 D_803016AC[];
extern u16 D_803016C4[];
extern u16 D_803016C8[];
extern u16 D_803016CC[];
extern u16 D_803016D0[];
extern u16 D_803016E4[];
extern u16 D_80301700[];
extern u16 D_8030171C[];
extern u16 D_80301720[];
extern u16 D_80301724[];
extern u16 D_80301728[];
extern u16 D_80301744[];
extern u16 D_80301760[];
extern u16 D_8030177C[];
extern u16 D_80301780[];
extern u16 D_80301784[];
extern u16 D_80301788[];
extern u16 D_8030178C[];
extern u16 D_80301790[];
extern u16 D_80301B98[];
extern u16 D_80301BA0[];
extern u16 D_80301BA8[];
extern u16 D_80301BB4[];
extern u16 D_80301BC0[];
extern u16 D_80301BCC[];
extern u16 D_80301BD4[];
extern u16 D_80301BE0[];
extern u16 D_80301BF4[];
extern u16 D_80301C04[];
extern u16 D_80301C14[];
extern u16 D_80301C24[];
extern u16 D_80301C30[];
extern u16 D_80301C40[];
extern u16 D_80301C50[];
extern u16 D_80301C64[];
extern u16 D_80301C70[];
extern u16 D_80301C78[];
extern u16 D_80301C8C[];
extern u16 D_80301C9C[];
extern u16 D_80301CB0[];
extern u16 D_80301CC8[];
extern u16 D_80301CE8[];
extern u16 D_80301CEC[];
extern u16 D_80301CF0[];
extern u16 D_80301CF4[];
extern u16 D_80301D08[];
extern u16 D_80301D24[];
extern u16 D_80301D38[];
extern u16 D_80301D3C[];
extern u16 D_80301D40[];
extern u16 D_80301D44[];
extern u16 D_80301D48[];
extern u16 D_80301D64[];
extern u16 D_80301D7C[];
extern u16 D_80301D8C[];
extern u16 D_80301DA4[];
extern u16 D_80301DC0[];
extern u16 D_80301DC4[];
extern u16 D_80301DE0[];
extern u16 D_80301DF4[];
extern u16 D_80301E0C[];
extern u16 D_80301E20[];
extern u16 D_80301E38[];
extern u16 D_80301E3C[];
extern u16 D_80301E40[];
extern u16 D_80301E44[];
extern u16 D_80301E48[];
extern u16 D_80301E60[];
extern u16 D_80301E7C[];
extern u16 D_80301E94[];
extern u16 D_80301E98[];
extern u16 D_80301E9C[];
extern u16 D_80301EA0[];
extern u16 D_80301EA4[];
extern u16 D_80301EC0[];
extern u16 D_80301ED8[];
extern u16 D_80301EF0[];
extern u16 D_80301EF4[];
extern u16 D_80301EF8[];
extern u16 D_80301EFC[];
extern u16 D_80301F00[];
extern u16 D_80301F14[];
extern u16 D_80301F28[];
extern u16 D_80301F38[];
extern u16 D_80301F3C[];
extern u16 D_80301F40[];
extern u16 D_80301F54[];
extern u16 D_80301F6C[];
extern u16 D_80301F8C[];
extern u16 D_80301FA8[];
extern u16 D_80301FAC[];
extern u16 D_80301FB0[];
extern u16 D_80301FD0[];
extern u16 D_80301FE8[];
extern u16 D_80302000[];
extern u16 D_80302004[];
extern u16 D_80302008[];
extern u16 D_8030200C[];
extern u16 D_8030202C[];
extern u16 D_8030204C[];
extern u16 D_80302068[];
extern u16 D_80302088[];
extern u16 D_8030208C[];
extern u16 D_80302090[];
extern u16 D_803020AC[];
extern u16 D_803020CC[];
extern u16 D_803020E4[];
extern u16 D_803020E8[];
extern u16 D_803020EC[];
extern u16 D_80302104[];
extern u16 D_80302124[];
extern u16 D_80302140[];
extern u16 D_8030215C[];
extern u16 D_80302174[];
extern u16 D_80302178[];
extern u16 D_8030217C[];
extern u16 D_80302194[];
extern u16 D_803021B0[];
extern u16 D_803021CC[];
extern u16 D_803021EC[];
extern u16 D_803021F0[];
extern u16 D_8030220C[];
extern u16 D_8030222C[];
extern u16 D_8030224C[];
extern u16 D_80302264[];
extern u16 D_80302280[];
extern u16 D_80302284[];
extern u16 D_80302288[];
extern u16 D_803022A8[];
extern u16 D_803022C8[];
extern u16 D_803022E0[];
extern u16 D_803022F4[];
extern u16 D_803022F8[];
extern u16 D_803022FC[];
extern u16 D_80302310[];
extern u16 D_80302328[];
extern u16 D_80302340[];
extern u16 D_8030235C[];
extern u16 D_80302360[];
extern u16 D_80302364[];
extern u16 D_80302380[];
extern u16 D_803023A0[];
extern u16 D_803023C0[];
extern u16 D_803023DC[];
extern u16 D_803023E0[];
extern u16 D_803023E4[];
extern u16 D_803023FC[];
extern u16 D_80302410[];
extern u16 D_80302424[];
extern u16 D_8030243C[];
extern u16 D_80302440[];
extern u16 D_80302460[];
extern u16 D_8030247C[];
extern u16 D_80302494[];
extern u16 D_803024AC[];
extern u16 D_803024CC[];
extern u16 D_803024D0[];
extern u16 D_803024F0[];
extern u16 D_80302504[];
extern u16 D_8030251C[];
extern u16 D_80302534[];
extern u16 D_80302538[];
extern u16 D_80302550[];
extern u16 D_80302554[];
extern u16 D_8030256C[];
extern u16 D_80302584[];
extern u16 D_80302588[];
extern u16 D_8030258C[];
extern u16 D_803025B8[];
extern u16 D_803025DC[];
extern u16 D_80302600[];
extern u16 D_8030262C[];
extern u16 D_80302650[];
extern u16 D_8030268C[];
extern u16 D_80302698[];
extern u16 D_803026C0[];
extern u16 D_803026CC[];
extern u16 D_803026F8[];
extern u16 D_80302704[];
extern u16 D_80302734[];
extern u16 D_80302748[];
extern u16 D_80302774[];
extern u16 D_80302790[];
extern u16 D_803027AC[];
extern u16 D_803027C4[];
extern u16 D_803027E0[];
extern u16 D_80302800[];
extern u16 D_80302820[];
extern u16 D_80302840[];
extern u16 D_8030285C[];
extern u16 D_80302878[];
extern u16 D_8030288C[];
extern u16 D_803028AC[];
extern u16 D_803028C8[];
extern u16 D_803028E8[];
extern u16 D_80302908[];
extern u16 D_80302918[];
extern u16 D_80302930[];
extern u16 D_80302934[];
extern u16 D_80302940[];
extern u16 D_80302954[];
extern u16 D_80302968[];
extern u16 D_80302974[];
extern u16 D_80302978[];
extern u16 D_8030298C[];
extern u16 D_803029A0[];
extern u16 D_803029B4[];
extern u16 D_803029B8[];
extern u16 D_803029C8[];
extern u16 D_803029CC[];
extern u16 D_803029D0[];
extern u16 D_803029D4[];
extern u16 D_803029E8[];
extern u16 D_803029EC[];
extern u16 D_803029F0[];
extern u16 D_80302A00[];
extern u16 D_80302A14[];
extern u16 D_80302A28[];
extern u16 D_80302A3C[];
extern u16 D_80302A50[];
extern u16 D_80302A60[];
extern u16 D_80302A64[];
extern u16 D_80302A68[];
extern u16 D_80302A7C[];
extern u16 D_80302A8C[];
extern u16 D_80302A90[];
extern u16 D_80302AA4[];
extern u16 D_80302AB4[];
extern u16 D_80302AB8[];
extern u16 D_80302AD0[];
extern u16 D_80302AE4[];
extern u16 D_80302AE8[];
extern u16 D_80302AFC[];
extern u16 D_80302B0C[];
extern u16 D_80302B10[];
extern u16 D_80302B24[];
extern u16 D_80302B34[];
extern u16 D_80302B4C[];
extern u16 D_80302B50[];
extern u16 D_80302B64[];
extern u16 D_80302B7C[];
extern u16 D_80302B94[];
extern u16 D_80302BA8[];
extern u16 D_80302BAC[];
extern u16 D_80302BB0[];
extern u16 D_80302BB4[];
extern u16 D_80302BCC[];
extern u16 D_80302BE4[];
extern u16 D_80302BE8[];
extern u16 D_80302BEC[];
extern u16 D_80302BF0[];
extern u16 D_80302BF4[];
extern u16 D_80302C08[];
extern u16 D_80302C20[];
extern u16 D_80302C2C[];
extern u16 D_80302C30[];
extern u16 D_80302C34[];
extern u16 D_80302C4C[];
extern u16 D_80302C64[];
extern u16 D_80302C68[];
extern u16 D_80302C7C[];
extern u16 D_80302C94[];
extern u16 D_80302C98[];
extern u16 D_80302CA8[];
extern u16 D_80302CBC[];
extern u16 D_80302CC0[];
extern u16 D_80302CD4[];
extern u16 D_80302CE4[];
extern u16 D_80302CF0[];
extern u16 D_80302CF4[];
extern u16 D_80302D08[];
extern u16 D_80302D14[];
extern u16 D_80302D28[];
extern u16 D_80302D2C[];
extern u16 D_80302D40[];
extern u16 D_80302D58[];
extern u16 D_80302D70[];
extern u16 D_80302D84[];
extern u16 D_80302D9C[];
extern u16 D_80302DB4[];
extern u16 D_80302DCC[];
extern u16 D_80302DE4[];
extern u16 D_80302DFC[];
extern u16 D_80302E14[];
extern u16 D_80302E28[];
extern u16 D_80302E2C[];
extern u16 D_80302E30[];
extern u16 D_80302E34[];
extern u16 D_80302E40[];
extern u16 D_80302E58[];
extern u16 D_80302E70[];
extern u16 D_80302E74[];
extern u16 D_80302E88[];
extern u16 D_80302E9C[];
extern u16 D_80302EB0[];
extern u16 D_80302EC8[];
extern u16 D_80302EE0[];
extern u16 D_80302EF4[];
extern u16 D_80302F08[];
extern u16 D_80302F1C[];
extern u16 D_80302F30[];
extern u16 D_80302F44[];
extern u16 D_80302F54[];
extern u16 D_80302F64[];
extern u16 D_80302F74[];
extern u16 D_80302F8C[];
extern u16 D_80302F90[];
extern u16 D_80302FA0[];
extern u16 D_80302FB0[];
extern u16 D_80302FB4[];
extern u16 D_80302FCC[];
extern u16 D_80302FE0[];
extern u16 D_80302FF0[];
extern u16 D_80303004[];
extern u16 D_80303014[];
extern u16 D_8030302C[];
extern u16 D_80303040[];
extern u16 D_80303058[];
extern u16 D_80303070[];
extern u16 D_80303084[];
extern u16 D_80303098[];
extern u16 D_8030309C[];
extern u16 D_803030B4[];
extern u16 D_803030CC[];
extern u16 D_803030E4[];
extern u16 D_803030F8[];
extern u16 D_8030310C[];
extern u16 D_80303124[];
extern u16 D_80303138[];
extern u16 D_8030314C[];
extern u16 D_80303160[];
extern u16 D_80303174[];
extern u16 D_80303184[];
extern u16 D_80303188[];
extern u16 D_80303198[];
extern u16 D_803031B0[];
extern u16 D_803031C8[];
extern u16 D_803031D8[];
extern u16 D_803031EC[];
extern u16 D_803031FC[];
extern u16 D_8030320C[];
extern u16 D_80303220[];
extern u16 D_80303234[];
extern u16 D_80303248[];
extern u16 D_8030325C[];
extern u16 D_80303270[];
extern u16 D_80303288[];
extern u16 D_8030329C[];
extern u16 D_803032B4[];
extern u16 D_803032C8[];
extern u16 D_803032E0[];
extern u16 D_803032E4[];
extern u16 D_803032F8[];
extern u16 D_80303304[];
extern u16 D_80303318[];
extern u16 D_8030331C[];
extern u16 D_80303320[];
extern u16 D_80303324[];
extern u16 D_80303338[];
extern u16 D_8030334C[];
extern u16 D_80303360[];
extern u16 D_80303378[];
extern u16 D_8030338C[];
extern u16 D_8030339C[];
extern u16 D_803033B0[];
extern u16 D_803033C0[];
extern u16 D_803033D0[];
extern u16 D_803033E4[];
extern u16 D_803033F0[];
extern u16 D_80303400[];
extern u16 D_80303410[];
extern u16 D_80303420[];
extern u16 D_80303424[];
extern u16 D_80303428[];
extern u16 D_80303438[];
extern u16 D_8030343C[];
extern u16 D_80303450[];
extern u16 D_8030345C[];
extern u16 D_80303470[];
extern u16 D_80303488[];
extern u16 D_803034A0[];
extern u16 D_803034B8[];
extern u16 D_803034D0[];
extern u16 D_803034DC[];
extern u16 D_803034EC[];
extern u16 D_803034FC[];
extern u16 D_80303514[];
extern u16 D_80303520[];
extern u16 D_80303534[];
extern u16 D_80303544[];
extern u16 D_8030355C[];
extern u16 D_80303574[];
extern u16 D_8030358C[];
extern u16 D_80303594[];
extern u16 D_803035A0[];
extern u16 D_803035AC[];
extern u16 D_803035B4[];
extern u16 D_803035BC[];
extern u16 D_803035C8[];
/* .data, 0x802F47B0-0x802FA270 (tools/data_c.py) */
UnkStruct_802F47B0 D_802F47B0[0x17] = {
    { 0, 0, 0, 255, 0, 0, 0, 255 },
    { 90, 90, 220, 255, 90, 90, 220, 255 },
    { 0, 255, 0, 255, 0, 255, 0, 255 },
    { 0, 255, 255, 255, 0, 255, 255, 255 },
    { 255, 0, 0, 255, 255, 0, 0, 255 },
    { 255, 0, 255, 255, 255, 0, 255, 255 },
    { 255, 255, 0, 255, 255, 255, 0, 255 },
    { 255, 255, 255, 255, 255, 255, 255, 255 },
    { 128, 128, 128, 255, 128, 128, 128, 255 },
    { 255, 180, 0, 255, 255, 180, 0, 255 },
    { 255, 120, 0, 255, 255, 120, 0, 255 },
    { 255, 240, 70, 255, 255, 240, 70, 255 },
    { 255, 0, 0, 255, 255, 255, 0, 255 },
    { 255, 255, 255, 255, 255, 255, 0, 255 },
    { 0, 0, 255, 255, 255, 255, 255, 255 },
    { 0, 255, 255, 255, 0, 0, 255, 255 },
    { 255, 0, 0, 255, 255, 255, 0, 255 },
    { 255, 0, 0, 255, 255, 255, 0, 255 },
    { 255, 255, 255, 255, 0, 0, 255, 255 },
    { 255, 255, 255, 255, 255, 0, 0, 255 },
    { 255, 0, 255, 255, 255, 0, 0, 255 },
    { 255, 180, 0, 255, 255, 120, 0, 255 },
    { 0, 255, 0, 255, 255, 255, 0, 255 },
};
u8 D_802F4868[8] = { 15, 16, 16, 16, 16, 16, 16, 16 };
u8 D_802F4870[8] = { 6, 7, 7, 7, 7, 7, 7, 7 };
u8 D_802F4878[8] = { 13, 25, 14, 23, 16, 0, 16, 14 };
u16 D_802F4880[0x28] = { 0xFFF };
UnkStruct_802F48D0 D_802F48D0[8] = {
    { 0, { 87, 84, 85, 80, 76, 83, 74, 77, 78, 79, 73, 75, -1 } },
    { 15, { 85, 70, 71, 76, -1 } },
    { 16, { 85, 70, 76, 71, -1 } },
    { 3, { 85, 70, 71, 72, -1 } },
    { 18, { 81, -1 } },
    { 33, { 82, -1 } },
    { 13, { 86, 84, -1 } },
    { 10, { 85, -1 } },
};
u8 D_802F49E0[0x14] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
UnkStruct_802F49F4 D_802F49F4[0x4b] = {
    { 0, 0, 0, 0, { 0 }, 1, { 0 }, 0, 1, 0, 1.0f, 1, 0, 0, 0 },
    {
        0, -8, 3, 0, { 9, 61, 9, 61, 9, 62, 9, 62, 9, 63, 9, 63 }, 4, { 2, 1, 2, 3 }, 1, 8, 0,
        1.0f, 2, 9, 0, 0,
    },
    { 0, -8, 1, 0, { 9, 62, 9, 62 }, 1, { 1 }, 1, 8, 0, 1.0f, 2, 9, 0, 0 },
    { 0, -8, 1, 0, { 9, 63, 9, 63 }, 1, { 1 }, 2, 8, 0, 1.0f, 2, 9, 0, 0 },
    {
        -16, -8, 5, 0, { 9, 64, 9, 64, 9, 65, 9, 65, 9, 66, 9, 66, 9, 67, 9, 67, 9, 68, 9, 68 },
        10, { 3, 2, 1, 1, 2, 3, 4, 5, 5, 4 }, 1, 10, 0, 1.0f, 2, 9, 0, 0,
    },
    { -16, -8, 1, 0, { 9, 66, 9, 66 }, 1, { 1 }, 1, 10, 0, 1.0f, 2, 9, 0, 0 },
    {
        -32, -9, 5, 0, { 9, 48, 9, 49, 9, 50, 9, 51, 9, 52 }, 7, { 1, 1, 1, 2, 3, 4, 5 }, 1, 9, 0,
        1.0f, 1, 3, 0, 0,
    },
    {
        -32, -9, 5, 0, { 9, 38, 9, 39, 9, 40, 9, 41, 9, 42 }, 8, { 1, 2, 3, 4, 5, 4, 3, 2 }, 1, 6,
        0, 1.0f, 1, 1, 0, 0,
    },
    {
        -32, -7, 5, 0, { 9, 43, 9, 44, 9, 45, 15, 127, 15, 128 }, 8, { 1, 2, 3, 4, 5, 4, 3, 2 }, 1,
        7, 0, 1.0f, 1, 1, 0, 0,
    },
    { -32, -9, 3, 0, { 9, 53, 9, 54, 9, 55 }, 4, { 1, 1, 2, 3 }, 1, 8, 0, 1.0f, 1, 3, 0, 0 },
    { -32, -9, 2, 0, { 9, 46, 9, 47 }, 2, { 1, 2 }, 1, 16, 0, 1.0f, 1, 1, 0, 0 },
    { -32, -9, 1, 0, { 9, 46 }, 1, { 1 }, 2, 16, 0, 1.0f, 1, 1, 0, 0 },
    {
        -28, -8, 5, 0, { 9, 56, 9, 56, 9, 57, 9, 57, 9, 58, 9, 58, 9, 59, 9, 59, 9, 60, 9, 60 }, 5,
        { 1, 2, 3, 4, 5 }, 1, 8, 0, 1.0f, 2, 9, 0, 0,
    },
    { 0, 0, 1, 0, { 9, 16, 9, 15 }, 1, { 1, 2, 3, 4, 5 }, 1, 8, 0, 1.0f, 2, 1, 0, 0 },
    {
        0, 0, 5, 0, { 9, 48, 9, 49, 9, 50, 9, 51, 9, 52 }, 7, { 1, 1, 1, 2, 3, 4, 5 }, 1, 9, 0,
        2.0f, 1, 3, 0, 0,
    },
    {
        0, 0, 5, 0, { 9, 38, 9, 39, 9, 40, 9, 41, 9, 42 }, 5, { 1, 2, 3, 4, 5 }, 1, 6, 0, 2.0f, 1,
        1, 0, 0,
    },
    { 0, 0, 3, 0, { 9, 53, 9, 54, 9, 55 }, 4, { 1, 1, 2, 3 }, 1, 8, 0, 2.0f, 1, 3, 0, 0 },
    { 0, 0, 2, 0, { 9, 46, 9, 47 }, 2, { 1, 2 }, 1, 16, 0, 2.0f, 1, 1, 0, 0 },
    { 184, -3, 1, 0, { 9, 27 }, 1, { 1 }, 2, 16, 0, 0.75f, 1, 0, 0, 0 },
    { 184, -3, 1, 0, { 9, 27 }, 1, { 1 }, 1, 16, 0, 0.75f, 1, 0, 0, 0 },
    { 184, -3, 1, 0, { 9, 28 }, 1, { 1 }, 1, 16, 0, 0.75f, 1, 0, 0, 0 },
    { 184, -3, 1, 0, { 9, 29 }, 1, { 1 }, 1, 16, 0, 0.75f, 1, 0, 0, 0 },
    { 184, -3, 1, 0, { 5, 114 }, 1, { 1 }, 1, 16, 0, 0.75f, 1, 0, 0, 0 },
    {
        0, 0, 5, 0,
        { 9, 220, 9, 219, 9, 222, 9, 221, 9, 224, 9, 223, 9, 226, 9, 225, 9, 228, 9, 227 }, 5,
        { 1, 2, 3, 4, 5 }, 1, 8, 0, 1.0f, 2, 1, 0, 0,
    },
    { 0, 0, 1, 0, { 10, 151, 9, 30 }, 1, { 1 }, 1, 8, 0, 1.0f, 2, 1, 0, 0 },
    {
        0, 0, 5, 0, { 9, 93, 9, 92, 9, 95, 9, 94, 9, 97, 9, 96, 9, 99, 9, 98, 9, 101, 9, 100 }, 5,
        { 1, 2, 3, 4, 5 }, 1, 8, 0, 1.0f, 2, 1, 0, 0,
    },
    { 0, 0, 1, 0, { 5, 101, 5, 100 }, 1, { 1 }, 1, 8, 0, 1.0f, 2, 1, 0, 0 },
    { 0, 0, 1, 0, { 9, 214, 9, 213 }, 1, { 1 }, 1, 8, 0, 1.0f, 2, 1, 0, 0 },
    { 0, 0, 1, 0, { 9, 216, 9, 215 }, 1, { 1 }, 1, 8, 0, 1.0f, 2, 1, 0, 0 },
    { 0, 0, 1, 0, { 5, 94, 5, 93 }, 1, { 1 }, 1, 8, 0, 1.0f, 2, 1, 0, 0 },
    { 0, 0, 1, 0, { 5, 94, 5, 93 }, 1, { 1 }, 1, 8, 0, 1.0f, 2, 1, 0, 0 },
    {
        0, 0, 5, 0, { 9, 48, 9, 49, 9, 50, 9, 51, 9, 52 }, 7, { 1, 1, 1, 2, 3, 4, 5 }, 1, 12, 0,
        2.0f, 1, 3, 0, 0,
    },
    { 0, 0, 1, 0, { 5, 116, 5, 115 }, 1, { 1 }, 1, 8, 0, 1.0f, 2, 1, 0, 0 },
    { 0, 0, 1, 0, { 9, 218, 9, 217 }, 2, { 1, 1 }, 1, 24, 0, 1.0f, 2, 1, 0, 0 },
    { -44, -8, 1, 0, { 9, 16, 9, 15 }, 1, { 1 }, 1, 8, 0, 0.61f, 2, 1, 0, 0 },
    { -44, -8, 1, 0, { 5, 113, 5, 112 }, 1, { 1 }, 1, 8, 0, 0.61f, 2, 1, 0, 0 },
    { -44, -8, 1, 0, { 9, 24, 9, 23 }, 1, { 1 }, 1, 8, 0, 0.61f, 2, 1, 0, 0 },
    { -44, -8, 1, 0, { 9, 12, 9, 11 }, 1, { 1 }, 1, 8, 0, 0.61f, 2, 1, 0, 0 },
    { -44, -8, 1, 0, { 7, 10, 7, 9 }, 1, { 1 }, 1, 8, 0, 0.61f, 2, 1, 0, 0 },
    { -44, -8, 1, 0, { 7, 114, 7, 19 }, 1, { 1 }, 1, 8, 0, 0.61f, 2, 1, 0, 0 },
    { -44, -8, 1, 0, { 0 }, 1, { 1 }, 1, 8, 0, 0.61f, 2, 1, 0, 0 },
    { -44, -8, 1, 0, { 0 }, 1, { 1 }, 1, 8, 0, 0.61f, 2, 1, 0, 0 },
    { -44, -8, 1, 0, { 9, 18, 9, 17 }, 1, { 1 }, 1, 8, 0, 0.61f, 2, 1, 0, 0 },
    { -44, -8, 1, 0, { 9, 22, 9, 21 }, 1, { 1 }, 1, 8, 0, 0.61f, 2, 1, 0, 0 },
    { -44, -8, 1, 0, { 9, 10, 9, 9 }, 1, { 1 }, 1, 8, 0, 0.61f, 2, 1, 0, 0 },
    { -44, -8, 1, 0, { 0 }, 1, { 1 }, 1, 8, 0, 0.61f, 2, 1, 0, 0 },
    { -44, -8, 1, 0, { 0 }, 1, { 1 }, 1, 8, 0, 0.61f, 2, 1, 0, 0 },
    { -44, -8, 1, 0, { 9, 14, 9, 13 }, 1, { 1 }, 1, 8, 0, 0.61f, 2, 1, 0, 0 },
    { -44, -8, 1, 0, { 9, 8, 9, 7 }, 1, { 1 }, 1, 8, 0, 0.61f, 2, 1, 0, 0 },
    { -44, -8, 1, 0, { 9, 26, 9, 25 }, 1, { 1 }, 1, 8, 0, 0.61f, 2, 1, 0, 0 },
    { -44, -8, 1, 0, { 7, 18, 7, 17 }, 1, { 1 }, 1, 8, 0, 0.61f, 2, 1, 0, 0 },
    { 0, 0, 1, 0, { 9, 31 }, 1, { 1 }, 1, 8, 0, 1.0f, 1, 1, 0, 0 },
    { -32, -6, 1, 0, { 9, 27 }, 1, { 1 }, 1, 16, 0, 1.0f, 1, 0, 0, 0 },
    { -32, -6, 1, 0, { 9, 28 }, 1, { 1 }, 1, 16, 0, 1.0f, 1, 0, 0, 0 },
    { -32, -6, 1, 0, { 9, 29 }, 1, { 1 }, 1, 16, 0, 1.0f, 1, 0, 0, 0 },
    { -32, -6, 1, 0, { 5, 114 }, 1, { 1 }, 1, 16, 0, 1.0f, 1, 0, 0, 0 },
    { 0, 0, 1, 0, { 2, 228, 2, 227 }, 1, { 1 }, 1, 8, 0, 1.0f, 2, 1, 0, 0 },
    { 0, 0, 1, 0, { 9, 16, 9, 15 }, 1, { 1 }, 1, 8, 0, 1.0f, 2, 1, 0, 0 },
    { 0, 0, 1, 0, { 5, 113, 5, 112 }, 1, { 1 }, 1, 8, 0, 1.0f, 2, 1, 0, 0 },
    { 0, 0, 1, 0, { 9, 24, 9, 23 }, 1, { 1 }, 1, 8, 0, 1.0f, 2, 1, 0, 0 },
    { 0, 0, 1, 0, { 9, 12, 9, 11 }, 1, { 1 }, 1, 8, 0, 1.0f, 2, 1, 0, 0 },
    { 0, 0, 1, 0, { 7, 10, 7, 9 }, 1, { 1 }, 1, 8, 0, 1.0f, 2, 1, 0, 0 },
    { 0, 0, 1, 0, { 7, 114, 7, 19 }, 1, { 1 }, 1, 8, 0, 1.0f, 2, 1, 0, 0 },
    { 0, 0, 1, 0, { 0 }, 1, { 1 }, 1, 8, 0, 1.0f, 2, 1, 0, 0 },
    { 0, 0, 1, 0, { 0 }, 1, { 1 }, 1, 8, 0, 1.0f, 2, 1, 0, 0 },
    { 0, 0, 1, 0, { 9, 18, 9, 17 }, 1, { 1 }, 1, 8, 0, 1.0f, 2, 1, 0, 0 },
    { 0, 0, 1, 0, { 9, 22, 9, 21 }, 1, { 1 }, 1, 8, 0, 1.0f, 2, 1, 0, 0 },
    { 0, 0, 1, 0, { 9, 10, 9, 9 }, 1, { 1 }, 1, 8, 0, 1.0f, 2, 1, 0, 0 },
    { 0, 0, 1, 0, { 0 }, 1, { 1 }, 1, 8, 0, 1.0f, 2, 1, 0, 0 },
    { 0, 0, 1, 0, { 0 }, 1, { 1 }, 1, 8, 0, 1.0f, 2, 1, 0, 0 },
    { 0, 0, 1, 0, { 9, 14, 9, 13 }, 1, { 1 }, 1, 8, 0, 1.0f, 2, 1, 0, 0 },
    { 0, 0, 1, 0, { 9, 8, 9, 7 }, 1, { 1 }, 1, 8, 0, 1.0f, 2, 1, 0, 0 },
    { 0, 0, 1, 0, { 9, 26, 9, 25 }, 1, { 1 }, 1, 8, 0, 1.0f, 2, 1, 0, 0 },
    { 0, 0, 1, 0, { 7, 18, 7, 17 }, 1, { 1 }, 1, 8, 0, 1.0f, 2, 1, 0, 0 },
    { 0, 0, 1, 0, { 13, 68, 13, 67 }, 1, { 1 }, 1, 8, 0, 1.0f, 2, 1, 0, 0 },
};
UnkStruct_8036BB10 D_802F5804[0x1da] = {
    { 32, 56, 48, 24, 24, { 0 }, "SELECT OPTION", D_80301B98, 0, 0, 30, 7, 0, 0 },
    { 97, 80, 82, 20, 20, { 0 }, "MORE", D_80301BD4, 0, 0, 30, 7, 4, 0 },
    { 97, 80, 102, 20, 20, { 0 }, "VIEW STATS", D_80301BA8, 0, 0, 30, 7, 4, 0 },
    { 97, 80, 122, 20, 20, { 0 }, "RESTART", D_80301BC0, 0, 0, 30, 7, 4, 0 },
    { 97, 80, 142, 20, 20, { 0 }, "QUIT LEVEL", D_80301BCC, 0, 0, 30, 7, 4, 0 },
    { 32, 56, 48, 24, 24, { 0 }, "SELECT OPTION", D_80301B98, 0, 0, 30, 7, 0, 0 },
    { 113, 80, 82, 20, 20, { 0 }, "CONTINUE", D_80301BA0, 0, 0, 30, 7, 4, 0 },
    { 97, 80, 102, 20, 20, { 0 }, "CONTROL MODE", D_80301BB4, 0, 0, 30, 7, 4, 0 },
    { 97, 80, 122, 20, 20, { 0 }, "MISSION BRIEFING", D_80301BE0, 0, 0, 30, 7, 4, 0 },
    { 97, 80, 142, 20, 20, { 0 }, "MUSIC VOLUME", D_80301BF4, 0, 0, 30, 7, 4, 0 },
    { 36, 32, 6, 20, 20, { 0 }, "COLLISION IMMINENT!", D_80301C04, 0, 0, 30, 17, 4, 0 },
    { 36, 52, 6, 20, 20, { 0 }, "WARNING!", D_80301C14, 0, 0, 30, 17, 4, 0 },
    { 32, 32, 40, 20, 20, { 0 }, "REACTOR MELTDOWN!", D_80301C24, 0, 0, 30, 12, 6, 0 },
    { 36, 44, 64, 20, 20, { 0 }, "ABORTING MISSION", D_80301C30, 0, 0, 30, 18, 4, 0 },
    { 32, 44, 40, 20, 20, { 0 }, "CONGRATULATIONS!", D_80301C40, 0, 0, 30, 16, 6, 0 },
    { 36, 40, 64, 20, 20, { 0 }, "MISSION COMPLETE", D_80301C50, 0, 0, 30, 14, 2, 0 },
    { 160, 64, 42, 28, 30, { 0 }, D_8036B980, D_802F4880, 0, 0, 30, 12, 12, 0 },
    { 240, 112, 210, 24, 24, { 0 }, "PRESS START", NULL, 0, 0, 30, 7, 7, 0 },
    { 0x400, 76, 96, 15, 15, { 0 }, D_8036B9A8, NULL, 6, 0, 0, 22, 2, 0 },
    { 0x400, 216, 96, 15, 15, { 0 }, D_8036B9C8, NULL, 7, 0, 0, 22, 2, 0 },
    { 0x400, 76, 128, 15, 15, { 0 }, D_8036B9E8, NULL, 8, 0, 0, 22, 2, 0 },
    { 0x400, 216, 128, 15, 15, { 0 }, D_8036BA08, NULL, 9, 0, 0, 22, 2, 0 },
    { 0x400, 152, 170, 15, 15, { 0 }, D_8036BA28, NULL, 10, 0, 0, 22, 2, 0 },
    { 0x401, 60, 208, 19, 19, { 0 }, NULL, NULL, 2, 0, 30, 7, 4, 0 },
    { 0x401, 248, 208, 19, 19, { 0 }, NULL, NULL, 5, 0, 30, 7, 4, 0 },
    { 160, 64, 42, 28, 30, { 0 }, D_8036B980, D_802F4880, 0, 0, 30, 12, 12, 0 },
    { 224, 112, 210, 24, 24, { 0 }, "", NULL, 0, 0, 30, 7, 7, 0 },
    { 0x400, 40, 108, 15, 15, { 0 }, NULL, NULL, 6, 0, 0, 22, 2, 0 },
    { 0x400, 240, 108, 15, 15, { 0 }, NULL, NULL, 6, 0, 0, 22, 2, 0 },
    { 0x400, 40, 108, 15, 15, { 0 }, NULL, NULL, 6, 0, 0, 22, 2, 0 },
    { 0x400, 240, 108, 15, 15, { 0 }, NULL, NULL, 6, 0, 0, 22, 2, 0 },
    { 0x1A0, 130, 118, 22, 22, { 0 }, "******MISSION", D_80301C64, 0, 0, 0, 4, 2, 0 },
    { 0x1A0, 130, 140, 22, 22, { 0 }, "FAILED!*****", D_80301C70, 0, 0, 0, 4, 2, 0 },
    { 0x401, 60, 208, 19, 19, { 0 }, NULL, NULL, 2, 0, 30, 7, 4, 0 },
    { 0x401, 248, 208, 19, 19, { 0 }, NULL, NULL, 5, 0, 30, 7, 4, 0 },
    { 36, 40, 6, 20, 20, { 0 }, NULL, NULL, 30, 0, 16, 6, 0, 0 },
    { 32, 0, 17, 20, 20, { 0 }, NULL, NULL, 0, 0, 30, 16, 6, 0 },
    { 36, 24, 39, 20, 20, { 0 }, NULL, NULL, 0, 0, 30, 14, 4, 0 },
    { 32, 0, 22, 24, 24, { 0 }, "SET MUSIC VOLUME", D_803010A8, 0, 0, 0, 7, 7, 0 },
    { 209, 52, 54, 22, 22, { 0 }, "QUIET", D_803010BC, 0, 0, 30, 7, 4, 0 },
    { 209, 188, 54, 22, 22, { 0 }, "LOUD", D_803010C0, 0, 0, 30, 7, 4, 0 },
    { 32, 53, 20, 26, 26, { 0 }, "**MISSION FAILED!**", D_80301C78, 0, 0, 0, 4, 4, 0 },
    { 36, 40, 6, 20, 20, { 0 }, NULL, NULL, 30, 0, 16, 6, 0, 0 },
    { 0x10A4, 0, -146, 22, 22, { 0 }, "CONGRATULATIONS!!", D_80301C8C, 0, 0, 30, 18, 6, 0 },
    { 0x10A0, 0, 0, 16, 16, { 0 }, "MIRACULOUSLY, THE SHUTTLE", D_80301C9C, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 18, 16, 16, { 0 }, "COMPLETES ITS RETURN", D_80301CB0, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 36, 16, 16, { 0 }, "TO EARTH WITHOUT A", D_80301CC8, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 54, 16, 16, { 0 }, "SINGLE CASUALTY.", D_80301CE8, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 72, 16, 16, { 0 }, NULL, D_80301CEC, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 90, 16, 16, { 0 }, NULL, D_80301CF0, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 108, 16, 16, { 0 }, "BLAST CORPS HAS COME", D_80301CF4, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 126, 16, 16, { 0 }, "THROUGH WITH FLYING", D_80301D08, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 144, 16, 16, { 0 }, "COLORS YET AGAIN.", D_80301D24, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 162, 16, 16, { 0 }, NULL, D_80301D38, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 180, 16, 16, { 0 }, NULL, D_80301D3C, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 198, 16, 16, { 0 }, NULL, D_80301D40, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 216, 16, 16, { 0 }, "THEIR POPULARITY GIVEN", D_80301D44, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 234, 16, 16, { 0 }, "A FURTHER BOOST, THE", D_80301D48, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 252, 16, 16, { 0 }, "TEAM FIND NEW OFFERS", D_80301D64, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 270, 16, 16, { 0 }, "OF WORK POURING IN -", D_80301D7C, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 288, 16, 16, { 0 }, "BUT DECIDE THAT MAYBE,", D_80301D8C, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 306, 16, 16, { 0 }, "FOR NOW, IT'S TIME", D_80301DA4, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 324, 16, 16, { 0 }, "FOR A HOLIDAY.", D_80301DC0, 0, 0, 30, 6, 6, 0 },
    {
        0x10A0, 0, -186, 16, 16, { 0 }, "BATTERED AND CRIPPLED AFTER", D_80301DC4, 0, 0, 30, 6, 6,
        0,
    },
    {
        0x10A0, 0, -168, 16, 16, { 0 }, "ITS LONG VOYAGE, THE LATEST", D_80301DE0, 0, 0, 30, 6, 6,
        0,
    },
    {
        0x10A0, 0, -150, 16, 16, { 0 }, "SPACE SHUTTLE IS THROWN OFF", D_80301DF4, 0, 0, 30, 6, 6,
        0,
    },
    {
        0x10A0, 0, -132, 16, 16, { 0 }, "COURSE DURING RE-ENTRY AND", D_80301E0C, 0, 0, 30, 6, 6,
        0,
    },
    { 0x10A0, 0, -114, 16, 16, { 0 }, "FORCED INTO DESPERATE", D_80301E20, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, -96, 16, 16, { 0 }, "MEASURES.", D_80301E38, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, -78, 16, 16, { 0 }, NULL, D_80301E3C, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, -60, 16, 16, { 0 }, NULL, D_80301E40, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, -42, 16, 16, { 0 }, NULL, D_80301E44, 0, 0, 30, 6, 6, 0 },
    {
        0x10A0, 0, -24, 16, 16, { 0 }, "A MAJOR CITY IS SEIZED BY", D_80301E48, 0, 0, 30, 6, 6, 0,
    },
    { 0x10A0, 0, -6, 16, 16, { 0 }, "PANIC WHEN THE RESIDENTS", D_80301E60, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 12, 16, 16, { 0 }, "FIND OUT THAT THEIR HOMES", D_80301E7C, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 30, 16, 16, { 0 }, "ARE ABOUT TO BECOME AN", D_80301E94, 0, 0, 30, 6, 6, 0 },
    {
        0x10A0, 0, 48, 16, 16, { 0 }, "EMERGENCY LANDING STRIP ...", D_80301E98, 0, 0, 30, 6, 6, 0,
    },
    { 0x10A0, 0, 66, 16, 16, { 0 }, NULL, D_80301E9C, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 84, 16, 16, { 0 }, NULL, D_80301EA0, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 102, 16, 16, { 0 }, NULL, D_80301EA4, 0, 0, 30, 6, 6, 0 },
    {
        0x10A0, 0, 120, 16, 16, { 0 }, "TIME IS OF THE ESSENCE AS", D_80301EC0, 0, 0, 30, 6, 6, 0,
    },
    { 0x10A0, 0, 138, 16, 16, { 0 }, "BLAST CORPS RISES ONCE", D_80301ED8, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 156, 16, 16, { 0 }, "MORE TO THE CHALLENGE.", D_80301EF0, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 174, 16, 16, { 0 }, NULL, D_80301EF4, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 192, 16, 16, { 0 }, NULL, D_80301EF8, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 210, 16, 16, { 0 }, NULL, D_80301EFC, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 228, 16, 16, { 0 }, "EVEN AS THE SHUTTLE", D_80301F00, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 246, 16, 16, { 0 }, "BLAZES DOWN THROUGH", D_80301F14, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 264, 16, 16, { 0 }, "THE SKIES, A RUNWAY", D_80301F28, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 282, 16, 16, { 0 }, "MUST BE CLEARED.", D_80301F38, 0, 0, 30, 6, 6, 0 },
    { 176, 0, 36, 20, 20, { 0 }, "SITUATION:", D_8030268C, 0, 0, 30, 4, 4, 0 },
    {
        0x1A0, 32, 58, 16, 16, { 0 }, "********CARRIER LOCKED ON COURSE********", D_80302698, 0, 0,
        30, 7, 4, 0,
    },
    { 0x2A0, 0, 84, 20, 20, { 0 }, "SOLUTION:", D_803026C0, 0, 0, 30, 4, 4, 0 },
    {
        0x1A0, 23, 106, 16, 16, { 0 }, "********CLEAR PATH TO GROUND ZERO!************",
        D_803026CC, 0, 0, 30, 7, 4, 0,
    },
    { 176, 0, 36, 20, 20, { 0 }, "AGENTS:", D_803026F8, 0, 0, 30, 4, 4, 0 },
    {
        0x1A0, 69, 58, 16, 16, { 0 }, "********BLAST CORPS********", D_80302704, 0, 0, 30, 7, 4, 0,
    },
    { 0x2A0, 0, 84, 20, 20, { 0 }, "CHANCES:", D_80302734, 0, 0, 30, 4, 4, 0 },
    {
        0x1A0, 94, 106, 16, 16, { 0 }, "********SLIM*!******************", D_80302748, 0, 0, 30, 7,
        4, 0,
    },
    { 0x1B0, 0, 48, 20, 20, { 0 }, "******MISSION 1:**", D_80302774, 0, 0, 30, 4, 4, 0 },
    { 0x220, 0, 74, 15, 15, { 0 }, "CLEAR PATH FOR CARRIER", D_80302790, 0, 0, 30, 7, 4, 0 },
    { 0x220, 0, 91, 15, 15, { 0 }, "ON EACH MAIN LEVEL.", D_803027AC, 0, 0, 30, 7, 4, 0 },
    { 0x1B0, 0, 40, 20, 20, { 0 }, "******MISSION 2:**", D_803027C4, 0, 0, 30, 4, 4, 0 },
    { 0x220, 0, 66, 15, 15, { 0 }, "ACTIVATE ALL RDUS AND", D_803027E0, 0, 0, 30, 7, 4, 0 },
    { 0x220, 0, 83, 15, 15, { 0 }, "DESTROY ALL BUILDINGS", D_80302800, 0, 0, 30, 7, 4, 0 },
    { 0x220, 0, 100, 15, 15, { 0 }, "TO EARN SECOND GOLD.", D_80302820, 0, 0, 30, 7, 4, 0 },
    { 0x1B0, 0, 40, 20, 20, { 0 }, "******MISSION 3:**", D_80302840, 0, 0, 30, 4, 4, 0 },
    {
        0x220, 0, 66, 14, 15, { 0 }, "AFTER COMPLETING MAIN LEVELS,", D_8030285C, 0, 0, 30, 7, 4,
        0,
    },
    { 0x220, 0, 83, 14, 15, { 0 }, "FIND ALL 6 SCIENTISTS TO", D_80302878, 0, 0, 30, 7, 4, 0 },
    {
        0x220, 0, 100, 14, 15, { 0 }, "ENSURE A CONTROLLED DETONATION.", D_8030288C, 0, 0, 30, 7,
        4, 0,
    },
    { 0x1B0, 0, 48, 20, 20, { 0 }, "******MISSION 4:**", D_803028AC, 0, 0, 30, 4, 4, 0 },
    { 0x220, 0, 74, 15, 15, { 0 }, "ACHIEVE GOLD ON ALL LEVELS", D_803028C8, 0, 0, 30, 7, 4, 0 },
    { 0x220, 0, 91, 15, 15, { 0 }, "TO COMMENCE TIME ATTACK.", D_803028E8, 0, 0, 30, 7, 4, 0 },
    { 176, 0, 16, 15, 15, { 0 }, "BLAST CORPS : LEADERS IN", D_80301F3C, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 32, 15, 15, { 0 }, "THE FIELD OF HEAVY DUTY", D_80301F40, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 48, 15, 15, { 0 }, "DEMOLITION THROUGH A", D_80301F54, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 64, 15, 15, { 0 }, "COMBINATION OF SKILL,", D_80301F6C, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 80, 15, 15, { 0 }, "EXPERIENCE AND CUTTING-", D_80301F8C, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 96, 15, 15, { 0 }, "EDGE TECHNOLOGY.", D_80301FA8, 0, 0, 30, 7, 6, 0 },
    { 176, 0, 16, 15, 15, { 0 }, "SINCE ITS BIRTH THE COMPANY", D_80301FAC, 0, 0, 30, 7, 6, 0 },
    {
        160, 0, 32, 15, 15, { 0 }, "HAS APPLIED ITS UNIQUE TALENTS", D_80301FB0, 0, 0, 30, 7, 6, 0,
    },
    {
        160, 0, 48, 15, 15, { 0 }, "TO THE PROBLEM OF URBAN DECAY,", D_80301FD0, 0, 0, 30, 7, 6, 0,
    },
    { 160, 0, 64, 15, 15, { 0 }, "RENOVATING AND REVITALIZING", D_80301FE8, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 80, 15, 15, { 0 }, "CITIES FROM ONE END OF THE", D_80302000, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 96, 15, 15, { 0 }, "COUNTRY TO THE OTHER.", D_80302004, 0, 0, 30, 7, 6, 0 },
    { 176, 0, 16, 15, 15, { 0 }, "A FAR CRY FROM THE SENSELESS", D_80302008, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 32, 15, 15, { 0 }, "WARFARE AMIDST WHICH THE", D_8030200C, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 48, 15, 15, { 0 }, "SEEDS OF THE PROJECT WERE", D_8030202C, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 64, 15, 15, { 0 }, "SOWN, IN THE HEAVY VEHICLE", D_8030204C, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 80, 15, 15, { 0 }, "DEVELOPMENT BAY AT THE", D_80302068, 0, 0, 30, 7, 6, 0 },
    {
        160, 0, 96, 15, 15, { 0 }, "MILITARY BASE CALLED RAFTERS.", D_80302088, 0, 0, 30, 7, 6, 0,
    },
    { 176, 0, 16, 15, 15, { 0 }, "WHILE DEMONSTRATING A GREAT", D_8030208C, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 32, 15, 15, { 0 }, "NATURAL FLAIR, THE FOUNDING", D_80302090, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 48, 15, 15, { 0 }, "MEMBERS OF THE TEAM - AMBER,", D_803020AC, 0, 0, 30, 7, 6, 0 },
    {
        160, 0, 64, 15, 15, { 0 }, "CLARK, WESLEY AND SPIKE - WERE", D_803020CC, 0, 0, 30, 7, 6, 0,
    },
    {
        160, 0, 80, 15, 15, { 0 }, "NEVER HAPPY WITH THE ULTIMATE", D_803020E4, 0, 0, 30, 7, 6, 0,
    },
    {
        160, 0, 96, 15, 15, { 0 }, "PURPOSE OF THEIR MACHINES ...", D_803020E8, 0, 0, 30, 7, 6, 0,
    },
    { 176, 0, 16, 15, 15, { 0 }, "SO WHEN WESLEY WAS CRUELLY", D_803020EC, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 32, 15, 15, { 0 }, "REJECTED FOLLOWING THE FIELD", D_80302104, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 48, 15, 15, { 0 }, "ACCIDENT THAT LEFT HIM", D_80302124, 0, 0, 30, 7, 6, 0 },
    {
        160, 0, 64, 15, 15, { 0 }, "DISABLED, HIS FRIENDS FINALLY", D_80302140, 0, 0, 30, 7, 6, 0,
    },
    { 160, 0, 80, 15, 15, { 0 }, "REBELLED AND LED THE", D_8030215C, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 96, 15, 15, { 0 }, "INFAMOUS RAFTERS WALKOUT.", D_80302174, 0, 0, 30, 7, 6, 0 },
    { 176, 0, 16, 15, 15, { 0 }, "BLAST CORPS CAME INTO BEING", D_80302178, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 32, 15, 15, { 0 }, "SOON AFTER. THAT WAS FIVE", D_8030217C, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 48, 15, 15, { 0 }, "YEARS AGO. BUT NOW, IN", D_80302194, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 64, 15, 15, { 0 }, "THE PRESENT DAY, WORLD PEACE", D_803021B0, 0, 0, 30, 7, 6, 0 },
    {
        160, 0, 80, 15, 15, { 0 }, "IS SHATTERED AS MANKIND FACES", D_803021CC, 0, 0, 30, 7, 6, 0,
    },
    { 160, 0, 96, 15, 15, { 0 }, "CRISIS ON A WORLDWIDE SCALE.", D_803021EC, 0, 0, 30, 7, 6, 0 },
    { 176, 0, 16, 15, 15, { 0 }, "A PAIR OF DEFECTIVE NUCLEAR", D_803021F0, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 32, 15, 15, { 0 }, "MISSILES, EN ROUTE TO A SAFE", D_8030220C, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 48, 15, 15, { 0 }, "DETONATION SITE, HAVE BEGUN", D_8030222C, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 64, 15, 15, { 0 }, "TO LEAK. BADLY DAMAGED, THE", D_8030224C, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 80, 15, 15, { 0 }, "CARRIER AUTOMATICALLY LOCKS", D_80302264, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 96, 15, 15, { 0 }, "ONTO THE MOST DIRECT ROUTE.", D_80302280, 0, 0, 30, 7, 6, 0 },
    { 176, 0, 16, 15, 15, { 0 }, "BAD MEMORIES RESURFACE FOR", D_80302284, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 32, 15, 15, { 0 }, "THE BLAST CORPS TEAM WHEN,", D_80302288, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 48, 15, 15, { 0 }, "SUMMONED TO THEIR NATION'S", D_803022A8, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 64, 15, 15, { 0 }, "DEFENSE, THEY FIND OUT WHERE", D_803022C8, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 80, 15, 15, { 0 }, "THE WARHEADS ORIGINATED. A", D_803022E0, 0, 0, 30, 7, 6, 0 },
    {
        160, 0, 96, 15, 15, { 0 }, "CERTAIN NEARBY MILITARY BASE.", D_803022F4, 0, 0, 30, 7, 6, 0,
    },
    {
        176, 0, 16, 15, 15, { 0 }, "THE FLOOD OF RADIATION PREVENTS", D_803022F8, 0, 0, 30, 7, 6,
        0,
    },
    { 160, 0, 32, 15, 15, { 0 }, "ANYONE GETTING CLOSE TO THE", D_803022FC, 0, 0, 30, 7, 6, 0 },
    {
        160, 0, 48, 15, 15, { 0 }, "RUNAWAY CARRIER, AND PEOPLE IN", D_80302310, 0, 0, 30, 7, 6, 0,
    },
    { 160, 0, 64, 15, 15, { 0 }, "THE KNOW FEAR THAT EVEN THE", D_80302328, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 80, 15, 15, { 0 }, "SLIGHTEST JOLT COULD TRIGGER", D_80302340, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 96, 15, 15, { 0 }, "A CATASTROPHIC EXPLOSION.", D_8030235C, 0, 0, 30, 7, 6, 0 },
    {
        176, 0, 16, 15, 15, { 0 }, "STANDING AS THE WORLD'S FINAL", D_80302360, 0, 0, 30, 7, 6, 0,
    },
    { 160, 0, 32, 15, 15, { 0 }, "HOPE, BLAST CORPS MUST CLEAR", D_80302364, 0, 0, 30, 7, 6, 0 },
    {
        160, 0, 48, 15, 15, { 0 }, "THE WAY TO GROUND ZERO, GATHER", D_80302380, 0, 0, 30, 7, 6, 0,
    },
    {
        160, 0, 64, 15, 15, { 0 }, "A TEAM OF SIX ELITE SCIENTISTS", D_803023A0, 0, 0, 30, 7, 6, 0,
    },
    { 160, 0, 80, 15, 15, { 0 }, "AND ULTIMATELY COUNTER THE", D_803023C0, 0, 0, 30, 7, 6, 0 },
    { 160, 0, 96, 15, 15, { 0 }, "THREAT OF NUCLEAR WINTER.", D_803023DC, 0, 0, 30, 7, 6, 0 },
    { 176, 0, 88, 16, 16, { 0 }, "EVEN AS THE CARRIER", D_803023E0, 0, 0, 30, 6, 6, 0 },
    { 160, 0, 106, 16, 16, { 0 }, "TRUNDLES TOWARDS GROUND", D_803023E4, 0, 0, 30, 6, 6, 0 },
    { 160, 0, 124, 16, 16, { 0 }, "ZERO, YOU ARE DOING", D_803023FC, 0, 0, 30, 6, 6, 0 },
    { 160, 0, 142, 16, 16, { 0 }, "EVERYTHING IN YOUR POWER", D_80302410, 0, 0, 30, 6, 6, 0 },
    { 160, 0, 160, 16, 16, { 0 }, "TO GET THE ASSEMBLED", D_80302424, 0, 0, 30, 6, 6, 0 },
    { 160, 0, 178, 16, 16, { 0 }, "SCIENTISTS THERE FIRST ...", D_8030243C, 0, 0, 30, 6, 6, 0 },
    {
        0x10A0, 0, -188, 16, 16, { 0 }, "MERCIFULLY, THE SCIENTISTS", D_80302440, 0, 0, 30, 6, 6,
        0,
    },
    { 0x10A0, 0, -170, 16, 16, { 0 }, "ARE ABLE TO SET UP A", D_80302460, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, -152, 16, 16, { 0 }, "PROPERLY CONTROLLED", D_8030247C, 0, 0, 30, 6, 6, 0 },
    {
        0x10A0, 0, -134, 16, 16, { 0 }, "DETONATION ... AND FINALLY,", D_80302494, 0, 0, 30, 6, 6,
        0,
    },
    {
        0x10A0, 0, -116, 16, 16, { 0 }, "AS THE SMOKE FADES, THE WORLD", D_803024AC, 0, 0, 30, 6,
        6, 0,
    },
    {
        0x10A0, 0, -98, 16, 16, { 0 }, "CAN LET OUT A SIGH OF RELIEF.", D_803024CC, 0, 0, 30, 6, 6,
        0,
    },
    { 0x10A0, 0, -26, 16, 16, { 0 }, "THE DEVASTATION LEFT IN", D_803024D0, 0, 0, 30, 6, 6, 0 },
    {
        0x10A0, 0, -8, 16, 16, { 0 }, "YOUR WAKE IS NOTHING COMPARED", D_803024F0, 0, 0, 30, 6, 6,
        0,
    },
    {
        0x10A0, 0, 10, 16, 16, { 0 }, "TO WHAT WOULD HAVE HAPPENED", D_80302504, 0, 0, 30, 6, 6, 0,
    },
    { 0x10A0, 0, 28, 16, 16, { 0 }, "IF BLAST CORPS HAD FAILED", D_8030251C, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 46, 16, 16, { 0 }, "AT THE LAST.", D_80302534, 0, 0, 30, 6, 6, 0 },
    {
        0x10A0, 0, 82, 16, 16, { 0 }, "REBUILDING BEGINS IMMEDIATELY.", D_80302538, 0, 0, 30, 6, 6,
        0,
    },
    {
        0x10A0, 0, 154, 16, 16, { 0 }, "WITH CATASTROPHE AVERTED, THE", D_80302550, 0, 0, 30, 6, 6,
        0,
    },
    {
        0x10A0, 0, 172, 16, 16, { 0 }, "TEAM MEMBERS BECOME NATIONAL", D_80302554, 0, 0, 30, 6, 6,
        0,
    },
    {
        0x10A0, 0, 190, 16, 16, { 0 }, "HEROES, THEIR SUCCESS AND", D_8030256C, 0, 0, 30, 6, 6, 0,
    },
    { 0x10A0, 0, 208, 16, 16, { 0 }, "SATISFACTION ASSURED FOR", D_80302584, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 226, 16, 16, { 0 }, "THE FORESEEABLE FUTURE.", D_80302588, 0, 0, 30, 6, 6, 0 },
    {
        0x120, 44, 6, 20, 20, { 0 }, "**RDUS COLLECTED!**********", D_803025B8, 0, 0, 30, 18, 4, 0,
    },
    {
        0x120, 44, 6, 20, 20, { 0 }, "**SURVIVORS FREE!**********", D_803025DC, 0, 0, 30, 18, 4, 0,
    },
    {
        0x120, 44, 6, 20, 20, { 0 }, "**BUILDINGS DESTROYED!**********", D_80302600, 0, 0, 30, 18,
        4, 0,
    },
    {
        0x120, 44, 6, 20, 20, { 0 }, "**LEVEL COMPLETE!**********", D_8030258C, 0, 0, 30, 18, 4, 0,
    },
    { 0x120, 44, 6, 20, 20, { 0 }, "**PATH CLEARED!**********", D_8030262C, 0, 0, 30, 18, 4, 0 },
    {
        0x1A0, 24, 20, 24, 24, { 0 }, "********EMERGENCY! ...****************", D_80302650, 0, 0,
        30, 4, 4, 0,
    },
    { 160, 0, 48, 20, 20, { 0 }, "YOU MUST COMPLETELY", D_80302908, 0, 0, 30, 7, 4, 0 },
    { 160, 0, 70, 20, 20, { 0 }, "REMOVE ALL OBSTACLES", D_80302918, 0, 0, 30, 7, 4, 0 },
    { 160, 0, 92, 20, 20, { 0 }, "FROM THE DANGER ZONE!", D_80302930, 0, 0, 30, 7, 4, 0 },
    { 164, 32, 6, 20, 20, { 0 }, "DANGER ZONE!", D_80302934, 0, 0, 30, 17, 4, 0 },
    { 0x480, -32, 38, 15, 15, { 0 }, NULL, NULL, 16, 0, 0, 22, 2, 0 },
    { 0x1020, 0, -128, 16, 16, { 0 }, "THIS IS AN RDU,", D_80302940, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, -110, 16, 16, { 0 }, "TRIGGERED REMOTELY", D_80302954, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, -92, 16, 16, { 0 }, "AS YOU DRIVE BY.", D_80302968, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, -74, 16, 16, { 0 }, NULL, D_80302974, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, -56, 16, 16, { 0 }, "THEY CAN BE USED FOR", D_80302978, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, -38, 16, 16, { 0 }, "GUIDANCE AS WELL AS", D_8030298C, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, -20, 16, 16, { 0 }, "RADIATION DISPERSAL.", D_803029A0, 0, 0, 30, 7, 7, 0 },
    { 0x480, -32, 38, 15, 15, { 0 }, NULL, NULL, 56, 0, 0, 22, 2, 0 },
    { 0x1020, 0, -128, 16, 16, { 0 }, "COMMUNICATION POINTS", D_803029B4, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, -110, 16, 16, { 0 }, "ALLOW YOU TO MAKE", D_803029B8, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, -92, 16, 16, { 0 }, "CONTACT WITH HQ.", D_803029C8, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, -74, 16, 16, { 0 }, NULL, D_803029CC, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, -56, 16, 16, { 0 }, "WHEN ACTIVATED, THEY", D_803029D0, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, -38, 16, 16, { 0 }, "BREAK OPEN VALUABLE", D_803029D4, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, -20, 16, 16, { 0 }, "NEW TRAINING LEVELS.", D_803029E8, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, -2, 16, 16, { 0 }, NULL, D_803029EC, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 16, 16, 16, { 0 }, "YOU CAN", D_803029F0, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 34, 16, 16, { 0 }, "ACCESS THESE FROM", D_80302A00, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 52, 16, 16, { 0 }, "THE WORLD SCREEN.", D_80302A14, 0, 0, 30, 7, 7, 0 },
    { 0x480, -16, 8, 15, 15, { 0 }, NULL, NULL, 62, 0, 0, 22, 2, 0 },
    { 0x11A0, 0, -52, 24, 24, { 0 }, "BACKLASH", D_80302A28, 0, 0, 30, 4, 7, 0 },
    { 0x10A0, 0, 20, 16, 16, { 0 }, "DESTROY BUILDINGS", D_80302A3C, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 38, 16, 16, { 0 }, "WITH BACKLASH USING", D_80302A50, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 56, 16, 16, { 0 }, "ITS ARMORED REAR.", D_80302A60, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 74, 16, 16, { 0 }, NULL, D_80302A64, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 92, 16, 16, { 0 }, NULL, D_80302A68, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 110, 16, 16, { 0 }, "USE R TO SKID", D_80302A7C, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 128, 16, 16, { 0 }, "THE TRUCK WHEN", D_80302A8C, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 146, 16, 16, { 0 }, "GOING INTO A TURN.", D_80302A90, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 164, 16, 16, { 0 }, NULL, D_80302AA4, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 182, 16, 16, { 0 }, "AIM FOR AT LEAST", D_80302AB4, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 200, 16, 16, { 0 }, "A SILVER MEDAL", D_80302AB8, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 218, 16, 16, { 0 }, "BEFORE PROGRESSING:", D_80302AD0, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 236, 16, 16, { 0 }, NULL, D_80302AE4, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 254, 16, 16, { 0 }, "THIS TECHNIQUE", D_80302AE8, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 272, 16, 16, { 0 }, "MUST BE MASTERED", D_80302AFC, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 290, 16, 16, { 0 }, "FOR LATER LEVELS.", D_80302B0C, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 308, 16, 16, { 0 }, NULL, D_80302B10, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 326, 16, 16, { 0 }, "USE BUMPS TO GET", D_80302B24, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 344, 16, 16, { 0 }, "BACKLASH AIRBORNE AND", D_80302B34, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 362, 16, 16, { 0 }, "CAUSE MAXIMUM DAMAGE.", D_80302B4C, 0, 0, 30, 7, 7, 0 },
    { 0x480, -16, 8, 15, 15, { 0 }, NULL, NULL, 58, 0, 0, 22, 2, 0 },
    { 0x11A0, 0, -52, 24, 24, { 0 }, "SIDESWIPE", D_80302B50, 0, 0, 30, 4, 7, 0 },
    { 0x10A0, 0, 20, 16, 16, { 0 }, "HITS HARDEST AT THE", D_80302B64, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 38, 16, 16, { 0 }, "MAXIMUM EXTENSION", D_80302B7C, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 56, 16, 16, { 0 }, "OF ITS SIDE PANELS.", D_80302B94, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 74, 16, 16, { 0 }, NULL, D_80302BA8, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 92, 16, 16, { 0 }, NULL, D_80302BAC, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 110, 16, 16, { 0 }, "FIND BLUE AMMO BOXES", D_80302BB0, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 128, 16, 16, { 0 }, "TO KEEP SIDESWIPE'S", D_80302BB4, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 146, 16, 16, { 0 }, "ATTACK POWER AT FULL.", D_80302BCC, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 164, 16, 16, { 0 }, NULL, D_80302BE4, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 182, 16, 16, { 0 }, "CHARGES REMAINING", D_80302BE8, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 200, 16, 16, { 0 }, "ARE DISPLAYED IN THE", D_80302BEC, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 218, 16, 16, { 0 }, "LOWER LEFT CORNER.", D_80302BF0, 0, 0, 30, 7, 7, 0 },
    { 0x480, -16, 8, 15, 15, { 0 }, NULL, NULL, 59, 0, 0, 22, 2, 0 },
    { 0x11A0, 0, -52, 24, 24, { 0 }, "THUNDERFIST", D_80302BF4, 0, 0, 30, 4, 7, 0 },
    { 0x10A0, 0, 20, 16, 16, { 0 }, "DEMOLISH BUILDINGS", D_80302C08, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 38, 16, 16, { 0 }, "BY DIVING AND", D_80302C20, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 56, 16, 16, { 0 }, "ROLLING INTO THEM.", D_80302C2C, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 74, 16, 16, { 0 }, NULL, D_80302C30, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 92, 16, 16, { 0 }, "A WELL-TIMED SERIES", D_80302C34, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 110, 16, 16, { 0 }, "OF ATTACKS CAN CAUSE", D_80302C4C, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 128, 16, 16, { 0 }, "INCREDIBLE DAMAGE.", D_80302C64, 0, 0, 30, 7, 7, 0 },
    { 0x480, -16, 8, 15, 15, { 0 }, NULL, NULL, 60, 0, 0, 22, 2, 0 },
    { 0x11A0, 0, -52, 24, 24, { 0 }, "SKYFALL", D_80302C68, 0, 0, 30, 4, 7, 0 },
    { 0x10A0, 0, 20, 16, 16, { 0 }, "MAKE USE OF SKYFALL'S", D_80302C7C, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 38, 16, 16, { 0 }, "ARMORED UNDERSIDE", D_80302C94, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 56, 16, 16, { 0 }, "TO CRUSH FROM ABOVE.", D_80302C98, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 74, 16, 16, { 0 }, NULL, D_80302CA8, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 92, 16, 16, { 0 }, "TURBO INTO A DITCH", D_80302CBC, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 110, 16, 16, { 0 }, "WITH L/R TO LAUNCH", D_80302CC0, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 128, 16, 16, { 0 }, "YOURSELF SKYWARDS ...", D_80302CD4, 0, 0, 30, 7, 7, 0 },
    { 0x480, -16, 8, 15, 15, { 0 }, NULL, NULL, 66, 0, 0, 22, 2, 0 },
    { 0x11A0, 0, -52, 24, 24, { 0 }, "J-BOMB", D_80302CE4, 0, 0, 30, 4, 7, 0 },
    { 0x10A0, 0, 20, 16, 16, { 0 }, "USE A TO THRUST", D_80302CF0, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 38, 16, 16, { 0 }, "J-BOMB INTO THE", D_80302CF4, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 56, 16, 16, { 0 }, "AIR OVER A TARGET ...", D_80302D08, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 74, 16, 16, { 0 }, NULL, D_80302D14, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 92, 16, 16, { 0 }, "THEN HIT B TO", D_80302D28, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 110, 16, 16, { 0 }, "DIVE EARTHWARDS", D_80302D2C, 0, 0, 30, 7, 7, 0 },
    { 0x10A0, 0, 128, 16, 16, { 0 }, "FROM A HEIGHT.", D_80302D40, 0, 0, 30, 7, 7, 0 },
    { 0x480, -36, 38, 15, 15, { 0 }, NULL, NULL, 74, 0, 0, 22, 2, 0 },
    { 0x1020, 0, -128, 16, 16, { 0 }, "SURVIVORS ESCAPE WHEN", D_80302D58, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, -110, 16, 16, { 0 }, "THE WALLS AROUND", D_80302D70, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, -92, 16, 16, { 0 }, "THEM ARE DESTROYED.", D_80302D84, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, -56, 16, 16, { 0 }, "CUE THE BLAST CORPS", D_80302D9C, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, -38, 16, 16, { 0 }, "CHOPPER, SWOOPING IN", D_80302DB4, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, -20, 16, 16, { 0 }, "TO PICK THEM UP.", D_80302DCC, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 16, 16, 16, { 0 }, "ONE GOLD COMMENDATION", D_80302DE4, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 34, 16, 16, { 0 }, "IS GIVEN PER LEVEL", D_80302DFC, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 52, 16, 16, { 0 }, "FOR PATH CLEARANCE:", D_80302E14, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 88, 16, 16, { 0 }, "THE SECOND REQUIRES", D_80302E28, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 106, 16, 16, { 0 }, "ALL SURVIVORS, RDUS", D_80302E2C, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 124, 16, 16, { 0 }, "AND TOTAL DESTRUCTION.", D_80302E30, 0, 0, 30, 7, 7, 0 },
    { 0x480, -36, 38, 15, 15, { 0 }, NULL, NULL, 13, 0, 0, 22, 2, 0 },
    { 0x1061, 0, -128, 20, 20, { 0 }, "WARNING!", D_80302E34, 0, 0, 30, 4, 4, 0 },
    { 0x1020, 0, -74, 16, 16, { 0 }, "SOMETHING IN THE", D_80302E40, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, -56, 16, 16, { 0 }, "CARRIER'S PATH", D_80302E58, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, -38, 16, 16, { 0 }, "HAS BEEN MISSED!", D_80302E70, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, -2, 16, 16, { 0 }, "KEEP AN EYE", D_80302E74, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 16, 16, 16, { 0 }, "ON THE LOWER", D_80302E88, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 34, 16, 16, { 0 }, "LEFT ARROW ...", D_80302E9C, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 70, 16, 16, { 0 }, "IT CHANGES FROM GREEN", D_80302EB0, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 88, 16, 16, { 0 }, "TO RED AS YOU CLOSE", D_80302EC8, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 106, 16, 16, { 0 }, "IN ON THE CARRIER.", D_80302EE0, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 142, 16, 16, { 0 }, "USE IT WITH THE RADAR", D_80302EF4, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 160, 16, 16, { 0 }, "TO QUICKLY TRACK", D_80302F08, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 178, 16, 16, { 0 }, "DOWN THE PROBLEM:", D_80302F1C, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 214, 16, 16, { 0 }, "RED INDICATES THE", D_80302F30, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 232, 16, 16, { 0 }, "CARRIER, BLUE THE NEXT", D_80302F44, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 250, 16, 16, { 0 }, "BUILDING IN ITS PATH.", D_80302F54, 0, 0, 30, 7, 7, 0 },
    { 0x480, -36, 38, 15, 15, { 0 }, NULL, NULL, 74, 0, 0, 22, 2, 0 },
    { 0x1020, 0, -74, 16, 16, { 0 }, "CONGRATULATIONS!", D_80302F64, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, -56, 16, 16, { 0 }, "THIS IS ONE OF", D_80302F74, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, -38, 16, 16, { 0 }, "THE BONUS VEHICLES.", D_80302F8C, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, -2, 16, 16, { 0 }, "THEY ARE", D_80302F90, 30, 0, 7, 7, 0, 0 },
    { 0x1021, 0, 16, 16, 16, { 0 }, "MOST USEFUL IN", D_80302FA0, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 34, 16, 16, { 0 }, "TRAINING STAGES:", D_80302FB0, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 70, 16, 16, { 0 }, "ACCESS THESE", D_80302FB4, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 88, 16, 16, { 0 }, "VIA THE LEVEL'S", D_80302FCC, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 106, 16, 16, { 0 }, "COMMUNICATION POINTS.", D_80302FE0, 0, 0, 30, 7, 7, 0 },
    { 0x480, -36, 38, 15, 15, { 0 }, NULL, NULL, 74, 0, 0, 22, 2, 0 },
    { 0x1024, 0, 0, 16, 16, { 0 }, "PATH CLEARED!", D_80302FF0, 0, 0, 30, 18, 18, 0 },
    { 0x1021, 0, 18, 16, 16, { 0 }, "YOUR PRIMARY MISSION", D_80303004, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 36, 16, 16, { 0 }, "HERE IS COMPLETE.", D_80303014, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 72, 16, 16, { 0 }, "THE BLAST CORPS", D_8030302C, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 90, 16, 16, { 0 }, "SEMI ALLOWS YOU", D_80303040, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 108, 16, 16, { 0 }, "TO EXIT THE LEVEL.", D_80303058, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 144, 16, 16, { 0 }, "MOVE BETWEEN", D_80303070, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 162, 16, 16, { 0 }, "VEHICLES WITH", D_80303084, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 180, 16, 16, { 0 }, "THE Z BUTTON.", D_80303098, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 216, 16, 16, { 0 }, "SPARE TIME CAN BE", D_8030309C, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 234, 16, 16, { 0 }, "USED TO FIND RDUS AND", D_803030B4, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 252, 16, 16, { 0 }, "DESTROY BUILDINGS ...", D_803030CC, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 288, 16, 16, { 0 }, "RETURN IF NECESSARY", D_803030E4, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 306, 16, 16, { 0 }, "AFTER CHECKING", D_803030F8, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 324, 16, 16, { 0 }, "YOUR PERFORMANCE.", D_8030310C, 0, 0, 30, 7, 7, 0 },
    { 0x480, -36, 38, 15, 15, { 0 }, NULL, NULL, 74, 0, 0, 22, 2, 0 },
    { 0x1020, 0, 0, 16, 16, { 0 }, "USE Z TO GET OUT", D_80303124, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 18, 16, 16, { 0 }, "OF ONE VEHICLE", D_80303138, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 36, 16, 16, { 0 }, "AND COMMANDEER ANOTHER.", D_8030314C, 0, 0, 30, 7, 7, 0 },
    { 0x480, -36, 38, 15, 15, { 0 }, NULL, NULL, 74, 0, 0, 22, 2, 0 },
    { 0x1020, 0, 0, 16, 16, { 0 }, "THE DESTRUCTION OF", D_80303160, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 18, 16, 16, { 0 }, "THIS BUILDING", D_80303174, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 36, 16, 16, { 0 }, "IS ESSENTIAL!", D_80303184, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 72, 16, 16, { 0 }, "FLASHING ARROWS", D_80303188, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 90, 16, 16, { 0 }, "MEAN IT STANDS IN", D_80303198, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 108, 16, 16, { 0 }, "THE CARRIER'S PATH.", D_803031B0, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 144, 16, 16, { 0 }, "AS DANGER CLOSES IN,", D_803031C8, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 162, 16, 16, { 0 }, "THE ARROWS CHANGE", D_803031D8, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 180, 16, 16, { 0 }, "FROM GREEN TO RED.", D_803031EC, 0, 0, 30, 7, 7, 0 },
    { 0x480, -36, 38, 15, 15, { 0 }, NULL, NULL, 74, 0, 0, 22, 2, 0 },
    { 0x1020, 0, 0, 16, 16, { 0 }, "THIS IS A PERIPHERY", D_803031FC, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 18, 16, 16, { 0 }, "STRUCTURE : CRUSHING", D_8030320C, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 36, 16, 16, { 0 }, "IT IS NOT VITAL.", D_80303220, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 72, 16, 16, { 0 }, "THEN AGAIN, IT'S FUN", D_80303234, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 90, 16, 16, { 0 }, "- AND MIGHT REVEAL", D_80303248, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 108, 16, 16, { 0 }, "A SURPRISE OR TWO ...", D_8030325C, 0, 0, 30, 7, 7, 0 },
    { 0x480, -36, 38, 15, 15, { 0 }, NULL, NULL, 74, 0, 0, 22, 2, 0 },
    { 0x1020, 0, 0, 16, 16, { 0 }, "LEVELING EVERYTHING", D_80303270, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 18, 16, 16, { 0 }, "HELPS YOU GAIN", D_80303288, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 36, 16, 16, { 0 }, "A COMMENDATION.", D_8030329C, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 72, 16, 16, { 0 }, "HOWEVER, IT'S A", D_803032B4, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 90, 16, 16, { 0 }, "SECONDARY OBJECTIVE", D_803032C8, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 108, 16, 16, { 0 }, "TO CLEARING THE WAY.", D_803032E0, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 144, 16, 16, { 0 }, "CONCENTRATE ON THE", D_803032E4, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 162, 16, 16, { 0 }, "ARROWED BUILDINGS AS", D_803032F8, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 180, 16, 16, { 0 }, "THE CARRIER PASSES ...", D_80303304, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 216, 16, 16, { 0 }, "PLENTY OF TIME TO", D_80303318, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 234, 16, 16, { 0 }, "COME BACK LATER", D_8030331C, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 252, 16, 16, { 0 }, "AND FINISH THE JOB.", D_80303320, 0, 0, 30, 7, 7, 0 },
    { 0x480, -36, 38, 15, 15, { 0 }, NULL, NULL, 74, 0, 0, 22, 2, 0 },
    { 0x1020, 0, 0, 16, 16, { 0 }, "USE Z TO GET OUT", D_80303324, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 18, 16, 16, { 0 }, "OF ONE VEHICLE", D_80303338, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 36, 16, 16, { 0 }, "AND COMMANDEER ANOTHER.", D_8030334C, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 72, 16, 16, { 0 }, "BUT CLEAR A PATH FOR", D_80303360, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 90, 16, 16, { 0 }, "THE CARRIER BEFORE", D_80303378, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 108, 16, 16, { 0 }, "GOING OFF TO EXPLORE!", D_8030338C, 0, 0, 30, 7, 7, 0 },
    { 0x480, -36, 38, 15, 15, { 0 }, NULL, NULL, 74, 0, 0, 22, 2, 0 },
    { 0x1020, 0, 0, 16, 16, { 0 }, "THE CRANE CAN MOVE", D_8030339C, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 18, 16, 16, { 0 }, "OBJECTS TO PREVIOUSLY", D_803033B0, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 36, 16, 16, { 0 }, "INACCESSIBLE PLACES.", D_803033C0, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 72, 16, 16, { 0 }, "LOAD IT UP THEN", D_803033D0, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 90, 16, 16, { 0 }, "HEAD FOR THE", D_803033E4, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 108, 16, 16, { 0 }, "CONTROLS IN THE CAB.", D_803033F0, 0, 0, 30, 7, 7, 0 },
    { 0x480, -36, 38, 15, 15, { 0 }, NULL, NULL, 74, 0, 0, 22, 2, 0 },
    { 0x1020, 0, 0, 16, 16, { 0 }, "COLLECT AMMO BOXES", D_80303400, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 18, 16, 16, { 0 }, "AND YOU CAN BLAST", D_80303410, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 36, 16, 16, { 0 }, "YOUR WAY THROUGH.", D_80303420, 0, 0, 30, 7, 7, 0 },
    { 0x480, -36, 38, 15, 15, { 0 }, NULL, NULL, 74, 0, 0, 22, 2, 0 },
    { 0x1020, 0, 0, 16, 16, { 0 }, "YOU COULD STOP", D_80303424, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 18, 16, 16, { 0 }, "THE TRAIN AT", D_80303428, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 36, 16, 16, { 0 }, "THIS STATION.", D_80303438, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 72, 16, 16, { 0 }, "WAIT FOR THE SMILEY", D_8030343C, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 90, 16, 16, { 0 }, "BEFORE ATTEMPTING TO", D_80303450, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 108, 16, 16, { 0 }, "LOAD OR UNLOAD.", D_8030345C, 0, 0, 30, 7, 7, 0 },
    { 0x480, -36, 38, 15, 15, { 0 }, NULL, NULL, 74, 0, 0, 22, 2, 0 },
    { 0x1020, 0, 0, 16, 16, { 0 }, "TNT CRATES CAN BE", D_80303470, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 18, 16, 16, { 0 }, "PUSHED AROUND USING", D_80303488, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 36, 16, 16, { 0 }, "RAMDOZER'S SHOVEL.", D_803034A0, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 72, 16, 16, { 0 }, "BUT THEY WON'T BE", D_803034B8, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 90, 16, 16, { 0 }, "STABLE FOR LONG ...", D_803034D0, 0, 0, 30, 7, 7, 0 },
    { 0x480, -36, 38, 15, 15, { 0 }, NULL, NULL, 74, 0, 0, 22, 2, 0 },
    { 0x1020, 0, 0, 16, 16, { 0 }, "SELECT START THEN", D_803034DC, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 18, 16, 16, { 0 }, "VIEW STATS TO CHECK", D_803034EC, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 36, 16, 16, { 0 }, "STATUS OF LEVEL.", D_803034FC, 0, 0, 30, 7, 7, 0 },
    { 0x480, -36, 38, 15, 15, { 0 }, NULL, NULL, 74, 0, 0, 22, 2, 0 },
    { 0x1020, 0, 0, 16, 16, { 0 }, "THE TRAIN CAN HELP", D_80303514, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 18, 16, 16, { 0 }, "TRANSPORT RAMDOZER", D_80303520, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 36, 16, 16, { 0 }, "TO THE STATION.", D_80303534, 0, 0, 30, 7, 7, 0 },
    { 0x480, -36, 38, 15, 15, { 0 }, NULL, NULL, 74, 0, 0, 22, 2, 0 },
    { 0x1020, 0, 0, 16, 16, { 0 }, "PRESSING START WILL", D_80303544, 0, 0, 30, 7, 7, 0 },
    { 0x1021, 0, 18, 16, 16, { 0 }, "ALLOW YOU TO VIEW THE", D_8030355C, 0, 0, 30, 7, 7, 0 },
    { 0x1020, 0, 36, 16, 16, { 0 }, "MISSILE CARRIER'S PATH.", D_80303574, 0, 0, 30, 7, 7, 0 },
    { 160, -36, 34, 22, 22, { 0 }, NULL, NULL, 61, 0, 0, 7, 2, 0 },
    { 32, 0, 60, 19, 19, { 0 }, NULL, NULL, 0, 0, 30, 7, 4, 0 },
    { 209, 48, 84, 29, 29, { 0 }, "NO", D_80301098, 0, 0, 30, 8, 4, 0 },
    { 209, 180, 84, 29, 29, { 0 }, "YES", D_803010A0, 0, 0, 30, 8, 4, 0 },
    { 0x10A4, 0, -146, 22, 22, { 0 }, "CONGRATULATIONS!!", D_80301488, 0, 0, 30, 18, 6, 0 },
    { 0x10A0, 0, 0, 16, 16, { 0 }, "HAVING DEMONSTRATED", D_80301498, 0, 0, 30, 6, 6, 0 },
    {
        0x10A0, 0, 18, 16, 16, { 0 }, "VERSATILITY AND RELIABILITY", D_803014B0, 0, 0, 30, 6, 6, 0,
    },
    { 0x10A0, 0, 36, 16, 16, { 0 }, "WELL BEYOND THE CALL OF", D_803014C4, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 54, 16, 16, { 0 }, "DUTY, THE BLAST CORPS", D_803014DC, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 72, 16, 16, { 0 }, "TEAM CAN FINALLY TAKE", D_803014FC, 0, 0, 30, 6, 6, 0 },
    {
        0x10A0, 0, 90, 16, 16, { 0 }, "THAT WELL-DESERVED HOLIDAY.", D_80301518, 0, 0, 30, 6, 6, 0,
    },
    { 0x10A0, 0, 108, 16, 16, { 0 }, NULL, D_80301530, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 126, 16, 16, { 0 }, NULL, D_80301534, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 144, 16, 16, { 0 }, NULL, D_80301538, 0, 0, 30, 6, 6, 0 },
    {
        0x10A0, 0, 162, 16, 16, { 0 }, "WHEN THEY GET BACK THEY'LL", D_8030153C, 0, 0, 30, 6, 6, 0,
    },
    {
        0x10A0, 0, 180, 16, 16, { 0 }, "FIND THE OFFERS AND DEALS", D_80301540, 0, 0, 30, 6, 6, 0,
    },
    { 0x10A0, 0, 198, 16, 16, { 0 }, "STILL FLOODING IN,", D_80301558, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 216, 16, 16, { 0 }, "KEEPING THEM IN THEIR", D_80301570, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 234, 16, 16, { 0 }, "CHOSEN LINE OF WORK", D_80301588, 0, 0, 30, 6, 6, 0 },
    {
        0x10A0, 0, 252, 16, 16, { 0 }, "FOR MANY YEARS TO COME ...", D_803015A4, 0, 0, 30, 6, 6, 0,
    },
    { 0x10A0, 0, 270, 16, 16, { 0 }, NULL, D_803015A8, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 288, 16, 16, { 0 }, NULL, D_803015AC, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 306, 16, 16, { 0 }, NULL, D_803015B0, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 324, 16, 16, { 0 }, "MAYBE AT SOME POINT EVEN", D_803015C8, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 342, 16, 16, { 0 }, "LEADING THEM BACK INTO", D_803015E4, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 360, 16, 16, { 0 }, "THE FIELD OF MILITARY", D_80301600, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 378, 16, 16, { 0 }, "OPERATIONS - BUT THIS", D_80301620, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 396, 16, 16, { 0 }, "TIME FOR A CONSIDERABLY", D_80301634, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 414, 16, 16, { 0 }, "NOBLER CAUSE.", D_80301638, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 432, 16, 16, { 0 }, NULL, D_8030163C, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 450, 16, 16, { 0 }, NULL, D_80301640, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 468, 16, 16, { 0 }, NULL, D_8030165C, 0, 0, 30, 6, 6, 0 },
    {
        0x10A0, 0, 486, 16, 16, { 0 }, "ALL THAT, THOUGH, CAN WAIT.", D_80301674, 0, 0, 30, 6, 6,
        0,
    },
    { 0x10A0, 0, 504, 16, 16, { 0 }, "WITH THEIR COUNTRY", D_80301694, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 522, 16, 16, { 0 }, "BREATHING A SIGH OF", D_803016AC, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 540, 16, 16, { 0 }, "RELIEF AND THEIR GOOD", D_803016C4, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 558, 16, 16, { 0 }, "NAME ASSURED FOR LIFE,", D_803016C8, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 576, 16, 16, { 0 }, "THE TEAM CAN REST EASY", D_803016CC, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 594, 16, 16, { 0 }, "FOR A WHILE.", D_803016D0, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 612, 16, 16, { 0 }, NULL, D_803016E4, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 630, 16, 16, { 0 }, NULL, D_80301700, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 648, 16, 16, { 0 }, NULL, D_8030171C, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 666, 16, 16, { 0 }, "UNLESS, OF COURSE, THE", D_80301720, 0, 0, 30, 6, 6, 0 },
    {
        0x10A0, 0, 684, 16, 16, { 0 }, "LURE OF THE GOLD STANDARD", D_80301724, 0, 0, 30, 6, 6, 0,
    },
    { 0x10A0, 0, 702, 16, 16, { 0 }, "PROVES TOO MUCH ...", D_80301728, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 720, 16, 16, { 0 }, NULL, D_80301744, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 738, 16, 16, { 0 }, NULL, D_80301760, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 756, 16, 16, { 0 }, NULL, D_8030177C, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 774, 16, 16, { 0 }, NULL, D_80301780, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 792, 16, 16, { 0 }, "PERHAPS THERE ARE", D_80301784, 0, 0, 30, 6, 6, 0 },
    {
        0x10A0, 0, 810, 16, 16, { 0 }, "FURTHER CHALLENGES AWAITING", D_80301788, 0, 0, 30, 6, 6,
        0,
    },
    { 0x10A0, 0, 828, 16, 16, { 0 }, "THOSE WHO CAN ACHIEVE", D_8030178C, 0, 0, 30, 6, 6, 0 },
    { 0x10A0, 0, 846, 16, 16, { 0 }, "A PERFECT RECORD ...", D_80301790, 0, 0, 30, 6, 6, 0 },
};
UnkStruct_802F8BDC D_802F8BDC[0x6c] = {
    { 0x100, 208, 32, 16, -0xEFFFFC7, 0, 0, 5, 27, 28, 29, 0, 0, 0 },
    { 0x100, 208, 32, 16, -0x4EFFFFC7, 0, 5, 5, 0, 28, 29, 0, 0, 0 },
    { 0x100, 32, 32, 36, 0x8000008, 0, 10, 1, 0, 0, 0, 0, 0, 0 },
    { 192, 32, 64, 36, 0x8000008, 0, 11, 1, 31, 0, 0, 0, 0, 0 },
    { 0x100, 128, 32, 56, 11, 2, 12, 2, 0, 0, 0, 0, 0, 0 },
    { 0x110, 128, 24, 56, 25, 2, 14, 2, 0, 0, 0, 0, 0, 0 },
    { 0x160, 0x110, -16, -16, -0x4EBFEA18, 3, 16, 9, 0, 0, 229, 23, 0, 0 },
    { 0x160, 0x110, -16, -16, -0x4EBFEA18, 2, 25, 10, 0, 0, 229, 33, 0, 0 },
    { 192, 32, 64, 192, 0x8000008, 2, 35, 1, 107, 0, 0, 0, 0, 0 },
    { 0x118, 72, 20, 80, 24, 3, 36, 2, 0, 0, 0, 0, 0, 0 },
    { 0x140, 157, 0, 85, -0x4FFFF5D8, 0, 2, 5, 0, 0, 29, 0, 0, 0 },
    { 0x140, 240, 0, 0, 2584, 0, 7, 2, 0, 28, 229, 0, 0, 0 },
    { 0x100, 128, 32, 56, -0x4FFFF788, 0, 9, 4, 0, 0, 29, 0, 0, 0 },
    { 0x130, 96, 8, 72, -0x4EFFFB98, 0, 38, 3, 0, 0, 29, 0, 0, 0 },
    { 0x130, 64, 8, 80, 153, 1, 41, 1, 58, 0, 229, 0, 0, 0 },
    { 0x140, 240, 0, 0, -0x4FFFE018, 0, 13, 9, 0, 0, 229, 0, 0, 0 },
    { 0x140, 240, 0, 0, -0x4FFFE018, 0, 22, 11, 0, 0, 229, 0, 0, 0 },
    { 0x100, 64, 32, 96, 6168, 0, 0, 2, 0, 0, 229, 0, 0, 0 },
    { 0x1C0, 92, -64, 96, -0x4FFFB3D8, 0, 33, 20, 0, 0, 229, 0, 0, 0 },
    { 0x140, 144, 0, 48, 0x10001838, 0, 53, 3, 0, 0, 229, 0, 0, 0 },
    { 192, 32, 64, 124, -0x4FFFF7C8, 2, 56, 1, 0, 0, 229, 0, 0, 0 },
    { 0x100, 140, 56, 50, 0x2005D428, 0, 0, 0, 0, 0, 229, 0, 0, 0 },
    { 0x100, 160, 56, 54, -0x4FF429E0, 0, 0, 0, 0, 0, 229, 0, 0, 0 },
    { 0x100, 32, 32, 192, 0x8000008, 2, 42, 1, 31, 0, 0, 0, 0, 0 },
    { 0x140, 128, 0, 56, 0x5000888, 5, 57, 3, 0, 0, 229, 0, 0, 0 },
    { 0x140, 128, 0, 56, 0x5000888, 5, 60, 3, 0, 0, 229, 0, 0, 0 },
    { 0x140, 0x110, 0, -16, 0x1104888, 4, 63, 23, 0, 0, 229, 0, 0, 0 },
    { 0x140, 180, 0, 30, 0x1000888, 5, 86, 5, 0, 0, 229, 0, 0, 0 },
    { 0x140, 240, 0, 0, 0x5000A00, 7, 176, 6, 0, 0, 229, 0, 0, 0 },
    { 0x140, 0x110, 0, -16, 0x1104808, 2, 91, 23, 0, 0, 229, 0, 0, 0 },
    { 0x140, 0x110, 0, -16, 0x1104009, 2, 0x1A9, 49, 0, 0, 229, 0, 0, 0 },
    { 0x140, 0x110, 0, -16, 0x1104808, 2, 114, 24, 0, 0, 229, 0, 0, 0 },
    { 0x140, 0x110, 0, -16, 0x1104808, 2, 138, 37, 0, 0, 229, 0, 0, 0 },
    { 0x140, 64, 0, 88, 2184, 4, 196, 1, 0, 0, 229, 0, 0, 0 },
    { 192, 64, 64, 88, 2688, 7, 197, 1, 0, 0, 229, 0, 0, 0 },
    { 0x140, 0x110, 0, -16, 0x104009, 2, 43, 20, 0, 0, 229, 0, 0, 0 },
    { 0x140, 0x110, 0, -16, 0x104008, 5, 63, 27, 0, 0, 229, 0, 0, 0 },
    { 0x120, 160, 16, 40, 0x4000088, 9, 90, 4, 0, 0, 229, 0, 0, 0 },
    { 0x100, 160, 32, 40, 0x4000088, 6, 94, 4, 0, 0, 229, 0, 0, 0 },
    { 0x100, 160, 32, 40, 0x5000088, 5, 98, 3, 0, 0, 229, 0, 0, 0 },
    { 0x100, 160, 32, 40, 0x5000088, 5, 101, 4, 0, 0, 229, 0, 0, 0 },
    { 0x140, 160, 0, 40, 0x5000088, 5, 105, 4, 0, 0, 229, 0, 0, 0 },
    { 0x100, 160, 32, 40, 0x5000088, 5, 109, 3, 0, 0, 229, 0, 0, 0 },
    { 0x140, 128, 0, 56, 0x5000008, 7, 112, 6, 0, 0, 229, 0, 0, 0 },
    { 0x140, 128, 0, 56, 0x5000008, 7, 118, 6, 0, 0, 229, 0, 0, 0 },
    { 0x140, 128, 0, 56, 0x5000008, 7, 124, 6, 0, 0, 229, 0, 0, 0 },
    { 0x140, 128, 0, 56, 0x5000008, 7, 130, 6, 0, 0, 229, 0, 0, 0 },
    { 0x140, 128, 0, 56, 0x5000008, 7, 136, 6, 0, 0, 229, 0, 0, 0 },
    { 0x140, 128, 0, 56, 0x5000008, 7, 142, 6, 0, 0, 229, 0, 0, 0 },
    { 0x140, 128, 0, 56, 0x5000008, 7, 148, 6, 0, 0, 229, 0, 0, 0 },
    { 0x140, 128, 0, 56, 0x5000008, 7, 154, 6, 0, 0, 229, 0, 0, 0 },
    { 0x140, 128, 0, 56, 0x5000008, 7, 160, 6, 0, 0, 229, 0, 0, 0 },
    { 0x140, 128, 0, 56, 0x5000008, 7, 166, 6, 0, 0, 229, 0, 0, 0 },
    { 144, 32, 88, 164, -0x6BFFF758, 0, 175, 1, 0, 0, 229, 0, 0, 0 },
    { 0x140, 0x110, 0, -16, 0x4000008, 7, 172, 6, 0, 0, 229, 0, 0, 0 },
    { 0x140, 0x110, 0, -16, 0x104008, 5, 178, 17, 0, 0, 229, 0, 0, 0 },
    { 0x190, 0x12C, -40, -30, -0x6FFDE580, 0, 182, 14, 0, 0, 229, 0, 0, 0 },
    { 0x100, 32, 32, 36, 0x8000088, 3, 195, 1, 0, 0, 0, 0, 0, 0 },
    { 0x100, 32, 32, 36, 0x8000088, 3, 196, 1, 0, 0, 0, 0, 0, 0 },
    { 0x100, 32, 32, 36, 0x8000088, 3, 197, 1, 0, 0, 0, 0, 0, 0 },
    { 0x100, 32, 32, 36, 0x8000088, 3, 198, 1, 0, 0, 0, 0, 0, 0 },
    { 0x100, 32, 32, 36, 0x8000088, 3, 199, 1, 130, 0, 0, 0, 0, 0 },
    { 0x100, 64, 32, 80, 136, 4, 200, 1, 0, 0, 229, 0, 0, 0 },
    { 0x140, 160, 0, 40, 0x4000088, 3, 201, 3, 0, 0, 229, 0, 0, 0 },
    { 192, 32, 64, 36, 0x4000008, 0, 204, 1, 235, 0, 0, 0, 0, 0 },
    { 0x120, 80, 40, 156, 0x905088, 3, 225, 22, 0, 0, 229, 0, 0, 0 },
    { 0x120, 80, 40, 156, 0x905088, 3, 247, 14, 0, 0, 229, 0, 0, 0 },
    { 0x120, 80, 40, 156, 0x905088, 3, 0x105, 9, 0, 0, 229, 0, 0, 0 },
    { 0x120, 80, 40, 156, 0x905088, 3, 0x10E, 9, 0, 0, 229, 0, 0, 0 },
    { 0x120, 80, 40, 156, 0x905088, 3, 0x117, 9, 0, 0, 229, 0, 0, 0 },
    { 0x100, 140, 56, 50, 0x1255029, 0, 205, 8, 0, 0, 229, 0, 0, 0 },
    { 0x100, 140, 56, 50, 0x1255029, 0, 213, 12, 0, 94, 229, 0, 0, 0 },
    { 0x100, 140, 56, 50, 0x1255029, 0, 0x120, 13, 0, 0, 229, 0, 0, 0 },
    { 0x100, 140, 56, 50, 0x2055029, 0, 0x12D, 17, 0, 0, 229, 0, 0, 0 },
    { 0x100, 140, 56, 50, 0x1255029, 0, 0x13E, 10, 0, 0, 229, 0, 0, 0 },
    { 0x100, 140, 56, 50, 0x2055029, 0, 0x148, 16, 0, 0, 229, 0, 0, 0 },
    { 0x100, 140, 56, 50, 0x1255029, 0, 0x158, 4, 0, 0, 229, 0, 0, 0 },
    { 0x100, 140, 56, 50, 0x3055029, 0, 0x15C, 10, 0, 0, 229, 0, 0, 0 },
    { 0x100, 140, 56, 50, 0x1255029, 0, 0x166, 7, 0, 0, 229, 0, 0, 0 },
    { 0x100, 140, 56, 50, 0x1255029, 0, 0x16D, 13, 0, 0, 229, 0, 0, 0 },
    { 0x100, 140, 56, 50, 0x1255029, 0, 0x17A, 7, 0, 0, 229, 0, 0, 0 },
    { 0x100, 140, 56, 50, 0x1255029, 0, 0x181, 7, 0, 0, 229, 0, 0, 0 },
    { 0x100, 140, 56, 50, 0x1255029, 0, 0x188, 4, 0, 0, 229, 0, 0, 0 },
    { 0x100, 140, 56, 50, 0x1255029, 0, 0x18C, 7, 0, 0, 229, 0, 0, 0 },
    { 0x100, 140, 56, 50, 0x1255029, 0, 0x193, 6, 0, 0, 229, 0, 0, 0 },
    { 0x100, 140, 56, 50, 0x1255029, 0, 0x199, 4, 0, 0, 229, 0, 0, 0 },
    { 0x100, 140, 56, 50, 0x1255029, 0, 0x19D, 4, 0, 0, 229, 0, 0, 0 },
    { 0x100, 140, 56, 50, 0x1255029, 0, 0x1A1, 4, 0, 0, 229, 0, 0, 0 },
    { 0x120, 140, 16, 50, -0x4EFFFB97, 0, 0x1A5, 4, 0, 0, 29, 0, 0, 0 },
    { 0x140, 168, 0, 64, 2056, 0, 198, 6, 0, 0, 229, 0, 0, 0 },
    { 0x140, 128, 0, 56, 0x8000800, 0, 204, 2, 0, 0, 229, 0, 0, 0 },
    { 0x140, 128, 0, 56, 0x8000800, 0, 206, 3, 0, 0, 229, 0, 0, 0 },
    { 0x140, 128, 0, 56, 0x8000800, 0, 209, 3, 0, 0, 229, 0, 0, 0 },
    { 0x140, 128, 0, 56, 0x8000800, 0, 212, 3, 0, 0, 229, 0, 0, 0 },
    { 0x100, 160, 32, 40, -0x5AFFFFD8, 0, 98, 3, 0, 0, 229, 0, 0, 0 },
    { 0x100, 160, 32, 40, -0x5AFFFFD8, 0, 101, 4, 0, 0, 229, 0, 0, 0 },
    { 0x140, 160, 0, 40, -0x5AFFFFD8, 0, 105, 4, 0, 0, 229, 0, 0, 0 },
    { 0x100, 160, 32, 40, -0x5AFFFFD8, 0, 109, 3, 0, 0, 229, 0, 0, 0 },
    { 0x140, 128, 0, 56, -0x5AFFFFD8, 0, 112, 6, 0, 0, 229, 0, 0, 0 },
    { 0x140, 128, 0, 56, -0x5AFFFFD8, 0, 118, 6, 0, 0, 229, 0, 0, 0 },
    { 0x140, 128, 0, 56, -0x5AFFFFD8, 0, 124, 6, 0, 0, 229, 0, 0, 0 },
    { 0x140, 128, 0, 56, -0x5AFFFFD8, 0, 130, 6, 0, 0, 229, 0, 0, 0 },
    { 0x140, 128, 0, 56, -0x5AFFFFD8, 0, 136, 6, 0, 0, 229, 0, 0, 0 },
    { 0x140, 128, 0, 56, -0x5AFFFFD8, 0, 142, 6, 0, 0, 229, 0, 0, 0 },
    { 0x140, 128, 0, 56, -0x5AFFFFD8, 0, 148, 6, 0, 0, 229, 0, 0, 0 },
    { 0x140, 128, 0, 56, -0x5AFFFFD8, 0, 154, 6, 0, 0, 229, 0, 0, 0 },
    { 0x140, 128, 0, 56, -0x5AFFFFD8, 0, 160, 6, 0, 0, 229, 0, 0, 0 },
    { 0x140, 128, 0, 56, -0x5AFFFFD8, 0, 166, 6, 0, 0, 229, 0, 0, 0 },
};
Vtx D_802F97B0[0x10] = {
    { { { -600, 600, -10 }, 0, { 0 }, { 0, 0, 0, 160 } } },
    { { { -600, 1000, -10 }, 0, { 0 }, { 0 } } },
    { { { -1000, 600, -10 }, 0, { 0 }, { 0 } } },
    { { { -600, 600, -10 }, 0, { 0 }, { 0, 0, 0, 160 } } },
    { { { 600, 1000, -10 }, 0, { 0 }, { 0 } } },
    { { { 600, 600, -10 }, 0, { 0 }, { 0, 0, 0, 160 } } },
    { { { 600, 600, -10 }, 0, { 0 }, { 0, 0, 0, 160 } } },
    { { { 1000, 600, -10 }, 0, { 0 }, { 0 } } },
    { { { 600, -600, -10 }, 0, { 0 }, { 0, 0, 0, 160 } } },
    { { { 1000, -600, -10 }, 0, { 0 }, { 0 } } },
    { { { 600, -1000, -10 }, 0, { 0 }, { 0 } } },
    { { { 600, -600, -10 }, 0, { 0 }, { 0, 0, 0, 160 } } },
    { { { -1000, -600, -10 }, 0, { 0 }, { 0 } } },
    { { { -600, -600, -10 }, 0, { 0 }, { 0, 0, 0, 160 } } },
    { { { -600, -600, -10 }, 0, { 0 }, { 0, 0, 0, 160 } } },
    { { { -600, -1000, -10 }, 0, { 0 }, { 0 } } },
};
Gfx D_802F98B0[0x10] = {
    gsSPVertex(D_802F97B0, 16, 0),
    gsSP1Triangle(0, 5, 14, 0),
    gsSP1Triangle(14, 11, 5, 0),
    gsSP1Triangle(1, 2, 3, 2),
    gsSP1Triangle(1, 3, 6, 0),
    gsSP1Triangle(1, 4, 6, 0),
    gsSP1Triangle(4, 7, 6, 0),
    gsSP1Triangle(6, 7, 8, 0),
    gsSP1Triangle(7, 8, 9, 0),
    gsSP1Triangle(8, 9, 10, 0),
    gsSP1Triangle(8, 10, 13, 0),
    gsSP1Triangle(10, 13, 15, 0),
    gsSP1Triangle(12, 13, 15, 0),
    gsSP1Triangle(12, 13, 2, 0),
    gsSP1Triangle(3, 2, 13, 0),
    gsSPEndDisplayList(),
};
s32 D_802F9930 = 1;
UnkStruct_802F9934 D_802F9934[7] = {
    { 189, "RAFTS", D_8030358C },
    { 104, "GAS PLANTS", D_80303594 },
    { 0, "CONTAINERS", D_803035A0 },
    { 186, "SPHERES", D_803035AC },
    { 188, "SPHERES", D_803035B4 },
    { 192, "BEACONS", D_803035BC },
    { 230, "CRATES", D_803035C8 },
};
Vtx D_802F99C0[4] = {
    { { { 6, 12, 6 }, 0, { 480, 480 }, { 255, 255, 255, 255 } } },
    { { { -6, 12, -6 }, 0, { 0, 480 }, { 255, 255, 255, 255 } } },
    { { { -6, 0, -6 }, 0, { 0 }, { 255, 255, 255, 255 } } },
    { { { 6, 0, 6 }, 0, { 480 }, { 255, 255, 255, 255 } } },
};
Vtx D_802F9A00[0x40] = {
    { { { 0 }, 0, { 0 }, { 0 } } },
    { { { 0 }, 0, { 0 }, { 32, 26, 19, 74 } } },
    { { { 13357, 8778 }, 0, { 0 }, { 0 } } },
    { { { 0 }, 0, { 0 }, { 0 } } },
    { { { 0 }, 0, { 0 }, { 0 } } },
    { { { 0, 0, 2825 }, 0x61B, { 20030, 11452 }, { 110, 90, 65, 255 } } },
    { { { -19300, 30463, -28547 }, 0x60C4, { 5138, 3611 }, { 0 } } },
    { { { 0 }, 0, { 0 }, { 0 } } },
    { { { 0 }, 0, { 0 }, { 0 } } },
    { { { 1285, 1307, 11561 }, 0x22A0, { 26449, 15103 }, { 111, 92, 67, 255 } } },
    { { { -15188, -30977, -16986 }, 0x80FF, { 18499, 14492 }, { 9, 10, 9, 39 } } },
    { { { 0 }, 0, { 0 }, { 0 } } },
    { { { 0 }, 0, { 0 }, { 11, 11, 10, 70 } } },
    { { { 10539, 10219, 16703 }, 0x35FF, { 29793, 18687 }, { 113, 95, 71, 255 } } },
    { { { -5421, -22529, -10049 }, 0x97FF, { 27758, 25343 }, { 65, 72, 68, 239 } } },
    { { { 4114, 4426 }, 0, { 0 }, { 0 } } },
    { { { 0 }, 0, { 1029, 1319 }, { 35, 38, 35, 243 } } },
    { { { 10798, 11007, 16707 }, 0x3BFF, { 31078, 19967 }, { 117, 99, 74, 255 } } },
    { { { -12358, -26881, -7479 }, 0xA1FF, { -31616, 28927 }, { 70, 79, 74, 255 } } },
    { { { 12599, 13559, 1543 }, 0x627, { 0 }, { 0 } } },
    { { { 0, 0, 257 }, 0x107, { 3856, 3977 }, { 34, 39, 37, 255 } } },
    { { { 10031, 12031, 16706 }, 0x3BFF, { 32620, 20991 }, { 122, 104, 78, 255 } } },
    { { { -11331, -26625, -9277 }, 0x9CFF, { -20819, -27137 }, { 94, 99, 91, 255 } } },
    { { { 12600, 14079, 6171 }, 0x1A91, { 770, 519 }, { 0 } } },
    { { { 0, 0, 8989 }, 0x158D, { 13357, 9195 }, { 35, 40, 39, 255 } } },
    { { { 9260, 11263, 13880 }, 0x32FF, { 24144, 15615 }, { 101, 85, 63, 255 } } },
    { { { 26456, 16895, 31851 }, 0x53FF, { 31096, 26623 }, { 77, 80, 73, 255 } } },
    { { { 13626, 14335, 21578 }, 0x3BF3, { 16179, 9873 }, { 0 } } },
    { { { 0, 0, 11556 }, 0x1BC4, { 20804, 13055 }, { 78, 67, 50, 255 } } },
    { { { 15160, 12287, 8225 }, 0x1FFF, { 8476, 6399 }, { 63, 35, 25, 255 } } },
    { { { 17191, 7423, 11303 }, 0x20FF, { 8737, 8191 }, { 78, 70, 59, 255 } } },
    { { { 26968, 17663, 31075 }, 0x4AFF, { 21315, 13260 }, { 0 } } },
    { { { 0, 0, 1541 }, 0x417, { 18236, 11479 }, { 90, 76, 56, 255 } } },
    { { { 24400, 15359, 8219 }, 0x16FF, { 17941, 3839 }, { 183, 53, 36, 255 } } },
    { { { -7563, 25343, 27691 }, 0x22FF, { 5652, 4863 }, { 77, 62, 47, 255 } } },
    { { { 27479, 17407, 25939 }, 0x3FD7, { 3595, 2079 }, { 0 } } },
    { { { 0 }, 0, { 514, 279 }, { 38, 32, 23, 211 } } },
    { { { 23115, 14335, 6167 }, 0x13FF, { 17935, 2815 }, { 106, 19, 11, 255 } } },
    { { { 28181, 3327, 24340 }, 0xEFF, { 4369, 4095 }, { 81, 66, 49, 255 } } },
    { { { 15409, 9420, 1541 }, 0x41B, { 0 }, { 0 } } },
    { { { 0 }, 0, { 0 }, { 0 } } },
    { { { 6934, 4501, 7708 }, 0x18FF, { 8718, 3327 }, { 76, 15, 10, 255 } } },
    { { { 19982, 2559, 10253 }, 0xBFF, { 7710, 7167 }, { 40, 34, 26, 141 } } },
    { { { 771, 523 }, 0, { 0 }, { 0 } } },
    { { { 0 }, 0, { 0 }, { 0 } } },
    { { { 0, 0, 514 }, 0x22B, { 8991, 6324 }, { 52, 44, 33, 251 } } },
    { { { 15155, 10239, 8477 }, 0x17B0, { 772, 1071 }, { 0 } } },
    { { { 0 }, 0, { 0 }, { 0 } } },
    { { { 0 }, 0, { 0 }, { 0 } } },
    { { { 0 }, 0, { 0 }, { 4, 3, 2, 35 } } },
    { { { 2055, 1315 }, 0, { 0 }, { 0 } } },
};
Vtx D_802F9E00[0x40] = {
    { { { 5377, 265, 5890 }, 0x10A, { 5890, 266 }, { 22, 3, 1, 10 } } },
    { { { 5122, 265, 4609 }, 8, { 4097, 520 }, { 50, 28, 19, 82 } } },
    { { { 18992, 8788, 7427 }, 12, { 8963, 271 }, { 37, 3, 2, 16 } } },
    { { { 8708, 271, 7939 }, 0x10D, { 7426, 525 }, { 29, 3, 2, 13 } } },
    { { { 5378, 266, 6915 }, 0x10C, { 7683, 525 }, { 30, 3, 1, 13 } } },
    { { { 6915, 12, 8971 }, 0x726, { 25408, 11974 }, { 133, 91, 65, 255 } } },
    { { { -12643, 30719, -19328 }, 0x61D5, { 16662, 4143 }, { 46, 3, 2, 20 } } },
    { { { 10243, 273, 8963 }, 0x210, { 8708, 15 }, { 33, 3, 1, 14 } } },
    { { { 4610, 8, 6915 }, 0x10C, { 9219, 528 }, { 38, 5, 1, 17 } } },
    { { { 11275, 2103, 19243 }, 0x22AA, { -31917, 15359 }, { 137, 95, 67, 255 } } },
    { { { -6226, -31233, -3669 }, 0x82FF, { -31158, 15551 }, { 63, 14, 10, 62 } } },
    { { { 12037, 276, 11525 }, 0x214, { 10500, 531 }, { 35, 3, 1, 15 } } },
    { { { 4098, 263, 6402 }, 0x10B, { 9988, 529 }, { 62, 17, 11, 92 } } },
    { { { 23858, 10495, 28228 }, 0x37FF, { -26267, 18943 }, { 152, 99, 71, 255 } } },
    { { { -41, -22529, -59 }, 0x95FF, { -18572, 25343 }, { 128, 77, 68, 255 } } },
    { { { 19478, 4708, 13829 }, 0x118, { 11267, 275 }, { 32, 2, 1, 14 } } },
    { { { 4610, 520, 5634 }, 0x109, { 9736, 1330 }, { 91, 43, 36, 255 } } },
    { { { 30006, 11519, -31158 }, 0x3CFF, { -19858, 20223 }, { 173, 106, 75, 255 } } },
    { { { -63, -27137, -47 }, 0x9EFF, { -7288, 28415 }, { 155, 85, 74, 255 } } },
    { { { 31804, 13823, 16139 }, 0x840, { 9987, 273 }, { 25, 3, 1, 11 } } },
    { { { 6916, 12, 7173 }, 0x213, { 11541, 3987 }, { 84, 46, 38, 255 } } },
    { { { -30917, 12543, -19117 }, 0x3CFF, { -5763, 21247 }, { 232, 123, 82, 255 } } },
    { { { -48, -27393, -44 }, 0x9AFF, { -72, -27649 }, { 208, 109, 91, 255 } } },
    { { { 32062, 14591, 16926 }, 0x1B9D, { 7686, 531 }, { 20, 2, 2, 9 } } },
    { { { 9476, 529, 20000 }, 0x169C, { 25650, 9727 }, { 88, 47, 40, 255 } } },
    { { { 31034, 11519, -673 }, 0x36FF, { -124, 17151 }, { 255, 148, 76, 255 } } },
    { { { -90, 18943, -101 }, 0x56FF, { -110, 26623 }, { 178, 90, 73, 255 } } },
    { { { 26433, 14591, 30028 }, 0x3DFE, { 21297, 8844 }, { 21, 2, 1, 9 } } },
    { { { 11526, 276, 26155 }, 0x1DE1, { -26549, 13311 }, { 174, 79, 52, 255 } } },
    { { { -17328, 12799, -13489 }, 0x24FF, { -105, 12287 }, { 255, 155, 60, 255 } } },
    { { { -67, 14847, -121 }, 0x2DFF, { -18883, 8959 }, { 152, 80, 61, 255 } } },
    { { { -24737, 17919, -23706 }, 0x4BFF, { 30534, 13273 }, { 35, 3, 2, 15 } } },
    { { { 13061, 278, 19212 }, 0x736, { -23481, 12031 }, { 226, 94, 57, 255 } } },
    { { { -130, 16127, -135 }, 0x25FF, { -67, 21759 }, { 255, 255, 164, 255 } } },
    { { { -1, -22529, -136 }, 0x2FFF, { -3003, 6399 }, { 225, 83, 49, 255 } } },
    { { { -11421, 17663, -20391 }, 0x3EFA, { 19474, 2362 }, { 49, 4, 1, 21 } } },
    { { { 10245, 530, 13318 }, 0x117, { 17930, 1074 }, { 140, 46, 25, 254 } } },
    { { { -142, 15103, -3732 }, 0x21FF, { -38, 24575 }, { 255, 255, 187, 255 } } },
    { { { -11, 26879, -111 }, 0x24FF, { -169, 6143 }, { 255, 93, 52, 255 } } },
    { { { -19649, 10239, 23565 }, 0x53D, { 17158, 285 }, { 51, 6, 1, 23 } } },
    { { { 7940, 270, 10500 }, 0x212, { 14344, 538 }, { 84, 14, 2, 45 } } },
    { { { -27344, 5821, -15540 }, 0x22FF, { -142, 11007 }, { 255, 255, 111, 255 } } },
    { { { -103, 13311, -3514 }, 0x18FF, { -15039, 9215 }, { 169, 54, 28, 188 } } },
    { { { 24847, 1077, 17928 }, 0x11F, { 14597, 537 }, { 46, 5, 2, 21 } } },
    { { { 7427, 269, 8451 }, 0x10E, { 8710, 528 }, { 37, 7, 2, 18 } } },
    { { { 18958, 1058, -27868 }, 0x968, { -149, 9727 }, { 255, 185, 57, 255 } } },
    { { { -126, 14079, -166 }, 0x24FF, { 32541, 2658 }, { 51, 8, 3, 23 } } },
    { { { 10501, 274, 11525 }, 0x314, { 10500, 530 }, { 37, 4, 1, 16 } } },
    { { { 4866, 264, 4354 }, 0x108, { 5124, 9 }, { 35, 6, 1, 16 } } },
    { { { 12039, 277, 21775 }, 0x327, { -6097, 2413 }, { 255, 77, 14, 192 } } },
    { { { -16338, 3955, -25826 }, 0x848, { 28177, 1074 }, { 53, 7, 1, 23 } } },
    { { { 6146, 523, 4867 }, 0x209, { 5635, 266 }, { 24, 2, 1, 10 } } },
    { { { 2817, 261, 3842 }, 7, { 5634, 266 }, { 25, 3, 1, 11 } } },
    { { { 7684, 526, 17673 }, 0x31F, { -27370, 1091 }, { 202, 31, 5, 91 } } },
    { { { 24336, 812, 22286 }, 0x328, { 17160, 285 }, { 55, 7, 2, 25 } } },
    { { { 9219, 528, 4610 }, 0x108, { 3586, 518 }, { 13, 2, 1, 6 } } },
    { { { 2817, 5, 4098 }, 0x208, { 4354, 7 }, { 17, 2, 0, 7 } } },
    { { { 7428, 269, 15880 }, 0x31C, { 26892, 815 }, { 131, 16, 3, 58 } } },
    { { { 15880, 283, 13319 }, 0x117, { 13062, 278 }, { 42, 5, 1, 19 } } },
    { { { 9732, 272, 6915 }, 12, { 4099, 7 }, { 10, 1, 1, 5 } } },
    { { { 2818, 5, 3073 }, 0x105, { 3330, 262 }, { 17, 2, 2, 8 } } },
    { { { 7939, 526, 14086 }, 0x118, { 20744, 804 }, { 96, 11, 2, 42 } } },
    { { { 12550, 790, 9476 }, 0x110, { 9989, 530 }, { 34, 4, 2, 15 } } },
    { { { 7938, 269, 7428 }, 13, { 5378, 521 }, { 12, 2, 2, 6 } } },
};
s32 D_802FA200[0x14] = { 60, 100, 200, 50, 120, 120, 0, 0, 50, 200, 120, 0, 0, 50, 50, 50, 100 };
s32 D_802FA250 = 0;
s32 D_802FA254 = 0;
s32 D_802FA258 = 0;
s32 D_802FA25C = 0;
s32 D_802FA260 = 0;
s32 D_802FA264 = 0;
s32 D_802FA268 = 0;
s32 D_802FA26C = 0;

u8 func_8026AD30(s16 arg0) {
    UnkStruct_802F48D0 *sp2C;
    u8 sp2B;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    sp2B = 0;
    if (!(D_80364A90 & 0x2104)) {
        return 0;
    }
    if (D_80364AF0[D_80364AE8].unk88[9] >= 11) {
        return 0;
    }
    for (sp24 = 0; sp24 < 8 && sp2B == 0; sp24++) {
        sp2C = &D_802F48D0[sp24];
        if (sp2C->unk0 == D_802E8BDC) {
            for (sp20 = 0; sp20 < 16 && sp2B == 0 && sp2C->unk2[sp20] != -1; sp20++) {
                if (sp2C->unk2[sp20] == arg0) {
                    sp1C = D_80364AF0[D_80364AE8].unk88[arg0] < D_802F499A[arg0];
                    sp18 = D_802E8BDC == 0;
                    if (D_8036BAA2[arg0] == 0 && (sp18 || sp1C)) {
                        if (sp1C && !sp18) {
                            D_80364AF0[D_80364AE8].unk88[arg0]++;
                        }
                        D_8036BAA2[arg0] = 1;
                        func_8026AF6C(arg0 | 0x8000 | 0x2000);
                        sp2B = 1;
                    }
                }
            }
        }
    }
    return sp2B;
}

void func_8026AF6C(u16 arg0) {
    u16 sp1E;
    u16 sp1C;

    sp1E = D_8036BB14 & 0xFF;
    sp1C = arg0 & 0xFF;
    if (D_8036BB14) {
        if (D_8036BB14) {
            func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "!yoshiDemandV", "yoshi.c", 0x520);
        }
        func_8029A7E4("NEW: %x OLD:%x\n", arg0, D_8036BB14);
    }
    if ((arg0 & 0x4000) && (arg0 != 0x4000)) {
        func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "yd==YOSHI_DEMAND_OFF", "yoshi.c", 0x525);
    }
    if ((sp1C == 0x1E) || (sp1C == 0x23) || (sp1C == 5) || (sp1C == 0xE)) {
        D_8036BB1A = -1;
    }
    if ((sp1E == 0x1E) || (sp1E == 0x23) || (sp1E == 5) || (sp1E == 0xE)) {
        func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "1==0", "yoshi.c", 0x52C);
        func_8029A7E4("OH MY GOD!\n");
        return;
    }
    if (D_8036BB14) {
        if (D_8036BB14) {
            func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "!yoshiDemandV", "yoshi.c", 0x533);
        }
        func_8029A7E4("GOING FOR NEW: %x OLD:%x\n", arg0, D_8036BB14);
    }
    D_8036BB14 = arg0;
}

u16 func_8026B10C(void) {
    return D_8036BB14;
}

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1[0x43];
} UnkStruct_802E8F94; /* size = 0x44 */

extern UnkStruct_802E8F94 D_802E8F94[];
extern u8 D_802E8BF8;
extern u8 D_8036BAE8[];
extern s16 D_8036BB0C;
extern s8 D_8036BB0E;
extern u16 D_8036BB16;
s32 func_80297EF8(s32);

/* K&R definition: it reads its u8 argument back from the stack slot. */
void func_8026B118(arg0)
    u8 arg0;
{
    UnkStruct_802F8BDC *sp44;
    UnkStruct_802F48D0 *sp40;
    u8 sp3F;
    s32 sp38;
    s32 sp34;
    s32 pad;

    D_8036BB1C = 1;
    D_8036BB16 = 0;
    D_8036BB14 = 0;
    D_8036BB1A = -1;
    D_8036BB18 = -1;
    D_8036BB0C = 0;
    sp44 = NULL;
    D_8036BB0E = 1;
    if (arg0 == 0) {
        for (sp38 = 0; sp38 < 108; sp38++) {
            sp44 = &D_802F8BDC[sp38];
            if (sp44->unk8 & 0x100) {
                sp44->unk8 |= 0x80;
            }
        }
    }
    D_802F8BDC[6].unkC = 3;
    for (sp38 = 0; sp38 < 18; sp38++) {
        D_8036BAE8[sp38] = 0;
    }
    for (sp38 = 0; sp38 < 75; sp38++) {
        D_802F49F4[sp38].unk2E = -1;
    }
    switch (D_80364A98) {
        case 0x80:
        case 0x8000000:
            D_8020C070[25].unk14 = 0;
        case 0x40000000:
            sp44 = &D_802F8BDC[D_802F4868[func_8026F92C(D_802E8F94[D_802E8BDC].unk0)]];
            if (D_802E8BF8 != 0) {
                D_8020C070[29].unk0 &= ~1;
                D_8020C070[29].unk14 = 0xB;
            }
            if (D_802E8F94[D_802E8BDC].unk0 == 1) {
                if (func_80297EF8(D_802E8BDC) != 0) {
                    D_8020C070[18].unk14 = 0x18;
                } else {
                    D_8020C070[18].unk14 = 0;
                }
            } else if (D_802E8F94[D_802E8BDC].unk0 == 0x20) {
                D_8020C070[23].unk0 &= ~0x400;
                D_8020C070[26].unk0 &= ~0x400;
                D_8020C070[27].unk14 = 0;
                D_8020C070[28].unk14 = 0;
            } else {
                D_8020C070[23].unk14 = D_802F4878[func_8026F92C(D_802E8F94[D_802E8BDC].unk0)];
                D_8020C070[26].unk14 = D_802F4878[func_8026F92C(D_802E8F94[D_802E8BDC].unk0)];
                D_8020C070[27].unk14 = 0;
                D_8020C070[28].unk14 = 0;
            }
            break;
        case 0x40000000000:
            sp44 = &D_802F8BDC[22];
            break;
        case 0x4000000000000:
            sp44 = &D_802F8BDC[56];
            break;
        case 0x40:
            sp44 = &D_802F8BDC[D_802F4870[func_8026F92C(D_802E8F94[D_802E8BDC].unk0)]];
            if (D_802E8F94[D_802E8BDC].unk0 == 0x20) {
                D_802F5804[27].unk0 &= ~0x400;
                D_802F5804[28].unk0 &= ~0x400;
                D_802F5804[29].unk14 = 0;
                D_802F5804[30].unk14 = 0;
            } else {
                D_802F5804[27].unk14 = D_802F4878[func_8026F92C(D_802E8F94[D_802E8BDC].unk0)];
                D_802F5804[28].unk14 = D_802F4878[func_8026F92C(D_802E8F94[D_802E8BDC].unk0)];
                D_802F5804[29].unk14 = 0;
                D_802F5804[30].unk14 = 0;
            }
            break;
        case 0x2000:
            if (((D_80364AF0[D_80364AE8].unk0[D_802E8BDC + 0x18] > 0 &&
                  D_80364AF0[D_80364AE8].unk0[D_802E8BDC + 0x18] < 6)
                     ? 1
                     : 0) &&
                D_802E8F94[D_802E8BDC].unk0 == 1) {
                sp44 = &D_802F8BDC[6];
            } else {
                sp44 = NULL;
            }
            break;
        case 0x100000000000:
            switch (D_802E8BDC) {
                case 0x37:
                    sp44 = &D_802F8BDC[65];
                    break;
                case 0x1C:
                    sp44 = &D_802F8BDC[66];
                    break;
                case 0x35:
                    sp44 = &D_802F8BDC[67];
                    break;
                case 7:
                    sp44 = &D_802F8BDC[68];
                    break;
                case 0x13:
                    sp44 = &D_802F8BDC[69];
                    break;
                default:
                    sp44 = NULL;
                    break;
            }
            break;
        default:
            sp44 = NULL;
            break;
    }
    if (sp44 != NULL) {
        func_8026BA7C(sp44);
    }
    if (D_80364A98 & 0x2004) {
        for (sp38 = 0, sp3F = 0; sp38 < 8 && sp3F == 0; sp38++) {
            sp40 = &D_802F48D0[sp38];
            if (sp40->unk0 == D_802E8BDC) {
                for (sp34 = 0; sp34 < 16 && sp40->unk2[sp34] != -1; sp34++) {
                    func_8026BA7C(&D_802F8BDC[sp40->unk2[sp34]]);
                }
            }
        }
    }
}

void func_8026B8F8(void) {
    if (D_80364AA8 & 0x20) {
        D_8020C070[23].unk0 |= 0x400;
        D_8020C070[26].unk0 |= 0x400;
        D_802F5804[27].unk0 |= 0x400;
        D_802F5804[28].unk0 |= 0x400;
        D_8020C070[23].unk14 = D_8020C070[26].unk14 = D_802F5804[27].unk14 = D_802F5804[28].unk14 = func_8026FA38(NULL, NULL);
        if (D_80364A98 == 0x40) {
            func_8026BA7C(&D_802F8BDC[D_802F4870[func_8026F92C(D_80364AA8)]]);
        } else {
            func_8026BA7C(&D_802F8BDC[D_802F4868[func_8026F92C(D_80364AA8)]]);
        }
    }
}

void func_8026BA7C(UnkStruct_802F8BDC *arg0) {
    UnkStruct_802F49F4 *sp2C;
    s32 sp28;
    u8 sp27;
    UnkStruct_8036BB10 *sp20;

    sp27 = 4;
    func_8026FB50(arg0);
    if (arg0->unk8 & 0x20000) {
        sp27 = 0;
    }
    for (sp28 = arg0->unkE; sp28 < arg0->unkE + arg0->unk10; sp28++) {
        sp20 = &D_8036BB10[sp28];
        if (sp20->unk0 & 0x400) {
            sp2C = &D_802F49F4[sp20->unk14];
            if (sp2C->unk2E == -1) {
                sp20->unk1A = func_80272C5C(sp2C->unk6, 0, sp2C->unk4, sp2C->unk2C, sp2C->unk2D | sp27, 1.0f);
                D_8036BA98[sp20->unk14] = 0;
            } else {
                sp20->unk1A = sp2C->unk2E;
            }
        }
    }
}

typedef struct {
    /* 0x0000 */ u8 unk0[0x1240];
    /* 0x1240 */ Mtx unk1240;
    /* 0x1280 */ Mtx unk1280;
    /* 0x12C0 */ Mtx unk12C0;
    /* 0x1300 */ Mtx unk1300;
    /* 0x1340 */ u8 unk1340[0xAC0];
    /* 0x1E00 */ Vtx unk1E00[0x1E0];
    /* 0x3C00 */ u8 unk3C00[0x1D898];
} UnkStruct_803156F8; /* size = 0x21498 */

Gfx *func_8026BCE0(Gfx *, UnkStruct_803156F8 *, s32 *);

void func_8026BBD0(Gfx *arg0, UnkStruct_803156F8 *arg1, s32 *arg2) {
    Gfx *gfx;

    gfx = arg0;
    if (D_8036BB1C == 1 && D_8036BB18 != -1) {
        func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "!(yoshiState==YOSHI_OFF && currentYoshiWindow!=NO_YOSHI_WINDOW)", "yoshi.c", 0x61F);
    }
    gfx = func_8026BCE0(gfx, arg1, arg2);
    if (D_8036BB1C == 1 && D_8036BB18 != -1) {
        func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "!(yoshiState==YOSHI_OFF && currentYoshiWindow!=NO_YOSHI_WINDOW)", "yoshi.c", 0x623);
    }
    gDPPipeSync(gfx++);
    *arg2 += gfx - arg0;
}

extern u8 D_802E8BD4;
extern u8 D_802E8BD8;
extern u8 D_8035805C;
extern u8 D_803643D6;
extern u8 D_803643DB;
extern u8 D_8036BA48[];
extern f32 D_8036BB08;
extern s16 D_8036BB20;
extern f32 D_8036BB28;
extern f32 D_8036BB2C;
extern s32 D_8036BB30;
extern f32 D_8036BB34;
extern f32 D_8036BB38;
extern u16 D_8036BB3C;
extern u16 D_8036BB3E;
extern u32 D_8036BB40;
extern s32 D_8036BB44;
extern s8 D_80370C11;
extern s8 D_80370C12;
extern s8 D_80370C13;
extern s8 D_80370C14;
extern u16 D_80370C28;
extern u16 D_80370C2A;
f32 func_802574F0(f32);
void func_80259BD4(Gfx **, UnkStruct_803156F8 *);
void func_80259DC8(UnkStruct_803156F8 *, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
                   s32, s32, s32);
s32 func_8025B498(s16, u16, char *, u16 *);
void func_8026EF70(UnkStruct_802F8BDC *);
void func_80261570(f32);
void *func_8026F004(UnkStruct_802F8BDC *, u16, u8);
u8 func_8026F644(UnkStruct_8026F644 *, u16 *, s16);
u16 func_8026F82C(u16, u16, u16);
Gfx *func_80272ED8(Gfx *, u8, s16, s16, u8, u8, f32);
Gfx *func_80274868(Gfx *);
Gfx *func_80274998(Gfx *);
Gfx *func_80274AA4(Gfx *);
Gfx *func_80274B08(Gfx *);
Gfx *func_80275DA4(Gfx *, u8);
s32 func_80276080(UnkStruct_803156F8 *, u8, s32, s32, s32, s32, s32, u8, u8, u8, u8);
s32 func_80276130(UnkStruct_803156F8 *, u8, s32, s32, s32, s32, s32, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8,
                  u8, u8, u8, u8);

Gfx *func_8026BCE0(Gfx *arg0, UnkStruct_803156F8 *arg1, s32 *arg2) {
    UnkStruct_802F8BDC *sp14C;
    UnkStruct_8036BB10 *sp148;
    void *sp144;
    s32 sp140;
    Gfx *sp13C;
    u16 sp13A;
    u16 sp138;
    u16 sp136;
    u16 sp134;
    u16 sp132;
    u16 sp130;
    UnkStruct_802F47B0 *sp12C;
    f32 sp128;
    u16 sp126;
    u16 sp124;
    s32 sp120;
    u8 sp11F;

    sp13C = arg0;
    sp132 = (D_803156C4 - D_8036BB40) * 15;
    sp130 = 0;
    sp128 = 1.0f;
    D_8036BB40 = D_803156C4;
    D_8036BB0C += D_8036BB0E * sp132;
    if (D_8036BB0C >= 0x100) {
        D_8036BB0C = 0xFF;
        D_8036BB0E = -D_8036BB0E;
    }
    if (D_8036BB0C < 0) {
        D_8036BB0C = 0;
        D_8036BB0E = -D_8036BB0E;
    }
    sp12C = &D_802F47B0[16];
    sp12C->unk1 = 0xFF - D_8036BB0C;
    sp12C->unk5 = D_8036BB0C;
    sp12C = &D_802F47B0[17];
    sp12C->unk1 = 0xAA - D_8036BB0C * 2 / 3;
    sp12C->unk5 = D_8036BB0C * 2 / 3;
    sp12C = &D_802F47B0[18];
    sp12C->unk0 = sp12C->unk1 = 0xFF - D_8036BB0C;
    sp12C->unk4 = sp12C->unk5 = D_8036BB0C;
    sp12C = &D_802F47B0[19];
    sp12C->unk2 = sp12C->unk1 = 0xFF - D_8036BB0C;
    sp12C->unk6 = sp12C->unk5 = D_8036BB0C;
    sp12C = &D_802F47B0[20];
    sp12C->unk2 = 0xFF - D_8036BB0C;
    sp12C->unk6 = D_8036BB0C;
    if (D_80364A90 == 0x200 && D_803643DB != 0 && D_803643D6 != 0) {
        D_8036BB1A = -1;
        if (D_8036BB1C == 4 || D_8036BB1C == 2) {
            func_8029A7E4("putting off!\n");
            func_8026AF6C(0x4000);
        }
    }
    if (D_8036BB18 == -1 && (D_8036BB14 & 0x4000)) {
        func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "1==0", "yoshi.c", 0x65B);
        D_8036BB14 = 0;
        return arg0;
    }
    if (D_8036BB14 != 0) {
        sp126 = D_8036BB14 & 0xFF;
        sp124 = D_8036BB14 & 0x2000;
        sp120 = 0;
        func_8029A7E4("yoshiDemand=%x\n", D_8036BB14);
        if (D_8036BB14 & 0x8000) {
            D_8036BB1A = -1;
            if (D_8036BB18 != -1) {
                sp120 = D_802F8BDC[D_8036BB18].unk8 & 0x8000000;
            }
            if (D_8036BB1C == 1 || sp124 != 0 || sp120 != 0) {
                D_8036BB18 = sp126;
                D_8036BB1C = 1;
            } else {
                D_8036BB1A = sp126;
            }
        }
        if (D_8036BB1C != 8) {
            sp130 = 1;
        }
        D_8036BB14 = 0;
    }
    if (D_8036BB18 == -1) {
        D_8036BB18 = D_8036BB1A;
        D_8036BB1A = -1;
        if (D_8036BB18 == -1) {
            return arg0;
        }
        sp130 = 1;
    }
    sp14C = &D_802F8BDC[D_8036BB18];
    func_8026FB50(sp14C);
    if ((sp14C->unk8 & 0x20) && D_8036BB1C == 2) {
        if ((((D_80370C28 & 0x8000) && !(D_80370C2A & 0x8000)) ||
             ((sp14C->unk8 & 0x80000000) && (D_80370C28 & 0x1000) && !(D_80370C2A & 0x1000))) &&
            sp14C->unk1A != 0) {
            sp13A = D_8036BB10[sp14C->unk18].unk16;
            if (sp13A != 0) {
                func_80260650(D_80367738, sp13A, 0);
            }
            if (D_8036BB10[sp14C->unk18].unk0 & 0x10) {
                D_802E8BD4 = 1;
            }
            D_8036BB16 = sp14C->unk18;
            sp130 = 1;
        }
        if ((D_80370C28 & 0x4000) && !(D_80370C2A & 0x4000)) {
            if ((sp14C->unk8 & 0x20000000) && sp14C->unk1A != 0) {
                func_80260650(D_80367738, 0xDE, 0);
                D_8036BB16 = 0xFFFF;
                sp130 = 1;
                if (sp14C->unk8 & 0x40000000) {
                    D_802E8BD4 = 1;
                }
            } else {
                func_80260650(D_80367738, 0xD0, 0);
            }
        }
    }
    if (sp130 != 0) {
        D_8036BAFC = D_803156C4;
        switch (D_8036BB1C) {
            case 8:
                D_8036BAFC = D_803156C4 - D_8036BB08 * D_8036BB38 * D_8036BB34;
            case 1:
                D_8036BB1C = 4;
                D_8036BB34 = 1.0f;
                if (sp14C->unk8 & 0x18) {
                    D_8036BB08 = 40.0f;
                } else {
                    D_8036BB08 = 13.333333f;
                }
                func_8026EF70(sp14C);
                sp13A = sp14C->unk12;
                if (sp13A != 0) {
                    func_80260650(D_80367738, sp13A, 0);
                }
                if (!(sp14C->unk8 & 0x400)) {
                    for (sp138 = sp14C->unkE; !(D_8036BB10[sp138].unk0 & 1) && sp138 < sp14C->unkE + sp14C->unk10;
                         sp138++) {
                    }
                    sp14C->unk18 = sp138;
                }
                for (sp138 = sp14C->unkE; sp138 < sp14C->unkE + sp14C->unk10; sp138++) {
                    sp148 = &D_8036BB10[sp138];
                    if (sp148->unk0 & 0x20) {
                        if (sp14C->unk8 & 0x80000) {
                            sp148->unk2 = func_8025B498(sp14C->unk0 / 2, sp148->unk6, sp148->unkC, sp148->unk10);
                        } else {
                            sp148->unk2 = func_8025B498(sp14C->unk0 / 2, sp148->unk6, sp148->unkC, sp148->unk10);
                        }
                    }
                }
                if (sp14C->unk8 & 1) {
                    D_802E8BD8 = 1;
                }
                if (sp14C->unk8 & 2) {
                    func_80261570(0.0f);
                }
                if (sp14C->unk8 & 0x100000) {
                    D_8036BB28 = sp14C->unk2;
                } else {
                    D_8036BB28 = sp14C->unk2 / 2 - D_8036BB10[sp14C->unk18].unk4;
                    if (sp14C->unk8 & 0x40000) {
                        D_8036BB28 -= D_8036BB10[sp14C->unk18].unk8 / 2;
                    }
                }
                D_8036BB2C = D_8036BB28;
                break;
            case 4:
                D_8036BAFC = (D_8036BB38 - sp128) * D_8036BB08 + D_803156C4;
            case 2:
                D_8036BB1C = 8;
                sp13A = sp14C->unk14;
                if (sp13A != 0) {
                    func_80260650(D_80367738, sp13A, 0);
                }
                if (sp14C->unk8 & 0x200000) {
                    D_802E8BD4 = 1;
                }
                if (sp14C->unk8 & 4) {
                    func_80261570(1.0f);
                }
                break;
        }
    }
    switch (D_8036BB1C) {
        case 2:
            if (sp14C->unk8 & 0x100000) {
                sp11F = D_8036BB2C < sp14C->unk2 / 8 - D_8036BB10[sp14C->unkE + sp14C->unk10 - 1].unk4;
            } else {
                sp11F = sp14C->unkC != 0 && (D_803156C4 - D_8036BAFC) / 60.0f > sp14C->unkC &&
                        (!(sp14C->unk8 & 0x400000) || !(D_8036BB1E != 0));
            }
            if (sp11F != 0) {
                sp13A = sp14C->unk14;
                if (sp13A != 0) {
                    func_80260650(D_80367738, sp13A, 0);
                }
                if (sp14C->unk8 & 0x2000) {
                    func_80261570(0.0f);
                }
                D_8036BB1C = 8;
                D_8036BAFC = D_803156C4;
            }
            break;
        case 4:
            D_8036BB38 = (D_803156C4 - D_8036BAFC) / D_8036BB08;
            if (sp128 < D_8036BB38) {
                D_8036BAFC = D_803156C4;
                D_8036BB1C = 2;
                D_8036BB38 = sp128;
                if (sp14C->unk8 & 0x40) {
                    D_8036BB3C = 0x200;
                    D_8036BB3E = 0x100;
                } else {
                    D_8036BB3C = 0x800;
                    D_8036BB3E = 0x400;
                }
                if (sp14C->unk8 & 0x10000000) {
                    sp14C->unk1A = 1;
                } else {
                    sp14C->unk1A = 0;
                }
                if (func_8026F8A8(sp14C->unkE, sp14C->unk10, sp14C->unk18, 1) == sp14C->unk18) {
                    sp14C->unk1A = 1;
                }
            }
            break;
        case 8:
            D_8036BB38 = sp128 - (D_803156C4 - D_8036BAFC) / D_8036BB08;
            if (D_8036BB38 < 0.001) {
                D_8036BB38 = 0.0f;
                D_8036BB1C = 1;
                if (sp14C->unk8 & 0x2000000) {
                    D_802E8BD4 = 1;
                }
                if (sp14C->unk8 & 0x100) {
                    sp14C->unk8 &= ~0x80;
                }
                D_8036BB18 = -1;
                return arg0;
            }
            break;
    }
    if (D_8036BB1C != 1) {
        D_8036BB20 = (func_802574F0(D_8036BB38 * D_8036BB34 / sp128 * 1.57 + 4.71) + 1.0) * 255.0;
    }
    if (D_8036BB1C != 1 && D_8036BB38 * D_8036BB34 > 0.1) {
        sp136 = sp14C->unk0 / 2;
        sp134 = sp14C->unk2 / 2;
        guOrtho(&arg1->unk1240, -sp14C->unk4 - sp136, -sp14C->unk4 - sp136 + 319, -sp14C->unk6 - sp134 + 239,
                -sp14C->unk6 - sp134, -256.0f, 256.0f, 256.0f);
        gSPMatrix(sp13C++, OS_K0_TO_PHYSICAL(&arg1->unk1240), G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
        if (sp14C->unk8 & 0x10) {
            guRotate(&arg1->unk12C0, 180.0 - D_8036BB38 * D_8036BB34 / sp128 * 180.0, 2.0f, 0.0f, 1.0f);
            gSPMatrix(sp13C++, OS_K0_TO_PHYSICAL(&arg1->unk12C0), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
        } else {
            guTranslate(&arg1->unk12C0, 0.0f, 0.0f, 0.0f);
            gSPMatrix(sp13C++, OS_K0_TO_PHYSICAL(&arg1->unk12C0), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
        }
        gSPMatrix(sp13C++, OS_K0_TO_PHYSICAL(&arg1->unk1300), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
        gSPPopMatrix(sp13C++, G_MTX_MODELVIEW);
        if (sp14C->unk8 & 8) {
            guScale(&arg1->unk1300, sp136 * D_8036BB38 * D_8036BB34 / 1000.0f,
                    sp134 * D_8036BB38 * D_8036BB34 / 1000.0f, 1.0f);
            gSPMatrix(sp13C++, OS_K0_TO_PHYSICAL(&arg1->unk1300), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
        } else {
            guScale(&arg1->unk1300, sp136 / 1000.0f, sp134 / 1000.0f, 1.0f);
            gSPMatrix(sp13C++, OS_K0_TO_PHYSICAL(&arg1->unk1300), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
        }
        gDPPipeSync(sp13C++);
        gDPSetRenderMode(sp13C++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
        gDPSetCombineMode(sp13C++, G_CC_SHADE, G_CC_SHADE);
        gSPClearGeometryMode(sp13C++, 0xFFFFFFFF);
        gSPSetGeometryMode(sp13C++, G_SHADE | G_SHADING_SMOOTH);
        gSPTexture(sp13C++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
        if (!(sp14C->unk8 & 0x200)) {
            gSPDisplayList(sp13C++, D_802F98B0);
        }
        gSPPopMatrix(sp13C++, G_MTX_MODELVIEW);
        if (sp14C->unk8 & 8) {
            guScale(&arg1->unk1280, D_8036BB38, D_8036BB38, 1.0f);
            gSPMatrix(sp13C++, OS_K0_TO_PHYSICAL(&arg1->unk1280), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
        }
        {
            s32 spD8;
            s32 spD4;
            u16 spD2;
            u16 spD0;
            s32 spCC;
            s16 spCA;
            UnkStruct_802F47B0 *spC4;

            if ((sp14C->unk8 & 0x20) && D_8036BB1C == 2) {
                spD8 = 0;
                spD4 = 0;
                if (D_8036BB3C == 0x800) {
                    if (D_80370C12 >= 31 && D_80370C14 < 31) {
                        spD8 = 1;
                    } else {
                        spD8 = 0;
                    }
                } else if (D_80370C11 < -30 && D_80370C13 >= -30) {
                    spD8 = 1;
                } else {
                    spD8 = 0;
                }
                if (D_8036BB3E == 0x400) {
                    if (D_80370C12 < -30 && D_80370C14 >= -30) {
                        spD4 = 1;
                    } else {
                        spD4 = 0;
                    }
                } else if (D_80370C11 >= 31 && D_80370C13 < 31) {
                    spD4 = 1;
                } else {
                    spD4 = 0;
                }
                if (((D_80370C28 & D_8036BB3C) && !(D_80370C2A & D_8036BB3C)) || spD8 != 0) {
                    spD2 = func_8026F82C(sp14C->unkE, sp14C->unk18, 1);
                    sp13A = sp14C->unk16;
                    if (sp13A != 0) {
                        if (spD2 != sp14C->unk18) {
                            func_80260650(D_80367738, sp13A, 0);
                        } else {
                            func_80260650(D_80367738, 0xD0, 0);
                        }
                    }
                    D_8036BB28 += D_8036BB10[sp14C->unk18].unk4 - D_8036BB10[spD2].unk4;
                    sp14C->unk18 = spD2;
                } else if ((((sp14C->unk1A != 0 ? 0 : 0x8000) | D_8036BB3E) & D_80370C28 &&
                            !(((sp14C->unk1A != 0 ? 0 : 0x8000) | D_8036BB3E) & D_80370C2A)) ||
                           spD4 != 0) {
                    spD0 = func_8026F8A8(sp14C->unkE, sp14C->unk10, sp14C->unk18, 1);
                    if (func_8026F8A8(sp14C->unkE, sp14C->unk10, spD0, 1) == spD0) {
                        sp14C->unk1A = 1;
                    }
                    sp13A = sp14C->unk16;
                    if (sp13A != 0) {
                        if (spD0 != sp14C->unk18) {
                            func_80260650(D_80367738, sp13A, 0);
                        } else {
                            func_80260650(D_80367738, 0xD0, 0);
                        }
                    }
                    D_8036BB28 += D_8036BB10[sp14C->unk18].unk4 - D_8036BB10[spD0].unk4;
                    sp14C->unk18 = spD0;
                    D_8036BAFC = D_803156C4;
                }
            }
            if (sp14C->unk8 & 0x4000) {
                if (sp14C->unk8 & 0x100000) {
                    if (sp14C->unkC == 0 || !((D_803156C4 - D_8036BAFC) / 60.0f < sp14C->unkC)) {
                        if (sp14C->unk8 & 0x800000) {
                            D_8036BB2C -= 0.5;
                        } else {
                            D_8036BB2C -= 1.0;
                        }
                    }
                } else {
                    D_8036BB2C += (D_8036BB28 - D_8036BB2C) * 0.1;
                }
                if (sp14C->unk8 & 0x10000) {
                    spCC = 0;
                    if (sp14C->unk8 & 0x40000) {
                        spCA = 0x12;
                    } else {
                        spCA = 0x1C;
                    }
                    if (!(D_80364A90 & 0xC9FD0FE79BFF80B0) || D_8035805C != 0) {
                        D_8036BB44 += D_802F9930;
                    }
                    if (D_802F9930 < 0) {
                        D_8036BB44 += D_802F9930 * 2;
                    }
                    if (D_8036BB44 < 0 || D_8036BB44 >= 8) {
                        D_8036BB44 -= D_802F9930 * 2;
                        D_802F9930 = -D_802F9930;
                    }
                    if (func_8026F8A8(sp14C->unkE, sp14C->unk10, sp14C->unk18, 1) != sp14C->unk18) {
                        spC4 = &D_802F47B0[18];
                        spCC = func_80276130(arg1, 0, spCC, -sp136, sp134 - D_8036BB44 - spCA, 16, D_8036BB44 / 2 + 10,
                                             spC4->unk0, spC4->unk1, spC4->unk2, D_8036BB20, spC4->unk4, spC4->unk5,
                                             spC4->unk6, D_8036BB20, spC4->unk0, spC4->unk1, spC4->unk2, D_8036BB20,
                                             spC4->unk4, spC4->unk5, spC4->unk6, D_8036BB20);
                        spCC = func_80276080(arg1, 0, spCC, -3 - sp136, sp134 - D_8036BB44 - spCA + 3, 16,
                                             D_8036BB44 / 2 + 10, 0, 0, 0, D_8036BB20 / 2);
                        sp13C = func_80275DA4(sp13C, 1);
                        gSPVertex(sp13C++, arg1->unk1E00, 8, 0);
                        gSP1Triangle(sp13C++, 4, 5, 6, 0);
                        gSP1Triangle(sp13C++, 4, 6, 7, 0);
                        gSP1Triangle(sp13C++, 0, 1, 2, 0);
                        gSP1Triangle(sp13C++, 0, 2, 3, 0);
                    }
                    if (func_8026F82C(sp14C->unkE, sp14C->unk18, 1) != sp14C->unk18) {
                        /* volatile: these colours are reloaded, not reused as in the call above. */
                        volatile UnkStruct_802F47B0 *spAC;

                        spAC = &D_802F47B0[18];
                        spCC = func_80276130(arg1, 1, spCC, -sp136, D_8036BB44 - sp134 + spCA, 16, D_8036BB44 / 2 + 10,
                                             spAC->unk0, spAC->unk1, spAC->unk2, D_8036BB20, spAC->unk4, spAC->unk5,
                                             spAC->unk6, D_8036BB20, spAC->unk0, spAC->unk1, spAC->unk2, D_8036BB20,
                                             spAC->unk4, spAC->unk5, spAC->unk6, D_8036BB20);
                        spCC = func_80276080(arg1, 1, spCC, -3 - sp136, D_8036BB44 - sp134 + spCA - 3, 16,
                                             D_8036BB44 / 2 + 10, 0, 0, 0, D_8036BB20 / 2);
                        sp13C = func_80275DA4(sp13C, 1);
                        gSPVertex(sp13C++, &arg1->unk1E00[spCC - 8], 8, 0);
                        gSP1Triangle(sp13C++, 4, 5, 6, 0);
                        gSP1Triangle(sp13C++, 4, 6, 7, 0);
                        gSP1Triangle(sp13C++, 0, 1, 2, 0);
                        gSP1Triangle(sp13C++, 0, 2, 3, 0);
                    }
                }
            } else {
                D_8036BB2C = 0.0f;
            }
        }
        {
            UnkStruct_802F49F4 *sp94;
            s16 sp92;
            s16 sp90;
            u8 sp8F;
            u8 sp8E;
            u8 sp8D;
            u8 sp8C;
            u8 sp8B;

            D_8036BB30 = D_8036BB2C;
            if (sp14C->unk8 & 0x1000) {
                if (sp14C->unk8 & 0x20000) {
                    sp13C = func_80274868(sp13C);
                } else {
                    sp13C = func_80274998(sp13C);
                }
                for (sp138 = sp14C->unkE; sp138 < sp14C->unkE + sp14C->unk10; sp138++) {
                    sp148 = &D_8036BB10[sp138];
                    if (!(sp148->unk0 & 0x800) && (sp148->unk0 & 0x400) &&
                        (!(sp148->unk0 & 0x300) || sp138 <= D_8036BB04)) {
                        sp94 = &D_802F49F4[sp148->unk14];
                        if (sp14C->unk8 & 0x20000) {
                            sp92 = sp14C->unk4;
                        } else {
                            sp92 = -sp136;
                        }
                        if (sp14C->unk8 & 0x20000) {
                            sp90 = sp14C->unk6;
                        } else {
                            sp90 = -sp134;
                        }
                        sp8F = 1;
                        sp8E = sp94->unk25;
                        if ((sp148->unk0 & 1) && sp138 != sp14C->unk18) {
                            sp8F = 0;
                        }
                        sp8D = D_8036BA48[sp148->unk14];
                        sp8C = D_8036BA48[sp148->unk14] = D_803156C4 * 60 / 60 / sp94->unk26 % sp94->unk1A;
                        if (sp8C != sp8D && (sp8F != 0 || D_8036BA98[sp148->unk14] != 0)) {
                            D_8036BA98[sp148->unk14] = (D_8036BA98[sp148->unk14] + 1) % sp94->unk1A;
                        }
                        sp8B = sp94->unk1B[D_8036BA98[sp148->unk14]];
                        if (sp8B != 0) {
                            if (sp8F != 0) {
                                if (sp138 == sp14C->unk18 && (sp148->unk0 & 0x40)) {
                                    sp8E |= 8;
                                }
                                sp13C = func_80272ED8(
                                    sp13C, sp148->unk1A + sp8B - 1, sp94->unk0 + sp148->unk2 + sp92,
                                    ((sp148->unk0 & 0x1000) ? D_8036BB30 : 0) + (sp94->unk2 + sp148->unk4 + sp90),
                                    func_8026F644((UnkStruct_8026F644 *) sp14C, &sp148->unk0,
                                                     sp148->unk4 + sp94->unk2 - sp134 + D_8036BB30 + 8) *
                                        D_8036BB38 * D_8036BB34,
                                    sp8E, sp94->unk28);
                            } else {
                                sp13C = func_80272ED8(
                                    sp13C, sp148->unk1A + sp8B - 1, sp94->unk0 + sp148->unk2 + sp92,
                                    ((sp148->unk0 & 0x1000) ? D_8036BB30 : 0) + (sp94->unk2 + sp148->unk4 + sp90),
                                    func_8026F644((UnkStruct_8026F644 *) sp14C, &sp148->unk0,
                                                     sp148->unk4 + sp94->unk2 - sp134 + D_8036BB30 + 8) *
                                        D_8036BB38 * D_8036BB34 * 0.7,
                                    sp8E & ~1, sp94->unk28);
                            }
                        }
                    }
                }
                if (sp14C->unk8 & 0x20000) {
                    sp13C = func_80274AA4(sp13C);
                } else {
                    sp13C = func_80274B08(sp13C);
                }
            }
        }
        if (D_8036BB18 < 0x62 || D_8036BB18 >= 0x6C || D_80364A90 == 2) {
            for (sp138 = sp14C->unkE; sp138 < sp14C->unkE + sp14C->unk10; sp138++) {
                sp148 = &D_8036BB10[sp138];
                sp140 = 0;
                sp144 = func_8026F004(sp14C, sp138, 0);
                if ((sp148->unk0 & 0x80) && !(sp148->unk0 & 0x800)) {
                    if (sp138 == sp14C->unk18) {
                        func_80259DC8(
                            arg1, sp144, sp140, sp148->unk0 & 8, 0, sp148->unk2 - sp136 - 3,
                            ((sp148->unk0 & 0x1000) ? D_8036BB30 : 0) + (sp148->unk4 - sp134) + 3, sp148->unk6,
                            sp148->unk8, 1, 0, 0, 0,
                            (D_8036BB20 * D_802F47B0[sp148->unk19].unk3) *
                                func_8026F644((UnkStruct_8026F644 *) sp14C, &sp148->unk0,
                                              sp148->unk4 - sp134 + D_8036BB30) / 65025 / 2,
                            0, 0, 0,
                            (D_8036BB20 * D_802F47B0[sp148->unk19].unk3) *
                                func_8026F644((UnkStruct_8026F644 *) sp14C, &sp148->unk0,
                                              sp148->unk4 - sp134 + D_8036BB30 + sp148->unk8) / 65025 / 2);
                    } else if (!(sp148->unk0 & 4) || D_803156C4 % 23 * 60 / 60 < 16) {
                        func_80259DC8(
                            arg1, sp144, sp140, sp148->unk0 & 8, 0, sp148->unk2 - sp136 - 3,
                            ((sp148->unk0 & 0x1000) ? D_8036BB30 : 0) + (sp148->unk4 - sp134) + 3, sp148->unk6,
                            sp148->unk8, 1, 0, 0, 0,
                            (D_8036BB20 * D_802F47B0[sp148->unk18].unk3) *
                                func_8026F644((UnkStruct_8026F644 *) sp14C, &sp148->unk0,
                                              sp148->unk4 - sp134 + D_8036BB30) / 65025 / 2,
                            0, 0, 0,
                            (D_8036BB20 * D_802F47B0[sp148->unk18].unk3) *
                                func_8026F644((UnkStruct_8026F644 *) sp14C, &sp148->unk0,
                                              sp148->unk4 - sp134 + D_8036BB30 + sp148->unk8) / 65025 / 2);
                    }
                }
            }
        }
        for (sp138 = sp14C->unkE; sp138 < sp14C->unkE + sp14C->unk10; sp138++) {
            sp148 = &D_8036BB10[sp138];
            sp140 = 0;
            sp144 = func_8026F004(sp14C, sp138, 0);
            if (!(sp148->unk0 & 0x800)) {
                if (sp138 == sp14C->unk18) {
                    if ((!(sp148->unk0 & 4) || D_803156C4 % 23 * 60 / 60 < 16) &&
                        (!(sp148->unk0 & 0x40) || D_803156C4 % 15 * 60 / 60 < 11)) {
                        func_80259DC8(arg1, sp144, sp140, sp148->unk0 & 8, 0, sp148->unk2 - sp136,
                                      ((sp148->unk0 & 0x1000) ? D_8036BB30 : 0) + (sp148->unk4 - sp134), sp148->unk6,
                                      sp148->unk8, 1, D_802F47B0[sp148->unk19].unk0, D_802F47B0[sp148->unk19].unk1,
                                      D_802F47B0[sp148->unk19].unk2,
                                      (D_8036BB20 * D_802F47B0[sp148->unk19].unk3) *
                                          func_8026F644((UnkStruct_8026F644 *) sp14C, &sp148->unk0,
                                                        sp148->unk4 - sp134 + D_8036BB30) /
                                          65025,
                                      D_802F47B0[sp148->unk19].unk4, D_802F47B0[sp148->unk19].unk5,
                                      D_802F47B0[sp148->unk19].unk6,
                                      (D_8036BB20 * D_802F47B0[sp148->unk19].unk7) *
                                          func_8026F644((UnkStruct_8026F644 *) sp14C, &sp148->unk0,
                                                        sp148->unk4 - sp134 + D_8036BB30 + sp148->unk8) / 65025);
                    }
                } else if (!(sp148->unk0 & 4) || D_803156C4 % 23 * 60 / 60 < 16) {
                    func_80259DC8(arg1, sp144, sp140, sp148->unk0 & 8, 0, sp148->unk2 - sp136,
                                  ((sp148->unk0 & 0x1000) ? D_8036BB30 : 0) + (sp148->unk4 - sp134), sp148->unk6,
                                  sp148->unk8, 1, D_802F47B0[sp148->unk18].unk0, D_802F47B0[sp148->unk18].unk1,
                                  D_802F47B0[sp148->unk18].unk2,
                                  (D_8036BB20 * D_802F47B0[sp148->unk18].unk3) *
                                      func_8026F644((UnkStruct_8026F644 *) sp14C, &sp148->unk0,
                                                    sp148->unk4 - sp134 + D_8036BB30) / 65025,
                                  D_802F47B0[sp148->unk18].unk4, D_802F47B0[sp148->unk18].unk5,
                                  D_802F47B0[sp148->unk18].unk6,
                                  (D_8036BB20 * D_802F47B0[sp148->unk18].unk7) *
                                      func_8026F644((UnkStruct_8026F644 *) sp14C, &sp148->unk0,
                                                    sp148->unk4 - sp134 + D_8036BB30 + sp148->unk8) / 65025);
                }
            }
        }
        func_80259BD4(&sp13C, arg1);
    }
    return sp13C;
}

void func_8026EF70(UnkStruct_802F8BDC *arg0) {
    if (arg0->unk8 & 0x80) {
        D_8036BB04 = func_8026F8A8(arg0->unkE, arg0->unk10, arg0->unkE - 1, 0x100);
        D_8036BB06 = 0;
        if (D_8036BB04 + 1 == arg0->unkE) {
            D_8036BB1E = 0;
        } else {
            D_8036BB1E = 1;
        }
    } else {
        D_8036BB1E = 0;
    }
}

void *func_8026F004(UnkStruct_802F8BDC *arg0, u16 arg1, u8 arg2) {
    UnkStruct_8036BB10 *sp3C;
    u8 sp3B;
    u8 *sp34;
    u16 *sp30;
    u16 sp2E;
    s32 sp28;
    u16 sp26;

    sp3C = &D_8036BB10[arg1];
    if (arg2) {
        sp3B = 1;
    } else {
        sp3B = 0;
    }
    sp34 = (u8 *)sp3C->unkC;
    sp30 = sp3C->unk10;
    D_8036BB48[0] = D_802E8C98[sp3B];
    switch (D_8036BB1E) {
        case 0:
            if (arg2) {
                return sp30;
            }
            return sp34;
        case 1:
            if (D_8036BB1C == 2) {
                D_8036BB1E = 2;
                D_8036BB00 = D_803156C4;
            }
            break;
        case 2:
            if (arg1 < D_8036BB04) {
                if (arg2) {
                    return sp30;
                }
                return sp34;
            }
            if (arg1 <= D_8036BB04) {
                if (D_803156C4 - D_8036BB00 >= 5) {
                    D_8036BB00 = D_803156C4;
                    D_8036BB06++;
                    if (arg2) {
                        sp2E = sp30[D_8036BB06];
                    } else {
                        sp2E = sp34[D_8036BB06];
                    }
                    if (sp2E == D_802E8C90[sp3B]) {
                        func_80260650(D_80367738, 0x91, 0);
                    } else if (sp2E != D_802E8C94[sp3B] && sp2E != D_802E8C98[sp3B] && sp2E != D_802E8C8C[sp3B]) {
                        func_80260650(D_80367738, 0x22, 0);
                    }
                }
                if (arg2) {
                    if (sp30 == NULL) {
                        func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "jtext", "./vidiPrint.h", 0x46);
                    }
                } else {
                    if (sp34 == NULL) {
                        func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "text", "./vidiPrint.h", 0x46);
                    }
                }
                sp28 = 0;
                if (arg2) {
                    while (sp30[sp28] != D_802E8C98[sp3B]) {
                        D_8036BB48[sp28] = sp30[sp28++];
                    }
                } else {
                    while (sp34[sp28] != D_802E8C98[sp3B]) {
                        D_8036BB48[sp28++] = sp34[sp28];
                    }
                }
                D_8036BB48[sp28] = D_802E8C98[sp3B];
                if (D_8036BB48[D_8036BB06] == D_802E8C98[sp3B]) {
                    sp26 = func_8026F8A8(arg0->unkE, arg0->unk10, D_8036BB04, 0x100);
                    if (sp26 == D_8036BB04) {
                        D_8036BB1E = 0;
                        if ((arg0->unk8 & 0x400000) && D_8036BB1C == 2) {
                            D_8036BAFC = D_803156C4;
                        }
                    } else {
                        func_80260650(D_80367738, 0x23, 0);
                        D_8036BB04 = sp26;
                    }
                    D_8036BB06 = 0;
                } else {
                    D_8036BB48[D_8036BB06] = D_802E8C98[sp3B];
                    if (!(sp3C->unk0 & 0x4000) && D_803156C4 % 10 >= 6) {
                        D_8036BB48[D_8036BB06] = D_802E8C9C[sp3B];
                        D_8036BB48[D_8036BB06 + 1] = D_802E8C98[sp3B];
                    }
                }
                if (arg2) {
                    return D_8036BB48;
                }
                return func_8025B558(D_8036BB48);
            }
            break;
    }
    if ((sp3C->unk0 & 0x100) || (sp3C->unk0 & 0x200)) {
        if (arg2) {
            return D_8036BB48;
        }
        return func_8025B558(D_8036BB48);
    }
    if (arg2) {
        return sp30;
    }
    return sp34;
}

#define ABS(x) ((x) > 0 ? (x) : -(x))
#define F644_VOL0(a, b) (0x200 - (ABS(b) << 9) / ((a)->unk2 / 3))
#define F644_VOL(a, b) (F644_VOL0(a, b) >= 0x100 ? 0xFF : F644_VOL0(a, b))

u8 func_8026F644(UnkStruct_8026F644 *arg0, u16 *arg1, s16 arg2) {
    if (*arg1 & 0x1000) {
        return F644_VOL(arg0, arg2) < 0 ? 0 : F644_VOL(arg0, arg2);
    }
    return 0xFF;
}

u16 func_8026F82C(u16 arg0, u16 arg1, u16 arg2) {
    s32 i;

    for (i = arg1 - 1; i >= arg0; i--) {
        if (D_8036BB10[i].unk0 & arg2) {
            return i;
        }
    }
    return arg1;
}

u16 func_8026F8A8(u16 arg0, u16 arg1, u16 arg2, u16 arg3) {
    s32 i;

    for (i = arg2 + 1; i < arg0 + arg1; i++) {
        if (D_8036BB10[i].unk0 & arg3) {
            return i;
        }
    }
    return arg2;
}

s32 func_8026F92C(u64 arg0) {
    s64 i;

    if (arg0 == 0) {
        func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "in", "yoshi.c", 0x8DE);
    }
    if (arg0 == 0) {
        return -1;
    }
    for (i = 0; !(((u64) 1 << i) & arg0); i++) {
    }
    return i;
}

u8 func_8026FA38(char **arg0, u16 **arg1) {
    s32 i;
    s32 sp18;

    sp18 = 0;
    func_8029A7E4("path builing=%d\n", D_803F7684);
    for (i = 0; i < 7 && sp18 == 0; i++) {
        if (D_802F9934[i].unk0 == D_803F7684) {
            sp18 = i + 0x1A;
        }
    }
    if (sp18 == 0) {
        sp18 = 0x1A;
        i = 1;
    }
    if (arg0 != NULL) {
        *arg0 = D_802F9934[i - 1].unk1;
    }
    if (arg1 != NULL) {
        *arg1 = D_802F9934[i - 1].unk10;
    }
    return sp18;
}

void func_8026FB50(UnkStruct_802F8BDC *arg0) {
    if (arg0->unk8 & 0x8000) {
        D_8036BB10 = D_8036BB24;
    } else if (arg0->unk8 & 0x800) {
        D_8036BB10 = D_8020C070;
    } else {
        D_8036BB10 = D_802F5804;
    }
}

void func_8026FBB0(UnkStruct_8026FBB0 *arg0, UnkStruct_8026FBB0 *arg1) {
    s32 pad;

    D_8036EB90 = 0;
    D_8036EA7C = 0;
    if (D_80364A90 != 0x40) {
        D_8036BED4 = D_8036BBB0[0] = 0;
    }
    D_8036BED8 = (UnkStruct_8036BED8 *) D_80358070;
    D_8036BEE0 = 0;
    D_8036BEDC = 999999.0f;
    while (arg0 != arg1) {
        D_8036BED8[D_8036EB90].unk0 = arg0->unk0;
        D_8036BED8[D_8036EB90].unk2 = arg0->unk2;
        D_8036BED8[D_8036EB90].unk4 = arg0->unk4;
        D_8036BED8[D_8036EB90].unk6 = 0;
        D_8036BED8[D_8036EB90].unk7 = (arg0->unk4 / (D_803BE710 >> 5)) * D_803BE714 + arg0->unk0 / (D_803BE70C >> 5);
        func_8026A5CC((u64 *) D_8036BED8[D_8036EB90].unk8[0], (u64 *) D_802F99C0, 0x40);
        func_8026A5CC((u64 *) D_8036BED8[D_8036EB90].unk8[1], (u64 *) D_802F99C0, 0x40);
        D_8036EB90++;
        arg0++;
    }
    D_80358070 += D_8036EB90 * sizeof(UnkStruct_8036BED8);
}

u8 func_8026FE6C(s32 arg0) {
    return D_8036BED8[arg0].unk6;
}

void func_8026FE8C(s32 arg0) {
    D_8036BED8[arg0].unk6 = 1;
    D_8036EA7C++;
}

void func_8026FEC4(void) {
    s32 i;
    s32 pad;
    s32 sp2C;
    u8 sp2B;
    u8 sp2A;

    sp2A = 0;
    sp2B = (D_803643E8 / D_803BE710) * D_803BE714 + D_803643E0 / D_803BE70C;
    for (i = 0; i < D_8036EB90; i++) {
        if (D_8036BED8[i].unk7 == sp2B && D_8036BED8[i].unk6 == 0) {
            sp2C = func_8026A6F0(D_803643E0 >> 5, D_803643E4 >> 5, D_803643E8 >> 5, D_8036BED8[i].unk0,
                                 D_8036BED8[i].unk2, D_8036BED8[i].unk4);
            if (sp2C < D_802FA200[D_80364456]) {
                if (++D_8036EA7C >= 4 && D_802E8BD0 == 0) {
                    func_8026AD30(0x46);
                }
                if (D_80364A90 != 0x40) {
                    D_8036BBB0[D_8036BED4] = D_8036BBB0[D_8036BED4 + 1] = i;
                    D_8036BED4++;
                }
                func_802AC544(D_8036BED8[i].unk0, D_8036BED8[i].unk2 + 5, D_8036BED8[i].unk4);
                D_8036BED8[i].unk6 = 1;
                if (sp2A == 0) {
                    sp2A = 1;
                    if (D_80364AA8 == 0x40) {
                        func_80260650(D_80367738, 0x3B, 0);
                    } else {
                        func_80260650(D_80367738, 0x27, 0);
                    }
                }
            }
        }
    }
}

void func_802701A8(Gfx **arg0, s32 arg1) {
    Gfx *gfx;
    s32 i;
    s32 j;
    f32 mf[4][4];
    f32 x[4];
    f32 y[4];
    f32 z[4];

    gfx = *arg0;
    gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
    gSPSetGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetRenderMode(gfx++, G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2);
    gDPSetCombineMode(gfx++, G_CC_MODULATERGBA, G_CC_MODULATERGBA);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    if (D_80364414 != D_8036BEDC) {
        D_8036BEE0 ^= 1;
        guRotateF(mf, D_80364414 - 135.0, 0.0f, 1.0f, 0.0f);
        for (i = 0; i < 4; i++) {
            guMtxXFMF(mf, D_802F99C0[i].v.ob[0], D_802F99C0[i].v.ob[1], D_802F99C0[i].v.ob[2], &x[i], &y[i], &z[i]);
        }
        for (i = 0; i < D_8036EB90; i++) {
            for (j = 0; j < 4; j++) {
                D_8036BED8[i].unk8[D_8036BEE0][j].v.ob[0] = (s16) x[j] + D_8036BED8[i].unk0;
                D_8036BED8[i].unk8[D_8036BEE0][j].v.ob[1] = (s16) y[j] + D_8036BED8[i].unk2;
                D_8036BED8[i].unk8[D_8036BEE0][j].v.ob[2] = (s16) z[j] + D_8036BED8[i].unk4;
            }
        }
    }
    gDPLoadTextureBlock(gfx++, osVirtualToPhysical(D_802F9A00), G_IM_FMT_RGBA, G_IM_SIZ_32b, 16, 16, 0, G_TX_CLAMP,
                        G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    for (i = 0; i < D_8036EB90; i++) {
        if (D_8036BED8[i].unk6 == 0 && func_80270A54(&D_8036BED8[i])) {
            gSPVertex(gfx++, D_8036BED8[i].unk8[D_8036BEE0], 4, 0);
            gSP1Triangle(gfx++, 0, 1, 2, 0);
            gSP1Triangle(gfx++, 0, 2, 3, 0);
        }
    }
    gDPPipeSync(gfx++);
    gDPLoadTextureBlock(gfx++, osVirtualToPhysical(D_802F9E00), G_IM_FMT_RGBA, G_IM_SIZ_32b, 16, 16, 0, G_TX_CLAMP,
                        G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    for (i = 0; i < D_8036EB90; i++) {
        if (D_8036BED8[i].unk6 != 0 && func_80270A54(&D_8036BED8[i])) {
            gSPVertex(gfx++, D_8036BED8[i].unk8[D_8036BEE0], 4, 0);
            gSP1Triangle(gfx++, 0, 1, 2, 0);
            gSP1Triangle(gfx++, 0, 2, 3, 0);
        }
    }
    gDPPipeSync(gfx++);
    *arg0 = gfx;
    D_8036BEDC = D_80364414;
}

s32 func_80270A54(UnkStruct_8036BED8 *arg0) {
    s32 i;
    u8 spB;

    i = 0;
    spB = arg0->unk7;
    while (D_803C30A8[i] != 0xFFFF) {
        if (D_803C30A8[i++] == spB) {
            return 1;
        }
    }
    return 0;
}

void func_80270AE0(u8 *arg0) {
    s32 argc;
    u8 *argv[33];
    u8 **av;
    s32 pad;
    u8 *p;

    argc = 1;
    av = argv;
    if (arg0 != NULL && *arg0 != 0) {
        p = arg0;
        while (*p != 0) {
            while (*p != 0 && *p == ' ') {
                *p = 0;
                p++;
            }
            if (*p != 0) {
                argv[argc] = p;
                argc++;
            }
            while (*p != 0 && *p != ' ') {
                p++;
            }
        }
        while (argc >= 2 && av[1][0] == '-') {
            switch (av[1][1]) {
                case 'd':
                    D_802FA254 = 1;
                    break;
                case 'v':
                    D_802FA250 = 1;
                    break;
                case 's':
                    D_802FA258 = 1;
                    break;
                case 'j':
                    D_802FA25C = 1;
                    break;
                case 'm':
                    D_802FA260 = 1;
                    break;
                case 'l':
                    D_802FA264 = 1;
                    break;
                case 'c':
                    D_802FA268 = 1;
                    break;
                case 'C':
                    D_802FA26C = 1;
                    D_802FA268 = 1;
                    break;
            }
            argc--;
            av++;
        }
    }
}
