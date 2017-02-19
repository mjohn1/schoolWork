/* Michael John
 * February 17, 2015
 * I pledge my honor that I have abided by The Stevens Honor System
 * This function prints the list of strings with their prev and next
 */

#include "my.h"
#include "mylist.h"

void print_string(t_node *n)
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
    my_str(((char*)(n->prev->elem)));
  my_str("<-");
  my_str(((char*)(n->elem)));
  my_str("->");
  if(n->next == NULL)
    my_char('N');
  else
    my_str(((char*)(n->next->elem)));
  my_char(')');
}
