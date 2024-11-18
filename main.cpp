#include "grafo.hpp"
#include "bfs.hpp"

int main() {
    int v = 26;

    Grafo grafo(v);

    grafo.addAresta(21, 22);
    grafo.addAresta(21, 16);
    grafo.addAresta(16, 11);
    grafo.addAresta(22, 23);
    grafo.addAresta(22, 17);
    grafo.addAresta(17, 12);
    grafo.addAresta(23, 24);
    grafo.addAresta(12, 13);
    grafo.addAresta(24, 25);
    grafo.addAresta(13, 14);
    grafo.addAresta(13, 18);
    grafo.addAresta(25, 20);
    grafo.addAresta(18, 19);
    grafo.addAresta(20, 19);
    grafo.addAresta(14, 15);
    grafo.addAresta(14, 9);
    grafo.addAresta(9, 8);
    grafo.addAresta(8, 3);
    grafo.addAresta(8, 7);
    grafo.addAresta(7, 6);
    grafo.addAresta(3, 4);
    grafo.addAresta(6, 1);
    grafo.addAresta(1, 2);
    grafo.addAresta(4, 5);
    grafo.addAresta(5, 10);

    cout << "Representação do Grafo:"<< endl;
    grafo.imprimir();
    cout << endl;   
    BFS::executar(grafo,21,5);

    return 0;
}
/*
1 2_|3 4_ 5
6_ 7_ 8_ 9| 10_
11| 12 13 14_ 15_
16| 17| 18_ 19_ 20
21 22 23 24 25
*/