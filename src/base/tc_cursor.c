#include <stdio.h>

#include "base/tc_cursor.h"
#include "base/tc_display.h"
#include "primitives/tc_style_prims.h"
#include "tc_misc.h"

#include "primitives/tc_cursor_prims.h"

void _set_cursor_pos(size_t x, size_t y);

// ------------------------------------------------------------------------------

typedef struct TCCursor
{
    size_t x, y;
} TCCursor;

TCCursor cursor;

void _tc_cursor_init()
{
    tc_cursor_abs_reset();
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
    cursor.x = misc_conform(1, x, tc_display_get_display_width() - 1);
    cursor.y = misc_conform(1, y, tc_display_get_display_height() - 1);
}

void tc_cursor_rel_move(int row_diff, int col_diff)
{
    tc_cursor_abs_move_x(col_diff);
    tc_cursor_abs_move_y(row_diff);
}

void tc_cursor_rel_move_y(int row_diff)
{
    if(row_diff == 0) return;

    ((row_diff > 0) ? tc_prim_move_cursor_down(row_diff) : tc_prim_move_cursor_up(-row_diff));
    _set_cursor_pos(cursor.x, cursor.y + row_diff);
}

void tc_cursor_rel_move_x(int col_diff)
{
    if(col_diff == 0) return;

    ((col_diff > 0) ? tc_prim_move_cursor_right(col_diff) : tc_prim_move_cursor_left(-col_diff));
    _set_cursor_pos(cursor.x + col_diff, cursor.y);
}

void tc_cursor_abs_reset()
{
    tc_prim_move_cursor_home();
    _set_cursor_pos(1, 1);
}

void tc_cursor_abs_move_x(size_t col)
{
    tc_prim_move_cursor_to_col(col);
    _set_cursor_pos(col, cursor.y);
}

void tc_cursor_abs_move_y(size_t row)
{
    tc_cursor_abs_move(cursor.x, row);
}

void tc_cursor_abs_move(size_t row, size_t col)
{
    tc_prim_move_cursor_to_line_col(row, col);
    _set_cursor_pos(col, row);
}

// void tc_colorize(TCColor color, size_t row, size_t col, int bg)
// {
//     size_t cursor_x = cursor.x;
//     size_t cursor_y = cursor.y;
//
//     tc_cursor_abs_move(row, col);
//
//     if(bg)
//         tc_prim_set_bg_color(color);
//     else
//         tc_prim_set_fg_color(color);
//
//     tc_cursor_abs_move(cursor_y, cursor_x);
//
// }
