#ifndef TC_ERASE_PRIMS_H
#define TC_ERASE_PRIMS_H

#define ERASE_ENTIRE_SCREEN_CODE "\e[2J"
#define ERASE_CURSOR_TO_END_LINE_CODE "\e[0K"
#define ERASE_START_TO_CURSOR_LINE_CODE "\e[1K"
#define ERASE_ENTIRE_LINE_CODE "\e[2K"

void tc_erase_screen();

void tc_erase_line();
void tc_erase_line_start_to_cursor();
void tc_erase_line_cursor_to_end();

#endif
