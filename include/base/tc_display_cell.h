#ifndef TC_DISPLAY_CELL
#define TC_DISPLAY_CELL

#include "tc_color.h"

typedef struct TCDisplayCell
{
    enum TCColor fg_color, bg_color;
    char content;
} TCDisplayCell;

#endif