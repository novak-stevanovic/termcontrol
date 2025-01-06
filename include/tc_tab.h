#ifndef TC_TAB_H
#define TC_TAB_H

#include "tc_component_base/tc_container.h"

#define TC_TAB_MAX_WINDOW_COUNT 10

typedef struct TCTab
{
    TCContainer _base;
    struct Array* _windows;
    int color;
} TCTab;

void _tc_tab_init(TCContainer* tc_container, void (*draw_func)(void*)); // for inheritance

#define TC_TAB_INIT(tc_c) _tc_tab_init(tc_c, tc_tab_draw_func);

void tc_tab_draw_func(void* tc_tab);

struct Array* tc_tab_get_windows(TCTab* tc_tab);

#endif
