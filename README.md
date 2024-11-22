# Analisando a utilização dos algoritmos BFS e DFS

## BFS:

A busca em largura BFS, é um algoritmo utilizado para percorrer ou buscar em uma estrutura de dados que pode ser representada como um grafo ou uma árvore. Nesse algoritmo, a exploração começa no vértice ou nó raiz e se expande gradualmente para os vértices ou nós vizinhos de forma nivelada, ou seja, explora todos os vértices vizinhos de um determinado nível antes de avançar para o próximo nível. Durante a busca em largura, um conjunto de vértices ou nós visitados é mantido para garantir que cada vértice seja visitado apenas uma vez. O processo de ações realizadas é baseado na coloração dos nós para demonstrar o nós já visitados (preto), visualizados (cinza) e não visualizados (branco), assim o algoritmo classifica os nós vizinhos do nó atual e sendo controlado por uma fila processa as condições necessárias. 

## DFS:
Na busca em profundidade (DFS) a exploração também começa a partir de um vértice ou nó raiz e, ao contrário da busca em largura, a exploração se aprofunda em cada caminho até o final (vértice folha ou nó terminal) antes de voltar e explorar outros caminhos. Ou seja, o algoritmo explora recursivamente(ou usando uma pilha) cada vértice vizinho até que não haja mais vértices não visitados em um determinado caminho, e então retorna para explorar outros caminhos.

Durante a busca em profundidade, um conjunto de vértices ou nós visitados é mantido para garantir que cada vértice seja visitado apenas uma vez. O DFS implementado é controlado por uma pilha, onde o nó atual é empilhado e seus vizinhos são empilhados um a um até atingir um nó sem mais vizinhos para explorar, retornando então para os nós anteriores. A pilha mantém o controle da ordem de exploração.

## Compilação e Execução

<div align="justify">
O algoritmo disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:
</div>
<p></p>
<div align="center">

| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |
</div>
