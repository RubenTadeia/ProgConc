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

int pipe_watermark[2]; // Pipe onde se vai escrever e ler para watermark
int pipe_resize[2]; // Pipe onde se vai escrever e ler para resize
int pipe_thumbnail[2]; // Pipe onde se vai escrever e ler para thumbnail

int numero_imagens_processadas_watermark = 0; // Numero de imagens processadas - watermark
int numero_imagens_processadas_resize = 0; // Numero de imagens processadas - resize
int numero_imagens_processadas_thumbnail = 0; // Numero de imagens processadas- thumbnail

pthread_mutex_t watermark_mutex;
pthread_mutex_t resize_mutex;
pthread_mutex_t thumbnail_mutex;

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
	if ( pipe(pipe_watermark) !=0 || pipe(pipe_resize) !=0 || pipe(pipe_thumbnail) !=0){
		printf("ERROR: creating a pipe!\n");
		exit(-1);
	}

	// Inicializacao dos mutex
	pthread_mutex_init(&watermark_mutex, NULL);
	pthread_mutex_init(&resize_mutex, NULL);
	pthread_mutex_init(&thumbnail_mutex, NULL);

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
	printf("Numero de imagens validas para processar = %d\n",numero_imagens_validas);
	print_image_array(images_array, numero_imagens_validas);

	// Thread Creation
	for(int i = 0 ; i < n_threads_per_stage; i++){
		thread_input_info * thread_information_wm = (thread_input_info *) malloc (sizeof(thread_input_info));
		thread_input_info * thread_information_rs = (thread_input_info *) malloc (sizeof(thread_input_info));
		thread_input_info * thread_information_tn = (thread_input_info *) malloc (sizeof(thread_input_info));
		
		thread_information_wm->thread_id = i + 1;
		thread_information_rs->thread_id = i + 1;
		thread_information_tn->thread_id = i + 1;
		
		thread_information_wm->image_folder = (char *) calloc(strlen(images_directory)+1, sizeof(char));
		strcpy(thread_information_wm->image_folder,images_directory);

		thread_information_rs->image_folder = (char *) calloc(strlen(images_directory)+1, sizeof(char));
		strcpy(thread_information_rs->image_folder,images_directory);

		thread_information_tn->image_folder = (char *) calloc(strlen(images_directory)+1, sizeof(char));
		strcpy(thread_information_tn->image_folder,images_directory);

		pthread_create(&thread_id_list[i], NULL, thread_function_wm, thread_information_wm);
		pthread_create(&thread_id_list[i+n_threads_per_stage], NULL, thread_function_rs, thread_information_rs);
		pthread_create(&thread_id_list[i+n_threads_per_stage+n_threads_per_stage], NULL, thread_function_tn, thread_information_tn);
	}

	// Main loop - Escrita dos nomes das imagens a serem processadas
	for(int image_array_index = 0; image_array_index < numero_imagens_validas; image_array_index++){
		write(pipe_watermark[1], &image_array_index, sizeof(int));
	}

	// Final Loop to await the ending of threads
	for(int i = 0 ; i < numero_de_stages * n_threads_per_stage; i++){
		pthread_join(thread_id_list[i],  NULL);
	}

	// Libertar memoria
	printf("Vamos começar a libertar a memoria!\n");
	free_image_array(images_array,numero_imagens_validas);
	free(images_directory);
	free(thread_id_list);

	// Destruicao dos mutex
	pthread_mutex_destroy(&watermark_mutex);
	pthread_mutex_destroy(&resize_mutex);
	pthread_mutex_destroy(&thumbnail_mutex);

	// Mensagem de conclusao correta do programa
	printf("Programa terminado com sucesso!\n");

	// Sair corretamente do programa
	exit(0);
}