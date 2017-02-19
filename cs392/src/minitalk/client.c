/* Michael John
 * I pledge my honor that I have abided by The Stevens Honor System
 * March 25, 2015 
 */

//#define _CLIENT_H_

#include "minitalk.h"

char gl_ack;

int main(int argc, char* argv[])
{
  int pid = 0;
  int i,j;
  int my_pid = getpid();
  char* message;
  char char_mask = 1;
  int int_mask = 1;
  int_mask <<= 31;
  char_mask <<= 7;
  signal(SIGUSR1, sigusr_handler_c);
  signal(SIGUSR2, sigusr_handler_c);
  signal(SIGALRM, sigalrm_handler);
  if(argc > 2)
    {
      if((pid = my_atoi(argv[1])) > 0)
	{
	  gl_ack = 0;
	  //my_int(pid); my_char('\n');
	  message = my_vect2str(&argv[1]);
	  //my_str(message); my_char('\n');
	  for(i = 0; i < 8*sizeof(pid_t); i++)
	    {
	      if(my_pid & int_mask)
		kill(pid, SIGUSR1);
	      else
		kill(pid, SIGUSR2);
	      my_pid <<= 1;
	      usleep(2000);
	    }
	  if(!gl_ack)
	    {
	      alarm(2);
	      pause();
	    }
	  alarm(0);
	  for(j = 0; message[j] != '\0'; j++)
	    {
	      for(i = 0; i < 8*sizeof(char); i++)
		{
		  if(message[j] & char_mask)
		    kill(pid, SIGUSR1);
		  else
		    kill(pid, SIGUSR2);
		  message[j] <<= 1;
		  usleep(2000);
		}
	    }
	  for(i = 0; i < 8*sizeof(char); i++) //sends the message
	    {
	      if(message[j] & char_mask)
		kill(pid, SIGUSR1);
	      else
		kill(pid, SIGUSR2);
	      char_mask <<= 1;
	      usleep(5000);
	    }
	  exit(0);
	}
      my_str("Error, Invalid Process ID");
      exit(1);
    }
  my_str("Too few arguments!\n");
  exit(1);
}

void sigusr_handler_c(int sig)
{
  if(sig != SIGUSR1)
    {
      my_str("This process has unexpectedly quit");
      exit(1);
    }
  gl_ack = 1;
  }

void sigalrm_handler(int sig)
{
  if(sig == SIGALRM)
    {
      my_str("Invalid PID\n");
      exit(1);
    }
}
