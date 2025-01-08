#ifndef TC_CONTENT_WINDOW_H
#define TC_CONTENT_WINDOW_H

#include "base/tc_display_cell.h"
#include "tc_object/window/tc_window.h"

typedef struct TCContentWindow
{
    struct TCWindow _base;
    TCDisplayCell** _content;
} TCContentWindow;

void tc_content_window_init(TCContentWindow* content_window);

void _tc_content_window_set_content_at(TCContentWindow* content_window, size_t x, size_t y, TCDisplayCell* content_bp);

TCDisplayCell* _tc_content_window_get_content_at_func(TCWindow* content_window, size_t x, size_t y);

#endif
