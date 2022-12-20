#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
    while (1){
        // STEP 4
        //printf("AQUI!\n");
        read(pipe_fd[0], &number, sizeof(int));
        if(verify_prime(number) == 1){
            printf("\t\t%d is prime\n", number);
            local_n_primes ++;
        }else{
            //printf("\t\t%d is not prime\n", number);
        }
    } 
    printf("Thread %d found %d primes on %d processed randoms\n", int_arg, local_n_primes, local_count);
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

    //ciclo para criar as várias threads que irão verificar os numeros
    pthread_t t_id[N_THREADS];

    for(int i = 0 ; i < N_THREADS; i++){
        int * int_p = malloc(sizeof(int));
        *int_p = i;
        pthread_create(&t_id[i], NULL, verify_primes_thread, int_p);
    }

    int number;
    //int n_primes = 0;
    for(int i = 0; i< total_randoms; i++){
        number = random();
        //STEP 3
        write(pipe_fd[1], &number, sizeof(int));
    }

    //ciclo que esperara a terminação das threads
    for(int i = 0 ; i < N_THREADS; i++){
        pthread_join(t_id[i],  NULL);
    }

    exit(0);
}
