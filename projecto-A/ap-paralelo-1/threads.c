/* Libraries*/
#include "threads.h"

void * thread_function_wm_tn_rs(void * arg){
	// Variaveis
	thread_input_info * thread_argument = (thread_input_info *) arg;
	extern char ** images_array;

	// Variaveis de tempo
	//struct timespec begin_thread_time, end_thread_time;
	//clock_gettime(CLOCK_REALTIME, &begin_thread_time);

	// Inicio
	printf("DEBUG THREAD: A Thread %d começou agora...\n",thread_argument->thread_id);

	//printf("DEBUG THREAD: Thread numero = %d\n", thread_argument->thread_id);
	printf("DEBUG THREAD: Thread primeiro index = %d\n", thread_argument->first_image_index);
	printf("DEBUG THREAD: Thread ultimo index = %d\n", thread_argument->last_image_index);
	//printf("DEBUG THREAD: Nome do caminho = %s\n\n", thread_argument->image_folder);

	// Aqui dentro deste if a thread tem pelo menos uma imagem para processar
	if (thread_argument->first_image_index != -1){
		int iterator;
		for (iterator = thread_argument->first_image_index; iterator <= thread_argument->last_image_index; iterator++){
			// Aqui dentro chamamos a funcao de tratamento de imagens
			printf("DEBUG THREAD: Thread numero = %d vai processar a imagem %s\n"
				, thread_argument->thread_id, images_array[iterator]);
		}
	}
	else{
		// Aqui dentro significa que a thread nao tem imagem para processar
		printf("DEBUG THREAD: Thread numero = %d não tem imagem para processar\n", thread_argument->thread_id);
	}

	long int resultado = 1;
	
	// Fim
	printf("DEBUG THREAD: Thread %d Concluida - A libertar memoria ...\n"
			,thread_argument->thread_id);
	//clock_gettime(CLOCK_REALTIME, &end_thread_time); 
	//printf("DEBUG THREAD: Thread %d Concluida em %lld.%.9ld - A libertar memoria ...\n"
			//,thread_argument->thread_id,(long long)end_thread_time.tv_sec, end_thread_time.tv_nsec);

	// Libertacao de memoria
	free(thread_argument->image_folder);
	free(thread_argument);

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