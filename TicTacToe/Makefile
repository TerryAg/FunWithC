CC=gcc
CFLAGS=-Wall -Werror
BINS=ttt
ttt: board_funcs.o end.o main.o turn.o
	$(CC) -o ttt board_funcs.o end.o main.o turn.o

clean: 
	rm -f $(BINS) *.o core