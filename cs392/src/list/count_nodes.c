/* Michael John
 * February 17, 2015
 * I pledge my honor that I have abided by The Stevens Honor System
 * This function counts the nodes in the list
 */

#include "my.h"
#include "mylist.h"

unsigned int count_nodes(t_node *n)
{
  unsigned int count = 0;
  if(n != NULL){
    for(count = 1; n->next != NULL; count++)
      n = n->next;
  }
  return count;
}
