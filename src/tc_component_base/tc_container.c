#include "tc_component_base/tc_container.h"
#include "vector.h"
#include <assert.h>

void tc_container_init(TCContainer* tc_container, void (*draw_func)(void*))
{
    assert(tc_container != NULL);
    tc_object_init(&tc_container->_base, draw_func);
    tc_container->_children = vec_init(3, 2, sizeof(TCObject*));
}

struct Vector* tc_container_get_children(TCContainer* tc_container)
{
    return tc_container->_children;
}
