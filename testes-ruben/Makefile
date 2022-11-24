# the compiler: gcc for C program, define as g++ for C++
CC = gcc

CFLAGS = -g -Wall -ansi -pedantic -std=c99

MAIN = main

ALUNO = aluno

# the build of all the binary executables:
BINARY = turma

all: $(BINARY)

$(BINARY): $(MAIN).c $(ALUNO).c
	$(CC) $(CFLAGS) $(ALUNO).c $(MAIN).c -o $(BINARY)

clean:
	$(RM) $(BINARY)