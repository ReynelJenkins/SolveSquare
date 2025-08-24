#ifndef SOLVE_H
#define SOLVE_H

struct Coefficients
{
    double a, b, c;
};

enum RootsAmount
{

    ROOTS_AMOUNT_ERR_CODE = -2,
    ROOTS_AMOUNT_INF_ROOTS = -1,
    ROOTS_AMOUNT_NO_ROOTS = 0,
    ROOTS_AMOUNT_ONE_ROOT = 1,
    ROOTS_AMOUNT_TWO_ROOTS = 2
};

int SolveSquare(const struct Coefficients *my_coeff, double* x1, double* x2);

#endif //SOLVE_H
