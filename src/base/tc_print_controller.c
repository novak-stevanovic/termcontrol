#include <stdio.h>

#include "base/tc_print_controller.h"
#include "base/tc_cursor.h"
#include "primitives/tc_cursor_prims.h"

void tc_putchar(char c)
{
    putchar(c);
    tc_prim_move_cursor_left(1);
    tc_cursor_rel_move_x(1);
    tc_cursor_conform_pos_to_scr();
}
