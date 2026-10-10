#include "apc.h"

int compare_list(Dlist *head1, Dlist *head2)
{
    int count1 = 0;
    int count2 = 0;

    Dlist *temp1 = head1;
    Dlist *temp2 = head2;

    while (temp1 != NULL)
    {
        count1++;
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        count2++;
        temp2 = temp2->next;
    }

    if (count1 > count2)
    {
        return 1;
    }
    else if (count1 < count2)
    {
        return -1;
    }

    temp1 = head1;
    temp2 = head2;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data > temp2->data)
        {
            return 1;
        }
        else if (temp1->data < temp2->data)
        {
            return -1;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return 0;
}
