#include "tc_cursor.h"
#include "tc_display.h"
#include "misc.h"

#include "primitives/tc_cursor_prims.h"
#include <stdio.h>

void _set_cursor_pos(size_t x, size_t y);

// ------------------------------------------------------------------------------

struct TCCursor
{
    size_t x, y;
};

struct TCCursor cursor;

void _tc_cursor_init()
{
    prim_move_cursor_home();

    _set_cursor_pos(0, 0);
}

size_t tc_cursor_get_x()
{
    return cursor.x;
}

size_t tc_cursor_get_y()
{
    return cursor.y;
}

void _set_cursor_pos(size_t x, size_t y)
{
    cursor.x = misc_flatten(0, x, tc_display_get_display_width() - 1);
    cursor.y = misc_flatten(0, y, tc_display_get_display_height() - 1);
}

void tc_cursor_print_chr(char c)
{
    putchar(c);
    if(cursor.x == (tc_display_get_display_width() - 1))
    {
        cursor.x = 0;
        cursor.y++;
    }
    else
    {
        cursor.x++;
    }

}
