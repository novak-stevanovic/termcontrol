#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "tc_display.h"
#include "tc_cursor.h"
#include "tc_tab.h"
#include "assert.h"
#include "array.h"
#include "primitives/tc_erase_prims.h"

#define SIGWINCH 28

void _update_display_size();
void _update_display_handler(int sig);

// ----------------------------------------------------------------------------

struct TCDisplay
{
    size_t height, width;
    struct Array* tabs;
    int current_tab_idx;
};

struct TCDisplay display;

void _tc_display_init()
{
    prim_erase_screen();
    struct sigaction new_sigact;
    new_sigact.sa_handler = _update_display_handler;
    int status = sigaction(SIGWINCH, &new_sigact, NULL);
    assert(status == 0);

    _update_display_size();
    display.current_tab_idx = 0;
    display.tabs = arr_init_dynamic(MAX_TAB_COUNT, tc_tab_get_struct_size());
    struct TCTab* first_tab = tc_tab_init();
    arr_append(display.tabs, first_tab);
    free(first_tab);
}

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

    // tc_cursor_fix_pos();
}

void tc_display_draw()
{
    size_t cursor_x = tc_cursor_get_x();
    size_t cursor_y = tc_cursor_get_y();

    // tc_display_draw_outline()
    struct TCTab* current_tab = tc_display_get_current_tab();
    tc_tab_draw(current_tab);

    tc_cursor_abs_move(cursor_y, cursor_x);

}

struct TCTab* tc_display_get_current_tab()
{
    return arr_at(display.tabs, display.current_tab_idx);
}

size_t tc_display_get_tab_start_x()
{
    return 0;
}

size_t tc_display_get_tab_start_y()
{
    return 1;
}

size_t tc_display_get_tab_end_x()
{
    assert(display.width > 0);
    return display.width - 2;
}

size_t tc_display_get_tab_end_y()
{
    assert(display.height > 0);
    return display.height - 2;
}

size_t tc_display_get_display_height()
{
    return display.height;
}

size_t tc_display_get_display_width()
{
    return display.width;
}

size_t tc_display_get_struct_size()
{
    return sizeof(struct TCDisplay);
}
