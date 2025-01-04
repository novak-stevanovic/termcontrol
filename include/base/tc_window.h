#ifndef TC_WINDOW_H
#define TC_WINDOW_H

#include "base/tc_object.h"
#include "base/tc_display_cell.h"

struct TCWindow
{
    struct TCObject tc_object;
    struct TCDisplayCell** content;
};

void tc_window_init(struct TCWindow* tc_window, void (*init_func)(void*), void (*draw_func)(void*));

#endif
