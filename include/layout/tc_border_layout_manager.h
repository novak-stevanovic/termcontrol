#ifndef TC_BORDER_LAYOUT_MANAGER_H
#define TC_BORDER_LAYOUT_MANAGER_H

#include <stddef.h>

#include "layout/tc_layout_manager.h"
#include "tc_object/tc_object.h"
#include "tc_object/container/tc_layout_container.h"

typedef enum TCBorderLayoutDirection { TC_NORTH, TC_EAST, TC_SOUTH, TC_WEST, TC_CENTER } TCBorderLayoutDirection;

typedef struct TCBorderLMOptions
{
    TCObject *object;
    size_t size;
} TCBorderLMOptions;

typedef struct TCBorderLayoutManager
{
    TCLayoutManager _base;
    TCBorderLMOptions _north, _east, _south, _west, _center;
} TCBorderLayoutManager;

void tc_border_lm_init(TCBorderLayoutManager* border_lm, TCLayoutContainer* layout_container);

void _tc_border_lm_arrange_func(TCLayoutManager* layout_manager);

size_t tc_border_lm_get_direction_size(TCBorderLayoutManager* border_lm, TCBorderLayoutDirection direction);
TCObject* tc_border_lm_get_object(TCBorderLayoutManager* border_lm, TCBorderLayoutDirection direction);

void tc_border_lm_set_direction_size(TCBorderLayoutManager* border_lm, TCBorderLayoutDirection direction, size_t size);
void tc_border_lm_set_object(TCBorderLayoutManager* border_lm, TCBorderLayoutDirection direction, TCObject* object);

TCBorderLMOptions* get_tc_border_lm_opts(TCBorderLayoutManager* border_lm, TCBorderLayoutDirection direction);

#endif
