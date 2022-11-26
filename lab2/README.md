# 2 LAB
Concurrent Programming

# RESPOSTAS EXERCISE 1

# 1 - How many different values of r there are?

- R: 100 valores

# 2 - Why does each digit (1, 2, 3, …) is repeated by each thread?

- R: Cada thread tem uma função sleep e imprime os número de 1 a 10  

# 3 - What happens to the threads if the user presses enter and exits main?

- R: São abortadas pois o program também o é

# 4 - Read the pthread_create() man page and take note of the various arguments.

- R: 1º argumento - Thread que vamos criar
     2º argumento - Atributos da thread (NULL para que os atributos sejam default)
     3º argumento - Função que cada thread vai estar a executar ao ser criada
     4º argumento - Argumento que se passa para a função de rotina 

# DUVIDAS 

# 1  - Com 2 thread`s o programa imprime a mensagem (prima enter para terminar) antes da 2º thread ser iniciada, porquê?

R:
