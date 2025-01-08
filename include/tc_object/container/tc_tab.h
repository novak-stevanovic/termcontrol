#ifndef TC_TAB_H
#define TC_TAB_H

#include "tc_object/container/tc_layout_container.h"
#include "tc_object/window/tc_content_window.h"

#define TC_TAB_MAX_WINDOW_COUNT 2

struct Array;

typedef struct TCTab
{
    TCLayoutContainer _base;
    struct Array* _windows;
} TCTab;

void tc_tab_init(TCTab* tab); // constructor

size_t tc_tab_get_window_idx(TCTab* tab, TCContentWindow* window);
void tc_tab_add_window(TCTab* tab);
void tc_tab_remove_window(TCTab* tab, size_t idx);

#endif
