#include "debug/panic.h"
#include "core.h"

void kernel_panic(const char *msg) {
    core_log("[panic] kernel panic");
    core_log(msg);

    for (;;) {
        /* Halt forever */
    }
}
