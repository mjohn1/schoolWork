/* Michael John
   I pledge my Honor that I have abided by The Stevens Honor System
   April 15, 2015
*/

#include "myselect.h"

void refreshin()
{
  term_move_to_item(gl_env.pos);
  term_underline();
  if(gl_env.elements[gl_env.pos].mode)
    term_standout();
  my_str(gl_env.elements[gl_env.pos].elem);
  term_standend();
  term_underend();
}
