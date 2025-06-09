CC=gcc
CFLAGS=-W -Wall

program: *.c
	$(CC) $(CFLAGS) *.c -o program
