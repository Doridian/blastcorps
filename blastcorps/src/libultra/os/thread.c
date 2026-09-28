/* libultra os/thread.c: the functions.  Its data, if any, is defined by the includer. */
#include "common.h"
#include "ultra_internal.h"

void __osDequeueThread(register OSThread **queue, register OSThread *t) {
    register OSThread *pred;
    register OSThread *succ;

    pred = (OSThread *)queue;
    succ = pred->next;
    while (succ != NULL) {
        if (succ == t) {
            pred->next = t->next;
            return;
        }
        pred = succ;
        succ = pred->next;
    }
}
