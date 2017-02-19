#include "my.h"

void my_alpha()
{
  char c;
  for(c = 'a'/* thses will always be the same as the ascii value */; c <= 'z'; c++)
    my_char(c);
}
