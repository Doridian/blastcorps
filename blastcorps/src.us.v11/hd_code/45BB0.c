#include "common.h"

/* Same layout as OSContPad, but byte 1 is also read on its own. */
typedef struct {
    /* 0x0 */ u16 unk0;
    /* 0x2 */ s8 unk2;
    /* 0x3 */ s8 unk3;
    /* 0x4 */ u8 unk4;
} UnkStruct_80370BD8;

typedef struct {
    /* 0x0 */ u16 unk0;
    /* 0x2 */ s8 unk2;
    /* 0x3 */ s8 unk3;
} UnkStruct_80370C30;

typedef struct {
    /* 0x0000 */ u8 unk0[0x2E18];
    /* 0x2E18 */ char *unk2E18;
    /* 0x2E1C */ s32 unk2E1C;
    /* 0x2E20 */ u8 unk2E20[0xE];
    /* 0x2E2E */ s16 unk2E2E;
    /* 0x2E30 */ u8 unk2E30[4];
    /* 0x2E34 */ char *unk2E34;
} UnkStruct_802F5804;

typedef struct {
    /* 0x000 */ u8 unk0[0x9B8];
    /* 0x9B8 */ s16 unk9B8;
} UnkStruct_802F8BDC;

extern OSMesgQueue D_80370BF8;
extern OSMesg D_80370BF0;
extern u8 D_80370BC8[];
extern u8 D_80370C10;
extern s8 D_80370C35;
extern u8 D_8039C4B0;
extern u8 D_802E8BD0;
extern s32 D_80370BC0;
extern u8 D_80370C15;
extern u8 D_80370C16;
extern u8 D_80370C17;
extern u8 D_80370C18;
extern u8 D_80370C19;
extern u8 D_80370C1A;
extern u8 D_80370C1B;
extern u8 D_80370C1C;
extern u8 D_80370C1D;
extern u8 D_80370C1E;
extern u8 D_80370C1F;
extern u8 D_80370C20;
extern u8 D_80370C21;
extern u8 D_80370C22;
extern s8 D_80370C23;
extern s8 D_80370C24;
extern s8 D_80370C25;
extern s8 D_80370C26;
extern s8 D_80370C27;
extern u16 D_80370C28;
extern u16 D_80370C2A;
extern s8 D_80370C2C;
extern s8 D_80370C2D;
extern s32 D_80370C38;
extern UnkStruct_802F5804 D_802F5804[];
extern UnkStruct_802F8BDC D_802F8BDC[];
extern u8 D_80364456;
extern u8 D_80364AE8;
extern s32 D_80364BE0[][0x40];
extern UnkStruct_80370BD8 D_80370BD8;
extern UnkStruct_80370C30 D_80370C30;
extern u32 D_80358060;
extern s32 D_80358064;
extern s32 D_802E8BDC;
extern u64 D_80364A90;
extern s8 D_80370C11;
extern s8 D_80370C12;
extern s8 D_80370C13;
extern s8 D_80370C14;
extern s8 D_80370C2E;
extern s8 D_80370C2F;
extern s8 D_80370C34;
extern s32 D_80370C40;
extern s8 D_80370C75;
extern u8 D_803ED40A;
extern s16 D_803F7C34;
extern u8 D_803F7C3F;

void func_8026AF6C(s32);
void func_8029A7E4(char *, ...);
void func_8028A42C(void);
void func_8025BEF8(void);
void func_8025BBE8(u16, s8, s8);
void func_8028B734(s8 *, s8 *, u8);
void func_8028ADF0(u8, u8, u16 *, s8 *, s8 *);
void func_8028AFA4(u16, s8 *, s8 *);
void func_8028B0E8(u16 *, s8, s8);
void func_8028B190(s8 *, s8 *);

s32 D_802FDB10 = 0;
u8 D_802FDB14 = 0;

u8 func_8028A370(void) {
    s32 unused;
    u8 sp1B;

    osCreateMesgQueue(&D_80370BF8, &D_80370BF0, 1);
    osSetEventMesg(OS_EVENT_SI, &D_80370BF8, 0);
    osContInit(&D_80370BF8, &sp1B, D_80370BC8);
    osContSetCh(1);
    D_80370C10 = 0;
    D_80370C35 = 0;
    return sp1B;
}

void func_8028A3E4(void) {
    if (D_8039C4B0 == 0) {
        func_8028A42C();
        osContStartReadData(&D_80370BF8);
        D_80370C10 = 1;
    }
}

void func_8028A42C(void) {
    if (D_80370C10 != 0) {
        osRecvMesg(&D_80370BF8, NULL, OS_MESG_BLOCK);
        D_80370C10 = 0;
    }
}

void func_8028A470(void) {
    UnkStruct_80370BD8 *sp44;
    s32 unused;
    s32 sp3C;

    sp44 = &D_80370BD8;
    if (D_80358064 != 0) {
        if (D_8039C4B0 == 0 && D_80370C10 != 0) {
            osRecvMesg(&D_80370BF8, NULL, OS_MESG_BLOCK);
            osContGetReadData(sp44);
            if (sp44->unk4 != 0) {
                func_8029A7E4("pad read error - zeroing data\n");
                sp44->unk0 = 0;
                sp44->unk2 = sp44->unk3 = ((s8 *) sp44)[1];
            }
            D_80370C10 = 0;
        }
        D_80370C2A = D_80370C28;
        D_80370C28 = sp44->unk0;
        if (D_80370C38 != 0) {
            if (sp44->unk0 & 0x4000) {
                sp44->unk0 &= ~0x4000;
            } else {
                D_80370C38 = 0;
            }
        }
        if (D_80358060 < 6) {
            if (D_80358060 == 5) {
                D_80370C2A |= 0xD000;
            } else {
                D_80370C28 &= ~0xD000;
            }
        }
        D_80370C13 = D_80370C11;
        D_80370C14 = D_80370C12;
        D_80370C11 = sp44->unk2;
        D_80370C12 = sp44->unk3;
        D_80370C24 = D_80370C1E;
        D_80370C25 = D_80370C1F;
        D_80370C26 = D_80370C20;
        D_80370C27 = D_80370C21;
        switch (D_80364A90) {
            case 0x2:
            case 0x40:
            case 0x400:
            case 0x100000000000:
                if (D_802E8BDC != 0x26 && D_802E8BDC != 0x31) {
                    do {
                        func_8025BEF8();
                        if (D_80370C30.unk0 & 0x40) {
                            D_80370C40 = 0;
                        } else if (D_80370C30.unk0 & 0x80) {
                            D_80370C40 = 1;
                        }
                    } while (D_80370C30.unk0 & 0xC0);
                }
                sp44->unk0 = D_80370C30.unk0;
                sp44->unk2 = D_80370C30.unk2;
                sp44->unk3 = D_80370C30.unk3;
                sp44->unk0 &= ~8;
                break;
            case 0x4:
            case 0x100:
                if (D_802E8BD0 == 0 || D_80364A90 == 0x2000) {
                    func_8025BBE8(sp44->unk0 & ~0x1000, sp44->unk2, sp44->unk3);
                }
                break;
            case 0x1:
            case 0x8:
            case 0x200:
            case 0x800:
            case 0x1000:
            case 0x4000000:
                sp44->unk0 = 0;
                sp44->unk2 = 0;
                sp44->unk3 = 0;
                break;
        }
        D_80370C34 = 0;
        if (D_80364A90 & 0x2000100000002546) {
            D_803ED40A = 0;
            D_803F7C34 = 0;
            if (D_80364A90 & 0x440) {
                sp3C = D_80370C40;
            } else if (D_80364BE0[D_80364AE8][0] & (1 << D_80364456)) {
                sp3C = 1;
            } else {
                sp3C = 0;
            }
            if (D_80364A90 == 0x2 || D_80364A90 == 0x100000000000) {
                sp3C = 0;
            }
            D_80370C35 = sp3C;
            if (D_802E8BD0 != 0) {
                func_8028ADF0(1, 0, &sp44->unk0, &sp44->unk2, &sp44->unk3);
            } else {
                switch (sp3C) {
                    case 0:
                        switch (D_80364456) {
                            case 9:
                                if (D_803F7C3F != 0) {
                                    D_80370C34 = 1;
                                }
                            case 0:
                            case 2:
                            case 16:
                                func_8028B734(&sp44->unk2, &sp44->unk3, D_80364456);
                                func_8028B190(&sp44->unk2, &sp44->unk3);
                                break;
                            default:
                                D_80370C75 = 0;
                                func_8028ADF0(0, 0, &sp44->unk0, &sp44->unk2, &sp44->unk3);
                                break;
                        }
                        break;
                    case 1:
                        if (D_80364456 == 9) {
                            D_80370C75 = 0;
                            func_8028ADF0(1, 1, &sp44->unk0, &sp44->unk2, &sp44->unk3);
                        } else {
                            D_80370C75 = 0;
                            func_8028ADF0(1, 0, &sp44->unk0, &sp44->unk2, &sp44->unk3);
                        }
                        break;
                }
            }
        }
    } else {
        sp44->unk0 = 0;
        sp44->unk2 = 0;
        sp44->unk3 = 0;
    }
    if (sp44->unk0 & 0x200) {
        D_80370C15 = 1;
    } else {
        D_80370C15 = 0;
    }
    if (sp44->unk0 & 0x100) {
        D_80370C16 = 1;
    } else {
        D_80370C16 = 0;
    }
    if (sp44->unk0 & 0x800) {
        D_80370C17 = 1;
    } else {
        D_80370C17 = 0;
    }
    if (sp44->unk0 & 0x400) {
        D_80370C18 = 1;
    } else {
        D_80370C18 = 0;
    }
    if (sp44->unk0 & 0x1000) {
        D_80370C19 = 1;
    } else {
        D_80370C19 = 0;
    }
    if (sp44->unk0 & 0x20) {
        D_80370C1A = 1;
    } else {
        D_80370C1A = 0;
    }
    if (sp44->unk0 & 0x10) {
        D_80370C1B = 1;
    } else {
        D_80370C1B = 0;
    }
    if (sp44->unk0 & 0x8000) {
        D_80370C1C = 1;
    } else {
        D_80370C1C = 0;
    }
    if (sp44->unk0 & 0x4000) {
        D_80370C1D = 1;
    } else {
        D_80370C1D = 0;
    }
    if (sp44->unk0 & 2) {
        D_80370C1E = 1;
    } else {
        D_80370C1E = 0;
    }
    if (sp44->unk0 & 4) {
        D_80370C1F = 1;
    } else {
        D_80370C1F = 0;
    }
    if (sp44->unk0 & 8) {
        D_80370C20 = 1;
    } else {
        D_80370C20 = 0;
    }
    if (sp44->unk0 & 1) {
        D_80370C21 = 1;
    } else {
        D_80370C21 = 0;
    }
    if (sp44->unk0 & 0x2000) {
        D_80370C22 = 1;
    } else {
        D_80370C22 = 0;
    }
    D_80370C23 = D_80370C1D || D_80370C22;
    D_80370C2E = D_80370C2C;
    D_80370C2F = D_80370C2D;
    D_80370C2C = sp44->unk2;
    D_80370C2D = sp44->unk3;
}

void func_8028ADF0(u8 arg0, u8 arg1, u16 *arg2, s8 *arg3, s8 *arg4) {
    if (arg0 == 0 && D_802E8BD0 == 0) {
        *arg4 = 0;
    }
    if (arg1 == 0) {
        func_8028AFA4(*arg2, arg3, arg4);
    }
    func_8028B190(arg3, arg4);
    if (arg1 == 0) {
        func_8028B0E8(arg2, *arg3, *arg4);
    }
}

void func_8028AE88(void) {
    D_80370C27 = 0;
    D_80370C26 = 0;
    D_80370C25 = 0;
    D_80370C24 = 0;
    D_80370C2D = 0;
    D_80370C2C = 0;
    D_80370C23 = 0;
    D_80370C22 = 0;
    D_80370C21 = 0;
    D_80370C20 = 0;
    D_80370C15 = D_80370C16 = D_80370C17 = D_80370C18 = D_80370C19 = D_80370C1A = D_80370C1B = D_80370C1C =
        D_80370C1D = D_80370C1E = D_80370C1F = 0;
    D_80370C2A = 0;
    D_80370C28 = 0;
    D_80370BC0 = 0;
    D_80370C38 = 0;
}

void func_8028AFA4(u16 arg0, s8 *arg1, s8 *arg2) {
    if (arg0 & 0x200) {
        *arg1 = -80;
    }
    if (arg0 & 0x100) {
        *arg1 = 80;
    }
    if (arg0 & 0x4000) {
        *arg2 = -80;
    }
    if (arg0 & 0x8000) {
        *arg2 = 80;
    }
}

void func_8028B000(s8 *arg0, s8 *arg1) {
    switch (D_80364456) {
        case 1:
        case 3:
        case 4:
        case 5:
        case 6:
            if (*arg0 < 51 && *arg0 >= -50) {
                *arg0 = 0;
            } else {
                if (*arg0 >= 51) {
                    *arg0 = 80;
                }
                if (*arg0 < -50) {
                    *arg0 = -80;
                }
            }
            if (*arg1 < 51 && *arg1 >= -50) {
                *arg1 = 0;
                return;
            }
            if (*arg1 >= 51) {
                *arg1 = 80;
            }
            if (*arg1 < -50) {
                *arg1 = -80;
            }
            break;
    }
}

void func_8028B0E8(u16 *arg0, s8 arg1, s8 arg2) {
    if (!(*arg0 & 0x200) && arg1 < -50) {
        *arg0 |= 0x200;
    }
    if (!(*arg0 & 0x100) && arg1 > 50) {
        *arg0 |= 0x100;
    }
    if (!(*arg0 & 0x8000) && arg2 > 50) {
        *arg0 |= 0x8000;
    }
    if (!(*arg0 & 0x4000) && arg2 < -50) {
        *arg0 |= 0x4000;
    }
}

void func_8028B190(s8 *arg0, s8 *arg1) {
    if (*arg0 < 10 && *arg0 > -10) {
        *arg0 = 0;
    }
    if (*arg0 > 80) {
        *arg0 = 80;
    }
    if (*arg0 < -80) {
        *arg0 = -80;
    }
    if (*arg1 < 10 && *arg1 > -10) {
        *arg1 = 0;
    }
    if (*arg1 > 80) {
        *arg1 = 80;
    }
    if (*arg1 < -80) {
        *arg1 = -80;
    }
}

void func_8028B240(void) {
    char *sp24[3] = { "SPEED ON 3D STICK?", "360 DEGREE MODE?", "AIRBORNE 360' MODE?" };
    static s32 D_802FDB24[3] = { 0xEDBA, 0x10005, 0x200 };
    char *sp20;
    s32 sp1C;
    s32 sp18;

    sp20 = "CONTROL METHOD:";
    sp1C = 0;
    sp18 = 0;
    do {
        if (D_802FDB24[sp18] & (1 << D_80364456)) {
            sp1C = 1;
        } else {
            sp18++;
        }
    } while (sp18 < 3 && sp1C == 0);
    if (sp1C == 0) {
        func_8029A7E4("\n\007 --- ASSERTION FAULT - %s - %s, line %d\n\n", "found", "controller.c", 0x203);
    }
    D_802F5804[0].unk2E18 = sp20;
    D_802F5804[0].unk2E1C = 0;
    D_802F5804[0].unk2E34 = sp24[sp18];
    D_802F5804[0].unk2E2E = 0x13;
    if ((D_80364BE0[D_80364AE8][0] ^ 0x10205) & (1 << D_80364456)) {
        D_802F8BDC[0].unk9B8 = 0x1A8;
    } else {
        D_802F8BDC[0].unk9B8 = 0x1A7;
    }
    func_8026AF6C(0x8058);
}
