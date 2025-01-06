#include "tc_tab.h"
#include "array.h"
#include "tc_component_base/tc_window.h"

void tc_tab_init(TCTab* tc_tab, int color)
{
    tc_container_init((TCContainer*)tc_tab, tc_tab_draw_func);
    tc_tab->_windows = arr_init(TC_TAB_MAX_WINDOW_COUNT, sizeof(TCWindow*));
    tc_tab->color = color;
}

void tc_tab_draw_func(void* tc_tab)
{
}

struct Array* tc_tab_get_windows(TCTab* tc_tab)
{
    return tc_tab->_windows;
}
