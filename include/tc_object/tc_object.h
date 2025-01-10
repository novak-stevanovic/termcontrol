#ifndef TC_OBJECT_H
#define TC_OBJECT_H

#include <stddef.h>

struct Array;

typedef struct TCObject // "ABSTRACT"
{
    size_t start_x, start_y, end_x, end_y;
    size_t _pref_height, _pref_width;

    void (*_draw_func)(void*); // arrange container or draw window on display
    struct Vector* (*_get_next_to_draw_func)(void*); // after this object has been drawn, return a vector of this obj's children(if existent)
                                                     // that need to be drawn next.
} TCObject;

void tc_object_init(TCObject* tc_obj, void (*draw_func)(void*));

void tc_object_draw(TCObject* tc_obj);
struct Vector* tc_object_get_next_to_draw(TCObject* tc_obj);

void tc_object_set_positions(TCObject* tc_obj, size_t start_x, size_t start_y, size_t end_x, size_t end_y);
void tc_object_set_pref_height(TCObject* tc_obj, size_t pref_height);
void tc_object_set_pref_width(TCObject* tc_obj, size_t pref_width);
void tc_object_set_pref_size(TCObject* tc_obj, size_t pref_height, size_t pref_width);

size_t tc_object_get_pref_height(TCObject* tc_obj);
size_t tc_object_get_pref_width(TCObject* tc_obj);

#endif

