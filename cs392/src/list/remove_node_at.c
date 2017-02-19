/* Michael John
 * February 17, 2015
 * I pledge my honor that I have abided by The Stevens Honor System
 * This function removes a node at the index of n
 */

#include "mylist.h"

void *remove_node_at(t_node **ph, unsigned int n)
{
  t_node *n5;
  void *temp;
  while(ph != NULL && *ph != NULL)
    {
      if(n == 0 && *ph->next == NULL)
	return remove_node(ph);
      n5 = *ph;
      while(n5->next != NULL && n > 0)
	{
	  n5 = n5->next;
	  n--;
	}
      if(n5->next == NULL)
	return remove_last(ph);
      temp = n5->elem;
      (n5->prev)->next = n5->next;
      (n5->next)->prev = n5->prev;
      n5->prev = NULL;
      n5->next = NULL;
      free(n5);
      return temp; 
    }
}
