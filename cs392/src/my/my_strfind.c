/* Michael John
 * February 6, 2015
 * I pledge my honor that I have abided by The Stevens Honor System
 */

#include "my.h"

/* pre: Takes a char* and a char
   post: Returns the pointer to the
   first occurence of the char in the char*
*/
char *my_strfind(char *s, char c)
{

  if(s != NULL)
    while(*s != '\0' && *s != c)
      *(s++);
  if(s == NULL || *s == '\0')
    return NULL;
  return s;
  
  /*  if(s != NULL)
    {
      return &s[my_strindex(s, c)];
    }
  return NULL;
  */
}
