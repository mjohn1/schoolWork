/* Michael John
 * February 6, 2015
 * I pledge my honor that I have abided by The Stevens Honor System
 */

#include "my.h"

/* pre: Takes a char* dst and char* src
   post: Moves src to dst; returns dst
*/
char *my_strcpy(char *dst, char *src)
//copies everything including the \0
{
  int i;
  if(dst != NULL && src != NULL)
    {
      for(i = 0; *src != '\0'; i++)
	dst[i] = *(src++);
      dst[i] = '\0';
    }
  return dst;
}
