#include <math.h>
#include <assert.h>

bool foo(double a, double b)
{
    //return __fpclassifyf(a);
    double x = a / b;
    return fpclassify(x);
    return isfinite(-(a / b));
}

