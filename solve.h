#ifndef SOLVE_H
#define SOLVE_H


struct Coefficients {
    double a, b, c;
};

struct Result {
    double x1, x2;
    int n_roots;
};

struct Params {
    struct Coefficients coeffs;
    struct Result result;
};

struct Test
{
    struct Coefficients coeffs;
    struct Result result;
};

enum RootsAmount
{
    ROOTS_AMOUNT_ERR_CODE = -2,
    ROOTS_AMOUNT_INF_ROOTS = -1,
    ROOTS_AMOUNT_NO_ROOTS = 0,
    ROOTS_AMOUNT_ONE_ROOT = 1,
    ROOTS_AMOUNT_TWO_ROOTS = 2
};

int SolveSquare(const struct Coefficients *coeffs, struct Result *result);

#endif //SOLVE_H
