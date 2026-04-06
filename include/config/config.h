#ifndef MCK_CONFIG_H
#define MCK_CONFIG_H

#include "core.h"

typedef struct mck_config {
    const char *project_name;
    mck_u32     version_major;
    mck_u32     version_minor;
    mck_u32     version_patch;
} mck_config;

void mck_config_set(const mck_config *cfg);
const mck_config *mck_config_get(void);

#endif
