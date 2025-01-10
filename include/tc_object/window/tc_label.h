#ifndef TC_LABEL_H
#define TC_LABEL_H

#include "primitives/tc_color.h"
#include "tc_content_window.h"
#include <stdio.h>

typedef struct TCLabel
{
    struct TCContentWindow _base;
    size_t _text_len;
    enum TCColor _fg_color, _bg_color;
} TCLabel;

void tc_label_init(TCLabel* label);

void tc_label_set_text(TCLabel* label, char* text, size_t limit);
char* tc_label_get_text(TCLabel* label);

void tc_label_set_max_len(TCLabel* label, size_t max_len);

void tc_label_set_fg_color(TCLabel* label, enum TCColor color);
enum TCColor tc_label_get_fg_color(TCLabel* label);

void tc_label_set_bg_color(TCLabel* label, enum TCColor color);
enum TCColor tc_label_get_bg_color(TCLabel* label);

#endif
