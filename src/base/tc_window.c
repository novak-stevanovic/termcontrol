#include "base/tc_window.h"
#include "base/tc_object.h"

#include "tc_shared.h"
#include "vector.h"

void tc_window_init(struct TCWindow* tc_window, void (*init_func)(void*), void (*draw_func)(void*))
{
    tc_object_init(&tc_window->tc_object, init_func, draw_func);

    tc_window->content = (struct TCDisplayCell**)malloc(sizeof(struct TCDisplayCell*) * MAX_WINDOW_SIZE_Y);
    int i, j;
    for(i = 0; i < MAX_WINDOW_SIZE_Y; i++)
    {
        tc_window->content[i] = (struct TCDisplayCell*)malloc(sizeof(struct TCDisplayCell) * MAX_WINDOW_SIZE_X);
        for(j = 0; j < MAX_WINDOW_SIZE_X; j++)
        {
            tc_window->content[i][j].content = 'u';
            tc_window->content[i][j].bg_color = TC_COLOR_RED;
            tc_window->content[i][j].fg_color = TC_COLOR_BLACK;
        }
    }
}

