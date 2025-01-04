#ifndef TC_DISPLAY_H
#define TC_DISPLAY_H

#include <stddef.h>
#include "base/tc_window.h"
#include "tc_color.h"

#define SIGWINCH 28

struct TCDisplay;

extern struct TCDisplay display;

void _tc_display_init();

void tc_display_draw_tc_window(struct TCWindow* tc_window);

size_t tc_display_get_display_width();
size_t tc_display_get_display_height();

#endif
