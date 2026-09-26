#ifndef CAL_H
#define CAL_H
#include "dll.h"
#include "utilis.h"
int addition(Dlist *tail1, Dlist *tail2, Dlist **res_head,Dlist **res_tail);
int subtraction(Dlist *head1, Dlist* tail1, Dlist *head2, Dlist *tail2, Dlist **res_head,Dlist **res_tail);
int multiplication(Dlist *head1, Dlist* tail1, Dlist *head2, Dlist *tail2, Dlist **res_head,Dlist **res_tail);
int division(Dlist *head1, Dlist* tail1, Dlist *head2, Dlist *tail2, Dlist **res_head,Dlist **res_tail, Dlist **rem_head, Dlist **rem_tail);
#endif