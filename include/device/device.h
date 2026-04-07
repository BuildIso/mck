#ifndef MCK_DEVICE_H
#define MCK_DEVICE_H

/* Minimal device registry for mck */

typedef struct mck_device {
    const char *name;
    void *userdata;
} mck_device;

typedef struct {
    mck_device *devices;
    unsigned long capacity;
    unsigned long count;
} mck_device_registry;

void mck_device_registry_init(mck_device_registry *reg,
                              mck_device *storage,
                              unsigned long capacity);

int mck_device_register(mck_device_registry *reg,
                        const char *name,
                        void *userdata);

mck_device *mck_device_find(mck_device_registry *reg,
                            const char *name);

#endif
