#include <stdio.h>
#include <math.h>
#include <assert.h>


// enum
const int INF_ROOTS = -1;
const int ERR_CODE = -2;

const double MIN_DIFF = 0.001;

bool IsZero(double a);
bool Compare(double a, double b);
int PrintEquation(double a, double b, double c);
int SolveSquare(double a, double b, double c, double* x1, double* x2);
int PrintResult(int n, double x1, double x2);
int UserInput(double *a, double *b, double *c);

// struct

int main()
{

    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    UserInput(&a, &b, &c);
    int nRoots = SolveSquare(a, b, c, &x1, &x2);
    PrintResult(nRoots, x1, x2);

    return 0;
}

// Верно для небольших a и b
bool Compare(double a, double b)
{
    return (fabs(a - b) <= MIN_DIFF) ? true : false;
}

int UserInput(double *a, double *b, double *c)
{
    assert(a);
    assert(b);
    assert(c);

    printf("Programm for solving an equation of the type ax^2 + bx + c = 0\n");
    printf("Enter the coefficients: a, b, c\n");

    printf("a = ");
    scanf("%lg", a);
    printf("b = ");
    scanf("%lg", b);
    printf("c = ");
    scanf("%lg", c);

    PrintEquation(*a, *b, *c);

    return 0;
}

bool IsZero(double a)
{
    return (a <= MIN_DIFF && a >= -MIN_DIFF) ? true : false;
}

int SolveSquare(double a, double b, double c, double *x1, double *x2)
{
    assert(x1);
    assert(x2);

    if (IsZero(a))
    {
        if (IsZero(b))
        {
            return (IsZero(c)) ? INF_ROOTS : 0;
        }
        else
        {
            *x1 = (IsZero(c)) ? 0 : (-c / b);

            return 1;
        }
    }

    double d = (b*b) - (4*a*c);

    if (d < 0)
    {
        return 0;
    }
    else if (IsZero(d))
    {
        *x1 = *x2 = (IsZero(-b / (2*a))) ? 0 : (-b / (2*a));

        return 1;
    }
    else if (d > 0)
    {
        *x1 = (IsZero((-b + sqrt(d)) / (2*a))) ? 0 : ((-b + sqrt(d)) / (2*a));
        *x2 = (IsZero((-b - sqrt(d)) / (2*a))) ? 0 : ((-b - sqrt(d)) / (2*a));

        return 2;
    }

    return ERR_CODE;
}

int PrintEquation(double a, double b, double c)
{
    int FirstPrint = 0;

    if (!IsZero(a))
    {
        if (Compare(a, 1))
            printf("X^2");
        else if (Compare(a, -1))
            printf("-X^2");
        else
            printf("%lgX^2", a);
        FirstPrint = 1;
    }

    if (!IsZero(b))
    {
        if (FirstPrint == 0)
        {
            FirstPrint = 1;
            if (Compare(b, 1))
                printf("X");
            else if (Compare(b, 1))
                printf("-X");
            else
            {
                if (b > 0)
                    printf("%lgX", b);
                else
                    printf("-%lgX", fabs(b));
            }
        }
        else
        {
            if (Compare(b, 1))
                printf(" + X");
            else if (Compare(b, -1))
                printf(" - X");
            else
            {
                if (b > 0)
                    printf(" + %lgX", b);
                else
                    printf(" - %lgX", fabs(b));
            }
        }
    }

    if (!IsZero(c))
    {
        if (FirstPrint == 0)
        {
            FirstPrint = 1;
            printf("%lg", c);
        }
        else
        {
            if (c > 0)
                printf(" + %lg", c);
            else
                printf(" - %lg", fabs(c));
        }
    }
    if  (IsZero(c) && FirstPrint == 0)
        printf("0");

    printf(" = 0\n");

    return 0;
}

int PrintResult(int n, double x1, double x2)
{
    switch (n)
    {
        case 0:
            printf("No roots\n");
            break;
        case 1:
            printf("Single root x = %lg\n", x1);
            break;
        case 2:
            printf("Roots: x1 = %lg, x2 = %lg\n", x1, x2);
            break;
        case INF_ROOTS:
            printf("Any number is a root\n");
            break;
        case ERR_CODE:
            printf("Error (Finding roots)\n");
            break;
        default:
            printf("Error\n");
            break;
    }

    return 0;
}
