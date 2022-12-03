/* Libraries*/
#include "threads.h"

void * thread_function_wm_tn_rs(void * arg){
	//int input_divisor = *(int *) arg;
	//thread_input_info * thread_argument = *(thread_input_info *) arg;
	//int * input_for_free = (int * ) arg;

	//printf("input_divisor -> %d\n",input_divisor);
	//printf("DEBUG THREAD: Thread %d A iniciar...",thread_argument->thread_id);

	long int resultado = 1;

	//free(input_for_free);

	//printf("DEBUG THREAD: Thread %d Concluida...",thread_argument->thread_id);

	return (void *)resultado;
}

int get_images_threads_difference(int number_images, int number_threads){
	// Numero de threads igual ao numero de imagens
	if(number_images == number_threads){
		return 1;
	}
	// Numero de threads menor que o numero de imagens
	else if(number_images > number_threads){
		return 2;
	}
	// Numero de threads maior que o numero de imagens
	else{
		return 3;
	}
}