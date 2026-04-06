#include "drivers.h"

#define MCK_MAX_DRIVERS 16

static const mck_driver *g_drivers[MCK_MAX_DRIVERS];
static mck_u32           g_driver_count = 0;

mck_result drivers_register(const mck_driver *driver) {
    if (!driver || !driver->init || !driver->name) {
        return MCK_INVALID_ARGUMENT;
    }

    if (g_driver_count >= MCK_MAX_DRIVERS) {
        return MCK_OUT_OF_SPACE;
    }

    g_drivers[g_driver_count] = driver;
    g_driver_count++;

    core_log("[drivers] registered driver");
    return MCK_OK;
}

mck_result drivers_init_all(void) {
    mck_u32 i;
    mck_result res;

    core_log("[drivers] initializing all drivers...");

    for (i = 0; i < g_driver_count; ++i) {
        res = g_drivers[i]->init();
        if (res != MCK_OK) {
            core_log("[drivers] driver init failed");
            return res;
        }
    }

    core_log("[drivers] all drivers initialized");
    return MCK_OK;
}
