#ifndef MCK_VFS_H
#define MCK_VFS_H

/* Minimal VFS abstraction for mck */

typedef struct mck_vfs_node mck_vfs_node;

struct mck_vfs_node {
    const char *name;
    mck_vfs_node *parent;
    void *userdata;
};

typedef mck_vfs_node *(*mck_vfs_lookup_fn)(mck_vfs_node *root,
                                           const char *path);

void mck_vfs_set_root(mck_vfs_node *root);
void mck_vfs_set_lookup(mck_vfs_lookup_fn fn);

mck_vfs_node *mck_vfs_root(void);
mck_vfs_node *mck_vfs_lookup(const char *path);

#endif
