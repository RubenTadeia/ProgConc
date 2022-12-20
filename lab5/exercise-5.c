#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define BUFFERSIZE 100

/**
 * @brief program that creates a pipe, writes values to a it and reads them
 * 
 */

// Thread Structure
typedef struct thread_input_info_struct{
	int thread_id;
	int pipe_function;
} thread_input_info;

// THREAD FUNCTION
void * thread_function(void * arg){
	// Variaveis
	thread_input_info * thread_argument = (thread_input_info *) arg;
	char * read_value = (char *) malloc (sizeof(char)*BUFFERSIZE+1);;

	read(thread_argument->pipe_function, read_value, BUFFERSIZE);
	
	printf("Segunda Confirmação: Tamanho da string %ld\n",strlen(read_value));

	printf("\tThread %d just read %s from pipe_fd[0]\n", thread_argument->thread_id , read_value);

	free(read_value);

	return (void *)NULL;
}

// MAIN FUNCTION
int main(){
	// two files descriptiors used to write. read on the pipe
	int pipe_fd[2];
	// INDEX 0 -> READS
	// INDEX 1 -> WRITES

	// initialization of the pipe
	if (pipe(pipe_fd)!=0){
		printf("ERROR: creating the pipe\n");
		exit(-1);
	}
	int n = 0;
	int number_of_threads = 4;
	//int read_value;
	// infinite loop that in each iteration writes a number to the pipe and read it afterwards
	
	// Loop infinite que em cada iterecao escreve na pipe e le de seguida
	//while(1){
	printf("Escreve uma palavra, por favor :) \n");
	char * buffer = (char *) malloc (sizeof(char)*BUFFERSIZE+1);
	// Inicio do loop
	while( fgets(buffer, BUFFERSIZE , stdin) ) /* break with ^D or ^Z */
	{	
		// Variaveis de Threads
		int thread_index = 1;
		
		buffer[strcspn(buffer, "\n")] = 0;
		printf("Going to write %s into pipe_fd[1]\n", buffer);
		printf("Primeira Confirmação: Tamanho da string %ld\n",strlen(buffer));
		//n++;
		//sleep(1);

		//write(pipe_fd[1], &n, sizeof(n));
		write(pipe_fd[1], buffer, BUFFERSIZE);
		sleep(1);
		// pipe_fd[1] corresponded to an entry of data in the pipe
		// &n is a pointer to the data to be written
		// sizeof(n) is the amount of data to write in the pipe

		for (int iterator = 0; iterator < number_of_threads; iterator++){
			pthread_t thread_id;
			thread_input_info * thread_information = (thread_input_info *) malloc (sizeof(thread_input_info));
			thread_information->thread_id = thread_index;
			thread_information->pipe_function = pipe_fd[0];
			pthread_create(&thread_id, NULL, thread_function, thread_information);
			thread_index++;
			
		}
		
		printf("\nVolta a escrever palavras :)\n");

		//read(pipe_fd[0], &read_value, sizeof(read_value));

		// pipe_fd[0] correpsonded to the exit of data in the pipe
		// &n is apointer to variable that will hold the read data
		// sizeof(n) is the ammount of data to be read from the pipe
		// printf("\tJust read %d from pipe_fd[0]\n",read_value);
		n++;
	}
}