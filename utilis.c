#include "utilis.h"


void print_error(int status)
{
    switch (status) {
        case INVALID_ARG_COUNT:
            printf("Error [INVALID_ARG_COUNT]: Expected 3 arguments.\n");
            printf("Usage: ./a.out <number1> <operator> <number2>\n");
            break;
        case INVALID_OPERATOR:
            printf("Error [INVALID_OPERATOR]: Operator must be +, -, x, *, or /.\n");
            break;
        case INVALID_INPUT:
            printf("Error [INVALID_INPUT]: Operands must contain valid numeric digits.\n");
            break;
        case DIVISION_BY_ZERO:
            printf("Error [DIVISION_BY_ZERO]: Cannot divide by zero.\n");
            break;
        case MEMORY_ALLOCATION_FAILURE:
            printf("Error [MEMORY_ALLOCATION_FAILURE]: Failed to allocate memory for list node.\n");
            break;
        case LIST_EMPTY:
            printf("Error [LIST_EMPTY]: Operation failed on empty list.\n");
            break;
        default:
            printf("Error [FAILURE]: An unknown error occurred.\n");
            break;
}
}

int validate_syntax(int argc, char *argv[])
{
    if(argc !=4 )
    return INVALID_ARG_COUNT;

    if(strlen(argv[2]) !=1 )
    {
        return INVALID_OPERATOR;
    }
    char op = *argv[2];
    if (op != '+' && op != '-' && op != 'x' && op != '*' && op != '/')
    return INVALID_OPERATOR;
    
    for(int arg_idx = 1;arg_idx<=3;arg_idx+=2)
    {
        char *str = argv[arg_idx];
        int i = 0;
        if(str[i]=='+' || str[i] == '-')
        {
            i++;
        }
        if(str[i] == '\0')
        {
            return INVALID_INPUT;
        }
        while(str[i] != '\0')
        {
            if(!isdigit((unsigned char)str[i]))
            {
                return INVALID_INPUT;
            }
            i++;
        }
    }
    return SUCCESS;
}

int parse_input(char *str,Dlist **head,Dlist **tail,int *sign)
{
    if(str == NULL || strlen(str)==0)
    return INVALID_INPUT;
    *sign = 1;
    int len = strlen(str);
    int start = 0;
    if(str[0]=='-')
    {
        *sign = -1;
        start = 1;
    }
    else if(str[0] == '+')
    {
        *sign = 1;
        start = 1;
    }
    int end = len-1;
    while(end>= start)
    {
        int chunk_start = end-3;
        if(chunk_start<start)
        chunk_start = start;

        int val = 0;
        for(int i = chunk_start;i<=end;i++)
        {
            val = val*10 + (str[i]-'0');
        }
        int status = dl_insert_first(head,tail,val);
        if(status != SUCCESS)
        {
            return status;
        }
        end = chunk_start-1;
    }
    remove_leading_zeros(head,tail);
    return SUCCESS;
}

void remove_leading_zeros(Dlist **head,Dlist **tail)
{
    if(*head == NULL)
    {
        return;
    }
    while((*head)->next && (*head)->data == 0)
    {
        Dlist *temp=*head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }

    if (*head && (*head)->data == 0 && (*head)->next == NULL && tail)
    {
        *tail = *head;
    }
    
}

int compare_lists(Dlist *head1,Dlist*head2)
{
    remove_leading_zeros(&head1,NULL);
    remove_leading_zeros(&head2,NULL);
    int len1 = dl_get_length(head1);
    int len2 = dl_get_length(head2);

    if(len1>len2)
    return 1;
    if(len2>len1)
    return -1;
    while(head1 && head2)
    {
        if(head1->data > head2->data)
        {
            return 1;
        }
        if(head1->data < head2->data)
        {
            return -1;
        }
        head1 = head1->next; 
        head2 = head2->next;
    }
    return 0;

}