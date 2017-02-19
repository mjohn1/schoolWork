/* Michael John
   I pledge my Honor that I have abided by The Stevens Honor System
   April 15, 2015
*/

#include "myselect.h"

void show_select();

char check_char(char *c)
{
  if(!strcmp(c, " "))
    doselect();
  else if (!strcmp(c, KL))
    moveleft();
  else if (!strcmp(c, KR))
    moveright();
  else if (!strcmp(c, KU))
    moveup();
  else if (!strcmp(c, KD))
    movedown();
  else if (c[1] == '\0' && c[0] == '\033')
    getout(0);
    else if (c[1] == '\0' && c[0] == '\n')
    getout(1);
  else
    return 0;
}

