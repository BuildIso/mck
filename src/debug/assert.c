#include "debug/assert.h"

void mck_assert(int condition, const char *message) {
    if (!condition) {
        core_log("[assert] failed: ");
        core_log(message);
        /* In OSDev, this would halt the system */
        for (;;) {}
    }
}
