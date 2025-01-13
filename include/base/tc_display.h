#ifndef TC_DISPLAY_H
#define TC_DISPLAY_H

#include <stddef.h>
#include "tc_object/window/tc_window.h"

#define SIGWINCH 28

typedef struct TCDisplay TCDisplay;

extern struct TCDisplay display;

void _tc_display_init();

void tc_display_draw_tc_display_cell(TCDisplayCell* display_cell, size_t x, size_t y);
void tc_display_draw_tc_object_tree(TCObject* tc_obj);
void _tc_display_draw_tc_window(TCWindow* window);

size_t tc_display_get_display_width();
size_t tc_display_get_display_height();

TCColor tc_display_get_fg_color();
TCColor tc_display_get_bg_color();
void tc_display_set_fg_color(TCColor color);
void tc_display_set_bg_color(TCColor color);

#endif
