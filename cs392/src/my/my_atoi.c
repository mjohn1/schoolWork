/* Michael John
 * I pledge my honor that I have abided by The Stevens Honor System
 * March 19, 2015
 */

#include "my.h"


int my_atoi(char *s)
{
  int ret = 0;
  //int i = 0;
  int neg_count = 0;
  //if(s != NULL && s[i] != '\0')
  while(s[0] == ' ' || s[0] == '\t' || s[0] == '\n')
    {
      s++;
    }
  while(s[0] == '+' || s[0] == '-')
    {
      if(s[0] == '-')
	neg_count++;
      s++;
    }
  while(s[0] >= '0' && s[0] <= '9')
    { 
      //my_char(s[0]); my_char('\n');
      ret = ret*10;
      ret = ret+(s[0]-'0');
      s++;
    }
  if(neg_count%2 > 0)
    ret *= -1;
  return ret;
}
