#ifndef TC_OBJECT_H
#define TC_OBJECT_H

#include <stddef.h>

struct Array;

struct TCObject
{
    size_t start_x, start_y, end_x, end_y;

    void (*init_func)(void*);
    void (*draw_func)(void*); // arrange container or draw window
};

void tc_object_init(struct TCObject* tc_object, void (*init_func)(void*), void (*draw_func)(void*));
// struct TCBase* tc_object_dyn_init(void (*init_func)(void*), void (*draw_func)(void*));
    

#endif

