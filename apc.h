#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUCCESS 0
#define FAILURE -1

extern int positive_flag1;
extern int positive_flag2;
extern int negative_flag1;
extern int negative_flag2;

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} Dlist;

/* Double linked list functions */
int insert_last(Dlist **head, Dlist **tail, int data);
int insert_first(Dlist **head, Dlist **tail, int data);
int delete_list(Dlist **head, Dlist **tail);
void print_list(Dlist *head);

/* Comparison */
int compare_list(Dlist *head1, Dlist *head2);

/*Sign checking*/
void check_sign(char *num1, char *num2);

/* APC operations */
//Addition
int addition(Dlist *tail1, Dlist *tail2,Dlist **headR, Dlist **tailR);
//Subtraction
int subtraction(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);
//Multiplication
int multiplication(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);
//Division
int division(Dlist *head1,Dlist *head2,Dlist **headR,Dlist **tailR);
#endif