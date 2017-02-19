/* Michael John
   I pledge my Honor that I have abided by The Stevens Honor System
   April 15, 2015
*/

#include "myselect.h"

int my_termprint(int c)
{
  return write(1, &c, 1);
}
