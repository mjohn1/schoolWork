/* Michael John
 * February 17, 2015
 * I pledge my honor that I have abided by The Stevens Honor System
 * This function prints the list of integers with their prev and next
 */

#include "my.h"
#include "mylist.h"

void print_int(t_node *n)
{
  if(n == NULL)
    {
      my_str("The list is empty");
      return;
    }
  my_char('(');
  if(n->prev == NULL)
    my_char('N');
  else
    my_int(*((int*)(n->prev->elem)));
  my_str("<-");
  my_int(*((int*)(n->elem)));
  my_str("->");
  if(n->next == NULL)
    my_char('N');
  else
    my_int(*((char*)(n->next->elem)));
  my_char(')');
  my_char(' ');
}
