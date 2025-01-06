#ifndef TC_TAB_H
#define TC_TAB_H

#include "tc_component_base/tc_container.h"

struct TCTab
{
    struct TCContainer tc_container;
    int color;
};

void tc_tab_init(struct TCTab* tc_tab, int color);

void tc_tab_init_func(void* tc_tab);
void tc_tab_draw_func(void* tc_tab);

#endif
