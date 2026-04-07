#include "crypto/crc32.h"

unsigned long mck_crc32(const void *data, unsigned long size) {
    const unsigned char *p = (const unsigned char *)data;
    unsigned long crc = 0xFFFFFFFFUL;
    unsigned long i, j;

    for (i = 0; i < size; ++i) {
        crc ^= (unsigned long)p[i];
        for (j = 0; j < 8; ++j) {
            if (crc & 1UL) {
                crc = (crc >> 1) ^ 0xEDB88320UL;
            } else {
                crc >>= 1;
            }
        }
    }

    return crc ^ 0xFFFFFFFFUL;
}
