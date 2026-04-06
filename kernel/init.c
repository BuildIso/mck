#include "kernel.h"
#include "debug/panic.h"

void kernel_init(void) {
    core_log("[kernel] init");

    mck_time_init(1);  /* 1 tick = 1 ms */

    core_log("[kernel] time initialized");
}

void kernel_run(void) {
    core_log("[kernel] running");

    for (;;) {
        /* Kernel main loop */
        /* Scheduler, events, drivers, etc. */
    }
}
