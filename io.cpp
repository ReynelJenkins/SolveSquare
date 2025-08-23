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

int UserInput(struct coefficients* my_coeff)
{
    assert(my_coeff);

    printf("Program for solving an equation of the type ax^2 + bx + c = 0\n");
    printf("Enter the coefficients: a, b, c\n");

    printf("a = ");
    scanf("%lg", &my_coeff->a);   // sscanf

    printf("b = ");
    scanf("%lg", &my_coeff->b);

    printf("c = ");
    scanf("%lg", &my_coeff->c);

    PrintEquation(my_coeff);

    return 0;
}

int PrintEquation(struct coefficients* my_coeff)
{
    int first_print = 0;

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

    printf(" = 0\n");

    return 0;
}

int PrintResult(int n, double x1, double x2)
{
    switch (n)
    {
        case ROOTS_AMOUNT_NO_ROOTS:
            printf("No roots\n");
            break;
        case ROOTS_AMOUNT_ONE_ROOT:
            printf("Single root x = %lg\n", x1);
            break;
        case ROOTS_AMOUNT_TWO_ROOTS:
            printf("Roots: x1 = %lg, x2 = %lg\n", x1, x2);
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

    return 0;
}
