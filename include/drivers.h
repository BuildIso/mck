#ifndef DRIVERS_H
#define DRIVERS_H

#include "core.h"

/* Driver init function type */
typedef mck_result (*mck_driver_init_fn)(void);

/* Driver descriptor */
typedef struct mck_driver {
    const char           *name;
    mck_driver_init_fn    init;
} mck_driver;

/* Public API */
mck_result drivers_register(const mck_driver *driver);
mck_result drivers_init_all(void);

#endif
