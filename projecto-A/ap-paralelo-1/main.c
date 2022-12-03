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
	
	/*************************************************************************/

	/* First Function To check input arguments */
	check_arguments (argc, argv);

	/*************************************************************************/

	/* Variaveis */
	int i = 0;
	int gamma = 0;
	// This variable below, has the value of extra images
	// To be added to each thread
	int extra_images = 0; 	
	int n_threads = atoi(argv[2]);
	char * images_directory = (char *) calloc(strlen(argv[1])+1,sizeof(char));
	strcpy(images_directory,argv[1]);
	int aux_index_threads = 0;
	int numero_imagens_por_thread = 0;
	
	/* Variaveis de Threads */
	pthread_t * thread_id_list = (pthread_t *) calloc (n_threads,sizeof(pthread_t));
	pthread_t thread_id;
	void * thread_ret;
	long int ret_val;

	/* Variaveis de Tempo */
	//struct timespec begin_main_time, end_main_time;
	//clock_gettime(CLOCK_REALTIME, &begin_main_time);

 	/*************************************************************************/

	/* Leitura do ficheiro com os nomes das imagens */
	read_image_file(images_directory, IMAGE_FILE);
	
	/* Criar as pastas de destino */
	create_directories(images_directory);

	// DEBUG PRINTF's
	printf("DEBUG: Numero nomes validos para imagens = %d\n",numero_imagens_validas);
	print_image_array(images_array, numero_imagens_validas);

	// Main Switch case for the project
	switch (get_images_threads_difference(numero_imagens_validas,n_threads)) {
			case 1:
				// Numero de Threads igual ao numero de imagens
				printf("DEBUG: Numero de Threads igual ao numero de imagens\n");
				numero_imagens_por_thread = 1;
				break;
			case 2:
				// Numero de Threads menor que o numero de imagens
				printf("DEBUG: Numero de Threads menor que o numero de imagens\n");
				numero_imagens_por_thread = numero_imagens_validas / n_threads;
				extra_images = numero_imagens_validas % n_threads;
				break;
			case 3:
				// Numero de Threads maior que o numero de imagens
				printf("DEBUG: Numero de Threads maior que o numero de imagens\n");
				numero_imagens_por_thread = 1;
				break;
			default:
				printf("ERRO: Existiu um problema com a relacao entre as imagens e as threads\n");
				exit(5);
				break;
	}
	
	/*************************************************************************/

	// Main loop
	// Thread Creation
	while( i < n_threads ){
		thread_input_info * thread_information = (thread_input_info *) malloc (sizeof(thread_input_info));
		// Ainda temos imagens para ser processadas
		// Resolve as situacoes em que numero de threads e igual ou menor que o numero de imagens
		if (aux_index_threads < numero_imagens_validas){
			/* Structure to send to the threads*/
			thread_information->image_folder = (char *) calloc(strlen(images_directory)+1, sizeof(char));
			strcpy(thread_information->image_folder,images_directory);
			
			thread_information->first_image_index = aux_index_threads;
			
			// Isto é que pode não funcionar... Porque o main
			// E as threads têm velocidades diferentes
			if (extra_images != 0){
				extra_images = extra_images - 1;
				aux_index_threads = aux_index_threads + 1;
			}

			aux_index_threads = aux_index_threads + numero_imagens_por_thread - 1;
			thread_information->last_image_index = aux_index_threads;

			thread_information->thread_id = i + 1;
		}

		// Ja nao temos imagens para ser processadas. Threads Sem trabalho
		// Resolve a situacao em que numero de threads e maior que o numero de imagens
		else{
			/* Structure to send to the threads*/
			thread_information->image_folder = NULL;
			
			thread_information->first_image_index = -1;

			thread_information->last_image_index = -1;

			thread_information->thread_id = i + 1;
		}
		
		/*******************************************************/
		// DEBUG PRINTS
		//printf("DEBUG: Thread numero = %d\n", thread_information->thread_id);
		//printf("DEBUG: Thread primeiro index = %d\n", thread_information->first_image_index);
		//printf("DEBUG: Thread ultimo index = %d\n", thread_information->last_image_index);
		//printf("DEBUG: Nome do caminho = %s\n\n", thread_information->image_folder);
		
		pthread_create(&thread_id, NULL, thread_function_wm_tn_rs, thread_information);
		thread_id_list[i] = thread_id;
		i++;
		aux_index_threads++;
	};

	/*************************************************************************/

	// Thread Join
	while( gamma < n_threads) {
		pthread_join(thread_id_list[gamma], &thread_ret);
		ret_val = (long int) thread_ret;
		printf("Valor que se queira returnar da thread -> %ld\n", ret_val);;
		gamma++;
	};

	/*************************************************************************/

	// Libertar memoria
	printf("Vamos começar a libertar a memoria!\n");
	free_image_array(images_array,numero_imagens_validas);
	free(images_directory);
	free(thread_id_list);

	/*************************************************************************/

	// Mensagem de conclusao correta do programa
	printf("Programa concluido com sucesso!\nObrigado por processar imagens conosco! :)\n\n");
	
	/*************************************************************************/

	// Sair corretamente do programa
	exit(0);
}