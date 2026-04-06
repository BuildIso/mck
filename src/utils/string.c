#include "utils/string.h"

mck_u32 mck_str_len(const char *s) {
    mck_u32 len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

int mck_str_cmp(const char *a, const char *b) {
    while (*a && *b) {
        if (*a != *b) {
            return (*a < *b) ? -1 : 1;
        }
        a++;
        b++;
    }
    if (*a == *b) return 0;
    return (*a < *b) ? -1 : 1;
}
