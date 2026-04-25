#ifndef STORAGE_VRAMFS_M_VRAMFS_H
#define STORAGE_VRAMFS_M_VRAMFS_H

typedef struct {
    const char *name;
    unsigned long offset;
    unsigned long size;
} vramfs_file;

typedef struct {
    unsigned char *vram;
    unsigned long capacity;
    unsigned long used;
    vramfs_file *files;
    unsigned long file_capacity;
    unsigned long file_count;
} vramfs;

void vramfs_init(vramfs *fs,
                 void *vram,
                 unsigned long capacity,
                 vramfs_file *files,
                 unsigned long file_capacity);

int vramfs_create(vramfs *fs,
                  const char *name,
                  const void *data,
                  unsigned long size);

int vramfs_delete(vramfs *fs, const char *name);
int vramfs_write(vramfs *fs, const char *name, const void *data, unsigned long size);
int vramfs_truncate(vramfs *fs, const char *name, unsigned long new_size);

#endif
