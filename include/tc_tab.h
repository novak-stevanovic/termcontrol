#ifndef _TC_TAB_H
#define _TC_TAB_H

#include <stddef.h>

#include "tc_window.h"
#include "misc.h"

struct Tab
{
    struct Window* first_window;
};

void tc_tab_init(struct Tab* tab);
void tc_tab_set_active_window(struct Window* window);

#endif
