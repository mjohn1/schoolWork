/* Michael John
 * February 17, 2015
 * I pledge my honor that I have abided by The Stevens Honor System
 * This function empties the whole list
 */

#include "mylist.h"

void empty_list(t_node **ph)
{
  while(ph != NULL && *ph != NULL)
    {
      remove_node(ph);
      ph = ph->next;
    }
}
