#ifndef TC_LAYOUT_MANAGER_H
#define TC_LAYOUT_MANAGER_H

struct TCLayoutContainer;

typedef struct TCLayoutManager // ABSTRACT
{
    struct TCLayoutContainer* _container;
    void (*_arrange_func)(struct TCLayoutManager*);
} TCLayoutManager;

void tc_lm_init(TCLayoutManager* layout_manager,
        struct TCLayoutContainer* layout_container,
        void (*arrange_func)(struct TCLayoutManager*));

void tc_lm_arrange(TCLayoutManager* tc_lm);

struct TCLayoutContainer* tc_lm_get_container(TCLayoutManager* layout_manager);

#endif
