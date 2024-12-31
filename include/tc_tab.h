#ifndef TC_TAB_H
#define TC_TAB_H

#include <stddef.h>

struct TCTab;
struct TCWindow;

// void tc_tab_init(struct Tab* tab);
/* Draws the specified <tab> on screen from scratch. Tab coordinates and dimensions are mandated by tc_display. */
void tc_tab_draw(struct TCTab* tab);
// void tc_tab_set_active_window(struct TCWindow* window);

#endif
