/* Michael John
   I pledge my honor that I have abided by The Stevens Honor System
   April 15, 2015
*/

#include "myselect.h"

void init_terminal()
{
  char *name;
  int fd;
  struct termio line;
  ioctl(0, TCGETA, &line);
  gl_env.line_backup = line;
  line.c_lflag &= ~(ICANON|ISIG|ECHO);
  line.c_cc[VMIN] = READMIN;
  line.c_cc[VTIME] = READTIME;
  ioctl(0, TCSETA, &line);
  name = ttyname(0);
  fd = open(name, O_WRONLY);
  gl_env.stdio_backup = dup(1);
  dup2(fd, 1);
}
