#include "core.h"
#include "time/time.h"

void kernel_scheduler_tick(void) {
    /* Called by timer interrupt */
    mck_time_tick();
}
