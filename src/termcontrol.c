#include "termcontrol.h"
#include "tc_display.h"
#include "tc_cursor.h"

void tc_init()
{
    _tc_display_init();
    _tc_cursor_init();
}
