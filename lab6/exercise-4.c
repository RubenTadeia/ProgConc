#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define LENGTH_ARRAY 100000
int rand_num_array[LENGTH_ARRAY];

int prime_array[LENGTH_ARRAY]; // exercise 4
int prime_array_index = 0; //exercise 4

int next_random = 0; //exercise 1

// Creation of the mutex
pthread_mutex_t mutex;

#define N_THREADS 5
/**
 * @brief funcao que verifica se um número é primo
 * 
 * @param value valor a verificar se é primo
 * @return int 1 se value for primo 0, se não for primo
 */
int verify_prime( int value){

	int divisor = 2;
	if(value < 4){
		return 1;
	}
	while (value%divisor != 0){
		divisor ++;
	}
	if (value == divisor){
		return 1;
	}else{
		return 0;
	}
}
/**
 * @brief código da thread. itera sobre o array rand_num_array e verifica se os numero são primos
 * 
 * @param arg indica da thread. É usado para cada threda saber que valores ler do array
 * @return void* numero de primos encontrados
 */
void * inc_thread(void * arg){

	int int_arg = *(int *) arg;

	int partial_count = 0;
	long int n_primes = 0;

	//int i = 0;

	//while(i<LENGTH_ARRAY){
	while(next_random<LENGTH_ARRAY){
		if(verify_prime(rand_num_array[next_random]) == 1){
			//printf("\t\t%d %lu is prime\n", i,rand_num_array[i]);
			n_primes ++;
			pthread_mutex_lock(&mutex);
			prime_array[prime_array_index] = rand_num_array[next_random];
			prime_array_index++;
			pthread_mutex_unlock(&mutex);
		}else{
			//printf("\t\t%d %lu is not prime\n", i,rand_num_array[i]);
		}
		pthread_mutex_lock(&mutex);
		next_random++;
		partial_count++;
		pthread_mutex_unlock(&mutex);
	}
	printf("Thread %d found %ld primes on %d numbers\n", int_arg, n_primes, partial_count);

	pthread_exit((void *)n_primes);
}

/**
 * @brief programa principal que cria várias threads para verificarem se os interiso num array sao primos ou nao
 * 
 * @return int 
 */
int main(){

	pthread_mutex_init(&mutex, NULL);

	// Inicializar o prime_array
	for(int i = 0 ; i < LENGTH_ARRAY; i++){
		prime_array[i] = -1;
	}

	int total_primes = 0;

	for(int  i= 0 ; i < LENGTH_ARRAY; i++){
		// if the following line is uncommented there will be 59 primes in the array
		//rand_num_array[i] = rand()/10; 
		// if the following line is uncommented there will be 170 prime numbers
		rand_num_array[i] = i; 
	}

	pthread_t t_id[N_THREADS];
	for(int i = 0 ; i < N_THREADS; i++){
		pthread_create(&t_id[i], NULL, inc_thread, &i);
	}


	long int ret_val;
	void * thread_ret;
	for(int i = 0 ; i < N_THREADS; i++){
		pthread_join(t_id[i], &thread_ret);
		ret_val = (long int) thread_ret;
		printf("From Join: Thread %d found %ld primes\n", i, ret_val);
	}

	// Inicializar o prime_array
	for(int i = 0 ; i < LENGTH_ARRAY; i++){
		if(prime_array[i] == -1){
			break;
		}
		else{
			total_primes++;
		}
	}

	printf("main - total primes %i\n", total_primes); // exercise 4
	pthread_mutex_destroy(&mutex);

	exit(0);
}