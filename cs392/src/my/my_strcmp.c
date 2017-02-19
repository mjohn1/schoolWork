/* Michael John
 * February 6, 2015
 * I pledge my honor that I have abided by The Stevens Honor System
 */

#include "my.h"

/* pre: Takes two char*
   post: Returns number indicating if s1 > s2
*/
int my_strcmp(char *s1, char *s2)
{
  if(s1 == NULL && s2 == NULL)
    return 0;
  if(s1 == NULL)
    return -1;
  if(s2 == NULL)
    return 1;
  for(; *s1 == *s2; s1++, s2++)
    if(*s1 == '\0')
      return 0;
  return *s1 - *s2;
}
