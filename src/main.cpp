#include "bfs.hpp"
#include "dfs.hpp"

int main() {
    const int numVertices = 26;

    Grafo grafo(numVertices);

    cout << "Listas de adjacência do Grafo:" << endl;
    grafo.imprimir();
    cout << endl;
    BFS::executar(grafo, 21, 5);
    DFS::executar(grafo, 21, 5);
    cout << "Caminhos e processos do BFS e DFS salvos nos arquivos txt" << endl;

    return 0;
}
/*
1 2_|3 4_ 5
6_ 7_ 8_ 9| 10_
11| 12 13 14_ 15_
16| 17| 18_ 19_ 20
21 22 23 24 25
*/