#include "base/tc_container.h"
#include "vector.h"
#include <assert.h>

void tc_container_init(struct TCContainer* tc_container, void (*init_func)(void*), void (*draw_func)(void*))
{
    assert(tc_container != NULL);
    tc_object_init(&tc_container->tc_base, init_func, draw_func);
    tc_container->children = vec_init(3, 2, sizeof(struct TCObject*));
}

void tc_container_draw(void* tc_container)
{
    assert(tc_container != NULL);
    struct TCContainer* cast_tc_container = (struct TCContainer*)tc_container;

    assert(cast_tc_container->children != NULL);

    struct Vector* tc_container_children = cast_tc_container->children;

    int i;
    for(i = 0; i < vec_get_count(tc_container_children); i++)
    {
        struct TCObject* current_child = (struct TCObject*)vec_at(tc_container_children, i);

        assert(current_child != NULL);

        if(current_child->draw_func != NULL)
            current_child->draw_func(current_child);
    }


}
