/*
 * The interface between the two halves of the port.
 *
 * "N64 side": the decompiled game C and port/src/ (the libultra
 * replacement).  Built by clang with BEPass, so its memory is big-endian,
 * byte for byte what the N64 would hold (docs/PORT.md, "Memory model").
 *
 * "Host side": port/host/ (SDL, files, fibers, the renderer) and the
 * translated handwritten code (which does its own byte swapping).  Built
 * normally.
 *
 * Only scalars and addresses cross between the two.  A host function that
 * reads or writes game memory through an address must do it in big-endian
 * order (port_be32 etc. below) or byte by byte.
 */
#ifndef PORT_H
#define PORT_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ---- memory ------------------------------------------------------------ */

/* RDRAM: the N64's 4 MB, mapped at its KSEG0 address.  The port's own
   image is linked right above it (0x80400000), so every address the game
   sees, whether a fixed RDRAM buffer or one of its variables, is a KSEG0
   address, and K0_TO_PHYS/PHYS_TO_K0 round-trip. */
#define PORT_RDRAM_BASE 0x80000000u
#define PORT_RDRAM_SIZE 0x00400000u
/* hardware registers (KSEG1 0xA4000000-0xA4900000): plain memory, so the
   odd debug read of one gets a zero */
#define PORT_HWREG_BASE 0xA4000000u
#define PORT_HWREG_SIZE 0x00900000u
/* fiber stacks for the game's threads, inside the KSEG0 window so that the
   address of a local means the same thing to the translated code */
#define PORT_STACK_BASE 0x90000000u
#define PORT_STACK_SIZE 0x00100000u
#define PORT_MAX_THREADS 16

static inline void *port_ptr(uint32_t addr) {
    if (addr - 0xA0000000u < 0x20000000u)
        addr -= 0x20000000u;        /* KSEG1 -> KSEG0 */
    return (void *)(uintptr_t)addr;
}

/* big-endian accessors for host-side code touching game memory */
static inline uint32_t port_be32(const void *p) {
    const uint8_t *b = (const uint8_t *)p;
    return ((uint32_t)b[0] << 24) | ((uint32_t)b[1] << 16) | ((uint32_t)b[2] << 8) | b[3];
}
static inline uint16_t port_be16(const void *p) {
    const uint8_t *b = (const uint8_t *)p;
    return (uint16_t)((b[0] << 8) | b[1]);
}
static inline void port_wbe32(void *p, uint32_t v) {
    uint8_t *b = (uint8_t *)p;
    b[0] = v >> 24; b[1] = v >> 16; b[2] = v >> 8; b[3] = v;
}
static inline void port_wbe16(void *p, uint16_t v) {
    uint8_t *b = (uint8_t *)p;
    b[0] = v >> 8; b[1] = v;
}

/* ---- host services (port/host) ----------------------------------------- */

void host_fatal(const char *fmt, ...) __attribute__((noreturn, format(printf, 1, 2)));
void host_log(const char *fmt, ...) __attribute__((format(printf, 1, 2)));
extern int host_verbose;

/* the cartridge */
uint32_t host_rom_size(void);
void host_rom_read(uint32_t dst, uint32_t rom, uint32_t len);
uint32_t host_rom_word(uint32_t rom);

/* 46.875 MHz CPU count since boot */
uint64_t host_ticks(void);

/* threads: the game's OSThreads, run as fibers, one at a time */
void host_thread_create(uint32_t key, void (*entry)(void *), void *arg, uint32_t mips_sp, int pri);
void host_thread_start(uint32_t key);
void host_thread_stop(uint32_t key);
void host_thread_destroy(uint32_t key);
void host_thread_set_pri(uint32_t key, int pri);
int host_thread_get_pri(uint32_t key);
uint32_t host_thread_current(void);
/* block the current thread until host_wake(key); then return */
void host_block(uint32_t key);
void host_wake(uint32_t key);
/* let a higher-priority runnable thread run now (libultra preemption) */
void host_preempt(void);
void host_yield(void);

/* "interrupts" the host raises from its loop, into port/src */
void port_irq_vi(void);             /* one retrace */
uint64_t port_irq_timers(uint64_t now);   /* fire due timers; next deadline or ~0 */
void port_irq_event(int event);     /* OS_EVENT_* */
void host_raise(int event);         /* queue an event for the loop */

/* RSP/RDP */
/* runs a graphics task; 1 if its display list ended in a full sync */
int host_gfx_task(uint32_t dl, uint32_t size, uint32_t ucode);
void host_vi_set_framebuffer(uint32_t fb, int width);

/* input: N64 button bits and stick (written big-endian: the pointers are
   the N64 side's) */
void host_input(int pad, uint16_t *buttons, int8_t *x, int8_t *y);
int host_quit_requested(void);
void host_controller_poll(void);

/* EEPROM (4 Kbit) */
void host_eeprom_read(int block, uint32_t dst);
void host_eeprom_write(int block, uint32_t src);

void host_audio_buffer(uint32_t addr, uint32_t len, uint32_t freq);

#ifdef __cplusplus
}
#endif

#endif
