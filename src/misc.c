#include "misc.h"
#include <assert.h>
#include <stddef.h>

size_t misc_conform(int min, int suggested, int max)
{
    if(suggested < min)
        return min;
    else if(suggested > max)
        return max;
    else
        return suggested;
}

void misc_vec_conform(struct Vector* vector, size_t desired_count, void* data)
{
    assert(vector != NULL);

    size_t vec_count = vec_get_count(vector);

    if(vec_count > desired_count) PERFORM(vec_pop(vector), vec_count - desired_count);
    else
    {
        assert(data != NULL);
        PERFORM(vec_append(vector, data), vec_count - desired_count);
    }
}
