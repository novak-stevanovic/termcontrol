#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "tc_display.h"
#include "tc_window.h"
#include "tc_cursor.h"
#include "assert.h"
#include "misc.h"

void _update_display_info();
void _update_display_handler(int sig);

// ----------------------------------------------------------------------------

struct DisplayInfo
{
    size_t _width, _height;
    struct Tab tabs[MAX_TAB_COUNT];
    size_t _tab_count;
    size_t curr_tab_idx;
};

struct DisplayInfo display_info;

void _tc_display_init()
{
    struct sigaction new_sigact;
    new_sigact.sa_handler = _update_display_handler;

    int status = sigaction(SIGWINCH, &new_sigact, NULL);

    ASSERT(status == 0, "Failure to set handler.");

    _update_display_info();
}

void _update_display_handler(int sig)
{
    _update_display_info();
}

void _update_display_info()
{
    struct winsize win_size;

    int status = ioctl(STDOUT_FILENO, TIOCGWINSZ, &win_size);

    ASSERT(status == 0, "Failure to get window size.");

    display_info._height = win_size.ws_row;
    display_info._width = win_size.ws_col;

    // tc_cursor_fix_pos();
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
    ASSERT(display_info._width > 0, "INVALID DISPLAY WIDTH");
    return display_info._width - 1;
}

size_t tc_display_get_tab_end_y()
{
    ASSERT(display_info._height > 0, "INVALID DISPLAY HEIGHT");
    return display_info._height - 1;
}
