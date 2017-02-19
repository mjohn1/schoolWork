/* Michael John
 * February 17, 2015
 * I pledge my honor that I have abided by The Stevens Honor System
 * This function prints the list of strings
 */

#include "my.h"
#include "mylist.h"

void traverse_string(t_node *n)
{
  if(n == NULL)
    {
      my_str("The list is empty\n");
      return;
    }
  while(n != NULL)
    {
      my_str(((char*)(n->elem)));
      my_char(' ');
      n = n->next;
    }
}
