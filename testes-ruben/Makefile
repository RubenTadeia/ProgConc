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

mem:
	valgrind --leak-check=full \
--show-leak-kinds=all \
--track-origins=yes \
--verbose \
--log-file=valgrind-ruben.txt \
./turma Ruben