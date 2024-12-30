#ifndef _TC_WINDOW_H
#define _TC_WINDOW_H

#include <stddef.h>

struct Window
{
    size_t _start_x, _start_y, _end_x, _end_y;
};

void tc_window_write(struct Window* window, char** content);

size_t tc_window_get_start_x(struct Window* window);
size_t tc_window_get_start_y(struct Window* window);
size_t tc_window_get_end_x(struct Window* window);
size_t tc_window_get_end_y(struct Window* window);
size_t tc_window_get_dim_x(struct Window* window);
size_t tc_window_get_dim_y(struct Window* window);

#endif
