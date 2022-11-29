#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Structures */
typedef struct aluno_class{
	char * name;
	int number;
	struct aluno_class * next;
} aluno; //nome que vai ter a extrutura


void student_insert_begining(aluno** head, char * studentName, int number);

void student_insert_end(aluno** head, char * studentName, int number);

void bubbleSort(aluno *turma);

void swap(aluno *a, aluno *b);

void order_classroom_and_print(aluno* student);

void print_class(aluno* student);

void print_class_with_null(aluno* student);

void freeTurma(aluno* head);