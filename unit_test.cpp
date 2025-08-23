#include <stdio.h>
#include "solve.h"
#include "floating.h"

#include "unit_test.h"

void TestSolveSquare()
{

    for (int a_i = -100; a_i <= 100; a_i += 1)
    {
        for (int b_i = -100; b_i <= 100; b_i += 1)
        {
            for (int c_i = -100; c_i <= 100; c_i += 1)
            {
                double x1 = 0, x2 = 0;

                double a = a_i * 0.1;
                double b = b_i * 0.1;
                double c = c_i * 0.1;

                struct coefficients test_coefficients = {a, b, c};

                int nRoots = SolveSquare(test_coefficients, &x1, &x2);

                switch (nRoots)
                {
                    case ROOTS_AMOUNT_ONE_ROOT:
                        if (!IsZero(a*x1*x1 + b*x1 + c))
                            printf("FAILED a = %lg b = %lg c = %lg x1 = %lg\n", a, b, c, x1);
                        break;
                    case ROOTS_AMOUNT_TWO_ROOTS:
                        if (!IsZero(a*x1*x1 + b*x1 + c) && !IsZero(a*x2*x2 + b*x2 + c))
                            printf("FAILED a = %lg b = %lg c = %lg x1 = %lg x2 = %lg\n", a, b, c, x1, x2);
                        break;
                    default:;
                }
            }
        }
    }
}
