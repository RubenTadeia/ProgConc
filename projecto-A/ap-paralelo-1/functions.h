/* Libraries */
#include "threads.h"

/* Function to read_file*/
void check_arguments (int argc, char * argv[]);

/* Function to read_file*/
void read_image_file(char * imagesDirectory, char * fname);

void print_image_array(char ** images_array, int array_size);

void free_image_array(char ** images_array, int array_size);

int check_images(char * image_string);

void create_directories(char * images_folder);