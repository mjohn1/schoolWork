/* Michael John
 * February 6, 2015
 * I pledge my honor that I have abided by The Stevens Honor System
 */

#include "my.h"

/* pre: Takes two char*, unsigned int
   post: Returns a new char* with all 
   the items of s1 and the first n 
   items of s2.
   Chill.
*/
char *my_strnconcat(char *s1, char *s2, unsigned int n)
//do a copy then at cat
{
  int l;
  char* ret;
  if(s1 == NULL && s2 == NULL)
    return NULL;
  if(n == 0 || s2 == NULL)
    return my_strdup(s1);
  l = my_strlen(s2);
  if(n > l)
    n = l;
  l = my_strlen(s1);
  if(l < 0)
    l = 0;
  ret = (char*)xmalloc(l+n+1);
  ret = my_strcpy(ret, s1);
  ret = my_strncpy(&ret[l], s2, n);
  ret[n+l] = '\0';
  return ret;
}
