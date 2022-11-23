#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structures
typedef struct aluno{
	char * name;
	int number;
	struct aluno * next;
} aluno;
