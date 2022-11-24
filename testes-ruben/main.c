#include "aluno.h"

/* Variables */
aluno * turma = NULL;
int n_students;
char inputFile[30] = "alunos.txt";

int gamma = 0;

/* Functions */
void read_file(char * fname){

	char linha[100];
	FILE * file = fopen(fname, "r");
	if(file == NULL){
		perror("Opening file");
		exit(-1);
	}
	turma = (aluno *) malloc (sizeof(aluno));

	if (turma == NULL){
		perror("malloc ");
		exit(0);
	}
	n_students = 0;

	while(fgets(linha, 100, file)){
		if(linha[0] != '\n' &&  linha[0] != '\0' && isalpha(linha[0])){
			/* The isalpha() function checks whether a character is an alphabet or not. */
			n_students++;
		}   
	}
	printf("Existem cerca de %d alunos!\n", n_students);
	
	file = fopen(fname, "r");
	if(file == NULL){
		perror("opening file");
		exit(-1);
	}

	while(fgets(linha, 100, file)){
		if(linha[0] != '\n' && linha[0] != '\0' && isalpha(linha[0])){
			linha[strlen(linha)-1] = '\0';
			printf("%s -> Ruben\n", linha);
			student_insert_begining(&turma,linha,0);
			/* student_insert_end(&turma,linha,0); */
			print_class(turma);
			gamma++;
			if (gamma == 2){
				exit(1);
			}
		}
	}
	fclose(file);
}

/* Main */
int main(int argc, char *argv[]){

	/* Leitura do ficheiro */
	read_file(inputFile);

	//print_class(turma);

	exit(0);
}