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
    TCColor fg_color, bg_color;
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

    display.fg_color = TC_COLOR_DEFAULT;
    display.bg_color = TC_COLOR_DEFAULT;
}

void tc_display_draw_tc_display_cell(TCDisplayCell* display_cell, size_t x, size_t y)
{
    TCColor fg_color = tc_display_get_fg_color();
    TCColor bg_color = tc_display_get_bg_color();

    size_t cursor_x = tc_cursor_get_x();
    size_t cursor_y = tc_cursor_get_y();

    tc_cursor_abs_move(y, x);

    tc_prim_set_bg_color(display_cell->bg_color);
    tc_prim_set_fg_color(display_cell->fg_color);
    tc_putchar(display_cell->content);

    tc_cursor_abs_move(cursor_y, cursor_x);
    tc_display_set_fg_color(fg_color);
    tc_display_set_bg_color(bg_color);
}

void _tc_display_draw_tc_window(TCWindow* window)
{
    TCColor fg_color = tc_display_get_fg_color();
    TCColor bg_color = tc_display_get_bg_color();

    size_t cursor_x = tc_cursor_get_x();
    size_t cursor_y = tc_cursor_get_y();

    // printf("%ld %ld", cursor_y, cursor_x);
    assert(window != NULL);

    int w_start_x = window->_base.start_x;
    int w_start_y = window->_base.start_y;
    int w_end_x = window->_base.end_x;
    int w_end_y = window->_base.end_y;

    int i,j;
    for(i = 0; i < w_end_y - w_start_y; i++)
    {
        for(j = 0; j < w_end_x - w_start_x; j++)
        {
            tc_cursor_abs_move(w_start_y + i, w_start_x + j);
            TCDisplayCell* content_cell = tc_window_get_content_at(window, j, i);
            tc_display_draw_tc_display_cell(content_cell, w_start_x + j, w_start_y + i);
        }
    }

    tc_cursor_abs_move(cursor_y, cursor_x);
    tc_display_set_fg_color(fg_color);
    tc_display_set_bg_color(bg_color);
}

void tc_display_draw_tc_object_tree(TCObject* tc_obj)
{
    assert(tc_obj != NULL);
    TCColor fg_color = tc_display_get_fg_color();
    TCColor bg_color = tc_display_get_bg_color();

    tc_object_draw(tc_obj);
    struct Vector* next_to_draw = tc_object_get_next_to_draw(tc_obj);
    if(next_to_draw == NULL) return;
    
    int i;
    for(i = 0; i < vec_get_count(next_to_draw); i++)
    {
        TCObject** tc_obj_ptr = vec_at(next_to_draw, i);
        tc_display_draw_tc_object_tree(*tc_obj_ptr);
    }

    tc_display_set_fg_color(fg_color);
    tc_display_set_bg_color(bg_color);
}

size_t tc_display_get_display_width()
{
    return display.width;
}

size_t tc_display_get_display_height()
{
    return display.height;
}

TCColor tc_display_get_fg_color()
{
    return display.fg_color;
}
TCColor tc_display_get_bg_color()
{
    return display.bg_color;
}
void tc_display_set_fg_color(TCColor color)
{
    tc_prim_set_fg_color(color);
    display.fg_color = color;
}
void tc_display_set_bg_color(TCColor color)
{
    tc_prim_set_bg_color(color);
    display.bg_color = color;
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
