#include "dfs.hpp"
#include "Stack/stack.hpp"
#include <string>
#include <stack>
#include <limits>
#include <chrono>

void DFS::executar(Grafo &grafo, int inicial, int final) {
    int vertices = grafo.getNumVertices();
    vector<vector<int>> &adj = grafo.getAdjList();

    ofstream out("caminhoDfs.txt");

    if (!out.is_open()) {
        cerr << "Erro ao abrir o arquivo para escrita!" << endl;
        return;
    }

    auto start = chrono::high_resolution_clock::now();

    vector<bool> visited(vertices, false);
    vector<int> pi(vertices, -1);
    vector<int> d(vertices, numeric_limits<int>::max());
    int iteracao = 0;

    out << "================================" << endl;
    out << "INÍCIO DA BUSCA EM PROFUNDIDADE (DFS)" << endl;
    out << "================================" << endl;
    out << "Nó Inicial: " << inicial << endl;
    out << "Nó Final: " << final << endl;
    out << "================================" << endl;

    visited[inicial] = true;
    d[inicial] = 0;
    pi[inicial] = -1;

    Stack *pilha = new Stack();
    pilha->Push(inicial);
    bool found = false;

    while (!pilha->Empty() && !found) {
        iteracao++;
        int u = pilha->Top()->getValue();
        pilha->Pop();

        out << "\nIteração " << iteracao << ": Explorando nó " << u << endl;
        out << "  Distância da origem: " << d[u] << ", Predecessor: " << pi[u] << endl;

        out << "  Vizinhos do nó " << u << ":" << endl;
        bool algumNaoVisitado = false;

        for (int v : adj[u]) {
            if (!visited[v]) {
                out << "    - Explorando vizinho " << v << " (NÃO VISITADO)" << endl;
                visited[v] = true;
                d[v] = d[u] + 1;
                pi[v] = u;
                pilha->Push(v);

                if (v == final) {
                    found = true;
                    out << "    *** NÓ FINAL " << final << " ENCONTRADO! ***" << endl;
                    break;
                }

                algumNaoVisitado = true;
            } else {
                out << "    - Vizinho " << v << " (JÁ VISITADO)" << endl;
            }
        }

        if (!algumNaoVisitado) {
            out << "  Todos os vizinhos de " << u << " já foram visitados." << endl;
        }

        out << "  Nó " << u << " visitado!" << endl;
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;

    out << "\n================================" << endl;
    out << "RESUMO DA BUSCA" << endl;
    out << "================================" << endl;

    if (found) {
        out << "Caminho encontrado do nó " << inicial << " até o nó " << final << "!" << endl;
        out << "Distância: " << d[final] << endl;
        out << "CAMINHO ENCONTRADO: ";
        printPath(pi, final, out);
    } else {
        out << "Não foi possível encontrar um caminho até o nó " << final << endl;
    }

    out << "\n================================" << endl;
    out << "ESTATÍSTICAS DE EXECUÇÃO" << endl;
    out << "================================" << endl;
    out << "Tempo de execução: " << duration.count() << " ms" << endl;

    out.close();
}

void DFS::printPath(vector<int> &pi, int target, ofstream &out) {
    Stack path;
    int current = target;

    while (current != -1) {
        path.Push(current);
        current = pi[current];
    }

    while (!path.Empty()) {
        out << path.Top()->getValue();
        path.Pop();
        if (!path.Empty()) out << " -> ";
    }
    out << endl;
}