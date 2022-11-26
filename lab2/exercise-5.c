#include <stdio.h>
#include <pthread.h>  
#include <unistd.h> 
#include <stdlib.h>

// Util para o projecto do ano anterior
// Figura 1: Paralelização simples
// Pagina 6 de 11

void * thread_function(void * arg){
	int n = 0;

	int int_val = *(int *) arg;

	long int r = random()%100;
	printf("Start Thread %lu\n", r);
	while(n < int_val){
		sleep(1);
		n++;
		printf("inside Thread %lu %d\n", r, n);
	}
	printf("End Thread %lu\n", r);
	return (void *)r;
}

int main(){
	char line[100];
	int n_threads;
	int j = 0;
	int i = 0;
	printf("How many threads: ");
	fgets(line, 100, stdin);
	sscanf(line, "%d", &n_threads);
	pthread_t * thread_id_list = (pthread_t *) calloc (n_threads,sizeof(pthread_t));
	pthread_t thread_id;

	// Exercise 4 Variables
	void * thread_ret;
	long int ret_val;

	// New seed every run
	srand(time(NULL));

    // Exercise 5 Variables
    int * thr_val = malloc(sizeof(int));
    *thr_val = rand() % 5;
	printf("O preço certo da montra final e o numero random é -> %d\n", *thr_val);
    
	while( i < n_threads) {
		pthread_create(&thread_id, NULL,thread_function, thr_val);
		//pthread_create(&thread_id_list[i], NULL,thread_function, thr_val);	
		thread_id_list[i] = thread_id;
		//pthread_create(&thread_id, NULL,thread_function, NULL);
		i++;
		//pthread_join(thread_id, NULL);
	};

	while( j < n_threads) {
		//pthread_join(thread_id_list[j], NULL);
		pthread_join(thread_id_list[j], &thread_ret);
		printf("Inteiro da thread -> %ld\n\n", (long int) thread_ret);
		ret_val = (long int) thread_ret;
		printf("Repetição do Inteiro da thread -> %ld\n\n", (long int) ret_val);
		//printf("miau\n");
		j++;
	};

	//printf("Carregue em enter para terminar\n");
	//fgets(line, 100, stdin);

	printf("Threads concluidas com sucesso!\n");

	exit(0);
}