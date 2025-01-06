#ifndef TC_OBJECT_H
#define TC_OBJECT_H

#include <stddef.h>

struct Array;

typedef struct TCObject
{
    size_t start_x, start_y, end_x, end_y;

    // void (*init_func)(void*);
    void (*_draw_func)(void*); // arrange container or draw window on display
} TCObject;

// void tc_object_init(TCObject* tc_object, void (*init_func)(void*), void (*draw_func)(void*));
void tc_object_init(TCObject* tc_object, void (*draw_func)(void*));

void _tc_object_init_func();

#endif

