/* Michael John
   I pledge my Honor that I have abided by The Stevens Honor System
   April 15, 2015
*/

#include "myselect.h"

void refreshout(int i)
/* refresh the item at the position i w/o an underline */
{
  term_move_to_item(i);
  if(gl_env.elements[i].mode)
    term_standout();
  my_str(gl_env.elements[i].elem);
  term_standend();
}
