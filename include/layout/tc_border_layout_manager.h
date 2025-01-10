#ifndef TC_BORDER_LAYOUT_MANAGER_H
#define TC_BORDER_LAYOUT_MANAGER_H

#include <stddef.h>

#include "layout/tc_layout_manager.h"
#include "tc_object/tc_object.h"
#include "tc_object/container/tc_layout_container.h"

typedef enum TCBorderLMDirection { TC_CENTER, TC_NORTH, TC_EAST, TC_SOUTH, TC_WEST } TCBorderLMDirection;

typedef struct TCBorderLayoutManager
{
    TCLayoutManager _base;
    TCObject *_center, *_north, *_east, *_south, *_west;
} TCBorderLayoutManager;

void tc_border_lm_init(TCBorderLayoutManager* border_lm, TCLayoutContainer* layout_container);

size_t tc_border_lm_get_direction_size(TCBorderLayoutManager* border_lm, TCBorderLMDirection direction);
TCObject* tc_border_lm_get_object(TCBorderLayoutManager* border_lm, TCBorderLMDirection direction);

void tc_border_lm_set_direction_size(TCBorderLayoutManager* border_lm, TCBorderLMDirection direction, size_t size);
void tc_border_lm_set_object(TCBorderLayoutManager* border_lm, TCBorderLMDirection direction, TCObject* object);

TCObject* tc_border_lm_get_object_for_direction(TCBorderLayoutManager* border_lm, TCBorderLMDirection direction);
void tc_border_lm_set_object_for_direction(TCBorderLayoutManager* border_lm, TCBorderLMDirection direction, TCObject* new_obj);

// -----------------------------------------------------------------------

void _tc_border_lm_arrange_func(TCLayoutManager* layout_manager);

#endif
