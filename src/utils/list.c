#include "utils/list.h"

void mck_list_init(mck_list *list, void **buffer, mck_u32 capacity) {
    list->items = buffer;
    list->capacity = capacity;
    list->count = 0;
}

mck_result mck_list_push(mck_list *list, void *item) {
    if (list->count >= list->capacity) {
        return MCK_OUT_OF_SPACE;
    }
    list->items[list->count++] = item;
    return MCK_OK;
}
