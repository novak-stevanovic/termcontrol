#ifndef TC_CONTENT_WINDOW_H
#define TC_CONTENT_WINDOW_H

#include "tc_component_base/tc_window.h"

typedef struct TCContentWindow
{
    TCWindow _base;
    TCDisplayCell** _content;
} TCContentWindow;

void _tc_content_window_init( // constructor
        TCWindow* tc_window, 
        void (*draw_func)(void*),
        TCDisplayCell* (*get_content_at_func)(struct TCWindow*, size_t, size_t),
        void (*set_content_at_func)(struct TCWindow*, TCDisplayCell, size_t, size_t));

void _tc_content_window_draw_func(void* tc_content_window);
TCDisplayCell* _tc_content_window_get_content_at_func(struct TCWindow* tc_content_window, size_t x, size_t y);
void _tc_content_window_set_content_at_func(struct TCWindow* tc_content_window, TCDisplayCell tc_display_cell, size_t x, size_t y); 

#define TC_CONTENT_WINDOW_INIT(tc_w) _tc_content_window_init( \
        tc_w, \
        _tc_content_window_draw_func, \
        _tc_content_window_get_content_at_func, \
        _tc_content_window_set_content_at_func)



#endif

