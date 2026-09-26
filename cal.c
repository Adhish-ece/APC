#include "cal.h"

/*
 * Project: Arbitrary Precision Calculator (APC)
 * Author: Adhish V (Emertxe Project)
 *
 * Note: When using '*' for multiplication, enclose it in quotes ('*')
 * or escape it (\*) to prevent shell globbing. Alternatively, use 'x'.
 */

 
int division(Dlist *head1, Dlist* tail1, Dlist *head2, Dlist *tail2, Dlist **res_head,Dlist **res_tail, Dlist **rem_head, Dlist **rem_tail)
{
    if(!head1 && !head2)
    return LIST_EMPTY;

    if(head2->data == 0 && head2->next == NULL)
    return DIVISION_BY_ZERO;

    int cmp = compare_lists(head1,head2);
    
    if(cmp<0)
    {
        dl_insert_first(res_head,res_tail,0);
        if(rem_head && rem_tail)
        {
            *rem_head = copy_list(head1,NULL);
        }
        return SUCCESS;
    }
    

    Dlist *curr_div_head =  NULL, *curr_div_tail = NULL;
    Dlist *curr = head1;

    while(curr)
    {
        if(dl_insert_last(&curr_div_head,&curr_div_tail,curr->data) != SUCCESS)
        {
            dl_delete_list(&curr_div_head,&curr_div_tail);
            return MEMORY_ALLOCATION_FAILURE;
        }
        remove_leading_zeros(&curr_div_head,&curr_div_tail);

        int count = 0;

        while(compare_lists(curr_div_head,head2)>=0)
        {
            Dlist *sub_res_head = NULL, *sub_res_tail = NULL;
            int st = subtraction(curr_div_head,curr_div_tail,head2,tail2,&sub_res_head,&sub_res_tail);
            if(st != SUCCESS)
            {
                dl_delete_list(&curr_div_head,&curr_div_tail);
                return st;
            }
            dl_delete_list(&curr_div_head,&curr_div_tail);
            curr_div_head = sub_res_head;
            curr_div_tail = sub_res_tail;
            count++;
        }
        dl_insert_last(res_head,res_tail,count);
        curr=curr->next;
    }
    *rem_head = curr_div_head;
    *rem_tail = curr_div_tail;
    remove_leading_zeros(res_head,res_tail);
    return SUCCESS;
}


int multiplication(Dlist *head1, Dlist* tail1, Dlist *head2, Dlist *tail2, Dlist **res_head,Dlist **res_tail)
{
    if (!tail1 || !tail2)
    {
        return LIST_EMPTY;
    }
    Dlist *curr2 = tail2;
    int shift = 0;
    *res_head = NULL;
    *res_tail = NULL;

    if (dl_insert_first(res_head,res_tail,0) !=SUCCESS)
    {
        return MEMORY_ALLOCATION_FAILURE;
    }
    while (curr2)
    {
        
        Dlist *curr1 = tail1;
        Dlist *prod_head = NULL, *prod_tail = NULL;
        long long carry = 0;
        while(curr1 || carry)
        {
            long long val1 = curr1 ? curr1->data : 0;
            long long prod = (val1 * curr2->data) + carry;
            carry = prod/10000;
            prod = prod%10000;
            if(dl_insert_first(&prod_head,&prod_tail,(int)prod) != SUCCESS)
            {
                dl_delete_list(&prod_head,&prod_tail);
                return MEMORY_ALLOCATION_FAILURE;
            }
            if(curr1)
            {
                curr1= curr1->prev;
            }
        }
        for(int i = 0;i < shift;i++)
        {
            if(dl_insert_last(&prod_head,&prod_tail,0) != SUCCESS)
            {
                dl_delete_list(&prod_head,&prod_tail);
                return MEMORY_ALLOCATION_FAILURE;
            }
        }
        Dlist *temp_head = NULL, *temp_tail = NULL;
        int status = addition(*res_tail,prod_tail,&temp_head,&temp_tail);
        if(status != SUCCESS)
        {
            dl_delete_list(&prod_head,&prod_tail);
            return status;
        }
        dl_delete_list(res_head,res_tail);
        *res_head = temp_head;
        *res_tail = temp_tail;
        dl_delete_list(&prod_head,&prod_tail);

        shift++;
        curr2 = curr2->prev;
    }
    remove_leading_zeros(res_head,res_tail);
    return SUCCESS;   
    
    
}
int subtraction(Dlist *head1, Dlist* tail1, Dlist *head2, Dlist *tail2, Dlist **res_head,Dlist **res_tail)
{
    if(!tail1 & !tail2)
    {
        return LIST_EMPTY;
    }
    int borrow = 0;

    while(tail1 || tail2)
    {
        int val1 = tail1 ? tail1->data : 0;
        int val2 = tail2 ? tail2->data : 0;

        int diff = val1-val2-borrow;
        if(diff<0)
        {
            diff+=10000;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        int status = dl_insert_first(res_head,res_tail,diff);
        if(status != SUCCESS)
        return status;

        if(tail1)
        tail1 = tail1->prev;
        if(tail2)
        tail2 = tail2->prev;
    }
    remove_leading_zeros(res_head,res_tail);
    return SUCCESS;
}




int addition(Dlist *tail1, Dlist *tail2, Dlist **res_head,Dlist **res_tail)
{
    if(!tail1 && !tail2)
    return LIST_EMPTY;
    int carry = 0;
    while(tail1 || tail2 || carry)
    {
        int sum = carry;
        if(tail1)
        {
            sum+=tail1->data;
            tail1 = tail1->prev;
        }
        if(tail2)
        {
            sum+=tail2->data;
            tail2 = tail2->prev;
        }
        carry = sum/10000;
        sum = sum%10000;
        int status = dl_insert_first(res_head,res_tail,sum);
        if(status != SUCCESS)
        return status;
    }
    return SUCCESS;
}