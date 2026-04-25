#include "storage/vramfs/m_vramfs.h"

static int vramfs_str_eq(const char *a, const char *b) {
    while (*a && *b) {
        if (*a != *b) return 0;
        a++;
        b++;
    }
    return *a == *b;
}

static vramfs_file *vramfs_find_mut(vramfs *fs, const char *name) {
    unsigned long i;
    for (i = 0; i < fs->file_count; i++) {
        if (fs->files[i].name && vramfs_str_eq(fs->files[i].name, name)) {
            return &fs->files[i];
        }
    }
    return 0;
}

void vramfs_init(vramfs *fs,
                 void *vram,
                 unsigned long capacity,
                 vramfs_file *files,
                 unsigned long file_capacity) {
    unsigned long i;
    fs->vram = (unsigned char *)vram;
    fs->capacity = capacity;
    fs->used = 0;
    fs->files = files;
    fs->file_capacity = file_capacity;
    fs->file_count = 0;

    for (i = 0; i < file_capacity; i++) {
        fs->files[i].name = 0;
        fs->files[i].offset = 0;
        fs->files[i].size = 0;
    }
}

int vramfs_create(vramfs *fs,
                  const char *name,
                  const void *data,
                  unsigned long size) {
    unsigned long i;
    unsigned long off;
    unsigned char *dst;
    const unsigned char *src;

    if (fs->file_count >= fs->file_capacity) return 0;
    if (fs->used + size > fs->capacity) return 0;

    for (i = 0; i < fs->file_capacity; i++) {
        if (!fs->files[i].name) {
            off = fs->used;
            dst = fs->vram + off;
            src = (const unsigned char *)data;

            while (size--) *dst++ = *src++;

            fs->files[i].name = name;
            fs->files[i].offset = off;
            fs->files[i].size = dst - (fs->vram + off);
            fs->used = fs->files[i].offset + fs->files[i].size;
            fs->file_count++;
            return 1;
        }
    }
    return 0;
}

int vramfs_delete(vramfs *fs, const char *name) {
    vramfs_file *f = vramfs_find_mut(fs, name);
    if (!f) return 0;

    if (fs->file_count > 0) fs->file_count--;

    if (f->offset + f->size == fs->used) {
        fs->used = f->offset;
    }

    f->name = 0;
    f->offset = 0;
    f->size = 0;
    return 1;
}

int vramfs_write(vramfs *fs, const char *name, const void *data, unsigned long size) {
    vramfs_file *f = vramfs_find_mut(fs, name);
    unsigned long off;
    unsigned char *dst;
    const unsigned char *src;

    if (!f) return 0;

    if (size <= f->size) {
        off = f->offset;
        dst = fs->vram + off;
        src = (const unsigned char *)data;
        while (size--) *dst++ = *src++;
        f->size = dst - (fs->vram + off);
        return 1;
    }

    if (f->offset + f->size != fs->used) return 0;
    if (f->offset + size > fs->capacity) return 0;

    off = f->offset;
    dst = fs->vram + off;
    src = (const unsigned char *)data;

    while (size--) *dst++ = *src++;

    f->size = dst - (fs->vram + off);
    fs->used = f->offset + f->size;
    return 1;
}

int vramfs_truncate(vramfs *fs, const char *name, unsigned long new_size) {
    vramfs_file *f = vramfs_find_mut(fs, name);
    unsigned long old_end;
    unsigned long new_end;

    if (!f) return 0;

    old_end = f->offset + f->size;

    if (new_size <= f->size) {
        f->size = new_size;
        if (old_end == fs->used) fs->used = f->offset + new_size;
        return 1;
    }

    new_end = f->offset + new_size;

    if (old_end != fs->used) return 0;
    if (new_end > fs->capacity) return 0;

    f->size = new_size;
    fs->used = new_end;
    return 1;
}
