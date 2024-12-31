#include "tc_window.h"

struct TCWindow
{
    size_t start_x;
    size_t start_y;

    size_t end_x;
    size_t end_y;

    char** content;
};

size_t tc_window_get_start_x(struct TCWindow* window)
{
    return window->start_x;
}

size_t tc_window_get_start_y(struct TCWindow* window)
{
    return window->start_y;
}

size_t tc_window_get_end_x(struct TCWindow* window)
{
    return window->end_x;
}

size_t tc_window_get_end_y(struct TCWindow* window)
{
    return window->end_y;
}

void tc_window_set_start_x(struct TCWindow* window, size_t start_x)
{
    window->start_x = start_x;
}

void tc_window_set_start_y(struct TCWindow* window, size_t start_y)
{
    window->start_y = start_y;
}

void tc_window_set_end_x(struct TCWindow* window, size_t end_x)
{
    window->end_x = end_x;
}

void tc_window_set_end_y(struct TCWindow* window, size_t end_y)
{
    window->end_y = end_y;
}
