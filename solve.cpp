#include<assert.h>
#include <math.h>

#include "floating.h"

#include "solve.h"

int SolveSquare(const struct Coefficients *my_coeff, double *x1, double *x2)
{
    assert(x1);
    assert(x2);
    assert(my_coeff);

    if (IsZero(my_coeff->a))
    {
        if (IsZero(my_coeff->b))
        {
            return (IsZero(my_coeff->c)) ? ROOTS_AMOUNT_INF_ROOTS : ROOTS_AMOUNT_NO_ROOTS;
        }

        *x1 = *x2 = (IsZero(my_coeff->c)) ? 0 : -(my_coeff->c / my_coeff->b);

        return ROOTS_AMOUNT_ONE_ROOT;
    }

    if (IsZero(my_coeff->b))
    {
        if (IsZero(my_coeff->c))
        {
            *x1 = *x2 = 0;

            return ROOTS_AMOUNT_ONE_ROOT;
        }

        if (my_coeff->c/my_coeff->a < 0)
        {
            *x1 = sqrt(-my_coeff->c/my_coeff->a);
            *x2 = -sqrt(-my_coeff->c/my_coeff->a);

            return ROOTS_AMOUNT_TWO_ROOTS;
        }
    }

    if (IsZero(my_coeff->c))
    {
        *x1 = 0;
        *x2 = (-my_coeff->b/my_coeff->a);

        return ROOTS_AMOUNT_TWO_ROOTS;
    }

    double d = (my_coeff->b*my_coeff->b) - (4*my_coeff->a*my_coeff->c);

    if (d < 0)
    {
        return ROOTS_AMOUNT_NO_ROOTS;
    }

    else if (IsZero(d))
    {
        *x1 = *x2 = (IsZero(-my_coeff->b / (2*my_coeff->a))) ? 0 : (-my_coeff->b / (2*my_coeff->a));

        return ROOTS_AMOUNT_ONE_ROOT;
    }

    else if (d > 0)
    {
        *x1 = (IsZero((-my_coeff->b + sqrt(d)) / (2*my_coeff->a))) ? 0 : ((-my_coeff->b + sqrt(d)) / (2*my_coeff->a));
        *x2 = (IsZero((-my_coeff->b - sqrt(d)) / (2*my_coeff->a))) ? 0 : ((-my_coeff->b - sqrt(d)) / (2*my_coeff->a));

        return ROOTS_AMOUNT_TWO_ROOTS;
    }

    return ROOTS_AMOUNT_ERR_CODE;
}
