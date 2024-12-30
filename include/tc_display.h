#ifndef _TC_DISPLAY_H
#define _TC_DISPLAY_H

#include <stddef.h>
#include "tc_tab.h"

#define SIGWINCH 28

#define MAX_TAB_COUNT 50

struct DisplayInfo;

extern struct DisplayInfo display_info;

void _tc_display_init();
void _tc_display_show_tab(struct Tab* tab);

size_t tc_display_get_display_height();
size_t tc_display_get_display_width();

size_t tc_display_get_tab_start_x();
size_t tc_display_get_tab_start_y();
size_t tc_display_get_tab_end_x();
size_t tc_display_get_tab_end_y();

#endif
