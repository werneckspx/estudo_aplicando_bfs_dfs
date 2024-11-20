# Analisando a utilização dos algoritmos BFS e DFS

Para rodar:

g++ -o programa main.cpp grafo.cpp bfs.cpp <br>
./programa

Explicando o BFS:

A busca em largura BFS, é um algoritmo utilizado para percorrer ou buscar em uma estrutura de dados que pode ser representada como um grafo ou uma árvore. Nesse algoritmo, a exploração começa no vértice ou nó raiz e se expande gradualmente para os vértices ou nós vizinhos de forma nivelada, ou seja, explora todos os vértices vizinhos de um determinado nível antes de avançar para o próximo nível. Durante a busca em largura, um conjunto de vértices ou nós visitados é mantido para garantir que cada vértice seja visitado apenas uma vez. O processo de ações realizadas é baseado na coloração dos nós para demonstrar o nós já visitados (preto), visualizados (cinza) e não visualizados (branco), assim o algoritmo classifica os nós vizinhos do nó atual e sendo controlado por uma fila processa as condições necessárias. 
