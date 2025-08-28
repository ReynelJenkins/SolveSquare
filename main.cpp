/*!
\file
\brief ���� main.cpp

������ ���� �������� � ���� �������� ������� ���������.
*/

//#include <TXLib.h>
#include <stdio.h>
#include <string.h>

#include "io.h"
#include "solve.h"
#include "unit_test.h"

/*!
�������� ������� ���������
*/
int main(int argc, char *argv[])
{
    if (argc != 1 && (strcmp(argv[1], "-t") == 0 || strcmp(argv[1], "--test") == 0))
    {
        TestSolveSquare();
        return 0;
    }

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
