#include <stdlib.h>

#include "tc_component_base/tc_window.h"
#include "base/tc_display.h"
#include "base/tc_shared.h"
#include "tc_component_base/tc_object.h"

// ------------------------------------------------------------------------------------------------------------------------------------

void _tc_window_init_content(TCWindow* tc_window);

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

void _tc_window_init(TCWindow* tc_window, void (*draw_func)(void*))
{
    tc_object_init((TCObject*)tc_window, draw_func);
    _tc_window_init_content(tc_window);
    
}

void tc_window_init(TCWindow* tc_window)
{
    _tc_window_init(tc_window, tc_window_draw_func);
}

void tc_window_draw_func(void* tc_window)
{
    tc_display_draw_tc_window(tc_window);
}

TCDisplayCell* tc_window_get_content_at(TCWindow* tc_window, size_t x, size_t y)
{
    return &tc_window->_content[y][x];
}
void tc_window_set_content_at(TCWindow* tc_window, size_t x, size_t y, TCDisplayCell* new_content_bp)
{
    tc_window->_content[y][x] = *new_content_bp;
}

// ------------------------------------------------------------------------------------------------------------------------------------

void _tc_window_init_content(TCWindow* tc_window)
{
    tc_window->_content = (TCDisplayCell**)malloc(sizeof(TCDisplayCell*) * MAX_WINDOW_SIZE_Y);
    int i, j;
    for(i = 0; i < MAX_WINDOW_SIZE_Y; i++)
    {
        tc_window->_content[i] = (TCDisplayCell*)malloc(sizeof(TCDisplayCell) * MAX_WINDOW_SIZE_X);
        for(j = 0; j < MAX_WINDOW_SIZE_X; j++)
        {
            tc_window->_content[i][j].content = 'u';
            tc_window->_content[i][j].bg_color = TC_COLOR_RED;
            tc_window->_content[i][j].fg_color = TC_COLOR_BLACK;
        }
    }
}
