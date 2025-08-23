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

bool IsZero(double a)
{
    return (fabs(a) <= MIN_DIFF) ? true : false;
}

// True for small a & b
bool Compare(double a, double b)
{
    return (fabs(a - b) <= MIN_DIFF) ? true : false;
}
