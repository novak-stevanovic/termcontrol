#ifndef TC_TAB_H
#define TC_TAB_H

#include "tc_object/container/tc_layout_container.h"

#define TC_TAB_MAX_WINDOW_COUNT 2

typedef struct TCTab
{
    TCLayoutContainer _base;
    struct Array* _windows;
} TCTab;

void tc_tab_init(TCTab* tc_tab); // constructor

#endif
