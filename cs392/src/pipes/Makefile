TARGET = pipes
SRC = pipes.c
OBJ = $(SRC:.c=.o)
RM = rm -f
INCLPATH = ../../include
CFLAGS+=-I$(INCLPATH)
LDFLAGS+= -L../../lib
LDLIBS+= -lmy

all:$(TARGET)

$(TARGET): $(OBJ)

clean:
	-$(RM) *~
	-$(RM) *.o
	-$(RM) *.core
	-$(RM) *.swp
	-$(RM) \#*

fclean:clean all


