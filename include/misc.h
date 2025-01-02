#ifndef MISC_H
#define MISC_H

#include <stddef.h>
#include "vector.h"

#define PERFORM(act, times) for(int uniq_it = 0; uniq_it < (times); uniq_it++) act

size_t misc_conform(int min, int suggested, int max);
void misc_vec_conform(struct Vector* vector, size_t desired_count, void* data);

#endif
