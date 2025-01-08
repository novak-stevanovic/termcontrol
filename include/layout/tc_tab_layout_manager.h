#ifndef TC_TAB_LAYOUT_MANAGER_H
#define TC_TAB_LAYOUT_MANAGER_H

#include "tc_layout_manager.h"
#include "tc_object/container/tc_tab.h"

struct TCWindow;

typedef struct TCTabLayoutManager
{
    struct TCLayoutManager _base;
    struct TCWindow *left, *right;
} TCTabLayoutManager;

void tc_tab_lm_init(TCTabLayoutManager* tab_lm, TCTab* tab);

void _tc_tab_lm_arrange_func(TCLayoutManager* tab_lm);

#endif
