#ifndef TC_CONTAINER_H
#define TC_CONTAINER_H

#include "tc_component_base/tc_object.h"

struct TCContainer
{
    struct TCObject tc_base;
    struct Vector* children;
};

void tc_container_init(struct TCContainer* tc_container, void (*init_func)(void*), void (*draw_func)(void*));

void tc_container_draw(void* tc_container);

#endif
