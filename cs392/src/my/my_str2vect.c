/* Michael John
 * I pledge my Honor that I have abided by The Stevens Honor System
 * March 8, 2015
 */

#include "my.h"

char **my_str2vect(char*s)
{
  int i = 0;
  int j = 0;
  int k = 0;
  char* str;
  //my_int(my_str_size(s));
  //my_char('\n');
  char** vec = (char**)xmalloc((my_str_size(s)+1)*sizeof(char*));
  //my_str("Before the NULL check\n");

  if(s == NULL)
    return NULL;
  //my_str(s);
  //my_char('\n');
  //my_str("after the NULL check\n");


  while(s[k] == ' ' || s[k] == '\t' || s[k] == '\n')
    {
      //my_str("In the while spaces loop\n");
      k++;
    }
  while(s[k] != '\0')
    {
      while(s[k] != ' ' && s[k] != '\t' && s[k] != '\n')
	{
	  j++;
	  k++;
	}
      str = (char*)xmalloc((++j)*sizeof(char));
      vec[i] = str;
      i++;
      if(s[k] == '\0'){
	//my_str("In the if statement\n");
	break;
      }
      j = 0;
      while(s[k] == ' ' || s[k] == '\t' || s[k] == '\n')
	{
	  k++;
	} 
    }
  i = 0;
  j = 0;
  k = 0;
  while(s[k] == ' ' || s[k] == '\t' || s[k] == '\n')
    {
      //my_str("In the while spaces loop\n");
      k++;
    }
  while(s[k] != '\0')
    {
      while(s[k] != ' ' && s[k] != '\t' && s[k] != '\n')
	{
	  //my_str("In the while letters loop\n");
	  //my_char(s[k]);
	  //my_str(vec[i]);
	  vec[i][j] = s[k];
	  //my_str("after we add the word\n");
	  j++;
	  k++;
	}
      if(s[k] == '\n' || s[k] == '\0'){
	//my_str("In the if statement\n");
	i++;
	break;
      }
      vec[i][j] = '\0';
      j = 0;
      i++;
      while(s[k] == ' ' || s[k] == '\t' || s[k] == '\n')
	{
	  k++;
	} 
    }
  vec[i] = NULL; 
  return vec;
}
