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
	// This variable below, has the value of extra images
	// To be added to each thread
	int n_threads = 3;
	char * images_directory = (char *) calloc(strlen(argv[1])+1,sizeof(char));
	strcpy(images_directory,argv[1]);
	
	/* Variaveis de Threads */
	pthread_t * thread_id_list = (pthread_t *) calloc (n_threads,sizeof(pthread_t));
	pthread_t thread_id;


	// Variaveis de tempo
	clock_t t;
   	double time_taken = 0;

 	/*************************************************************************/
	
	/* Inicio do clock */
	t = clock();

	/* Leitura do ficheiro com os nomes das imagens */
	read_image_file(images_directory, IMAGE_FILE);
	
	/* Criar as pastas de destino */
	create_directories(images_directory);

	// DEBUG PRINTF's
	printf("DEBUG: Numero nomes validos para imagens = %d\n",numero_imagens_validas);
	print_image_array(images_array, numero_imagens_validas);
	
	/*************************************************************************/

	// Main loop
	// Thread Creation
	while( i < n_threads ){
		thread_input_info * thread_information = (thread_input_info *) malloc (sizeof(thread_input_info));
		// Ainda temos imagens para ser processadas
		// Resolve as situacoes em que numero de threads e igual ou menor que o numero de imagens
		if (numero_imagens_validas > 0){
			/* Structure to send to the threads*/
			thread_information->image_folder = (char *) calloc(strlen(images_directory)+1, sizeof(char));
			strcpy(thread_information->image_folder,images_directory);
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
		
		// Thread 1
		if ( i == 0 ){
			thread_information->first_image_index = 0;	
			thread_information->last_image_index = numero_imagens_validas - 1;
			pthread_create(&thread_id, NULL, thread_function_wm, thread_information);
			// Descomentar a linha abaixo se quisermos
			// Ter a thread 1 a fazer tambem resize
			//pthread_create(&thread_id, NULL, thread_function_wm_rs, thread_information);
			pthread_join(thread_id, NULL);
		}
		// Thread 2
		else if ( i == 1 ){
			thread_information->first_image_index = numero_imagens_validas / 3;	
			thread_information->last_image_index = numero_imagens_validas - 1;
			pthread_create(&thread_id, NULL, thread_function_wm_rs, thread_information);
		}
		// Thread 3
		else if ( i == 2 ){
			thread_information->first_image_index = numero_imagens_validas - 1;	
			thread_information->last_image_index =  0;
			pthread_create(&thread_id, NULL, thread_function_wm_tn, thread_information);
		}
		thread_id_list[i] = thread_id;
		i++;
	};

	/*************************************************************************/
	void * thread_ret;
	float ret_val;
	int gamma = 1;

	// Thread Join
	while( gamma < n_threads) {
		pthread_join(thread_id_list[gamma], &thread_ret);
		ret_val = *(float *) thread_ret;
		free(thread_ret);
		printf("Valor que se queira returnar da thread -> %f\n", ret_val);
		gamma++;
	};

	/*************************************************************************/
	
	// Libertar memoria
	printf("Vamos começar a libertar a memoria!\n");
	free_image_array(images_array,numero_imagens_validas);
	free(images_directory);
	free(thread_id_list);

	/*************************************************************************/

	// Tempo
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC; // calculate the elapsed time
   	printf("O programa demorou %f segundos a executar\n", time_taken);

	/*************************************************************************/

	// Mensagem de conclusao correta do programa
	printf("Programa concluido com sucesso!\nObrigado por processar imagens conosco! :)\n\n");
	
	/*************************************************************************/

	// Sair corretamente do programa
	exit(0);
}