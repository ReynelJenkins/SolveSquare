/*!
\file
\brief ���� floating.cpp

������ ���� �������� � ���� �������, ������������ � ���������.
*/

#include <math.h>

#include "floating.h"

/*!
���������� ��� ����� ���� double
\param val1, val2 ������������ �����
\return ���� ����� ����� ������� ������� true, ����� false
*/
bool Compare(double val1, double val2)
{
    return (fabs(val1 - val2) <= MIN_DIFF);
}

/*!
���������, �������� �� ����� ���� double �����
\param val ����������� �����
\return true, ���� ����� ����� ������� �����, ����� false
*/
bool IsZero(double val)
{
    return (fabs(val) <= MIN_DIFF);
}
