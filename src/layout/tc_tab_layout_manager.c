#include <assert.h>

#include "layout/tc_tab_layout_manager.h"
#include "array.h"
#include "tc_object/container/tc_tab.h"

void tc_tab_lm_init(TCTabLayoutManager* tab_lm, TCTab* tab)
{
    assert(tab != NULL);
    assert(tab_lm != NULL);

    tc_lm_init((TCLayoutManager*)tab_lm, (TCLayoutContainer*)tab, _tc_tab_lm_arrange_func);
    tab_lm->left = NULL;
    tab_lm->right = NULL;
}

void _tc_tab_lm_arrange_func(TCLayoutManager* tab_lm)
{
    assert(tab_lm != NULL);

    TCTab* tab = (TCTab*)tab_lm->_container;
    TCObject* tab_obj = (TCObject*)tab;

    size_t window_count = arr_get_count(tab->_windows);

    assert(window_count != 0);

    if(window_count == 1)
    {
        TCContentWindow* win = (TCContentWindow*)arr_at(tab->_windows, 0);
        TCObject* win_obj = (TCObject*)win;

        win_obj->start_x = tab_obj->start_x;
        win_obj->start_y = tab_obj->start_y;
        win_obj->end_x = tab_obj->end_x;
        win_obj->end_y = tab_obj->end_y;
    }
    else
    {
        TCContentWindow* left_win = (TCContentWindow*)arr_at(tab->_windows, 0);
        TCContentWindow* right_win = (TCContentWindow*)arr_at(tab->_windows, 1);

        TCObject* left_win_obj = (TCObject*)left_win;
        TCObject* right_win_obj = (TCObject*)right_win;

        left_win_obj->start_x = tab_obj->start_x;
        left_win_obj->start_y = tab_obj->start_y;
        left_win_obj->end_x = tab_obj->end_x / 2 - 1;
        left_win_obj->end_y = tab_obj->start_y;

        right_win_obj->start_x = tab_obj->end_x / 2 + 1;
        right_win_obj->start_y = tab_obj->start_y;
        right_win_obj->end_x = tab_obj->end_x;
        right_win_obj->end_y = tab_obj->start_y;
    }
}
