/* Michael John
   I pledge my Honor that I have abided by The Stevens Honor System
   April 15, 2015
*/

#include "myselect.h"

void show_elems()
{
  int x;
  int y; 
  int i; 
  int max;
  get_win_size();
  term_clear();
  gl_env.flag = 0;
  for(i = 0, x = 0, y = 0, max = 0; i < gl_env.nbelems; i++, y++)
    {
      if(y >= gl_env.win.ws_row)
	{
	  y = 0;
	  x += (max + 3);
	  max = 0;
	}
      if(max < gl_env.elements[i].size)
	{
	  max = gl_env.elements[i].size;
	    if(x+max > gl_env.win.ws_col)
	      {
		term_clear();
		my_str("Enlarge This Window Yo!");
		gl_env.flag = 1;
		break;
	      }
	}
      gl_env.elements[i].x = x;
      gl_env.elements[i].y = y;
      refreshout(i);
    }
  if(!gl_env.flag)
    refreshin();
}
