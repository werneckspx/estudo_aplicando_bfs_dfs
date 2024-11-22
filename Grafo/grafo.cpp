#include "grafo.hpp"

Grafo::Grafo(int v) : vertices(v) {
    adj.resize(v);

    addAresta(21, 22);
    addAresta(21, 16);
    addAresta(16, 11);
    addAresta(22, 23);
    addAresta(22, 17);
    addAresta(17, 12);
    addAresta(23, 24);
    addAresta(12, 13);
    addAresta(24, 25);
    addAresta(13, 14);
    addAresta(13, 18);
    addAresta(25, 20);
    addAresta(18, 19);
    addAresta(20, 19);
    addAresta(14, 15);
    addAresta(14, 9);
    addAresta(9, 8);
    addAresta(8, 3);
    addAresta(8, 7);
    addAresta(7, 6);
    addAresta(3, 4);
    addAresta(6, 1);
    addAresta(1, 2);
    addAresta(4, 5);
    addAresta(5, 10);
}

void Grafo::addAresta(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Grafo::imprimir() {
    for (int i = 1; i < vertices; i++) {
        cout << i << " -> ";
        for (int vizinho : adj[i]) {
            cout << vizinho << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> &Grafo::getAdjList() {
    return adj;
}

int Grafo::getNumVertices() {
    return vertices;
}