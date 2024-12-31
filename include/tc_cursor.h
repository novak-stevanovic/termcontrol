#ifndef TC_CURSOR_H
#define TC_CURSOR_H

#include <stddef.h>
#include <sys/types.h>

struct TCCursor;

extern struct TCCursor cursor;

/* Initializes tc_cursor module. Moves cursor to 0,0 which starts tracking the cursor position */
void _tc_cursor_init();

/* Returns cursor x coordinate */
size_t tc_cursor_get_x();

/* Returns cursor y coordinate */
size_t tc_cursor_get_y();

/* Fixes the position of cursor if terminal window size changed. */
void tc_cursor_fix_pos();

/* Moves the cursor along the x and y axes relative to it's current position by <row_diff>, <col_diff> respectively.
 * Calls the adequate cursor primitive for moving the cursor. Updates struct TCCursor cursor's x and y coordinates if needed. */
void tc_cursor_rel_move(int row_diff, int col_diff);

/* Moves the cursor along the y axis relative to it's current position by <row_diff>.
 * Calls the adequate cursor primitive for moving the cursor. Updates struct TCCursor cursor's x and y coordinates if needed. */
void tc_cursor_rel_move_y(int row_diff);

/* Moves the cursor along the x axis relative to it's current position by <col_diff>.
 * Calls the adequate cursor primitive for moving the cursor. Updates struct TCCursor cursor's x and y coordinates if needed. */
void tc_cursor_rel_move_x(int col_diff);

/* Moves the cursor to absolute 0, 0.
 * Calls the adequate cursor primitive for moving the cursor. Updates struct TCCursor cursor's x and y coordinates if needed. */
void tc_cursor_abs_reset();

/* Moves the cursor along the x axis absolutely to <col>.
 * Calls the adequate cursor primitive for moving the cursor. Updates struct TCCursor cursor's x and y coordinates if needed. */
void tc_cursor_abs_move_x(size_t col);

/* Moves the cursor along the y axis absolutely to <col>.
 * Calls the adequate cursor primitive for moving the cursor. Updates struct TCCursor cursor's x and y coordinates if needed. */
void tc_cursor_abs_move_y(size_t row);

/* Moves the cursor along both x and y axes absolutely to <row>, <col> respectively.
 * Calls the adequate cursor primitive for moving the cursor. Updates struct TCCursor cursor's x and y coordinates if needed. */
void tc_cursor_abs_move(size_t row, size_t col);

// void tc_cursor_print_chr(char c);
// void tc_cursor_print_str(char* str, size_t str_len);

#endif
