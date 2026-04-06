#include "core.h"
#include "drivers.h"
#include "modules.h"
#include <stdio.h>

/* Simple logger using printf (hosted only) */
static void mck_stdout_logger(const char *message) {
    printf("%s\n", message);
}

/* Example driver */
static mck_result example_driver_init(void) {
    core_log("[example_driver] init");
    return MCK_OK;
}

static const mck_driver example_driver = {
    "example_driver",
    example_driver_init
};

/* Example module */
static mck_result example_module_init(void) {
    core_log("[example_module] init");
    return MCK_OK;
}

static const mck_module example_module = {
    "example_module",
    example_module_init
};

int main(void) {
    mck_result res;

    core_set_logger(mck_stdout_logger);
    core_init();

    if (!core_is_ready()) {
        printf("[error] core not ready\n");
        return 1;
    }

    res = drivers_register(&example_driver);
    if (res != MCK_OK) {
        printf("[error] failed to register driver\n");
        return 1;
    }

    res = modules_register(&example_module);
    if (res != MCK_OK) {
        printf("[error] failed to register module\n");
        return 1;
    }

    res = drivers_init_all();
    if (res != MCK_OK) {
        printf("[error] driver init failed\n");
        return 1;
    }

    res = modules_init_all();
    if (res != MCK_OK) {
        printf("[error] module init failed\n");
        return 1;
    }

    printf("mck is ready.\n");
    return 0;
}
