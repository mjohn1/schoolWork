#include "my.h"

int my_revstr(char *s)
{
  int length, i;
  if((length = my_strlen(s)) > 1)
    {
      for(i = 0; i < (length/2); i++)
	{
	  s[i] ^= s[length-i-1];
	  s[length-i-1] ^= s[i];
	  s[i] ^= s[length-i-1];
	    }
    }
  return length;
}
