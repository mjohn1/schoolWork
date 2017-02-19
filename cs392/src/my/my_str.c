#include "my.h"

void my_str(char *s){
  if(s != NULL){
    while(*s != '\0')// could have done while(*s) but this shows you are looking for chars
      my_char(*(s++));// this increments the pointer
  }
}
