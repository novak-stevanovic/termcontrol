#include <assert.h>

#include "layout/tc_border_layout_manager.h"

void tc_border_lm_init(TCBorderLayoutManager* border_lm, TCLayoutContainer* layout_container)
{
    assert(border_lm != NULL);
    assert(layout_container != NULL);

    tc_lm_init((TCLayoutManager*)border_lm, layout_container, _tc_border_lm_arrange_func);
}

void _tc_border_lm_arrange_func(TCLayoutManager* layout_manager);

size_t tc_border_lm_get_direction_size(TCBorderLayoutManager* border_lm, TCBorderLayoutDirection direction)
{
}
TCObject* tc_border_lm_get_object(TCBorderLayoutManager* border_lm, TCBorderLayoutDirection direction);

void tc_border_lm_set_direction_size(TCBorderLayoutManager* border_lm, TCBorderLayoutDirection direction, size_t size);
void tc_border_lm_set_object(TCBorderLayoutManager* border_lm, TCBorderLayoutDirection direction, TCObject* object);
