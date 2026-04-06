#ifndef MCK_LOG_H
#define MCK_LOG_H

#include "core.h"

typedef enum mck_log_level {
    MCK_LOG_INFO,
    MCK_LOG_WARN,
    MCK_LOG_ERROR
} mck_log_level;

void mck_log_set_callback(mck_log_fn fn);
void mck_log_msg(mck_log_level level, const char *msg);

#endif
