/* Michael John
   I pledge my Honor that I have abided by The Stevens Honor System
   April 15, 2015
*/

#include "myselect.h"

void setup_elems(int i, char** vec)
{
  int count;
  gl_env.elements = xmalloc(i*sizeof(t_elem));
  gl_env.nbelems = i;
  gl_env.pos = 0;
  for(count = 0; count < i; count++)
    {
      gl_env.elements[count].elem = vec[count];
      gl_env.elements[count].size = my_strlen(vec[count]);
      gl_env.elements[count].x = 0;
      gl_env.elements[count].y = 0;
      gl_env.elements[count].mode = 0;
    }
}
