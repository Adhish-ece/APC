#include "cal.h"


int main(int argc, char *argv[])
{
    int status = validate_syntax(argc,argv);
    if(status != SUCCESS)
    {
        print_error(status);
        return status;
    }
   
    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *res_head = NULL, *res_tail = NULL;
    Dlist *rem_head = NULL, *rem_tail = NULL;
    
    int sign1 = 1, sign2 = 1, res_sign = 1;
    status = parse_input(argv[1],&head1,&tail1,&sign1);
    if(status != SUCCESS)
    {
        print_error(status);
        return status;
    }
    char op = *argv[2];
  
    status = parse_input(argv[3],&head2,&tail2,&sign2);
    if(status != SUCCESS)
    {
        print_error(status);
        return status;
    }

    switch(op)
    {
        case '+':
        if(sign1 == sign2)
        {
            status = addition(tail1,tail2,&res_head,&res_tail);
            res_sign = sign1;
        }
        else
        {
            int cmp = compare_lists(head1,head2);
            if(cmp>=0)
            {
                status = subtraction(head1,tail1,head2,tail2,&res_head,&res_tail);
                res_sign = sign1;
            }
            else
            {
                status = subtraction(head2,tail2,head1,tail1,&res_head,&res_tail);
                res_sign = sign2;

            }
        }
        break;
        case '-':
        sign2 = -sign2;
        if(sign1 ==  sign2)
        {
            status = addition(tail1,tail2,&res_head,&res_tail);
            res_sign = sign1;
        }
        else
        {
            int cmp = compare_lists(head1,head2);
            if(cmp>0)
            {
                status = subtraction(head1,tail1,head2,tail2,&res_head,&res_tail);
                res_sign = sign1;
            }
            else
            {
                status = subtraction(head2,tail2,head1,tail1,&res_head,&res_tail);
                res_sign = sign2;
            }
        }
        break;
        case 'x':
        case '*':

        status = multiplication(head1,tail1,head2,tail2,&res_head,&res_tail);
        res_sign = sign1*sign2;
        break;
        case '/':
        status = division(head1,tail1,head2,tail2,&res_head,&res_tail,&rem_head,&rem_tail);
        res_sign =  sign1*sign2;
        if(status == SUCCESS)
        {
            printf("Quotient: ");
            dl_print_list(res_head, res_sign);
            printf("Remainder: ");
            dl_print_list(rem_head, 1);
            return 0;
        }

    }
   


    if(status == SUCCESS)
    {
        dl_print_list(res_head,res_sign);
    }
    else
    {
        print_error(status);
    }
}
