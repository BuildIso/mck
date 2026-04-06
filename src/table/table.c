#include "table/table.h"
#include "utils/string.h"

static mck_u32 mck_hash(const char *s) {
    mck_u32 h = 5381;
    char c;
    while ((c = *s++)) {
        h = ((h << 5) + h) + (mck_u32)c;
    }
    return h;
}

void mck_table_init(mck_table *t, mck_table_entry *buffer, mck_u32 capacity) {
    t->entries = buffer;
    t->capacity = capacity;
    mck_u32 i;
    for (i = 0; i < capacity; ++i) {
        t->entries[i].key = 0;
        t->entries[i].value = 0;
    }
}

int mck_table_set(mck_table *t, const char *key, void *value) {
    mck_u32 index = mck_hash(key) % t->capacity;
    mck_u32 start = index;

    do {
        if (t->entries[index].key == 0) {
            t->entries[index].key = key;
            t->entries[index].value = value;
            return 1;
        }
        if (mck_str_cmp(t->entries[index].key, key) == 0) {
            t->entries[index].value = value;
            return 1;
        }
        index = (index + 1) % t->capacity;
    } while (index != start);

    return 0;
}

void *mck_table_get(const mck_table *t, const char *key) {
    mck_u32 index = mck_hash(key) % t->capacity;
    mck_u32 start = index;

    do {
        if (t->entries[index].key == 0) return 0;
        if (mck_str_cmp(t->entries[index].key, key) == 0) {
            return t->entries[index].value;
        }
        index = (index + 1) % t->capacity;
    } while (index != start);

    return 0;
}
