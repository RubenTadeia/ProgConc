#include <stdio.h>
#include <pthread.h>  
#include <unistd.h> 
#include <stdlib.h>
long int n = 0;

void * thread_function(void * arg){
	long int r = random()%100;

	long int input_ponteiro_inteiro = *(int *) arg;
	int * input_for_free = (int * ) arg;

	printf("Start Thread %lu\n", r);
	while(input_ponteiro_inteiro < 10){
		//sleep(1);
		input_ponteiro_inteiro++;
		printf("inside Thread %lu %ld\n", r, n);
	}
	printf("End Thread %lu\n", r);

	free(input_for_free);

	return (void *)input_ponteiro_inteiro;
}

int main(){
	char line[100];
	int n_threads;
	printf("How many threads: ");
	fgets(line, 100, stdin);
	sscanf(line, "%d", &n_threads);
	
	pthread_t * thread_id_list = (pthread_t *) calloc (n_threads,sizeof(pthread_t));
	pthread_t thread_id;

	int i = 0;
	int gamma = 0;

	void * thread_ret;
	long int ret_val;

	while( i < n_threads) {
		int * ponteiro_inteiro_a_zero = (int *) malloc(sizeof(int));
		* ponteiro_inteiro_a_zero = 0;
		//printf("Valor do divisor = %d\n", *ponteiro_inteiro_a_zero);
		pthread_create(&thread_id, NULL,thread_function, ponteiro_inteiro_a_zero);
		thread_id_list[i] = thread_id;
		i++;
	};

	while( gamma < n_threads) {
		pthread_join(thread_id_list[gamma], &thread_ret);
		ret_val = (long int) thread_ret;
		n = n + ret_val;
		gamma++;
	};

	//printf("Carregue em enter para terminar\n");
	//fgets(line, 100, stdin);
	free(thread_id_list);
	printf("\n\nConfirmation:\nn_threads x 10 = %d\nn value = %ld\n",n_threads*10,n);
	exit(0);
}