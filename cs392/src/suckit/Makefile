# Michael John
# I pledge my honor that I have abided by The Stevens Honor System
# April 6, 2015
# Makefile for Sockets
TARG0 = server
TARG1 = client
SRC0 = server.c
SRC1 = client.c
OBJ0 = $(SRC0:.c=.o)
OBJ1 = $(SRC1:.c=.o)
RM = rm -f
INCLPATH = ../../include
CFLAGS += -I$(INCLPATH)
LDFLAGS += -L../../lib 
LDLIBS += -lmy

all:$(TARG0) $(TARG1)

$(TARG0):$(OBJ0)

$(TARG1):$(OBJ1)

clean:
	-$(RM) *~
	-$(RM) *.o
	-$(RM) *.core
	-$(RM) *.swp
	-$(RM) \#*

fclean: clean
	-$(RM) $(TARG0)
	-$(RM) $(TARG1)

re:flcean all
