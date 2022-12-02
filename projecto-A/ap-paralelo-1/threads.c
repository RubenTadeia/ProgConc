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