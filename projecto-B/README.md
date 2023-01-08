# To Do List Projecto - B

- [X] **O Inicio** -> Aproveitamento do código da parte A do projecto
- [X] **Funcionalidade** -> Funções das imagens funcionam da seguinte Forma. **1º** watermark | **2º** resize + watermark | **3º** thumbnail + watermark 
- [X] **Funcionalidade** -> Existe uma função de thread para cada transformação, e existe um loop de joins apenas no fim.
- [X] **Pipes** -> Cada thread espera por dados no pipe; depois de ler a referência de uma imagem, a thread, processa-a, grava o resultado e notifica o estágio seguinte (no caso das threads do estágio watermark e resize).
- [X] **Optimizações** -> Os alunos poderão definir as estruturas de dados que considerarem convenientes, garantindo sempre que a referência/nome da imagem a processar em cada iteração das threads/estágio é lida a partir de pipes.
- [ ] **Optimizações** -> Se desejarem, os aluno poderão comparar a solução do pipeline proposto (thumbnail só executado depois do resize) com uma solução em que que o resize e thumbnail executem em paralelo imediatamente a seguir ao watermark.
- [ ] **Relatório** -> Calcular o valor de Throughput
- [ ] **Submissão** -> Ficheiro zip com as pasta ap-paralelo-3 + make file + **relatório pconc-relatorio-B-grupo11.pdf**
- [X] **Valgrind** -> Validações de memória
- [X] **Comentarios** -> Adicionar comentarios às nossas funções
- [ ] **Comentarios** -> Remover os comentarios desnecessários que estão nas funções