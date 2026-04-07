#ifndef MCK_FS_H
#define MCK_FS_H

/* Minimal filesystem abstraction for mck */

typedef void *mck_fs_handle;

typedef mck_fs_handle (*mck_fs_open_fn)(const char *path);
typedef long (*mck_fs_read_fn)(mck_fs_handle h, void *buffer, long size);
typedef long (*mck_fs_write_fn)(mck_fs_handle h, const void *buffer, long size);
typedef void (*mck_fs_close_fn)(mck_fs_handle h);

void mck_fs_set_open(mck_fs_open_fn fn);
void mck_fs_set_read(mck_fs_read_fn fn);
void mck_fs_set_write(mck_fs_write_fn fn);
void mck_fs_set_close(mck_fs_close_fn fn);

mck_fs_handle mck_fs_open(const char *path);
long mck_fs_read(mck_fs_handle h, void *buffer, long size);
long mck_fs_write(mck_fs_handle h, const void *buffer, long size);
void mck_fs_close(mck_fs_handle h);

#endif
