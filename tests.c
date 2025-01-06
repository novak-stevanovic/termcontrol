#include <termios.h>
#include <stdio.h>
#include <unistd.h>

#include "base/tc_display.h"
#include "tc_component_base/tc_window.h"
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

    char str[20];

    while(1)
    {
        read(STDIN_FILENO, str, 1);
        if(str[0] == 'q') break;
        else printf("%c", str[0]);
    }

    reset_opts();
    return 0;
}

