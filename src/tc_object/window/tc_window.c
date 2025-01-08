#include "tc_object/window/tc_window.h"
#include "base/tc_display.h"
#include "tc_object/tc_object.h"

// ------------------------------------------------------------------------------------------------------------------------------------

void _tc_window_init(TCWindow* window, void (*draw_func)(void*), TCDisplayCell* (*get_content_at_func)(TCWindow*, size_t, size_t))
{
    tc_object_init((TCObject*)window, draw_func);
    window->get_content_at_func = get_content_at_func;
}

void tc_window_init(TCWindow* window, TCDisplayCell* (*get_content_at_func)(TCWindow*, size_t, size_t))
{
    _tc_window_init(window, tc_window_draw_func, get_content_at_func);
}

void tc_window_draw_func(void* indow)
{
    tc_display_draw_tc_window(indow);
}

TCDisplayCell* tc_window_get_content_at(TCWindow* window, size_t x, size_t y)
{
    return window->get_content_at_func(window, x, y);
}

// ------------------------------------------------------------------------------------------------------------------------------------
