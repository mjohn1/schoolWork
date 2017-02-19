/* Michael John
   I pledge my Honor that I have abided by The Stevens Honor System
   April 15, 2015
*/

#include "myselect.h"

void term_move(int x, int y)
{
  tputs(tgoto(gl_env.move, x, y), 1, my_termprint);
}
