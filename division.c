#include "apc.h"

int is_zero(Dlist *head)
{
    while (head != NULL)
    {
        if (head->data != 0)
        {
            return 0;
        }

        head = head->next;
    }

    return 1;
}

int division(Dlist *head1, Dlist *head2,
             Dlist **headR, Dlist **tailR)
{
    int num1 = 0;
    int num2 = 0;
    int quotient = 0;

    Dlist *temp;

    if (is_zero(head2))
    {
        printf("Number cannot be divided by 0\n");
        return FAILURE;
    }

    if (is_zero(head1))
    {
        insert_last(headR, tailR, 0);
        return SUCCESS;
    }

    if (compare_list(head1, head2) < 0)
    {
        insert_last(headR, tailR, 0);
        return SUCCESS;
    }

    temp = head1;

    while (temp != NULL)
    {
        num1 = (num1 * 10) + temp->data;
        temp = temp->next;
    }

    temp = head2;

    while (temp != NULL)
    {
        num2 = (num2 * 10) + temp->data;
        temp = temp->next;
    }

    while (num1 >= num2)
    {
        num1 = num1 - num2;
        quotient++;
    }

    if (quotient == 0)
    {
        insert_last(headR, tailR, 0);
        return SUCCESS;
    }

    while (quotient > 0)
    {
        insert_first(headR,
                     tailR,
                     quotient % 10);

        quotient = quotient / 10;
    }

    return SUCCESS;
}