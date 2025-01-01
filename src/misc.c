#include <stddef.h>

int misc_conform(int min, int val, int max)
{
    if(val < min)
        return min;
    else if(val > max)
        return max;
    else
        return val;
}
