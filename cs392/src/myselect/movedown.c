/* Michael John
   I pledge my Honor that I have abided by The Stevens Honor System
   April 15, 2015
*/

#include "myselect.h"

void movedown()
{
  refreshout(gl_env.pos);
  if((gl_env.pos += 1) >= gl_env.nbelems)
    gl_env.pos = 0;
  refreshin();
}
