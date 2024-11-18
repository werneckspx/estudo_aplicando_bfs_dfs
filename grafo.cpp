#include "Grafo.hpp"

Grafo::Grafo(int v) : vertices(v) {
    adj.resize(v);
}

void Grafo::addAresta(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); 
}

void Grafo::imprimir() const {
    for (int i = 1; i < vertices; i++) {
        cout << i << " -> ";
        for (int vizinho : adj[i]) {
            cout << vizinho << " ";
        }
        cout << endl;
    }
}

const vector<vector<int>>& Grafo::getAdjList() const {
    return adj;
}

int Grafo::getNumVertices() const {
    return vertices;
}