# the compiler: gcc for C program, define as g++ for C++
CC = gcc

CFLAGS = -g -Wall

MAIN = main

ALUNO = aluno

# the build of all the binary executables:
BINARY = turma

all: $(BINARY)

$(BINARY): $(MAIN).c $(ALUNO).c
	$(CC) $(CFLAGS) $(MAIN).c $(ALUNO).c -o $(BINARY)

clean:
	$(RM) $(BINARY)