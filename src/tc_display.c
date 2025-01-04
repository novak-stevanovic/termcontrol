#include "tc_display.h"
#include "misc.h"
#include "primitives/tc_erase_prims.h"
#include "tc_color.h"
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
void _conform_display_content_vector();

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
        display.content[i] = (struct TCDisplayCell*)malloc(sizeof(char) * MAX_WINDOW_SIZE_X);
        for(j = 0; j < MAX_WINDOW_SIZE_X; j++)
        {
            display.content[i][j].content = 'u';
            display.content[i][j].bg_color = TC_COLOR_BLUE;
            display.content[i][j].fg_color = TC_COLOR_RED;
        }
    }
    _update_display_size();

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

    _conform_display_content_vector();
    printf("%ld %ld\n", display.height, display.height);
}
