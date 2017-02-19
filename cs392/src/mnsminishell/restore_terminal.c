/* Michael John
   I pledge my Honor that I have abided by The Stevens Honor System
   April 15, 2015
*/

#include "myselect.h"

void restore_terminal()
{
  term_ve();
  term_standend();
  term_underend();
  ioctl(0, TCSETA, &(gl_env.line_backup));
  dup2(gl_env.stdio_backup, 1);
}
