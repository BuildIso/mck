#include "storage/vramfs/q_vramfs.h"

static int vramfs_str_eq_q(const char *a, const char *b) {
    while (*a && *b) {
        if (*a != *b) return 0;
        a++;
        b++;
    }
    return *a == *b;
}

const vramfs_file *vramfs_find(vramfs *fs, const char *name) {
    unsigned long i;
    for (i = 0; i < fs->file_count; i++) {
        if (fs->files[i].name && vramfs_str_eq_q(fs->files[i].name, name)) {
            return &fs->files[i];
        }
    }
    return 0;
}

unsigned long vramfs_file_count(vramfs *fs) {
    return fs->file_count;
}

unsigned long vramfs_used(vramfs *fs) {
    return fs->used;
}

unsigned long vramfs_free(vramfs *fs) {
    if (fs->capacity < fs->used) return 0;
    return fs->capacity - fs->used;
}
