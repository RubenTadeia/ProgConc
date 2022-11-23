#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Estrutura 
typedef struct aluno{
	char *nome;
}aluno;


int main(){

	// Variaveis
	FILE *ficheiro_entrada;
	char ficheiro_alunos[30] = "alunos.txt";
	char linha[50];
	int numero_alunos = 0;
	int maior_nome = 0;

	// Main
	ficheiro_entrada = fopen(ficheiro_alunos, "r");

	while(fgets(linha, 50, ficheiro_entrada) != NULL){
		numero_alunos++;
		if(strlen)	// Fiquei Aqui
	}


}