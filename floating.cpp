#include<math.h>

#include "floating.h"

bool Compare(double a, double b)
{
    return (fabs(a - b) <= MIN_DIFF) ? true : false;
}

bool IsZero(double a)
{
    return (fabs(a) <= MIN_DIFF) ? true : false;
}
