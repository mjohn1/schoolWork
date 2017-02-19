/* Michael John
 * February 17, 2015
 * I pledge my honor that I have abided by The Stevens Honor System
 * This function adds a node to the head of the list
 */

#include "my.h"
#include "mylist.h"

void add_node(t_node *n, t_node **ph)
{
   if(n != NULL && ph != NULL && *ph != NULL && n->elem != NULL)
     {
       if((*ph)->next != NULL)
	 (*ph)->prev = n;
       n->prev = NULL;
       n->next = *ph;
       *ph = n;
     } 
}
