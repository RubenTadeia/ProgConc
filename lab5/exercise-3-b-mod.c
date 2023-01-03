#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//GLOBAL VARIABLE
int counter_random_number_dec;

// Creation of the mutex
pthread_mutex_t mutex;

//STEP 1
int pipe_fd[2];

#define N_THREADS 4
/**
 * @brief funcao que rverifica se um n;umero é primo
 * 
 * @param value valor a verificar se é primo
 * @return int 1 se value for primo 0, se não for primo
 */
int verify_prime(int value){

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
 * @brief código da thread que verificas se os numeros são primos
 * 
 * @param arg indice da thread.
 */
void * verify_primes_thread(void * arg){

	int int_arg = *((int*) arg);
	int number;
	int local_count = 0;
	int local_n_primes = 0;

	//Mutex	
	pthread_mutex_lock(&mutex);
	int aux_counter = counter_random_number_dec;
	counter_random_number_dec--;
	pthread_mutex_unlock(&mutex);

	while (1){
		read(pipe_fd[0], &number, sizeof(int));

		pthread_mutex_lock(&mutex);
		aux_counter = counter_random_number_dec;
		counter_random_number_dec--;
		pthread_mutex_unlock(&mutex);

		//ALTERADO
		if(verify_prime(number) == 1){
			printf("\t\t%d is prime\n", number);
			local_n_primes ++;
			local_count++;
		}else{
			local_count++;
			//printf("\t\t%d is not prime\n", number);
		}

		// STEP 4
		if( aux_counter == 0){
			printf("Sair da thread %d porque o contador vale %d\n", int_arg, aux_counter);
			printf("Thread %d found %d primes on %d processed randoms\n", int_arg, local_n_primes, local_count);
			pthread_exit(NULL);
		}
	} 
	printf("Thread %d found %d primes on %d processed randoms ULTIMA\n", int_arg, local_n_primes, local_count);
	pthread_exit(NULL);

}

/**
 * @brief programa principal que vários numeros aleatórios e verifica se são primos
 * 
 * @return int 
 */
int main(){

	// STEP 2
	if (pipe(pipe_fd)!=0){
		printf("ERROR: creating the pipe\n");
		exit(-1);
	}

	int total_randoms;
	printf("Type how many random numbers should be verified ");
	if (scanf("%d", &total_randoms)!= 1 && total_randoms<1){
		printf("invalid Number\n");
		exit(-1);
	}

	counter_random_number_dec = total_randoms; 

	//ciclo para criar as várias threads que irão verificar os numeros
	pthread_t t_id[N_THREADS];

	for(int i = 0 ; i < N_THREADS; i++){
		int * int_p = malloc(sizeof(int));
		*int_p = i+1;
		pthread_create(&t_id[i], NULL, verify_primes_thread, int_p);
	}

	int number;
	//int n_primes = 0;
	for(int i = 0; i< total_randoms; i++){
		number = random();
		//printf("Number random -> %d\n", number);
		//STEP 3
		write(pipe_fd[1], &number, sizeof(int));
	}

	//ciclo que esperara a terminação das threads
	for(int i = 0 ; i < N_THREADS; i++){
		pthread_join(t_id[i],  NULL);
	}

	exit(0);
}
