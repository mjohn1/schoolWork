/* Michael John
 * February 17, 2015
 * I pledge my honor that I have abided by The Stevens Honor System
 * This function prints the list of strings with their prev and next
 */

#include "my.h"
#include "mylist.h"

void debug_string(t_node *n)
{
  if(n == NULL)
    {
      my_str("The list is empty");
      return;
    }
  while(n != NULL)
    {
      print_string(n);
      my_char(' ');
      n = n->next;
    }
}
