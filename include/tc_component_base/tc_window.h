#ifndef TC_WINDOW_H
#define TC_WINDOW_H

#include "tc_component_base/tc_object.h"
#include "base/tc_display_cell.h"

struct TCWindow
{
    struct TCObject tc_object;
    struct TCDisplayCell** content;
};

void tc_window_init(struct TCWindow* tc_window); // constructor
void _tc_window_init_base(struct TCWindow* tc_window, void (*init_func)(void*), void (*draw_func)(void*)); // for inheritance

#endif
