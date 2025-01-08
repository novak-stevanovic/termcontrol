#ifndef TC_LAYOUT_CONTAINER_H
#define TC_LAYOUT_CONTAINER_H

#include "tc_object/container/tc_container.h"
#include "tc_object/tc_object.h"

struct Vector;
struct TCLayoutManager;

typedef struct TCLayoutContainer // "ABSTRACT"
{
    TCContainer _base;
    struct TCLayoutManager* _layout_manager;
} TCLayoutContainer;

void tc_layout_container_init(TCContainer* container, struct TCLayoutManager* layout_manager); // constructor
void tc_layout_container_draw_func(void* container);

#endif
