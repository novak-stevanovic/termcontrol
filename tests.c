#include <termios.h>
#include <stdio.h>
#include <unistd.h>

#include "tc_display.h"
#include "base/tc_window.h"
#include "termcontrol.h"

#include "primitives/tc_style_prims.h"

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

void a()
{
}

int main(int argc, char *argv[])
{
    printf("In main\n");
    load_init_opts();
    conf_term_opts();

    tc_init();
    // printf(COLOR_RED_BG_CODE);
    // printf(COLOR_YELLOW_FG_CODE);

    // tc_display_draw();
    struct TCWindow w;
    tc_window_init(&w, a, a);

    w.tc_object.start_x = 1;
    w.tc_object.start_y = 10;

    w.tc_object.end_x = 65;
    w.tc_object.end_y = 25;

    tc_display_draw_tc_window(&w);

    char str[10];
    while(1)
    {
        read(STDIN_FILENO, str, 1);
        if(str[0] == 'q') break;
        else printf("%c", str[0]);
    }

    reset_opts();
    return 0;
}

