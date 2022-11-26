#include "aluno.h"

/* Variables */
aluno * turma = NULL;
int n_students;
char inputFile[30] = "alunos.txt";

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
			//printf("%s -> Ruben\n", linha);
			student_insert_begining(&turma,linha,-1);
			//student_insert_end(&turma,linha,-1);
			//print_class(turma);
		}
	}
	fclose(file);
}

/* Main */
int main(int argc, char *argv[]){

	//Leitura do ficheiro
	read_file(inputFile);

	//Print da turma para efeitos de teste
	//print_class(turma);
	
	//sort_classroom_alphabetically(turma);

	if (argc == 2){
		printf("%s\n", argv[1]);
		student_insert_begining(&turma,argv[1],-1);
		//sort_classroom_alphabetically(turma);
	}

	order_classroom_and_print(turma);

	exit(0);
}