#include "apc.h"

int insert_last(Dlist **head,Dlist **tail,int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if(new == NULL)
    {
        return FAILURE;
    }
    new -> data = data;
    new -> prev = NULL;
    new -> next = NULL;
    if(*head == NULL)
    {
        *head = new;
        *tail = new;
    }
    else
    {
        new -> prev = *tail;
        (*tail) -> next = new;
        *tail = new;
    }
    return SUCCESS;
}
int insert_first(Dlist **head,Dlist **tail,int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if(new == NULL)
    {
        return FAILURE;
    }
    new -> data = data;
    if(*head == NULL)
    {
        new -> prev = NULL;
        new -> next = NULL;
        *head = new;
        *tail = new;
    }
    else
    {
        new -> prev = NULL;
        new -> next = *head;
        (*head) -> prev = new;
        *head = new;
    }
    return SUCCESS;
}
int delete_list(Dlist **head,Dlist **tail)
{
    Dlist *temp;
    while(*head != NULL)
    {
        temp = *head;
        *head = (*head) -> next;
        free(temp);
    }
    *tail =NULL;
    return SUCCESS;
}
void print_list(Dlist *head)
{
    Dlist *temp = head;
    while(temp != NULL)
    {
        printf("%d",temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}