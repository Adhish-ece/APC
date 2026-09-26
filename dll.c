#include "dll.h"

Dlist *copy_list(Dlist *head, int *status)
{
    Dlist *new_head = NULL, *new_tail = NULL;
    while(head)
    {
        if(dl_insert_last(&new_head,&new_tail,head->data) != SUCCESS)
        {
            if(status)
            {
                *status = MEMORY_ALLOCATION_FAILURE;
                dl_delete_list(&new_head,&new_tail);
                return NULL;
            }
        }
        head = head->next;
    }

    if(status)
    {
        *status = SUCCESS;

    }
    return new_head;
}
int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if(new == NULL)
    {
        return MEMORY_ALLOCATION_FAILURE;
    }
    new->data = data;
    new->prev = NULL;
    new->next = *head;
    
    if(*head == NULL)
    {
        *tail = *head = new;
    }
    else
    {
        (*head)->prev = new;
        *head = new;
    }
    return SUCCESS;
}
int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if(new == NULL)
    {
        return MEMORY_ALLOCATION_FAILURE;
    }
    new->data = data;
    new->next = NULL;
    new->prev = *tail;
    
    if(*tail == NULL)
    {
        *head = *tail = new;
    }
    else
    {
        (*tail)->next = new;
        *tail = new;
    }
    return SUCCESS;
}

int dl_get_length(Dlist *head)
{
    int count =0;
    while(head)
    {
        count++;
        head = head->next;
    }
    return count;
}

void dl_delete_list(Dlist **head, Dlist **tail)
{
    Dlist *temp;
    while(*head != NULL)
    {
        temp =  *head;
        *head = (*head)->next;
        free(temp);
    }
    *head = *tail = NULL;
    return;
}

void dl_print_list(Dlist *head,int sign)
{
    if(!head)
    {
        printf("0\n");
        return;
    }
    while(head->next && head->data ==0)
    {
        head = head->next;
    }
    if(sign<0 && !(head->data == 0 && head->next == NULL))
    {
        printf("-");
    }
    printf("%d",head->data);
    head = head->next;
    while (head)
    {
        printf("%04d",head->data);
        head = head->next;
    }
    printf("\n");
    
}