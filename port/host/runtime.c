/*
 * Runtime support: the hooks the translated code needs, and the startup
 * byte swaps that put initialized data into big-endian order.
 */
#include <stdio.h>
#include <stdlib.h>

#include "host.h"

/* ---- startup fixups ------------------------------------------------------ */

/* BEPass: runs of equally sized scalars in C initializers, swapped from the
   compiler's host order (called from each module's constructor) */
struct bepass_entry {
    uint8_t *p;
    uint32_t count, size;
};

static void swap_bytes(uint8_t *q, uint32_t size) {
    for (uint32_t a = 0, b = size - 1; a < b; a++, b--) {
        uint8_t t = q[a];
        q[a] = q[b];
        q[b] = t;
    }
}

void __bepass_fixup(const struct bepass_entry *e, uint32_t n) {
    for (uint32_t i = 0; i < n; i++)
        for (uint32_t k = 0; k < e[i].count; k++)
            swap_bytes(e[i].p + k * e[i].size, e[i].size);
}

/* asm2x86.py: symbolic .words in the game's data, in host order until now */
extern uint32_t __start_port_bswap32[] __attribute__((weak));
extern uint32_t __stop_port_bswap32[] __attribute__((weak));

void port_fixups(void) {
    for (uint32_t *p = __start_port_bswap32; p < __stop_port_bswap32; p++)
        swap_bytes((uint8_t *)(uintptr_t)*p, 4);
}

/* ---- translated-code hooks ------------------------------------------------ */

void recomp_trap(recomp_context *ctx, int kind, uint32_t pc, uint32_t code) {
    (void)ctx;
    host_fatal("translated code trapped: kind %d at %08X (code %X)", kind, pc, code);
}

void recomp_call_external(uint8_t *rdram, recomp_context *ctx, uint32_t addr) {
    (void)rdram; (void)ctx;
    host_fatal("unhandled call out of translated code to %08X", addr);
}

uint64_t recomp_mfc0(recomp_context *ctx, int reg) {
    (void)ctx;
    if (reg == 12)          /* Status: interrupts enabled, CU1 */
        return 0x2000FF01u;
    if (reg == 9)           /* Count */
        return (uint32_t)host_ticks();
    return 0;
}

void recomp_mtc0(recomp_context *ctx, int reg, uint64_t value) {
    (void)ctx; (void)reg; (void)value;
}
