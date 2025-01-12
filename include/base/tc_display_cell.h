#ifndef TC_DISPLAY_CELL
#define TC_DISPLAY_CELL

#include "primitives/tc_color.h"

typedef struct TCDisplayCell
{
    TCColor fg_color, bg_color;
    char content;
} TCDisplayCell;

#endif
