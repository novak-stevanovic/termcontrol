#include <stdio.h>

#include "base/tc_print_controller.h"
#include "base/tc_cursor.h"
#include "base/tc_display.h"
#include "primitives/tc_cursor_prims.h"

void tc_putchar(char c)
{
    putchar(c);
    size_t cursor_x = tc_cursor_get_x();
    size_t cursor_y = tc_cursor_get_y();

    if(cursor_x == (tc_display_get_display_width() - 1))
        tc_cursor_abs_move(cursor_y + 1, 1);
    else
        tc_cursor_abs_move(cursor_y, cursor_x + 1);
}
