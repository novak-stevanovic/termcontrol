#include <assert.h>

#include "tc_object/tc_object.h"

void tc_object_init(TCObject* tc_object, void (*draw_func)(void*))
{
    assert(tc_object != NULL);
    tc_object_set_positions(tc_object, 0, 0, 0, 0);
    tc_object->_draw_func = draw_func;
}

void tc_object_set_positions(TCObject* tc_object, size_t start_x, size_t start_y, size_t end_x, size_t end_y)
{
    assert(tc_object != NULL);
    tc_object->start_x = start_x;
    tc_object->start_y = start_y;
    tc_object->end_x = end_x;
    tc_object->end_y = end_y;
}
