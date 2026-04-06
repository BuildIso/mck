#ifndef CORE_H
#define CORE_H

/* Basic fixed-size types (C89-compatible) */
typedef unsigned char  mck_u8;
typedef unsigned short mck_u16;
typedef unsigned long  mck_u32;

/* Generic result codes */
typedef enum mck_result {
    MCK_OK = 0,
    MCK_ERROR = 1,
    MCK_INVALID_ARGUMENT = 2,
    MCK_OUT_OF_SPACE = 3
} mck_result;

/* Logging callback type */
typedef void (*mck_log_fn)(const char *message);

/* Core API */
void        core_init(void);
int         core_is_ready(void);
void        core_set_logger(mck_log_fn logger);
void        core_log(const char *message);

#endif
