/* Michael John
 * I pledge my honor that I have abided by The Stevens Honor System
 * February 29, 2015
 */

#include "my.h"

/* pre: takes a vector as a char**
 * post: returns the contents of the vector as one string
 * Rejoice
 */
char *my_vect2str(char** vec){
  int vec_index = 1;
  //int word_index = 0;
  int ret_index = 0;
  char* temp = vec[vec_index];
  char* str = (char*)xmalloc(my_vect_size(vec)*sizeof(char*));
  while(temp != NULL)
    {
      //my_str("Num1");
      for(;*temp != '\0';ret_index++)
	str[ret_index] = *(temp++);
      //my_str("Num2");
      str[ret_index] = ' ';
      ret_index++;
      vec_index++;
      temp = vec[vec_index];
    }
  str[ret_index] = '\0';
  return str;
}
