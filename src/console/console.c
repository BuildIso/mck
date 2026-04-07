#include "console/console.h"

static mck_console_write_fn g_write = 0;
static mck_console_clear_fn g_clear = 0;

void mck_console_set_write(mck_console_write_fn fn) {
    g_write = fn;
}

void mck_console_set_clear(mck_console_clear_fn fn) {
    g_clear = fn;
}

void mck_console_write(const char *text) {
    if (g_write) {
        g_write(text);
    }
}

void mck_console_clear(void) {
    if (g_clear) {
        g_clear();
    }
}
