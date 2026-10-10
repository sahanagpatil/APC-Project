#include "apc.h"

int multiplication(Dlist *tail1, Dlist *tail2,Dlist **headR, Dlist **tailR)
{
    Dlist *temp1 = tail1;
    Dlist *temp2 = tail2;

    Dlist *rhead1 = NULL;
    Dlist *rtail1 = NULL;

    Dlist *rhead2 = NULL;
    Dlist *rtail2 = NULL;

    int count = 0;

    while (temp2 != NULL)
    {
        int carry = 0;
        int result;

        rhead1 = NULL;
        rtail1 = NULL;

        for (int i = 0; i < count; i++)
        {
            insert_first(&rhead1, &rtail1, 0);
        }

        tail1 = temp1;

        while (tail1 != NULL)
        {
            result =
            (tail1->data * temp2->data) + carry;

            carry = result / 10;

            result = result % 10;

            insert_first(&rhead1,
                         &rtail1,
                         result);

            tail1 = tail1->prev;
        }

        if (carry)
        {
            insert_first(&rhead1,
                         &rtail1,
                         carry);
        }

        if (count == 0)
        {
            *headR = rhead1;
            *tailR = rtail1;
        }
        else
        {
            rhead2 = NULL;
            rtail2 = NULL;

            addition(rtail1,
                     *tailR,
                     &rhead2,
                     &rtail2);

            delete_list(headR, tailR);

            *headR = rhead2;
            *tailR = rtail2;

            delete_list(&rhead1, &rtail1);
        }

        count++;

        temp2 = temp2->prev;
    }

    return SUCCESS;
}