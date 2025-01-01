#include "tc_tab.h"
#include "tc_display.h"
#include "tc_window.h"
#include <stdlib.h>

struct TCTab
{
    struct TCWindow* left;
    struct TCWindow* right;
};

void tc_tab_draw(struct TCTab* tab)
{
   if(tab->right == NULL)
   {
       tc_window_set_start_x(tab->left, tc_display_get_tab_start_x());
       tc_window_set_start_y(tab->left, tc_display_get_tab_start_y());
       tc_window_set_end_x(tab->left, tc_display_get_tab_end_x());
       tc_window_set_end_y(tab->left, tc_display_get_tab_end_y());

       tc_window_draw(tab->left);
   }
    
}

void tc_tab_draw_outline(struct TCTab* tab)
{
}

struct TCTab* tc_tab_init()
{
    struct TCTab* new = (struct TCTab*)malloc(sizeof(struct TCTab));

    if(new == NULL) return NULL;

    new->left = tc_window_init();
    new->right = NULL;

    return new;
}

size_t tc_tab_get_struct_size()
{
    return sizeof(struct TCTab);
}
