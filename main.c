#include "apc.h"

int positive_flag1 = 0;
int positive_flag2 = 0;
int negative_flag1 = 0;
int negative_flag2 = 0;

int main(int argc, char *argv[])
{
    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *headR = NULL, *tailR = NULL;

    if (argc != 4)
    {
        printf("Usage: ./a.out <operand1> <operator> <operand2>\n");
        return FAILURE;
    }

    char *operand1 = argv[1];
    char *operand2 = argv[3];
    char operator = argv[2][0];

    check_sign(operand1, operand2);

    int start1 = (operand1[0] == '-') ? 1 : 0;
    int start2 = (operand2[0] == '-') ? 1 : 0;

    for (int i = start1; operand1[i] != '\0'; i++)
    {
        if (isdigit(operand1[i]))
        {
            if (insert_last(&head1, &tail1, operand1[i] - '0') == FAILURE)
            {
                return FAILURE;
            }
        }
    }

    for (int i = start2; operand2[i] != '\0'; i++)
    {
        if (isdigit(operand2[i]))
        {
            if (insert_last(&head2, &tail2, operand2[i] - '0') == FAILURE)
            {
                return FAILURE;
            }
        }
    }

    switch (operator)
    {
       case '+':
{
    int result = compare_list(head1, head2);

    /* +a + +b */
    if (positive_flag1 && positive_flag2)
    {
        if (addition(tail1, tail2, &headR, &tailR) == FAILURE)
        {
            return FAILURE;
        }

        print_list(headR);
    }

    /* +a + -b */
    else if (positive_flag1 && negative_flag2)
    {
        if (result == 0)
        {
            printf("0\n");
        }
        else if (result > 0)
        {
            if (subtraction(tail1, tail2, &headR, &tailR) == FAILURE)
            {
                return FAILURE;
            }

            print_list(headR);
        }
        else
        {
            if (subtraction(tail2, tail1, &headR, &tailR) == FAILURE)
            {
                return FAILURE;
            }

            printf("-");
            print_list(headR);
        }
    }

    /* -a + +b */
    else if (negative_flag1 && positive_flag2)
    {
        if (result == 0)
        {
            printf("0\n");
        }
        else if (result > 0)
        {
            if (subtraction(tail1, tail2, &headR, &tailR) == FAILURE)
            {
                return FAILURE;
            }

            printf("-");
            print_list(headR);
        }
        else
        {
            if (subtraction(tail2, tail1, &headR, &tailR) == FAILURE)
            {
                return FAILURE;
            }

            print_list(headR);
        }
    }

    /* -a + -b */
    else
    {
        if (addition(tail1, tail2, &headR, &tailR) == FAILURE)
        {
            return FAILURE;
        }

        printf("-");
        print_list(headR);
    }

    break;
}
    
    case '-':
{
    int result = compare_list(head1, head2);

    /* +a - +b */
    if (positive_flag1 && positive_flag2)
    {
        if (result == 0)
        {
            printf("0\n");
        }
        else if (result > 0)
        {
            if (subtraction(tail1, tail2, &headR, &tailR) == FAILURE)
            {
                return FAILURE;
            }

            print_list(headR);
        }
        else
        {
            if (subtraction(tail2, tail1, &headR, &tailR) == FAILURE)
            {
                return FAILURE;
            }

            printf("-");
            print_list(headR);
        }
    }

    /* +a - -b */
    else if (positive_flag1 && negative_flag2)
    {
        if (addition(tail1, tail2, &headR, &tailR) == FAILURE)
        {
            return FAILURE;
        }

        print_list(headR);
    }

    /* -a - +b */
    else if (negative_flag1 && positive_flag2)
    {
        if (addition(tail1, tail2, &headR, &tailR) == FAILURE)
        {
            return FAILURE;
        }

        printf("-");
        print_list(headR);
    }

    /* -a - -b */
    else
    {
        if (result == 0)
        {
            printf("0\n");
        }
        else if (result > 0)
        {
            if (subtraction(tail1, tail2, &headR, &tailR) == FAILURE)
            {
                return FAILURE;
            }

            printf("-");
            print_list(headR);
        }
        else
        {
            if (subtraction(tail2, tail1, &headR, &tailR) == FAILURE)
            {
                return FAILURE;
            }

            print_list(headR);
        }
    }

    break;
}

    case '*':
{
    if (multiplication(tail1, tail2, &headR, &tailR) == FAILURE)
    {
        printf("Multiplication failed\n");
        return FAILURE;
    }

    if ((positive_flag1 && negative_flag2) ||
        (negative_flag1 && positive_flag2))
    {
        printf("-");
    }

    print_list(headR);

    break;
}

   case '/':
{
    if (division(head1, head2, &headR, &tailR) == FAILURE)
    {
        return FAILURE;
    }

    if ((positive_flag1 && negative_flag2) ||
        (negative_flag1 && positive_flag2))
    {
        printf("-");
    }

    print_list(headR);

    break;
}

    default:
        printf("Invalid operator\n");
        return FAILURE;
    }

    delete_list(&head1, &tail1);
    delete_list(&head2, &tail2);
    delete_list(&headR, &tailR);

    return SUCCESS;
}