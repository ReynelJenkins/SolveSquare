#ifndef FLOATING_H
#define FLOATING_H

const double MIN_DIFF = 1e-6;

enum Operations
{
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV
};

bool IsZero(double val);
bool Compare(double val1, double val2);
//double DoOperation(double val1, double val2, int op_type);
#endif //FLOATING_H
