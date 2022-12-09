/* Libraries*/
#include "threads.h"

// Function that only does watermark
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

	float * resultado = malloc(sizeof(float));
	*resultado = 1;
	
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

	return (void *)resultado;
}

// Function that does watermark and resize
void * thread_function_wm_rs(void * arg){
	// Variaveis
	thread_input_info * thread_argument = (thread_input_info *) arg;
	extern char ** images_array;

	// Variaveis de tempo
	clock_t start_t, end_t;
	clock_t end_time_resize, end_time_watermark;
	start_t = clock();
   	double time_taken = 0;

	// Inicio
	printf("DEBUG THREAD: A Thread %d começou agora...\n",thread_argument->thread_id);

	//printf("DEBUG THREAD: Thread numero = %d\n", thread_argument->thread_id);
	//printf("DEBUG THREAD: Thread primeiro index = %d\n", thread_argument->first_image_index);
	//printf("DEBUG THREAD: Thread ultimo index = %d\n", thread_argument->last_image_index);
	//printf("DEBUG THREAD: Nome do caminho = %s\n\n", thread_argument->image_folder);

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
			
			clock_t start_image_resize = clock();
			add_resize_to_image(images_array[iterator],thread_argument->image_folder);
			end_time_resize = clock();
			time_taken = (double)(end_time_resize - start_image_resize) / CLOCKS_PER_SEC; // calculate the elapsed time
			printf("RESIZE: A Thread %d demorou %f segundos a executar a imagem %s\n",
				 thread_argument->thread_id, time_taken,images_array[iterator]);
		}
		// Para que serve este IF? 
		// Ora este if serve apenas para a thread 2, dar a volta e recomeçar nas primeiras imagens
		if (thread_argument->thread_id == 2){
			int iterator_t2;
			for (iterator_t2 = 0; iterator_t2 < thread_argument->first_image_index; iterator_t2++){
				// Aqui dentro chamamos a funcao de tratamento de imagens
				printf("DEBUG THREAD: Thread numero = %d vai processar a imagem %s\n"
					, thread_argument->thread_id, images_array[iterator_t2]);

				clock_t start_image_water = clock();
				add_watermark_in_image(images_array[iterator_t2],thread_argument->image_folder);
				end_time_watermark = clock();
				time_taken = (double)(end_time_watermark - start_image_water) / CLOCKS_PER_SEC; // calculate the elapsed time
				printf("WATERMARK: A Thread %d demorou %f segundos a executar a imagem %s\n"
					, thread_argument->thread_id, time_taken,images_array[iterator_t2]);
				
				clock_t start_image_resize = clock();
				add_resize_to_image(images_array[iterator_t2],thread_argument->image_folder);
				end_time_resize = clock();
				time_taken = (double)(end_time_resize - start_image_resize) / CLOCKS_PER_SEC; // calculate the elapsed time
				printf("RESIZE: A Thread %d demorou %f segundos a executar a imagem %s\n",
					thread_argument->thread_id, time_taken,images_array[iterator_t2]);
			}
		}
	}
	else{
		// Aqui dentro significa que a thread nao tem imagem para processar
		printf("DEBUG THREAD: Thread numero = %d não tem imagem para processar\n", thread_argument->thread_id);
	}

	float * resultado = malloc(sizeof(float));
	*resultado = 1;
	
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

	return (void *)resultado;
}

// Function that does watermark and thumbnail
void * thread_function_wm_tn(void * arg){
	// Variaveis
	thread_input_info * thread_argument = (thread_input_info *) arg;
	extern char ** images_array;

	// Variaveis de tempo
	clock_t start_t, end_t;
	clock_t end_time_thumbnail, end_time_watermark;
	start_t = clock();
   	double time_taken = 0;

	// Inicio
	printf("DEBUG THREAD: A Thread %d começou agora...\n",thread_argument->thread_id);

	//printf("DEBUG THREAD: Thread numero = %d\n", thread_argument->thread_id);
	//printf("DEBUG THREAD: Thread primeiro index = %d\n", thread_argument->first_image_index);
	//printf("DEBUG THREAD: Thread ultimo index = %d\n", thread_argument->last_image_index);
	//printf("DEBUG THREAD: Nome do caminho = %s\n\n", thread_argument->image_folder);

	// Aqui dentro deste if a thread tem pelo menos uma imagem para processar
	if (thread_argument->first_image_index != -1){
		int iterator;
		for (iterator = thread_argument->first_image_index; iterator >= thread_argument->last_image_index; iterator--){
			
			// Aqui dentro chamamos a funcao de tratamento de imagens
			printf("DEBUG THREAD: Thread numero = %d vai processar a imagem %s\n"
				, thread_argument->thread_id, images_array[iterator]);

			clock_t start_image_water = clock();
			add_watermark_in_image(images_array[iterator],thread_argument->image_folder);
			end_time_watermark = clock();
			time_taken = (double)(end_time_watermark - start_image_water) / CLOCKS_PER_SEC; // calculate the elapsed time
			printf("WATERMARK: A Thread %d demorou %f segundos a executar a imagem %s\n"
				, thread_argument->thread_id, time_taken,images_array[iterator]);
			
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

	float * resultado = malloc(sizeof(float));
	*resultado = 1;
	
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

	return (void *)resultado;
}

// Function that does watermark, thumbnail and resize
void * thread_function_wm_tn_rs(void * arg){
	// Variaveis
	thread_input_info * thread_argument = (thread_input_info *) arg;
	extern char ** images_array;

	// Variaveis de tempo
	clock_t start_t, end_t;
	clock_t end_time_resize, end_time_thumbnail, end_time_watermark;
	start_t = clock();
   	double time_taken = 0;

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

			clock_t start_image_water = clock();
			add_watermark_in_image(images_array[iterator],thread_argument->image_folder);
			end_time_watermark = clock();
			time_taken = (double)(end_time_watermark - start_image_water) / CLOCKS_PER_SEC; // calculate the elapsed time
			printf("WATERMARK: A Thread %d demorou %f segundos a executar a imagem %s\n"
				, thread_argument->thread_id, time_taken,images_array[iterator]);
			
			clock_t start_image_resize = clock();
			add_resize_to_image(images_array[iterator],thread_argument->image_folder);
			end_time_resize = clock();
			time_taken = (double)(end_time_resize - start_image_resize) / CLOCKS_PER_SEC; // calculate the elapsed time
			printf("RESIZE: A Thread %d demorou %f segundos a executar a imagem %s\n",
				 thread_argument->thread_id, time_taken,images_array[iterator]);
			
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

	float * resultado = malloc(sizeof(float));
	*resultado = 1;
	
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