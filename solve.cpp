#include <assert.h>
#include <stdio.h>
#include <math.h>

#include "floating.h"
#include "solve.h"

//#include <cmath>        //????????????????????????
// using namespace std;

int SolveSquare(struct Params *equation_params)
{
    assert(equation_params);

    double a = equation_params->coeffs.a;
    double b = equation_params->coeffs.b;
    double c = equation_params->coeffs.c;

    if (IsZero(a))
    {
        if (IsZero(b))
        {
            return (IsZero(c)) ? ROOTS_AMOUNT_INF_ROOTS : ROOTS_AMOUNT_NO_ROOTS;
        }

        else if (IsZero(c))
            equation_params->result.x1 = equation_params->result.x2 = 0;

        else
        {
            if (isfinite(-(c / b)))
            {
                equation_params->result.x1 = equation_params->result.x2 = -(c / b);

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
            equation_params->result.x1 = equation_params->result.x2 = 0;

            return ROOTS_AMOUNT_ONE_ROOT;
        }

        else if (isfinite((float)(c / a)) && (c / a) < 0)
        {
            equation_params->result.x1 = sqrt(-c / a);
            equation_params->result.x2 = -sqrt(-c / a);

            return ROOTS_AMOUNT_TWO_ROOTS;
        }
        if (isfinite((float)(c / a)))
            return ROOTS_AMOUNT_NO_ROOTS;

        printf("Root is not finite!\n");
        return ROOTS_AMOUNT_ERR_CODE;
    }

    if (IsZero(c))
    {
        if (isfinite((float)(b / a)))
        {
            equation_params->result.x1 = 0;
            equation_params->result.x2 = -(b / a);

            return ROOTS_AMOUNT_TWO_ROOTS;
        }

        printf("Root is not finite!\n");

        return ROOTS_AMOUNT_ERR_CODE;
    }

    double d = (b*b) - (4*a*c);

    if (!isfinite(d))
    {
        printf("Invalid discriminant!\n");

        return ROOTS_AMOUNT_ERR_CODE;
    }

    if (d < 0)
    {
        return ROOTS_AMOUNT_NO_ROOTS;
    }

    else if (IsZero(d))
    {
        if (isfinite((float)(-b / (2*a))))
        {
            equation_params->result.x1 = equation_params->result.x2 = (IsZero(-b / (2*a))) ? 0 : (-b / (2*a));

            return ROOTS_AMOUNT_ONE_ROOT;
        }

        printf("Root is not finite!\n");

        return ROOTS_AMOUNT_ERR_CODE;
    }

    else if (d > 0)
    {
        if (isfinite((float)((-b + sqrt(d)) / (2*a))) && isfinite((float)((-b - sqrt(d)) / (2*a))))
        {
            equation_params->result.x1 = (IsZero((-b + sqrt(d)) / (2*a))) ? 0 : ((-b + sqrt(d)) / (2*a));
            equation_params->result.x2 = (IsZero((-b - sqrt(d)) / (2*a))) ? 0 : ((-b - sqrt(d)) / (2*a));

            return ROOTS_AMOUNT_TWO_ROOTS;
        }

        printf("Root is not finite!\n");

        return ROOTS_AMOUNT_ERR_CODE;
    }

    return ROOTS_AMOUNT_ERR_CODE;
}
