#include <string.h>

#include "unit_test.h"

#include "flag_parse.h"


/*!
���� ����� ��������� ������
\param[in] argc ���������� ����������
\param[in] *argv[] ������ ���������� �� ������
\return ���������� ������
*/
int FlagParse(int argc, char *argv[])
{
    if (argc != 1 && (strcmp(argv[1], "-t") == 0 || strcmp(argv[1], "--test") == 0))
    {
        TestSolveSquare();
        return 1;
    }

    return 0;
}
