/* Michael John
 * February 6, 2015
 * I pledge my honor that I have abided by The Stevens Honor System
 */

#include "my.h"

/* pre: Takes two char* and unsigned int
   post: Moves first n items from src to dst; returns dst
*/
char *my_strncpy(char *dst, char *src, unsigned int n)
{
  int i = 0;
  if(src != NULL && dst != NULL)
    while(n > 0 && (dst[i] = src[i++]) != '\0')
      n--;
  return dst;
}
