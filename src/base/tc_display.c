#include "base/tc_display.h"
#include "primitives/tc_erase_prims.h"
#include "primitives/tc_color.h"
#include "base/tc_cursor.h"
#include "base/tc_shared.h"
#include "vector.h"
#include <assert.h>
#include <stddef.h>
#include <signal.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

void _update_display_size();
void _update_display_handler(int sig);
void _tc_display_content_init();

// ---------------------------------------------------------------------------------------------------

typedef struct TCDisplay
{
    size_t height, width;
    TCDisplayCell** content;
} TCDisplay;

TCDisplay display = {0};

void _tc_display_init()
{
    tc_prim_erase_screen();
    struct sigaction new_sigact;
    new_sigact.sa_handler = _update_display_handler;
    int status = sigaction(SIGWINCH, &new_sigact, NULL);
    assert(status == 0);

    _tc_display_content_init();
    _update_display_size();
}

void _tc_display_content_init()
{
    display.content = (TCDisplayCell**)malloc(sizeof(TCDisplayCell*) * MAX_WINDOW_SIZE_Y);
    int i, j;
    for(i = 0; i < MAX_WINDOW_SIZE_Y; i++)
    {
        display.content[i] = (TCDisplayCell*)malloc(sizeof(TCDisplayCell) * MAX_WINDOW_SIZE_X);
        for(j = 0; j < MAX_WINDOW_SIZE_X; j++)
        {
            display.content[i][j].content = 'u';
            display.content[i][j].bg_color = TC_COLOR_BLUE;
            display.content[i][j].fg_color = TC_COLOR_RED;
        }
    }
}

void tc_display_draw_tc_window(TCWindow* tc_window)
{
    assert(tc_window != NULL);

    int w_start_x = tc_window->_base.start_x;
    int w_start_y = tc_window->_base.start_y;
    int w_end_x = tc_window->_base.end_x;
    int w_end_y = tc_window->_base.end_y;

    int i,j;
    for(i = w_start_y; i < w_end_y; i++)
    {
        for(j = w_start_x; j < w_end_x; j++)
        {
            tc_cursor_abs_move(i, j);
            TCDisplayCell* content_cell = tc_window->get_content_at_func(tc_window, j, i);
            putchar(content_cell->content);
        }
    }
}

void tc_display_draw_tc_object_tree(TCContainer* tc_container)
{
    if(tc_container == NULL) return;
    assert(tc_container->_children != NULL);

    tc_container->_base._draw_func(tc_container);

    int i;
    for(i = 0; i < vec_get_count(tc_container->_children); i++)
    {
        TCObject** curr_child = vec_at(tc_container->_children, i); //TODO ???
        assert((*curr_child)->_draw_func != NULL);
        (*curr_child)->_draw_func(*curr_child);
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

    tc_cursor_conform_pos_to_scr();

    printf("%ld %ld\n", display.height, display.width);
}
