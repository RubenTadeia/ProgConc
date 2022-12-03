/* Libraries*/
#include "image-lib.h"

/*****************************************************************************/
// Structure
typedef struct thread_input_info_struct{
	char * image_folder;
	int first_image_index;
	int last_image_index;
	int thread_id;
} thread_input_info;

/* Functions */
void * thread_function_wm_tn_rs(void * arg);

int get_images_threads_difference(int number_images, int number_threads);
