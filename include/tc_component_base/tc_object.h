#ifndef TC_OBJECT_H
#define TC_OBJECT_H

#include <stddef.h>

struct Array;

struct TCObject
{
    size_t start_x, start_y, end_x, end_y;

    void (*init_func)(void*);
    void (*draw_func)(void*); // arrange container or draw window on display
};

void tc_object_init(struct TCObject* tc_object, void (*init_func)(void*), void (*draw_func)(void*));

void _tc_object_init_func();

#endif

