/*!
\file
\brief Файл unit_test.cpp

Данный файл содержит в себе функции, используемые программе.
*/

#include <stdio.h>
#include <assert.h>

#include "solve.h"
#include "floating.h"
#include "io.h"

#include "unit_test.h"


/*!
Запускает юнит-тесты
*/
int TestSolveSquare()
{
    bool success = true;
    /*
    for (int a_i = -100; a_i <= 100; a_i += 1)
    {
        for (int b_i = -100; b_i <= 100; b_i += 1)
        {
            for (int c_i = -100; c_i <= 100; c_i += 1)
            {
                double a = a_i * 0.1;
                double b = b_i * 0.1;
                double c = c_i * 0.1;

                struct Test test_equation = {};

                test_equation.coeffs = {a, b, c};

                int n_roots = SolveSquare(&test_equation.coeffs, &test_equation.result);

                double x1 = test_equation.result.x1;
                double x2 = test_equation.result.x2;

                switch (n_roots)
                {
                    case ROOTS_AMOUNT_ONE_ROOT:
                        if (!IsZero(a*x1*x1 + b*x1 + c))
                        {
                            PrintTestError(&test_equation, 0, 0);

                            success = false;
                        }
                        break;

                    case ROOTS_AMOUNT_TWO_ROOTS:
                        if (!IsZero(a*x1*x1 + b*x1 + c) || !IsZero(a*x2*x2 + b*x2 + c))
                        {
                            PrintTestError(&test_equation, 0, 0);

                            success = false;
                        }
                        break;

                    default:;
                }
            }
        }
    }
    */
    if (success && ReadTestsFromFile())
        printf(GREEN "SUCCESS: All tests passed!\n" RESET);

    return 0;
}

/*!
Запускает тесты из файла file.txt
\return 1, если все тесты пройдены успешно, при хотя бы одном проваленом тесте возвращает 0
*/
int ReadTestsFromFile()
{
    FILE* file = fopen("file.txt", "r");
    if (file == NULL)
    {
        printf(RED "Error opening file.txt! Extern tests will be passed..." RESET);

        return 1;
    }

    char buf[BUF_SIZE] = {};

    struct Test test = {};
    struct Result result_of_program = {};

    int n_roots = 0;

    while (fgets(buf, sizeof(buf), file) != NULL)
    {
        test = {};
        result_of_program = {};

        sscanf(buf, "%lg %lg %lg %lg %lg", &test.coeffs.a, &test.coeffs.b, &test.coeffs.c, &test.result.x1, &test.result.x2);
        // SerializeTest(const Test *test, FILE* file) // fprintf(a b c x1 x2)
        // DeserializeTest(Test *test)        fscanf()

        n_roots = SolveSquare(&test.coeffs, &result_of_program);

        switch (n_roots)
        {
            case ROOTS_AMOUNT_TWO_ROOTS:
                if (!((Compare(test.result.x1, result_of_program.x1) && Compare(test.result.x2, result_of_program.x2))
                   || (Compare(test.result.x1, result_of_program.x2) && Compare(test.result.x2, result_of_program.x1))))
                {
                    PrintTestError(&test, result_of_program.x1, result_of_program.x2);

                    return 0;
                }
                break;

            case ROOTS_AMOUNT_ONE_ROOT:
                if (!(Compare(test.result.x1, result_of_program.x1)
                   || Compare(test.result.x1, result_of_program.x2)))
                {
                    PrintTestError(&test, result_of_program.x1, result_of_program.x2);

                    return 0;
                }
                break;

            default:
                break;
        }
    }

    fclose(file);

    return 1;
}
