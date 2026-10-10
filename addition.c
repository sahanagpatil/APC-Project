#include "apc.h"

int addition(Dlist *tail1, Dlist *tail2,Dlist **headR, Dlist **tailR)
{
    int carry = 0;
    int sum;
    int digit;

    while (tail1 != NULL || tail2 != NULL)
    {
        if (tail1 != NULL && tail2 != NULL)
        {
            sum = tail1->data + tail2->data + carry;
            tail1 = tail1->prev;
            tail2 = tail2->prev;
        }
        else if (tail1 != NULL)
        {
            sum = tail1->data + carry;
            tail1 = tail1->prev;
        }
        else
        {
            sum = tail2->data + carry;
            tail2 = tail2->prev;
        }

        digit = sum % 10;
        carry = sum / 10;

        if (insert_first(headR, tailR, digit) == FAILURE)
        {
            return FAILURE;
        }
    }

    if (carry != 0)
    {
        if (insert_first(headR, tailR, carry) == FAILURE)
        {
            return FAILURE;
        }
    }

    return SUCCESS;
}