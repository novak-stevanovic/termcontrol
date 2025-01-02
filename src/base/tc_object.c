#include "base/tc_object.h"
#include "array.h"

void tc_object_init(struct TCObject* tc_object, void (*init_func)(void*), void (*draw_func)(void*))
{
    tc_object->init_func = init_func;
    tc_object->draw_func = draw_func;

    tc_object->start_x = 0;
    tc_object->start_y = 0;
    tc_object->end_x = 0;
    tc_object->end_y = 0;
}

// struct TCObject* tc_object_dyn_init(void (*init_func)(void* tc_object), void (*draw_func)(void* tc_object))
// {
//     struct TCObject* tcb = (struct TCObject*)malloc(sizeof(struct TCObject));
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
