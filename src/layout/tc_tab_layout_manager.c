#include "layout/tc_tab_layout_manager.h"
#include "tc_object/container/tc_tab.h"

void tc_tab_lm_init(TCTabLayoutManager* tab_lm, TCTab* tab)
{
    tc_lm_init((TCLayoutManager*)tab_lm, (TCLayoutContainer*)tab, _tc_tab_lm_arrange_func);
    tab_lm->left = NULL;
    tab_lm->right = NULL;
}

void _tc_tab_lm_arrange_func(TCLayoutManager* tab_lm)
{
    //TODO
}
