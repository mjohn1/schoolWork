/* Michael John
 * February 17, 2015
 * I pledge my honor that I have abided by The Stevens Honor System
 * This function adds a node at the specified index
 */

#include "mylist.h"

void add_node_at(t_node *n, t_node **ph, unsigned int i)
{
  t_node *n3;
  if(ph != NULL && n != NULL && n->elem != NULL)
    {
      if(*ph != NULL && i > 0)
	{
	  n3 = *ph;
	  while(n3->next != NULL && i > 1)
	    {
	      n3 = n3->next;
	      i--;
	    }
	  n->next = n3->next;
	  if(n->next != NULL)
	    (n3->next)->prev = n;
	  n3->next = n;
	  n->prev = n3;
	}
      else
	add_node(n, ph);
    }
}
