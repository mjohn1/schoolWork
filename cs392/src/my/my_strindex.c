#include "my.h"

int my_strindex(char *s, char c){
  int i;
  if(s != NULL){
    for(i = 0; s[i] != '\0'; i++){
      if(s[i] == c)
	return i;
    }
  }
}
