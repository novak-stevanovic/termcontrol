#ifndef TC_DISPLAY_H
#define TC_DISPLAY_H

#include <stddef.h>

#define SIGWINCH 28

#define MAX_TAB_COUNT 50

struct Display;
struct Tab;

extern struct Display display;

void _tc_display_init();

void tc_display_draw();

void tc_display_show_prev_tab();
void tc_display_show_next_tab();
void tc_display_show_tab(struct Tab* tab);
void tc_display_show_tab_idx(size_t tab_idx);

size_t tc_display_get_display_height();
size_t tc_display_get_display_width();

size_t tc_display_get_tab_start_x();
size_t tc_display_get_tab_start_y();
size_t tc_display_get_tab_end_x();
size_t tc_display_get_tab_end_y();

#endif
