/* Michael John
 * February 6, 2015
 * I pledge my honor that I have abided by The Stevens Honor System
 */

#include "my.h"

/* pre: Takes two char*
   post: Returns a new string containing s1 concatenated with s2
   Embrace.
*/
char *my_strconcat(char *s1, char *s2)
{
  int length;
  int l;
  char* ret;
  if(s1 == NULL && s2 == NULL)
    return NULL;
  if(s1 == NULL)
    return my_strdup(s2);
  if(s2 == NULL)
    return my_strdup(s1);
  length = my_strlen(s2);
  l = my_strlen(s1);
  ret = (char*)xmalloc(length+l);
  ret = my_strcpy(ret, s1);
  return my_strcpy(&ret[l], s2);
}
