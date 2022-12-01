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

/* Libraries*/
#include "image-lib.h"
#include "functions.h"

/* the directories wher output files will be placed */
#define RESIZE_DIR "/Resize-dir/"
#define THUMB_DIR "/Thumbnail-dir/"
#define WATER_DIR "/Watermark-dir/"

/* Input Image File */
#define IMAGE_FILE "image-list.txt"


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
    /* Variaveis*/
    char ** images_array;
    int numero_imagens_validas = 0;
    /* Main Functions*/
    check_arguments (argc, argv);

    //int n_threads = atoi(argv[2]);
    char * images_directory = (char *) calloc(strlen(argv[1])+1,sizeof(char));
    strcpy(images_directory,argv[1]);

    images_array = read_image_file(images_directory, IMAGE_FILE, numero_imagens_validas);
    print_image_array(images_array, numero_imagens_validas);
    
    printf("Teste %d\n",numero_imagens_validas);
    printf("Até agora está tudo a correr bem\n");

    free(images_directory);
    exit(0);
}