#include "tc_component_base/tc_object.h"

void tc_object_init(TCObject* tc_object, void (*draw_func)(void*))
{
    tc_object->_draw_func = draw_func;

    tc_object_set_positions(tc_object, 0, 0, 0, 0);
}

void tc_object_set_positions(TCObject* tc_object, size_t start_x, size_t start_y, size_t end_x, size_t end_y)
{
    tc_object->start_x = start_x;
    tc_object->start_y = start_y;
    tc_object->end_x = end_x;
    tc_object->end_y = end_y;
}

// void tc_object_init(TCObject* tc_object, void (*init_func)(void*), void (*draw_func)(void*))
// {
//     tc_object->init_func = init_func;
//     tc_object->draw_func = draw_func;
//
//     tc_object->start_x = 0;
//     tc_object->start_y = 0;
//     tc_object->end_x = 0;
//     tc_object->end_y = 0;
// }

// TCObject* tc_object_dyn_init(void (*init_func)(void* tc_object), void (*draw_func)(void* tc_object))
// {
//     TCObject* tcb = (TCObject*)malloc(sizeof(TCObject));
//
//     tcb->start_x = 0;
//     tcb->start_y = 0;
//     tcb->end_x = 0;
//     tcb->end_y = 0;
//     tcb->init_func = init_func;
//     tcb->draw_func = draw_func;
//
//     return tcb;
// }
