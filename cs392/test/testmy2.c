/* Michael John
 * testmy2
 * February 4, 2015
 * I pledge my honor that I have abided by The Stevens Honor System
 * This is a test for the second addition to my.h
 */

 #include "my.h"

int main(){
#if 0
  /* testing my_strdup */
  my_str("testing my_strdup\n");
  my_str(my_strdup(NULL)); my_char('\n'); /* NULL */
  my_str(my_strdup("")); my_char('\n');/* "" */
  my_str(my_strdup("Hello")); my_char('\n');/* HelloHello */
  my_str(my_strdup("543")); my_char('\n');/* 543543 */

  /* testing my_strcpy */
  my_str("testing my_strcpy");
  my_str(my_strcpy("Hello", "111")); my_char('\n');/* 111 */
  my_str(my_strcpy("Hello", "11111")); my_char('\n');/* 11111 */
  my_str(my_strcpy(NULL, "Hello")); my_char('\n'); /* NULL */
  my_str(my_strcpy("Hello", NULL)); my_char('\n'); /* Hello */
  my_str(my_strcpy("HelloHello", "1234")); my_char('\n'); /* 1234oHello */
  my_str(my_strcpy("ABCDE", "12")); my_char('\n'); /* 12CDE */
#endif
  /* testing my_strncpy */
  my_str("testing my_strncpy");
  my_str(my_strncpy("Hello", "11111", 5)); my_char('\n');/* 11111 */
  my_str(my_strncpy(NULL, "Hello", 3)); my_char('\n'); /* NULL */
  my_str(my_strncpy("Hello", NULL, 4)); my_char('\n'); /* Hello */
  my_str(my_strncpy("HelloHello", "1234", 9)); my_char('\n'); /* 1234 */
#if 0
  /* testing my_strcmp */
  my_str("testing my_strcmp\n"); 
  my_str("this should be negative");
  my_char('\n');
  my_int(my_strcmp(NULL, "Hi"));//1
  my_char('\n');
  my_str("this should be negative");
  my_char('\n');
  my_int(my_strcmp("", "Hi"));//2
  my_char('\n');
  my_str("this should be positive\n");
  my_int(my_strcmp("Hi", NULL));//3
  my_char('\n');
  my_str("This should be positive\n");
  my_int(my_strcmp("Hi", ""));//4
  my_char('\n');
  my_str("This should be negative\n");
  my_int(my_strcmp(NULL, ""));//5
  my_char('\n');
  my_str("this shoule be positive\n");
  my_int(my_strcmp("ABCDE", "ABC"));//6
  my_char('\n');
  my_str("This should be 0\n");
  my_int(my_strcmp("Hello", "Hello"));//7
  my_char('\n');
  my_str("this should be 0\n");
  my_int(my_strcmp(NULL, NULL));//8
  my_char('\n');
  my_str("This should be 0\n");
  my_int(my_strcmp("", ""));//9
  my_char('\n');
 
  /* testing my_strncmp */
  my_str("testing my_strncmp");
  my_char('\n');
  my_str("This should be positive");
  my_char('\n');
  my_int(my_strncmp("Hi", "", 0));
  my_char('\n');
  my_str("This should be positive\n");
  my_int(my_strncmp("Hi", NULL, 3));
  my_char('\n');
  my_str("This should be negative\n");
  my_int(my_strncmp("", "Hi", 234556));
  my_char('\n');
  my_str("This should be negative\n");
  my_int(my_strncmp(NULL, "he", 3));
  my_char('\n');
  my_str("This should be negative\n");
  my_int(my_strncmp(NULL, "", 0));
  my_char('\n');
  my_str("This should be negative\n");
  my_int(my_strncmp(NULL, "", 10));
  my_char('\n');
  my_str("This should be 0\n");
  my_int(my_strncmp(NULL, NULL, 5));
  my_char('\n');
  my_str("This should be 0\n");
  my_int(my_strncmp("", "", 343434));
  my_char('\n');
  my_str("This should be 0\n");
  my_int(my_strncmp("Hello", "Hello", 4));
  my_char('\n');
#endif
  /* testing my_strconcat */
  my_str("testing my_strconcat\n");
  my_str(my_strconcat("Hello", "Hello")); my_char('\n'); /* HelloHello */
  my_str(my_strconcat("Hi ", "Hello")); my_char('\n'); /* Hi Hello */
  my_str(my_strconcat("", "Bewchy")); my_char('\n'); /* Bewchy */
  my_str(my_strconcat(NULL, "Jim")); my_char('\n'); /* Jim */
  my_str(my_strconcat("Cramer", NULL)); my_char('\n'); /* Cramer */
  my_str(my_strconcat(NULL, NULL)); my_char('\n'); /* NULL */
  my_str(my_strconcat("", "")); my_char('\n'); /* prints nothing */

  /* testing my_strnconcat */
  my_str("testing my_strnconcat\n");
  my_str(my_strnconcat("Hello", "Hello", 0)); my_char('\n'); /* Hello */
  my_str(my_strnconcat("Hi ", "Hello", 3)); my_char('\n'); /* Hi Hel */
  my_str(my_strnconcat("", "Bewchy", 40)); my_char('\n'); /* Bewchy */
  my_str(my_strnconcat(NULL, "Jim", 3)); my_char('\n'); /* Jim */
  my_str(my_strnconcat("Cramer", NULL, 0)); my_char('\n'); /* Cramer */
  my_str(my_strnconcat(NULL, NULL, 100)); my_char('\n'); /* NULL */
  my_str(my_strnconcat("", "", 0)); my_char('\n'); /* prints nothing */
#if 0
  /* testing my_strcat */
  my_str("testing my_strcat");
  my_str(my_strcat("Hi  ", "Hi")); my_char('\n'); /* HiHi */
  my_str(my_strcat("", "How are you?")); my_char('\n'); /* How are you? */
  my_str(my_strcat(NULL, "I'm fine.")); my_char('\n'); /* I'm fine. */
  my_str(my_strcat("I'm watching you", NULL)); my_char('\n'); /* I'm watching you */
  my_str(my_strcat("Excellent", "")); my_char('\n'); /* Excellent */

  /* testing my_panic */
  my_str("testing my_panic");
  my_panic("This is not a drill", 99); my_char('\n'); /* This is not a drill */
  my_panic("Get to the Chopper!", 66); my_char('\n'); /* Get to the Chopper! */
  my_panic("Good! You're being a Smart-Lazy.", 0); my_char('\n'); /* Good! You're being a Smart-Lazy */
#endif
  /* testing my_strfind */
  my_str("testing my_strfind\n");
  my_str(my_strfind("Hello", 'e')); my_char('\n'); /*ello*/
  my_str(my_strfind("Fantastic", 'z')); my_char('\n'); /* NULL */
  my_str(my_strfind("", 'f')); my_char('\n'); /* NULL */
  my_str(my_strfind(NULL, 'f')); my_char('\n'); /* NULL */

  /* testing my_strrfind */
  my_str("testing my_strrfind\n");
  my_str(my_strrfind("asdadaassd", 'a')); my_char('\n'); /* 7 */
  my_str(my_strrfind("Fantastic", 'z')); my_char('\n'); /* NULL */
  my_str(my_strrfind("", 'f')); my_char('\n'); /* NULL */
  my_str(my_strrfind(NULL, 'f')); my_char('\n'); /* NULL */
 
  return 0;
}
