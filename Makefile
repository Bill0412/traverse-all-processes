CC = gcc
CFLAGS = -std=c11 -Wall -fmax-errors=10 -Wextra -lpthread -g

objects = main.o

p1-2: $(objects)
	$(CC) -o p1-2 $(objects)