#ifndef TC_TAB_MANEGER_H
#define TC_TAB_MANEGER_H

#include "tc_object/container/tc_layout_container.h"
#include "tc_object/container/tc_tab.h"

#define TC_TAB_MANAGER_MAX_TAB_COUNT 5

typedef struct TCTabManager
{
    TCLayoutContainer _base;
    struct Array* _tabs;
    size_t active_tab_idx;
} TCTabManager;

void tc_root_init(TCTabManager* root);

size_t tc_root_get_tab_idx(TCTabManager* tab_manager, TCTab* tab);
void tc_root_add_tab(TCTabManager* tab_manager);
void tc_root_remove_tab(TCTabManager* tab_manager, size_t idx);

#endif
