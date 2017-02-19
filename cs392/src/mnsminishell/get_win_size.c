/* Michael John
   I pledge my Honor that I have abided by The Stevens Honor System
   April 15, 2015
*/

#include "myselect.h"

void get_win_size()
{
  ioctl(0, TIOCGWINSZ, &gl_env.win);
}
