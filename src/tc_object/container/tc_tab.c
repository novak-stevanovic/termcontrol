#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "tc_object/container/tc_tab.h"
#include "array.h"
#include "layout/tc_tab_layout_manager.h"
#include "tc_object/window/tc_content_window.h"

void tc_tab_init(TCTab* tab)
{
    assert(tab != NULL);
    TCTabLayoutManager* tab_lm = (TCTabLayoutManager*)malloc(sizeof(TCTabLayoutManager));
    assert(tab_lm != NULL);
    tc_tab_lm_init(tab_lm, tab);

    tc_lc_init((TCLayoutContainer*)tab, (TCLayoutManager*)tab_lm);
    tab->_windows = arr_init(TC_TAB_MAX_WINDOW_COUNT, sizeof(TCContentWindow));
    assert(tab->_windows != NULL);

    tc_tab_add_window(tab);
}

size_t tc_tab_get_window_idx(TCTab* tab, TCContentWindow* window)
{
    assert(tab != NULL);
    assert(window != NULL);

    int i;
    TCContentWindow* curr_win;
    for(i = 0; i < arr_get_count(tab->_windows); i++)
    {
        curr_win = arr_at(tab->_windows, i);

        if(window == curr_win)
            return i;
    }

    assert(1 != 1);
}

void tc_tab_add_window(TCTab* tab)
{
    assert(tab != NULL);
    assert(arr_get_count(tab->_windows) <= TC_TAB_MAX_WINDOW_COUNT);

    TCContentWindow new_window;
    tc_content_window_init(&new_window);

    arr_append(tab->_windows, &new_window);

    tc_object_draw((TCObject*)tab);
}

void tc_tab_remove_window(TCTab* tab, size_t idx)
{
    assert(tab != NULL);
    assert(idx < arr_get_count(tab->_windows));
    assert(arr_get_count(tab->_windows) > 1);

    arr_remove(tab->_windows, idx);

    tc_object_draw((TCObject*)tab);
}
