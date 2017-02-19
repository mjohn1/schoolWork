/* Michael John
 * February 17, 2015
 * I pledge my honor that I have abided by The Stevens Honor System
 * This function prints the list of ints
 */

#include "my.h"
#include "mylist.h"

void traverse_int(t_node *n)
{
  if(n == NULL)
    {
      my_str("The list is empty");
      return;
    }
  while(n != NULL)
    {
      my_int(*((int*)(n->elem)));
      my_char(' ');
      n = n->next;
    }
}
