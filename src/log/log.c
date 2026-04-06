#include "log/log.h"

static mck_log_fn g_callback = 0;

void mck_log_set_callback(mck_log_fn fn) {
    g_callback = fn;
}

void mck_log_msg(mck_log_level level, const char *msg) {
    if (!g_callback) return;

    switch (level) {
        case MCK_LOG_INFO:  g_callback("[info] ");  break;
        case MCK_LOG_WARN:  g_callback("[warn] ");  break;
        case MCK_LOG_ERROR: g_callback("[error] "); break;
    }

    g_callback(msg);
}
