#include "vfs/vfs.h"

static mck_vfs_node *g_root = 0;
static mck_vfs_lookup_fn g_lookup = 0;

void mck_vfs_set_root(mck_vfs_node *root) {
    g_root = root;
}

void mck_vfs_set_lookup(mck_vfs_lookup_fn fn) {
    g_lookup = fn;
}

mck_vfs_node *mck_vfs_root(void) {
    return g_root;
}

mck_vfs_node *mck_vfs_lookup(const char *path) {
    if (g_lookup && g_root && path) {
        return g_lookup(g_root, path);
    }
    return 0;
}
