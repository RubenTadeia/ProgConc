#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Variables
char ** word_array; //ordenado
int n_words;
int max_word_len;
char inputFile[30] = "lusiadas-words.txt";

/* Declaration of compare() as a function */
int compare (const void *arg1, const void *arg2) /* macro is automatically */                
{                                                                               
	/* Compare all of both strings */              
	return(strncmp(*(char **)arg1, *(char **)arg2,1));                              
}   

// Functions
void read_words(char * fname){

	char linha[100];
	FILE * file = fopen(fname, "r");
	if(file == NULL){
		perror("Opening file");
		exit(-1);
	}
	n_words =0;
	max_word_len = 0;
	while(fgets(linha, 100, file)){
		if(linha[0] != '\n' &&  linha[0] != '\0' && isalpha(linha[0])){
			//The isalpha() function checks whether a character is an alphabet or not.
			n_words++;
			if(strlen(linha)-1 > max_word_len){
				max_word_len = strlen(linha)-1 ;
			}
		}   
	}
	printf("%d numero de palavras\n", n_words);
	word_array = calloc(sizeof(char *), n_words);
	if (word_array == NULL){
		perror("malloc ");
		exit(0);
	}
	max_word_len = max_word_len +1;
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
			word_array[i] = calloc(sizeof(char), max_word_len);
			strcpy(word_array[i], linha);
			i++;
		}
	}
	fclose(file);
}

int count_words(char **word_array, int n_words, char letter){
	
	int n_unique_words = 0;

	for (int i = 0; i < n_words; i++){
		if(word_array[i][0] == letter){
			n_unique_words++;
		}
	}
	return n_unique_words;
}

// Main
int main(int argc, char *argv[]){
	printf("Reading the file. Please note that empty lines will be ignored\n");
	read_words(inputFile);


	////////////////////////////////////////////////////////
	// Exercise 1
	////////////////////////////////////////////////////////
	// Before Sorting
	//for (int i = 0; i < n_words ; i++){
	//	printf("%s\n", word_array[i]);
	//}

	// Sorting
	//qsort((char *)words, n_words, sizeof(char *), compare);
	qsort((char *)word_array, n_words, sizeof(char *), compare);

	// After Sorting
	//for (int i = 0; i < n_words ; i++){
	//	printf("%s\n", word_array[i]);
	//}

	////////////////////////////////////////////////////////
	// Exercise 2
	////////////////////////////////////////////////////////
	int n_unique_words;
	for (char c = 'a'; c <='z'; c++){
		n_unique_words = count_words(word_array, n_words, c);
		printf("%c %d\n", c ,n_unique_words);
	}

	exit(0);
}