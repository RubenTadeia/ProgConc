/******************************************************************************
 * Programacao Concorrente
 * MEEC 21/22
 *
 * Projecto - Parte B - Paralelização com Pipes
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
int max_word_len = 0; // Tamanho maximo por palavra
char ** images_array; // Array com o nome das imagens
int numero_imagens_validas = 0; // Contem o numero de nomes validos de imagens
int pipe_fd[2];

/******************************************************************************
 * main()
 *
 * Arguments: (none)
 * Returns: 0 in case of sucess, positive number in case of failure
 * Side-Effects: creates thumbnail, resized copy and watermarked copies
 *               of images
 *
 * Description: Implementa a versão da paralelização da parte B com pipes
 *
 *****************************************************************************/
int main (int argc, char * argv[]){

	// Verificacao dos argumentos
	check_arguments (argc, argv);

	// Inicializacao da pipe
	if (pipe(pipe_fd)!=0){
		printf("ERROR: creating the pipe\n");
		exit(-1);
	}

	// Guardar argumentos de entrada em variaveis
	int n_threads_per_stage = atoi(argv[2]);
	char * images_directory = (char *) calloc(strlen(argv[1])+1,sizeof(char));
	strcpy(images_directory,argv[1]);
	int numero_de_stages = 3;
	
	// Variaveis de Threads
	pthread_t * thread_id_list = (pthread_t *) calloc (numero_de_stages * n_threads_per_stage,sizeof(pthread_t));

	// Leitura do ficheiro de imagens e criar directorias de saida
	read_image_file(images_directory, IMAGE_FILE);	
	create_directories(images_directory);

	// DEBUG PRINTF's
	printf("Numero nomes validos para imagens = %d\n",numero_imagens_validas);
	print_image_array(images_array, numero_imagens_validas);

	// Thread Creation
	for(int i = 0 ; i < n_threads_per_stage; i++){
		thread_input_info * thread_information_wm = (thread_input_info *) malloc (sizeof(thread_input_info));
		thread_input_info * thread_information_rs = (thread_input_info *) malloc (sizeof(thread_input_info));
		thread_input_info * thread_information_tn = (thread_input_info *) malloc (sizeof(thread_input_info));
		thread_information_wm->thread_id = i + 1;
		thread_information_rs->thread_id = i + 1;
		thread_information_tn->thread_id = i + 1;
		pthread_create(&thread_id_list[i], NULL, thread_function_wm, thread_information_wm);
		pthread_create(&thread_id_list[i+n_threads_per_stage], NULL, thread_function_rs, thread_information_rs);
		pthread_create(&thread_id_list[i+n_threads_per_stage+n_threads_per_stage], NULL, thread_function_tn, thread_information_tn);
	}

	// Main loop

	// Final Loop to await the ending of threads
	for(int i = 0 ; i < numero_de_stages * n_threads_per_stage; i++){
		pthread_join(thread_id_list[i],  NULL);
	}

	// Libertar memoria
	printf("Vamos começar a libertar a memoria!\n");
	free_image_array(images_array,numero_imagens_validas);
	free(images_directory);
	free(thread_id_list);

	// Mensagem de conclusao correta do programa
	printf("Programa terminado com sucesso!\n");

	// Sair corretamente do programa
	exit(0);
}