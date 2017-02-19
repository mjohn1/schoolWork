/* Michael John
 * I pledge my honor that I have abided by The Stevens Honor System
 * April 4, 2015
 */

#include "suckit.h"
#define MAX 1024

char nickname[MAX];

void front()
{
  my_str("***");
  my_str(nickname);
}

void handler(int sig)
{
  if(sig == SIGINT)
    {
      usleep(1900);
      my_str("Peace out homie!\n");
      exit(0);
    }
}

void handler2(int sig)
{
  if(sig == SIGINT)
    {
      usleep((getpid()%100)*10);
      my_char('\n');
      front();
      my_str(" has disconnected from the ultimate server.\n");
      exit(0);
    }
}

int main(int argc, char* argv[])
{
  int iii;
  int pid;
  int portnum;
  int n;
  int sockfd;
  int clisockfd;
  int clilen;
  char buffer[MAX];
  char* temp;
  char** vec;
  struct sockaddr_in srv;
  struct sockaddr_in cli;
  if(argc!=2)
    {
      my_panic("Usage: ./server PORT\n", 1);
      return 0;
    }
  portnum = my_atoi(argv[1]);
  if(portnum > 0 && portnum < (1<<16)-1)
    {
      my_str("Welcome to my server!\n");
      signal(SIGINT, handler);
      sockfd = socket(AF_INET, SOCK_STREAM, 0);
      memset(&srv, 0, sizeof(srv));
      srv.sin_addr.s_addr = INADDR_ANY;
      srv.sin_family = AF_INET;
      srv.sin_port = htons(portnum);
      if((bind(sockfd, (struct sockaddr*)&srv, sizeof(srv))) < 0)
	{
	  my_panic("Can not bind!\n", 1);
	  return 0;
	}
	listen(sockfd, 5);
      clilen = sizeof(cli);
      while(1)
	{
	  if((clisockfd = accept(sockfd,(struct sockaddr*)&cli,&clilen))< 0)
	    { 
	      my_panic("the socket doesn't exist", 1);
	      return 0;
	    }
	  if((pid=fork())<0)
	    {
	      my_panic("Bad fork!\n",1);
	      return 0;
	    }
	  if(pid > 0)  
	    {
	      close(clisockfd);
	    }
	  else// the child
	    {
	      close(sockfd);
	      n = read(clisockfd, nickname, MAX-1);
	      nickname[n-1]='\0';
	      front(nickname);
	      my_str(" is connected\n");
	      write(clisockfd, "?", 1);
	      while(1)
		{
		  signal(SIGINT, handler2);
		  n = read(clisockfd, buffer, MAX-1);
		  //my_str("Reading from client\n");
		  buffer[n-1] = '\0';
		  //my_str(buffer);
		  //my_char('\n');
		  write(clisockfd, "?", MAX-1);
		  //my_str("wrote to client\n");
      		  vec = my_str2vect(buffer);
		  //handler(vec, buffer);
       		  //if(my_strncmp(buffer, "/exit ", 6) == 0)
		  if(my_strcmp(vec[0], "/exit") == 0 || (buffer[0] == '/' && buffer[1] == 'e' && buffer[2] == 'x' && buffer[3] == 'i' && buffer[4] == 't' && (buffer[5] == ' ' || buffer[5] == '\t' || buffer[5] == '\n' || buffer[5] == '\0')))
		    {
		      //my_str("exiting\n");
		      front(nickname);
		      my_str(" has exited!\n");
		      exit(0);
		    }
		  //else if(my_strncmp(buffer, "/nick ", 6) == 0)
		  else if(my_strcmp(vec[0], "/nick") == 0)
		    {
		      //my_str("changing nickname\n");		      
		      //nickname = vec[1];
		      front(nickname);
		      temp = &buffer[4];
		      for(iii = 0; iii <= n; iii++)
			nickname[iii] = buffer[iii+6];
		      nickname[iii] = '\0';
		      //my_str("length of name: ");my_int(my_strlen(temp));
		      //my_char('\n');
		      //my_str("new nickname: ");my_str(temp);
		      my_str(" has changed to ");
		      my_str(nickname);
		      my_char('\n');
		    }
		  //else if(my_strncmp(buffer, "/me ", 6) == 0)
		  else if(my_strcmp(vec[0],"/me") == 0)
		    {
		      //my_str("/me statement\n");
		      front(nickname);
		      my_char(' ');
		      my_str(&buffer[4]);
		      my_char('\n');
		    }
		  //if(buffer[0] == '/')
		  //my_str("Command not found\n");
		  else
		    {
		      //my_str("entered the else\n");
		      my_str(nickname);
		      my_str(": ");
		      my_str(buffer);
		      my_char('\n');
		    }
		}
	    }
	}
    }
  else
    {
      my_panic("Incompatibale Port Number\n", 1);
      return 0;
    }
}
  
