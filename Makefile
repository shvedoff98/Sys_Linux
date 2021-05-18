#Makefile

CLEAN = rm -f
CC = gcc
NAME = signals_kill

$(NAME).o: $(NAME).c
	$(CC) -c $^

$(NAME): $(NAME).o
	$(CC) -Wall -o $@ $^

clean:
	$(CLEAN) *.0
	$(CLEAN) $(NAME)	