#include "config/config.h"

static mck_config g_cfg;
static int g_has_cfg = 0;

void mck_config_set(const mck_config *cfg) {
    g_cfg = *cfg;
    g_has_cfg = 1;
}

const mck_config *mck_config_get(void) {
    if (!g_has_cfg) return 0;
    return &g_cfg;
}
