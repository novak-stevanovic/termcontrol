#ifndef TC_WINDOW_H
#define TC_WINDOW_H

#include "tc_object/tc_object.h"
#include "base/tc_display_cell.h"

typedef struct TCWindow // ABSTRACT
{
    struct TCObject _base;
    TCDisplayCell* (*get_content_at_func)(struct TCWindow*, size_t, size_t);
} TCWindow;

void tc_window_init(TCWindow* window, TCDisplayCell* (*get_content_at_func)(struct TCWindow*, size_t, size_t)); // constructor

TCDisplayCell* tc_window_get_content_at(TCWindow* window, size_t x, size_t y);

void _tc_window_draw_func(void* window);

#endif
