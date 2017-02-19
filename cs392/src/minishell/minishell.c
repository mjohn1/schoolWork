/* Michael John
 * I pledge my honor that I have abided by The Stevens Honor System
 * March 8, 2015
 */

#include "my.h"
#define MAX 256

int main()
{

  int pid;
  int n;
  int exp;
  char buffer[MAX];
  char** commands;

  while(1)
    {
      my_str("Please enter a Command: ");
      n = read(0, buffer, MAX-1);
      buffer[n-1] = '\0';
      commands = my_str2vect(buffer);
      //my_str(commands[0]);
      if(my_strcmp("cd", commands[0]) == 0){
	if(commands[1] == NULL)
	  my_str("Please give a location\n");
	else if((chdir(commands[1])) != 0)
	  my_str("Location Invalid");
      }
      else if(my_strcmp("exit", commands[0]) == 0){
	for(n = 0; commands[n] != NULL; n++)
	  free(commands[n]);
	free(commands);
	break;
      }
      else
	{
	  if((pid = fork()) < 0)
	    my_panic("Forking Failure my Friend\n", 1);
	  if(pid > 0)
	    wait();
	  else
	    {
	      if((execvp(commands[0], commands)) < 0)
		{
		  my_str(commands[0]);
		  my_panic(" is not defined.\n", 1);
		}
	      exit(0);
	    }
	  // parent waits
	  // child execvp or panics
	}
    }
  my_str("Thank you for using the minishell\n");
  my_str("Goodbye\n");
  return 0;
}
