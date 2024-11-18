#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <vector>
#include <iostream>
using namespace std;

class Grafo {
private:
    int vertices;
    vector<vector<int>> adj;

public:
    Grafo(int v);
    void addAresta(int u, int v);
    void imprimir() const;
    const vector<vector<int>>& getAdjList() const;
    int getNumVertices() const;
};

#endif