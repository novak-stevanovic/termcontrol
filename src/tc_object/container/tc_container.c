#include <assert.h>

#include "tc_object/container/tc_container.h"
#include "vector.h"

void tc_container_init(TCContainer* container, void (*draw_func)(void*))
{
    assert(container != NULL);

    tc_object_init((TCObject*)container, draw_func);
    container->_children = vec_init(3, 2, sizeof(TCObject*));
}

struct Vector* tc_container_get_children(TCContainer* container)
{
    assert(container != NULL);
    return container->_children;
}

struct Vector* _tc_container_get_next_to_draw_func(void* container)
{
    assert(container != NULL);
    return ((TCContainer*)(container))->_children;
}
