#include <stdlib.h>

#include "tc_object/window/tc_content_window.h"
#include "base/tc_shared.h"

void _tc_content_window_init_content(TCContentWindow* tc_cwindow);

// ---------------------------------------------------------------------------------------------------

void _tc_content_window_init(TCContentWindow* tc_cwindow,
        void (*draw_func)(void*),
        TCDisplayCell* (*get_content_at_func)(TCWindow*, size_t, size_t))
{
    _tc_window_init((TCWindow*)tc_cwindow, draw_func, get_content_at_func);
    _tc_content_window_init_content(tc_cwindow);
}

void tc_content_window_init(TCContentWindow* tc_cwindow)
{
    _tc_content_window_init(tc_cwindow, tc_window_draw_func, _tc_content_window_get_content_at_func);
}

void _tc_content_window_set_content_at(TCContentWindow* tc_cwindow, size_t x, size_t y, TCDisplayCell* content_bp)
{
    tc_cwindow->_content[y][x].content = content_bp->content;
    tc_cwindow->_content[y][x].bg_color = content_bp->bg_color;
    tc_cwindow->_content[y][x].fg_color = content_bp->fg_color;
}

TCDisplayCell* _tc_content_window_get_content_at_func(TCWindow* tc_cwindow, size_t x, size_t y)
{
    TCContentWindow* tc_cont_window = (TCContentWindow*)tc_cwindow;
    return &(tc_cont_window->_content[y][x]);
}

// ---------------------------------------------------------------------------------------------------

void _tc_content_window_init_content(TCContentWindow* tc_cwindow)
{
    tc_cwindow->_content = (TCDisplayCell**)malloc(sizeof(TCDisplayCell*) * MAX_WINDOW_SIZE_Y);
    int i, j;
    for(i = 0; i < MAX_WINDOW_SIZE_Y; i++)
    {
        tc_cwindow->_content[i] = (TCDisplayCell*)malloc(sizeof(TCDisplayCell) * MAX_WINDOW_SIZE_X);
        for(j = 0; j < MAX_WINDOW_SIZE_X; j++)
        {
            tc_cwindow->_content[i][j].content = 'u';
            tc_cwindow->_content[i][j].bg_color = TC_COLOR_RED;
            tc_cwindow->_content[i][j].fg_color = TC_COLOR_BLACK;
        }
    }
}
