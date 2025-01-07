#include <stdio.h>
#include <assert.h>

#include "tc_object/container/tc_tab.h"
#include "array.h"
#include "tc_object/window/tc_window.h"

// void _tc_tab_init(TCTab* tc_tab, void (*draw_func)(void*))
// {
//     assert(tc_tab != NULL);
//     assert(draw_func != NULL);
//
//     _tc_container_init((TCContainer*)tc_tab, draw_func);
//     tc_tab->_windows = arr_init(TC_TAB_MAX_WINDOW_COUNT, sizeof(TCWindow*));
// }
//
// void tc_tab_init(TCTab* tc_tab)
// {
//     assert(tc_tab != NULL);
//     _tc_tab_init(tc_tab, tc_container_draw_func);
// }

// TCWindow* tc_tab_get_window_at(TCTab* tc_tab, size_t idx)
// {
//     assert(tc_tab != NULL);
//
//     return *(TCWindow**)arr_at(tc_tab->_windows, idx);
// }
//
// TCWindow* tc_tab_add_window(TCTab* tc_tab)
// {
//     assert(tc_tab != NULL);
//
//     TCWindow* tc_w = (TCWindow*)malloc(sizeof(TCWindow));
//     tc_window_init(tc_w);
//     arr_append(tc_tab->_windows, &tc_w);
//
//     return tc_w;
// }
//
// void tc_tab_remove_window(TCTab* tc_tab, TCWindow* tc_window)
// {
//     assert(tc_tab != NULL);
//     assert(tc_window != NULL);
//
//     int i;
//     TCWindow* curr_win;
//     for(i = 0; i < arr_get_count(tc_tab->_windows); i++)
//     {
//         curr_win = arr_at(tc_tab->_windows, i);
//         if(curr_win == tc_window)
//         {
//             arr_remove(tc_tab->_windows, i);
//             free(tc_window);
//             return;
//         }
//
//     }
//
//     assert(1 != 1);
// }

// ----------------------------------------------------------------------------------------------------------------

// void _tc_tab_position_windows(TCTab* tc_tab)
// {
//     assert(tc_tab != NULL);
//     assert(arr_get_count(tc_tab->_windows) > 0);
//
//     TCWindow* first_window = arr_at(tc_tab->_windows, 0);
//     TCObject* first_window_obj = (TCObject*)first_window;
//     TCObject* tc_tab_obj = (TCObject*)tc_tab;
//
//     if(tc_tab->_layout == TC_TAB_LAYOUT_SINGLE_WIN)
//     {
//         tc_object_set_positions(first_window_obj,
//                 tc_tab_obj->start_x,
//                 tc_tab_obj->start_y,
//                 tc_tab_obj->end_x,
//                 tc_tab_obj->end_y);
//     }
//     else
//     {
//         assert(arr_get_count(tc_tab->_windows) == 2);
//
//         struct TCWindow* second_window = arr_at(tc_tab->_windows, 1);
//         TCObject* second_window_obj = (TCObject*)second_window;
//
//         if(tc_tab->_layout == TC_TAB_LAYOUT_HSPLIT)
//         {
//             tc_object_set_positions(first_window_obj,
//                     tc_tab_obj->start_x,
//                     tc_tab_obj->start_y, 
//                     tc_tab_obj->end_x,
//                     tc_tab_obj->end_y / 2);
//
//             tc_object_set_positions(second_window_obj,
//                     tc_tab_obj->start_x,
//                     tc_tab_obj->end_y / 2 + 1,
//                     tc_tab_obj->end_x,
//                     tc_tab_obj->end_y);
//         }
//         else if(tc_tab->_layout == TC_TAB_LAYOUT_VSPLIT)
//         {
//             tc_object_set_positions(first_window_obj,
//                     tc_tab_obj->start_x,
//                     tc_tab_obj->start_y, 
//                     tc_tab_obj->end_x / 2,
//                     tc_tab_obj->end_y);
//
//             tc_object_set_positions(second_window_obj,
//                     tc_tab_obj->end_x / 2 + 1,
//                     tc_tab_obj->start_y,
//                     tc_tab_obj->end_x,
//                     tc_tab_obj->end_y);
//         }
//         else
//         {
//             printf("EXITING1\n");
//             exit(1);
//         }
//     }
// }
