#ifndef TC_TAB_H
#define TC_TAB_H

#include <stddef.h>

#include "tc_window.h"
#include "misc.h"

struct Tab;

void tc_tab_init(struct Tab* tab);
void tc_tab_set_active_window(struct Window* window);

#endif
