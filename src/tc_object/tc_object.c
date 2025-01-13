#include <assert.h>

#include "tc_object/tc_object.h"

void tc_object_init(TCObject* tc_obj, void (*draw_func)(void*), struct Vector* (*get_next_to_draw_func)(void*))
{
    assert(tc_obj != NULL);
    tc_object_set_positions(tc_obj, 0, 0, 0, 0);
    tc_object_set_pref_size(tc_obj, 0, 0);
    tc_obj->_draw_func = draw_func;
    tc_obj->_get_next_to_draw_func = get_next_to_draw_func;
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
    assert(tc_obj != NULL);
    tc_obj->_draw_func(tc_obj);
}

struct Vector* tc_object_get_next_to_draw(TCObject* tc_obj)
{
    assert(tc_obj != NULL);
    return tc_obj->_get_next_to_draw_func(tc_obj);
}

void tc_object_set_pref_height(TCObject* tc_obj, size_t pref_height)
{
    assert(tc_obj != NULL);
    tc_obj->_pref_height = pref_height;
}

void tc_object_set_pref_width(TCObject* tc_obj, size_t pref_width)
{
    assert(tc_obj != NULL);
    tc_obj->_pref_width = pref_width;
}

void tc_object_set_pref_size(TCObject* tc_obj, size_t pref_height, size_t pref_width)
{
    assert(tc_obj != NULL);
    tc_obj->_pref_height = pref_height;
    tc_obj->_pref_width = pref_width;
}

size_t tc_object_get_pref_height(TCObject* tc_obj)
{
    assert(tc_obj != NULL);
    return tc_obj->_pref_height;
}

size_t tc_object_get_pref_width(TCObject* tc_obj)
{
    assert(tc_obj != NULL);
    return tc_obj->_pref_width;
}

size_t tc_object_calculate_actual_height(TCObject* tc_obj)
{
    assert(tc_obj != NULL);

    return (tc_obj->end_y - tc_obj->start_y);
}
size_t tc_object_calculate_actual_width(TCObject* tc_obj)
{
    return (tc_obj->end_x - tc_obj->start_x);
}
