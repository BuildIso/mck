#include "fs/fs.h"

static mck_fs_open_fn g_open = 0;
static mck_fs_read_fn g_read = 0;
static mck_fs_write_fn g_write = 0;
static mck_fs_close_fn g_close = 0;

void mck_fs_set_open(mck_fs_open_fn fn) { g_open = fn; }
void mck_fs_set_read(mck_fs_read_fn fn) { g_read = fn; }
void mck_fs_set_write(mck_fs_write_fn fn) { g_write = fn; }
void mck_fs_set_close(mck_fs_close_fn fn) { g_close = fn; }

mck_fs_handle mck_fs_open(const char *path) {
    return g_open ? g_open(path) : 0;
}

long mck_fs_read(mck_fs_handle h, void *buffer, long size) {
    return g_read ? g_read(h, buffer, size) : 0;
}

long mck_fs_write(mck_fs_handle h, const void *buffer, long size) {
    return g_write ? g_write(h, buffer, size) : 0;
}

void mck_fs_close(mck_fs_handle h) {
    if (g_close) g_close(h);
}
