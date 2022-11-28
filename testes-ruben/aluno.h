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

void bubbleSort(aluno *turma); /* Esta para ordenar apenas a primeira letra */

void swap(aluno *a, aluno *b);

void sort_classroom_alphabetically(aluno* student);

void order_classroom_and_print(aluno* student);

void print_class(aluno* student);

void print_class_with_null(aluno* student);