#ifndef TC_LABEL_H
#define TC_LABEL_H

#include <stdio.h>

#include "primitives/tc_color.h"
#include "tc_content_window.h"

#define TC_LABEL_MAX_CONTENT_LENGTH 500

typedef struct TCLabel
{
    TCContentWindow _base;
    size_t _text_len;
    TCColor _fg_color, _bg_color;
    char _text_buff[TC_LABEL_MAX_CONTENT_LENGTH];
} TCLabel;

void tc_label_init(TCLabel* label);

void tc_label_set_text(TCLabel* label, char* text, size_t limit);
char* tc_label_get_text(TCLabel* label);

// void tc_label_set_max_len(TCLabel* label, size_t max_len);

void tc_label_set_fg_color(TCLabel* label, TCColor color);
TCColor tc_label_get_fg_color(TCLabel* label);

void tc_label_set_bg_color(TCLabel* label, TCColor color);
TCColor tc_label_get_bg_color(TCLabel* label);

void _tc_label_pre_draw_func(TCWindow* window);

#endif
