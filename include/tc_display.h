#ifndef TC_DISPLAY_H
#define TC_DISPLAY_H

#include <stddef.h>

#define MAX_TAB_COUNT 50

struct TCDisplay;
struct TCTab;

extern struct TCDisplay display;

/* Initializes tc_display module. This will set the signal handler of SIGWINCH so it updates struct TCDisplay display whenever the terminal
 * window size changes. It will also initialize it's values. */
void _tc_display_init();

/* Draws the terminal screen from scratch depending on the display outline, current tab... etc. */
void tc_display_draw();

// void tc_display_set_prev_tab();
// void tc_display_set_next_tab();
// void tc_display_set_tab_idx(size_t tab_idx);

/* Returns the current active tab displayed by module tc_display */
struct TCTab* tc_display_get_current_tab();

// size_t tc_display_get_display_height(); ??
// size_t tc_display_get_display_width();

/* Returns start x coordinate of any tab displayed by tc_display. */
size_t tc_display_get_tab_start_x();
/* Returns start y coordinate of any tab displayed by tc_display. */
size_t tc_display_get_tab_start_y();
/* Returns end x coordinate of any tab displayed by tc_display. */
size_t tc_display_get_tab_end_x();
/* Returns end y coordinate of any tab displayed by tc_display. */
size_t tc_display_get_tab_end_y();

#endif
