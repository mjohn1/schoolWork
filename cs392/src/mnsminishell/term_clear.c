/* Michael John
   I pledge my Honor that I have abided by The Stevens Honor System
   April 15, 2015
*/

#include "myselect.h"

void term_clear()
{
  tputs(gl_env.clear, 1, my_termprint);
}
