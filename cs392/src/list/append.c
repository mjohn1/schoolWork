/* Michael John
 * February 17, 2015
 * I pledge my honor that I have abided by The Stevens Honor System
 * This function adds a node to the end of the list
 */

#include "mylist.h"

void append(t_node *n, t_node **ph)
{
  t_node *n3 = (t_node*)xmalloc(sizeof(t_node*));
  if(ph != NULL && n != NULL && n->elem != NULL)
    {
      if(*ph != NULL)
	{
	  n3 = *ph;
	  while(n3->next != NULL)
	    n3 = n3->next;
	  n3->next = n;
	  n->next = NULL;
	  n->prev = n3;
	}
      else
	add_node(n, ph);
    }
}
