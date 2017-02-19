/* Michael John
   I pledge my Honor that I have abided by The Stevens Honor System
   April 15, 2015
*/

#include "myselect.h"

void term_vi()
{
  tputs(gl_env.cursoroff, 1, my_termprint);
}
