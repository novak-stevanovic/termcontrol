#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <stdio.h>
#include <unistd.h>

#include "base/tc_cursor.h"
#include "base/tc_display.h"
#include "base/tc_display_cell.h"
#include "base/tc_print_controller.h"
#include "primitives/tc_color.h"
#include "primitives/tc_style_prims.h"
#include "tc_object/window/tc_content_window.h"
#include "termcontrol.h"

struct termios init_opts;

void conf_term_opts()
{
    struct termios init_opts_cpy = init_opts;

    // cfmakeraw(&init_opts_cpy);

    init_opts_cpy.c_lflag &= ~(ICANON);
    init_opts_cpy.c_lflag &= ~(ECHO);
    init_opts_cpy.c_lflag &= ~(ISIG);
    init_opts_cpy.c_lflag &= ~(ECHONL);

    init_opts_cpy.c_iflag &= (IGNBRK);
    init_opts_cpy.c_iflag &= (BRKINT);

    // init_opts_cpy.c_iflag &= (INLCR);
    // init_opts_cpy.c_iflag &= (IGNCR);

    setvbuf(stdout, NULL, _IONBF, 0);

    tcsetattr(STDOUT_FILENO, TCSAFLUSH, &init_opts_cpy);
}

void load_init_opts()
{
    tcgetattr(STDOUT_FILENO, &init_opts);
}

void reset_opts()
{
    tcsetattr(STDOUT_FILENO, TCSAFLUSH, &init_opts);
}

int main(int argc, char *argv[])
{
    printf("In main\n");
    // printf("\033[?7l"); // Isključuje line wrapping    
    load_init_opts();
    conf_term_opts();

    tc_init();

    char str[20];
    //tc_prim_set_bg_color(TC_COLOR_BLUE);

    TCContentWindow* tc = (TCContentWindow*)malloc(sizeof(TCContentWindow));
    tc_content_window_init(tc);

    ((TCObject*)tc)->start_x = 20;
    ((TCObject*)tc)->start_y = 20;
    ((TCObject*)tc)->end_x = 28;
    ((TCObject*)tc)->end_y = 21;

    int i;
        size_t cursor_x = tc_cursor_get_x();
        size_t cursor_y = tc_cursor_get_y();
        char buff[20];
        snprintf(buff, 20, "%ld %ld", cursor_x, cursor_y);

        TCDisplayCell tcd_bp = (TCDisplayCell) {
            .content = '0',
            .bg_color = TC_COLOR_YELLOW,
            .fg_color = TC_COLOR_GREEN
        };
        for(i = 0; i < strlen(buff); i++)
        {
            tcd_bp.content = buff[i];
            tc_content_window_set_content_at(tc, i, 0, &tcd_bp);
        }
        tc_display_draw_tc_window((TCWindow*)tc);
    while(1)
    {
        read(STDIN_FILENO, str, 1);
        if(str[0] == 'q') break;
        else if(str[0] == 'c') tc_prim_set_bg_color(TC_COLOR_GREEN);
        tc_putchar(str[0]);
        size_t cursor_x = tc_cursor_get_x();
        size_t cursor_y = tc_cursor_get_y();
        char buff[20];
        snprintf(buff, 20, "%ld %ld", cursor_x, cursor_y);

        TCDisplayCell tcd_bp = (TCDisplayCell) {
            .content = '0',
            .bg_color = TC_COLOR_YELLOW,
            .fg_color = TC_COLOR_GREEN
        };
        for(i = 0; i < strlen(buff); i++)
        {
            tcd_bp.content = buff[i];
            tc_content_window_set_content_at(tc, i, 0, &tcd_bp);
        }
        tc_display_draw_tc_window((TCWindow*)tc);
    }

    reset_opts();
    return 0;
}

