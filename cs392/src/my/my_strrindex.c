#include "my.h"

int my_strrindex(char *s, char c){
  int i;
  int ret = -1;
  if(s != NULL){
    for(i = 0; s[i] != '\0'; i++)
      if(s[i] == c)
	ret = i;
    return ret;
  }
}
