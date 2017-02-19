/* Michael John
 * February 17, 2015
 * I pledge my honor that I have abided by The Stevens Honor System
 * This function removes the last node
 */

#include "mylist.h"

void *remove_last(t_node **ph)
{
  t_node *n4;
  void *temp;
  if(ph != NULL && (*ph) != NULL)
    {
      if((*ph)->next == NULL)
	  return remove_node(ph);
      n4 = *ph;
      while(n4->next != NULL)
	  n4 = n4->next;
      temp = n4->elem;
      (n4->prev)->next = NULL;
      n4->prev = NULL;
      free(n4);
      return temp;
    }
}
