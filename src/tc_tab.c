#include "tc_tab.h"

void tc_tab_init(struct TCTab* tc_tab, int color)
{
    tc_container_init((struct TCContainer*)tc_tab, tc_tab_init_func, tc_tab_draw_func);
    tc_tab->color = color;
}

void tc_tab_init_func(void* tc_tab)
{

}

void tc_tab_draw_func(void* tc_tab)
{
    tc_container_draw(tc_tab);
}
