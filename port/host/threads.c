/*
 * The game's threads as fibers on one OS thread, scheduled as libultra
 * does: the highest-priority runnable thread runs until it blocks, yields,
 * or wakes a thread of higher priority; equal priorities are FIFO.  The
 * main loop (main.c) runs whenever none is runnable, and stands in for the
 * interrupts.
 *
 * Each thread has two stacks: a host stack for the native C (a fiber stack
 * inside the KSEG0 window, see port.h), and its N64 stack, the one the game
 * passed to osCreateThread, which only the translated code uses (through
 * ctx->sp).  Each also has its own recomp_context.
 */
#include <stdlib.h>
#include <string.h>
#include <ucontext.h>

#include "host.h"

enum { T_FREE, T_STOPPED, T_RUNNABLE, T_WAITING, T_PARKED, T_DEAD };
static const char *state_names[] = { "free", "stopped", "runnable", "waiting", "parked", "dead" };

typedef struct {
    int state;
    uint32_t key;               /* the OSThread's address */
    int pri;
    uint64_t seq;               /* FIFO order among equal priorities */
    uint32_t wait_key;
    void (*entry)(void *);
    void *arg;
    ucontext_t uc;
    recomp_context ctx;
    int started;
} HThread;

static HThread threads[PORT_MAX_THREADS];
static HThread *cur;
static ucontext_t loop_uc;
static uint64_t seq_counter;

recomp_context *port_ctx(void) {
    if (!cur)
        host_fatal("translated code called outside a thread");
    return &cur->ctx;
}

static HThread *find(uint32_t key) {
    if (key == 0)
        return cur;
    for (int i = 0; i < PORT_MAX_THREADS; i++)
        if (threads[i].state != T_FREE && threads[i].key == key)
            return &threads[i];
    return NULL;
}

static void fiber_main(void) {
    HThread *t = cur;
    t->entry(t->arg);
    /* returning from a thread's entry: it just stops */
    t->state = T_DEAD;
    swapcontext(&t->uc, &loop_uc);
    host_fatal("dead thread resumed");
}

void host_thread_create(uint32_t key, void (*entry)(void *), void *arg, uint32_t mips_sp, int pri) {
    HThread *t = find(key);
    if (!t || key == 0) {
        for (int i = 0; i < PORT_MAX_THREADS && !t; i++)
            if (threads[i].state == T_FREE || threads[i].state == T_DEAD)
                t = &threads[i];
    }
    if (!t)
        host_fatal("out of threads");
    if (t == cur)
        host_fatal("osCreateThread on the running thread");
    int idx = (int)(t - threads);
    memset(t, 0, sizeof *t);
    t->state = T_STOPPED;
    t->key = key;
    t->pri = pri;
    t->entry = entry;
    t->arg = arg;
    t->ctx.sp = (uint64_t)(int64_t)(int32_t)mips_sp;
    getcontext(&t->uc);
    t->uc.uc_stack.ss_sp = (void *)(uintptr_t)(PORT_STACK_BASE + idx * PORT_STACK_SIZE);
    t->uc.uc_stack.ss_size = PORT_STACK_SIZE;
    t->uc.uc_link = NULL;
    makecontext(&t->uc, fiber_main, 0);
    if (host_verbose)
        host_log("thread %08X created, pri %d, entry %p\n", key, pri, (void *)entry);
}

static void to_loop(void) {
    HThread *t = cur;
    swapcontext(&t->uc, &loop_uc);
}

void host_preempt(void) {
    if (!cur)
        return;
    for (int i = 0; i < PORT_MAX_THREADS; i++)
        if (threads[i].state == T_RUNNABLE && threads[i].pri > cur->pri) {
            cur->seq = seq_counter++;
            to_loop();
            return;
        }
}

void host_thread_start(uint32_t key) {
    HThread *t = find(key);
    if (!t)
        host_fatal("osStartThread on unknown thread %08X", key);
    if (t->state == T_STOPPED) {
        t->state = T_RUNNABLE;
        t->seq = seq_counter++;
    }
    host_preempt();
}

void host_thread_stop(uint32_t key) {
    HThread *t = find(key);
    if (!t)
        return;
    if (t == cur) {
        t->state = T_STOPPED;
        to_loop();
    } else if (t->state == T_RUNNABLE || t->state == T_WAITING) {
        t->state = T_STOPPED;
    }
}

void host_thread_destroy(uint32_t key) {
    HThread *t = find(key);
    if (!t)
        return;
    if (t == cur) {
        t->state = T_DEAD;
        to_loop();
        host_fatal("destroyed thread resumed");
    }
    t->state = T_FREE;
}

void host_thread_set_pri(uint32_t key, int pri) {
    HThread *t = find(key);
    if (!t)
        return;
    t->pri = pri;
    if (t == cur && pri == 0) {
        /* the idle thread drops to priority 0 and spins forever: park it
           instead, as nothing ever runs at priority 0 but it */
        if (host_verbose)
            host_log("thread %08X parked (idle)\n", t->key);
        t->state = T_PARKED;
        to_loop();
        host_fatal("parked thread resumed");
    }
    host_preempt();
}

int host_thread_get_pri(uint32_t key) {
    HThread *t = find(key);
    return t ? t->pri : 0;
}

uint32_t host_thread_current(void) {
    return cur ? cur->key : 0;
}

void host_block(uint32_t key) {
    if (!cur)
        host_fatal("blocking receive outside a thread (key %08X)", key);
    cur->state = T_WAITING;
    cur->wait_key = key;
    to_loop();
}

void host_wake(uint32_t key) {
    for (int i = 0; i < PORT_MAX_THREADS; i++)
        if (threads[i].state == T_WAITING && threads[i].wait_key == key) {
            threads[i].state = T_RUNNABLE;
            threads[i].seq = seq_counter++;
        }
}

void host_yield(void) {
    if (!cur)
        return;
    cur->seq = seq_counter++;
    to_loop();
}

int host_run_one(void) {
    HThread *best = NULL;
    for (int i = 0; i < PORT_MAX_THREADS; i++) {
        HThread *t = &threads[i];
        if (t->state != T_RUNNABLE)
            continue;
        if (!best || t->pri > best->pri || (t->pri == best->pri && t->seq < best->seq))
            best = t;
    }
    if (!best)
        return 0;
    cur = best;
    swapcontext(&loop_uc, &best->uc);
    cur = NULL;
    return 1;
}

void host_threads_dump(void) {
    for (int i = 0; i < PORT_MAX_THREADS; i++) {
        HThread *t = &threads[i];
        if (t->state == T_FREE)
            continue;
        host_log("  thread %08X pri %3d %-8s wait %08X%s\n", t->key, t->pri, state_names[t->state],
                 t->wait_key, t == cur ? " (current)" : "");
    }
}
