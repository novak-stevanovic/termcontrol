#ifndef TC_CONTAINER_H
#define TC_CONTAINER_H

#include "tc_object/tc_object.h"

typedef struct TCContainer // "ABSTRACT"
{
    TCObject _base;
    struct Vector* _children;
} TCContainer;

void tc_container_init(TCContainer* container, void (*draw_func)(void*));

struct Vector* tc_container_get_children(TCContainer* container);

struct Vector* _tc_container_get_next_to_draw_func(void* container);

#endif
