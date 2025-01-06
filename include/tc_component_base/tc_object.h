#ifndef TC_OBJECT_H
#define TC_OBJECT_H

#include <stddef.h>

struct Array;

typedef struct TCObject
{
    size_t start_x, start_y, end_x, end_y;

    void (*_draw_func)(void*); // arrange container or draw window on display
} TCObject;

void tc_object_init(TCObject* tc_object, void (*draw_func)(void*));

void tc_object_set_positions(TCObject* tc_object, size_t start_x, size_t start_y, size_t end_x, size_t end_y);

#endif

