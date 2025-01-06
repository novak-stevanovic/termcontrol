#include "primitives/tc_style_prims.h"
#include "primitives/tc_color.h"

int tc_color_get_code_for_tc_color(enum TCColor tc_color)
{
    if(tc_color == TC_COLOR_DEFAULT) return 9;
    else return tc_color;
}
