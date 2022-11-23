#include "aluno.h"

// Variables
char ** list_students;
aluno * turma;
int n_students;
int max_name_size;
char inputFile[30] = "alunos.txt";

// Functions
void read_file(char * fname){

	char linha[100];
	FILE * file = fopen(fname, "r");
	if(file == NULL){
		perror("Opening file");
		exit(-1);
	}
	n_students = 0;
	max_name_size = 0;
	while(fgets(linha, 100, file)){
		if(linha[0] != '\n' &&  linha[0] != '\0' && isalpha(linha[0])){
			//The isalpha() function checks whether a character is an alphabet or not.
			n_students++;
			if(strlen(linha)-1 > max_name_size){
				max_name_size = strlen(linha)-1 ;
			}
		}   
	}
	printf("Existem cerca de %d alunos!\n", n_students);
	list_students = calloc(sizeof(char *), n_students);
	if (list_students == NULL){
		perror("malloc ");
		exit(0);
	}
	max_name_size = max_name_size +1;
	file = fopen(fname, "r");
	if(file == NULL){
		perror("opening file");
		exit(-1);
	}
	int i = 0;
	while(fgets(linha, 100, file)){
		if(linha[0] != '\n' && linha[0] != '\0' && isalpha(linha[0])){
		   linha[strlen(linha)-1] = '\0';
		   for (int j = 0; linha[j]!= '\0'; j++){
			   linha[j] = tolower(linha[j]);
		   } 
			list_students[i] = calloc(sizeof(char), max_name_size);
			strcpy(list_students[i], linha);
			i++;
		}
	}
	fclose(file);
}

// Main
int main(int argc, char *argv[]){

	// Leitura do ficheiro
	read_file(inputFile);

	exit(0);
}