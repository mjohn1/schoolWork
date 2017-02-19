/* Author: Michael John
* Date: February 5, 2015
* I pledge my honor that I have abided by The Stevens Honor System
* This is the function that helps with malloc - this is what we are suppose to use.
*/

#include "my.h"

/* pre: Takes an int and checks if it succeeded using malloc
   post: Complains and exits if malloc was unsuccessful
   Exult.
*/

void *xmalloc(unsigned int n){
  /* Checks the return value of malloc
     still requires all the usual things that malloc requires */
  void *p = NULL;
  if(!(p = malloc(n)))
    {
      my_str("Virtual Memory Exhausted\n");
      exit(1);
    }
  return p;
}
