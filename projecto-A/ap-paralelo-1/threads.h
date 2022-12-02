/* Libraries*/
#include "image-lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

/*****************************************************************************/
/* the directories wher output files will be placed */
#define RESIZE_DIR "/Resize-dir/"
#define THUMB_DIR "/Thumbnail-dir/"
#define WATER_DIR "/Watermark-dir/"

/*****************************************************************************/
// Structure
typedef struct thread_input_info_struct{
	char * image_folder;
	int first_image_index;
	int last_image_index;
} thread_input_info;

/* Functions */
void * thread_function_wm_tn_rs(void * arg);

int get_images_threads_difference(int number_images, int number_threads);