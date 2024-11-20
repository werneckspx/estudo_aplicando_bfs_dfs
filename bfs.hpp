#ifndef BFS_HPP
#define BFS_HPP

#include "Grafo.hpp"
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <limits>
#include <chrono>

class BFS {
public:
    static void executar(Grafo& grafo, int inicial, int final);
    static void printPath(vector<int>& pi, int start, int target);
};

#endif