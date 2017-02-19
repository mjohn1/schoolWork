/* Michael John
   I pledge my Honor that I have abided by The Stevens Honor System
   April 15, 2015
*/

#include "myselect.h"

void doselect()
{
  if(gl_env.elements[gl_env.pos].mode == 0)
    {
      gl_env.elements[gl_env.pos].mode = 1;
      movedown();
    }
  else
    gl_env.elements[gl_env.pos].mode = 0;
  refreshin();
}
