#include <stdlib.h>

#include "tc_object/window/tc_content_window.h"
#include "base/tc_shared.h"

void _tc_content_window_init_content(TCContentWindow* content_window);

// ---------------------------------------------------------------------------------------------------

void tc_content_window_init(TCContentWindow* content_window)
{
    tc_window_init((TCWindow*)content_window, _tc_content_window_get_content_at_func);

    _tc_content_window_init_content(content_window);
}

void _tc_content_window_set_content_at(TCContentWindow* content_window, size_t x, size_t y, TCDisplayCell* content_bp)
{
    content_window->_content[y][x].content = content_bp->content;
    content_window->_content[y][x].bg_color = content_bp->bg_color;
    content_window->_content[y][x].fg_color = content_bp->fg_color;
}

TCDisplayCell* _tc_content_window_get_content_at_func(TCWindow* cwidnow, size_t x, size_t y)
{
    TCContentWindow* tc_cont_window = (TCContentWindow*)cwidnow;
    return &(tc_cont_window->_content[y][x]);
}

// ---------------------------------------------------------------------------------------------------

void _tc_content_window_init_content(TCContentWindow* cwidnow)
{
    cwidnow->_content = (TCDisplayCell**)malloc(sizeof(TCDisplayCell*) * MAX_WINDOW_SIZE_Y);
    int i, j;
    for(i = 0; i < MAX_WINDOW_SIZE_Y; i++)
    {
        cwidnow->_content[i] = (TCDisplayCell*)malloc(sizeof(TCDisplayCell) * MAX_WINDOW_SIZE_X);
        for(j = 0; j < MAX_WINDOW_SIZE_X; j++)
        {
            cwidnow->_content[i][j].content = 'u';
            cwidnow->_content[i][j].bg_color = TC_COLOR_RED;
            cwidnow->_content[i][j].fg_color = TC_COLOR_BLACK;
        }
    }
}
