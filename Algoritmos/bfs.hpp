#ifndef BFS_HPP
#define BFS_HPP

#include "Grafo/grafo.hpp"
#include <vector>
#include <string>
#include <stack>
#include <limits>
#include <chrono>
#include <fstream>

class BFS {
public:
    static void executar(Grafo &grafo, int inicial, int final);
    static void printPath(vector<int> &pi, int target, ofstream &out);
};

#endif