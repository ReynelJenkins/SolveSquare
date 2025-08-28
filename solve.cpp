/*!
\file
\brief Файл solve.cpp

Данный файл содержит в себе функции и макрос, используемые в программе.
*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#include "floating.h"
#include "solve.h"

#define MY_ASSERT(condition) \
    if (!(condition)) { \
        fprintf(stderr, "Assertion failed: %s, file %s, line %d\n", \
                #condition, __FILE__, __LINE__); \
        abort(); \
    }

/*!
Решает квадратное уравнение
\param[in] coeffs указатель на структуру типа Coefficients
\param[out] result указатель на структуру типа Result
\return Количество корней
*/
int SolveSquare(const struct Coefficients *coeffs, struct Result *result)
{

// #define NDEBUG
// ASSERT()
// Test Driven Development
// K & R

    assert(coeffs);
    assert(result);

    double a = coeffs->a;
    double b = coeffs->b;
    double c = coeffs->c;

    if (IsZero(a))
    {
        return SolveLinearEquation(b, c, result);
    }

    if (IsZero(b) || IsZero(c))
    {
        return SolveSpecialCase(coeffs, result);
    }

    double discriminant = (b*b) - (4*a*c);

    if (!isfinite(discriminant))
    {
        return ROOTS_AMOUNT_DISCRIMINANT_NOT_FINITE;
    }

    else if (IsZero(discriminant))
    {
        if (isfinite((float) (-b / (2*a))))
        {
            result->x1 = result->x2 = (IsZero(-b / (2*a))) ? 0 : (-b / (2*a));

            return ROOTS_AMOUNT_ONE_ROOT;
        }

        return ROOTS_AMOUNT_ROOT_NOT_FINITE;
    }

    else if (discriminant < 0)
    {
        return ROOTS_AMOUNT_NO_ROOTS;
    }

    else if (discriminant > 0)
    {
        double sqrt_d = sqrt(discriminant);
        if (isfinite((float) ((-b + sqrt_d) / (2*a))) && isfinite((float) ((-b - sqrt_d) / (2*a))))
        {
            result->x1 = (IsZero((-b + sqrt_d) / (2*a))) ? 0 : ((-b + sqrt_d) / (2*a));
            result->x2 = (IsZero((-b - sqrt_d) / (2*a))) ? 0 : ((-b - sqrt_d) / (2*a));

            return ROOTS_AMOUNT_TWO_ROOTS;
        }

        return ROOTS_AMOUNT_ROOT_NOT_FINITE;
    }

    return ROOTS_AMOUNT_ERR_CODE;
}

/*!
Решает линейное уравнение
\param[in] coeffs указатель на структуру типа Coefficients
\param[out] result указатель на структуру типа Result
\return Количество корней
*/
int SolveLinearEquation(double b, double c, struct Result *result)
{
    if (IsZero(b))
    {
        return (IsZero(c)) ? ROOTS_AMOUNT_INF_ROOTS : ROOTS_AMOUNT_NO_ROOTS;
    }
    else if (IsZero(c))
    {
        result->x1 = result->x2 = 0;
    }
    else
    {
        if (isfinite(-(c / b)))
        {
            result->x1 = result->x2 = -(c / b);

            return ROOTS_AMOUNT_ONE_ROOT;
        }

        return ROOTS_AMOUNT_ROOT_NOT_FINITE;
    }

    return ROOTS_AMOUNT_ONE_ROOT;
}

int SolveSpecialCase(const struct Coefficients *coeffs, struct Result *result)
{
    double a = coeffs->a;
    double b = coeffs->b;
    double c = coeffs->c;

    if (IsZero(b))
    {
        if (IsZero(c))
        {
            result->x1 = result->x2 = 0;

            return ROOTS_AMOUNT_ONE_ROOT;
        }

        else if (isfinite(-(c / a)) && ((c / a) < 0))
        {
            result->x1 =  sqrt(-c / a);
            result->x2 = -sqrt(-c / a);

            return ROOTS_AMOUNT_TWO_ROOTS;
        }

        if (isfinite((float) (c / a)))
        {
            return ROOTS_AMOUNT_NO_ROOTS;
        }

        return ROOTS_AMOUNT_ROOT_NOT_FINITE;
    }

    if (IsZero(c))
    {
        if (isfinite((float) (b / a)))
        {
            result->x1 = 0;
            result->x2 = -(b / a);

            return ROOTS_AMOUNT_TWO_ROOTS;
        }

        return ROOTS_AMOUNT_ROOT_NOT_FINITE;
    }

    return ROOTS_AMOUNT_ERR_CODE;
}
