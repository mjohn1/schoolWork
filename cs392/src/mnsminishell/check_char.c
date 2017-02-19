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
  else if (c[1] == '\0')
  {
    if(c[0] == '\033')
      getout(0);
    else if (c[0] == '\n')
      getout(1);
    else if(c[0] == '^A')
      //move to the beginning of buffer
    else if(c[0] == '^E')
      //move to the end of buffer

  else
    return 0;
}

