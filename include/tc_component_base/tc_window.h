#ifndef TC_WINDOW_H
#define TC_WINDOW_H

#include "tc_component_base/tc_object.h"
#include "base/tc_display_cell.h"

typedef struct TCWindow
{
    struct TCObject _base;
    TCDisplayCell* (*get_content_at_func)(struct TCWindow*, size_t, size_t);
    void (*set_content_at_func)(struct TCWindow*, TCDisplayCell, size_t, size_t);
} TCWindow;

void _tc_window_init( // for inheritance
        TCWindow* tc_window, 
        void (*draw_func)(void*),
        TCDisplayCell* (*get_content_at_func)(struct TCWindow*, size_t, size_t),
        void (*set_content_at_func)(struct TCWindow*, TCDisplayCell, size_t, size_t));

void tc_window_init(
        TCWindow* tc_window, 
        TCDisplayCell* (*get_content_at_func)(struct TCWindow*, size_t, size_t),
        void (*set_content_at_func)(struct TCWindow*, TCDisplayCell, size_t, size_t)); // constructor

void tc_window_draw_func(void* tc_window);

#endif
