/*!
\file
\brief ���� main.cpp

������ ���� �������� � ���� �������� ������� ���������.
*/

//#include <TXLib.h>
#include <stdio.h>

#include "io.h"
#include "solve.h"
#include "unit_test.h"

/*!
�������� ������� ���������
*/
int main()
{
    printf(YELLOW "\nMeow\n\n" RESET);

    struct Result result = {};

    struct Coefficients coeffs = {};

    UserInput(&coeffs);

    result.n_roots = SolveSquare(&coeffs, &result);

    PrintResult(&result);

    TestSolveSquare();

    printf(MAGENTA "\n-----COMMIT GITHUB-----\n" RESET);

    return 0;
}
