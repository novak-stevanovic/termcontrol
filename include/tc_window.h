#ifndef TC_WINDOW_H
#define TC_WINDOW_H

#include <stddef.h>

struct Window;

void tc_window_write(struct Window* window, char** content);

size_t tc_window_get_start_x(struct Window* window);
size_t tc_window_get_start_y(struct Window* window);
size_t tc_window_get_end_x(struct Window* window);
size_t tc_window_get_end_y(struct Window* window);
size_t tc_window_get_dim_x(struct Window* window);
size_t tc_window_get_dim_y(struct Window* window);

#endif
