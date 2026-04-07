#include "arch/common/cpu.h"

/* Default weak implementations */

void mck_cpu_pause(void) {
    /* No-op by default */
}

void mck_cpu_halt(void) {
    for (;;) {
        /* Infinite halt loop */
    }
}
