# Analisando a utilização dos algoritmos BFS e DFS

Os algoritmos análisados neste trabalho sao algoritmos de busca sem informação, ou seja, não recebem qualquer indicação sobre a proximidade que um estado se encontra de sua meta.

## BFS:

A busca em largura BFS, é um algoritmo utilizado para percorrer ou buscar em uma estrutura de dados que pode ser representada como um grafo ou uma árvore. Nesse algoritmo, a exploração começa no vértice ou nó raiz e se expande gradualmente para os vértices ou nós vizinhos de forma nivelada, ou seja, explora todos os vértices vizinhos de um determinado nível antes de avançar para o próximo nível. Durante a busca em largura, um conjunto de vértices ou nós visitados é armazenado para garantir que cada vértice seja visitado apenas uma vez. O processo de ações realizadas é baseado na coloração dos nós para demonstrar o nós já visitados (preto), visualizados (cinza) e não visualizados (branco), assim o algoritmo classifica os nós vizinhos do nó atual e sendo controlado por uma fila processa as condições necessárias. 

> **OBS:** a implementação está no arquivo ```bfs.cpp```.

## DFS:
Na busca em profundidade DFS a exploração também começa a partir de um vértice ou nó raiz e, ao contrário da busca em largura, a exploração se aprofunda em cada caminho até o final (vértice folha ou nó terminal) antes de voltar e explorar outros caminhos. Ou seja, o algoritmo explora recursivamente(ou usando uma pilha) cada vértice vizinho até que não haja mais vértices não visitados em um determinado caminho, e então retorna para explorar outros caminhos se necessário.

Durante a busca em profundidade, um conjunto de vértices ou nós visitados é armazenado para garantir que cada vértice seja visitado apenas uma vez. O DFS implementado é controlado por uma pilha, onde o nó atual é empilhado e seus vizinhos são empilhados um a um até atingir um nó sem mais vizinhos para explorar, retornando então para os nós anteriores. A pilha mantém o controle da ordem de exploração.

> **OBS:** a implementação está no arquivo ```dfs.cpp```.

## Implementação do Labirinto
O labirinto é representado como um grafo não direcionado, implementado na classe ```Grafo```. 

- Inicialização do grafo: 25 vértices.
- Arestas são adicionadas bidirecionalmente usando o método ```addAresta(u, v)```.
- Nós são conectados para criar caminhos potenciais.
- Algoritmos de busca (BFS e DFS) percorrem este grafo para encontrar um caminho entre nós de início e fim.

#### Abordagem de Medição de Desempenho
Ambos algoritmos medem:

- Tempo de execução usando ```chrono::high_resolution_clock```
- Uso de memória através de rastreamento personalizado.

Registro e Saída

- ```caminhoBfs.txt``` para Busca em Largura.
- ```caminhoDfs.txt``` para Busca em Profundidade.

Estes arquivos contêm, detalhes passo a passo da exploração, ordem de visitação dos nós, caminho para a solução e estatísticas de execução

## Medições e desempenho

### Discussão 

Como base para discussão feita, é preciso compreender alguns conceitos. Um algoritmo completo deve ser capaz de explorar sistematicamente todos os estados que podem ser alcançados desde o estado inicial. Em espaços de estados finitos, que é o caso deste trabalho, é garantido que poderá ser atingido qualquer estado que esteja conectado ao estado inicial.

Analisando a BFS, temos que ela é uma estratégia de busca sistemática que, portanto, é completa. Além disso, a solução encontrada apresenta um número mínimo de ações porque, quando a busca está analisando nós na profundidade d, ela já gerou todos os nós na profundidade $$d - 1$$, de modo que, se um deles fosse uma solução, teria sido encontrado, ou seja, a busca é ótima em termos de custo para problemas em que todas as ações tem o mesmo custo.

Já a análise da DFS mostra que, para espaços de estados finitos é eficiente e completa, mas para espaço de estado cíclicos pode ficar presa em um laço infinito, e para espaços de estados infinitos não é sistemática. Porém, não tem custo ótimo pois ela devolve a primeira solução que encontra, mesmo que não seja a de menor custo, entretando a busca faz muito menos uso de memória.

#### Análisando as complexidades
- Temporal
   - A DFS pode ser limitada pelo tamanho do espaço de estados finito, explorando no máximo E arestas e V vértices. Assim a complexidade seria $$O(E+V)$$.
   - Na BFS o tempo cresce exponencialmente com a profundidade da meta d e o fator de ramificação b sendo $$O(b^d)$$.
- Memória
    - Na DFS, a memória pode ser limitada pelo fator de ramificação B, e M a profundidade mámixa $$O(B*M)$$.
    - A memória necessária para armazenar os nós também cresce exponencialmente devido à natureza da fila utilizada na BFS $$O(b^d)$$.

#### Tempo de execução e Consumo de memória

Nesta etapa será visualizado o tempo gasto por cada algoritmo pra completar o objetivo e a memoria utilizada. Nos testes realizados, o algoritmo DFS tende a ter melhor performance, apresentando menor tempo gasto e menor consumo de memória.

#### BFS

| Execução | Tempo de Execução (ms) | Memória Usada (bytes) |
|----------|-------------------------|-----------------------|
| 1        | 40.1414                | 80                    |
| 2        | 45.0311                | 80                    |
| 3        | 39.7616                | 80                    |
| 4        | 45.2823                | 80                    |
| 5        | 43.3294                | 80                    |
| 6        | 44.7546                | 80                    |
| 7        | 48.9619                | 80                    |
| 8        | 43.9959                | 80                    |
| 9        | 45.7866                | 80                    |
| 10       | 40.3562                | 80                    |
| **Média**| **43.9401**            | **80**                |

---

#### DFS

| Execução | Tempo de Execução (ms) | Memória Usada (bytes) |
|----------|-------------------------|-----------------------|
| 1        | 17.6397                | 64                    |
| 2        | 17.4939                | 64                    |
| 3        | 17.4542                | 64                    |
| 4        | 17.3467                | 64                    |
| 5        | 15.8473                | 64                    |
| 6        | 17.6435                | 64                    |
| 7        | 18.2479                | 64                    |
| 8        | 18.2099                | 64                    |
| 9        | 17.5320                | 64                    |
| 10       | 17.2292                | 64                    |
| **Média**| **17.4644**            | **64**                |

---

É válido ressaltar, que para alguns problemas que exigiriam exabytes($10^{18}$) de memória nas busca em largura podem ser tratados com apenas kilobytes($10^{3}$) usando a busca em profundidade.

## Possíveis melhorias

Para o algoritmo BFS, uma possível melhoria seria adicionar o conjunto de estado alcançado, no lugar de um mapeamento de estados para nós, pois quando o estado e alcançado, não será possível encontrar um caminho melhor até ele. Isso signigica que seria possível realizar um teste de meta antecipado, verificando se um nó devolve uma solução assim que ele é gerado.

Para o algoritmo DFS, poderia ser aplicada uma melhoria que utiliza menos memória, o retrocesso. Nele, apenas o um sucessor é gerado de cada vez, e não todos os sucessores. Além disso, os sucessores são gerados modificando diretamente a descrição do estado atual, em vez de alocando a memória para um estado totalmente novo.

## Conclusão

A escolha entre BFS e DFS para um problema depende de vários fatores, como a estrutura e o tamanho do grafo, a localização e o número dos nós de interesse, o tipo e a complexidade do problema e as restrições de memória e tempo. BFS é preferível para encontrar caminhos mais curtos ou soluções ótimas, desde que a memória disponível seja suficiente. DFS é mais indicado quando o consumo de memória é uma restrição crítica, mesmo que a solução encontrada não seja a de menor custo. No contexto de exploração de labirintos, a DFS mostrou-se uma abordagem eficiente, mas para aplicações onde a completude e a otimalidade são críticas, o BFS pode ser mais adequado, desde que melhorias sejam implementadas para otimizar seu desempenho.

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
