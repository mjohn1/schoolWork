#include "my.h"

int main()
{
  char str[] = "Hello";
  int maxneg;

  /* testing my_char...maybe just once */
  my_char('A');
 
  /* testing my_str */
  my_str(str);  my_char('\n');
  my_str(NULL);  my_char('\n');
  my_str("");  my_char('\n');
  
  /* testing my_int */
  my_int(1); my_char('\n');
  my_int(1000); my_char('\n');
  my_int(-3); my_char('\n');
  my_int(0); my_char('\n');
  maxneg = 1 << (8*sizeof(int) - 1);
  my_int(maxneg); my_char('\n');
  
  /* testing my_num_base */
  my_num_base(5, "01"); /* 101 */  my_char('\n');
  my_num_base(9, "BLAH"); /* AL */ my_char('\n');
  my_num_base(-5, "--"); /* ---- */ my_char('\n');
  my_num_base(-10, "0123456789ABCDEF"); /* -A */ my_char('\n');
  my_num_base(-16, ""); /* "Base not valid" */ my_char('\n');
  my_num_base(22, NULL); /* "Base not valid" */ my_char('\n');
  
  /* testing my_alpha */
  my_alpha();  my_char('\n');
  /* testing my_digits */
  my_digits();  my_char('\n');

  /* testing str_len */
  my_int(my_strlen(str));/* 5 */my_char('\n');
  my_int(my_strlen("five"));/* 4 */    my_char('\n');
  my_int(my_strlen("seventeen"));/* 9 */my_char('\n');
  my_int(my_strlen(NULL));/* 0 */my_char('\n');
  my_int(my_strlen(""));/* 0 */my_char('\n');
 
  /* testing my_revstr */
  my_int(my_revstr(str));/* 5 */my_char('\n');
  my_int(my_revstr(NULL));/* 0 */my_char('\n');
  my_int(my_revstr(""));/* 0 */my_char('\n');
    
  /* testing my_strindex */
  my_int(my_strindex(str, 'H'));/* 0 */my_char('\n');
  my_int(my_strindex(str, 'v'));/* -1 */my_char('\n');
  my_int(my_strindex(str, 'l'));/* 2 */my_char('\n');
  my_int(my_strindex("AAA" , 'A'));/* 0 */my_char('\n');
  my_int(my_strindex("", 'z'));/* -1 */my_char('\n');
    
  my_int(my_revstr(str));my_char('\n');
  /* testing mystrrindex */
  my_int(my_strrindex(str, 'H'));/* 0 */my_char('\n');
  my_int(my_strrindex(str, 'l'));/* 3 */my_char('\n');
  my_int(my_strrindex(str, 'o'));/* 4 */my_char('\n');
  my_int(my_strrindex(str, 'v'));/* -1 */my_char('\n');
  my_int(my_strrindex("", 'r'));/* -1 */my_char('\n');
  my_int(my_strrindex("   ", ' '));/* 2 */my_char('\n');

  return 0;
}
