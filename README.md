# Analisando a utilização dos algoritmos BFS e DFS

## BFS:

A busca em largura BFS, é um algoritmo utilizado para percorrer ou buscar em uma estrutura de dados que pode ser representada como um grafo ou uma árvore. Nesse algoritmo, a exploração começa no vértice ou nó raiz e se expande gradualmente para os vértices ou nós vizinhos de forma nivelada, ou seja, explora todos os vértices vizinhos de um determinado nível antes de avançar para o próximo nível. Durante a busca em largura, um conjunto de vértices ou nós visitados é mantido para garantir que cada vértice seja visitado apenas uma vez. O processo de ações realizadas é baseado na coloração dos nós para demonstrar o nós já visitados (preto), visualizados (cinza) e não visualizados (branco), assim o algoritmo classifica os nós vizinhos do nó atual e sendo controlado por uma fila processa as condições necessárias. 

## DFS:
Na busca em profundidade (DFS) a exploração também começa a partir de um vértice ou nó raiz e, ao contrário da busca em largura, a exploração se aprofunda em cada caminho até o final (vértice folha ou nó terminal) antes de voltar e explorar outros caminhos. Ou seja, o algoritmo explora recursivamente(ou usando uma pilha) cada vértice vizinho até que não haja mais vértices não visitados em um determinado caminho, e então retorna para explorar outros caminhos.

Durante a busca em profundidade, um conjunto de vértices ou nós visitados é mantido para garantir que cada vértice seja visitado apenas uma vez. O DFS implementado é controlado por uma pilha, onde o nó atual é empilhado e seus vizinhos são empilhados um a um até atingir um nó sem mais vizinhos para explorar, retornando então para os nós anteriores. A pilha mantém o controle da ordem de exploração.

## Medições e desempenho

### Tempo de execução e Consumo de memória

Nesta etapa será visualizado o tempo gasto por cada algoritmo pra completar o objetivo e a memoria utilizada. Nos testes realizados, o algoritmo DFS tende a ter melhor performance, apresentando menor tempo gasto e menor consumo de memória.

|Algoritmo|Tempo de execução|Consumo de memória|
|---------|-----------------|------------------|
|DFS|29 ms|64 bytes|
|BFS|70 ms|80 bytes|

#### Análisando as complexidades
- Temporal
    A DFS pode ser limitada pelo tamanho do espaço de estados finito, explorando no máximo E arestas e V vértices. Assim a complexidade seria $$O(E+V)$$.
    Na BFS o tempo cresce exponencialmente com a profundidade da meta d e o fator de ramificação b sendo $$ O(b^d) $$.
- Memória
    Na DFS, a memória pode ser limitada pelo número total de vértices V, e M a profundidade mámixa do nó $$ O(V+m)$$.
    A memória necessária para armazenar os nós também cresce exponencialmente devido à natureza da fila utilizada na BFS $$ O(b^d) $$.
### Completude

Para todos os testes realizados nos algoritmos, a partir de uma entrada válida, retornaram saídas válidas, não entrando em loops infinitos e terminando em um tempo razoável para as entradas. Mas a pontos a se destacar, o BFS só é completo se o fator de ramificação for finito, e na DFS somente se o espaço de estado for finito.

### Otimalidade

A DFS e a BFS não são necessariamnte ótimas, em relação a encontrar o melhor caminho ambas cumprem o requisito, porém quando se olha para o tempo de execução e para o consumo de memória ambas gastam mais do que outros algoritmos melhor otimizados.

## Conclusão

A escolha entre BFS e DFS para um problema depende de vários fatores, como a estrutura e o tamanho do gráfico, a localização e o número dos nós de interesse, o tipo e a complexidade do problema e as restrições de memória e tempo. Por exemplo, se o gráfico for esparso e grande, e os nós estiverem distantes, o DFS pode ser mais eficiente do que o BFS. Por outro lado, se o problema exigir encontrar o caminho mais curto ou o nó mais próximo, o BFS pode ser mais adequado do que o DFS. Além disso, se a memória for limitada e o tempo for flexível, o DFS pode ser mais preferível do que o BFS. Em última análise, as compensações entre memória e tempo devem ser levadas em consideração ao decidir qual algoritmo usar.
%https://www.linkedin.com/advice/0/how-do-you-compare-contrast-bfs-dfs-graph-traversal?lang=pt&originalSubdomain=pt
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
