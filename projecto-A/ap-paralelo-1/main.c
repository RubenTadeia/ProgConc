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
	int j = 0;
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

	// Main loop
	for (i = 0; i < numero_imagens_validas;) {
		// Thread Creation
		j = 0;
		while( j < n_threads ){
			/* Structure to send to the threads*/
			image_info * image_information = (image_info *) malloc (sizeof(image_info));
			image_information->image_folder = (char *) calloc(strlen(images_directory)+1, sizeof(char));
			strcpy(image_information->image_folder,images_directory);
			image_information->image_name = (char *) calloc(strlen(images_array[i])+1, sizeof(char));
			strcpy(image_information->image_name,images_array[i]);
			/*******************************************************/
			printf("DEBUG: Nome do caminho = %s\n", image_information->image_folder);
			printf("DEBUG: Nome da imagem = %s\n", image_information->image_name);
			//pthread_create(&thread_id, NULL, thread_function_wm_tn_rs, image_information);
			//thread_id_list[j] = thread_id;	
			j++;
			i++;
			// Situacao em que acabaram as imagens
			if (i >= numero_imagens_validas){
				break;
			}
		};
	}

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