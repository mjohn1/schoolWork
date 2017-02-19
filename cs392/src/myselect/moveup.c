/* Michael John
   I pledge my Honor that I have abided by The Stevens Honor System
   April 15, 2015
*/

#include "myselect.h"

void moveup()
{
  refreshout(gl_env.pos);
  if((gl_env.pos -= 1) < 0)
    gl_env.pos = (gl_env.nbelems - 1);
  refreshin();
}
