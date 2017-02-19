/* Michael John
 * I pledge my honor that I have abided by The Stevens Honor System
 * March 25, 2015
 */

//#define _SERVER_H_

#include "minitalk.h"

struct s_env
{
  pid_t clipid;
  char done;
}    gl_env;

void sigint_handler(int sig)
{
  if(sig == SIGINT)
    {
      my_str("\nThis is the end for us!\nGoodbye my friend!\n");
      exit(0);
    }
}

void sigusr_handler(int sig)
{
  if(sig == SIGUSR1)
    {
      gl_env.clipid <<= 1;
      gl_env.clipid |= 1;
    }
  else
    gl_env.clipid <<= 1;
}

void getchar(int sig)
{
  if(sig == SIGUSR1)
    {
      gl_env.done <<= 1;
      gl_env.done |= 1;
    }
  else
    gl_env.done <<= 1;
}

int main()
{
  int i;
  my_int(getpid()); /* Prints the servers PID */
  signal(SIGINT, sigint_handler);
  signal(SIGUSR1, sigusr_handler);
  signal(SIGUSR2, sigusr_handler);
  
  while(1)
    {
      gl_env.clipid = 0;
      gl_env.done = 0;
      signal(SIGUSR1, sigusr_handler);
      signal(SIGUSR2, sigusr_handler);
      for(i = 0; i < 8*sizeof(pid_t); i++)
	pause();
      //my_char('\n'); my_char('1'); my_char('\n');
      signal(SIGUSR1, getchar);
      signal(SIGUSR2, getchar);
      usleep(5000);
      kill(gl_env.clipid, SIGUSR1);
      gl_env.done = 0;
      while(1)
	{
	  for(i = 0; i < 8*sizeof(char); i++)
	    pause();
	  if(gl_env.done == '\0')
	    {
	      my_char('\n');
	      break;
	    }
	  my_char(gl_env.done);
	  gl_env.done = 0;
	}
    }
}


