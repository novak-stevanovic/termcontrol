#include "tc_object/window/tc_window.h"
#include "base/tc_display.h"
#include "tc_object/tc_object.h"

// ------------------------------------------------------------------------------------------------------------------------------------

void _tc_window_init(TCWindow* tc_window, void (*draw_func)(void*), TCDisplayCell* (*get_content_at_func)(TCWindow*, size_t, size_t))
{
    tc_object_init((TCObject*)tc_window, draw_func);
    tc_window->get_content_at_func = get_content_at_func;
}

void tc_window_init(TCWindow* tc_window, TCDisplayCell* (*get_content_at_func)(TCWindow*, size_t, size_t))
{
    _tc_window_init(tc_window, tc_window_draw_func, get_content_at_func);
}

void tc_window_draw_func(void* tc_window)
{
    tc_display_draw_tc_window(tc_window);
}

// ------------------------------------------------------------------------------------------------------------------------------------
