#ifndef TC_LAYOUT_CONTAINER_H
#define TC_LAYOUT_CONTAINER_H

#include "tc_object/container/tc_container.h"

struct TCLayoutManager;

typedef struct TCLayoutContainer // "ABSTRACT"
{
    TCContainer _base;
    struct TCLayoutManager* _layout_manager;
} TCLayoutContainer;

void tc_lc_init(TCLayoutContainer* layout_container, struct TCLayoutManager* layout_manager); // constructor
void tc_lc_draw_func(void* layout_container);

#endif
