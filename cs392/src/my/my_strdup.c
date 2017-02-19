/* Michael John
 * February 6, 2015
 * I pledge my honor that I have abided by The Stevens Honor System
 * This function duplicates the string and returns it
 */

 #include "my.h"

/* pre: Takes a char *c
   post: Returns a duplicate of c
   Wallow.
*/
char *my_strdup(char *c)
{
  if(c == NULL)
    return NULL;
  char *ret = (char*)xmalloc(my_strlen(c)+1);
  ret = my_strcpy(ret, c);
  return ret;
}
