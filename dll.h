#ifndef DLL_H
#define DLL_H

#define SUCCESS                   0
#define FAILURE                  -1
#define LIST_EMPTY               -2
#define DIVISION_BY_ZERO         -3
#define INVALID_INPUT            -4
#define MEMORY_ALLOCATION_FAILURE -5
#define INVALID_OPERATOR         -6
#define INVALID_ARG_COUNT        -7

#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}Dlist;


Dlist *copy_list(Dlist *head, int *status);
int dl_insert_first(Dlist **head, Dlist **tail, int data);
int dl_insert_last(Dlist **head, Dlist **tail, int data);
int dl_get_length(Dlist *head);
void dl_delete_list(Dlist **head, Dlist **tail);
void dl_print_list(Dlist *head,int sign);

#endif