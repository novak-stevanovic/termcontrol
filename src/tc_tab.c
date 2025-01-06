#include "tc_tab.h"
#include "array.h"
#include "tc_component_base/tc_window.h"
#include "assert.h"
#include <stdio.h>

void _tc_tab_set_window_positions(TCTab* tc_tab)
{
    assert(tc_tab != NULL);
    assert(arr_get_count(tc_tab->_windows) > 0);

    TCWindow* first_window = arr_at(tc_tab->_windows, 0);
    TCObject* first_window_obj = (TCObject*)first_window;
    TCObject* tc_tab_obj = (TCObject*)tc_tab;

    if(tc_tab->_layout == TC_TAB_LAYOUT_DEF_MODE)
    {
        tc_object_set_positions(first_window_obj,
                tc_tab_obj->start_x,
                tc_tab_obj->start_y,
                tc_tab_obj->end_x,
                tc_tab_obj->end_y);
    }
    else
    {
        assert(arr_get_count(tc_tab->_windows) == 2);

        struct TCWindow* second_window = arr_at(tc_tab->_windows, 1);
        TCObject* second_window_obj = (TCObject*)second_window;

        if(tc_tab->_layout == TC_TAB_LAYOUT_HSPLIT)
        {
            tc_object_set_positions(first_window_obj,
                    tc_tab_obj->start_x,
                    tc_tab_obj->start_y, 
                    tc_tab_obj->end_x,
                    tc_tab_obj->end_y / 2);

            tc_object_set_positions(second_window_obj,
                    tc_tab_obj->start_x,
                    tc_tab_obj->end_y / 2 + 1,
                    tc_tab_obj->end_x,
                    tc_tab_obj->end_y);
        }
        else if(tc_tab->_layout == TC_TAB_LAYOUT_VSPLIT)
        {
            tc_object_set_positions(first_window_obj,
                    tc_tab_obj->start_x,
                    tc_tab_obj->start_y, 
                    tc_tab_obj->end_x / 2,
                    tc_tab_obj->end_y);

            tc_object_set_positions(second_window_obj,
                    tc_tab_obj->end_x / 2 + 1,
                    tc_tab_obj->start_y,
                    tc_tab_obj->end_x,
                    tc_tab_obj->end_y);
        }
        else
        {
            printf("EXITING1\n");
            exit(1);
        }
    }
}

void _tc_tab_init(TCTab* tc_tab, void (*draw_func)(void*))
{
    tc_container_init((TCContainer*)tc_tab, draw_func);
    tc_tab->_windows = arr_init(TC_TAB_MAX_WINDOW_COUNT, sizeof(TCWindow*));
    // LAYOUT
}

void tc_tab_init(TCTab* tc_tab)
{
    assert(tc_tab != NULL);

    tc_container_init((TCContainer*)tc_tab, tc_tab_draw_func);
}

void tc_tab_draw_func(void* tc_tab)
{
    assert(tc_tab != NULL);
}

struct Array* tc_tab_get_windows(TCTab* tc_tab)
{
    assert(tc_tab != NULL);
    return tc_tab->_windows;
}

enum TCTabLayout tc_tab_get_layout(TCTab* tc_tab)
{
    assert(tc_tab != NULL);

    return tc_tab->_layout;
}

void tc_tab_set_layout(TCTab* tc_tab, enum TCTabLayout layout)
{
    assert(tc_tab != NULL);

    tc_tab->_layout = layout;
}
