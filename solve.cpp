#include <stdio.h>
#include <math.h>
#include <assert.h>

struct coefficients
{
    double a, b, c;
};

enum RootsAmount
{

    ROOTS_AMOUNT_ERR_CODE = -2,
    ROOTS_AMOUNT_INF_ROOTS,
    ROOTS_AMOUNT_NO_ROOTS,
    ROOTS_AMOUNT_ONE_ROOT,
    ROOTS_AMOUNT_TWO_ROOTS
};

const double MIN_DIFF = 1e-3;

bool IsZero(double a);
bool Compare(double a, double b);
void TestSolveSquare();
int PrintEquation(struct coefficients* my_coeff);
int SolveSquare(struct coefficients my_coeff, double* x1, double* x2);
int PrintResult(int n, double x1, double x2);
int UserInput(struct coefficients *my_coeff);

int SolveSquare(struct coefficients my_coeff, double *x1, double *x2)
{
    assert(x1);
    assert(x2);

    if (IsZero(my_coeff.a))
    {
        if (IsZero(my_coeff.b))
        {
            return (IsZero(my_coeff.c)) ? ROOTS_AMOUNT_INF_ROOTS : ROOTS_AMOUNT_NO_ROOTS;
        }
        else
        {
            *x1 = (IsZero(my_coeff.c)) ? 0 : (-my_coeff.c / my_coeff.b);

            return ROOTS_AMOUNT_ONE_ROOT;
        }
    }

    double d = (my_coeff.b*my_coeff.b) - (4*my_coeff.a*my_coeff.c);

    if (d < 0)
    {
        return ROOTS_AMOUNT_NO_ROOTS;
    }
    else if (IsZero(d))
    {
        *x1 = *x2 = (IsZero(-my_coeff.b / (2*my_coeff.a))) ? 0 : (-my_coeff.b / (2*my_coeff.a));

        return ROOTS_AMOUNT_ONE_ROOT;
    }
    else if (d > 0)
    {
        *x1 = (IsZero((-my_coeff.b + sqrt(d)) / (2*my_coeff.a))) ? 0 : ((-my_coeff.b + sqrt(d)) / (2*my_coeff.a));
        *x2 = (IsZero((-my_coeff.b - sqrt(d)) / (2*my_coeff.a))) ? 0 : ((-my_coeff.b - sqrt(d)) / (2*my_coeff.a));

        return ROOTS_AMOUNT_TWO_ROOTS;
    }

    return ROOTS_AMOUNT_ERR_CODE;
}
