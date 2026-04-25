#ifndef STORAGE_RAMFS_H
#define STORAGE_RAMFS_H

typedef struct {
    const char *name;
    const void *data;
    unsigned long size;
} ramfs_file;

void ramfs_init(ramfs_file *files, unsigned long count);
const ramfs_file *ramfs_get(const char *name);

#endif
