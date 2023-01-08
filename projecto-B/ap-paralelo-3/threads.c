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
	// Variaveis Globais
	thread_input_info * thread_argument = (thread_input_info *) arg;
	extern char ** images_array;
	extern int pipe_watermark[2];
	extern int pipe_resize[2];
	extern int pipe_thumbnail[2];
	extern int numero_imagens_validas;
	extern int numero_imagens_processadas_watermark;
	extern pthread_mutex_t watermark_mutex;
	
	// Inicio
	printf("Watermark: A Thread %d iniciou e está à espera de imagens...\n",thread_argument->thread_id);

	while (1){
		// Variaveis Locais
		pthread_mutex_lock(&watermark_mutex);
		int index_local = numero_imagens_processadas_watermark;
		pthread_mutex_unlock(&watermark_mutex);

		if(index_local == numero_imagens_validas){
			// Fim
			printf("Watermark: Thread %d Concluida...\n",thread_argument->thread_id);

			// Libertacao de memoria
			free(thread_argument->image_folder);
			free(thread_argument);
			pthread_exit(NULL);
		}
		else{
			int image_array_index; // Variavel Local

			pthread_mutex_lock(&watermark_mutex);
			numero_imagens_processadas_watermark++;
			index_local = numero_imagens_processadas_watermark;
			pthread_mutex_unlock(&watermark_mutex);

			read(pipe_watermark[0], &image_array_index, sizeof(int));

			printf("Watermark: A Thread %d vai processar a imagem %s\n"
					,thread_argument->thread_id,images_array[image_array_index]);

			add_watermark_in_image(images_array[image_array_index],thread_argument->image_folder);

			write(pipe_resize[1], &image_array_index, sizeof(int));
			write(pipe_thumbnail[1], &image_array_index, sizeof(int));
		}
	}
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
	// Variaveis Globais
	thread_input_info * thread_argument = (thread_input_info *) arg;
	extern char ** images_array;
	extern int pipe_resize[2];
	extern int numero_imagens_validas;
	extern int numero_imagens_processadas_resize;
	extern pthread_mutex_t resize_mutex;

	// Inicio
	printf("Resize: A Thread %d iniciou e está à espera de imagens...\n",thread_argument->thread_id);

	while (1){
		// Variaveis Locais
		pthread_mutex_lock(&resize_mutex);
		int index_local = numero_imagens_processadas_resize;
		pthread_mutex_unlock(&resize_mutex);

		if(index_local == numero_imagens_validas){
			// Fim
			printf("Resize: Thread %d Concluida...\n",thread_argument->thread_id);

			// Libertacao de memoria
			free(thread_argument->image_folder);
			free(thread_argument);
			pthread_exit(NULL);
		}
		else{
			int image_array_index; // Variavel Local

			pthread_mutex_lock(&resize_mutex);
			numero_imagens_processadas_resize++;
			index_local = numero_imagens_processadas_resize;
			pthread_mutex_unlock(&resize_mutex);

			read(pipe_resize[0], &image_array_index, sizeof(int));

			printf("Resize: A Thread %d vai processar a imagem %s\n"
					,thread_argument->thread_id,images_array[image_array_index]);

			add_resize_to_image(images_array[image_array_index],thread_argument->image_folder);

			//write(pipe_thumbnail[1], &image_array_index, sizeof(int));
		}
	}
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
	// Variaveis Globais
	thread_input_info * thread_argument = (thread_input_info *) arg;
	extern char ** images_array;
	extern int pipe_thumbnail[2];
	extern int numero_imagens_validas;
	extern int numero_imagens_processadas_thumbnail;
	extern pthread_mutex_t thumbnail_mutex;

	// Inicio
	printf("Thumbnail: A Thread %d iniciou e está à espera de imagens...\n",thread_argument->thread_id);

	while (1){
		// Variaveis Locais
		pthread_mutex_lock(&thumbnail_mutex);
		int index_local = numero_imagens_processadas_thumbnail;
		pthread_mutex_unlock(&thumbnail_mutex);

		if(index_local == numero_imagens_validas){
			// Fim
			printf("Thumbnail: Thread %d Concluida...\n",thread_argument->thread_id);

			// Libertacao de memoria
			free(thread_argument->image_folder);
			free(thread_argument);
			pthread_exit(NULL);
		}
		else{
			int image_array_index; // Variavel Local

			pthread_mutex_lock(&thumbnail_mutex);
			numero_imagens_processadas_thumbnail++;
			index_local = numero_imagens_processadas_thumbnail;
			pthread_mutex_unlock(&thumbnail_mutex);

			read(pipe_thumbnail[0], &image_array_index, sizeof(int));
			
			printf("Thumbnail: A Thread %d vai processar a imagem %s\n"
					,thread_argument->thread_id,images_array[image_array_index]);

			add_thumbnail_to_image(images_array[image_array_index],thread_argument->image_folder);
		}
	}
}
