#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Structures */
typedef struct aluno{
	char * name;
	int number;
	struct aluno * next;
} aluno;


void student_insert_begining(aluno** head, char * studentName, int number);

void student_insert_end(aluno** head, char * studentName, int number);

void print_class(aluno* student);