#include <stdio.h>

#include "solve.h"
#include "floating.h"
#include "io.h"

#include "unit_test.h"

void TestSolveSquare()
{
    bool success = true;

    for (int a_i = -100; a_i <= 100; a_i += 1)
    {
        for (int b_i = -100; b_i <= 100; b_i += 1)
        {
            for (int c_i = -100; c_i <= 100; c_i += 1)
            {
                double a = a_i * 0.1;
                double b = b_i * 0.1;
                double c = c_i * 0.1;

                struct Params test_equation = {.coeffs = {a, b, c}};

                int n_roots = SolveSquare(&test_equation);
                double x1 = test_equation.result.x1;
                double x2 = test_equation.result.x2;
                switch (n_roots)
                {
                    case ROOTS_AMOUNT_ONE_ROOT:
                        if (!IsZero(a*x1*x1 + b*x1 + c))
                        {
                            printf(RED "FAILED: a = %lg b = %lg c = %lg x1 = %lg\n" RESET, a, b, c, x1);
                            success = false;
                        }
                        break;

                    case ROOTS_AMOUNT_TWO_ROOTS:
                        if (!IsZero(a*x1*x1 + b*x1 + c) || !IsZero(a*x2*x2 + b*x2 + c))
                        {
                            printf(RED "FAILED: a = %lg b = %lg c = %lg x1 = %lg x2 = %lg\n" RESET, a, b, c, x1, x2);
                            success = false;
                        }
                        break;

                    default:;
                }
            }
        }
    }

    if (success)
        printf(GREEN "SUCCESS: All tests passed!" RESET);
}
