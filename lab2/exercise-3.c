#include <stdio.h>
#include <pthread.h>  
#include <unistd.h> 
#include <stdlib.h>

// Util para o projecto do ano anterior
// Figura 1: Paralelização simples
// Pagina 6 de 11

void * thread_function(void * arg){
    int n = 0;
    long int r = random()%100;
    printf("Start Thread %lu\n", r);
    while(n <10){
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

	while( i < n_threads) {
		pthread_create(&thread_id, NULL,thread_function, NULL);
		thread_id_list[i] = thread_id;
		//pthread_create(&thread_id, NULL,thread_function, NULL);
		i++;
		//pthread_join(thread_id, NULL);
	};

	while( j < n_threads) {
		pthread_join(thread_id_list[j], NULL);
		j++;
	};

	//printf("Carregue em enter para terminar\n");
	//fgets(line, 100, stdin);

	printf("Threads concluidas com sucesso!\n");

	exit(0);
}