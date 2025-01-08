#include <assert.h>

#include "layout/tc_border_layout_manager.h"

void tc_border_lm_init(TCBorderLayoutManager* border_lm, TCLayoutContainer* layout_container)
{
    assert(border_lm != NULL);
    assert(layout_container != NULL);

    tc_lm_init((TCLayoutManager*)border_lm, layout_container, _tc_border_lm_arrange_func);
}

void _tc_border_lm_arrange_func(TCLayoutManager* layout_manager)
{
    TCBorderLayoutManager* b_lm = (TCBorderLayoutManager*)b_lm;
    TCContainer* container = ((TCContainer*)layout_manager->_container);
    struct Array* children = tc_container_get_children(container);

    if(b_lm->_center.object != NULL) tc_object_draw(b_lm->_center.object);
    if(b_lm->_north.object != NULL) tc_object_draw(b_lm->_north.object);
    if(b_lm->_south.object != NULL) tc_object_draw(b_lm->_south.object);
    if(b_lm->_east.object != NULL) tc_object_draw(b_lm->_east.object);
    if(b_lm->_west.object != NULL) tc_object_draw(b_lm->_west.object);

}

size_t tc_border_lm_get_direction_size(TCBorderLayoutManager* border_lm, TCBorderLayoutDirection direction)
{
    assert(border_lm != NULL);

    TCBorderLMOptions* opts = get_tc_border_lm_opts(border_lm, direction);
    return opts->size;
}

TCObject* tc_border_lm_get_object(TCBorderLayoutManager* border_lm, TCBorderLayoutDirection direction)
{
    assert(border_lm != NULL);

    TCBorderLMOptions* opts = get_tc_border_lm_opts(border_lm, direction);
    return opts->object;
}

void tc_border_lm_set_direction_size(TCBorderLayoutManager* border_lm, TCBorderLayoutDirection direction, size_t size)
{
    assert(border_lm != NULL);

    TCBorderLMOptions* opts = get_tc_border_lm_opts(border_lm, direction);
    opts->size = size;
}

void tc_border_lm_set_object(TCBorderLayoutManager* border_lm, TCBorderLayoutDirection direction, TCObject* object)
{
    assert(border_lm != NULL);

    TCBorderLMOptions* opts = get_tc_border_lm_opts(border_lm, direction);
    opts->object = object;
}

TCBorderLMOptions* get_tc_border_lm_opts(TCBorderLayoutManager* border_lm, TCBorderLayoutDirection direction)
{
    switch (direction) {
        case TC_NORTH:
            return &border_lm->_north;
        case TC_EAST:
            return &border_lm->_east;
        case TC_SOUTH:
            return &border_lm->_south;
        case TC_WEST:
            return &border_lm->_west;
        case TC_CENTER:
            return &border_lm->_center;
    }
}

