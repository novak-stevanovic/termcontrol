#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "tc_object/window/tc_label.h"
#include "base/tc_shared.h"

void tc_label_init(TCLabel* label)
{
    assert(label != NULL);

    tc_content_window_init((TCContentWindow*)label, _tc_label_pre_draw_func);
}

void tc_label_set_text(TCLabel* label, char* text, size_t limit)
{
    assert(label != NULL);
    assert(text != NULL);

    int i;
    char* label_text_buff = label->_text_buff;
    label->_text_len = strlen(text);
    TCDisplayCell** label_display_cells = ((TCContentWindow*)label)->_content_buff;
    size_t label_height = tc_object_calculate_actual_height((TCObject*)label);
    size_t label_width = tc_object_calculate_actual_width((TCObject*)label);
    assert(label_height > 0);
    assert(label_width > 0);
    for(i = 0; i < strlen(text) && i < limit && i < label_height * label_width; i++)
    {
        (label_display_cells[i / label_width][i % label_width]).content = text[i];
        label_text_buff[i] = text[i];
    }

}
char* tc_label_get_text(TCLabel* label)
{
    assert(label != NULL);

    return label->_text_buff;
}

// void tc_label_set_max_len(TCLabel* label, size_t max_len)
// {
//     assert(label != NULL);
//
//     label->
// }
//
void tc_label_set_fg_color(TCLabel* label, TCColor color)
{
    assert(label != NULL);

    label->_fg_color = color;
    tc_object_draw((TCObject*)label);
}
TCColor tc_label_get_fg_color(TCLabel* label)
{
    assert(label != NULL);

    return label->_fg_color;
}

void tc_label_set_bg_color(TCLabel* label, TCColor color)
{
    assert(label != NULL);

    label->_bg_color = color;
    tc_object_draw((TCObject*)label);
}
TCColor tc_label_get_bg_color(TCLabel* label)
{
    assert(label != NULL);

    return label->_bg_color;
}

void _tc_label_pre_draw_func(TCWindow* window)
{
    TCLabel* label_window = (TCLabel*)window;
    TCContentWindow* content_window = (TCContentWindow*)window;

    int i, j;
    for(i = 0; i < MAX_WINDOW_SIZE_Y; i++)
    {
        for(j = 0; j < MAX_WINDOW_SIZE_X; j++)
        {
            content_window->_content_buff[i][j].content = ' ';
            content_window->_content_buff[i][j].bg_color = TC_COLOR_RED;
            content_window->_content_buff[i][j].fg_color = TC_COLOR_WHITE;
        }
    }
    tc_label_set_text(label_window, label_window->_text_buff, label_window->_text_len);
}
