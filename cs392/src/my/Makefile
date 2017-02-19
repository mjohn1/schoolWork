# Michael John
# I pledge my Honor that I have abided by The Stevens Honor System
# February 23, 2015
# Makefile for the my library
NAME = libmy.a
SRC = my_char.c my_str.c my_int.c my_num_base.c my_alpha.c my_digits.c my_strlen.c my_revstr.c my_strindex.c my_strrindex.c xmalloc.c my_strdup.c my_strcpy.c my_strncpy.c my_strcmp.c my_strncmp.c my_strconcat.c my_strnconcat.c my_strcat.c my_strfind.c my_strrfind.c my_vect2str.c my_vect_size.c my_str2vect.c my_str_size.c my_atoi.c
OBJ = $(SRC:.c=.o)
RM = rm -f
INCLPATH = ../../include
LIBPATH = ../../lib
CFLAGS += -I$(INCLPATH) 
#comments with a pound sign
all:$(OBJ)
	ar -rc $(LIBPATH)/$(NAME) $(OBJ)
	ranlib $(LIBPATH)/$(NAME)
clean:
	-$(RM) *~
	-$(RM) *.o
	-$(RM) *.core
	-$(RM) *.swp
	-$(RM) \#*
fclean:clean
	-$(RM) $(LIBPATH)/$(NAME)
re:fclean all
