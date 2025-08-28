/*!
\file
\brief ������������ ���� solve.h

������ ���� �������� � ���� ����������� ��������, �������� � �������, ������������ � ���������.
*/

#ifndef SOLVE_H
#define SOLVE_H

/// ��������� ���������� ��� ���������� ���� double - ����������� ����������� ���������
struct Coefficients {
    double a, b, c;
};


/// ��������� ���������� ��� ���������� ���� double - ������� ����������� ��������� � ���� ���������� ���� int ���������� ���������� ��������� ������
struct Result {
    double x1, x2;
    int n_roots;
};

/// ����� ��������� ��������� ���������� ������ ��� �������
enum RootsAmount
{
    ROOTS_AMOUNT_ERR_CODE                = -2,  ///< ���������, ��� ���� ���������� ������
    ROOTS_AMOUNT_INF_ROOTS               = -1,  ///< ���������, ��� ���������� ����������� ���������� ������
    ROOTS_AMOUNT_NO_ROOTS                =  0,  ///< ���������, ��� ������ �� ����������
    ROOTS_AMOUNT_ONE_ROOT                =  1,  ///< ���������, ��� ��������� ���� ������
    ROOTS_AMOUNT_TWO_ROOTS               =  2,  ///< ���������, ��� ���������� ��� �����
    ROOTS_AMOUNT_ROOT_NOT_FINITE         =  3,  ///< ���������, ��� �������� ������ �� �������� �������� ������
    ROOTS_AMOUNT_DISCRIMINANT_NOT_FINITE =  4   ///< ���������, ��� �������� ������������ �� �������� �������� ������
};

int SolveSquare(const struct Coefficients *coeffs, struct Result *result);
int SolveLinearEquation(double b, double c, struct Result *result);
int SolveSpecialCase(const struct Coefficients *coeffs, struct Result *result);

#endif //SOLVE_H
