/* Michael John
   I pledge my Honor that I have abided by The Stevens Honor System
   April 15, 2015
*/

#include "myselect.h"

void getout(char c)
{
  int i;
  term_ve();
  restore_terminal();
  term_clear();
  if(c)
    {
      for(i = 0; i < gl_env.nbelems; i++)
	{
	  if(gl_env.elements[i].mode)
	    {
	      my_str(gl_env.elements[i].elem);
	      my_char(' ');
	      c = 10;
	    }
	}
      if(c == 10)
	my_char('\n');
    }
  exit(0);
}
