#include "tc_component_base/tc_window.h"
#include "tc_component_base/tc_object.h"

#include "base/tc_shared.h"
#include "vector.h"

// void _tc_window_init_base(TCWindow* tc_window, void (*init_func)(void*), void (*draw_func)(void*))
// {
//     tc_object_init(&tc_window->tc_object, init_func, draw_func);
//
//     tc_window->content = (TCDisplayCell**)malloc(sizeof(TCDisplayCell*) * MAX_WINDOW_SIZE_Y);
//     int i, j;
//     for(i = 0; i < MAX_WINDOW_SIZE_Y; i++)
//     {
//         tc_window->content[i] = (TCDisplayCell*)malloc(sizeof(TCDisplayCell) * MAX_WINDOW_SIZE_X);
//         for(j = 0; j < MAX_WINDOW_SIZE_X; j++)
//         {
//             tc_window->content[i][j].content = 'u';
//             tc_window->content[i][j].bg_color = TC_COLOR_RED;
//             tc_window->content[i][j].fg_color = TC_COLOR_BLACK;
//         }
//     }
// }

void tc_window_init(
        TCWindow* tc_window, 
        void (*draw_func)(void*),
        TCDisplayCell* (*get_content_at_func)(struct TCWindow*, size_t, size_t),
        void (*set_content_at_func)(struct TCWindow*, TCDisplayCell, size_t, size_t))
{
    tc_object_init((TCObject*)tc_window, draw_func);
    tc_window->get_content_at_func = get_content_at_func;
    tc_window->set_content_at_func = set_content_at_func;
}

