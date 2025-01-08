#include <assert.h>

#include "tc_object/container/tc_layout_container.h"
#include "layout/tc_layout_manager.h"

void tc_lc_init(TCLayoutContainer* layout_container, struct TCLayoutManager* layout_manager)
{
    assert(layout_container != NULL);
    
    tc_container_init((TCContainer*)layout_container, tc_lc_draw_func);
}

void tc_lc_draw_func(void* layout_container)
{
    assert(layout_container != NULL);
    TCLayoutContainer* layout_container_lc = (TCLayoutContainer*)layout_container;
    tc_lm_arrange(layout_container_lc->_layout_manager);
}
