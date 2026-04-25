#include "storage/ramfs.h"

static ramfs_file *g_files;
static unsigned long g_count;

static int cmp(const char *a, const char *b) {
    while (*a && *b) {
        if (*a != *b) return 0;
        a++;
        b++;
    }
    return *a == *b;
}

void ramfs_init(ramfs_file *files, unsigned long count) {
    g_files = files;
    g_count = count;
}

const ramfs_file *ramfs_get(const char *name) {
    unsigned long i;
    for (i = 0; i < g_count; i++) {
        if (cmp(g_files[i].name, name)) return &g_files[i];
    }
    return 0;
}
