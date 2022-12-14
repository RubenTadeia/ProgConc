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
 * thread_function_wm()
 *
 * Arguments: void * arg 
 * Returns: none
 * Side-Effects: none
 *
 * Description: Adds watermark to image
 *
 *****************************************************************************/
void * thread_function_wm(void * arg);

/******************************************************************************
 * thread_function_rs()
 *
 * Arguments: void * arg 
 * Returns: none
 * Side-Effects: none
 *
 * Description: Add resize to image given the filename but uses 
 * 				a watermark file as inputfile
 *
 *****************************************************************************/
void * thread_function_rs(void * arg);

/******************************************************************************
 * thread_function_rs_with_wm()
 *
 * Arguments: void * arg 
 * Returns: none
 * Side-Effects: none
 *
 * Description: Add resize to image given the filename but does
 * 				watermark on the inputfile and doesn't save it
 *
 *****************************************************************************/
void * thread_function_rs_with_wm(void * arg);

/******************************************************************************
 * thread_function_tn()
 *
 * Arguments: void * arg 
 * Returns: none
 * Side-Effects: none
 *
 * Description: Add thumbnail to image given the filename but uses 
 * 				a watermark file as inputfile
 *
 *****************************************************************************/
void * thread_function_tn(void * arg);

/******************************************************************************
 * thread_function_tn_with_wm()
 *
 * Arguments: void * arg 
 * Returns: none
 * Side-Effects: none
 *
 * Description: Add thumbnail to image given the filename but does
 * 				watermark on the inputfile and doesn't save it
 *
 *****************************************************************************/
void * thread_function_tn_with_wm(void * arg);

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
