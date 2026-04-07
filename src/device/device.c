#include "device/device.h"

void mck_device_registry_init(mck_device_registry *reg,
                              mck_device *storage,
                              unsigned long capacity) {
    reg->devices = storage;
    reg->capacity = capacity;
    reg->count = 0;
}

int mck_device_register(mck_device_registry *reg,
                        const char *name,
                        void *userdata) {
    mck_device *dev;

    if (reg->count >= reg->capacity) {
        return 0;
    }

    dev = &reg->devices[reg->count++];
    dev->name = name;
    dev->userdata = userdata;
    return 1;
}

mck_device *mck_device_find(mck_device_registry *reg,
                            const char *name) {
    unsigned long i;

    for (i = 0; i < reg->count; ++i) {
        const char *a = reg->devices[i].name;
        const char *b = name;
        if (!a || !b) {
            continue;
        }
        while (*a && *b && *a == *b) {
            ++a;
            ++b;
        }
        if (*a == 0 && *b == 0) {
            return &reg->devices[i];
        }
    }
    return 0;
}
