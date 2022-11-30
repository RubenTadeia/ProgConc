#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//////////////////////////////////////////////////////////////////////////////
// Variables
char ** word_array; //ordenado
int n_words;
int max_word_len;
char inputFile[30] = "lusiadas-words.txt";

//////////////////////////////////////////////////////////////////////////////
// Structure
typedef struct word_info_class{
	char * word;
	int count;
	struct word_info_class * next;
} word_info;

//////////////////////////////////////////////////////////////////////////////
// Structure Functions
void word_info_insert_begining(word_info** head, char * palavra, int number){

	word_info* uniqueWord = (word_info*) malloc(sizeof(word_info));

	uniqueWord->word = calloc(strlen(palavra)+1, sizeof(char *));
	strcpy(uniqueWord->word,palavra);
	uniqueWord->count = number;
	uniqueWord->next = *head;

	//changing the new head to this freshly entered node
	*head = uniqueWord; 
}

void print_word_info(word_info* palavra){

	//as linked list will end when Node is Null
	while(palavra->next!=NULL){
		printf("Word = %s\nCount = %d\n",palavra->word, palavra->count);
		palavra = palavra->next;
	}
	printf("\n");
}

void free_word_info(word_info* palavra)
{
	word_info * tmp;

	while (palavra != NULL)
	{
		tmp = palavra;
		palavra = palavra->next;
		free(tmp->word);
		free(tmp);
	}

}
//////////////////////////////////////////////////////////////////////////////
/* Declaration of compare() as a function */
int compare (const void *arg1, const void *arg2) /* macro is automatically */                
{                                                                               
	/* Compare all of both strings */              
	return(strncmp(*(char **)arg1, *(char **)arg2,1));                              
}   
//////////////////////////////////////////////////////////////////////////////
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

word_info * find_unique_word(char **word_array, int n_total_words, char letter){
	word_info * word_list = (word_info * ) calloc(1, sizeof(word_info));
	int i = 0;
	int y = 0;
	int j = 0;

	while (i < n_total_words){

		if ( word_array[i][0] == letter ){
			if( j == 1){
				// Ja existe uma palavra
				y = 0;
				word_info * tmp = word_list;
				// As linked list will end when Node is Null
				while(tmp->next!=NULL){
					if(strcmp(word_array[i], tmp->word) == 0){
						tmp->count = tmp->count + 1;
						y = 1;
					}
					tmp = tmp->next;
				}
				if (y == 0){
					// A palavra nao existe
					word_info_insert_begining(&word_list,word_array[i],1);
				}
			}
			else if ( j == 0){
				// Nao existem palavras
				word_info_insert_begining(&word_list,word_array[i],1);
				j = 1;
			}
		}
		i++;
	}

	return word_list;
}

void print_unique_words_count(word_info *word_list, char c){
	// As linked list will end when Node is Null
	int contaPalavras = 0;

	while(word_list->next!=NULL){
		if ((char) word_list->word[0] == c){
			contaPalavras = contaPalavras + 1;
		}
		word_list = word_list->next;
	}
	printf("%c %d\n", c ,contaPalavras);

	free_word_info(word_list);
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
	word_info * max_word_count = (word_info*) calloc(1,sizeof(word_info));
	
	int max = 0;
	while(word_list->next!=NULL){
		if (word_list->count > max){
			max = word_list->count;
			max_word_count->word = calloc(strlen(word_list->word)+1, sizeof(char *));
			strcpy(max_word_count->word,word_list->word);
			max_word_count->count = max;
		}
		word_list = word_list->next;
	}

	return max_word_count;
}


// Main
int main(int argc, char *argv[]){
	printf("Reading the file. Please note that empty lines will be ignored\n");
	read_words(inputFile);

	// Sorting
	qsort((char *)word_array, n_words, sizeof(char *), compare);

	////////////////////////////////////////////////////////
	// Exercise 2
	////////////////////////////////////////////////////////
	int number_of_character_words;

	word_info * word_list = NULL;
	word_info * word_count = NULL;
	for (char c = 'a'; c <='z'; c++){
		number_of_character_words = count_words(word_array, n_words, c);
		printf("%c %d\n", c ,number_of_character_words);
		
		////////////////////////////////////////////////////////
		// Exercise 3
		////////////////////////////////////////////////////////
		word_list = find_unique_word(word_array, n_words, c);
		print_unique_words_count(word_list, c);
		
		////////////////////////////////////////////////////////
		// Exercise 4
		////////////////////////////////////////////////////////
		word_count = more_freq_words(word_list);
		printf("%d %s\n\n", word_count->count , word_count->word);
	}

	exit(0);
}