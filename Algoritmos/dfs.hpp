#ifndef DFS_HPP
#define DFS_HPP

#include "Grafo/grafo.hpp"
#include <vector>
#include <fstream>

class DFS {
public:
    static void executar(Grafo &grafo, int inicial, int final);
    static void printPath(vector<int> &pi, int target, std::ofstream &out);
};

#endif