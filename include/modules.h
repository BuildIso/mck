#ifndef MODULES_H
#define MODULES_H

#include "core.h"

/* Module init function type */
typedef mck_result (*mck_module_init_fn)(void);

/* Module descriptor */
typedef struct mck_module {
    const char            *name;
    mck_module_init_fn     init;
} mck_module;

/* Public API */
mck_result modules_register(const mck_module *module);
mck_result modules_init_all(void);

#endif
