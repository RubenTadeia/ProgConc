/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <ctype.h>

/* Function to read_file*/
void check_arguments (int argc, char * argv[]);

/* Function to read_file*/
void read_image_file(char * imagesDirectory, char * fname);

void print_image_array(char ** images_array, int array_size);

void free_image_array(char ** images_array, int array_size);

int check_images(char * image_string);