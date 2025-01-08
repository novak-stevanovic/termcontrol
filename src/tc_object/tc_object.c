#include <assert.h>

#include "tc_object/tc_object.h"

void tc_object_init(TCObject* tc_obj, void (*draw_func)(void*))
{
    assert(tc_obj != NULL);
    tc_object_set_positions(tc_obj, 0, 0, 0, 0);
    tc_obj->_draw_func = draw_func;
}

void tc_object_set_positions(TCObject* tc_obj, size_t start_x, size_t start_y, size_t end_x, size_t end_y)
{
    assert(tc_obj != NULL);
    tc_obj->start_x = start_x;
    tc_obj->start_y = start_y;
    tc_obj->end_x = end_x;
    tc_obj->end_y = end_y;
}

void tc_object_draw(TCObject* tc_obj)
{
    tc_obj->_draw_func(tc_obj);
}
