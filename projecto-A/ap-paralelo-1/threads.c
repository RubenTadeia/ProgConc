/* Libraries*/
#include "threads.h"

void * thread_function_wm_tn_rs(void * arg){
	//int input_divisor = *(int *) arg;
	//int * input_for_free = (int * ) arg;
	
	//sleep(0.75);

	//printf("input_divisor -> %d\n",input_divisor);

	long int resultado = 1;

	//free(input_for_free);

	return (void *)resultado;
}

int get_images_threads_difference(int number_images, int number_threads){
	// Numero de threads igual ao numero de imagens
	if(number_images == number_threads){
		return 1;
	}
	// Numero de threads menor que o numero de imagens
	else if(number_images < number_threads){
		return 2;
	}
	// Numero de threads maior que o numero de imagens
	else{
		return 3;
	}
}