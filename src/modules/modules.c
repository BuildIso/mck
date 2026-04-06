#include "modules.h"

#define MCK_MAX_MODULES 16

static const mck_module *g_modules[MCK_MAX_MODULES];
static mck_u32           g_module_count = 0;

mck_result modules_register(const mck_module *module) {
    if (!module || !module->init || !module->name) {
        return MCK_INVALID_ARGUMENT;
    }

    if (g_module_count >= MCK_MAX_MODULES) {
        return MCK_OUT_OF_SPACE;
    }

    g_modules[g_module_count] = module;
    g_module_count++;

    core_log("[modules] registered module");
    return MCK_OK;
}

mck_result modules_init_all(void) {
    mck_u32 i;
    mck_result res;

    core_log("[modules] initializing all modules...");

    for (i = 0; i < g_module_count; ++i) {
        res = g_modules[i]->init();
        if (res != MCK_OK) {
            core_log("[modules] module init failed");
            return res;
        }
    }

    core_log("[modules] all modules initialized");
    return MCK_OK;
}
