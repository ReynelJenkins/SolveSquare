#include "io.h"
#include "solve.h"
#include "unit_test.h"

int main()
{
    while (true)
    {
        struct coefficients user_coeff = {0, 0, 0};
        double x1 = 0, x2 = 0;

        UserInput(&user_coeff);

        int n_roots = SolveSquare(user_coeff, &x1, &x2);
        PrintResult(n_roots, x1, x2);

        TestSolveSquare();
    }

    return 0;
}
