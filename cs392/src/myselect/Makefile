# Michael John
# I pledge my Honor that I have abided by The Stevens Honor System
# April 20, 2015
# Makefile for myselect
TARG = my_select
SRC = init_terminal.c restore_terminal.c term_get_cap.c init_caps.c my_termprint.c term_clear.c term_vi.c term_ve.c get_win_size.c show_elems.c refreshin.c refreshout.c moveup.c movedown.c moveleft.c moveright.c term_move_to_item.c term_move.c term_underline.c term_standout.c term_standend.c term_underend.c doselect.c getout.c setup_elems.c check_char.c
OBJ = $(SRC:.c=.o)
RM = rm -f
INCLPATH = ../../include
CFLAGS += -I$(INCLPATH)
LDFLAGS += -L../../lib
LDLIBS += -lmy -ltermcap

all:$(TARG)

$(TARG):$(OBJ)

clean:
	-$(RM) *~
	-$(RM) *.o
	-$(RM) *.core
	-$(RM) *.swp
	-$(RM) \#*

fclean: clean
	-$(RM) $(TARG)

re:flcean all
