#include "tc_cursor.h"
#include "misc.h"

#include "primitives/tc_cursor_prims.h"

void _set_cursor_pos(size_t x, size_t y);

// ------------------------------------------------------------------------------

struct Cursor cursor;

void _tc_cursor_init()
{
    prim_move_cursor_home();

    _set_cursor_pos(0, 0);
}

size_t tc_cursor_get_x()
{
    return cursor._x;
}

size_t tc_cursor_get_y()
{
    return cursor._y;
}

void _set_cursor_pos(size_t x, size_t y)
{
    //TODO
    cursor._x = x;
    cursor._y = y;
}
