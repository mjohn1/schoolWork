TEST1=testmyatoi
TEST2=testmy
TEST3=testmy2
SRC1=testmyatoi.c
SRC2=testmy.c
SRC3=testmy2.c
OBJ1=$(SRC1:.c=.o)
OBJ2=$(SRC2:.c=.o)
OBJ3=$(SRC3:.c=.o)
RM=rm -f
INCLPATH= ../include
CFLAGS+=-I$(INCLPATH)
LDFLAGS+= -L../lib
LDLIBS+= -lmylist -lmy

all:$(TEST1) $(TEST2) $(TEST3)

$(TEST1):$(OBJ1)
$(TEST2):$(OBJ2)
$(TEST3):$(OBJ3)

clean:
	-$(RM) *~
	-$(RM) *.o
	-$(RM) *.core
	-$(RM) *.swp
	-$(RM) \#*

fclean:clean all
