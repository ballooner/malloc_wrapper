CC=gcc
CFLAGS=-W -Wall

program: main.c
	$(CC) $(CFLAGS) main.c -o program
