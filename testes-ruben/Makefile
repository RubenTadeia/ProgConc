# the compiler: gcc for C program, define as g++ for C++
CC = gcc

CFLAGS = -g -Wall -ansi -pedantic -std=c99

MAIN = main

ALUNO = aluno

StudentName = Ruben

# the build of all the binary executables:
BINARY = turma

all: $(BINARY)

$(BINARY): $(MAIN).c $(ALUNO).c
	$(CC) $(CFLAGS) $(ALUNO).c $(MAIN).c -o $(BINARY)

clean:
	$(RM) $(BINARY)

run:
	./$(BINARY) $(StudentName)
#	-./$(BINARY) $(StudentName)
#	o traco - -> Ignora os erros do make. Tudo o que não é exit(0)
	