#ifndef MCK_LIST_H
#define MCK_LIST_H

#include "core.h"

typedef struct mck_list {
    void   **items;
    mck_u32 capacity;
    mck_u32 count;
} mck_list;

void mck_list_init(mck_list *list, void **buffer, mck_u32 capacity);
mck_result mck_list_push(mck_list *list, void *item);

#endif
