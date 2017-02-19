# Michael John
# I pledge my honor that I have abided by The Stevens Honor System
# April 28, 2015

TARGET0 = gtk_client
TARGET1 = gtk_server
SRC0 = gtk_client.c
SRC1 = gtk_server.c
OBJ0 = $(SRC0:.c=.o)
OBJ1 = $(SRC1:.c=.o)
RM= rm -f
INCLPATH = ../../include
CFLAGS += -I$(INCLPATH)
LDFLAGS += -L../../lib
LDLIBS += -lmy

all:$(TARGET0)# $(TARGET1)

$(TARGET0):
	cc $(LDFLAGS) $(SRC0) $(LDLIBS) -o $(TARGET0) `pkg-config --cflags --libs gtk+-2.0`

#$(TARGET1):$(OBJ1)

clean:
	-$(RM) *~
	-$(RM) *.o
	-$(RM) *.core
	-$(RM) *.swp
	-$(RM) \#*

fclean:clean
	-$(RM) $(TARGET0)
	#-$(RM) $(TARGET1)

re:fclean all
