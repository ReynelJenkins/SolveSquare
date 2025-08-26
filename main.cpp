#include <TXLib.h>
#include <stdio.h>

#include "io.h"
#include "solve.h"
#include "unit_test.h"

int main()
{
    printf(YELLOW "\nMeow\n\n" RESET);

    struct Params equation = {};

    UserInput(&(equation.coeffs));

    equation.result.n_roots = SolveSquare(&equation.coeffs, &equation.result);

    PrintResult(&(equation.result));

    TestSolveSquare();

    printf(MAGENTA "\n-----COMMIT GITHUB-----\n" RESET);

    return 0;
}
