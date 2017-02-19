/* Michael John
   I pledge my Honor that I have abided by The Stevens Honor System
   April 15, 2015
*/

#include "myselect.h"

void moveright()
{
  my_termprint(1);
  refreshout(gl_env.pos);
  my_termprint(2);
  if((gl_env.pos += gl_env.win.ws_row) >= gl_env.nbelems)
    {
      gl_env.pos = (gl_env.nbelems - 1);
      my_termprint(3);
    }
    my_termprint(4);
    refreshin();
    my_termprint(5);
}
