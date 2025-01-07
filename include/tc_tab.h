#ifndef TC_TAB_H
#define TC_TAB_H

#include "tc_component_base/tc_container.h"
#include "tc_component_base/tc_window.h"

#define TC_TAB_MAX_WINDOW_COUNT 2

enum TCTabLayout { TC_TAB_LAYOUT_DEF_MODE, TC_TAB_LAYOUT_VSPLIT, TC_TAB_LAYOUT_HSPLIT };

typedef struct TCTab
{
    TCContainer _base;
    struct Array* _windows;
    enum TCTabLayout _layout;
} TCTab;

void _tc_tab_init(TCTab* tc_tab, void (*draw_func)(void*)); // for inheritance

void tc_tab_init(TCTab* tc_tab); // constructor

void tc_tab_draw_func(void* tc_tab);

struct Array* tc_tab_get_window_at(TCTab* tc_tab, size_t idx);
struct Array* tc_tab_set_window_at(TCTab* tc_tab, size_t idx);
void tc_tab_add_window(TCTab* tc_tab, TCWindow* tc_window);
void tc_tab_remove_window(TCTab* tc_tab, TCWindow* tc_window);
void tc_tab_remove_window_at(TCTab* tc_tab, size_t idx);

enum TCTabLayout tc_tab_get_layout(TCTab* tc_tab);
void tc_tab_set_layout(TCTab* tc_tab, enum TCTabLayout layout);

#endif
