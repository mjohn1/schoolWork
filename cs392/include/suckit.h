/* Michael John
 * I pledge my Honor that I have abided by The Stevens Honor System
 * April 1, 2015
 */

#ifndef _SUCKIT_H_
#define _SUCKIT_H_

#include "my.h"
#include <signal.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netdb.h>
#include <gtk/gtk.h>

#ifndef _SERVER_H_ /* Server things only */
void front();
void handler(int sig);
void handler2(int sig);
#endif

#ifndef _CLIENT_H_ /* Client things only */

void sigint(int);
void sigint_2(int);

#endif

#endif
