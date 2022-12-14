/*/******************************************************************************
 * Programacao Concorrente
 * MEEC 21/22
 *
 * Projecto - ParteA - Paralelização 2
 *           
 * Grupo 11
 * 
 * Ruben Tadeia | 75268
 * 
 * Bernardo Costa | 102777
 * 
 *****************************************************************************/

/*****************************************************************************/
// Libraries
#include "functions.h"

/*****************************************************************************/
// Input Image File
#define IMAGE_FILE "image-list.txt"

/*****************************************************************************/
// Variaveis Globais
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
 * Description: Implementa a versão da paralelização da parte B
 *
 *****************************************************************************/
int main (int argc, char * argv[]){

	check_arguments (argc, argv);

	int i = 0;
	// This variable below, has the value of extra images
	// To be added to each thread
	int n_threads = 3;
	char * images_directory = (char *) calloc(strlen(argv[1])+1,sizeof(char));
	strcpy(images_directory,argv[1]);
	
	// Variaveis de Threads
	pthread_t * thread_id_list = (pthread_t *) calloc (n_threads,sizeof(pthread_t));
	pthread_t thread_id;


	// Variaveis de tempo
	clock_t t;
   	double time_taken = 0;
	
	//Inicio do clock
	t = clock();

	read_image_file(images_directory, IMAGE_FILE);
	
	create_directories(images_directory);

	// DEBUG PRINTF's
	printf("DEBUG: Numero nomes validos para imagens = %d\n",numero_imagens_validas);
	print_image_array(images_array, numero_imagens_validas);

	// Main loop
	// Thread Creation
	while( i < n_threads ){
		thread_input_info * thread_information = (thread_input_info *) malloc (sizeof(thread_input_info));
		// Ainda temos imagens para ser processadas
		if (numero_imagens_validas > 0){
			// Structure to send to the threads
			thread_information->image_folder = (char *) calloc(strlen(images_directory)+1, sizeof(char));
			strcpy(thread_information->image_folder,images_directory);
			thread_information->thread_id = i + 1;
		}
		// Ja nao temos imagens para ser processadas. Threads Sem trabalho
		else{
			// Structure to send to the threads
			thread_information->image_folder = NULL;
			
			thread_information->first_image_index = -1;

			thread_information->last_image_index = -1;

			thread_information->thread_id = i + 1;
		}
		
		// Thread 1
		if ( i == 0 ){
			thread_information->first_image_index = 0;	
			thread_information->last_image_index = numero_imagens_validas - 1;
			pthread_create(&thread_id, NULL, thread_function_wm, thread_information);
			// TESTES DOS CORES
			// Esperar pela thread 1 antes de fazer a thread 2 e 3
			//pthread_join(thread_id, NULL);
		}
		// Thread 2
		else if ( i == 1 ){
			thread_information->first_image_index = 0;	
			thread_information->last_image_index =  numero_imagens_validas - 1;
			// TESTES DOS CORES
			//pthread_create(&thread_id, NULL, thread_function_rs, thread_information);
			pthread_create(&thread_id, NULL, thread_function_rs_with_wm, thread_information);
		}
		// Thread 3
		else if ( i == 2 ){
			thread_information->first_image_index = 0;	
			thread_information->last_image_index =  numero_imagens_validas - 1;
			// TESTES DOS CORES
			//pthread_create(&thread_id, NULL, thread_function_tn, thread_information);
			pthread_create(&thread_id, NULL, thread_function_tn_with_wm, thread_information);
		}
		thread_id_list[i] = thread_id;
		i++;
	};

	// Descomentar se quisermos retornar algo da thread
	/*void * thread_ret;
	float ret_val;*/
	
	// TESTES DOS CORES
	//int gamma = 1; 
	int gamma = 0;

	// Thread Join
	while( gamma < n_threads) {
		// Descomentar se quisermos retornar algo da thread
		/*pthread_join(thread_id_list[gamma], &thread_ret);
		ret_val = *(float *) thread_ret;
		free(thread_ret);
		printf("Valor que se queira returnar da thread -> %f\n", ret_val); */
		pthread_join(thread_id_list[gamma], NULL);
		gamma++;
	};

	// Libertar memoria
	printf("Vamos começar a libertar a memoria!\n");
	free_image_array(images_array,numero_imagens_validas);
	free(images_directory);
	free(thread_id_list);

	// Tempo
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC; // calculate the elapsed time
   	printf("O programa demorou %f segundos a executar\n", time_taken);

	// Mensagem de conclusao correta do programa
	printf("Programa concluido com sucesso!\nObrigado por processar imagens conosco! :)\n\n");

	// Sair corretamente do programa
	exit(0);
}