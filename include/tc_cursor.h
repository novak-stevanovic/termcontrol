#ifndef TC_CURSOR_H
#define TC_CURSOR_H

#include <stddef.h>
#include <sys/types.h>

struct Cursor;

extern struct Cursor cursor;

void _tc_cursor_init();

size_t tc_cursor_get_x();
size_t tc_cursor_get_y();

void tc_cursor_fix_pos();

void tc_cursor_rel_move(int row_diff, int col_diff);
void tc_cursor_rel_move_y(int row_diff);
void tc_cursor_rel_move_x(int col_diff);

void tc_cursor_abs_reset();
void tc_cursor_abs_move_x(size_t col);
void tc_cursor_abs_move_y(size_t row);
void tc_cursor_abs_move(size_t row, size_t col);

void tc_cursor_print_chr(char c);
void tc_cursor_print_str(char* str, size_t str_len);

#endif
