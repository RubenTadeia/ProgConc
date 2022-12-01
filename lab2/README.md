# 2 LAB
Concurrent Programming

---

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

# RESPOSTAS EXERCISE 2.1

# 1 - Whats is difference in the output of this program compared with test-threads_1.c?
- R: A diferença é que é impresso o resultado de uma thread de cada vez.

# 2 - What is different in the source code?
- R: É a chamada da função **pthread_join(thread_id, NULL);** que aguarda que a thread termine a sua função.

# 3 - Does test-threads_2.c takes advantage of multiple processors?
- R: Não. Porque, emboram existam mais processadores, eles têm sempre que esperar que a thread anterior termine para começarem a nova.

---

# RESPOSTAS EXERCISE 4.2 Exercise 6 – bad way to send data into threads.

# 1 - Execute the program various times with various numbers of threads and try to explain what is happening.
- R: Nós diriamos... Que o problema está em utilizar uma variável que é alterada aquando a criação de várias threads. Existindo um possível Deadlock, porque estamos a tentar aceder a uma varial comum a várias threads, não sendo possível dizer qual é o seu valor num periodo específico no tempo.

---

# RESPOSTAS EXERCISE 5 - Shared Data

# 1 - What happens to the variable n?
- R: A variavel n vai incrementando ao longo do tempo. A variavel n vai ter um valor superior a 10 (consoante as threads que dermos de input), porque como existe um sleep dentro da linha 10 -> **while(n <10){**, todas as threads vão conseguir entrar no ciclo e **SÓ DEPOIS** é que incrementam o valor da variável n

# 2 - Where is variable n declared?
- R: A variavel n está declarada fora do main, e por isso acaba por ser uma variável global em todo o código.

---


# DUVIDAS 

# 1  - Com 2 thread's o programa imprime a mensagem (prima enter para terminar) antes da 2º thread ser iniciada, porquê?

- R: Isso é porque as "threads têm vontade própria" e fazem as suas tarefas em alturas consoante a "vontade" do sistema operativo.

# 2  - No exercise 3 pedido neste laboratório, quando pedem para remover o fgets. A que fgets se referem?

- R: É o ultimo fgets... :) Para ficar à espera de um input do utilizador, caso contrário, o programa para e não vemos output.