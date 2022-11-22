# the compiler: gcc for C program, define as g++ for C++
CC = gcc

CFLAGS = -g -Wall

FILE = main

# the build of all the binary executables:
BINARY = turma

all: $(BINARY)

$(BINARY): $(FILE).c
	$(CC) $(CFLAGS) $(FILE).c -o $(BINARY)

clean:
	$(RM) $(BINARY)