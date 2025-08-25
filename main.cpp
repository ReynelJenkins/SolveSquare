#include <TXLib.h>
#include <stdio.h>

#include "io.h"
#include "solve.h"
#include "unit_test.h"

int main()
{
    Params equation = {};

    UserInput(&(equation.coeffs));

    equation.result.n_roots = SolveSquare(&equation);

    PrintResult(&(equation.result)); // TODO: почитать про этапы компил€ции

    TestSolveSquare();               // TODO: Makefile
                                     // TODO: FSM, Readme, licence, doxygen
    return 0;
}
