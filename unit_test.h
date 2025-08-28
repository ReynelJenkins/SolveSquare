/*!
\file
\brief Заголовочный файл unit_test.h

Данный файл содержит в себе определения структуры и функций, используемых в программе.
*/

#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include "solve.h" //????????????????? можно ли так?

struct Test
{
    struct Coefficients coeffs;
    struct Result result;
};

int TestSolveSquare();
int ReadTestsFromFile();

#endif //UNIT_TEST_H
