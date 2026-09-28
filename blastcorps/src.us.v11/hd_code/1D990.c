#include "common.h"

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 pad1[0x1B];
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ u8 pad20[6];
    /* 0x26 */ s16 unk26;
    /* 0x28 */ s16 unk28;
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ u8 pad2C[0xC];
    /* 0x38 */ u8 unk38;
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ u16 unk40;
    /* 0x42 */ u16 unk42;
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
extern s32 D_803156C0;
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
void alCSPSetTempo(ALCSPlayer *, s32);
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

typedef struct {
    /* 0x0 */ u8 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 unk6;
} UnkStruct_802E8F74; /* size = 0x8 */

typedef struct {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 pad5;
    /* 0x06 */ u8 unk6[0x14];
    /* 0x1A */ u8 unk1A;
    /* 0x1B */ u8 unk1B[0xB];
    /* 0x26 */ u8 unk26;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ u8 unk2D;
    /* 0x2E */ s8 unk2E;
    /* 0x2F */ u8 pad2F;
} UnkStruct_802F49F4; /* size = 0x30 */

extern u8 D_006A32B0[];
extern u8 D_006A8DA0[];
extern UnkStruct_802E8F74 D_802E8F74[];
extern char D_802E9F90[];
extern s32 D_802E9F9C;
extern UnkStruct_802F49F4 D_802F49F4[];
extern u8 *D_80358070;
extern s32 D_803156C4;
extern s32 D_80364404;
extern s32 D_80364408;
extern s32 D_8036440C;
extern s8 D_80364410;
extern u8 D_80364424;
extern s32 D_80364428;
extern u16 D_8036442C;
extern s32 D_80364430;
extern u64 D_80364A98;
extern char D_80367BB0[];
extern s32 D_80367BC0;
extern u32 D_80367BC4;
extern u16 D_80367BC8;
extern UnkStruct_802F49F4 *D_80367BCC;
extern UnkStruct_802F49F4 *D_80367BD0;
extern u8 D_80367BD4;
extern s16 D_80367BD8;
extern u8 *D_80367BE0[];
extern s8 D_80367C00;
extern u8 D_80367C01;
extern char *D_80367C08;
extern s32 D_80367C0C;
extern s32 D_803F7C10;
extern s32 D_803F7C14;

u8 func_8026FA38(char **, s32 *);
s8 func_80272C5C(u8 *, s32, s32, s32, s32, f32);
void func_8028B4C4(u8 *, u8 *, s32 *, s32, s32, s32);

void func_80262320(u8 arg0) {
    s32 i;
    u8 sp33;
    s8 sp32;
    u8 found;
    s32 size;

    i = 0;
    sp33 = 0;
    sp32 = 0;
    found = 0;
    do {
        if (D_802E8F74[i].unk0 == arg0) {
            found = 1;
        } else {
            i++;
        }
    } while (found == 0 && i < 4);
    if (found != 0) {
        D_80364410 = 1;
        D_80364404 = D_802E8F74[i].unk2 << 16;
        D_80364408 = D_802E8F74[i].unk4 << 16;
        D_8036440C = D_802E8F74[i].unk6 << 16;
    } else {
        D_80364410 = 0;
    }
    D_80367C04 = (UnkStruct_80367C04 *)&D_802E8F94[arg0];
    D_803F7C10 = D_802E8F94[arg0].unk1C << 5;
    D_803F7C14 = D_802E8F94[arg0].unk1E << 5;
    D_80364424 = D_802E8F94[arg0].unk38;
    D_80364428 = D_802E8F94[arg0].unk3C << 5;
    D_8036442C = D_802E8F94[arg0].unk40;
    D_80364430 = D_802E8F94[arg0].unk42 << 5;
    D_80367BC0 = D_803156C4;
    D_80367BC4 = -1;
    D_80367BD8 = 0;
    switch ((u32)D_80364AA8) {
        case 0x4:
        case 0x80:
            sp33 = 6;
            break;
        case 0x20:
            sp33 = func_8026FA38(&D_80367C08, &D_80367C0C);
            D_80367BD8 = 2;
            break;
        case 0x10:
        case 0x40:
            sp33 = 9;
            D_80367BD8 = -2;
            break;
        case 0x1:
        case 0x2:
        case 0x8:
            break;
    }
    if (sp33 == 6) {
        D_80367BD8 = 6;
        D_80367C08 = D_802E9F90;
        sp32 = 0;
        D_80367C0C = D_802E9F9C;
    }
    if (D_80364AA8 != 1) {
        size = D_006A8DA0 - D_006A32B0;
        if (D_80364AA8 != 0x80 && D_80364A98 == 0x2000) {
            func_8028B4C4(D_006A32B0, D_80358070, &size, 0xA, 0, 1);
            for (i = 0; i < 5; i++) {
                D_80367BE0[i] = D_80358070 + (i << 15);
            }
            D_80358070 += size;
        }
        if (D_80364A98 == 0x40) {
            D_80367BC8 = 0;
        } else {
            D_80367BC8 = 1;
        }
    } else {
        D_80367BC8 = 0;
    }
    D_80367C01 = 0;
    D_80367C00 = 0;
    if (D_80364A98 == 0x40) {
        D_80367BFF = 0;
    } else {
        D_80367BFF = 0;
        D_80367BFE = 0;
    }
    D_80367BCC = &D_802F49F4[sp33];
    if (D_802E8F94[arg0].unk0 == 0x20) {
        D_80367BD0 = 0;
        D_80367BD4 = func_80272C5C(D_80367BCC->unk6, 0, D_80367BCC->unk4, D_80367BCC->unk2C, D_80367BCC->unk2D,
                                   D_80367BCC->unk28 * 0.5);
    } else {
        D_80367BD0 = 0;
        if (sp33 != 0) {
            D_80367BD4 = func_80272C5C(D_80367BCC->unk6, 0, D_80367BCC->unk4, D_80367BCC->unk2C, D_80367BCC->unk2D,
                                       1.0f);
        } else {
            D_80367BCC = NULL;
        }
    }
    if (D_80364A98 & 0x440) {
        func_80264A34(D_80367BB0, D_80367C04->unk36 - D_80367BF6, 0);
    } else {
        D_80367B54 = 0;
    }
}

extern u8 D_802E9FA0[];
extern u8 D_803156F4;
extern u8 D_8035805C;
extern s32 D_80367738;
extern char D_80367C18[];
extern char D_80367C40[];
extern u16 D_80367C68[];
extern u16 D_80367CB8[];

void func_80260650(s32, s32, s32);
s32 func_8026205C(s32);

void func_80262840(void) {
    u32 sp34;
    u16 sp32;
    u16 sp30;

    sp34 = (u32)(D_803156C4 - D_80367BC0) / 60;
    if (sp34 == D_80367BC4) {
    } else {
        switch (sp34) {
            case 0:
                D_80367C68[0] = 0xFFF;
                D_80367CB8[0] = 0xFFF;
                switch ((u32)D_80364AA8) {
                    case 0x2:
                        sprintf(D_80367C18, "FINISH %d LAPS IN", D_80367C04->unk18);
                        break;
                    case 0x4:
                    case 0x20:
                        if (D_802E8BDC == 0x34) {
                            sprintf(D_80367C18, "DESTROY TARGETS IN");
                        } else {
                            sprintf(D_80367C18, "DESTROY %s IN", D_80367C08);
                        }
                        break;
                    case 0x80:
                        if (D_802E8BDC == 0x32) {
                            sprintf(D_80367C18, "CLEAR SHUTTLE PATH");
                        } else {
                            sprintf(D_80367C18, "CLEAR CARRIER PATH");
                        }
                        break;
                    case 0x8:
                        sprintf(D_80367C18, "CAUSE $%d DAMAGE", D_80367C04->unk18);
                        break;
                    case 0x10:
                    case 0x40:
                        sprintf(D_80367C18, "FIND %d RDUS IN", D_80367C04->unk18);
                        break;
                }
                sp32 = D_80367C04->unk36 / 600;
                sp30 = (D_80367C04->unk36 / 10) % 60;
                sprintf(D_80367C40, "%d MINUTE%c %d SECONDS", sp32, D_802E9FA0[sp32 != 1], sp30);
                D_802F5804[0x3FC / 4] = D_80367C18;
                D_802F5804[0x418 / 4] = D_80367C40;
                D_802F5804[0x400 / 4] = (char *)D_80367C68;
                D_802F5804[0x41C / 4] = (char *)D_80367CB8;
                func_8026AF6C(0x8009);
                func_80260650(D_80367738, func_8026205C(0), 0);
                break;
            case 1:
                func_80260650(D_80367738, 0x96, 0);
                break;
            case 2:
                func_80260650(D_80367738, 0x96, 0);
                break;
            case 3:
                func_80260650(D_80367738, 0x96, 0);
                break;
            case 4:
                func_80260650(D_80367738, 0x99, 0);
                break;
        }
    }
    D_80367BC4 = sp34;
    if (sp34 == 4 && D_8035805C == D_803156F4) {
        D_80364A98 = 4;
    }
}

typedef struct {
    /* 0x00 */ u8 unk0[0x18];
    /* 0x18 */ u8 unk18[0xE8];
} UnkStruct_80364AF0; /* size = 0x100 */

extern u8 D_803643D6;
extern u8 D_803643D7;
extern u64 D_80364A90;
extern u8 D_80364AE8;
extern UnkStruct_80364AF0 D_80364AF0[];
extern char D_80367BB0[];
extern u16 D_80367BF4;
extern u16 D_80367D08;
extern s16 D_8036BB1A;
extern s16 D_8036BB1C;
extern u8 D_803BE738;

void func_802609F0(void);
void func_80260A10(void);
void func_80262FD0(void);
void func_8026303C(void);
void func_80263140(void);
void func_80263358(void);
void func_802633E0(void);
void func_80275270(u64, f32);
s32 func_802753C0(void);

void func_80262BF4(void) {
    if (D_803643D7 == 0 && D_803643D6 == 0) {
        D_80367BF6 = D_80367C04->unk36 - ((D_80367C04->unk36 < func_8028604C(D_803156C0 - D_80364A58))
                                              ? D_80367C04->unk36
                                              : func_8028604C(D_803156C0 - D_80364A58));
    }
    func_80264A34(D_80367BB0, D_80367BF6, 1);
    switch (D_80364A90) {
        case 0x2000:
            func_80262840();
            break;
        case 0x4000000:
            if (D_803643D6 != 0 && func_802753C0() == 0 && D_8036BB1C == 1) {
                if ((D_80364AF0[D_80364AE8].unk18[D_802E8BDC] > 0 && D_80364AF0[D_80364AE8].unk18[D_802E8BDC] < 6)
                        ? 1
                        : 0) {
                    func_80275270(0x8000000, 0.25f);
                } else {
                    func_80275270(0x40, 0.25f);
                }
            }
            break;
        default:
            if (D_80367BF6 == 0) {
                D_803643D9 = 1;
            } else {
                D_80367BF4 = D_80367BF6 / 10;
                if (D_80367BF4 < 10 && D_80367BF4 != D_80367D08) {
                    func_80260650(D_80367738, 0xA3 - D_80367BF4, 0);
                }
                D_80367D08 = D_80367BF4;
            }
            if (D_803BE738 != 0 && D_80364AA8 == 0x40) {
                func_80260650(D_80367738, 0x3C, 0);
            }
            if (D_803BE738 != 0) {
                D_803643D9 = 1;
            }
            if (D_803643D6 != 0) {
                func_80260A10();
                func_802609F0();
                func_8026AF6C(0xA00E);
                D_8036BB1A = -1;
                D_80364A98 = 0x4000000;
            } else if (D_803643D7 != 0) {
                D_80364A98 = 0x4000000;
            } else {
                switch ((u32)D_80364AA8) {
                    case 0x2:
                        func_802633E0();
                        break;
                    case 0x4:
                        func_8026303C();
                        break;
                    case 0x20:
                    case 0x80:
                        func_80263140();
                        break;
                    case 0x8:
                        func_80263358();
                        break;
                    case 0x10:
                    case 0x40:
                        func_80262FD0();
                        break;
                }
            }
            break;
    }
}

void func_80262FD0(void) {
    if (D_8036EA7C >= D_80367C04->unk18) {
        D_803643DA = 1;
    }
    sprintf(D_80367B60, "%d/%d", D_8036EA7C, D_80367C04->unk18);
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
    sprintf(D_80367B60, "%d/%d", D_8036EA78, D_8036EB92);
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
            sprintf(D_80367B60, "%d/%d", D_8036EA78, D_8036EB92);
            break;
        case 0x80:
            if (D_802E8BDC == 0x32) {
                sprintf(D_80367B60, "%d/%d", D_8036EA78, D_8036EB92);
            } else {
                sprintf(D_80367B60, "%d/%d", func_802C1B1C(), D_8036EB92);
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
    sprintf(D_80367B60, "$%d LEFT", sp1C);
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
            func_8029A7E4("box number=%d\n", D_80367BFA);
        }
        if (D_80367BF8 == 4) {
            if (func_8026394C(D_803643E0 >> 5, D_803643E8 >> 5, D_80367C04->unkA, D_80367C04->unkC, D_80367C04->unkE,
                              D_80367C04->unk10) != 0) {
                if (D_80367B58[D_80367B54 - 1] < D_80367BFC) {
                    func_8029A7E4("new best lap %d %d\n", D_80367BFC, D_80367B58[D_80367B54 - 1]);
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
                        sprintf(D_80367D10, "1 LAP LEFT!");
                    } else {
                        sprintf(D_80367D10, "%d LAPS LEFT!", sp33);
                    }
                    D_802F5804[0x3E0 / 4] = D_80367D10;
                    D_802F5804[0x3E4 / 4] = D_80367D28;
                    alCSPSetTempo(D_80367734, alCSPGetTempo(D_80367734) * 0.95);
                }
                D_80367B54++;
                D_80367BF8 = 0;
            }
        } else if (D_80367C04->unk12[D_80367BF8] == D_80367BF9 &&
                   D_80367C04->unk12[(D_80367BF8 + 1) % 4] == D_80367BFA) {
            func_8029A7E4("box cross: %d to %d\n", D_80367BF9, D_80367BFA);
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

extern s16 D_8036BB18;
extern u8 D_80367BD5;
extern s16 D_80367BD6;
extern u8 D_80367BFB;

void func_80259CCC(void *, char *, u16 *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_8025E2CC(Gfx **, void *, s32);
Gfx *func_80264264(void *, Gfx *);
Gfx *func_80272ED8(Gfx *, u8, s16, s16, u8, u8, f32);
Gfx *func_80274868(Gfx *);
Gfx *func_80274AA4(Gfx *);

Gfx *func_802639B4(Gfx *arg0, void *arg1, s32 arg2) {
    Gfx *gfx;
    s32 unused;
    u8 sp5F;
    u8 sp5E;
    u8 sp5D;
    s16 alpha;
    s32 unused2;
    s32 i;

    gfx = arg0;
    if ((D_80364A90 & 0x04000200) && D_8036BB18 != 0x1E) {
        alpha = 0xFF;
    } else {
        alpha = D_80367BD6;
    }
    switch ((u32)D_80364AA8) {
        case 0x2:
            for (i = 0; i < D_80367B54 - ((D_80364A90 & 0x440) ? 1 : 0) && i < D_80367C04->unk18; i++) {
                if (i + 1 == D_80367BFB && i + 1 != D_80367B54) {
                    func_80259CCC(arg1, D_80367B60 + i * 0x14, NULL, 1, 0, 0x18, i * 0x12 + 0x12, 0x14, 0x14, 1, 0xFF,
                                  0, 0, D_80367BD6);
                } else if (i + 1 == D_80367B54) {
                    func_80259CCC(arg1, D_80367B60 + i * 0x14, NULL, 1, 0, 0x18, i * 0x12 + 0x12, 0x14, 0x14, 1, 0xFF,
                                  0xFF, 0xFF, D_80367BD6);
                } else {
                    func_80259CCC(arg1, D_80367B60 + i * 0x14, NULL, 1, 0, 0x18, i * 0x12 + 0x12, 0x14, 0x14, 1, 0xA0,
                                  0xA0, 0xA0, D_80367BD6);
                }
            }
            break;
        case 0x4:
        case 0x20:
        case 0x80:
            func_80259CCC(arg1, D_80367B60, NULL, 1, 0, 0x38, 0x14, 0x14, 0x14, 1, 0xFF, 0xFF, 0xFF, alpha);
            break;
        case 0x8:
            func_80259CCC(arg1, D_80367B60, NULL, 1, 0, 0x1C, 0x12, 0x14, 0x14, 1, 0xFF, 0xFF, 0xFF, alpha);
            break;
        case 0x10:
        case 0x40:
            func_80259CCC(arg1, D_80367B60, NULL, 1, 0, 0x38, 0x12, 0x14, 0x14, 1, 0xFF, 0xFF, 0xFF, alpha);
            break;
    }
    sp5E = 0xFF;
    sp5F = 0;
    if (D_80364A90 & 0x04000104) {
        sp5D = D_80367BF4 < 10;
        if (!sp5D) {
            sp5F = 0xFF;
        }
    } else {
        sp5D = 0;
        sp5F = 0xFF;
        sp5E = 0;
    }
    if (D_80367BF4 == 0) {
        sp5D = 0;
    }
    if (sp5D == 0 || (u32)D_803156C4 % 20 < 16) {
        if (D_80364AA8 == 2) {
            func_80259CCC(arg1, D_80367BB0, NULL, 1, 0, 0x18, i * 0x12 + 0x14, 0x10, 0x10, 1, sp5E, sp5F, 0,
                          D_80367BD6);
        } else {
            func_80259CCC(arg1, D_80367BB0, NULL, 1, 0, 0x1C, D_80367BD8 + 0x2A, 0x10, 0x10, 1, sp5E, sp5F, 0, alpha);
        }
    }
    if (D_803643D7 != 0 && D_80364A90 == 0x04000000) {
        func_8025E2CC(&gfx, arg1, D_8035805C);
    }
    if (D_80367BC8 != 0) {
        gfx = func_80264264(arg1, gfx);
    }
    gfx = func_80274868(gfx);
    if (D_80367BCC != NULL) {
        gfx = func_80272ED8(gfx,
                            D_80367BCC->unk1B[((u32)D_803156C4 / D_80367BCC->unk26) % D_80367BCC->unk1A] + D_80367BD4 - 1,
                            0x18, D_80367BD8 + 0xC, alpha, 1, 1.0f);
    }
    if (D_80367BD0 != NULL) {
        gfx = func_80272ED8(gfx,
                            D_80367BD0->unk1B[((u32)D_803156C4 / D_80367BD0->unk26) % D_80367BD0->unk1A] + D_80367BD5 - 1,
                            0x18, D_80367BD8 + 0xC, alpha, 1, 1.0f);
    }
    gfx = func_80274AA4(gfx);
    arg2 += (gfx - arg0) * 4;
    return gfx;
}

void func_8026420C(void) {
    if (D_80367BFE != 0 && D_80358064 == D_80367B50) {
        func_8029A7E4("Replay turbo ....\n");
        D_80367BFF = 1;
    }
}

extern u8 D_80367BFE;
extern u8 *D_80367BDC[];
extern s16 D_80367D50;
extern u8 D_80367D52;
extern u8 D_80367D53;
extern u8 D_80370C1C;

Gfx *func_80264264(void *arg0, Gfx *arg1) {
    Gfx *gfx;
    s32 i;
    s32 x;

    gfx = arg1;
    switch (D_80367BC8) {
        case 1:
            D_80367D52 = 3;
            D_80367BC8 = 2;
            break;
        case 2:
            D_80367D50 = (u32)((D_803156C4 - D_80367BC0) * 60) / 60 - 64;
            D_80367D52 = 3 - ((D_80367D50 * 2 / 10 < 0) ? 0 : D_80367D50 * 2 / 10);
            if (D_80367D50 >= 10) {
                D_80367D52 = 1;
                D_80367D50 = 10;
                D_80367BC8 = 3;
            }
            break;
        case 3:
            if (D_802E8BD0 == 0) {
                D_80367BC8 = 4;
            }
            if (D_80370C1C != 0) {
                D_80367C01 = 1;
            }
            break;
        case 4:
            D_80367D53 = D_80367D52;
            if ((u32)(D_803156C0 - D_80364A58) >= 7) {
                D_80367D52 = 5;
            } else {
                D_80367D52 = 4;
            }
            if ((u32)(D_803156C0 - D_80364A58) >= 21) {
                D_80367BC8 = 5;
                D_80367BFF = D_80367BFE;
                D_80367B50 = D_80358064;
            }
            if (D_80367D53 == 1 && D_80370C1C == 0) {
                D_80367BFE = !D_80367C01;
            }
            if (D_80367D53 == 4 && D_80367D52 == 5 && D_80370C1C == 0) {
                D_80367BFE = 0;
            }
            break;
        case 5:
            D_80367D50 = 10 - (u32)((D_803156C0 - D_80364A58) * 2 * 60 - 2400) / 60;
            if (D_80367D50 < -63) {
                D_80367BC8 = 0, func_8029A7E4("turbo %d\n", D_80367BFE);
            }
            break;
    }
    if (D_80364AA8 != 0x80) {
        gDPPipeSync(gfx++);
        gSPTexture(gfx++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
        gDPSetTexturePersp(gfx++, G_TP_NONE);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gDPSetRenderMode(gfx++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
        gDPSetCombineLERP(gfx++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 0xFF);
        x = 32;
        for (i = 0; i < 0x100; i += 0x20) {
            gDPLoadTextureTile(gfx++, D_80367BDC[D_80367D52], G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 64, i, 0, i + 31, 63, 0,
                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                               G_TX_NOLOD, G_TX_NOLOD);
            gSPScisTextureRectangle(gfx++, (i + x) << 2, 0, (i + x + 32) << 2, (D_80367D50 + 63) << 2,
                                    G_TX_RENDERTILE, i << 5, -(D_80367D50 << 5), 1 << 10, 1 << 10);
        }
        gDPPipeSync(gfx++);
        gDPSetTexturePersp(gfx++, G_TP_PERSP);
    }
    return gfx;
}

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

u8 func_80264BA4(u8 arg0) {
    u8 ret;

    switch (arg0) {
        case 40:
            ret = 0;
            break;
        case 43:
            ret = 5;
            break;
        case 44:
            ret = 4;
            break;
        case 45:
            ret = 2;
            break;
        case 46:
            ret = 1;
            break;
        default:
            ret = 3;
            break;
    }
    return ret;
}
