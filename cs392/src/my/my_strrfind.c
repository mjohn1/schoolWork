/* Michael John
 * February 6, 2015
 * I pledge my honor that I have abided by The Stevens Honor System
 */

#include "my.h"

/* pre: Takes a char* and a char
   post: Returns the pointer to the 
   last occurence of the char in the char*
*/
char *my_strrfind(char *s, char c)
{
  int ret = 0;
  if(s != NULL)
    {
      ret = my_strrindex(s,c);
      if(ret < 0)
	return NULL;
      return &(s[ret]);
    }
  return NULL;
}
