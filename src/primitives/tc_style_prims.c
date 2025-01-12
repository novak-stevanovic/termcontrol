#include "primitives/tc_style_prims.h"
#include "primitives/tc_color.h"
#include "primitives/tc_primitives.h"
#include <stdio.h>
#include <unistd.h>

int tc_prim_get_code_for_tc_color(enum TCColor tc_color)
{
    if(tc_color == TC_COLOR_DEFAULT) return 9;
    else return tc_color;
}

void tc_prim_set_fg_color(TCColor tc_color)
{
    snprintf(code_buff, CODE_BUFF_LEN, COLOR_FG_CODE, tc_prim_get_code_for_tc_color(tc_color));
    WRITE_CODE; 
}
void tc_prim_set_bg_color(TCColor tc_color)
{
    snprintf(code_buff, CODE_BUFF_LEN, COLOR_BG_CODE, tc_prim_get_code_for_tc_color(tc_color));
    WRITE_CODE; 
}
