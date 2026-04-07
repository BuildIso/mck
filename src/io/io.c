#include "io/io.h"

static mck_io_read_fn g_read = 0;
static mck_io_write_fn g_write = 0;

void mck_io_set_read(mck_io_read_fn fn) {
    g_read = fn;
}

void mck_io_set_write(mck_io_write_fn fn) {
    g_write = fn;
}

mck_io_val mck_io_read(mck_io_addr addr) {
    if (g_read) {
        return g_read(addr);
    }
    return 0;
}

void mck_io_write(mck_io_addr addr, mck_io_val value) {
    if (g_write) {
        g_write(addr, value);
    }
}
