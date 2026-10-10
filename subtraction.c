#include "apc.h"

int subtraction(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR)
{
    int borrow = 0;
    int diff;

    while (tail1 != NULL || tail2 != NULL)
    {
        if (tail1 != NULL && tail2 != NULL)
        {
            diff = tail1->data - tail2->data - borrow;

            if (diff < 0)
            {
                diff += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }

            tail1 = tail1->prev;
            tail2 = tail2->prev;
        }
        else if (tail1 != NULL)
        {
            diff = tail1->data - borrow;

            if (diff < 0)
            {
                diff += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }

            tail1 = tail1->prev;
        }

        if (insert_first(headR, tailR, diff) == FAILURE)
        {
            return FAILURE;
        }
    }

    /* Remove leading zeros */

    while (*headR != NULL &&
           (*headR)->data == 0 &&
           (*headR)->next != NULL)
    {
        Dlist *temp = *headR;

        *headR = (*headR)->next;

        (*headR)->prev = NULL;

        free(temp);
    }

    if (*headR == NULL)
    {
        *tailR = NULL;
    }
    else
    {
        *tailR = *headR;

        while ((*tailR)->next != NULL)
        {
            *tailR = (*tailR)->next;
        }
    }

    return SUCCESS;
}