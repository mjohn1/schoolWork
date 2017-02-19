/* Michael John
   I pledge my Honor that I have abided by The Stevens Honor System
   April 15, 2015
*/

#include "myselect.h"

char* term_get_cap(char *cap)
{
  char *str;
  char area[2048];
  if ((str = tgetstr(cap, (char**)&area)) == NULL)
    {
      restore_terminal();
      my_panic("AHHHH", 1);
    }
  return str;
}
