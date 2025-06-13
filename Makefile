CC=gcc
CFLAGS=-W -Wextra -Wall -pedantic-errors

program: *.c
	$(CC) $(CFLAGS) *.c -o program
