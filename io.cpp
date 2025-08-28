/*!
\file
\brief Файл io.cpp

Данный файл содержит в себе функции, используемые в программе.
*/

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "floating.h"
#include "solve.h"
#include "unit_test.h"

#include "io.h"

/*!
Запрашивает ввод коэффицентов
\param[in] my_coeff указатель на структуру типа Coefficients
*/
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

/*!
Выводит уравнение
\param[in] my_coeff указатель на структуру типа Coefficients
*/
int PrintEquation(const struct Coefficients *my_coeff)
{
    assert(my_coeff);

    int first_print = 0;

    printf("\n");

    // TODO:
    // PrintA ...
    if (!IsZero(my_coeff->a))
    {
        PrintA(my_coeff->a);
        first_print = 1;
    }

    if (!IsZero(my_coeff->b))
    {
        PrintB(my_coeff->b, &first_print);
    }

    if (!IsZero(my_coeff->c))
    {
        PrintC(my_coeff->c, &first_print);
    }

    if  (IsZero(my_coeff->c) && first_print == 0)
    {
        printf("0");
    }

    printf(" = 0\n\n");

    return 0;
}

/*!
Выводит результат работы программы
\param[in] my_result указатель на структуру типа Result
*/
int PrintResult(struct Result* my_result)
{

    //const <-(нельзя менять массив) char* const <-(нельзя менять указатель) aaa = "123123"; Why not! const char* const????
    int n = my_result->n_roots;
    double x1 = my_result->x1;
    double x2 = my_result->x2;

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

        case ROOTS_AMOUNT_ROOT_NOT_FINITE:
            printf("Root is not finite!\n");
            break;

        case ROOTS_AMOUNT_DISCRIMINANT_NOT_FINITE:
            printf("Invalid discriminant!\n");
            break;

        default:
            printf("Error\n");
            break;
    }

    printf("\n");

    return 0;
}

/*!
Получает и проверяет значение из stdin
\param[in] prompt указатель на строковую константу, которая выводится перед получением значения
\return value - полученное число, в случае неудачи считывания числа - выводит соответствующую ошибку
*/
double InputNumber(const char *prompt)
{
    char buf[BUF_SIZE] = {0}; // K&R
    char *end_ptr = nullptr;
    double value = 0;

    do
    {
        printf("%s", prompt);
        fflush(stdout);

        if (!FillBuf(buf, sizeof(buf)))
        {
            continue;
        }

        if (strcmp(buf, "meow") == 0)
        {
            PrintCat();
            continue;
        }

        value = strtod(buf, &end_ptr);

        if (IsValid(value, end_ptr, &buf[0]))
        {
            break;
        }

    } while (true);

    return value;
}

/*!
Выводит котика :)
*/
int PrintCat()
{
    printf("\n");
    printf("  /\\_/\\  \n");
    printf(" ( o.o ) \n");
    printf("  > ^ <  \n");
    printf("\n");

    return 0;
}

/*!
Выводит сообщение о провале теста
\param[in] failed_test_params указатель на структуру, содержащую коэффиценты и верные корни
\param[in] x1_ref Результат, посчитаный программой
\param[in] x2_ref Результат, посчитаный программой
*/
int PrintTestError(const struct Test *failed_test_params,
                   double             x1_ref,
                   double             x2_ref)
{
    printf(RED "FAILED:");
    printf("a = %lg ", failed_test_params->coeffs.a);
    printf("b = %lg ", failed_test_params->coeffs.b);
    printf("c = %lg ", failed_test_params->coeffs.c);
    printf("x1_ref = %lg ", x1_ref);
    printf("x2_ref = %lg ", x2_ref);
    printf("x1 = %lg ", failed_test_params->result.x1);
    printf("x2 = %lg ", failed_test_params->result.x2);
    printf("\n" RESET);

    return 0;
}

/*!
Проверяет значение value
\return true, если число корректное, иначе false
*/
bool IsValid(double value, char *end_ptr, char *first_ptr)
{
        if (end_ptr == first_ptr || *end_ptr != 0)
        {
            printf("Invalid Input!!! Try again...\n");
            return false;
        }

        if (value == HUGE_VAL || value == HUGE_VALF || value == HUGE_VALL)
        {
            printf("Overflow! Value too large.\n");
            return false;
        }

        if (isnan(value))
        {
            printf("Invalid Input! Not a number.\n");
            return false;
        }

        if (isinf(value))
        {
            printf("Invalid Input! Infinity.\n");
            return false;
        }

        if (!isfinite(value))
        {
            printf("Invalid Input!\n");
            return false;
        }

        return true;
}

/*!
Заполняет буфер из stdin
\param[in] buf - массив типа char
\param[in] buf_size - размер массива типа size_t
\return 0, если буфер был переполнен, иначе 1
*/
int FillBuf(char buf[], size_t buf_size)
{
    unsigned int curr_pos = 0;

    memset(buf, 0, buf_size);

    for (curr_pos = 0; curr_pos != buf_size - 1; ++curr_pos)
    {
        int c = getchar();
        if (c == EOF || c == '\n')
        {
            break;
        }

        buf[curr_pos] = (char)c;
    }

    if (curr_pos == buf_size - 1)
    {
        printf("Buffer Overflow!\n");
        //fflush(stdin);
        while(getchar() != '\n');

        return 0;
    }

    return 1;
}

/*!
Выводит перый член уравнения
*/
int PrintA(double a)
{
    if (Compare(a, 1))
    {
        printf("X%c", SQUARE_SYMBOL);
    }

    else if (Compare(a, -1))
    {
        printf("-X%c", SQUARE_SYMBOL);
    }

    else
    {
        printf("%lgX%c", a, SQUARE_SYMBOL);
    }

    return 0;
}

/*!
Выводит второй член уравнения
*/
int PrintB(double b, int *first_print)
{
    if (*first_print == 0)
    {
        *first_print = 1;

        if (Compare(b, 1))
        {
            printf("X");
        }

        else if (Compare(b, 1))
        {
            printf("-X");
        }

        else
        {
            if (b > 0)
            {
                printf("%lgX", b);
            }

            else
            {
                printf("-%lgX", fabs(b));
            }
        }
    }

    else
    {
        if (Compare(b, 1))
        {
            printf(" + X");
        }

        else if (Compare(b, -1))
        {
            printf(" - X");
        }

        else
        {
            if (b > 0)
            {
                printf(" + %lgX", b);
            }

            else
            {
                printf(" - %lgX", fabs(b));
            }
        }
    }

    return 0;
}

/*!
Выводит третий член уравнения
*/
int PrintC(double c, int *first_print)
{
    if (*first_print == 0)
    {
        *first_print = 1;
        printf("%lg", c);
    }

    else
    {
        if (c > 0)
        {
            printf(" + %lg", c);
        }

        else
        {
            printf(" - %lg", fabs(c));
        }
    }

    return 0;
}
