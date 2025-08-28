/*!
\file
\brief Заголовочный файл solve.h

Данный файл содержит в себе определения структур, констант и функций, используемых в программе.
*/

#ifndef SOLVE_H
#define SOLVE_H

/// Структура содержащая три переменных типа double - коэффиценты квадратного уравнения
struct Coefficients {
    double a, b, c;
};


/// Структура содержащая две переменных типа double - решения квадратного уравнения и одну переменную типа int содержащую количество найденных корней
struct Result {
    double x1, x2;
    int n_roots;
};

/// Набор возможных вариантов количества корней при решении
enum RootsAmount
{
    ROOTS_AMOUNT_ERR_CODE                = -2,  ///< Указывает, что была обнаружена ошибка
    ROOTS_AMOUNT_INF_ROOTS               = -1,  ///< Указывает, что обнаружено бесконечное количество корней
    ROOTS_AMOUNT_NO_ROOTS                =  0,  ///< Указывает, что корней не обнаружено
    ROOTS_AMOUNT_ONE_ROOT                =  1,  ///< Указывает, что обнаружен один корень
    ROOTS_AMOUNT_TWO_ROOTS               =  2,  ///< Указывает, что обнаружено два корня
    ROOTS_AMOUNT_ROOT_NOT_FINITE         =  3,  ///< Указывает, что найденый корень не является конечным числом
    ROOTS_AMOUNT_DISCRIMINANT_NOT_FINITE =  4   ///< Указывает, что найденый дискриминант не является конечным числом
};

int SolveSquare(const struct Coefficients *coeffs, struct Result *result);
int SolveLinearEquation(double b, double c, struct Result *result);
int SolveSpecialCase(const struct Coefficients *coeffs, struct Result *result);

#endif //SOLVE_H
