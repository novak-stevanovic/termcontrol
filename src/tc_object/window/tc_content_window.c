#include <stdlib.h>

#include "tc_object/window/tc_content_window.h"
#include "base/tc_shared.h"

void _tc_content_window_init_content(TCContentWindow* content_window);

// ---------------------------------------------------------------------------------------------------

void tc_content_window_init(TCContentWindow* content_window, void (*pre_draw_func)(struct TCWindow*))
{
    tc_window_init((TCWindow*)content_window, _tc_content_window_get_content_at_func, pre_draw_func);

    _tc_content_window_init_content(content_window);
}

void tc_content_window_set_content_at(TCContentWindow* content_window, size_t x, size_t y, TCDisplayCell* content_bp)
{
    content_window->_content_buff[y][x].content = content_bp->content;
    content_window->_content_buff[y][x].bg_color = content_bp->bg_color;
    content_window->_content_buff[y][x].fg_color = content_bp->fg_color;
}

TCDisplayCell* _tc_content_window_get_content_at_func(TCWindow* cwidnow, size_t x, size_t y)
{
    TCContentWindow* tc_cont_window = (TCContentWindow*)cwidnow;
    return &(tc_cont_window->_content_buff[y][x]);
}

// ---------------------------------------------------------------------------------------------------

void _tc_content_window_init_content(TCContentWindow* content_window)
{
    content_window->_content_buff = (TCDisplayCell**)malloc(sizeof(TCDisplayCell*) * MAX_WINDOW_SIZE_Y);
    int i, j;
    for(i = 0; i < MAX_WINDOW_SIZE_Y; i++)
    {
        content_window->_content_buff[i] = (TCDisplayCell*)malloc(sizeof(TCDisplayCell) * MAX_WINDOW_SIZE_X);
        for(j = 0; j < MAX_WINDOW_SIZE_X; j++)
        {
            content_window->_content_buff[i][j].content = ' ';
            content_window->_content_buff[i][j].bg_color = TC_COLOR_RED;
            content_window->_content_buff[i][j].fg_color = TC_COLOR_WHITE;
        }
    }
}
