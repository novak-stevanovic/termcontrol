#include "base/tc_window.h"
#include "base/tc_object.h"

#include "vector.h"

void tc_window_init(struct TCWindow* tc_window, void (*init_func)(void*), void (*draw_func)(void*))
{
    tc_object_init(&tc_window->tc_object, init_func, draw_func);

    tc_window->content = vec_init(0, 5, vec_get_struct_size());
}

