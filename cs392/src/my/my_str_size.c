/* Michael John
 * I pledge my honor that I have abided by The Stevens Honor System
 * March 8, 2015
 */

#include "my.h"

int my_str_size(char *s)
/* finds the number of words in a string */
{
  int i = 0;
  int size = 0;
  while(s != NULL && s[i] != '\0')
    {
      while(s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
	  i++;
	}
      if(s[i] == '\0')
	break;
      size++;
      while(s[i] != '\0' && s[i] != '\n' && s[i] != ' ' && s[i] != '\t')
	{
	  i++;
	}
    }
  return size;
}
