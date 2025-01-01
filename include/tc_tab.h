#ifndef TC_TAB_H
#define TC_TAB_H

#include <stddef.h>

struct TCTab;
struct TCWindow;

// void tc_tab_init(struct Tab* tab);
/* Draws the specified <tab> on screen from scratch. Tab coordinates and dimensions are mandated by tc_display. */
void tc_tab_draw(struct TCTab* tab);
// void tc_tab_set_active_window(struct TCWindow* window);

/* Dynamically allocates memory for struct TCTab, initializes it's values and returns a pointer to it.
 * Return value:
 * on success: address of newly allocated struct TCTab.
 * on failure: NULL(malloc failed). */
struct TCTab* tc_tab_init();
/* Performs sizeof(struct TCTab) and returns the value */
size_t tc_tab_get_struct_size();


#endif
