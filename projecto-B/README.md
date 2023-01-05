# To Do List Projecto - B

- [X] **O Inicio** -> Aproveitamento do código da parte A do projecto
- [ ] **Funcionalidade** -> Funções das imagens funcionam da seguinte Forma. **1º** watermark | **2º** resize + watermark | **3º** thumbnail + watermark 
- [ ] **Funcionalidade** -> Cada thread gera as três imagens transformadas e existe um loop de joins apenas no fim. Ou seja, a função de thread tem lá dentro a chamada às função watermark, resize e thumbnail. Será?
- [ ] **Funcionalidade** -> Existem 3 funções de threads distintas. A função de thread tem lá dentro a chamada às função watermark, resize e thumbnail.
- [ ] **Pipes** -> Cada thread espera por dados no pipe; depois de ler a referência de uma imagem, a thread, processa-a, grava o resultado e notifica o estágio seguinte (no caso das threads do estágio watermark e resize).
- [ ] **Optimizações** -> Os alunos poderão definir as estruturas de dados que considerarem convenientes, garantindo sempre que a referência/nome da imagem a processar em cada iteração das threads/estágio é lida a partir de pipes.4
- [ ] **Optimizações** -> Se desejarem, os aluno poderão comparar a solução do pipeline proposto (thumbnail só executado depois do resize) com uma solução em que que o resize e thumbnail executem em paralelo imediatamente a seguir ao watermark.
- [ ] **Relatório** -> Calcular o valor de Throughput
- [ ] **Submissão** -> Ficheiro zip com as pasta ap-paralelo-3 + make file + **relatório pconc-relatorio-B-grupo11.pdf**
- [ ] **Valgrind** -> Validações de memória
- [ ] **Comentarios** -> Adicionar comentarios às nossas funções
- [ ] **Comentarios** -> Remover os comentarios desnecessários que estão nas funções