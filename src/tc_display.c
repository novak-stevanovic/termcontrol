#include "tc_display.h"
#include "misc.h"
#include "primitives/tc_erase_prims.h"
#include "tc_color.h"
#include "tc_cursor.h"
#include "tc_shared.h"
#include "vector.h"
#include <assert.h>
#include <stddef.h>
#include <signal.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define VEC_MATRIX_ROW_BP 20,20,vec_get_struct_size()
#define VEC_MATRIX_ELEMENT_BP 50,20,sizeof(TCDisplayCell)

void _update_display_size();
void _update_display_handler(int sig);

// ---------------------------------------------------------------------------------------------------

struct TCDisplay
{
    size_t height, width;
    struct TCDisplayCell** content;
};

struct TCDisplay display = {0};

void _tc_display_init()
{
    prim_erase_screen();
    struct sigaction new_sigact;
    new_sigact.sa_handler = _update_display_handler;
    int status = sigaction(SIGWINCH, &new_sigact, NULL);
    assert(status == 0);

    display.content = (struct TCDisplayCell**)malloc(sizeof(struct TCDisplayCell*) * MAX_WINDOW_SIZE_Y);
    int i, j;
    for(i = 0; i < MAX_WINDOW_SIZE_Y; i++)
    {
        display.content[i] = (struct TCDisplayCell*)malloc(sizeof(struct TCDisplayCell) * MAX_WINDOW_SIZE_X);
        for(j = 0; j < MAX_WINDOW_SIZE_X; j++)
        {
            display.content[i][j].content = 'u';
            display.content[i][j].bg_color = TC_COLOR_BLUE;
            display.content[i][j].fg_color = TC_COLOR_RED;
        }
    }
    _update_display_size();

}

void tc_display_draw_tc_window(struct TCWindow* tc_window)
{
    assert(tc_window != NULL);

    int w_start_x = tc_window->tc_object.start_x;
    int w_start_y = tc_window->tc_object.start_y;
    int w_end_x = tc_window->tc_object.end_x;
    int w_end_y = tc_window->tc_object.end_y;

    int i,j;
    for(i = w_start_y; i <= w_end_y; i++)
    {
        for(j = w_start_x; j <= w_end_x; j++)
        {
            tc_cursor_abs_move(i, j);
            putchar(tc_window->content[i - w_start_y][j - w_start_x].content);
        }
    }
}

size_t tc_display_get_display_width()
{
    return display.width;
}

size_t tc_display_get_display_height()
{
    return display.height;
}

// ------------------------------------------------------------------

void _update_display_handler(int sig)
{
    _update_display_size();
}

void _update_display_size()
{
    struct winsize win_size;

    int status = ioctl(STDOUT_FILENO, TIOCGWINSZ, &win_size);

    assert(status == 0);

    display.height = win_size.ws_row;
    display.width = win_size.ws_col;

    //TODO
    // tc_cursor_fix_pos();

    printf("%ld %ld\n", display.height, display.width);
}
