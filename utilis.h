#ifndef UTILIS_H
#define UTILIS_H
#include "dll.h"

void print_error(int status);
int validate_syntax(int argc, char *argv[]);
int parse_input(char *str,Dlist **head,Dlist **tail,int *sign);
void remove_leading_zeros(Dlist **head,Dlist **tail);
int compare_lists(Dlist *head1,Dlist*head2);
#endif