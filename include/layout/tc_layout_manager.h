#ifndef TC_LAYOUT_MANAGER_H
#define TC_LAYOUT_MANAGER_H

struct TCLayoutContainer;

typedef struct TCLayoutManager // ABSTRACT
{
    struct TCLayoutContainer* _container;
    void (*arrange)(struct TCLayoutManager*);
} TCLayoutManager;

#endif
