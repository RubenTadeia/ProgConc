// Libraries
#include "image-lib.h"

/*****************************************************************************/
// Structure
typedef struct thread_input_info_struct{
	char * image_folder;
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
