#include "utils/format.h"

char *mck_format_u32(char *buf, unsigned long value) {
    char tmp[16];
    unsigned long i = 0;
    unsigned long j;

    if (value == 0) {
        buf[0] = '0';
        buf[1] = '\0';
        return buf;
    }

    while (value > 0 && i < sizeof(tmp)) {
        tmp[i++] = (char)('0' + (value % 10UL));
        value /= 10UL;
    }

    for (j = 0; j < i; ++j) {
        buf[j] = tmp[i - 1 - j];
    }
    buf[i] = '\0';
    return buf;
}

char *mck_format_hex_u32(char *buf, unsigned long value) {
    static const char hex[] = "0123456789ABCDEF";
    char tmp[16];
    unsigned long i = 0;
    unsigned long j;

    if (value == 0) {
        buf[0] = '0';
        buf[1] = '\0';
        return buf;
    }

    while (value > 0 && i < sizeof(tmp)) {
        tmp[i++] = hex[value & 0xFUL];
        value >>= 4;
    }

    for (j = 0; j < i; ++j) {
        buf[j] = tmp[i - 1 - j];
    }
    buf[i] = '\0';
    return buf;
}
