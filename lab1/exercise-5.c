#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure
typedef struct word_info{
	char * word;
	int count;
	struct word_info *next;
} word_info;

// Variables
char ** word_array; //ordenado
int n_words;
int max_word_len;
int word_info_count;
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

/*word_info * teste (char **word_array, int n_total_words, char letter){
	// Criar 2 word info
	// Devolver o vector das 2 word infos
	word_info * aux = calloc(n_total_words, sizeof(word_info));
	word_info aux_1;
	aux_1.word = "banana";
	aux_1.count = 3;
	
	aux[0].word = malloc(strlen(aux_1.word)-1);
	strcpy(aux[0].word , aux_1.word);
	aux[0].count = aux_1.count;
	printf("palavra = %s\n",aux[0].word);
	printf("numero = %d\n",aux[0].count);

	word_info aux_2;
	aux_2.word = "cenoura";
	aux_2.count = 1;

	aux[1].word = malloc(strlen(aux_2.word)-1);
	strcpy(aux[1].word , aux_2.word);
	aux[1].count = aux_2.count;
	printf("palavra = %s\n",aux[1].word);
	printf("numero = %d\n",aux[1].count);

	return aux;
}*/

word_info * find_unique_word(char **word_array, int n_total_words, char letter){
	
	word_info * word_list = malloc(sizeof(word_info));
	word_list->word = word_array[0];
	word_list->count = 1;
	word_list->next = NULL;

	word_info * aux;
	word_info * aux2 = (word_info *) malloc (sizeof(word_info));

	for(int i = 1; i < n_total_words; i++){
		for(aux = word_list; aux != NULL ; aux = aux->next){
			if(strcmp(aux->word, word_array[i]) == 0){
				aux->count++;
				gamma = 1;
				break;
			//}else{
			//	aux2->word = word_array[i];
			//	aux2->count = 1;
			//	aux->next = aux2;
			//	aux2->next = NULL;
			//	break;
			}
			
		}

	}

	return word_list;
}

/*void print_unique_words_count(word_info *word_list, char c){
	printf("%c %d\n", c ,word_info_count);
}*/

void print_unique_words_count(char c){
	printf("%c %d\n", c ,word_info_count);
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

word_info * more_freq_words(word_info * word_list){
	word_info * max_word_count = malloc(sizeof(word_info));

	word_info aux;
	aux.word = malloc(50 * sizeof(char));
	aux.count = 1;
	
	int max = 0;
	for (int i =0; i < word_info_count; i++) {
		if (word_list[i].count > max){
			max = word_list[i].count;
			aux.count = max;    
			strcpy(aux.word ,  word_list[i].word);
		}
	}

	max_word_count[0].word = malloc(strlen(aux.word)-1);
	strcpy(max_word_count[0].word , aux.word);
	max_word_count[0].count = aux.count;

	return max_word_count;
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
	int number_of_character_words;

	word_info * word_list = NULL;
	word_info * word_count = NULL;
	//int n_unique_words = 0;
	for (char c = 'a'; c <='z'; c++){
		number_of_character_words = count_words(word_array, n_words, c);
		printf("%c %d\n", c ,number_of_character_words);
		word_list = find_unique_word(word_array, n_words, c);
		print_unique_words_count(c);
		word_count = more_freq_words(word_list);
		//printf("%d %s\n\n", word_count->count , word_count->word);
	}

	exit(0);
}