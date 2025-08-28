/*!
\file
\brief Файл floating.cpp

Данный файл содержит в себе функции, используемые в программе.
*/

#include <math.h>

#include "floating.h"

/*!
Сравнивает дла числа типа double
\param val1, val2 Сравниваемые числа
\return Если числа можно считать равными true, иначе false
*/
bool Compare(double val1, double val2)
{
    return (fabs(val1 - val2) <= MIN_DIFF);
}

/*!
Проверяет, является ли число типа double нулем
\param val Проверяемое число
\return true, если число можно считать нулем, иначе false
*/
bool IsZero(double val)
{
    return (fabs(val) <= MIN_DIFF);
}
