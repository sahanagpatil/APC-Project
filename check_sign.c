#include "apc.h"

void check_sign(char *num1, char *num2)
{
    positive_flag1 = 0;
    positive_flag2 = 0;
    negative_flag1 = 0;
    negative_flag2 = 0;

    if (num1[0] == '-')
           negative_flag1 = 1;
    else
        positive_flag1 = 1;

    if (num2[0] == '-')
        negative_flag2 = 1;
    else
        positive_flag2 = 1;
}