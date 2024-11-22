#include "bfs.hpp"
#include "Fifo/fifo.hpp"
#include "Stack/stack.hpp"

void BFS::executar(Grafo &grafo, int inicial, int final) {
    int vertices = grafo.getNumVertices();
    vector<vector<int>> &adj = grafo.getAdjList();

    ofstream out("caminhoBfs.txt");

    if (!out.is_open()) {
        cerr << "Erro ao abrir o arquivo para escrita!" << endl;
        return;
    }

    auto start = chrono::high_resolution_clock::now();
    vector<string> cor(vertices, "BRANCO");
    vector<int> pi(vertices, -1);
    vector<int> d(vertices, numeric_limits<int>::max());
    int iteracao = 0;

    out << "================================" << endl;
    out << "INÍCIO DA BUSCA EM LARGURA (BFS)" << endl;
    out << "================================" << endl;
    out << "Nó Inicial: " << inicial << endl;
    out << "Nó Final: " << final << endl;
    out << "================================" << endl;

    cor[inicial] = "CINZA";
    d[inicial] = 0;
    pi[inicial] = -1;

    Fifo fila;
    fila.Push(inicial);
    bool found = false;

    while (!fila.Empty() && !found) {
        iteracao++;
        int u = fila.Front()->getValue();
        fila.Pop();

        out << "\nIteração " << iteracao << ": Analisando nó " << u << endl;
        out << "-----------------------------------" << endl;

        out << "Estado atual do nó " << u << ":" << endl;
        out << "  Cor: CINZA" << endl;
        out << "  Distância da origem: " << d[u] << endl;
        out << "  Predecessor: " << pi[u] << endl;

        out << "\nVizinhos do nó " << u << ":" << endl;

        for (int v : adj[u]) {
            out << "\n  Explorando vizinho: " << v << endl;

            if (cor[v] == "BRANCO") {
                out << "    Status: NÃO VISITADO" << endl;
                out << "    Ação: Marcando para exploração" << endl;

                cor[v] = "CINZA";
                d[v] = d[u] + 1;
                pi[v] = u;
                fila.Push(v);

                out << "    Detalhes após marcação:" << endl;
                out << "      Nova cor: CINZA" << endl;
                out << "      Distância: " << d[v] << endl;
                out << "      Predecessor: " << u << endl;

                if (v == final) {
                    found = true;
                    out << "\n  *** NÓ FINAL ENCONTRADO! ***" << endl;
                    break;
                }
            } else {
                out << "    Status: JÁ VISITADO (Cor: "
                    << (cor[v] == "CINZA" ? "CINZA" : "PRETO") << ")" << endl;
            }
        }

        cor[u] = "PRETO";
        out << "\nNó " << u << " marcado como PRETO (completamente explorado)" << endl;
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;

    out << "\n================================" << endl;
    out << "RESUMO DA BUSCA" << endl;
    out << "================================" << endl;

    if (found) {
        out << "\nNó " << final << " encontrado!" << endl;
        out << "Distância do nó " << inicial << " até o nó " << final
            << ": " << d[final] << endl;

        out << "\nCAMINHO ENCONTRADO:" << endl;
        printPath(pi, final, out);
    } else {
        out << "Não foi possível encontrar um caminho até o nó " << final << endl;
    }

    out << "\n================================" << endl;
    out << "ESTATÍSTICAS DE EXECUÇÃO" << endl;
    out << "================================" << endl;
    out << "Tempo de execução: " << duration.count() << " ms" << endl;
    out << "Pico de memória: " << fila.getPicoMemoriaUsada() << " bytes" << endl;
    out << "Memoria Usada: " << fila.getMemoriaUsada() << " bytes" << endl;



    out.close();
}

void BFS::printPath(vector<int> &pi, int target, ofstream &out) {
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
