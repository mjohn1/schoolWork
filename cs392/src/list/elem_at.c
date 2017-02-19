/* Michael John
 * February 17, 2015
 * I pledge my honor that I have abided by The Stevens Honor System
 * This function returns the element at index i
 */

#include "mylist.h"

void *elem_at(t_node *n, unsigned int i)
{
  if(n != NULL)
    {
      while(n->next != NULL && i > 0)
	{
	  n = n->next;
	  i--;
	}
      return n->elem;
    }
  return NULL;
}
