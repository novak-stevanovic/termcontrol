#ifndef TC_WINDOW_H
#define TC_WINDOW_H

#include <stddef.h>

struct TCWindow;

/* Draws the specified <window> from scratch. It's dimensions are mandated by the container struct TCTab */
void tc_window_draw(struct TCWindow* window);

/* Returns specified <window>'s start x coordinate. */
size_t tc_window_get_start_x(struct TCWindow* window);
/* Returns specified <window>'s start y coordinate. */
size_t tc_window_get_start_y(struct TCWindow* window);
/* Returns specified <window>'s end x coordinate. */
size_t tc_window_get_end_x(struct TCWindow* window);
/* Returns specified <window>'s end y coordinate. */
size_t tc_window_get_end_y(struct TCWindow* window);

/* Sets the specified <window>'s start x coordinate to <start_x>. This is to be used only by the parent TCTab. */
void tc_window_set_start_x(struct TCWindow* window, size_t start_x);
/* Sets the specified <window>'s start y coordinate to <start_y>. This is to be used only by the parent TCTab. */
void tc_window_set_start_y(struct TCWindow* window, size_t start_y);
/* Sets the specified <window>'s end x coordinate to <end_x>. This is to be used only by the parent TCTab. */
void tc_window_set_end_x(struct TCWindow* window, size_t end_x);
/* Sets the specified <window>'s end y coordinate to <end_y>. This is to be used only by the parent TCTab. */
void tc_window_set_end_y(struct TCWindow* window, size_t end_y);

/* Returns window content for specified <window>. This content's dimensions are the same as <window>'s. Only for each row, an extra \0 is added. */
char** tc_window_get_content(struct TCWindow* window);
/* Sets the window content for specified <window> to <content>. Keep in mind the dimensions of <content> as window will think the dimensions adhere to it's size */
void tc_window_set_content(struct TCWindow* window, char** content);

#endif
