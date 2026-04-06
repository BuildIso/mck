#ifndef MCK_TABLE_H
#define MCK_TABLE_H

#include "core.h"

typedef struct mck_table_entry {
    const char *key;
    void       *value;
} mck_table_entry;

typedef struct mck_table {
    mck_table_entry *entries;
    mck_u32 capacity;
} mck_table;

void mck_table_init(mck_table *t, mck_table_entry *buffer, mck_u32 capacity);
int  mck_table_set(mck_table *t, const char *key, void *value);
void *mck_table_get(const mck_table *t, const char *key);

#endif
