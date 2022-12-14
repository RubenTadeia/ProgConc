// Libraries
#include "threads.h"

/******************************************************************************
 * check_arguments()
 *
 * Arguments: int argc
 * 			  char * argv[]
 * Returns: none
 * Side-Effects: none
 *
 * Description: Verifica se os argumentos estão na forma correta
 *
 *****************************************************************************/
void check_arguments (int argc, char * argv[]);

/******************************************************************************
 * read_image_file()
 *
 * Arguments: char * imagesDirectory
 * 			  char * fname
 * Returns: none
 * Side-Effects: none
 *
 * Description: Lê o ficheiro que contém o nome das imagens a serem tratadas. 
 * 				Retira o núemro de imagens válidas e um array que contém o nome dessas mesmas imagens
 *
 *****************************************************************************/
void read_image_file(char * imagesDirectory, char * fname);

/******************************************************************************
 * print_image_array()
 *
 * Arguments: char ** images_array
 * 			  int array_size
 * Returns: none
 * Side-Effects: none
 *
 * Description: Escreve no terminal o que images_array contém
 *
 *****************************************************************************/
void print_image_array(char ** images_array, int array_size);

/******************************************************************************
 * free_image_array()
 *
 * Arguments: char ** images_array
 * 			  int array_size
 * Returns: none
 * Side-Effects: none
 *
 * Description: Dá free ao images_array
 *
 *****************************************************************************/
void free_image_array(char ** images_array, int array_size);

/******************************************************************************
 * check_images()
 *
 * Arguments: char * image_string
 * Returns: Devolve um inteiro com valor 1 se encontrar, caso contrário 0 
 * Side-Effects: none
 *
 * Description: Verifica se as imagens existem na pasta fornecida
 *
 *****************************************************************************/
int check_images(char * image_string);

/******************************************************************************
 * create_directories()
 *
 * Arguments: char * images_folder
 * Returns: none
 * Side-Effects: none
 *
 * Description: Cria as respetivas diretorias
 *
 *****************************************************************************/
void create_directories(char * images_folder);