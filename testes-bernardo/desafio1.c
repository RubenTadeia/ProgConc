#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Estrutura 
typedef struct aluno{
	char *nome;
	struct aluno *next;
}aluno;


int main(){

	// Variaveis
	FILE *ficheiro_entrada;
	aluno *novo_aluno;
	char ficheiro_alunos[30] = "alunos.txt";
	char linha[50];
	int numero_alunos = 0;
	int maior_nome = 0;
	int i = 0;

	// Main
	ficheiro_entrada = fopen(ficheiro_alunos, "r");

	while(fgets(linha, 50, ficheiro_entrada)){
		numero_alunos++;
		if(strlen(linha)-1 > maior_nome){
			maior_nome = strlen(linha)-1;
		}	
	}

	fclose(ficheiro_entrada);

	ficheiro_entrada = fopen(ficheiro_alunos, "r");

	novo_aluno = (aluno *)malloc(numero_alunos * sizeof(aluno));

	//for( int i=0; i<numero_alunos; i++){
		while(fgets(linha, 50, ficheiro_entrada)){
				novo_aluno[i].nome = (char *)malloc(maior_nome * sizeof(char));
				strcpy(novo_aluno[i].nome, linha);
				novo_aluno[i].next = NULL;
				i++;
		}
	//}

	for( int i=0; i<numero_alunos; i++){
		printf("%s\n", novo_aluno[i].nome);
	}

	exit(0);
}