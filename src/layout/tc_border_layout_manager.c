#include <assert.h>

#include "layout/tc_border_layout_manager.h"

static TCObject** _tc_border_get_ptr_to_obj_for_fir(TCBorderLayoutManager* border_lm, TCBorderLMDirection direction);

// ------------------------------------------------------------------------------------------------------------------------------

void tc_border_lm_init(TCBorderLayoutManager* border_lm, TCLayoutContainer* layout_container)
{
    assert(border_lm != NULL);
    assert(layout_container != NULL);

    tc_lm_init((TCLayoutManager*)border_lm, layout_container, _tc_border_lm_arrange_func);
}

void vec_empty(struct Vector*);
void vec_append(struct Vector*, void*);
// TODO

void _tc_border_lm_arrange_func(TCLayoutManager* layout_manager)
{
    TCBorderLayoutManager* b_lm = (TCBorderLayoutManager*)layout_manager;
    TCContainer* container = ((TCContainer*)layout_manager->_container);
    TCObject* container_obj = ((TCObject*)container);
    struct Vector* children = tc_container_get_children(container);
    vec_empty(children);

    TCObject* north_obj = b_lm->_north;
    size_t north_size = (north_obj != NULL ? tc_object_get_pref_height(north_obj) : 0);

    TCObject* east_obj = b_lm->_east;
    size_t east_size = (east_obj != NULL ? tc_object_get_pref_width(east_obj) : 0);

    TCObject* south_obj = b_lm->_south;
    size_t south_size = (south_obj != NULL ? tc_object_get_pref_height(south_obj) : 0);

    TCObject* west_obj = b_lm->_west;
    size_t west_size = (west_obj != NULL ? tc_object_get_pref_width(west_obj) : 0);

    TCObject* center_obj = (b_lm->_center != NULL ? b_lm->_center : NULL);
    size_t center_width = container_obj->end_x - container_obj->start_x - east_size - west_size;
    size_t center_height = container_obj->end_y - container_obj->start_y - north_size - south_size;

    if(north_obj != NULL) 
    {
        tc_object_set_positions(north_obj, container_obj->start_x, container_obj->start_y, container_obj->end_x, north_size);
        vec_append(children, north_obj);
    }
    if(east_obj != NULL) 
    {
        tc_object_set_positions(east_obj, west_size + center_width, north_size, container_obj->end_x, north_size + center_height);
        vec_append(children, east_obj);
    }
    if(south_obj != NULL) 
    {
        tc_object_set_positions(south_obj, container_obj->start_x, north_size + center_height, container_obj->end_x, container_obj->end_y);
        vec_append(children, south_obj);
    }
    if(west_obj != NULL) 
    {
        tc_object_set_positions(west_obj, container_obj->start_x, north_size, west_size, north_size + center_height);
        vec_append(children, west_obj);
    }
    if(center_obj != NULL) 
    {
        tc_object_set_positions(center_obj, west_size, north_size, west_size + center_width, north_size + center_height);
        vec_append(children, center_obj);
    }
}

TCObject* tc_border_lm_get_object(TCBorderLayoutManager* border_lm, TCBorderLMDirection direction)
{
    assert(border_lm != NULL);

    TCObject** object_ptr = _tc_border_get_ptr_to_obj_for_fir(border_lm, direction);
    return (*object_ptr);
}

void tc_border_lm_set_object(TCBorderLayoutManager* border_lm, TCBorderLMDirection direction, TCObject* object)
{
    assert(border_lm != NULL);

    TCObject** object_ptr = _tc_border_get_ptr_to_obj_for_fir(border_lm, direction);
    (*object_ptr) = object;
}

TCObject* tc_border_lm_get_center_object(TCBorderLayoutManager* border_lm)
{
    assert(border_lm != NULL);
    return border_lm->_center;
}

void tc_border_lm_set_center_object(TCBorderLayoutManager* border_lm, TCObject* object)
{
    assert(border_lm != NULL);
    border_lm->_center = object;
}

// ------------------------------------------------------------------------------------------------------------------------------

static TCObject** _tc_border_get_ptr_to_obj_for_fir(TCBorderLayoutManager* border_lm, TCBorderLMDirection direction)
{
    switch (direction) {
        case TC_NORTH:
            return &(border_lm->_north);
        case TC_EAST:
            return &(border_lm->_east);
        case TC_SOUTH:
            return &(border_lm->_south);
        case TC_WEST:
            return &(border_lm->_west);
        case TC_CENTER:
            return &(border_lm->_center);
    }
}
