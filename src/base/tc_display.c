#include <assert.h>
#include <stddef.h>
#include <signal.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "base/tc_display.h"
#include "base/tc_print_controller.h"
#include "primitives/tc_erase_prims.h"
#include "base/tc_cursor.h"
#include "primitives/tc_style_prims.h"
#include "vector.h"

void _tc_display_update_display_size();
void _tc_display_update_display_handler(int sig);
void _tc_display_content_init();

// ---------------------------------------------------------------------------------------------------

typedef struct TCDisplay
{
    size_t height, width;
} TCDisplay;

TCDisplay display = {0};

void _tc_display_init()
{
    tc_prim_erase_screen();
    struct sigaction new_sigact;
    new_sigact.sa_handler = _tc_display_update_display_handler;
    int status = sigaction(SIGWINCH, &new_sigact, NULL);
    assert(status == 0);

    // _tc_display_content_init();
    _tc_display_update_display_size();
}

void tc_display_draw_tc_display_cell(TCDisplayCell* display_cell, size_t x, size_t y)
{
    size_t cursor_x = tc_cursor_get_x();
    size_t cursor_y = tc_cursor_get_y();

    tc_cursor_abs_move(y, x);

    tc_prim_set_bg_color(display_cell->bg_color);
    tc_prim_set_fg_color(display_cell->fg_color);
    tc_putchar(display_cell->content);

    tc_cursor_abs_move(cursor_y, cursor_x);
}

void tc_display_draw_tc_window(TCWindow* window)
{
    assert(window != NULL);

    int w_start_x = window->_base.start_x;
    int w_start_y = window->_base.start_y;
    int w_end_x = window->_base.end_x;
    int w_end_y = window->_base.end_y;

    int i,j;
    for(i = w_start_y; i < w_end_y; i++)
    {
        for(j = w_start_x; j < w_end_x; j++)
        {
            tc_cursor_abs_move(i, j);
            TCDisplayCell* content_cell = tc_window_get_content_at(window, j, i);
            tc_display_draw_tc_display_cell(content_cell, j, i);
        }
    }
}

void tc_display_draw_tc_object_tree(TCObject* tc_obj)
{
    assert(tc_obj != NULL);

    tc_object_draw(tc_obj);
    struct Vector* next_to_draw = tc_object_get_next_to_draw(tc_obj);
    if(next_to_draw == NULL) return;
    
    int i;
    for(i = 0; i < vec_get_count(next_to_draw); i++)
    {
        TCObject** tc_obj_ptr = vec_at(next_to_draw, i);
        tc_display_draw_tc_object_tree(*tc_obj_ptr);
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

void _tc_display_update_display_handler(int sig)
{
    _tc_display_update_display_size();
}

void _tc_display_update_display_size()
{
    struct winsize win_size;

    int status = ioctl(STDOUT_FILENO, TIOCGWINSZ, &win_size);

    assert(status == 0);

    display.height = win_size.ws_row;
    display.width = win_size.ws_col;

    tc_cursor_conform_pos_to_scr();

    // printf("%ld %ld\n", display.height, display.width);
}
