#ifndef TC_CONTAINER_H
#define TC_CONTAINER_H

#include "tc_component_base/tc_object.h"

typedef struct TCContainer
{
    TCObject _base;
    struct Vector* _children;
} TCContainer;

void tc_container_init(TCContainer* tc_container, void (*draw_func)(void*));

struct Vector* tc_container_get_children(TCContainer* tc_container);

#endif
