/* Michael John
 * February 17, 2015
 * I pledge my honor that I have abided by The Stevens Honor System
 * This function creates a new node
 */

#include "mylist.h"

t_node *new_node(void *e, t_node *n, t_node *p)
{
  t_node *n1 = (t_node*)xmalloc(sizeof(t_node*));
  n1->elem = e;
  n1->next = n;
  n1->prev = p;
  return n1;
}
