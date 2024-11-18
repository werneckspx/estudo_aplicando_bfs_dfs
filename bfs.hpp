#ifndef BFS_HPP
#define BFS_HPP

#include "Grafo.hpp"
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <limits>

class BFS {
public:
    static void executar(const Grafo& grafo, int inicial, int final);
    static void printPath(const vector<int>& pi, int start, int target);
};

#endif