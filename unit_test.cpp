#include <stdio.h>
#include <assert.h>

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

                struct Params test_equation = {};

                test_equation.coeffs = {a, b, c};

                int n_roots = SolveSquare(&test_equation.coeffs, &test_equation.result);

                double x1 = test_equation.result.x1;
                double x2 = test_equation.result.x2;

                switch (n_roots)
                {
                    case ROOTS_AMOUNT_ONE_ROOT:
                        if (!IsZero(a*x1*x1 + b*x1 + c))
                        {
                            printf(RED "FAILED: a = %lg b = %lg c = %lg x = %lg\n" RESET, a, b, c, x1);
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

    if (success && ReadTestsFromFile())
        printf(GREEN "SUCCESS: All tests passed!\n" RESET);
}


int ReadTestsFromFile()
{
    FILE* file = fopen("file.txt", "r");
    if (file == NULL)
    {
        printf(RED "Error opening file.txt with tests..." RESET);
        return 0;
    }

    char buf[BUF_SIZE] = {};

    struct Params test = {};
    double x1_ref = 0, x2_ref = 0;
    int  n_roots = 0;

    while (fgets(buf, sizeof(buf), file) != NULL)
    {
        test = {};

        sscanf(buf, "%lg %lg %lg %lg %lg", &test.coeffs.a, &test.coeffs.b, &test.coeffs.c, &x1_ref, &x2_ref);

        n_roots = SolveSquare(&test.coeffs, &test.result);

        switch (n_roots)
        {
            case ROOTS_AMOUNT_TWO_ROOTS:
                if (!((Compare(test.result.x1, x1_ref) && Compare(test.result.x2, x2_ref)) || (Compare(test.result.x1, x2_ref) && Compare(test.result.x2, x1_ref))))
                {
                    // Copy paste PrintTestsError(Test *test, Solution *solution)
                    printf(RED "FAILED: a = %lg b = %lg c = %lg x1_ref = %lg x2_ref = %lg x1 = %lg x2 = %lg\n" RESET, test.coeffs.a, test.coeffs.b, test.coeffs.c, x1_ref, x2_ref, test.result.x1, test.result.x2);

                    return 0;
                }
                break;

            case ROOTS_AMOUNT_ONE_ROOT:
                if (!(Compare(test.result.x1, x1_ref) || Compare(test.result.x1, x2_ref)))
                {
                    printf(RED "FAILED: a = %lg b = %lg c = %lg x1_ref = %lg x2_ref = %lg x1 = %lg x2 = %lg\n" RESET, test.coeffs.a, test.coeffs.b, test.coeffs.c, x1_ref, x2_ref, test.result.x1, test.result.x2);

                    return 0;
                }
                break;

            default:;
        }
    }

    fclose(file);

    return 1;
}
