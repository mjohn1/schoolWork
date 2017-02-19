/* Michael John
 * February 6, 2015
 * I pledge my honor that I have abided by The Stevens Honor System
 */

#include "my.h"

/* pre: Takes two char*
   post: Concatenates s2 to the end of s1; Returns s1
   Revel.
*/
char *my_strcat(char *s1, char *s2)
//if s1 is NULL
{
  int i;
  if(s1 != NULL)
    {
      if(s2 == NULL)
	return s1;
      for(i = 0; s1[i] != '\0'; i++)
	;
      for(;*s2 != '\0'; i++)
	s1[i] = *(s2++);
      s1[i] = '\0';
    }
  return s1;
}
