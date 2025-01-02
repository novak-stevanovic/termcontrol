#ifndef TC_CONTAINER_H
#define TC_CONTAINER_H

#include "base/tc_object.h"

#define TC_CONTAINER_MAX_CHILDREN 20

struct TCContainer
{
    struct TCObject tc_base;
    struct Vector* children;
};

void tc_container_init(struct TCContainer* tc_container, void (*init_func)(void*), void (*draw_func)(void*));

void tc_container_draw(void* tc_container);

#endif
