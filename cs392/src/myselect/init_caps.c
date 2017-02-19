/* Michael John
   I pledge my Honor that I have abided by The Stevens Honor System
   April 15, 2015
*/

#include "myselect.h"

void init_caps()
{
  char bp[2048];
  char *term;
  
  term = getenv("TERM");
  tgetent(bp, term);
  //my_str("underline\n");
  gl_env.underline = term_get_cap(UNDERLINE);
  //my_str("under_end\n");
  gl_env.under_end = term_get_cap(UNDER_END);
  //my_str("standout\n");
  gl_env.standout = term_get_cap(STANDOUT);
  //my_str("stand_end\n");
  gl_env.stand_end = term_get_cap(STAND_END);
  //my_str("Move\n");
  gl_env.move = term_get_cap(MOVE);
  //my_str("Clear\n");
  gl_env.clear = term_get_cap(CLEAR);
  //my_str("cursoroff\n");
  gl_env.cursoroff = term_get_cap(CURSOROFF);
  //my_str("cursoron\n");
  gl_env.cursoron = term_get_cap(CURSORON);
}
