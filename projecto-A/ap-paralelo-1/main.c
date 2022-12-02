/******************************************************************************
 * Programacao Concorrente
 * MEEC 21/22
 *
 * Projecto - Parte1
 * 
 * 
 * 
 *           
 *****************************************************************************/

/*****************************************************************************/
/* Libraries*/
#include "threads.h"
#include "functions.h"

/*****************************************************************************/
/* Input Image File */
#define IMAGE_FILE "image-list.txt"

/*****************************************************************************/
/* Variaveis Globais */
int max_word_len = 0;
char ** images_array;

// Contem o numero de nomes validos de imagens
int numero_imagens_validas = 0; 

/******************************************************************************
 * main()
 *
 * Arguments: (none)
 * Returns: 0 in case of sucess, positive number in case of failure
 * Side-Effects: creates thumbnail, resized copy and watermarked copies
 *               of images
 *
 * Description: implementation of the complex serial version 
 *              This application only works for a fixed pre-defined set of files
 *
 *****************************************************************************/

int main (int argc, char * argv[]){
	
	/* First Function To check input arguments */
	check_arguments (argc, argv);
	
	/* Variaveis*/
	int i = 0;
	int n_threads = atoi(argv[2]);
	char * images_directory = (char *) calloc(strlen(argv[1])+1,sizeof(char));
	strcpy(images_directory,argv[1]);
	//pthread_t * thread_id_list = (pthread_t *) calloc (n_threads,sizeof(pthread_t));
	//pthread_t thread_id;
	
	/* Leitura do ficheiro com os nomes das imagens */
	read_image_file(images_directory, IMAGE_FILE);
	
	// DEBUG PRINTF's
	printf("DEBUG: Numero nomes validos para imagens = %d\n",numero_imagens_validas);
	print_image_array(images_array, numero_imagens_validas);

	// Main Switch case for the project
	switch (get_images_threads_difference(numero_imagens_validas,n_threads)) {
			case 1:
				printf("DEBUG: Numero de Threads igual ao numero de imagens\n");
				// Fazer o resultado da divisao
				/// Fazer o resultado do resto da divisao inteiro
				int numero_imagens_por_thread = 1;
				break;
			case 2:
				printf("DEBUG: Numero de Threads menor que o numero de imagens\n");
				//int numero_imagens_por_thread = resultado da divisao inteira das imagens pelas threads;
				//int extra_imagens_add = resto da divisao inteira das imagens pelas threads;
				break;
			case 3:
				// Pegamos no numero de imagens e metemos cada thread com uma imagem
				// Assim que ultrapassarmos o numero de imagens
				// Colocamos os indices que entram as threads a -1 para nao fazerem nada
				printf("DEBUG: Numero de Threads maior que o numero de imagens\n");
				break;
			default:
				printf("ERRO: Existiu um problema com a relacao entre as imagens e as threads\n");
				exit(5);
				break;
	}

	// Main loop
	// Thread Creation
	while( i < n_threads ){
		/* Structure to send to the threads*/
		thread_input_info * thread_information = (thread_input_info *) malloc (sizeof(thread_input_info));
		thread_information->image_folder = (char *) calloc(strlen(images_directory)+1, sizeof(char));
		strcpy(thread_information->image_folder,images_directory);
		/*******************************************************/
		printf("DEBUG: Nome do caminho = %s\n", thread_information->image_folder);
		//pthread_create(&thread_id, NULL, thread_function_wm_tn_rs, thread_information);
		//thread_id_list[j] = thread_id;	
		i++;
	};

	// Thread Join

	// Libertar memoria
	printf("Vamos começar a libertar a memoria!\n");
	free_image_array(images_array,numero_imagens_validas);
	free(images_directory);

	// Tempo de execucao

	// Mensagem de conclusao correta do programa
	printf("Programa concluido com sucesso!\nObrigado por processar imagens conosco! :)\n\n");
	
	// Sair corretamente do programa
	exit(0);
}