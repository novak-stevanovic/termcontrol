#include "primitives/tc_cursor_prims.h"
#include "primitives/tc_primitives.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void tc_prim_move_cursor_home()
{
    snprintf(code_buff, CODE_BUFF_LEN, MOVE_CURSOR_HOME_CODE);
    WRITE_CODE;
}

void tc_prim_move_cursor_to_line_col(size_t line, size_t col)
{
    snprintf(code_buff, CODE_BUFF_LEN, MOVE_CURSOR_LINE_COL_CODE, line, col);
    WRITE_CODE;
}

void tc_prim_move_cursor_up(size_t row_diff)
{
    snprintf(code_buff, CODE_BUFF_LEN, MOVE_CURSOR_UP_CODE, (int)row_diff);
    WRITE_CODE;
}

void tc_prim_move_cursor_down(size_t row_diff)
{
    snprintf(code_buff, CODE_BUFF_LEN, MOVE_CURSOR_DOWN_CODE, (int)row_diff);
    WRITE_CODE;
}

void tc_prim_move_cursor_right(size_t col_diff)
{
    snprintf(code_buff, CODE_BUFF_LEN, MOVE_CURSOR_RIGHT_CODE, (int)col_diff);
    WRITE_CODE;
}

void tc_prim_move_cursor_left(size_t col_diff)
{
    snprintf(code_buff, CODE_BUFF_LEN, MOVE_CURSOR_LEFT_CODE, (int)col_diff);
    WRITE_CODE;
}

void tc_prim_move_cursor_to_col(size_t col)
{
    snprintf(code_buff, CODE_BUFF_LEN, MOVE_CURSOR_TO_COLUMN_CODE, (int)col);
    WRITE_CODE;
}
