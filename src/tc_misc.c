#include "tc_misc.h"
#include <assert.h>
#include <stddef.h>
#include <string.h>

size_t misc_conform(int min, int suggested, int max)
{
    if(suggested < min)
        return min;
    else if(suggested > max)
        return max;
    else
        return suggested;
}
