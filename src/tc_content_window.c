#include <stdlib.h>

#include "tc_content_window.h"
#include "base/tc_display.h"
#include "base/tc_shared.h"

void _tc_content_window_init_content(TCContentWindow* tc_window);

// --------------------------------------------------------------------------------

void _tc_content_window_init( // for inheritance
        TCContentWindow* tc_content_window, 
        void (*draw_func)(void*),
        TCDisplayCell* (*get_content_at_func)(struct TCWindow*, size_t, size_t),
        void (*set_content_at_func)(struct TCWindow*, TCDisplayCell, size_t, size_t))
{
    _tc_window_init((TCWindow*)tc_content_window, draw_func, get_content_at_func, set_content_at_func);
}

void tc_content_window_init(TCContentWindow* tc_content_window)
{
    _tc_content_window_init(tc_content_window,
            tc_window_draw_func,
            _tc_content_window_get_content_at_func,
            _tc_content_window_set_content_at_func);
    
}

TCDisplayCell* _tc_content_window_get_content_at_func(struct TCWindow* tc_content_window, size_t x, size_t y)
{
    TCContentWindow* cast_tc_content_window = (TCContentWindow*)tc_content_window;
    return &(cast_tc_content_window->_content[y][x]);
}

void _tc_content_window_set_content_at_func(struct TCWindow* tc_content_window, TCDisplayCell tc_display_cell, size_t x, size_t y)
{
    TCContentWindow* cast_tc_content_window = (TCContentWindow*)tc_content_window;
    TCDisplayCell* found_tc_display_cell = &(cast_tc_content_window->_content[y][x]);

    (*found_tc_display_cell) = tc_display_cell;
}

void _tc_content_window_init_content(TCContentWindow* tc_window)
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
