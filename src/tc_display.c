#include "tc_display.h"
#include "misc.h"
#include "primitives/tc_erase_prims.h"
#include "tc_color.h"
#include "vector.h"
#include <assert.h>
#include <stddef.h>
#include <signal.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define VEC_INIT_ROW_COUNT 0
#define VEC_ROW_RESIZE_COUNT 3
#define VEC_INIT_COL_COUNT 0
#define VEC_COL_RESIZE_COUNT 5

void _update_display_size();
void _update_display_handler(int sig);
void _conform_display_content_vector();

struct Vector* col_vec_blueprint; // blueprint for adding element
struct TCDisplayCell display_cell_blueprint;

void _init_blueprints();

// ---------------------------------------------------------------------------------------------------

struct TCDisplay
{
    size_t height, width;
    struct Vector* content;
};

struct TCDisplay display = {0};

void _tc_display_init()
{
    _init_blueprints();
    prim_erase_screen();
    struct sigaction new_sigact;
    new_sigact.sa_handler = _update_display_handler;
    int status = sigaction(SIGWINCH, &new_sigact, NULL);
    assert(status == 0);

    display.content = vec_init(VEC_INIT_ROW_COUNT, VEC_ROW_RESIZE_COUNT, vec_get_struct_size());

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

void _conform_display_content_vector()
{
    misc_vec_conform(display.content, display.height, col_vec_blueprint);
    int i;
    for(i = 0; i < vec_get_count(display.content); i++)
    {
        printf("%d", i);
        struct Vector* curr_row = vec_at(display.content, i);
        misc_vec_conform(curr_row, display.width, &display_cell_blueprint);
    }
}

void _init_blueprints()
{
    col_vec_blueprint = vec_init(VEC_INIT_COL_COUNT, VEC_COL_RESIZE_COUNT, sizeof(struct TCDisplayCell));

    display_cell_blueprint.content = 'x';
    display_cell_blueprint.bg_color = DEFAULT;
    display_cell_blueprint.fg_color = MAGENTA;
}
