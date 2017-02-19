/* Michael John
 * I pledge my Honor that I have abided by The Stevens Honor System
 * February 29, 2015
 */

#include "my.h"
#define MAX 256

int main(int argc, char** argv)
{
  char buffer[MAX];
  int fds[2];
  int fds2[2];
  int pid, pid2;
  int n;
  char* str;
  if(argc <= 1)
    {
      my_str("ERROR: Incorrect Inputs\nUsage: ./pipes arg1 arg2 arg3 ...\n");
      return 0;
    }
  pipe(fds);
  if((pid = fork()) < 0) //parent 
    my_panic("The fork did not work", 1);
  if(pid > 0)
    {
      close(fds[0]);
      str = my_vect2str(argv);
      my_str("The Grandfather Speaks the Truth: ");
      my_str(str);
      my_char('\n');
      write(fds[1], str, my_strlen(str));
      wait();
      exit(0);
    }
  else //child
    {
      close(fds[1]);
      n = read(fds[0], buffer, MAX-1);
      buffer[n] = '\0';
      my_str("The Father Speaks the Truth: ");
      my_str(buffer);
      my_char('\n');
      str = buffer;
      pipe(fds2);
      if((pid2 = fork()) < 0)
	my_panic("The fork did not work", 1);
      if(pid2 > 0) //parent
	{
	  close(fds2[0]);
	  write(fds2[1], str, my_strlen(str));
	  wait();
	  exit(0);
	}
      else //child
	{
	  close(fds2[1]);
	  n = read(fds2[0], buffer, MAX-1);
	  buffer[n] = '\0';
          my_str("The Child Speaks the Truth: ");
	  my_str(buffer);
	  my_char('\n');
	  exit(0);
	}
      exit(0);
    }
  return 0;
}
