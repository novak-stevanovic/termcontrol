#include "base/tc_container.h"
#include "vector.h"
#include <assert.h>

void tc_container_init(struct TCContainer* tc_container, void (*init_func)(void*), void (*draw_func)(void*))
{
    assert(tc_container != NULL);
    tc_object_init(&tc_container->tc_base, init_func, draw_func);
    tc_container->children = vec_init(3, 2, sizeof(struct TCObject*));
}
