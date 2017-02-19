/* Michael John
 * I pledge my Honor that I have abided by The Stevens Honor System
 * March 19, 2015
 */

#ifndef _MINITALK_H_
#define _MINITALK_H_

#include "my.h"
#include <signal.h>

#ifndef _SERVER_H_ /* Server things only */
void sigint_handler(int sig);
void sigusr_handler(int sig);
void getchar(int sig);
#endif

#ifndef _CLIENT_H_ /* Client things only */
void sigusr_handler_c(int sig);
void sigalrm_handler(int sig);
#endif

#endif
