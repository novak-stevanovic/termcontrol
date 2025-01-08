#include <assert.h>
#include <stdlib.h>

#include "layout/tc_layout_manager.h"

void tc_lm_init(TCLayoutManager* layout_manager,
        struct TCLayoutContainer* layout_container,
        void (*arrange_func)(struct TCLayoutManager*))
{
    assert(layout_manager != NULL);
    assert(layout_container != NULL);

    layout_manager->_container = layout_container;
    layout_manager->_arrange_func = arrange_func;
}

void tc_lm_arrange(TCLayoutManager* layout_manager)
{
    assert(layout_manager != NULL);

    layout_manager->_arrange_func(layout_manager);
}

struct TCLayoutContainer* tc_lm_get_container(TCLayoutManager* layout_manager)
{
    assert(layout_manager != NULL);

    return layout_manager->_container;
}
