#include "tty/tty.h"

static mck_tty_write_fn g_write = 0;
static mck_tty_putc_fn g_putc = 0;

void mck_tty_set_write(mck_tty_write_fn fn) {
    g_write = fn;
}

void mck_tty_set_putc(mck_tty_putc_fn fn) {
    g_putc = fn;
}

void mck_tty_write(const char *text) {
    if (g_write) {
        g_write(text);
    }
}

void mck_tty_putc(char c) {
    if (g_putc) {
        g_putc(c);
    }
}
