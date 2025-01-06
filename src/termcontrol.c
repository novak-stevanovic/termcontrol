#include "termcontrol.h"
#include "base/tc_display.h"
#include "base/tc_cursor.h"

void tc_init()
{
    _tc_display_init();
    _tc_cursor_init();
}
