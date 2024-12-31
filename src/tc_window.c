#include "tc_window.h"
#include "tc_cursor.h"
#include <stdio.h>

struct TCWindow
{
    size_t start_x;
    size_t start_y;

    size_t end_x;
    size_t end_y;

    char** content;
};

void tc_window_draw(struct TCWindow* window)
{
    tc_cursor_abs_move(window->start_x, window->start_y);

    size_t start_x = window->start_x; 
    size_t start_y = window->start_y; 

    size_t end_x = window->end_x; 
    size_t end_y = window->end_y; 

    int i, j;
    for(i = start_y; i <= end_y; i++)
    {
        for(j = start_x; j <= end_x; j++)
        {
            putchar('A' + j);
        }
    }
}

size_t tc_window_get_start_x(struct TCWindow* window)
{
    return window->start_x;
}

size_t tc_window_get_start_y(struct TCWindow* window)
{
    return window->start_y;
}

size_t tc_window_get_end_x(struct TCWindow* window)
{
    return window->end_x;
}

size_t tc_window_get_end_y(struct TCWindow* window)
{
    return window->end_y;
}

void tc_window_set_start_x(struct TCWindow* window, size_t start_x)
{
    window->start_x = start_x;
}

void tc_window_set_start_y(struct TCWindow* window, size_t start_y)
{
    window->start_y = start_y;
}

void tc_window_set_end_x(struct TCWindow* window, size_t end_x)
{
    window->end_x = end_x;
}

void tc_window_set_end_y(struct TCWindow* window, size_t end_y)
{
    window->end_y = end_y;
}
