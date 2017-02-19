/* Michael John
   I pledge my Honor that I have abided by The Stevens Honor System
   April 15, 2015
*/

#include "myselect.h"
#define MAX 1024

int main(int argc, char **argv)
{
  int i;
  int n;
  char buffer[MAX];
  char end = 0;
  if(argc > 1)
    {
      signal(SIGWINCH, show_elems);
      init_terminal();
      init_caps();
      term_vi();
      setup_elems(argc-1, &argv[1]);
      term_clear();
      show_elems();
      while(1)
	     {
	       if((n = read(0, buffer, MAX)) > 0)
	         {
	           buffer[n] = '\0';
	           check_char(buffer);
	         }
	       else
	       getout(0);
	}
    }
  else
    my_panic("Usage: ./my_select arg1 [arg2] . . .", 1);  
}
