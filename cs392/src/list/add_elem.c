/* Michael John
 * February 17, 2015
 * I pledge my honor that I have abided by The Stevens Honor System
 * This function adds an element to the list at the front
 */

#include "mylist.h"

void add_elem(void *e, t_node **ph)
{
  add_node(new_node(e, NULL, NULL), ph);
}
