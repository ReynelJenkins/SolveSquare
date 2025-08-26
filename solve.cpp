#include <assert.h>
#include <stdio.h>
#include <math.h>

#include "floating.h"
#include "solve.h"

int SolveSquare(const struct Coefficients *coeffs, struct Result *result)
{
    assert(coeffs);
    assert(result);

    double a = coeffs->a;
    double b = coeffs->b;
    double c = coeffs->c;

    if (IsZero(a))
    {
        if (IsZero(b))
        {
            return (IsZero(c)) ? ROOTS_AMOUNT_INF_ROOTS : ROOTS_AMOUNT_NO_ROOTS;
        }
        else if (IsZero(c))
        {
            result->x1 = result->x2 = 0;
        }
        else
        {
            if (isfinite(-(c / b)))
            {
                result->x1 = result->x2 = -(c / b);

                return ROOTS_AMOUNT_ONE_ROOT;
            }

            printf("Root is not finite!\n");

            return ROOTS_AMOUNT_ERR_CODE;
        }

        return ROOTS_AMOUNT_ONE_ROOT;
    }

    if (IsZero(b))
    {
        if (IsZero(c))
        {
            result->x1 = result->x2 = 0;

            return ROOTS_AMOUNT_ONE_ROOT;
        }

        else if (isfinite(-(c / a)) && ((c / a) < 0))
        {
            result->x1 =  sqrt(-c / a);
            result->x2 = -sqrt(-c / a);

            return ROOTS_AMOUNT_TWO_ROOTS;
        }

        if (isfinite((float) (c / a)))
        {
            return ROOTS_AMOUNT_NO_ROOTS;
        }

        printf("Root is not finite!\n");
        return ROOTS_AMOUNT_ERR_CODE;
    }

    if (IsZero(c))
    {
        if (isfinite((float) (b / a)))
        {
            result->x1 = 0;
            result->x2 = -(b / a);

            return ROOTS_AMOUNT_TWO_ROOTS;
        }

        printf("Root is not finite!\n");

        return ROOTS_AMOUNT_ERR_CODE;
    }

    double discriminant = (b*b) - (4*a*c);

    if (!isfinite(discriminant))
    {
        printf("Invalid discriminant!\n");

        return ROOTS_AMOUNT_ERR_CODE;
    }

    else if (IsZero(discriminant))
    {
        if (isfinite((float) (-b / (2*a))))
        {
            result->x1 = result->x2 = (IsZero(-b / (2*a))) ? 0 : (-b / (2*a));

            return ROOTS_AMOUNT_ONE_ROOT;
        }

        printf("Root is not finite!\n");

        return ROOTS_AMOUNT_ERR_CODE;
    }

    else if (discriminant < 0)
    {
        return ROOTS_AMOUNT_NO_ROOTS;
    }

    else if (discriminant > 0)
    {
        double sqrt_d = sqrt(discriminant);
        if (isfinite((float) ((-b + sqrt_d) / (2*a))) && isfinite((float) ((-b - sqrt_d) / (2*a))))
        {
            result->x1 = (IsZero((-b + sqrt_d) / (2*a))) ? 0 : ((-b + sqrt_d) / (2*a));
            result->x2 = (IsZero((-b - sqrt_d) / (2*a))) ? 0 : ((-b - sqrt_d) / (2*a));

            return ROOTS_AMOUNT_TWO_ROOTS;
        }

        printf("Root is not finite!\n");

        return ROOTS_AMOUNT_ERR_CODE;
    }

    return ROOTS_AMOUNT_ERR_CODE;
}
