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
    /* 0x0C */ u8 *unkC;
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
    /* 0x10 */ s32 unk10;
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
extern Vtx D_802F9A00[];
extern Vtx D_802F9E00[];
extern u16 D_802E8C8C[];
extern u16 D_802E8C90[];
extern u16 D_802E8C94[];
extern u16 D_802E8C98[];
extern u16 D_802E8C9C[];
extern u32 D_803156C4;
extern u32 D_8036BAFC;
extern u32 D_8036BB00;
extern u16 D_8036BB48[];
extern u16 D_803C30A8[];
extern UnkStruct_8036BB10 D_8020C070[];
extern u8 D_802F4868[];
extern u8 D_802F4870[];
extern UnkStruct_802F49F4 D_802F49F4[];
extern UnkStruct_8036BB10 D_802F5804[];
extern UnkStruct_802F8BDC D_802F8BDC[];
extern u64 D_80364A98;
extern u32 D_80364AA8;
extern u8 D_8036BA98[];
extern UnkStruct_8036BB10 *D_8036BB10;
extern UnkStruct_8036BB10 *D_8036BB24;
extern u16 D_8036BB04;
extern u16 D_8036BB06;
extern s16 D_8036BB1E;
extern UnkStruct_802F9934 D_802F9934[];
extern s32 D_803F7684;
extern u8 D_802E8BD0;
extern s32 D_802FA200[];
extern s32 D_803643E0;
extern s32 D_803643E4;
extern s32 D_803643E8;
extern u8 D_80364456;
extern s32 D_80367738;
extern Vtx D_802F99C0[4];
extern u8 *D_80358070;
extern u16 D_8036BBB0[];
extern s32 D_8036BED4;
extern UnkStruct_8036BED8 *D_8036BED8;
extern f32 D_8036BEDC;
extern u8 D_8036BEE0;
extern u16 D_8036EA7C;
extern u16 D_8036EB90;
extern s32 D_803BE70C;
extern s32 D_803BE710;
extern s16 D_803BE714;
extern s16 D_8036BB18;
extern s16 D_8036BB1C;
extern UnkStruct_802F48D0 D_802F48D0[];
extern u8 D_802F499A[];
extern u64 D_80364A90;
extern u8 D_80364AE8;
extern UnkStruct_80364AF0 D_80364AF0[];
extern u8 D_8036BAA2[];
extern u16 D_8036BB14;
extern s16 D_8036BB1A;

void func_8026AF6C(u16 arg0);
void func_8029A7E4(char *, ...);
s32 func_80270A54(UnkStruct_8036BED8 *arg0);
char *func_8025B558(u16 *);
void func_8026BA7C(UnkStruct_802F8BDC *arg0);
s32 func_8026F92C(u64);
u8 func_8026FA38(char **, s32 *);
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
const char D_803099D0[] = "SELECT OPTION";
const char D_803099E0[] = "MORE";
const char D_803099E8[] = "VIEW STATS";
const char D_803099F4[] = "RESTART";
const char D_803099FC[] = "QUIT LEVEL";
const char D_80309A08[] = "SELECT OPTION";
const char D_80309A18[] = "CONTINUE";
const char D_80309A24[] = "CONTROL MODE";
const char D_80309A34[] = "MISSION BRIEFING";
const char D_80309A48[] = "MUSIC VOLUME";
const char D_80309A58[] = "COLLISION IMMINENT!";
const char D_80309A6C[] = "WARNING!";
const char D_80309A78[] = "REACTOR MELTDOWN!";
const char D_80309A8C[] = "ABORTING MISSION";
const char D_80309AA0[] = "CONGRATULATIONS!";
const char D_80309AB4[] = "MISSION COMPLETE";
const char D_80309AC8[] = "PRESS START";
const char D_80309AD4[] = "";
const char D_80309AD8[] = "******MISSION";
const char D_80309AE8[] = "FAILED!*****";
const char D_80309AF8[] = "SET MUSIC VOLUME";
const char D_80309B0C[] = "QUIET";
const char D_80309B14[] = "LOUD";
const char D_80309B1C[] = "**MISSION FAILED!**";
const char D_80309B30[] = "CONGRATULATIONS!!";
const char D_80309B44[] = "MIRACULOUSLY, THE SHUTTLE";
const char D_80309B60[] = "COMPLETES ITS RETURN";
const char D_80309B78[] = "TO EARTH WITHOUT A";
const char D_80309B8C[] = "SINGLE CASUALTY.";
const char D_80309BA0[] = "BLAST CORPS HAS COME";
const char D_80309BB8[] = "THROUGH WITH FLYING";
const char D_80309BCC[] = "COLORS YET AGAIN.";
const char D_80309BE0[] = "THEIR POPULARITY GIVEN";
const char D_80309BF8[] = "A FURTHER BOOST, THE";
const char D_80309C10[] = "TEAM FIND NEW OFFERS";
const char D_80309C28[] = "OF WORK POURING IN -";
const char D_80309C40[] = "BUT DECIDE THAT MAYBE,";
const char D_80309C58[] = "FOR NOW, IT'S TIME";
const char D_80309C6C[] = "FOR A HOLIDAY.";
const char D_80309C7C[] = "BATTERED AND CRIPPLED AFTER";
const char D_80309C98[] = "ITS LONG VOYAGE, THE LATEST";
const char D_80309CB4[] = "SPACE SHUTTLE IS THROWN OFF";
const char D_80309CD0[] = "COURSE DURING RE-ENTRY AND";
const char D_80309CEC[] = "FORCED INTO DESPERATE";
const char D_80309D04[] = "MEASURES.";
const char D_80309D10[] = "A MAJOR CITY IS SEIZED BY";
const char D_80309D2C[] = "PANIC WHEN THE RESIDENTS";
const char D_80309D48[] = "FIND OUT THAT THEIR HOMES";
const char D_80309D64[] = "ARE ABOUT TO BECOME AN";
const char D_80309D7C[] = "EMERGENCY LANDING STRIP ...";
const char D_80309D98[] = "TIME IS OF THE ESSENCE AS";
const char D_80309DB4[] = "BLAST CORPS RISES ONCE";
const char D_80309DCC[] = "MORE TO THE CHALLENGE.";
const char D_80309DE4[] = "EVEN AS THE SHUTTLE";
const char D_80309DF8[] = "BLAZES DOWN THROUGH";
const char D_80309E0C[] = "THE SKIES, A RUNWAY";
const char D_80309E20[] = "MUST BE CLEARED.";
const char D_80309E34[] = "SITUATION:";
const char D_80309E40[] = "********CARRIER LOCKED ON COURSE********";
const char D_80309E6C[] = "SOLUTION:";
const char D_80309E78[] = "********CLEAR PATH TO GROUND ZERO!************";
const char D_80309EA8[] = "AGENTS:";
const char D_80309EB0[] = "********BLAST CORPS********";
const char D_80309ECC[] = "CHANCES:";
const char D_80309ED8[] = "********SLIM*!******************";
const char D_80309EFC[] = "******MISSION 1:**";
const char D_80309F10[] = "CLEAR PATH FOR CARRIER";
const char D_80309F28[] = "ON EACH MAIN LEVEL.";
const char D_80309F3C[] = "******MISSION 2:**";
const char D_80309F50[] = "ACTIVATE ALL RDUS AND";
const char D_80309F68[] = "DESTROY ALL BUILDINGS";
const char D_80309F80[] = "TO EARN SECOND GOLD.";
const char D_80309F98[] = "******MISSION 3:**";
const char D_80309FAC[] = "AFTER COMPLETING MAIN LEVELS,";
const char D_80309FCC[] = "FIND ALL 6 SCIENTISTS TO";
const char D_80309FE8[] = "ENSURE A CONTROLLED DETONATION.";
const char D_8030A008[] = "******MISSION 4:**";
const char D_8030A01C[] = "ACHIEVE GOLD ON ALL LEVELS";
const char D_8030A038[] = "TO COMMENCE TIME ATTACK.";
const char D_8030A054[] = "BLAST CORPS : LEADERS IN";
const char D_8030A070[] = "THE FIELD OF HEAVY DUTY";
const char D_8030A088[] = "DEMOLITION THROUGH A";
const char D_8030A0A0[] = "COMBINATION OF SKILL,";
const char D_8030A0B8[] = "EXPERIENCE AND CUTTING-";
const char D_8030A0D0[] = "EDGE TECHNOLOGY.";
const char D_8030A0E4[] = "SINCE ITS BIRTH THE COMPANY";
const char D_8030A100[] = "HAS APPLIED ITS UNIQUE TALENTS";
const char D_8030A120[] = "TO THE PROBLEM OF URBAN DECAY,";
const char D_8030A140[] = "RENOVATING AND REVITALIZING";
const char D_8030A15C[] = "CITIES FROM ONE END OF THE";
const char D_8030A178[] = "COUNTRY TO THE OTHER.";
const char D_8030A190[] = "A FAR CRY FROM THE SENSELESS";
const char D_8030A1B0[] = "WARFARE AMIDST WHICH THE";
const char D_8030A1CC[] = "SEEDS OF THE PROJECT WERE";
const char D_8030A1E8[] = "SOWN, IN THE HEAVY VEHICLE";
const char D_8030A204[] = "DEVELOPMENT BAY AT THE";
const char D_8030A21C[] = "MILITARY BASE CALLED RAFTERS.";
const char D_8030A23C[] = "WHILE DEMONSTRATING A GREAT";
const char D_8030A258[] = "NATURAL FLAIR, THE FOUNDING";
const char D_8030A274[] = "MEMBERS OF THE TEAM - AMBER,";
const char D_8030A294[] = "CLARK, WESLEY AND SPIKE - WERE";
const char D_8030A2B4[] = "NEVER HAPPY WITH THE ULTIMATE";
const char D_8030A2D4[] = "PURPOSE OF THEIR MACHINES ...";
const char D_8030A2F4[] = "SO WHEN WESLEY WAS CRUELLY";
const char D_8030A310[] = "REJECTED FOLLOWING THE FIELD";
const char D_8030A330[] = "ACCIDENT THAT LEFT HIM";
const char D_8030A348[] = "DISABLED, HIS FRIENDS FINALLY";
const char D_8030A368[] = "REBELLED AND LED THE";
const char D_8030A380[] = "INFAMOUS RAFTERS WALKOUT.";
const char D_8030A39C[] = "BLAST CORPS CAME INTO BEING";
const char D_8030A3B8[] = "SOON AFTER. THAT WAS FIVE";
const char D_8030A3D4[] = "YEARS AGO. BUT NOW, IN";
const char D_8030A3EC[] = "THE PRESENT DAY, WORLD PEACE";
const char D_8030A40C[] = "IS SHATTERED AS MANKIND FACES";
const char D_8030A42C[] = "CRISIS ON A WORLDWIDE SCALE.";
const char D_8030A44C[] = "A PAIR OF DEFECTIVE NUCLEAR";
const char D_8030A468[] = "MISSILES, EN ROUTE TO A SAFE";
const char D_8030A488[] = "DETONATION SITE, HAVE BEGUN";
const char D_8030A4A4[] = "TO LEAK. BADLY DAMAGED, THE";
const char D_8030A4C0[] = "CARRIER AUTOMATICALLY LOCKS";
const char D_8030A4DC[] = "ONTO THE MOST DIRECT ROUTE.";
const char D_8030A4F8[] = "BAD MEMORIES RESURFACE FOR";
const char D_8030A514[] = "THE BLAST CORPS TEAM WHEN,";
const char D_8030A530[] = "SUMMONED TO THEIR NATION'S";
const char D_8030A54C[] = "DEFENSE, THEY FIND OUT WHERE";
const char D_8030A56C[] = "THE WARHEADS ORIGINATED. A";
const char D_8030A588[] = "CERTAIN NEARBY MILITARY BASE.";
const char D_8030A5A8[] = "THE FLOOD OF RADIATION PREVENTS";
const char D_8030A5C8[] = "ANYONE GETTING CLOSE TO THE";
const char D_8030A5E4[] = "RUNAWAY CARRIER, AND PEOPLE IN";
const char D_8030A604[] = "THE KNOW FEAR THAT EVEN THE";
const char D_8030A620[] = "SLIGHTEST JOLT COULD TRIGGER";
const char D_8030A640[] = "A CATASTROPHIC EXPLOSION.";
const char D_8030A65C[] = "STANDING AS THE WORLD'S FINAL";
const char D_8030A67C[] = "HOPE, BLAST CORPS MUST CLEAR";
const char D_8030A69C[] = "THE WAY TO GROUND ZERO, GATHER";
const char D_8030A6BC[] = "A TEAM OF SIX ELITE SCIENTISTS";
const char D_8030A6DC[] = "AND ULTIMATELY COUNTER THE";
const char D_8030A6F8[] = "THREAT OF NUCLEAR WINTER.";
const char D_8030A714[] = "EVEN AS THE CARRIER";
const char D_8030A728[] = "TRUNDLES TOWARDS GROUND";
const char D_8030A740[] = "ZERO, YOU ARE DOING";
const char D_8030A754[] = "EVERYTHING IN YOUR POWER";
const char D_8030A770[] = "TO GET THE ASSEMBLED";
const char D_8030A788[] = "SCIENTISTS THERE FIRST ...";
const char D_8030A7A4[] = "MERCIFULLY, THE SCIENTISTS";
const char D_8030A7C0[] = "ARE ABLE TO SET UP A";
const char D_8030A7D8[] = "PROPERLY CONTROLLED";
const char D_8030A7EC[] = "DETONATION ... AND FINALLY,";
const char D_8030A808[] = "AS THE SMOKE FADES, THE WORLD";
const char D_8030A828[] = "CAN LET OUT A SIGH OF RELIEF.";
const char D_8030A848[] = "THE DEVASTATION LEFT IN";
const char D_8030A860[] = "YOUR WAKE IS NOTHING COMPARED";
const char D_8030A880[] = "TO WHAT WOULD HAVE HAPPENED";
const char D_8030A89C[] = "IF BLAST CORPS HAD FAILED";
const char D_8030A8B8[] = "AT THE LAST.";
const char D_8030A8C8[] = "REBUILDING BEGINS IMMEDIATELY.";
const char D_8030A8E8[] = "WITH CATASTROPHE AVERTED, THE";
const char D_8030A908[] = "TEAM MEMBERS BECOME NATIONAL";
const char D_8030A928[] = "HEROES, THEIR SUCCESS AND";
const char D_8030A944[] = "SATISFACTION ASSURED FOR";
const char D_8030A960[] = "THE FORESEEABLE FUTURE.";
const char D_8030A978[] = "**RDUS COLLECTED!**********";
const char D_8030A994[] = "**SURVIVORS FREE!**********";
const char D_8030A9B0[] = "**BUILDINGS DESTROYED!**********";
const char D_8030A9D4[] = "**LEVEL COMPLETE!**********";
const char D_8030A9F0[] = "**PATH CLEARED!**********";
const char D_8030AA0C[] = "********EMERGENCY! ...****************";
const char D_8030AA34[] = "YOU MUST COMPLETELY";
const char D_8030AA48[] = "REMOVE ALL OBSTACLES";
const char D_8030AA60[] = "FROM THE DANGER ZONE!";
const char D_8030AA78[] = "DANGER ZONE!";
const char D_8030AA88[] = "THIS IS AN RDU,";
const char D_8030AA98[] = "TRIGGERED REMOTELY";
const char D_8030AAAC[] = "AS YOU DRIVE BY.";
const char D_8030AAC0[] = "THEY CAN BE USED FOR";
const char D_8030AAD8[] = "GUIDANCE AS WELL AS";
const char D_8030AAEC[] = "RADIATION DISPERSAL.";
const char D_8030AB04[] = "COMMUNICATION POINTS";
const char D_8030AB1C[] = "ALLOW YOU TO MAKE";
const char D_8030AB30[] = "CONTACT WITH HQ.";
const char D_8030AB44[] = "WHEN ACTIVATED, THEY";
const char D_8030AB5C[] = "BREAK OPEN VALUABLE";
const char D_8030AB70[] = "NEW TRAINING LEVELS.";
const char D_8030AB88[] = "YOU CAN";
const char D_8030AB90[] = "ACCESS THESE FROM";
const char D_8030ABA4[] = "THE WORLD SCREEN.";
const char D_8030ABB8[] = "BACKLASH";
const char D_8030ABC4[] = "DESTROY BUILDINGS";
const char D_8030ABD8[] = "WITH BACKLASH USING";
const char D_8030ABEC[] = "ITS ARMORED REAR.";
const char D_8030AC00[] = "USE R TO SKID";
const char D_8030AC10[] = "THE TRUCK WHEN";
const char D_8030AC20[] = "GOING INTO A TURN.";
const char D_8030AC34[] = "AIM FOR AT LEAST";
const char D_8030AC48[] = "A SILVER MEDAL";
const char D_8030AC58[] = "BEFORE PROGRESSING:";
const char D_8030AC6C[] = "THIS TECHNIQUE";
const char D_8030AC7C[] = "MUST BE MASTERED";
const char D_8030AC90[] = "FOR LATER LEVELS.";
const char D_8030ACA4[] = "USE BUMPS TO GET";
const char D_8030ACB8[] = "BACKLASH AIRBORNE AND";
const char D_8030ACD0[] = "CAUSE MAXIMUM DAMAGE.";
const char D_8030ACE8[] = "SIDESWIPE";
const char D_8030ACF4[] = "HITS HARDEST AT THE";
const char D_8030AD08[] = "MAXIMUM EXTENSION";
const char D_8030AD1C[] = "OF ITS SIDE PANELS.";
const char D_8030AD30[] = "FIND BLUE AMMO BOXES";
const char D_8030AD48[] = "TO KEEP SIDESWIPE'S";
const char D_8030AD5C[] = "ATTACK POWER AT FULL.";
const char D_8030AD74[] = "CHARGES REMAINING";
const char D_8030AD88[] = "ARE DISPLAYED IN THE";
const char D_8030ADA0[] = "LOWER LEFT CORNER.";
const char D_8030ADB4[] = "THUNDERFIST";
const char D_8030ADC0[] = "DEMOLISH BUILDINGS";
const char D_8030ADD4[] = "BY DIVING AND";
const char D_8030ADE4[] = "ROLLING INTO THEM.";
const char D_8030ADF8[] = "A WELL-TIMED SERIES";
const char D_8030AE0C[] = "OF ATTACKS CAN CAUSE";
const char D_8030AE24[] = "INCREDIBLE DAMAGE.";
const char D_8030AE38[] = "SKYFALL";
const char D_8030AE40[] = "MAKE USE OF SKYFALL'S";
const char D_8030AE58[] = "ARMORED UNDERSIDE";
const char D_8030AE6C[] = "TO CRUSH FROM ABOVE.";
const char D_8030AE84[] = "TURBO INTO A DITCH";
const char D_8030AE98[] = "WITH L/R TO LAUNCH";
const char D_8030AEAC[] = "YOURSELF SKYWARDS ...";
const char D_8030AEC4[] = "J-BOMB";
const char D_8030AECC[] = "USE A TO THRUST";
const char D_8030AEDC[] = "J-BOMB INTO THE";
const char D_8030AEEC[] = "AIR OVER A TARGET ...";
const char D_8030AF04[] = "THEN HIT B TO";
const char D_8030AF14[] = "DIVE EARTHWARDS";
const char D_8030AF24[] = "FROM A HEIGHT.";
const char D_8030AF34[] = "SURVIVORS ESCAPE WHEN";
const char D_8030AF4C[] = "THE WALLS AROUND";
const char D_8030AF60[] = "THEM ARE DESTROYED.";
const char D_8030AF74[] = "CUE THE BLAST CORPS";
const char D_8030AF88[] = "CHOPPER, SWOOPING IN";
const char D_8030AFA0[] = "TO PICK THEM UP.";
const char D_8030AFB4[] = "ONE GOLD COMMENDATION";
const char D_8030AFCC[] = "IS GIVEN PER LEVEL";
const char D_8030AFE0[] = "FOR PATH CLEARANCE:";
const char D_8030AFF4[] = "THE SECOND REQUIRES";
const char D_8030B008[] = "ALL SURVIVORS, RDUS";
const char D_8030B01C[] = "AND TOTAL DESTRUCTION.";
const char D_8030B034[] = "WARNING!";
const char D_8030B040[] = "SOMETHING IN THE";
const char D_8030B054[] = "CARRIER'S PATH";
const char D_8030B064[] = "HAS BEEN MISSED!";
const char D_8030B078[] = "KEEP AN EYE";
const char D_8030B084[] = "ON THE LOWER";
const char D_8030B094[] = "LEFT ARROW ...";
const char D_8030B0A4[] = "IT CHANGES FROM GREEN";
const char D_8030B0BC[] = "TO RED AS YOU CLOSE";
const char D_8030B0D0[] = "IN ON THE CARRIER.";
const char D_8030B0E4[] = "USE IT WITH THE RADAR";
const char D_8030B0FC[] = "TO QUICKLY TRACK";
const char D_8030B110[] = "DOWN THE PROBLEM:";
const char D_8030B124[] = "RED INDICATES THE";
const char D_8030B138[] = "CARRIER, BLUE THE NEXT";
const char D_8030B150[] = "BUILDING IN ITS PATH.";
const char D_8030B168[] = "CONGRATULATIONS!";
const char D_8030B17C[] = "THIS IS ONE OF";
const char D_8030B18C[] = "THE BONUS VEHICLES.";
const char D_8030B1A0[] = "THEY ARE";
const char D_8030B1AC[] = "MOST USEFUL IN";
const char D_8030B1BC[] = "TRAINING STAGES:";
const char D_8030B1D0[] = "ACCESS THESE";
const char D_8030B1E0[] = "VIA THE LEVEL'S";
const char D_8030B1F0[] = "COMMUNICATION POINTS.";
const char D_8030B208[] = "PATH CLEARED!";
const char D_8030B218[] = "YOUR PRIMARY MISSION";
const char D_8030B230[] = "HERE IS COMPLETE.";
const char D_8030B244[] = "THE BLAST CORPS";
const char D_8030B254[] = "SEMI ALLOWS YOU";
const char D_8030B264[] = "TO EXIT THE LEVEL.";
const char D_8030B278[] = "MOVE BETWEEN";
const char D_8030B288[] = "VEHICLES WITH";
const char D_8030B298[] = "THE Z BUTTON.";
const char D_8030B2A8[] = "SPARE TIME CAN BE";
const char D_8030B2BC[] = "USED TO FIND RDUS AND";
const char D_8030B2D4[] = "DESTROY BUILDINGS ...";
const char D_8030B2EC[] = "RETURN IF NECESSARY";
const char D_8030B300[] = "AFTER CHECKING";
const char D_8030B310[] = "YOUR PERFORMANCE.";
const char D_8030B324[] = "USE Z TO GET OUT";
const char D_8030B338[] = "OF ONE VEHICLE";
const char D_8030B348[] = "AND COMMANDEER ANOTHER.";
const char D_8030B360[] = "THE DESTRUCTION OF";
const char D_8030B374[] = "THIS BUILDING";
const char D_8030B384[] = "IS ESSENTIAL!";
const char D_8030B394[] = "FLASHING ARROWS";
const char D_8030B3A4[] = "MEAN IT STANDS IN";
const char D_8030B3B8[] = "THE CARRIER'S PATH.";
const char D_8030B3CC[] = "AS DANGER CLOSES IN,";
const char D_8030B3E4[] = "THE ARROWS CHANGE";
const char D_8030B3F8[] = "FROM GREEN TO RED.";
const char D_8030B40C[] = "THIS IS A PERIPHERY";
const char D_8030B420[] = "STRUCTURE : CRUSHING";
const char D_8030B438[] = "IT IS NOT VITAL.";
const char D_8030B44C[] = "THEN AGAIN, IT'S FUN";
const char D_8030B464[] = "- AND MIGHT REVEAL";
const char D_8030B478[] = "A SURPRISE OR TWO ...";
const char D_8030B490[] = "LEVELING EVERYTHING";
const char D_8030B4A4[] = "HELPS YOU GAIN";
const char D_8030B4B4[] = "A COMMENDATION.";
const char D_8030B4C4[] = "HOWEVER, IT'S A";
const char D_8030B4D4[] = "SECONDARY OBJECTIVE";
const char D_8030B4E8[] = "TO CLEARING THE WAY.";
const char D_8030B500[] = "CONCENTRATE ON THE";
const char D_8030B514[] = "ARROWED BUILDINGS AS";
const char D_8030B52C[] = "THE CARRIER PASSES ...";
const char D_8030B544[] = "PLENTY OF TIME TO";
const char D_8030B558[] = "COME BACK LATER";
const char D_8030B568[] = "AND FINISH THE JOB.";
const char D_8030B57C[] = "USE Z TO GET OUT";
const char D_8030B590[] = "OF ONE VEHICLE";
const char D_8030B5A0[] = "AND COMMANDEER ANOTHER.";
const char D_8030B5B8[] = "BUT CLEAR A PATH FOR";
const char D_8030B5D0[] = "THE CARRIER BEFORE";
const char D_8030B5E4[] = "GOING OFF TO EXPLORE!";
const char D_8030B5FC[] = "THE CRANE CAN MOVE";
const char D_8030B610[] = "OBJECTS TO PREVIOUSLY";
const char D_8030B628[] = "INACCESSIBLE PLACES.";
const char D_8030B640[] = "LOAD IT UP THEN";
const char D_8030B650[] = "HEAD FOR THE";
const char D_8030B660[] = "CONTROLS IN THE CAB.";
const char D_8030B678[] = "COLLECT AMMO BOXES";
const char D_8030B68C[] = "AND YOU CAN BLAST";
const char D_8030B6A0[] = "YOUR WAY THROUGH.";
const char D_8030B6B4[] = "YOU COULD STOP";
const char D_8030B6C4[] = "THE TRAIN AT";
const char D_8030B6D4[] = "THIS STATION.";
const char D_8030B6E4[] = "WAIT FOR THE SMILEY";
const char D_8030B6F8[] = "BEFORE ATTEMPTING TO";
const char D_8030B710[] = "LOAD OR UNLOAD.";
const char D_8030B720[] = "TNT CRATES CAN BE";
const char D_8030B734[] = "PUSHED AROUND USING";
const char D_8030B748[] = "RAMDOZER'S SHOVEL.";
const char D_8030B75C[] = "BUT THEY WON'T BE";
const char D_8030B770[] = "STABLE FOR LONG ...";
const char D_8030B784[] = "SELECT START THEN";
const char D_8030B798[] = "VIEW STATS TO CHECK";
const char D_8030B7AC[] = "STATUS OF LEVEL.";
const char D_8030B7C0[] = "THE TRAIN CAN HELP";
const char D_8030B7D4[] = "TRANSPORT RAMDOZER";
const char D_8030B7E8[] = "TO THE STATION.";
const char D_8030B7F8[] = "PRESSING START WILL";
const char D_8030B80C[] = "ALLOW YOU TO VIEW THE";
const char D_8030B824[] = "MISSILE CARRIER'S PATH.";
const char D_8030B83C[] = "NO";
const char D_8030B840[] = "YES";
const char D_8030B844[] = "CONGRATULATIONS!!";
const char D_8030B858[] = "HAVING DEMONSTRATED";
const char D_8030B86C[] = "VERSATILITY AND RELIABILITY";
const char D_8030B888[] = "WELL BEYOND THE CALL OF";
const char D_8030B8A0[] = "DUTY, THE BLAST CORPS";
const char D_8030B8B8[] = "TEAM CAN FINALLY TAKE";
const char D_8030B8D0[] = "THAT WELL-DESERVED HOLIDAY.";
const char D_8030B8EC[] = "WHEN THEY GET BACK THEY'LL";
const char D_8030B908[] = "FIND THE OFFERS AND DEALS";
const char D_8030B924[] = "STILL FLOODING IN,";
const char D_8030B938[] = "KEEPING THEM IN THEIR";
const char D_8030B950[] = "CHOSEN LINE OF WORK";
const char D_8030B964[] = "FOR MANY YEARS TO COME ...";
const char D_8030B980[] = "MAYBE AT SOME POINT EVEN";
const char D_8030B99C[] = "LEADING THEM BACK INTO";
const char D_8030B9B4[] = "THE FIELD OF MILITARY";
const char D_8030B9CC[] = "OPERATIONS - BUT THIS";
const char D_8030B9E4[] = "TIME FOR A CONSIDERABLY";
const char D_8030B9FC[] = "NOBLER CAUSE.";
const char D_8030BA0C[] = "ALL THAT, THOUGH, CAN WAIT.";
const char D_8030BA28[] = "WITH THEIR COUNTRY";
const char D_8030BA3C[] = "BREATHING A SIGH OF";
const char D_8030BA50[] = "RELIEF AND THEIR GOOD";
const char D_8030BA68[] = "NAME ASSURED FOR LIFE,";
const char D_8030BA80[] = "THE TEAM CAN REST EASY";
const char D_8030BA98[] = "FOR A WHILE.";
const char D_8030BAA8[] = "UNLESS, OF COURSE, THE";
const char D_8030BAC0[] = "LURE OF THE GOLD STANDARD";
const char D_8030BADC[] = "PROVES TOO MUCH ...";
const char D_8030BAF0[] = "PERHAPS THERE ARE";
const char D_8030BB04[] = "FURTHER CHALLENGES AWAITING";
const char D_8030BB20[] = "THOSE WHO CAN ACHIEVE";
const char D_8030BB38[] = "A PERFECT RECORD ...";

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
extern u8 D_802F4878[];
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

extern UnkStruct_802F47B0 D_802F47B0[];
extern Gfx D_802F98B0[];
extern s32 D_802F9930;
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
s32 func_8025B498(s16, u16, u8 *, s32);
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
                            sp148->unk2 = func_8025B498(sp14C->unk0 / 2, sp148->unk6, sp148->unkC, (s32) sp148->unk10);
                        } else {
                            sp148->unk2 = func_8025B498(sp14C->unk0 / 2, sp148->unk6, sp148->unkC, (s32) sp148->unk10);
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
    sp34 = sp3C->unkC;
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

u8 func_8026FA38(char **arg0, s32 *arg1) {
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

extern s32 D_802FA250;
extern s32 D_802FA254;
extern s32 D_802FA258;
extern s32 D_802FA25C;
extern s32 D_802FA260;
extern s32 D_802FA264;
extern s32 D_802FA268;
extern s32 D_802FA26C;

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
