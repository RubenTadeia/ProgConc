// Libraries
#include "threads.h"

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
void * thread_function_wm(void * arg){
	// Variaveis
	thread_input_info * thread_argument = (thread_input_info *) arg;
	extern char ** images_array;

	// Variaveis de tempo
	clock_t start_t, end_t;
	clock_t end_time_watermark;
	start_t = clock();
   	double time_taken = 0;

	// Inicio
	printf("DEBUG THREAD: A Thread %d começou agora...\n",thread_argument->thread_id);


	// Aqui dentro deste if a thread tem pelo menos uma imagem para processar
	if (thread_argument->first_image_index != -1){
		int iterator;
		for (iterator = thread_argument->first_image_index; iterator <= thread_argument->last_image_index; iterator++){
			// Aqui dentro chamamos a funcao de tratamento de imagens
			printf("DEBUG THREAD: Thread numero = %d vai processar a imagem %s\n"
				, thread_argument->thread_id, images_array[iterator]);

			clock_t start_image_water = clock();
			add_watermark_in_image(images_array[iterator],thread_argument->image_folder);
			end_time_watermark = clock();
			time_taken = (double)(end_time_watermark - start_image_water) / CLOCKS_PER_SEC; // calculate the elapsed time
			printf("WATERMARK: A Thread %d demorou %f segundos a executar a imagem %s\n"
				, thread_argument->thread_id, time_taken,images_array[iterator]);
			
		}
	}
	else{
		// Aqui dentro significa que a thread nao tem imagem para processar
		printf("DEBUG THREAD: Thread numero = %d não tem imagem para processar\n", thread_argument->thread_id);
	}

	/*float * resultado = malloc(sizeof(float));
	*resultado = 1;*/
	
	// Fim
	printf("DEBUG THREAD: Thread %d Concluida - A libertar memoria ...\n"
			,thread_argument->thread_id);

	// Tempo
	end_t = clock();
	time_taken = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("A Thread %d demorou %f segundos a executar\n", thread_argument->thread_id, time_taken);

	// Libertacao de memoria
	free(thread_argument->image_folder);
	free(thread_argument);

	return (void *)NULL;
}

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
void * thread_function_rs(void * arg){
	// Variaveis
	thread_input_info * thread_argument = (thread_input_info *) arg;
	extern char ** images_array;

	// Variaveis de tempo
	clock_t start_t, end_t;
	clock_t end_time_resize;
	start_t = clock();
   	double time_taken = 0;

	// Inicio
	printf("DEBUG THREAD: A Thread %d começou agora...\n",thread_argument->thread_id);

	// Aqui dentro deste if a thread tem pelo menos uma imagem para processar
	if (thread_argument->first_image_index != -1){
		int iterator;
		for (iterator = thread_argument->first_image_index; iterator <= thread_argument->last_image_index; iterator++){
			// Aqui dentro chamamos a funcao de tratamento de imagens
			printf("DEBUG THREAD: Thread numero = %d vai processar a imagem %s\n"
				, thread_argument->thread_id, images_array[iterator]);

			clock_t start_image_resize = clock();
			add_resize_to_image(images_array[iterator],thread_argument->image_folder);
			end_time_resize = clock();
			time_taken = (double)(end_time_resize - start_image_resize) / CLOCKS_PER_SEC; // calculate the elapsed time
			printf("RESIZE: A Thread %d demorou %f segundos a executar a imagem %s\n",
				 thread_argument->thread_id, time_taken,images_array[iterator]);
		} 
	}
	else{
		// Aqui dentro significa que a thread nao tem imagem para processar
		printf("DEBUG THREAD: Thread numero = %d não tem imagem para processar\n", thread_argument->thread_id);
	}

	/*float * resultado = malloc(sizeof(float));
	*resultado = 1;*/

	// Fim
	printf("DEBUG THREAD: Thread %d Concluida - A libertar memoria ...\n"
			,thread_argument->thread_id);

	// Tempo
	end_t = clock();
	time_taken = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("A Thread %d demorou %f segundos a executar\n", thread_argument->thread_id, time_taken);

	// Libertacao de memoria
	free(thread_argument->image_folder);
	free(thread_argument);

	return (void *)NULL;
}

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
void * thread_function_tn(void * arg){
	// Variaveis
	thread_input_info * thread_argument = (thread_input_info *) arg;
	extern char ** images_array;

	// Variaveis de tempo
	clock_t start_t, end_t;
	clock_t end_time_thumbnail;
	start_t = clock();
   	double time_taken = 0;

	// Inicio
	printf("DEBUG THREAD: A Thread %d começou agora...\n",thread_argument->thread_id);

	// Aqui dentro deste if a thread tem pelo menos uma imagem para processar
	if (thread_argument->first_image_index != -1){
		int iterator;
		for (iterator = thread_argument->first_image_index; iterator <= thread_argument->last_image_index; iterator++){

			// Aqui dentro chamamos a funcao de tratamento de imagens
			printf("DEBUG THREAD: Thread numero = %d vai processar a imagem %s\n"
				, thread_argument->thread_id, images_array[iterator]);

			clock_t start_image_thumbnail = clock();
			add_thumbnail_to_image(images_array[iterator],thread_argument->image_folder);
			end_time_thumbnail = clock();
			time_taken = (double)(end_time_thumbnail - start_image_thumbnail) / CLOCKS_PER_SEC; // calculate the elapsed time
			printf("THUMBNAIL: A Thread %d demorou %f segundos a executar a imagem %s\n", 
				thread_argument->thread_id, time_taken,images_array[iterator]);
		}
	}
	else{
		// Aqui dentro significa que a thread nao tem imagem para processar
		printf("DEBUG THREAD: Thread numero = %d não tem imagem para processar\n", thread_argument->thread_id);
	}

	/*float * resultado = malloc(sizeof(float));
	*resultado = 1;*/

	// Fim
	printf("DEBUG THREAD: Thread %d Concluida - A libertar memoria ...\n"
			,thread_argument->thread_id);

	// Tempo
	end_t = clock();
	time_taken = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("A Thread %d demorou %f segundos a executar\n", thread_argument->thread_id, time_taken);

	// Libertacao de memoria
	free(thread_argument->image_folder);
	free(thread_argument);

	return (void *)NULL;
}
