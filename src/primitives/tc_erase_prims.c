#include "primitives/tc_erase_prims.h"
#include <stddef.h>
#include <string.h>
#include <unistd.h>

void prim_erase_screen()
{
    write(STDOUT_FILENO, ERASE_ENTIRE_SCREEN_CODE, strlen(ERASE_ENTIRE_SCREEN_CODE));
}

void prim_erase_line()
{
    write(STDOUT_FILENO, ERASE_ENTIRE_LINE_CODE, strlen(ERASE_ENTIRE_LINE_CODE));
}

void prim_erase_line_start_to_cursor()
{
    write(STDOUT_FILENO, ERASE_START_TO_CURSOR_LINE_CODE, strlen(ERASE_START_TO_CURSOR_LINE_CODE));
}

void prim_erase_line_cursor_to_end()
{
    write(STDOUT_FILENO, ERASE_CURSOR_TO_END_LINE_CODE, strlen(ERASE_CURSOR_TO_END_LINE_CODE));
}
