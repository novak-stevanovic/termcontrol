#ifndef TC_CONTENT_WINDOW_H
#define TC_CONTENT_WINDOW_H

#include "base/tc_display_cell.h"
#include "tc_object/window/tc_window.h"

typedef struct TCContentWindow
{
    struct TCWindow _base;
    TCDisplayCell** _content;
} TCContentWindow;

void _tc_content_window_init(TCContentWindow* tc_cont_window,
        void (*draw_func)(void*),
        TCDisplayCell* (*get_content_at_func)(TCWindow*, size_t, size_t));

void tc_content_window_init(TCContentWindow* tc_cont_window);

void _tc_content_window_set_content_at(TCContentWindow* tc_window, size_t x, size_t y, TCDisplayCell* content_bp);

TCDisplayCell* _tc_content_window_get_content_at_func(TCWindow* tc_window, size_t x, size_t y);

#endif
