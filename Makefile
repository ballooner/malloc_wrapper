CC=gcc
CFLAGS=-W -Wall -g -O0

program: *.c
	$(CC) $(CFLAGS) *.c -o program
