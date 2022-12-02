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
typedef struct image_info_struct{
	char * image_folder;
	char * image_name;
} image_info;

/* Functions */
void * thread_function_wm_tn_rs(void * arg);