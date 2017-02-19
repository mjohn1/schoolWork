/* Author: Michael John
 * Date: February 4, 2015
 * I pledge my honor that I have abided by The Stevens Honor System
 * This is the header for the my library. The First Assignment.
 */

#ifndef _MY_H_
#define _MY_H_
#ifndef NULL
#define NULL ((void*)0)
#endif
#include <unistd.h>
#include <stdlib.h>

/* First Edition */
void my_char(char);
void my_str(char*);
void my_int(int);
void my_num_base(int, char*);
void my_alpha();
void my_digits();
int my_strlen(char*);
int my_revstr(char*);
int my_strindex(char*, char);
int my_strrindex(char*, char);

/* Second Edition */
void *xmalloc(unsigned int);
char *my_strdup(char*);
char *my_strcpy(char*, char*);
char *my_strncpy(char*, char*, unsigned int);
int my_strcmp(char*, char*);
int my_strncmp(char*, char*, unsigned int); 
char *my_strconcat(char*, char*);
char *my_strnconcat(char*, char*, unsigned int);
char *my_strcat(char*, char*);
void my_panic(char *, unsigned int);
char *my_strfind(char *, char);
char *my_strrfind(char*, char);

/* Third Edition */
char *my_vect2str(char**);
int my_vect_size(char**);

/* Fourth Edition */
char **my_str2vect(char*);
int my_str_size(char*);

/* Fifth Edition */
int my_atoi(char*);

#endif
