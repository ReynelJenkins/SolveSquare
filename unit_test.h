/*!
\file
\brief ������������ ���� unit_test.h

������ ���� �������� � ���� ����������� ��������� � �������, ������������ � ���������.
*/

#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include "solve.h" //????????????????? ����� �� ���?

struct Test
{
    struct Coefficients coeffs;
    struct Result result;
};

int TestSolveSquare();
int ReadTestsFromFile();

#endif //UNIT_TEST_H
