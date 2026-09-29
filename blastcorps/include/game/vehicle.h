#ifndef GAME_VEHICLE_H
#define GAME_VEHICLE_H

#include "game/types.h"

/*
 * Vehicle (and other level object) types: the first byte of a level file's
 * vehicle record, and the switch in the object loader (func_802A396C, docs/
 * blast_corps_vehicles.txt).  The names are the model files' (the docs list
 * each type's ROM range), with the game's name where it differs.
 * D_80364456 is the one the player is in.
 */
enum VehicleType {
    VEHICLE_DRIVER = 0x00,      /* on foot */
    VEHICLE_SIDESWIPE = 0x01,
    VEHICLE_MAGOO = 0x02,       /* Thunderfist */
    VEHICLE_BUGGY = 0x03,       /* Skyfall */
    VEHICLE_BULLDOZER = 0x04,   /* Ramdozer */
    VEHICLE_TRUCK = 0x05,       /* Backlash */
    VEHICLE_CRANE = 0x06,
    VEHICLE_TRAIN = 0x07,
    VEHICLE_HOTROD = 0x08,      /* American Dream */
    VEHICLE_JETPACK = 0x09,     /* J-Bomb */
    VEHICLE_BIKE = 0x0A,        /* Ballista */
    VEHICLE_BARGE = 0x0B,       /* also 0x11 and 0x12 */
    VEHICLE_POLICE = 0x0D,
    VEHICLE_ATEAM = 0x0E,       /* A-Team Van */
    VEHICLE_STARSKI = 0x0F,     /* the other hotrod */
    VEHICLE_MINIMAGOO = 0x10,   /* Cyclone Suit */
    VEHICLE_BARGE_2 = 0x11,
    VEHICLE_BARGE_3 = 0x12,
    VEHICLE_COMMPOINT = 0x96,   /* the communication point satellite */
    VEHICLE_SCIENTIST = 0x98,
    VEHICLE_SHUTTLE = 0xFD,
    VEHICLE_CHOPPER = 0xFE,     /* the BCT chopper */
    VEHICLE_CMO = 0xFF          /* the missile carrier */
};

/*
 * The level's vehicles: D_80364460[12] (hd.c's .bss), D_803649D0 one past
 * the last one in use.  The pointers are into the vehicle's loaded model.
 */
typedef struct Vehicle {
    /* 0x00 */ void *unk0;
    /* 0x04 */ void *unk4;
    /* 0x08 */ void *unk8;
    /* 0x0C */ void *unkC;
    /* 0x10 */ void *unk10;
    /* 0x14 */ void *unk14;
    /* 0x18 */ u8 pad18[0x18];
    /* 0x30 */ void *unk30;
    /* 0x34 */ void *unk34;
    /* 0x38 */ void *unk38;       /* a display list */
    /* 0x3C */ u8 pad3C[0x18];
    /* 0x54 */ Gfx *unk54;
    /* 0x58 */ void *unk58;
    /* 0x5C */ s32 type;          /* VehicleType; the one equal to D_80364456 is the player's */
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 x;             /* world position << 5, as D_803643E0..E8 */
    /* 0x68 */ s32 y;
    /* 0x6C */ s32 z;
    /* 0x70 */ s32 unk70;
} Vehicle;
SIZE_CHECK(Vehicle, 0x74);

extern Vehicle D_80364460[12];
extern Vehicle *D_803649D0;
extern u8 D_80364456; /* the player's VehicleType */

#endif
