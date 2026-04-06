#include "core.h"

static int        core_ready = 0;
static mck_log_fn core_logger = 0;

void core_init(void) {
    core_ready = 1;
    if (core_logger) {
        core_logger("[core] initialized");
    }
}

int core_is_ready(void) {
    return core_ready;
}

void core_set_logger(mck_log_fn logger) {
    core_logger = logger;
}

void core_log(const char *message) {
    if (core_logger) {
        core_logger(message);
    }
}
