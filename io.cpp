#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "floating.h"
#include "solve.h"

#include "io.h"

int UserInput(struct Coefficients* my_coeff)
{
    assert(my_coeff);

    printf("Program for solving an equation of the type ax^2 + bx + c = 0\n");
    printf("Enter the coefficients: a, b, c:\n\n");

    my_coeff->a = InputNumber("a = ");
    my_coeff->b = InputNumber("b = ");
    my_coeff->c = InputNumber("c = ");

    PrintEquation(my_coeff);

    return 0;
}

int PrintEquation(const struct Coefficients* my_coeff)
{
    int first_print = 0;

    printf("\n");

    if (!IsZero(my_coeff->a))
    {
        if (Compare(my_coeff->a, 1))
            printf("X^2");
        else if (Compare(my_coeff->a, -1))
            printf("-X^2");
        else
            printf("%lgX^2", my_coeff->a);
        first_print = 1;
    }

    if (!IsZero(my_coeff->b))
    {
        if (first_print == 0)
        {
            first_print = 1;
            if (Compare(my_coeff->b, 1))
                printf("X");
            else if (Compare(my_coeff->b, 1))
                printf("-X");
            else
            {
                if (my_coeff->b > 0)
                    printf("%lgX", my_coeff->b);
                else
                    printf("-%lgX", fabs(my_coeff->b));
            }
        }
        else
        {
            if (Compare(my_coeff->b, 1))
                printf(" + X");
            else if (Compare(my_coeff->b, -1))
                printf(" - X");
            else
            {
                if (my_coeff->b > 0)
                    printf(" + %lgX", my_coeff->b);
                else
                    printf(" - %lgX", fabs(my_coeff->b));
            }
        }
    }

    if (!IsZero(my_coeff->c))
    {
        if (first_print == 0)
        {
            first_print = 1;
            printf("%lg", my_coeff->c);
        }
        else
        {
            if (my_coeff->c > 0)
                printf(" + %lg", my_coeff->c);
            else
                printf(" - %lg", fabs(my_coeff->c));
        }
    }
    if  (IsZero(my_coeff->c) && first_print == 0)
        printf("0");

    printf(" = 0\n\n");

    return 0;
}

int PrintResult(int n, double x1, double x2)
{

    //const char* aaa = "123123"; Why not! const char* const????

    //char x[3] = {1, 2, 3};
    //char x[4] = {'1', '2', '3', '\0 const struct const 123???

    //const char* x = "123";

    switch (n)
    {
        case ROOTS_AMOUNT_NO_ROOTS:
            printf("No roots\n");
            break;
        case ROOTS_AMOUNT_ONE_ROOT:
            printf("Single root x = %lg\n", x1);
            break;
        case ROOTS_AMOUNT_TWO_ROOTS:
            printf("Two roots: x1 = %lg, x2 = %lg\n", x1, x2);
            break;
        case ROOTS_AMOUNT_INF_ROOTS:
            printf("Any number is a root\n");
            break;
        case ROOTS_AMOUNT_ERR_CODE:
            printf("Error (Finding roots)\n");
            break;
        default:
            printf("Error\n");
            break;
    }

    printf("\n");

    return 0;
}

double InputNumber(const char *prompt)
{
    char buf[100] = {0}; // K&R
    char *end_ptr;
    double value = 0;

    do
    {
        memset(buf, 0, sizeof(buf));

        printf("%s", prompt);
        fflush(stdout);
        int curr_pos = 0;

        for (curr_pos = 0; curr_pos != sizeof(buf) - 1; ++curr_pos)
        {
            int c = getchar();
            if (c == EOF || c == '\n')
            {
                break;
            }

            buf[curr_pos] = (char)c;
        }

        if (curr_pos == sizeof(buf)-1)
        {
            printf("Buffer Overflow!\n");
            fflush(stdin);
        }

        value = strtod(buf, &end_ptr);

    } while (end_ptr == &buf[0] || *end_ptr != 0);

    return value;
}
