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

void tc_cursor_conform_pos_to_scr()
{
    _set_cursor_pos(cursor.x, cursor.y);
}

void _set_cursor_pos(size_t x, size_t y)
{
    cursor.x = misc_conform(0, x, tc_display_get_display_width() - 1);
    cursor.y = misc_conform(0, y, tc_display_get_display_height() - 1);
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

void tc_cursor_rel_move(int row_diff, int col_diff)
{
    tc_cursor_abs_move_x(col_diff);
    tc_cursor_abs_move_y(row_diff);
}

void tc_cursor_rel_move_y(int row_diff)
{
    ((row_diff > 0) ? prim_move_cursor_down(row_diff) : prim_move_cursor_up(-row_diff));
    _set_cursor_pos(cursor.x, cursor.y + row_diff);
}

void tc_cursor_rel_move_x(int col_diff)
{
    ((col_diff > 0) ? prim_move_cursor_right(col_diff) : prim_move_cursor_left(-col_diff));
    _set_cursor_pos(cursor.x + col_diff, cursor.y);
}

void tc_cursor_abs_reset()
{
    prim_move_cursor_home();
    _set_cursor_pos(0, 0);
}

void tc_cursor_abs_move_x(size_t col)
{
    prim_move_cursor_to_col(col);
    _set_cursor_pos(col, cursor.y);
}

void tc_cursor_abs_move_y(size_t row)
{
    tc_cursor_abs_move(cursor.x, row);
}

void tc_cursor_abs_move(size_t row, size_t col)
{
    prim_move_cursor_to_line_col(row, col);
    _set_cursor_pos(col, row);
}
