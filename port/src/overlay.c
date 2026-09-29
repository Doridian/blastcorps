/*
 * hd_front_end, the overlay.
 *
 * On the N64, func_8028B3E0 (hd_code/46C20.c) inflates the front end's
 * .text and .data from the ROM to 0x801E7000 and clears the rest of its
 * area, up to 0x8021ED00 (so its .bss); gameplay reuses that memory for
 * the level.  In the port the front end's code is linked in, and its data
 * sits at its N64 addresses (tools/gen_ld.py), so "loading" it means
 * putting its .data back as it was at startup and clearing its .bss, which
 * is what the inflate leaves behind.  The ROM's copy can't be used: its
 * .data holds N64 pointers to N64 code.
 *
 * The link wraps func_8028B3E0 (--wrap) with this.
 */
#include "common.h"
#include "port.h"

#define FE_START 0x801E7000     /* the overlay area */
#define FE_DATA 0x80208040      /* .hd_front_end_data */
#define FE_BSS 0x80210E90       /* .hd_front_end_bss */
#define FE_END 0x8021ED00       /* init's .text: the end of the area */

extern u8 D_80370C50;           /* "front end loaded" */
void func_801F57B0(void);
void func_8029A7E4(char *, ...);
extern void *memmove(void *, const void *, unsigned int);
extern void *memset(void *, int, unsigned int);

static u8 fe_data[FE_BSS - FE_DATA];

void port_overlay_init(void) {
    memmove(fe_data, (void *)FE_DATA, sizeof fe_data);
}

void __wrap_func_8028B3E0(void) {
    osViBlack(1);
    if (D_80370C50 == 0) {
        memmove((void *)FE_DATA, fe_data, sizeof fe_data);
        memset((void *)FE_BSS, 0, FE_END - FE_BSS);
        D_80370C50 = 1;
        func_801F57B0();
        if (host_verbose)
            host_log("front end loaded\n");
    }
}
