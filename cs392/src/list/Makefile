# Michael John
# I pledge my Honor that I have abided by The Stevens Honor System
# February 23, 2015
# Makefile for the list library
NAME = libmylist.a
SRC = new_node.c add_node.c add_elem.c append.c add_node_at.c remove_node.c remove_last.c remove_node_at.c count_nodes.c empty_list.c node_at.c elem_at.c traverse_int.c traverse_char.c traverse_string.c debug_string.c debug_int.c debug_char.c print_char.c print_string.c print_int.c
OBJ = $(SRC:.c=.o)
RM = rm -f
INCLPATH = ../../include
LIBPATH = ../../lib
CFLAGS +=-I$(INCLPATH) 
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
