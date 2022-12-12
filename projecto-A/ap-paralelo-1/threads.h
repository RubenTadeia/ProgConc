// Libraries
#include "image-lib.h"

/*****************************************************************************/
// Structure
typedef struct thread_input_info_struct{
	char * image_folder;
	int first_image_index;
	int last_image_index;
	int thread_id;
} thread_input_info;

/******************************************************************************
 * thread_function_wm_tn_rs()
 *
 * Arguments: void * arg 
 * Returns: none
 * Side-Effects: none
 *
 * Description: Adds watermark, resize and thumbnail to image
 *
 *****************************************************************************/
void * thread_function_wm_tn_rs(void * arg);

/******************************************************************************
 * get_images_threads_difference()
 *
 * Arguments: int number_images - número de imagens
 * 			  int number_threads - número de threads em que o programa vai executar
 * Returns: 1 (Numero de threads igual ao numero de imagens) , 2 (Numero de threads menor que o numero de imagens)
 * 			3 (Numero de threads maior que o numero de imagens)
 * Side-Effects: none
 *
 * Description: compare number_images with number_threads
 *
 *****************************************************************************/
int get_images_threads_difference(int number_images, int number_threads);
