/* Michael John
 * I pledge my Honor that I have abided by The Stevens Honor System
 * April 1, 2015
 */

#include "suckit.h"
#define MAX 1024

int gl_sockfd;

void sigint(int sig)
{
  if(sig == SIGINT)
    {
      write(gl_sockfd, "/exit ", 6);
      my_panic("Goodbye\n", 0);
    }
}

void sigint_2(int sig)
{
  if(sig == SIGINT)
    {
      my_str("Goodbye\n");
      exit(0);
    }
}

int main (int argc, char* argv[])
{
  int n;
  unsigned short port;
  struct sockaddr_in srv;
  struct hostent *brick;
  char nickname[MAX];
  signal(SIGINT, sigint_2);//ends the client be-4 we connect to srv  
  if(argc == 3)
    {
      port = my_atoi(argv[2]);
      if(port > 0 && port < (1<<16)-1)
	{
	  gl_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	  if((brick = gethostbyname(argv[1])) == NULL)
	    {
	      my_panic("This host doesn't exist\n", 1);
	      return 0;
	    }
	  memset(&srv, 0, sizeof(srv));
	  srv.sin_family = AF_INET;
	  srv.sin_port = htons(port);
	  memcpy(&srv.sin_addr.s_addr, brick->h_addr, brick->h_length);
	  if((connect(gl_sockfd, (struct sockaddr*)&srv, sizeof(srv))) < 0)
	    {
	      my_panic("Couldn't connect to the sever\n", 1);
	      return 0;
	    }
	  my_str("Please provide a nickname for the server: ");
	  n = read(0, nickname, MAX-1);
	  nickname[n-1] = '\0';
	  write(gl_sockfd, nickname, MAX-1); //sends the nickname
     	  signal(SIGINT, sigint);
	  usleep(2000);
	  n = read(gl_sockfd, nickname, MAX-1); // the sever's response
	  nickname[n] = '\0';
	  if(nickname[0] == '?')
	    {
	      while(1)
		{
		  my_char('~');
		  n = read(0, nickname, MAX-1);
		  nickname[n-1] = '\0';
		  if(my_strncmp(nickname, "/exit", 5) == 0 && (nickname[5]==' ' || nickname[5]=='\t' || nickname[5]=='\0' || nickname[5]=='\n'))
		    break;
		  write(gl_sockfd, nickname, MAX-1);
		  //my_str("Wrote to server\n");
		  usleep(2000);
		  n = read(gl_sockfd, nickname, MAX-1);
		  //my_str(nickname);
		  //my_char('\n');
		  if(nickname[0] != '?')
		    {
		      my_panic("You have been disconnected or the Server is down\n", 0);
		      return 0;
		    }
		}
	      write(gl_sockfd, "/exit", 6);
	      //usleep(2000);
	      my_panic("Goodbye\n", 0);
	      return 0;
	    }
	  else
	    {
	      my_panic("The Server is Down!\n", 1);
	      return 0;
	    }
	}
      else
	{
	  my_panic("Please provide a valid port number\n", 1);
	  return 0;
	}
    }
  else
    {
      my_panic("Usage: ./client server-machine-name PORT\n", 1);
      return 0;
    }
}
