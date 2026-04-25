#ifndef STORAGE_VRAMFS_Q_VRAMFS_H
#define STORAGE_VRAMFS_Q_VRAMFS_H

#include "storage/vramfs/m_vramfs.h"

const vramfs_file *vramfs_find(vramfs *fs, const char *name);

unsigned long vramfs_file_count(vramfs *fs);
unsigned long vramfs_used(vramfs *fs);
unsigned long vramfs_free(vramfs *fs);

#endif
