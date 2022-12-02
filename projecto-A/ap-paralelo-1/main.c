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
#include "image-lib.h"
#include "functions.h"

/*****************************************************************************/
/* the directories wher output files will be placed */
#define RESIZE_DIR "/Resize-dir/"
#define THUMB_DIR "/Thumbnail-dir/"
#define WATER_DIR "/Watermark-dir/"

/*****************************************************************************/
/* Input Image File */
#define IMAGE_FILE "image-list.txt"

/*****************************************************************************/
/* Variaveis Globais */
int max_word_len = 0;
char ** images_array;

// Contem o numero de nomes validos de imagens
int nomes_validos_imagens = 0; 

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
    //int n_threads = atoi(argv[2]);
    char * images_directory = (char *) calloc(strlen(argv[1])+1,sizeof(char));
    strcpy(images_directory,argv[1]);
    
    /* Leitura do ficheiro com os nomes das imagens */
    read_image_file(images_directory, IMAGE_FILE);
    
    // DEBUG PRINTF's
    printf("DEBUG: Numero nomes validos para imagens = %d\n",nomes_validos_imagens);
    print_image_array(images_array, nomes_validos_imagens);

    // Libertar memoria
    printf("Vamos começar a libertar a memoria!\n");
    free_image_array(images_array,nomes_validos_imagens);
    free(images_directory);

    // Mensagem de conclusao correta do programa
    printf("Programa concluido com sucesso!\nObrigado por processar imagens conosco! :)\n");
    
    // Sair corretamente do programa
    exit(0);
}