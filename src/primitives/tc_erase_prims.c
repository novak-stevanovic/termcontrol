#include "primitives/tc_erase_prims.h"
#include "primitives/tc_primitives.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void tc_prim_erase_screen()
{
    snprintf(code_buff, CODE_BUFF_LEN, ERASE_ENTIRE_SCREEN_CODE);
    WRITE_CODE;
}

void tc_prim_erase_line()
{
    snprintf(code_buff, CODE_BUFF_LEN, ERASE_ENTIRE_LINE_CODE);
    WRITE_CODE;
}

void tc_prim_erase_line_start_to_cursor()
{
    snprintf(code_buff, CODE_BUFF_LEN, ERASE_START_TO_CURSOR_LINE_CODE);
    WRITE_CODE;
}

void tc_prim_erase_line_cursor_to_end()
{
    snprintf(code_buff, CODE_BUFF_LEN, ERASE_CURSOR_TO_END_LINE_CODE);
    WRITE_CODE;
}
