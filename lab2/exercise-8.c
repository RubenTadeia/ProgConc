#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h> 

int * rand_num_array;

#define LIMIT 100000000

int n_mult(int n){
	int c = 0;
	for(int i = 0 ; i <LIMIT; i++){
		if(rand_num_array[i]%n == 0)
		c ++;
	}
	return c;
}

void * thread_function(void * arg){
	int input_divisor = *(int *) arg;
	int * input_for_free = (int * ) arg;
	
	//sleep(0.75);

	printf("input_divisor -> %d\n",input_divisor);

	long int resultado = n_mult(input_divisor);

	free(input_for_free);

	return (void *)resultado;
}

int main(){

	rand_num_array = calloc(LIMIT, sizeof(int));
	int n_threads = 5;
	
	int i;
	int j = 0;
	int gamma = 0;
	int divisores[5] = {2, 3, 5, 7, 11};
	//int * divisor = (int *) malloc(sizeof(int));

	pthread_t * thread_id_list = (pthread_t *) calloc (n_threads,sizeof(pthread_t));
	pthread_t thread_id;

	for(i = 0 ; i <LIMIT; i++){
		rand_num_array[i] = random();
	}

	void * thread_ret;
	long int ret_val;

	while( j < n_threads) {
		int * divisor = (int *) malloc(sizeof(int));
		* divisor = divisores[j];
		printf("Valor do divisor = %d\n", *divisor);

		pthread_create(&thread_id, NULL, thread_function, divisor);
		thread_id_list[j] = thread_id;
		
		//pthread_join(thread_id, &thread_ret); // nao queremos isto. Perdemos a paralelizacao
		//ret_val = (long int)thread_ret;
		//printf("Múltiplos de %d -> %ld\n", divisores[j], ret_val);
		j++;
	};

	while( gamma < n_threads) {
		//pthread_join(thread_id_list[j], NULL);

		pthread_join(thread_id_list[gamma], &thread_ret);
		ret_val = (long int) thread_ret;
		printf("Múltiplos de %d -> %ld\n", divisores[gamma], ret_val);;
		gamma++;
	};

	int n_2 = n_mult(2);
	int n_3 = n_mult(3);
	int n_5 = n_mult(5);
	int n_7 = n_mult(7);
	int n_11 = n_mult(11);
	printf("%d %d %d %d %d \n", n_2, n_3, n_5, n_7, n_11);

	free(rand_num_array);
	free(thread_id_list);
	exit(0);

}