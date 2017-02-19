/* Michael John
 * I pledge my Honor that I have abided by The Stevens Honor System
 * April 1, 2015
 */

#ifndef _SUCKIT_H_
#define _SUCKIT_H_

#define MAX 1024

#include "../../include/my.h"
#include <signal.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netdb.h>
#include <gtk/gtk.h>

typedef struct s_env
{
  int sockfd;
  unsigned short port;
  struct hostent *brick;
  char nickname[1024];
}              t_env;

#ifndef _SERVER_H_ /* Server things only */
void front();
void handler(int sig);
void handler2(int sig);
#endif

#ifndef _CLIENT_H_ /* Client things only */

void connect_to_server(GtkWidget*, gpointer);
void close_program(GtkWidget*, gpointer);
gint close_close(GtkWidget*, GdkEvent*, gpointer);
void toggle_button_callback(GtkWidget*, gpointer);
gint de(GtkWidget*, GdkEvent*, gpointer);
void sigint(int);
void sigint_2(int);

#endif

#endif
