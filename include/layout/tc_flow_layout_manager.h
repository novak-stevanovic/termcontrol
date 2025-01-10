#ifndef TC_FLOW_LAYOUT_MANAGER_H
#define TC_FLOW_LAYOUT_MANAGER_H

#include <stddef.h>

#include "layout/tc_layout_manager.h"

typedef enum TCFlowLMPaddingLocation { TC_PADDING_TOP, TC_PADDING_RIGHT, TC_PADDING_BOTTOM, TC_PADDING_LEFT } TCFlowLMPaddingLocation;
typedef enum TCFlowLayoutDirection { HORIZONTAL, VERTICAL } TCFlowLayoutDirection;

typedef struct TCFlowLayoutManager
{
    TCLayoutManager _base;
    TCFlowLayoutDirection _direction;
    size_t _padding_top, _padding_right, _padding_bottom, _padding_left;
    size_t _spacing;
} TCFlowLayoutManager;

void tc_flow_lm_init(TCFlowLayoutManager* flow_lm, TCFlowLayoutDirection direction);

void tc_flow_lm_set_padding(TCFlowLayoutManager* flow_lm, size_t value);
void tc_flow_lm_set_padding_for_direction(TCFlowLayoutManager* flow_lm, size_t value, TCFlowLMPaddingLocation direction);
size_t tc_flow_lm_get_padding_for_direction(TCFlowLayoutManager* flow_lm, TCFlowLMPaddingLocation direction);

size_t tc_flow_lm_get_spacing(TCFlowLayoutManager* flow_lm);
void tc_flow_lm_set_spacing(TCFlowLayoutManager* flow_lm, size_t value);

void tc_flow_lm_set_direction(TCFlowLayoutManager* flow_lm, TCFlowLayoutDirection value);
TCFlowLayoutDirection tc_flow_lm_get_direction(TCFlowLayoutManager* flow_lm);

// -----------------------------------------------------------------------

void _tc_flow_lm_arrange_func(TCLayoutManager* layout_manager);

#endif
