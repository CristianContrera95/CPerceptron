.SUFFIXES: .o .c
.c.o:
	$(CC) -c $(CFLAGS) $<

CC = gcc
CFLAGS = -Wall  -Wextra -Wformat -Werror -g -O3 -std=c99
SRC = src/perceptron.c perceptron.h

all: $(OBJ)
	$(CC) $(CFLAGS) -o Perceptron $(OBJ)

clean:
	$(RM) Perceptron
