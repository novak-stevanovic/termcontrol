#ifndef TC_WINDOW_H
#define TC_WINDOW_H

#include "tc_component_base/tc_object.h"
#include "base/tc_display_cell.h"

typedef struct TCWindow
{
    struct TCObject _base;
    TCDisplayCell** _content;
} TCWindow;

void _tc_window_init(TCWindow* tc_window, void (*draw_func)(void*)); // for inheritance
void tc_window_init(TCWindow* tc_window); // constructor

TCDisplayCell* tc_window_get_content_at(TCWindow* tc_window, size_t x, size_t y);
void tc_window_set_content_at(TCWindow* tc_window, size_t x, size_t y, TCDisplayCell* new_content_bp);

void tc_window_draw_func(void* tc_window);

#endif
