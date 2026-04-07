#ifndef MCK_UTILS_FORMAT_H
#define MCK_UTILS_FORMAT_H

/* Minimal integer-to-string formatting for mck */

char *mck_format_u32(char *buf, unsigned long value);
char *mck_format_hex_u32(char *buf, unsigned long value);

#endif
