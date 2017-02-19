/* Michael John
 * February 17, 2015
 * I pledge my honor that I have abided by The Stevens Honor System
 * This function removes the first node
 */

#include "mylist.h"

void *remove_node(t_node **ph)
{
  void *temp;
  //tnode* deleteme;
  if(ph != NULL && *ph != NULL)
    {
      temp = (*ph)->elem;
      if((*ph)->next != NULL)
	{
	  *ph = (*ph)->next;
	  ((*ph)->prev)->next = NULL;
	  free((*ph)->prev);
	  (*ph)->prev = NULL;
	  return temp;
	}
      else{
	(*ph)->prev = NULL;
	free(*ph);
	return temp;
      }
    }
}
