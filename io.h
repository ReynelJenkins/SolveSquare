#ifndef IO_H
#define IO_H

int PrintEquation(const struct Coefficients* my_coeff);
int PrintResult(int n, double x1, double x2);
int UserInput(struct Coefficients* my_coeff);
double InputNumber(const char* prompt);

#endif  //IO_H
