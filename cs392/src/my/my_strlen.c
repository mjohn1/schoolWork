#include "my.h"

int my_strlen(char*s)
{
  int ret = -1;
  if(s != NULL)
    for(ret = 0; s[ret] != '\0'; ret++)
      ;
  return ret;
}
