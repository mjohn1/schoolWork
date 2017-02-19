#include "my.h"

void my_num_base(int n, char *b)
{
  int r;
  unsigned int u,e;
  if((r = my_strlen(b)) > 0){
    u = n;
    if(n < 0)
      {
	my_char('-');
	u = -n;
      }
    if(r == 1)
      while(u-- > 0)
	my_char(*b);
    else
      {
	for(e = 1;  (u/e) >= r; e *= r)
	  ;
	for(;e; u %= e, e /= r)
	  my_char(b[u/e]);
      }
  }
  else
    my_str("Base not Valid!\n");
}
