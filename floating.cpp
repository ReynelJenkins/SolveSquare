#include<math.h>

#include "floating.h"

bool Compare(double val1, double val2)
{
    return (fabs(val1 - val2) <= MIN_DIFF) ? true : false;
}

bool IsZero(double val)
{
    return (fabs(val) <= MIN_DIFF) ? true : false;
}
 /*
double DoOperation(double val1, double val2, int op_type)
{
    switch(op_type)
    {
        case OP_ADD:
            if MAX_DOUBLE_VALUE - val2
    }

} */
