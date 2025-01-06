#ifndef TC_CURSOR_PRIMS_H
#define TC_CURSOR_PRIMS_H

#include <stddef.h>

#define MOVE_CURSOR_HOME_CODE "\e[H"
#define MOVE_CURSOR_LINE_COL_CODE "\e[%ld;%ldH"
#define MOVE_CURSOR_UP_CODE "\e[%dA"
#define MOVE_CURSOR_DOWN_CODE "\e[%dB"
#define MOVE_CURSOR_RIGHT_CODE "\e[%dC"
#define MOVE_CURSOR_LEFT_CODE "\e[%dD"
#define MOVE_CURSOR_TO_COLUMN_CODE "\e[%dG"

void tc_prim_move_cursor_home();
void tc_prim_move_cursor_to_line_col(size_t line, size_t col);
void tc_prim_move_cursor_up(size_t row_diff);
void tc_prim_move_cursor_down(size_t row_diff);
void tc_prim_move_cursor_right(size_t col_diff);
void tc_prim_move_cursor_left(size_t col_diff);
void tc_prim_move_cursor_to_col(size_t col);

#endif
