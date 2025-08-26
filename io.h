#ifndef IO_H
#define IO_H

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"
#define RESET   "\033[0m"

#define BG_RED     "\033[41m"
#define BG_GREEN   "\033[42m"
#define BG_YELLOW  "\033[43m"
#define BG_BLUE    "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN    "\033[46m"
#define BG_WHITE   "\033[47m"
#define BG_RESET   "\033[49m"

int PrintEquation(const struct Coefficients* my_coeff);
int PrintResult(struct Result* my_result);
int UserInput(struct Coefficients* my_coeff);
double InputNumber(const char* prompt);
void PrintCat();
void PrintTestError(const struct Params *failed_test_params, double x1_ref, double x2_ref);

const int BUF_SIZE = 100;

#endif  //IO_H
