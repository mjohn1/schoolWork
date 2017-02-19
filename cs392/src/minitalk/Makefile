# Michael John
# I pledge my Honor that I have abided by The Stevens Honor System
# March 25, 2015
# Makefile for minitalk
TARGET0 = server
TARGET1 = client
SRC0 = server.c
SRC1 = client.c
OBJ0 = $(SRC0: .c=.o)
OBJ1 = $(SRC1: .c=.o)
RM = rm -f
INCLPATH = ../../include
CFLAGS += -I$(INCLPATH)
LDFLAGS += -L../../lib -Wall
LDLIBS += -lmy

all:$(TARGET0) $(TARGET1)

server:

$(TARGET0):$(OBJ0)

client:

$(TRAGET1):$(OBJ1)

clean:
	-$(RM) *~
	-$(RM) *.o
	-$(RM) *.core
	-$(RM) *.swp
	-$(RM) \#*

fclean:clean all

re:fclean all
